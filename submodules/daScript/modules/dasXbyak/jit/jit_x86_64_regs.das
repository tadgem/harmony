options no_unused_block_arguments = false
options no_unused_function_arguments = false
options indenting = 4

module jit_x86_64_regs shared public

require dasxbyak/xbyak_boost
//
// non-transient registers
//      RBX, RBP, RDI, RSI, RSP, R12, R13, R14, R15, and XMM6-XMM15

let MAX_GP_TEMP_REG = 11
let FIRST_NON_TRANSIENT_GP_TEMP_REG = 4

enum GpTempReg
    // transient
    R8
    R9
    R10
    R11
    // permanent
    RBX
    RDI
    RSI
    R12
    R13
    R14
    R15
    // exta
    RAX
    RCX
    RDX
    // broken
    BROKEN = 100500

let MAX_XMM_TEMP_REG = 15
let FIRST_NON_TRANSIENT_XMM_TEMP_REG = 6

enum XmmTempReg
    XMM1
    XMM2
    XMM3
    XMM4
    XMM5
    // persistent
    XMM6
    XMM7
    XMM8
    XMM9
    XMM10
    XMM11
    XMM12
    XMM13
    XMM14
    XMM15
    // temp
    XMM0        // note - this is where result goes by ABI

def REG32 ( var gen:CodeGenerator; r:GpTempReg ) : Reg32 const &
    unsafe
        if r==GpTempReg R8
            return gen.r8d
        elif r==GpTempReg R9
            return gen.r9d
        elif r==GpTempReg R10
            return gen.r10d
        elif r==GpTempReg R11
            return gen.r11d
        elif r==GpTempReg RBX
            return gen.ebx
        elif r==GpTempReg RDI
            return gen.edi
        elif r==GpTempReg RSI
            return gen.esi
        elif r==GpTempReg R12
            return gen.r12d
        elif r==GpTempReg R13
            return gen.r13d
        elif r==GpTempReg R14
            return gen.r14d
        elif r==GpTempReg R15
            return gen.r15d
        elif r==GpTempReg RAX
            return gen.eax
        elif r==GpTempReg RCX
            return gen.ecx
        elif r==GpTempReg RDX
            return gen.edx
        else
            panic("REG32 fails with {r}")
            return gen.eax

def REG64 ( var gen:CodeGenerator; r:GpTempReg ) : Reg64 const &
    unsafe
        if r==GpTempReg R8
            return gen.r8
        elif r==GpTempReg R9
            return gen.r9
        elif r==GpTempReg R10
            return gen.r10
        elif r==GpTempReg R11
            return gen.r11
        elif r==GpTempReg RBX
            return gen.rbx
        elif r==GpTempReg RDI
            return gen.rdi
        elif r==GpTempReg RSI
            return gen.rsi
        elif r==GpTempReg R12
            return gen.r12
        elif r==GpTempReg R13
            return gen.r13
        elif r==GpTempReg R14
            return gen.r14
        elif r==GpTempReg R15
            return gen.r15
        elif r==GpTempReg RAX
            return gen.rax
        elif r==GpTempReg RCX
            return gen.rcx
        elif r==GpTempReg RDX
            return gen.rdx
        else
            panic("REG64 fails with {r}")
            return gen.rax

def REGXMM ( var gen:CodeGenerator; r:XmmTempReg ) : Xmm const &
    unsafe
        if r==XmmTempReg XMM0
            return gen.xmm0
        elif r==XmmTempReg XMM1
            return gen.xmm1
        elif r==XmmTempReg XMM2
            return gen.xmm2
        elif r==XmmTempReg XMM3
            return gen.xmm3
        elif r==XmmTempReg XMM4
            return gen.xmm4
        elif r==XmmTempReg XMM5
            return gen.xmm5
        elif r==XmmTempReg XMM6
            return gen.xmm6
        elif r==XmmTempReg XMM7
            return gen.xmm7
        elif r==XmmTempReg XMM8
            return gen.xmm8
        elif r==XmmTempReg XMM9
            return gen.xmm9
        elif r==XmmTempReg XMM10
            return gen.xmm10
        elif r==XmmTempReg XMM11
            return gen.xmm11
        elif r==XmmTempReg XMM12
            return gen.xmm12
        elif r==XmmTempReg XMM13
            return gen.xmm13
        elif r==XmmTempReg XMM14
            return gen.xmm14
        elif r==XmmTempReg XMM15
            return gen.xmm15
        else
            panic("REGXMM fails with {r}")
            return gen.xmm0
