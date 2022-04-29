options no_unused_block_arguments = false
options no_unused_function_arguments = false
options indenting = 4

module jit_x86_64_alloc_regs shared public

require jit_x86_64_regs
require jit_x86_64_common

require daslib/ast_boost
require daslib/strings_boost
require daslib/templates_boost
require math

require dasxbyak/xbyak_boost
require xbyak public

require ast public

class AllocateRegistersCodeVisitor : JitVisitor
    put_loop_variables_in_registers  : bool = true      // for i in range(blah);    i goes to GpReg
    put_local_variables_in_registers : bool = true      // var i = 5; i ++          i goes to GpReg
    [[do_not_delete]] local_stack : array<Variable?>
    local_stack_depth : array<int>
    [[do_not_delete]] this_function : Function?
    def AllocateRegistersCodeVisitor ( var ctx:EvContext )
        JitVisitor`JitVisitor(self, ctx)
    def evExpectSpecials ( expr:ExpressionPtr; spc:Specials; at:LineInfo )
        logAt("expect specials {spc} {expr.__rtti}.{intptr(expr)}", at)
        let key = intptr(expr)
        if ! context.specials |> key_exists(key)
            context.specials[key] = spc
    def evExpectStack ( expr:ExpressionPtr; stack:uint; at:LineInfo )
        logAt("expect stack {stack} {expr.__rtti}.{intptr(expr)}", at)
        var eV & = unsafe(evResSet(expr))
        if eV is nothing
            eV = [[EvResult stack=stack]]
    def evExpectCalli ( expr:ExpressionPtr; calli:uint; at:LineInfo )
        logAt("expect call arguments {calli} {expr.__rtti}.{intptr(expr)}", at)
        var eV & = unsafe(evResSet(expr))
        if eV is nothing
            eV = [[EvResult calli=calli]]
    def evExpectCmp ( expr:ExpressionPtr; at:LineInfo )
        logAt("expect results in flags {expr.__rtti}.{intptr(expr)}", at)
        var eV & = unsafe(evResSet(expr))
        if eV is nothing
            eV = [[EvResult cmp=CompareType always]]
    def evExpectNothing ( expr:ExpressionPtr; at:LineInfo )
        logAt("expect nothing {expr.__rtti}.{intptr(expr)}", at)
        var eV & = unsafe(evResSet(expr))
        if eV is nothing
            eV = [[EvResult skip=true]]
    def evRelease ( var res:EvResult; at:LineInfo )
        if res is gpReg
            let reg = res as gpReg
            if reg==GpTempReg RAX || reg==GpTempReg RDX || reg==GpTempReg RCX
                return
            logAt("release GP reg {reg}",at)
            context.gpa |> free(int(reg))
        elif res is xmmReg
            logAt("release XMM reg {res as xmmReg}",at)
            context.xmma |> free(int(res as xmmReg))
    def releaseGP ( reg:GpTempReg; at:LineInfo )
        logAt("releaseGP {reg}",at)
        context.gpa |> free(int(reg))
    def allocateGP ( at:LineInfo )
        let idx = context.gpa |> allocate()
        unsafe
            let reg = reinterpret<GpTempReg> idx
            logAt("allocate GP reg {reg}",at)
            return reg
    def allocateXMM ( at:LineInfo )
        let idx = context.xmma |> allocate()
        unsafe
            let reg = reinterpret<XmmTempReg> idx
            logAt("allocate XMM reg {reg}", at)
            return reg
    def setTransients(expr:smart_ptr<ExprCall>)
        context.transients[intptr(expr)] = [[Transients
            gp_mask = context.gpa |> mask(FIRST_NON_TRANSIENT_GP_TEMP_REG),
            xmm_mask = context.xmma |> mask(FIRST_NON_TRANSIENT_XMM_TEMP_REG)
        ]]
    def acceptConstR64 ( expr:smart_ptr<Expression>; value:uint64 )
        var ev & = unsafe(evResSet(expr))
        if !(ev is stack)
            ev = [[EvResult iconst=value]]
        return expr
// function
    def override preVisitFunction(fun:FunctionPtr) : void
        this_function = get_ptr(fun)
        context.stack_frame = fun.totalStackSize
    def override visitFunction(fun:FunctionPtr) : FunctionPtr
        if !context.uses_rcx
            let candidate = context |> pick_rcx_candidate()
            if candidate != GpTempReg BROKEN
                log("context does not use rcx, promoting {candidate}\n")
                context |> replace_register_allocation(candidate, GpTempReg RCX)
            else
                log("context does not use rcx, but there is nothing to promote\n")
        let total_xmm_save = length(context.xmma.regs) - FIRST_NON_TRANSIENT_XMM_TEMP_REG
        if total_xmm_save>0
            // save_frame has all extra non-transient xmm registers - 16 bytes each
            context.save_frame += uint(total_xmm_save) * 16u
        let total_gp_save = length(context.gpa.regs) - FIRST_NON_TRANSIENT_GP_TEMP_REG
        if total_gp_save>0
            // save frame has all extra gp non-transient GP registers - 8 bytes each, total aligned to 16
            context.save_frame += uint(total_gp_save) * 8u
            if (total_gp_save & 1)!=0
                context.save_frame += 8u
        return fun
// block
    def override preVisitExprBlock(blk:smart_ptr<ExprBlock>) : void
        // keep local variables on local_stack
        local_stack_depth |> push(length(local_stack))
    def override visitExprBlockExpression(blk:smart_ptr<ExprBlock>;expr:ExpressionPtr) : ExpressionPtr
        var topE & = unsafe(evResSet(expr))
        evRelease(topE,expr.at)
        return expr
    def override visitExprBlock(blk:smart_ptr<ExprBlock>) : ExpressionPtr
        // restore variable stack
        let lsvd = length(local_stack)
        let lsd = local_stack_depth |> back()
        local_stack_depth |> pop()
        for t in range(lsd,lsvd)
            let pvar = local_stack[t]
            // TODO: release GP variables on the last use, not on the block end
            if context.temp_var |> key_exists(intptr(pvar))
                let reg = context.temp_var[intptr(pvar)]
                releaseGP(reg,blk.at)
                log("{local_stack[t].name} out of scope, {reg}\n")
        local_stack |> resize(lsd)
        return blk
// const int
    def override visitExprConstInt(expr:smart_ptr<ExprConstInt>) : ExpressionPtr
        acceptConstR64(expr,uint64(expr.value))
        return expr
// const bool
    def override visitExprConstBool(expr:smart_ptr<ExprConstBool>) : ExpressionPtr
        acceptConstR64(expr,expr.value ? 1ul : 0ul)
        return expr
// let
    def override preVisitExprLetVariable(expr:smart_ptr<ExprLet>;arg:VariablePtr;lastArg:bool) : void
        local_stack |> push(get_ptr(arg))
        if !arg._type.isRef
            if arg._type |> is_gpreg_type
                // if its a local variable of the right type, promote to gpReg and done
                if put_local_variables_in_registers
                    let reg = allocateGP(expr.at)
                    context.temp_var[intptr(arg)] = reg
                    log("promote {arg.name} to {reg}\n")
                return
            else
                failed("ExprLetVariable !arg._type.isRef, {describe(arg._type)}", expr.at)
        // let var = value
        if arg.init != null
            if arg.init._type.isRef
                // we say nothing, and copy from address in gpReg
                pass
            else
                //  we say we expect value on the stack
                evExpectStack(arg.init,arg.stackTop,expr.at)
    def override visitExprLetVariableInit(blk:smart_ptr<ExprLet>;arg:VariablePtr;expr:ExpressionPtr) : ExpressionPtr
        // if result alrady comes on our stack, we are good
        var evI & = unsafe(evResSet(arg.init))
        if (evI ?as stack ?? -1u)==arg.stackTop
            return expr
        // after init, we are done with arg.init
        evRelease(evI,expr.at)
        return  expr
// variable
    def override visitExprVar(expr:smart_ptr<ExprVar>) : ExpressionPtr
        var ev & = unsafe(evResSet(expr))
        let varSize = expr._type.isRef ? 8 : expr._type.sizeOf
        if expr.varFlags._block
            failed("{expr.variable.name} support block variable", expr.at)
        elif expr.varFlags.local    // local varaibels
            if context.temp_var |> key_exists(intptr(expr.variable))
                let reg = context.temp_var[intptr(expr.variable)]
                ev = [[EvResult gpRegT=reg]]
            elif expr.varFlags.r2v
                if expr.variable._type |> is_gpreg_type
                    // return local variable as GP register
                    let reg = allocateGP(expr.at)
                    ev = [[EvResult gpReg=reg]]
                    log("local variable {expr.variable.name} is in {reg} for now\n")
                else
                    failed("ExprLetVariable expr.varFlags.local expr.varFlags.r2v, {expr.variable.name} : {describe(expr.variable._type)}", expr.at)
            else
                // if we are asking for reference, return stack
                ev = [[EvResult stack=expr.variable.stackTop]]
        elif expr.varFlags.argument // arguments
            context.use_args = true
            if expr.varFlags.r2v
                if expr.variable._type |> is_gpreg_type
                    // return local variable as GP register
                    let reg = allocateGP(expr.at)
                    ev = [[EvResult gpReg=reg]]
                    log("argument {expr.variable.name} is in {reg} for now\n")
                else
                    failed("ExprLetVariable expr.varFlags.argument expr.varFlags.r2v, {expr.variable.name} : {describe(expr.variable._type)}", expr.at)
            else
                // TODO: do we need 'argument' ref type?
                let reg = allocateGP(expr.at)
                ev = [[EvResult gpReg=reg]]
                log("argument {expr.variable.name} address is in {reg} for now\n")
        else
            failed("ExprLetVariable {expr.variable.name} : {describe(expr.variable._type)}", expr.at)
        return expr
// op1
    def override visitExprOp1(expr:smart_ptr<ExprOp1>) : ExpressionPtr
        var ev & = unsafe(evResSet(expr.subexpr))
        var evOP1 & = unsafe(evResSet(expr))
        if expr.subexpr._type.isWorkhorseType
            if expr.subexpr._type |> is_gpreg_type
                if expr.op=="++" || expr.op=="+++" || expr.op=="--" || expr.op=="---"
                    if (ev is gpRegT) && (expr.op=="++" || expr.op=="--")
                        // if its temp variable, and its pre-inc and pre-dec - result is that variable
                        log("{expr.op} prefix result stays in {ev}\n")
                        evOP1 = ev
                    elif ev is gpReg
                        // if subexpr is register, we reuse it as a result
                        evOP1 = ev
                    else
                        // we allocate new register for result
                        evRelease(ev,expr.at)
                        let reg = allocateGP(expr.at)
                        evOP1 = [[EvResult gpReg=reg]]
                        log("op1 {expr.op} result is in {reg} for now\n")
            else
                failed("ExprOp1 {expr.op} expr.subexpr._type.isWorkhorseType {describe(expr.subexpr._type)}", expr.at)
        else
            failed("ExprOp1 {expr.op} {describe(expr.subexpr._type)}", expr.at)
        return expr
// op2
    def override preVisitExprOp2(expr:smart_ptr<ExprOp2>): void
        var evL & = unsafe(evResSet(expr.left))
        var evR & = unsafe(evResSet(expr.right))
        var evOP2 & = unsafe(evResSet(expr))
        if expr.left._type.isWorkhorseType
            if expr.left._type |> is_gpreg_type
                if expr.left._type.isRef
                    if expr.op=="/=" || expr.op=="%="
                        if starts_with(expr.right.__rtti,"ExprConst")
                            // division by iconst uses rcx
                            context.uses_rcx = true
                else
                    if evOP2 is cmp
                        if expr.op=="<" || expr.op=="=="
                            if starts_with(expr.right.__rtti,"ExprConst")
                                // we can accept special on the left, if right is const
                                evExpectSpecials(expr.left, Specials RAX | Specials RDX | Specials RCX, expr.at)
                            else
                                // we can accept special on the right always
                                evExpectSpecials(expr.right, Specials RAX | Specials RDX | Specials RCX, expr.at)
                    if expr.op=="/" || expr.op=="%"
                        if starts_with(expr.right.__rtti,"ExprConst")
                            // division by iconst uses rcx
                            context.uses_rcx = true
    def override visitExprOp2(expr:smart_ptr<ExprOp2>) : ExpressionPtr
        var evL & = unsafe(evResSet(expr.left))
        var evR & = unsafe(evResSet(expr.right))
        var evOP2 & = unsafe(evResSet(expr))
        if expr.left._type.isWorkhorseType
            if expr.left._type |> is_gpreg_type
                if expr.op=="/" || expr.op=="%"
                    if evR is gpReg
                        context.rcx_candidates[evR as gpReg]++
                    elif evR is gpRegT
                        context.rcx_candidates[evR as gpRegT]++
                if expr.left._type.isRef    // +=, -=, and such - were left side is ref
                    // we are done with both sides
                    evRelease(evL,expr.at)
                    evRelease(evR,expr.at)
                else
                    if evOP2 is cmp
                        evOP2 = [[EvResult cmp=getCompareOp(expr.op)]]
                        evRelease(evL,expr.at)
                        evRelease(evR,expr.at)
                    else
                        // imm operators
                        if (expr.op=="-" || expr.op=="+" || expr.op=="*" || expr.op=="/" || expr.op=="%" ||
                            expr.op=="<" || expr.op=="<=" || expr.op=="==" || expr.op=="!=" || expr.op==">=" || expr.op==">")
                            // this operators require context for the exceptions
                            if expr.op=="%" || expr.op=="/"
                                context.use_context = true
                                let spec = evSpecialsGet(expr)
                                if (expr.op=="/" && spec.RAX) || (expr.op=="%" && spec.RDX)
                                    evResSet(expr) = [[EvResult gpReg=(expr.op=="/" ? GpTempReg RAX : GpTempReg RDX)]]
                                    evRelease(evL,expr.at)
                                    evRelease(evR,expr.at)
                                    return expr
                            if evL is gpReg                                             // left is reg
                                if (evR is iconst) || (evR is gpReg) || (evR is gpRegT) // right is const, or reg
                                    // reuse left register
                                    evResSet(expr) = evL
                                    // we release only right
                                    evRelease(evR,expr.at)
                                else
                                    failed("ExprOp2 {expr.op} expr.left._type.isWorkhorseType evL is gpReg right={evR}", expr.at)
                            elif evL is gpRegT
                                // we allocate new temp register
                                let nreg = allocateGP(expr.at)
                                evOP2 = [[EvResult gpReg=nreg]]
                                log("op2 {expr.op} result is in {nreg} for now\n")
                                // we release both left and right
                                evRelease(evL,expr.at)
                                evRelease(evR,expr.at)
                                log("reg {nreg} for {describe(expr)}\n")
                            else
                                failed("ExprOp2 {expr.op} expr.left._type.isWorkhorseType left={evL} right={evR}", expr.at)
                        else
                            failed("ExprOp2 {expr.op} expr.left._type.isWorkhorseType", expr.at)
            else
                failed("ExprOp2 {expr.op} expr.left._type.isWorkhorseType {describe(expr.left._type)}", expr.at)
        else
            failed("ExprOp2 {expr.op} {describe(expr.left._type)}", expr.at)
        return expr
// if-then-else
    def override preVisitExprIfThenElse(expr:smart_ptr<ExprIfThenElse>) : void
        evExpectCmp(expr.cond,expr.cond.at)
    def override visitExprIfThenElse(expr:smart_ptr<ExprIfThenElse>) : ExpressionPtr
        var evCond & = unsafe(evResSet(expr.cond))
        evRelease(evCond,expr.at)
        return expr
// op3
    def override preVisitExprOp3(expr:smart_ptr<ExprOp3>): void
        evExpectCmp(expr.subexpr,expr.at)
    def override visitExprOp3(expr:smart_ptr<ExprOp3>) : ExpressionPtr
        // TODO: support result type
        var evS & = unsafe(evResSet(expr.subexpr))
        var evL & = unsafe(evResSet(expr.left))
        var evR & = unsafe(evResSet(expr.right))
        var evOP3 & = unsafe(evResSet(expr))
        if evL is gpReg
            // if left one is there - we use that as result
            evOP3 = evL
            evRelease(evR,expr.right.at)
        elif evR is gpReg
            // if right one is there - we use that as result
            evOP3 = evR
            evRelease(evL,expr.left.at)
        else
            /// we allocate new register for the result
            let reg = allocateGP(expr.at)
            evOP3 = [[EvResult gpReg=reg]]
            log("op3 {expr.op} result is in {reg} for now\n")
            evRelease(evL,expr.left.at)
            evRelease(evR,expr.right.at)
        log("op3 {evS} ? {evL} : {evR} result in {evS}\n")
        evRelease(evS,expr.subexpr.at)
        return expr
// copy
    def override visitExprCopy(expr:smart_ptr<ExprCopy>) : ExpressionPtr
        var evL & = unsafe(evResSet(expr.left))
        var evR & = unsafe(evResSet(expr.right))
        // after copy we are done with both sides
        evRelease(evL,expr.at)
        evRelease(evR,expr.at)
        return expr
// return
    def override visitExprReturn(expr:smart_ptr<ExprReturn>) : ExpressionPtr
        if expr.subexpr!=null
            // if there is return (subexpr), we are done with it
            var evR & = unsafe(evResSet(expr.subexpr))
            evRelease(evR,expr.at)
        return expr
// for
    def override preVisitExprFor(expr:smart_ptr<ExprFor>) : void
        if is_for_range1_RANGE(expr)
            // if its for blah in range(...) then we take over range(...) arguments
            log("taking over the range for the loop\n")
            evExpectNothing(expr.sources[0],expr.at)
        if put_loop_variables_in_registers
            for v in expr.iteratorVariables
                let reg = allocateGP(expr.at)
                context.temp_var[intptr(v)] = reg
                log("for loop iterator variable {v.name} is in {reg}\n")
        else
            for v in expr.iteratorVariables
                log("loop variable {v.name} [rsp+{uint(v.stackTop)}]\n")
    def override visitExprForSource(expr:smart_ptr<ExprFor>;source:ExpressionPtr;last:bool) : ExpressionPtr
        if is_for_range1(expr)
            if !(context.temp_var |> key_exists(intptr(expr.iteratorVariables[0])))
                // blanet statement - if the range source is on the stack, ecx is very likely used
                context.uses_rcx = true
        return source
    def override preVisitExprForBody(expr:smart_ptr<ExprFor>) : void
        if is_for_range1_RANGE(expr)
            var crange = expr.sources[0] as ExprCall
            if length(crange.arguments)==2
                // if its range(from,to) than we only need the 'to' part
                var evA0 & = unsafe(evResSet(crange.arguments[0]))
                evRelease(evA0, expr.body.at)
    def override visitExprFor(expr:smart_ptr<ExprFor>) : ExpressionPtr
        if put_loop_variables_in_registers
            for v in expr.iteratorVariables
                if context.temp_var |> key_exists(intptr(v))
                    let reg = context.temp_var[intptr(v)]
                    releaseGP(reg,expr.at)
        // we are done with all sources by the time we are done with loop
        // body would be too early, cause sources used at the loop end to check
        for src in expr.sources
            var evS & = unsafe(evResSet(src))
            evRelease(evS,expr.body.at)
        if is_for_range1_RANGE(expr)
            // now its time to release the remainder of the range goo
            var crange = expr.sources[0] as ExprCall
            if length(crange.arguments)==2
                var evA1 & = unsafe(evResSet(crange.arguments[1]))
                evRelease(evA1, expr.body.at)
            else
                var evA0 & = unsafe(evResSet(crange.arguments[0]))
                evRelease(evA0, expr.body.at)
        return expr
// call
    def override visitExprCall(var expr:smart_ptr<ExprCall>) : ExpressionPtr
        if !expr.func.flags.builtIn
            // if not recursive, context is used
            if expr.func != this_function
                context.use_context = true
                context.uses_rcx = true
            // allocate temp frame for arguments, 16 bytes ech, aligned
            let bytes = uint(length(expr.arguments) * 16)
            if expr.func.flags.copyOnReturn || expr.func.flags.moveOnReturn
                failed("visitExprCall expr.func.flags.copyOnReturn || expr.func.flags.moveOnReturn", expr.at)
            if expr.stackTop != 0u
                failed("visitExprCall stackTop={expr.stackTop}", expr.at)
            for argi in range(length(expr.arguments))
                evExpectCalli(expr.arguments[argi],uint(argi)*16u,expr.at)
            for arg in expr.arguments
                var eaV & = unsafe(evResSet(arg))
                evRelease(eaV,expr.at)
            setTransients(expr)
            if expr.func.result != null
                if expr.func.result.isRef
                    failed("visitExprCall expr.func.result!=null expr.func.result.isRef", expr.at)
                else
                    var fnR & = unsafe(evResSet(expr))
                    if expr.func.result.isVectorType
                        let reg = allocateXMM(expr.at)
                        fnR = [[EvResult xmmReg=reg]]
                    else
                        let reg = allocateGP(expr.at)
                        fnR = [[EvResult gpReg=reg]]
                        log("function call {expr.name} result is in {reg} for now\n")
                    log("call {expr.func._module.name}::{expr.func.name} returns {fnR}\n")
            return expr
        ////////////////////
        // TODO: calls table
        let call_name = "{expr.func._module.name}::{expr.func.name}"
        if call_name=="$::range"

            JIT`range(expr)
        else
            failed("visitExprCall {call_name}", expr.at)
        return expr
    /////////////////////
    // function templates
    def JIT`range(var expr:smart_ptr<ExprCall>)
        let evJ & = unsafe(evResGet(expr))
        if evJ is skip
            return
        // release arugments
        for ai in range(length(expr.arguments))
            var evA & = unsafe(evResSet(expr.arguments[ai]))
            evRelease(evA,expr.at)
        // range retursn result in an xmm register
        let xreg = allocateXMM(expr.at)
        evResSet(expr) = [[EvResult xmmReg=xreg]]

