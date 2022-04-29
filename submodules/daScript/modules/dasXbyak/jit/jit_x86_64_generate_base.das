options no_unused_block_arguments = false
options no_unused_function_arguments = false
options indenting = 4

module jit_x86_64_generate_base shared public

require jit_x86_64_regs
require jit_x86_64_common

require daslib/ast_boost
require daslib/strings_boost
require daslib/templates_boost
require math

require dasxbyak/xbyak_boost
require xbyak public
require zydis

require ast public

enum DivResults
    need_rax
    need_rdx
    need_rax_rdx

class GenerateCodeVisitorBase : JitVisitor
    assume_no_exceptions : bool = false
    [[do_not_delete]] gen : CodeGenerator?
    rdx_has_args : bool                             // rdx contains arg *, as part of the parameters passed
    def GenerateCodeVisitorBase(var g:CodeGenerator?; var ctx:EvContext )
        JitVisitor`JitVisitor(self, ctx)
        gen = g
// label
    def Label(name:string)
        *gen |> L(name)
        context.labels[*gen |> get_current_address] = name
// ABI
    def getContextOffset
        return context.stack_frame+context.save_frame+8u+ARG_CONTEXT
    def getArgOffset
        return context.stack_frame+context.save_frame+8u+ARG_ARGUMENTS
    def getCmresOffset
        return context.stack_frame+context.save_frame+8u+ARG_CMRES
// exception
    def JIT`exception(text:string):void
        with_xbyak(gen) <| $ ( GEN )
            let ctx_offset = getContextOffset()
            mov(rcx,jit_generate_const_string(text))    // rcx is exception text
            mov(rdx,ptr[rbp+ctx_offset])                // rdx is Context *
            sub(rbp,32u)
            mov(rax,JIT_exception())
            call(rax)
            add(rbp,32u)
// CPU bugfixes and workaround
    def alignForIntelJccErratum ( macro_size : uint64 = 5ul )   // cmp-jmp or inc-jmp are 5 bytes
        var ofs = *gen |> get_current_address()
        let a1 = ofs & ~31ul
        let a2 = (ofs + macro_size) & ~31ul
        if a1 != a2
            if verbose
                log("\njcc-erratum at {ofs}\n")
            *gen |> align(32ul,true)
// copy
    def copyRegReg32 ( dest,src:GpTempReg; at:LineInfo ) : void                                                //  mov reg32, reg32
        if dest==src
            return
        with_xbyak(gen) <| $ ( GEN )
            if dest != src
                mov(REG32(GEN,dest),REG32(GEN,src))
    def copyRegAny32 ( dest:GpTempReg; srcV:EvResult; at:LineInfo ) : void                                         //  mov reg32, data
        with_xbyak(gen) <| $ ( GEN )
            if srcV is gpReg
                if dest != (srcV as gpReg)
                    mov(REG32(GEN,dest),REG32(GEN,srcV as gpReg))
            elif srcV is gpRegT
                if dest != (srcV as gpRegT)
                    mov(REG32(GEN,dest),REG32(GEN,srcV as gpRegT))
            elif srcV is iconst
                mov(REG32(GEN,dest),srcV as iconst)
            elif srcV is stack
                mov(REG32(GEN,dest),ptr[rbp+(srcV as stack)])
            else
                failed("copyRegAny32 mov({dest},{srcV})", at)
    def copyRegAnyPtr32 ( dest:GpTempReg; srcV:EvResult; at:LineInfo ) : void                                         //  mov reg32, data
        with_xbyak(gen) <| $ ( GEN )
            if srcV is gpReg
                mov(REG32(GEN,dest),dword[REG64(GEN,srcV as gpReg)])
            elif srcV is gpRegT
                if dest != (srcV as gpRegT)
                    mov(REG32(GEN,dest),REG32(GEN,srcV as gpRegT))
            elif srcV is stack
                mov(REG64(GEN,dest),qword[rbp+(srcV as stack)])
            else
                failed("copyRegAnyPtr32 mov({dest},{srcV})", at)
    def copyAnyPtrReg32 ( destV:EvResult; src:GpTempReg; at:LineInfo ) : void                                         //  mov reg32, data
        with_xbyak(gen) <| $ ( GEN )
            if destV is gpReg
                mov(dword[REG64(GEN,destV as gpReg)],REG32(GEN,src))
            elif destV is gpRegT
                if src != (destV as gpRegT)
                    mov(REG32(GEN,destV as gpRegT),REG32(GEN,src))
            elif destV is stack
                mov(qword[rbp+(destV as stack)],REG32(GEN,src))
            else
                failed("copyAnyPtrReg32 mov({destV},{src})", at)
// cmp
    def cmpRegAny32 ( left:GpTempReg; right:EvResult; cop:CompareType; at:LineInfo ) : void                      //  cmp reg32, *
        with_xbyak(gen) <| $ ( GEN )
            if right is gpReg
                cmp(REG32(GEN,left),REG32(GEN,right as gpReg))
            elif right is gpRegT
                cmp(REG32(GEN,left),REG32(GEN,right as gpRegT))
            elif right is iconst
                let ic = right as iconst
                if ic==0ul && (cop==CompareType equals || cop==CompareType not_equals)
                    // cmp reg, 0 can be promoted to test reg,reg if all we do is testing for equals or not equals
                    test(REG32(GEN,left),REG32(GEN,left))
                else
                    cmp(REG32(GEN,left),uint(right as iconst))
            elif right is stack
                cmp(REG32(GEN,left),ptr[rbp+(right as stack)])
            else
                failed("cmpRegAny32 cmp({left},{right})  // {cop}", at)
    def cmpAnyReg32 ( left:EvResult; right:GpTempReg; cop:CompareType; spill:GpTempReg; at:LineInfo ) : void     //  cmp *, reg32
        with_xbyak(gen) <| $ ( GEN )
            if left is gpReg
                cmp(REG32(GEN,left as gpReg),REG32(GEN,right))
            elif left is gpRegT
                cmp(REG32(GEN,left as gpRegT),REG32(GEN,right))
            elif left is iconst
                let ic = left as iconst
                if ic==0ul && (cop==CompareType equals || cop==CompareType not_equals)
                    // cmp 0, reg can be promoted to test reg,reg if all we do is testing for equals or not equals
                    test(REG32(GEN,right),REG32(GEN,right))
                else
                    if spill==GpTempReg BROKEN
                        failed("cmpAnyReg32 - can't spill",at)
                    mov(REG32(GEN,spill),left as iconst)
                    cmp(REG32(GEN,spill),REG32(GEN,right))
            elif left is stack
                cmp(ptr[rbp+(left as stack)],REG32(GEN,right))
            else
                failed("cmpAnyReg32 cmp({left},{right}) // {cop}", at)
    def cmpStackAny32 ( iSP:int; righ:EvResult; cop:CompareType; spill:GpTempReg; at:LineInfo ) : void     //  cmp [rbp+xxx], *
        with_xbyak(gen) <| $ ( GEN )
            if righ is gpReg
                cmp(dword[rbp+iSP],REG32(GEN,righ as gpReg))
            elif righ is gpRegT
                cmp(dword[rbp+iSP],REG32(GEN,righ as gpRegT))
            elif righ is iconst
                cmp(dword[rbp+iSP],uint(righ as iconst))
            elif righ is stack
                if spill==GpTempReg BROKEN
                    failed("cmpStackAny32 - can't spill",at)
                mov(REG32(GEN,spill),dword[rbp+(righ as stack)])
                cmp(dword[rbp+iSP],REG32(GEN,spill))
            else
                failed("cmpStackAny32 cmp([rbp+{iSP}],{righ}) // {cop}",at)
    def cmpAnyAny32 ( left, right : EvResult; cop:CompareType; spill:GpTempReg; at:LineInfo ) : void     //  cmp *, *
        if left is gpReg
            cmpRegAny32(left as gpReg,right,cop,at)
        elif left is gpRegT
            cmpRegAny32(left as gpRegT,right,cop,at)
        elif right is gpReg
            cmpAnyReg32(left,right as gpReg,cop,spill,at)
        elif right is gpRegT
            cmpAnyReg32(left,right as gpRegT,cop,spill,at)
        else
            failed("cmpAnyAny32 cmp({left},{right}) // {cop}", at)
// add
    def addRegAny32 ( reg:GpTempReg; evR:EvResult; at:LineInfo ) : void
        with_xbyak(gen) <| $ ( GEN )
            if evR is gpRegT
                add(REG32(GEN,reg),REG32(GEN,evR as gpRegT))
            elif evR is gpReg
                add(REG32(GEN,reg),REG32(GEN,evR as gpReg))
            elif evR is iconst
                let ic = uint(evR as iconst)
                if ic==1u
                    inc(REG32(GEN,reg))
                elif ic==-1u
                    dec(REG32(GEN,reg))
                elif ic==0u
                    pass
                else
                    add(REG32(GEN,reg),ic)
            else
                failed("addRegAny32 {reg},{evR}", at)
    def addStackAny32 ( iSP:uint; evR:EvResult; at:LineInfo ) : void
        with_xbyak(gen) <| $ ( GEN )
            if evR is gpReg
                add(dword[rbp+iSP],REG32(GEN,evR as gpReg))
            elif evR is gpRegT
                add(dword[rbp+iSP],REG32(GEN,evR as gpRegT))
            elif evR is iconst
                let ic = uint(evR as iconst)
                if ic==1u
                    inc(dword[rbp+iSP])
                elif ic==-1u
                    dec(dword[rbp+iSP])
                elif ic==0u
                    pass
                else
                    add(dword[rbp+iSP],ic)
            else
                failed("addRegAny32 [rbp+{iSP}],{evR}", at)
// sub
    def subRegAny32 ( reg:GpTempReg; evR:EvResult; at:LineInfo ) : void
        with_xbyak(gen) <| $ ( GEN )
            if evR is gpRegT
                sub(REG32(GEN,reg),REG32(GEN,evR as gpRegT))
            elif evR is gpReg
                sub(REG32(GEN,reg),REG32(GEN,evR as gpReg))
            elif evR is iconst
                let ic = uint(evR as iconst)
                if ic==1u
                    dec(REG32(GEN,reg))
                elif ic==-1u
                    inc(REG32(GEN,reg))
                elif ic==0u
                    pass
                else
                    sub(REG32(GEN,reg),ic)
            else
                failed("subRegAny32 {reg},{evR}", at)
    def subStackAny32 ( iSP:uint; evR:EvResult; at:LineInfo ) : void
        with_xbyak(gen) <| $ ( GEN )
            if evR is gpReg
                sub(dword[rbp+iSP],REG32(GEN,evR as gpReg))
            elif evR is gpRegT
                sub(dword[rbp+iSP],REG32(GEN,evR as gpRegT))
            elif evR is iconst
                let ic = uint(evR as iconst)
                if ic==1u
                    dec(dword[rbp+iSP])
                elif ic==-1u
                    inc(dword[rbp+iSP])
                elif ic==0u
                    pass
                else
                    sub(dword[rbp+iSP],ic)
            else
                failed("subRegAny32 [rbp+{iSP}],{evR}", at)
// imul
    def imulRegAny32 ( reg:GpTempReg; evR:EvResult; at:LineInfo ) : void
        with_xbyak(gen) <| $ ( GEN )
            if evR is gpRegT
                imul(REG32(GEN,reg),REG32(GEN,evR as gpRegT))
            elif evR is gpReg
                imul(REG32(GEN,reg),REG32(GEN,evR as gpReg))
            elif evR is iconst
                // TODO: there are many ways to optimize multiplication by const. implement something
                mov(eax,evR as iconst)
                imul(REG32(GEN,reg),eax)
            else
                failed("imulRegAny32 {reg},{evR}", at)
    def imulStackAny32 ( iSP:uint; evR:EvResult; at:LineInfo ) : void
        with_xbyak(gen) <| $ ( GEN )
            if evR is gpReg
                mov(eax,dword[rbp+iSP])
                imul(eax,REG32(GEN,evR as gpReg))
                mov(dword[rbp+iSP],eax)
            elif evR is gpRegT
                mov(eax,dword[rbp+iSP])
                imul(eax,REG32(GEN,evR as gpRegT))
                mov(dword[rbp+iSP],eax)
            elif evR is iconst
                // TODO: there are many ways to optimize multiplication by const. implement something
                mov(eax, evR as iconst)
                imul(eax, dword[rbp+iSP])   // note a*b = b*a
                mov(dword[rbp+iSP], eax)
            else
                failed("imulRegAny32 [rbp+{iSP}],{evR}", at)
// idiv
    def idivRegAny32 ( reg:GpTempReg; evR:EvResult; div_label:uint64; outp:DivResults; at:LineInfo ) : void
        with_xbyak(gen) <| $ ( GEN )
            if evR is iconst
                let iconst = evR as iconst
                if iconst==0ul
                    failed("DIVISION BY ZERO", at)
                // TODO: there are many ways to optimize division by const. implement something
                mov(eax,REG32(GEN,reg))
                mov(ecx,iconst)
                cdq()
                idiv(ecx);  rdx_has_args = false
            elif (evR is gpReg) || (evR is gpRegT)
                let regR = (evR is gpReg) ? (evR as gpReg) : (evR as gpRegT)
                if !assume_no_exceptions
                    alignForIntelJccErratum()
                    test(REG32(GEN,regR),REG32(GEN,regR))
                    jne("div_{div_label}",LabelType T_AUTO)
                    JIT`exception("division by zero")
                    Label("div_{div_label}")
                mov(eax,REG32(GEN,reg))
                cdq()
                idiv(REG32(GEN,regR));  rdx_has_args = false
            else
                failed("idivRegAny32 {reg},{evR}", at)
    def idivStackAny32 ( iSP:uint; evR:EvResult; div_label:uint64; outp:DivResults; at:LineInfo ) : void
        with_xbyak(gen) <| $ ( GEN )
            if evR is iconst
                let iconst = evR as iconst
                if iconst==0ul
                    failed("DIVISION BY ZERO", at)
                // TODO: there are many ways to optimize division by const. implement something
                mov(eax,dword[rbp+iSP])
                mov(ecx,iconst)
                cdq()
                idiv(ecx);  rdx_has_args = false
            elif (evR is gpReg) || (evR is gpRegT)
                let regR = (evR is gpReg) ? (evR as gpReg) : (evR as gpRegT)
                if !assume_no_exceptions
                    alignForIntelJccErratum()
                    test(REG32(GEN,regR),REG32(GEN,regR))
                    jne("div_{div_label}",LabelType T_AUTO)
                    JIT`exception("division by zero")
                    Label("div_{div_label}")
                mov(eax,dword[rbp+iSP])
                cdq()
                idiv(REG32(GEN,regR));  rdx_has_args = false
            else
                failed("idivRegAny32 [rbp+{iSP}],{evR}", at)
// arg helper
    def setRdxToArgs()
        if !rdx_has_args
            with_xbyak(gen) <| $ ( GEN )
                mov(rdx,ptr[rbp+getArgOffset()])
                rdx_has_args
