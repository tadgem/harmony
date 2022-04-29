options no_unused_block_arguments = false
options no_unused_function_arguments = false
options indenting = 4

module jit_x86_64_generate shared public

require jit_x86_64_regs
require jit_x86_64_common
require jit_x86_64_generate_base

require daslib/ast_boost
require daslib/strings_boost
require daslib/templates_boost
require math

require dasxbyak/xbyak_boost
require xbyak public
require zydis

require ast public

class GenerateCodeVisitor : GenerateCodeVisitorBase
    tab : int
    [[do_not_delete]] this_function : Function?
    func_begin : void?
    loop_stack : array<uint64>
    def GenerateCodeVisitor(var g:CodeGenerator?; var ctx:EvContext )
        GenerateCodeVisitorBase`GenerateCodeVisitorBase(self, g, ctx)
        gen = g
// function
    def override preVisitFunction(fun:FunctionPtr) : void
        log("(DEF {fun.name} [STACK={context.stack_frame}]\n")
        rdx_has_args = true
        this_function = get_ptr(fun)
        unsafe
            func_begin = *gen |> get_code()
        with_xbyak(gen) <| $ ( GEN )
            // passing (context(rcx) *, arguments(rdx) *, cmres(r8) *)
            if context.use_cmres
                mov(qword[rsp+ARG_CMRES],r8)
            if context.use_args
                mov(qword[rsp+ARG_ARGUMENTS],rdx)
            if context.use_context
                mov(qword[rsp+ARG_CONTEXT],rcx)
            // save non-transient gp regs
            let total_gp_save = length(context.gpa.regs) - FIRST_NON_TRANSIENT_GP_TEMP_REG
            if total_gp_save>0
                for t in range(total_gp_save)
                    unsafe
                        let gp_reg = reinterpret<GpTempReg> (t + FIRST_NON_TRANSIENT_GP_TEMP_REG)
                        push(REG64(GEN,gp_reg))
                if (total_gp_save & 1) != 0     // align to 16 bytes
                    push(rax)
            // save non-transient xmm regs
            let total_xmm_save = length(context.xmma.regs) - FIRST_NON_TRANSIENT_XMM_TEMP_REG
            if total_xmm_save>0
                for t in range(total_xmm_save)
                    unsafe
                        let xmm_reg = reinterpret<XmmTempReg> (t + FIRST_NON_TRANSIENT_XMM_TEMP_REG)
                        push(REGXMM(GEN,xmm_reg))
            sub(rsp,(context.stack_frame))
            push(rbp)
            mov(rbp,rsp)
    def gen_epilogue
        with_xbyak(gen) <| $ ( GEN )
            pop(rbp)
            add(rsp,(context.stack_frame))
            // restore non-transient xmm regs
            let total_xmm_save = length(context.xmma.regs) - FIRST_NON_TRANSIENT_XMM_TEMP_REG
            if total_xmm_save>0
                for t in range(total_xmm_save)
                    unsafe
                        let xmm_reg = reinterpret<XmmTempReg> ((total_xmm_save-t) + FIRST_NON_TRANSIENT_XMM_TEMP_REG)
                        pop(REGXMM(GEN,xmm_reg))
            // restore non-transient gp regs
            let total_gp_save = length(context.gpa.regs) - FIRST_NON_TRANSIENT_GP_TEMP_REG
            if total_gp_save>0
                if (total_gp_save & 1) != 0     // align to 16 bytes
                    pop(rax)
                for t in range(total_gp_save)
                    unsafe
                        let gp_reg = reinterpret<GpTempReg> ((total_gp_save-t-1) + FIRST_NON_TRANSIENT_GP_TEMP_REG)
                        pop(REG64(GEN,gp_reg))
            ret()
    def override visitFunction(fun:FunctionPtr) : FunctionPtr
        if fun.result==null || fun.result.isVoid
            gen_epilogue()
        log(")\n")
        return fun
// const int
    def override preVisitExprConstInt(expr:smart_ptr<ExprConstInt>) : void
        log("(INT32 {expr.value})")
    def override visitExprConstInt(expr:smart_ptr<ExprConstInt>) : ExpressionPtr
        with_xbyak(gen) <| $ ( GEN )
            let ev & = unsafe(evResGet(expr))
            if ev is stack
                mov(dword[rbp+(ev as stack)],uint64(expr.value))
        log(")")
        return expr
// let
    def override preVisitExprLetVariable(expr:smart_ptr<ExprLet>;arg:VariablePtr;lastArg:bool) : void
        log("(LET {arg.name} #{arg.stackTop} ")
    def override visitExprLetVariable(expr:smart_ptr<ExprLet>;arg:VariablePtr;lastArg:bool) : VariablePtr
        if arg.init==null
            with_xbyak(gen) <| $ ( GEN )
                let initSize = arg._type.isRef ? 8 : arg._type.sizeOf
                if initSize==1
                    mov(byte[rbp+arg.stackTop],0ul)
                elif initSize==2
                    mov(word[rbp+arg.stackTop],0ul)
                elif initSize==4
                    mov(dword[rbp+arg.stackTop],0ul)
                elif initSize==8
                    mov(qword[rbp+arg.stackTop],0ul)
                else
                    failed("visitExprLetVariable arg.init==null initSize={initSize}",expr.at)
        log(")")
        return arg
    def override visitExprLetVariableInit(blk:smart_ptr<ExprLet>;arg:VariablePtr;expr:ExpressionPtr) : ExpressionPtr
        let evI & = unsafe(evResGet(arg.init))
        if (evI ?as stack ?? -1u)==arg.stackTop
            return expr
        with_xbyak(gen) <| $ ( GEN )
            let initSize = arg._type.isRef ? 8 : arg._type.sizeOf
            if arg.init._type.isRef
                if context.temp_var |> key_exists(intptr(arg))
                    let reg = context.temp_var[intptr(arg)]
                    if initSize==4 || initSize==2 || initSize==1
                        copyRegAnyPtr32(reg,evI,expr.at)
                    else
                        failed("ExprLetVariableInit arg.init._type.ref temp_var {arg.name}:{describe(arg._type)} initSize={initSize}",arg.init.at)
                else
                    if initSize==4
                        copyRegAnyPtr32(GpTempReg RAX, evI, expr.at)   // here here here
                        mov(ptr[rbp+arg.stackTop],eax)
                    else
                        failed("ExprLetVariableInit arg.init._type.ref {arg.name}:{describe(arg._type)} initSize={initSize}",arg.init.at)
            else
                if context.temp_var |> key_exists(intptr(arg))
                    let reg = context.temp_var[intptr(arg)]
                    if initSize==4 || initSize==2 || initSize==1
                        copyRegAny32(reg,evI,expr.at)
                    else
                        failed("ExprLetVariableInit temp_var {arg.name}:{describe(arg._type)} initSize={initSize}",arg.init.at)
                else
                    if initSize==4
                        copyRegAny32(GpTempReg RAX,evI,expr.at)
                        mov(ptr[rbp+arg.stackTop],eax)
                    else
                        failed("ExprLetVariableInit arg.init._type {arg.name}:{describe(arg._type)} initSize={initSize}",arg.init.at)
        return  expr
// variable
    def override preVisitExprVar(expr:smart_ptr<ExprVar>) : void
        log("(VAR {expr.name} ")
        if expr.varFlags.r2v
            log("R2V ")
    def override visitExprVar(expr:smart_ptr<ExprVar>) : ExpressionPtr
        let ev & = unsafe(evResGet(expr))
        with_xbyak(gen) <| $ ( GEN )
            if expr.varFlags._block
                failed("ExprVar expr.varFlags._block {expr.variable.name}:{describe(expr.variable._type)}", expr.at)
            elif expr.varFlags.local
                if context.temp_var |> key_exists(intptr(expr.variable))
                    // this variable is in the register
                    pass
                elif expr.varFlags.r2v
                    let varSize = expr._type.sizeOf
                    if expr.variable._type |> is_gpreg_type
                        let reg = ev as gpReg
                        log("[{reg}]")
                        if varSize==8
                            mov(REG64(GEN,reg),qword[rbp+expr.variable.stackTop])
                        elif varSize==4
                            mov(REG32(GEN,reg),dword[rbp+expr.variable.stackTop])
                        else
                            failed("ExprVar expr.varFlags.local expr.varFlags.r2v {expr.variable.name}:{describe(expr.variable._type)} varSize={varSize}", expr.at)
                    else
                        failed("ExprVar expr.varFlags.local {expr.variable.name}:{describe(expr.variable._type)}", expr.at)
            elif expr.varFlags.argument
                if expr.varFlags.r2v
                    let varSize = expr._type.sizeOf
                    if expr.variable._type |> is_gpreg_type
                        if ev is gpReg
                            let reg = ev as gpReg
                            log("[{reg}]")
                            setRdxToArgs()
                            if varSize==8
                                mov(REG64(GEN,reg),qword[rdx+(expr.argumentIndex*16)])
                            elif varSize==4 || varSize==2 || varSize==1
                                mov(REG32(GEN,reg),dword[rdx+(expr.argumentIndex*16)])
                            else
                                failed("ExprVar expr.varFlags.argument expr.varFlags.r2v {expr.variable.name}:{describe(expr.variable._type)} varSize={varSize}", expr.at)
                        else
                            failed("ExprVar expr.varFlags.argument expr.varFlags.r2v {expr.variable.name}:{describe(expr.variable._type)} (register should be allocated?)", expr.at)
                    else
                        failed("ExprVar expr.varFlags.argument expr.varFlags.r2v {expr.variable.name}:{describe(expr.variable._type)}", expr.at)
                else
                    if ev is gpReg
                        setRdxToArgs()
                        lea(REG64(GEN,ev as gpReg),qword[rdx+(expr.argumentIndex*16)])
                    else
                        failed("ExprVar expr.varFlags.argument {expr.variable.name}:{describe(expr.variable._type)}", expr.at)
            else
                failed("ExprVar {expr.variable.name}:{describe(expr.variable._type)}", expr.at)
        log(")")
        return expr
// op1
    def override preVisitExprOp1(expr:smart_ptr<ExprOp1>) : void
        log("(OP1 {expr.op} ")
    def override visitExprOp1(expr:smart_ptr<ExprOp1>) : ExpressionPtr
        let ev & = unsafe(evResGet(expr.subexpr))
        let evOP1 & = unsafe(evResGet(expr))
        with_xbyak(gen) <| $ ( GEN )
            if expr.subexpr._type.isInteger
                if expr.subexpr._type.baseType==Type tInt || expr.subexpr._type.baseType==Type tUInt
                    if expr.subexpr._type.isRef    // ++, --
                        if ev is gpReg
                            if expr.op=="+++" || expr.op=="---"             // a++
                                mov(eax,dword[REG64(GEN,ev as gpReg)])
                                if expr.op=="+++"
                                    inc(dword[REG64(GEN,ev as gpReg)])
                                else
                                    dec(dword[REG64(GEN,ev as gpReg)])
                                mov(REG32(GEN,ev as gpReg),eax)
                            else
                                failed("ExprOp1 {expr.op} expr.subexpr._type.isRef ev is gpReg", expr.at)
                        elif ev is gpRegT
                            if expr.op=="+++" || expr.op=="---"             // a++
                                assert(evOP1 is gpReg)
                                mov(REG32(GEN,evOP1 as gpReg),REG32(GEN,ev as gpRegT))
                                if expr.op=="+++"
                                    inc(REG32(GEN,ev as gpRegT))
                                else
                                    dec(REG32(GEN,ev as gpRegT))
                            elif expr.op=="++" || expr.op=="--"             // ++a
                                if expr.op=="++"
                                    inc(REG32(GEN,ev as gpRegT))
                                else
                                    dec(REG32(GEN,ev as gpRegT))
                            else
                                failed("ExprOp1 {expr.op} integer expr.subexpr._type.isRef ev is gpRegT", expr.at)
                        elif ev is stack
                            assert(evOP1 is gpReg)
                            if expr.op=="+++" || expr.op=="---"             // a++
                                mov(REG32(GEN,evOP1 as gpReg),dword[rbp+(ev as stack)])
                                if expr.op=="+++"
                                    inc(dword[rbp+(ev as stack)])
                                else
                                    dec(dword[rbp+(ev as stack)])
                            elif expr.op=="++" || expr.op=="--"             // ++a
                                if expr.op=="++"
                                    inc(dword[rbp+(ev as stack)])
                                else
                                    dec(dword[rbp+(ev as stack)])
                                mov(REG32(GEN,evOP1 as gpReg),dword[rbp+(ev as stack)])
                            else
                                failed("ExprOp1 {expr.op} integer expr.subexpr._type.isRef ev is gpRegT", expr.at)
                        else
                            failed("ExprOp1 {expr.op} integer expr.subexpr._type.isRef ev={ev}", expr.at)
                    else
                        failed("ExprOp1 {expr.op} integer !expr.subexpr._type.isRef", expr.at)
                else
                    failed("ExprOp1 {expr.op} integer {describe(expr.subexpr._type)}", expr.at)
            else
                failed("ExprOp1 {expr.op} {describe(expr.subexpr._type)}", expr.at)
        log(")")
        return expr
// op2
    def override preVisitExprOp2(expr:smart_ptr<ExprOp2>): void
        log("(OP2 {expr.op} ")


    def override visitExprOp2(expr:smart_ptr<ExprOp2>) : ExpressionPtr
        let evOP2 &  = unsafe(evResGet(expr))
        let evL & = unsafe(evResGet(expr.left))
        let evR & = unsafe(evResGet(expr.right))
        with_xbyak(gen) <| $ ( GEN )
            if expr.left._type.isInteger
                if expr.left._type.baseType==Type tInt
                    if expr.left._type.isRef
                        let pvar = (expr.left is ExprVar) ? get_ptr((expr.left as ExprVar).variable) : null
                        if context.temp_var |> key_exists(intptr(pvar))
                            let reg = context.temp_var[intptr(pvar)]
                            if expr.op=="+="
                                addRegAny32(reg,evR,expr.at)
                            elif expr.op=="-="
                                subRegAny32(reg,evR,expr.at)
                            elif expr.op=="*="
                                imulRegAny32(reg,evR,expr.at)
                            elif expr.op=="/=" || expr.op=="%="
                                idivRegAny32(reg,evR,intptr(expr), expr.op=="%=" ? DivResults need_rdx : DivResults need_rax,expr.at)
                                copyRegReg32(reg,expr.op=="%=" ? GpTempReg RDX : GpTempReg RAX, expr.at)
                            else
                                failed("ExprOp2 {expr.op} expr.left._type.isInteger integer expr.left._type.isRef", expr.at)
                        elif evL is stack
                            let iSP = evL as stack
                            if expr.op=="+="
                                addStackAny32(iSP,evR,expr.at)
                            elif expr.op=="-="
                                subStackAny32(iSP,evR,expr.at)
                            elif expr.op=="*="
                                imulStackAny32(iSP,evR,expr.at)
                            elif expr.op=="/=" || expr.op=="%="
                                idivStackAny32(iSP,evR,intptr(expr),expr.op=="%=" ? DivResults need_rdx : DivResults need_rax,expr.at)
                                mov(dword[rbp+iSP], expr.op=="/=" ? eax : edx)
                            else
                                failed("ExprOp2 {expr.op} expr.left._type.isInteger integer expr.left._type.isRef [rbp+{iSP}]...", expr.at)
                        else
                            failed("ExprOp2 {expr.op} expr.left._type.isInteger integer expr.left._type.isRef evL={evL}", expr.at)
                    else
                        if evOP2 is cmp
                            if expr.op=="<" || expr.op=="<=" || expr.op=="==" || expr.op=="!=" || expr.op==">=" || expr.op==">"
                                alignForIntelJccErratum()
                                cmpAnyAny32(evL,evR,evOP2 as cmp,GpTempReg BROKEN,expr.at)  // do not spill!
                                log(" [{evL}]")
                            else
                                failed("ExprOp2 {expr.op} expr.left._type.isInteger integer cmp", expr.at)
                        else
                            if (expr.op=="-" || expr.op=="+" || expr.op=="*" || expr.op=="/" || expr.op=="%" ||
                                expr.op=="<" || expr.op=="<=" || expr.op=="==" || expr.op=="!=" || expr.op==">=" || expr.op==">")
                                if evL is gpReg
                                    // result is in the left register, which we reused during allocation
                                    if expr.op=="/" || expr.op=="%"
                                        idivRegAny32(evL as gpReg, evR, intptr(expr), expr.op=="%" ? DivResults need_rdx : DivResults need_rax, expr.at)
                                        copyRegReg32(evL as gpReg,expr.op=="%" ? GpTempReg RDX : GpTempReg RAX, expr.at)
                                    elif expr.op=="+"
                                        addRegAny32(evL as gpReg, evR, expr.at)
                                    elif expr.op=="-"
                                        subRegAny32(evL as gpReg, evR, expr.at)
                                    elif expr.op=="*"
                                        imulRegAny32(evL as gpReg, evR, expr.at)
                                    elif expr.op=="<" || expr.op=="<=" || expr.op=="==" || expr.op=="!=" || expr.op==">=" || expr.op==">"
                                        let cop = getCompareOp(expr.op)
                                        cmpRegAny32(evL as gpReg, evR, cop, expr.at)
                                        if expr.op=="<"
                                            setl(al)
                                        elif expr.op=="<="
                                            setle(al)
                                        elif expr.op=="=="
                                            sete(al)
                                        elif expr.op=="!="
                                            setne(al)
                                        elif expr.op==">="
                                            setge(al)
                                        elif expr.op==">"
                                            setg(al)
                                        else
                                            failed("ExprOp2 {expr.op} expr.left._type.isInteger integer evL is gpReg, evR is iconst bool", expr.at)
                                        movzx(REG32(GEN,evL as gpReg),al)
                                    else
                                        failed("ExprOp2 {expr.op} expr.left._type.isInteger integer evL is gpReg, evR={evR}", expr.at)
                                    log(" [{evL}]")
                                else
                                    // result is in the result register, which we allocated separately
                                    assert(evOP2 is gpReg)
                                    if expr.op=="/" || expr.op=="%"
                                        if (evL is gpReg) || (evL is gpRegT)
                                            let regL = (evL is gpReg) ? (evL as gpReg) : (evL as gpRegT)
                                            idivRegAny32(regL, evR, intptr(expr), expr.op=="%" ? DivResults need_rdx : DivResults need_rax, expr.at)
                                        else
                                            failed("ExprOp2 {expr.op} expr.left._type.isInteger integer evOP2 is gpReg, evL={evL} evR={evR}", expr.at)
                                        copyRegReg32(evOP2 as gpReg,expr.op=="%" ? GpTempReg RDX : GpTempReg RAX, expr.at)
                                    elif (expr.op=="+" || expr.op=="-") && ((evL is gpRegT) || (evL is gpReg)) && (evR is iconst)
                                        // lea r1,[r2+C]
                                        // note: when optimizations are enabled, C+r2 cases will be flipped by the compiler
                                        let regL = (evL is gpReg) ? (evL as gpReg) : (evL as gpRegT)
                                        if expr.op=="+"
                                            lea(REG32(GEN,evOP2 as gpReg),ptr[REG32(GEN,regL)+uint(evR as iconst)])
                                        elif expr.op=="-"
                                            lea(REG32(GEN,evOP2 as gpReg),ptr[REG32(GEN,regL)-uint(evR as iconst)])
                                        else
                                            failed("ExprOp2 {expr.op} expr.left._type.isInteger integer evOP2 is gpReg, evL s gpRegT && evR is iconst", expr.at)
                                    elif (expr.op=="+") && ((evL is gpRegT) || (evL is gpReg)) && ((evR is gpRegT) || (evR is gpReg))
                                        // lea r1,[r2+r3]
                                        let regL = (evL is gpReg) ? (evL as gpReg) : (evL as gpRegT)
                                        let regR = (evR is gpReg) ? (evR as gpReg) : (evR as gpRegT)
                                        lea(REG32(GEN,evOP2 as gpReg),dword[REG32(GEN,regL)+REG32(GEN,regR)])
                                    else
                                        copyRegAny32(evOP2 as gpReg,evL,expr.at)
                                        if expr.op=="+"
                                            addRegAny32(evOP2 as gpReg,evR,expr.at)
                                        elif expr.op=="-"
                                            subRegAny32(evOP2 as gpReg,evR,expr.at)
                                        elif expr.op=="*"
                                            imulRegAny32(evOP2 as gpReg,evR,expr.at)
                                        else
                                            failed("ExprOp2 {expr.op} expr.left._type.isInteger integer evOP2 is gpReg, evR={evR}", expr.at)
                            else
                                failed("ExprOp2 {expr.op} expr.left._type.isInteger integer", expr.at)
                else
                    failed("ExprOp2 {expr.op} expr.left._type.isInteger {describe(expr.left._type)}", expr.at)
            else
                failed("ExprOp2 {expr.op} {describe(expr.left._type)}", expr.at)
        log(")")
        return expr
// if-then-else
    /*
    1. if if_false is not null, and there is an 'else' section
        if cond
                cmp ???
                jne if_cond_faild
                if_true
                goto if_end
            .if_consd_failed:
                if_false
            .if_end:
    2. if if_false is null, and there is no 'else' section
        if cond
                cmp ???
                jne if_end
                if_true
            .if_end:
    */
    def override preVisitExprIfThenElse(expr:smart_ptr<ExprIfThenElse>) : void
        if verbose
            tab ++
            print("(IF\n{repeat("\t",tab)}")
    def override preVisitExprIfThenElseIfBlock(expr:smart_ptr<ExprIfThenElse>;ifBlock:ExpressionPtr) : void
        let evS & = unsafe(evResGet(expr.cond))
        with_xbyak(gen) <| $ ( GEN )
            if evS is gpReg
                alignForIntelJccErratum()
                test(REG32(GEN,evS as gpReg),REG32(GEN,evS as gpReg))
                if expr.if_false==null
                    jz("if_end_{intptr(expr)}",LabelType T_AUTO)
                else
                    jz("if_cond_failed_{intptr(expr)}",LabelType T_AUTO)
            elif evS is cmp
                if expr.if_false==null
                    GEN |> condJumpIfNot("if_end_{intptr(expr)}",evS as cmp)
                else
                    GEN |> condJumpIfNot("if_cond_failed_{intptr(expr)}",evS as cmp)
            else
                failed("ExprIfThenElse evS={evS}", expr.at)
        log("\n{repeat("\t",tab)}THEN\n")
    def override preVisitExprIfThenElseElseBlock(expr:smart_ptr<ExprIfThenElse>;elseBlock:ExpressionPtr) : void
        // we are only here, if there is an else block
        with_xbyak(gen) <| $ ( GEN )
            jmp("if_end_{intptr(expr)}",LabelType T_AUTO)
            Label("if_cond_failed_{intptr(expr)}");  rdx_has_args = false
        log("\n{repeat("\t",tab)}ELSE\n")
    def override visitExprIfThenElse(expr:smart_ptr<ExprIfThenElse>) : ExpressionPtr
        with_xbyak(gen) <| $ ( GEN )
            Label("if_end_{intptr(expr)}");  rdx_has_args = false
        if verbose
            tab --
            print(")\n{repeat("\t",tab)}")
        return expr
// op3
/*
    cmp ???
    jn  .cond_right
    result = cond_left
    jmp .cond_end
.cond_right:
    result = cond_right
.cond_end:
*/
    def override preVisitExprOp3(expr:smart_ptr<ExprOp3>): void
        log("(? ")
    def override preVisitExprOp3Left(expr:smart_ptr<ExprOp3>;left:ExpressionPtr): void
        let evS & = unsafe(evResGet(expr.subexpr))
        with_xbyak(gen) <| $ ( GEN )
            if evS is gpReg
                alignForIntelJccErratum()
                test(REG32(GEN,evS as gpReg),REG32(GEN,evS as gpReg))
                jz("cond_right_{intptr(expr)}",LabelType T_AUTO)
            elif evS is cmp
                GEN |> condJumpIfNot("cond_right_{intptr(expr)}",evS as cmp)
            else
                failed("supprt cond subexpr in {evS}", expr.at)
        log(" ? ")
    def override preVisitExprOp3Right(expr:smart_ptr<ExprOp3>;right:ExpressionPtr): void
        let eV & = unsafe(evResGet(expr))
        let evL & = unsafe(evResGet(expr.left))
        with_xbyak(gen) <| $ ( GEN )
            copyRegAny32(eV as gpReg,evL,expr.at)
            jmp("cond_end_{intptr(expr)}",LabelType T_AUTO)
            Label("cond_right_{intptr(expr)}");  rdx_has_args = false
        log(" : ")
    def override visitExprOp3(expr:smart_ptr<ExprOp3>) : ExpressionPtr
        let eV & = unsafe(evResGet(expr))
        let evR & = unsafe(evResGet(expr.right))
        with_xbyak(gen) <| $ ( GEN )
            copyRegAny32(eV as gpReg,evR,expr.at)
            Label("cond_end_{intptr(expr)}");  rdx_has_args = false
        log(")")
        return expr
// copy
    def override preVisitExprCopy(expr:smart_ptr<ExprCopy>): void
        log("(COPY ")
    def override visitExprCopy(expr:smart_ptr<ExprCopy>) : ExpressionPtr
        let evL & = unsafe(evResGet(expr.left))
        let evR & = unsafe(evResGet(expr.right))
        log("EVL={evL},EVR={evR} ")
        with_xbyak(gen) <| $ ( GEN )
            let copySize = expr.left._type.sizeOf
            let pvar = (expr.left is ExprVar) ? get_ptr((expr.left as ExprVar).variable) : null
            if context.temp_var |> key_exists(intptr(pvar))
                let reg = context.temp_var[intptr(pvar)]
                if expr.right._type.isRef
                    if copySize==4
                        copyRegAnyPtr32(reg,evR,expr.at)
                    else
                        failed("ExprCopy temp expr.right._type.isRef {reg} copySize={copySize}", expr.at)
                    log("(REF COPY {copySize})")
                else
                    failed("ExprCopy temp {reg}", expr.at)
            else
                if expr.right._type.isRef
                    if copySize==4
                        copyRegAnyPtr32(GpTempReg RAX,evR,expr.at)
                        copyAnyPtrReg32(evL,GpTempReg RAX,expr.at)
                    else
                        failed("ExprCopy expr.right._type.isRef copySize={copySize}", expr.at)
                    log("(REF COPY {copySize})")
                else
                    failed("ExprCopy !expr.right._type.isRef", expr.at)
        log(")")
        return expr
// return
    def override preVisitExprReturn(expr:smart_ptr<ExprReturn>) : void
        log("(RETURN ")
    def override visitExprReturn(expr:smart_ptr<ExprReturn>) : ExpressionPtr
        log(")")
        with_xbyak(gen) <| $ ( GEN )
            if expr.subexpr==null
                gen_epilogue()
            elif expr.returnFlags.returnReference
                failed("ExprReturn expr.returnFlags.returnReference", expr.at)
            elif expr.returnFlags.returnInBlock
                failed("ExprReturn expr.returnFlags.returnInBlock", expr.at)
            elif expr.returnFlags.returnCallCMRES
                failed("ExprReturn expr.returnFlags.returnCallCMRES", expr.at)
            elif expr.returnFlags.returnCMRES
                failed("ExprReturn expr.returnFlags.returnCMRES", expr.at)
            elif expr.returnFlags.takeOverRightStack
                failed("ExprReturn expr.returnFlags.takeOverRightStack", expr.at)
            else
                let evR & = unsafe(evResGet(expr.subexpr))
                if length(expr.subexpr._type.dim)!=0
                    failed("ExprReturn expr.subexpr._type.dim", expr.at)
                if expr.subexpr._type |> is_gpreg_type
                    let returnSize = expr.subexpr._type.sizeOf
                    if returnSize==1 || returnSize==2 || returnSize==4
                        if evR is gpReg
                            movd(xmm0,REG32(GEN,evR as gpReg))
                        elif evR is gpRegT
                            movd(xmm0,REG32(GEN,evR as gpRegT))
                        elif evR is iconst
                            mov(eax,evR as iconst)
                            movd(xmm0,eax)
                        else
                            failed("ExprReturn evR={evR}", expr.at)
                    else
                        failed("ExprReturn returnSize={returnSize}", expr.at)
                else
                    failed("ExprReturn {describe(expr.subexpr._type)}",expr.at)
            gen_epilogue()
        return expr
// block
    def override preVisitExprBlock(blk:smart_ptr<ExprBlock>) : void
        tab ++
    def override visitExprBlock(blk:smart_ptr<ExprBlock>) : ExpressionPtr
        tab --
        return blk
    def override preVisitExprBlockExpression(blk:smart_ptr<ExprBlock>;expr:ExpressionPtr): void
        log("{repeat("\t",tab)}")
    def override visitExprBlockExpression(blk:smart_ptr<ExprBlock>;expr:ExpressionPtr) : ExpressionPtr
        log("\n")
        return expr
// for
    def override preVisitExprFor(expr:smart_ptr<ExprFor>) : void
        log("(FOR ")
        loop_stack |> push(intptr(expr))
        if is_for_range1(expr)
            pass
        else
            failed("ExprFor !is_for_range1",expr.at)
    def override preVisitExprForVariable(expr:smart_ptr<ExprFor>;svar:VariablePtr;last:bool) : void
        log("`{svar.name}` ")
    def override preVisitExprForSource(expr:smart_ptr<ExprFor>;source:ExpressionPtr;last:bool) : void
        log("(SOURCE ")
    def override visitExprForSource(expr:smart_ptr<ExprFor>;source:ExpressionPtr;last:bool) : ExpressionPtr
        if is_for_range1(expr)
            let evS & = unsafe(evResGet(source))
            with_xbyak(gen) <| $ ( GEN )
                if evS is xmmReg
                    let reg & = unsafe(REGXMM(GEN,evS as xmmReg))
                    if context.temp_var |> key_exists(intptr(expr.iteratorVariables[0]))
                        let RV = context.temp_var[intptr(expr.iteratorVariables[0])]
                        if is_for_range1_with_unused_var(expr)
                            movd(eax,reg)
                            shufps(reg,reg,_MM_SHUFFLE(1,1,1,1))
                            movd(REG32(GEN,RV),reg)
                            sub(REG32(GEN,RV),eax)
                            jle("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                        else
                            movd(REG32(GEN,RV),reg)
                            shufps(reg,reg,_MM_SHUFFLE(1,1,1,1))
                            movd(eax,reg)
                            alignForIntelJccErratum()
                            cmp(eax,REG32(GEN,RV))
                            jle("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                    else
                        let iSP = expr.iteratorVariables[0].stackTop
                        if is_for_range1_with_unused_var(expr)
                            movd(eax,reg)
                            shufps(reg,reg,_MM_SHUFFLE(1,1,1,1))
                            movd(ecx,reg)   // for source - when on the stack - USES ECX
                            sub(ecx,eax)
                            mov(dword[rbp+iSP],ecx)
                            jle("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                        else
                            movd(eax,reg)
                            mov(dword[rbp+iSP],eax)
                            shufps(reg,reg,_MM_SHUFFLE(1,1,1,1))
                            movd(ecx,reg)   // for source - when on the stack - USES ECX
                            alignForIntelJccErratum()
                            cmp(ecx,eax)
                            jle("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                elif evS is skip
                    let rA = source as ExprCall
                    let rA0 & = unsafe(evResGet(rA.arguments[0]))
                    if context.temp_var |> key_exists(intptr(expr.iteratorVariables[0]))
                        let RV = context.temp_var[intptr(expr.iteratorVariables[0])]
                        if is_for_range1_with_unused_var(expr)
                            if length(rA.arguments)==1
                                copyRegAny32(RV, rA0, expr.at)
                                alignForIntelJccErratum()
                                test(REG32(GEN,RV),REG32(GEN,RV))
                                jz("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                            else
                                let rA1 & = unsafe(evResGet(rA.arguments[1]))
                                copyRegAny32(RV, rA1, expr.at)
                                if rA0 is gpReg
                                    alignForIntelJccErratum()
                                    sub(REG32(GEN,RV),REG32(GEN,rA0 as gpReg))
                                elif rA0 is gpRegT
                                    alignForIntelJccErratum()
                                    sub(REG32(GEN,RV),REG32(GEN,rA0 as gpRegT))
                                else
                                    copyRegAny32(GpTempReg RAX, rA0, expr.at)
                                    alignForIntelJccErratum()
                                    sub(REG32(GEN,RV),eax)
                                jle("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                        else
                            if length(rA.arguments)==1
                                sub(REG32(GEN,RV),REG32(GEN,RV))
                                if rA0 is gpReg
                                    alignForIntelJccErratum()
                                    test(REG32(GEN,rA0 as gpReg),REG32(GEN,rA0 as gpReg))
                                elif rA0 is gpRegT
                                    alignForIntelJccErratum()
                                    test(REG32(GEN,rA0 as gpRegT),REG32(GEN,rA0 as gpRegT))
                                else
                                    copyRegAny32(GpTempReg RAX, rA0, expr.at)
                                    alignForIntelJccErratum()
                                    test(eax,eax)
                                jz("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                            else
                                let rA1 & = unsafe(evResGet(rA.arguments[1]))
                                copyRegAny32(RV, rA0, expr.at)
                                alignForIntelJccErratum()
                                cmpAnyReg32(rA1,RV,CompareType less_equals,GpTempReg RAX,expr.at)
                                jle("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                    else
                        let iSP = expr.iteratorVariables[0].stackTop
                        if is_for_range1_with_unused_var(expr)
                            if length(rA.arguments)==1
                                copyRegAny32(GpTempReg RAX, rA0, expr.at)
                                mov(dword[rbp+iSP],eax)
                                alignForIntelJccErratum()
                                test(eax,eax)
                                jz("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                            else
                                let rA1 & = unsafe(evResGet(rA.arguments[1]))
                                copyRegAny32(GpTempReg RAX, rA0, expr.at)
                                copyRegAny32(GpTempReg RCX, rA1, expr.at)  //  range(a,b) when loop variables are on the stack - USES ECX
                                sub(ecx,eax)
                                mov(dword[rbp+iSP],ecx)
                                jle("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                        else
                            if length(rA.arguments)==1
                                copyRegAny32(GpTempReg RAX, rA0, expr.at)
                                mov(dword[rbp+iSP],0ul)
                                alignForIntelJccErratum()
                                test(eax,eax)
                                jz("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                            else
                                let rA1 & = unsafe(evResGet(rA.arguments[1]))
                                copyRegAny32(GpTempReg RAX, rA0, expr.at)
                                mov(dword[rbp+iSP],eax)
                                alignForIntelJccErratum()
                                cmpAnyReg32(rA1,GpTempReg RAX,CompareType less_equals,GpTempReg BROKEN,expr.at)
                                jle("for_loop_done_{intptr(expr)}",LabelType T_AUTO)
                else
                    failed("ExprFor is_for_range1 evS={evS}",expr.at)
        else
            failed("ExprFor !is_for_range1",expr.at)
        log(")")
        return source
    def override preVisitExprForBody(expr:smart_ptr<ExprFor>) : void
        with_xbyak(gen) <| $ ( GEN )
            align(16ul,true)
            Label("for_loop_{intptr(expr)}");  rdx_has_args = false
        log("\n")
    def override visitExprFor(expr:smart_ptr<ExprFor>) : ExpressionPtr
        if is_for_range1(expr)
            let evS & = unsafe(evResGet(expr.sources[0]))
            with_xbyak(gen) <| $ ( GEN )
                Label("for_loop_continue_{intptr(expr)}");  rdx_has_args = false
                let iSP = expr.iteratorVariables[0].stackTop
                if (evS is xmmReg) || (evS is skip)
                    if context.temp_var |> key_exists(intptr(expr.iteratorVariables[0]))
                        let RV = context.temp_var[intptr(expr.iteratorVariables[0])]
                        if is_for_range1_with_unused_var(expr)
                            alignForIntelJccErratum()
                            dec(REG32(GEN,RV))
                        else
                            inc(REG32(GEN,RV))
                            if evS is xmmReg
                                movd(eax,REGXMM(GEN,evS as xmmReg))
                                alignForIntelJccErratum()
                                cmp(REG32(GEN,RV),eax)
                            else
                                let ra = expr.sources[0] as ExprCall
                                let rA & = unsafe(evResGet(ra.arguments[length(ra.arguments)==1 ? 0 : 1]))
                                alignForIntelJccErratum()
                                cmpRegAny32(RV,rA,CompareType not_equals,expr.at)
                    else
                        if is_for_range1_with_unused_var(expr)
                            alignForIntelJccErratum()
                            dec(dword[rbp+iSP])
                        else
                            inc(dword[rbp+iSP])
                            if evS is xmmReg
                                movd(eax,REGXMM(GEN,evS as xmmReg))
                                alignForIntelJccErratum()
                                cmp(dword[rbp+iSP],eax)
                            else
                                let ra = expr.sources[0] as ExprCall
                                let rA & = unsafe(evResGet(ra.arguments[length(ra.arguments)==1 ? 0 : 1]))
                                alignForIntelJccErratum()
                                cmpStackAny32(int(iSP),rA,CompareType not_equals,GpTempReg RAX,expr.at)
                    jnz("for_loop_{intptr(expr)}",LabelType T_AUTO)
                else
                    failed("ExprFor is_for_range1 evS={evS}",expr.at)
        else
            failed("ExprFor !is_for_range1",expr.at)
        with_xbyak(gen) <| $ ( GEN )
            Label("for_loop_done_{intptr(expr)}");  rdx_has_args = false
        loop_stack |> pop()
        log("{repeat("\t",tab)})")
        return expr
// break
    def override visitExprBreak(expr:smart_ptr<ExprBreak>) : ExpressionPtr
        log("(BREAK)")
        let loop_ptr = loop_stack |> back
        with_xbyak(gen) <| $ ( GEN )
            jmp("for_loop_done_{loop_ptr}",LabelType T_AUTO)
        return expr
// continue
    def override visitExprContinue(expr:smart_ptr<ExprContinue>) : ExpressionPtr
        log("(CONTINUE)")
        let loop_ptr = loop_stack |> back
        with_xbyak(gen) <| $ ( GEN )
            jmp("for_loop_continue_{loop_ptr}",LabelType T_AUTO)
        return expr
// call
    def override preVisitExprCall(expr:smart_ptr<ExprCall>): void
        log("(CALL `{expr.name}` ")
        if !expr.func.flags.builtIn
            with_xbyak(gen) <| $ ( GEN )
                let frame = uint(expr.arguments |> length) * 16u
                if frame != 0u
                    sub(rsp,frame)
    def override visitExprCall(var expr:smart_ptr<ExprCall>) : ExpressionPtr
        if !expr.func.flags.builtIn
            rdx_has_args = false            // rdx no longer has args, since we call another function
            with_xbyak(gen) <| $ ( GEN )
                for ai in range(length(expr.arguments))
                    let asize = expr.arguments[ai]._type.isRef ? 8 : expr.arguments[ai]._type.sizeOf
                    let eA & = unsafe(evResGet(expr.arguments[ai]))
                    if eA is gpReg
                        if asize==4
                            mov(dword[rsp+uint(ai)*16u],REG32(GEN,eA as gpReg))
                        elif asize==8
                            mov(qword[rbp+uint(ai)*16u],REG64(GEN,eA as gpReg))
                        else
                            error("ExprCall eA is gpReg, asize={asize}",expr.at)
                    elif eA is gpRegT
                        if asize==4
                            mov(dword[rsp+uint(ai)*16u],REG32(GEN,eA as gpRegT))
                        elif asize==8
                            mov(qword[rsp+uint(ai)*16u],REG64(GEN,eA as gpRegT))
                        else
                            error("ExprCall eA is gpRegT, asize={asize}",expr.at)
                    elif eA is iconst
                        if asize==4
                            mov(dword[rsp+uint(ai)*16u],eA as iconst)
                        elif asize==8
                            mov(qword[rsp+uint(ai)*16u],eA as iconst)
                        else
                            error("ExprCall eA is iconst, asize={asize}",expr.at)
                    else
                        error("ExprCall eA={eA}",expr.at)
                // rdx is ARGS
                lea(rdx,ptr[rsp])
                var MNH_ADDR : uint64
                unsafe
                    let mangled_name = get_mangled_name(reinterpret<FunctionPtr> expr.func)
                    let MNH = hash(mangled_name)
                    MNH_ADDR = get_function_address(MNH)
                log(" @@{MNH_ADDR} ")
                // save used transient registers
                let recursive_call = expr.func == this_function
                let transients = context.transients[intptr(expr)]
                var t_offset = 0u
                var t_total = 0
                log(" GP_MASK={transients.gp_mask} XMM_MASK={transients.xmm_mask}\n")
                var xmm_total = 0u
                for t in urange(FIRST_NON_TRANSIENT_XMM_TEMP_REG)
                    if (transients.xmm_mask & (1u<<t)) != 0u
                        xmm_total ++
                if xmm_total != 0u                                  // TODO: if no gp transients and xmm transients, we generate double sub(rbp,const)
                    sub(rsp,xmm_total * 16u)
                for t in urange(FIRST_NON_TRANSIENT_XMM_TEMP_REG)
                    if (transients.xmm_mask & (1u<<t)) != 0u
                        var txmm : XmmTempReg
                        unsafe
                            txmm = reinterpret<XmmTempReg> t
                        movdqa(ptr[rbp+t_offset],REGXMM(GEN,txmm))
                        t_offset += 16u
                for t in urange(FIRST_NON_TRANSIENT_GP_TEMP_REG)
                    if (transients.gp_mask & (1u<<t)) != 0u
                        var tgpr : GpTempReg
                        unsafe
                            tgpr = reinterpret<GpTempReg> t
                        push(REG64(GEN,tgpr))
                        t_offset += 8u
                        t_total ++
                if recursive_call
                    // setup arguments
                    let ctx_offset = getContextOffset()
                    if context.use_context                      // in recursive call, if context is not used - don't pass
                        mov(rcx,qword[rbp+ctx_offset])          // rcx is Context *
                    // sub(r8,r8)                               // r8 is CMRES
                else
                    // setup arguments
                    let ctx_offset = getContextOffset()          // any non-recursive call -USES ECX
                    mov(rcx,uint64(MNH_ADDR))                    // rcx is MNH
                    mov(r8,ptr[rbp+ctx_offset])                  // r8  is Context *
                // call must be aligned, so if even number of transient registers is saved - we add extra 8 bytes
                sub(rsp,(t_total & 1) != 0 ? 40u : 32u)
                if recursive_call
                    call(func_begin)
                else
                    mov(rax,JIT_call_or_fastcall())
                    call(rax)
                // restore used transient registers
                add(rsp,(t_total & 1) != 0 ? 40u : 32u)
                for i_t in urange(FIRST_NON_TRANSIENT_GP_TEMP_REG)
                    let t = uint(FIRST_NON_TRANSIENT_GP_TEMP_REG) - i_t - 1u
                    if (transients.gp_mask & (1u<<t)) != 0u
                        unsafe
                            let tgpr = reinterpret<GpTempReg> t
                            pop(REG64(GEN,tgpr))
                var rt_offset = 0u
                for t in urange(FIRST_NON_TRANSIENT_XMM_TEMP_REG)
                    if (transients.xmm_mask & (1u<<t)) != 0u
                        var txmm : XmmTempReg
                        unsafe
                            txmm = reinterpret<XmmTempReg> t
                        movdqa(REGXMM(GEN,txmm),ptr[rbp+rt_offset])
                        rt_offset += 16u
                if xmm_total != 0u                                          // TODO: if no gp transients and xmm transients, we generate double add(rbp,const)
                    add(rsp,xmm_total * 16u)
                // restore call frame
                let frame = uint(expr.arguments |> length) * 16u
                if frame != 0u
                    add(rsp,frame)
                // move result to xmm0
                if expr.func.result != null
                    if expr.func.result.isRef
                        error("ExprCall expr.func.result.isRef",expr.at)
                    elif expr.func.result.isVoid
                        pass    // if void - no output
                    else
                        let fnR & = unsafe(evResGet(expr))
                        let asize = expr.func.result.sizeOf
                        if fnR is gpReg
                            if asize==4 || asize==2 || asize==1
                                movd(REG32(GEN,fnR as gpReg),xmm0)
                            elif asize==8
                                mov(REG64(GEN,fnR as gpReg),xmm0)
                            else
                                error("ExprCall rsize={asize}",expr.at)
                        else
                            error("ExprCall fnR={fnR}",expr.at)
            return expr
        ////////////////////
        // TODO: calls table
        let call_name = "{expr.func._module.name}::{expr.func.name}"
        if call_name=="$::range"
            JIT`range(expr)
        log(")")
        return expr
    /////////////////////
    // function templates
    def JIT`range(var expr:smart_ptr<ExprCall>)
        with_xbyak(gen) <| $ ( GEN )
            let evR & = unsafe(evResGet(expr))
            if evR is skip  // if skip is set, someone else is taking over the result and wants inputs
                return
            let xreg = evR as xmmReg
            // range(int)
            if length(expr.arguments)==1 && expr.arguments[0]._type.baseType==Type tInt
                let evA0 & = unsafe(evResGet(expr.arguments[0]))
                if evA0 is gpReg
                    shl(REG64(GEN,evA0 as gpReg),32)
                    movd(REGXMM(GEN,xreg),REG32(GEN,evA0 as gpReg))
                elif evA0 is gpRegT
                    shl(REG64(GEN,evA0 as gpRegT),32)
                    movd(REGXMM(GEN,xreg),REG32(GEN,evA0 as gpRegT))
                else
                    copyRegAny32(GpTempReg RAX,evA0,expr.at)
                    shl(rax,32)
                    movd(REGXMM(GEN,xreg),eax)
            // range(int,int)
            elif length(expr.arguments)==2 && expr.arguments[0]._type.baseType==Type tInt && expr.arguments[1]._type.baseType==Type tInt
                rdx_has_args = false
                let evA0 & = unsafe(evResGet(expr.arguments[0]))
                let evA1 & = unsafe(evResGet(expr.arguments[1]))
                copyRegAny32(GpTempReg RDX,evA1,expr.at)
                copyRegAny32(GpTempReg RAX,evA0,expr.at)
                shl(rax,32)
                shrd(rax,rdx,uint8(32))
                movd(REGXMM(GEN,xreg),eax)
            log(" [{xreg}]")

