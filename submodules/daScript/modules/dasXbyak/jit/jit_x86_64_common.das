options no_unused_block_arguments = false
options no_unused_function_arguments = false
options indenting = 4

module jit_x86_64_common shared public

require jit_x86_64_regs public

require ast public
require daslib/ast_boost
require dasxbyak/xbyak_boost
require daslib/strings_boost
require math

/*
    STACK FRAME IS
VARIABLE_FRAME
    0   var0
    ...
PROLOGUE
    CONTEXT     8
    ARGUMENTS   8
    CMRES       8
TEMPORARY
    0   temp0
    ...
*/


let ARG_CMRES             = 24u
let ARG_ARGUMENTS         = 16u
let ARG_CONTEXT           =  8u

let GP_TEMP_REG_TOTAL = 11

struct RegAllocator
    regs : array<bool>
    freq : array<int>

def free ( var regs:RegAllocator; r:int )
    assert(regs.regs[r]==true)
    regs.regs[r] = false

def allocate ( var regs:RegAllocator )
    let l = length(regs.regs)
    for i in range(l)
        if !regs.regs[i]
            regs.regs[i] = true
            regs.freq[i] ++
            return i
    regs.regs |> push(true)
    regs.freq |> push(1)
    return l

def mask ( var regs:RegAllocator; maxReg:int )
    var mask = 0u
    for t in range(min(maxReg,length(regs.regs)))
        if regs.regs[t]
            mask |= 1u << uint(t)
    return mask

enum CompareType
    always
    less
    less_equals
    equals
    not_equals
    greater
    greater_equals

def condJump ( var gen:CodeGenerator; lab:string; cond:CompareType )
    if cond==CompareType less
        jl(gen,lab,LabelType T_AUTO)
    elif cond==CompareType less_equals
        jle(gen,lab,LabelType T_AUTO)
    elif cond==CompareType equals
        je(gen,lab,LabelType T_AUTO)
    elif cond==CompareType not_equals
        jne(gen,lab,LabelType T_AUTO)
    elif cond==CompareType greater
        jg(gen,lab,LabelType T_AUTO)
    elif cond==CompareType greater_equals
        jge(gen,lab,LabelType T_AUTO)
    else
        panic("unsupported jump {cond}")

def condJumpIfNot ( var gen:CodeGenerator; lab:string; cond:CompareType )
    if cond==CompareType less
        jge(gen,lab,LabelType T_AUTO)
    elif cond==CompareType less_equals
        jg(gen,lab,LabelType T_AUTO)
    elif cond==CompareType equals
        jne(gen,lab,LabelType T_AUTO)
    elif cond==CompareType not_equals
        je(gen,lab,LabelType T_AUTO)
    elif cond==CompareType greater
        jle(gen,lab,LabelType T_AUTO)
    elif cond==CompareType greater_equals
        jl(gen,lab,LabelType T_AUTO)
    else
        panic("unsupported jump {cond}")

def getCompareOp ( op:das_string )
    return getCompareOp(string(op))

def getCompareOp ( op:string )
    if op=="<"
        return CompareType less
    elif op=="<="
        return CompareType less_equals
    elif op=="=="
        return CompareType equals
    elif op=="!="
        return CompareType not_equals
    elif op==">"
        return CompareType greater
    elif op==">="
        return CompareType greater_equals
    else
        panic("unsupported compare operation {op}")
        return CompareType always

bitfield Specials           // this is how operations like /, which require idiv know, that they can return result in RAX or RDX
    RAX
    RDX
    RCX

variant EvResult
    nothing : bool
    stack   : uint          // [rbp+stack] for local variables
    calli   : uint          // [rsp+calli] for the current call
    gpReg   : GpTempReg     // any GP register
    gpRegT  : GpTempReg     // variable replaced via register
    xmmReg  : XmmTempReg    // any XMM register
    iconst  : uint64        // constant
    cmp     : CompareType   // result in flags, from the cmp instruction
    skip    : bool          // do nothing, processing will be done in the levels above

struct Transients
    gp_mask  : uint
    xmm_mask : uint

struct EvContext
    expr_res        : table<uint64; EvResult>
    temp_var        : table<uint64; GpTempReg>
    transients      : table<uint64; Transients>
    specials        : table<uint64; Specials>
    labels          : table<uint64; string>
    rcx_candidates  : table<GpTempReg; int>                   // this are registers, who want to be rcx badly (i.e. divisors etc)
    gpa : RegAllocator
    xmma : RegAllocator
    stack_frame : uint      // regular stack
    save_frame  : uint      // where transient registers are saved
    use_cmres   : bool
    use_args    : bool
    use_context : bool
    uses_rcx    : bool
    assume_no_exceptions : bool

def pick_rcx_candidate ( var context:EvContext )
    if length(context.rcx_candidates) > 0
        var can = GpTempReg BROKEN
        var tot = 0
        for k,v in keys(context.rcx_candidates),values(context.rcx_candidates)
            if v > tot  // we pick the most frequently used for the right reason one
                can = k
                tot = v
        return can
    if length(context.gpa.regs) >= FIRST_NON_TRANSIENT_GP_TEMP_REG
        unsafe
            let gpi = length(context.gpa.regs) - 1  // last one out
            return reinterpret<GpTempReg> gpi
    return GpTempReg BROKEN

def replace_register_allocation ( var context:EvContext; freg, treg : GpTempReg )
    for v in values(context.expr_res)
        if v is gpReg
            if (v as gpReg)==freg
                v = [[EvResult gpReg=treg]]
        elif v is gpRegT
            if (v as gpRegT)==freg
                v = [[EvResult gpRegT=treg]]
    for v in values(context.temp_var)
        if v==freg
            v = treg
    let gpi = int(freg)
    let tgi = int(treg)
    if gpi==(length(context.gpa.regs)-1)
        context.gpa.regs |> pop
        context.gpa.freq |> pop
    else
        context.gpa.regs[gpi] = false
        context.gpa.freq[gpi] = 0
    let fmask = ~(1u << uint(gpi))
    let tmask = 1u<<uint(tgi)
    for v in values(context.transients)
        v.gp_mask = (v.gp_mask & fmask) | tmask

def dump ( ctx:EvContext )
    print("stack frame is {ctx.stack_frame}\n")
    print("save frame is {ctx.save_frame} bytes\n")
    print("use context: {ctx.use_context}\n")
    print("use args: {ctx.use_args}\n")
    print("use cmres: {ctx.use_cmres}\n")
    print("uses RCX: {ctx.uses_rcx}\n")
    if !ctx.uses_rcx
        let cand = join([{for k,v in keys(ctx.rcx_candidates),values(ctx.rcx_candidates); "{k}:{v}"}],", ")
        print("RCX candidates are: {cand}\n")
    print("gp temp: {length(ctx.gpa.regs)}\n")
    for t in range(length(ctx.gpa.regs))
        unsafe
            print("\t{reinterpret<GpTempReg> t} {ctx.gpa.freq[t]} times\n")
    print("xmm temp: {length(ctx.xmma.regs)}\n")
    for x in range(length(ctx.xmma.regs))
        unsafe
            print("\t{reinterpret<XmmTempReg> x} {ctx.xmma.freq[x]} times\n")
    print("register allocation:\n")
    for k,v in keys(ctx.expr_res),values(ctx.expr_res)
        unsafe
            let pexpr = reinterpret<Expression?> k
            let at & = pexpr.at
            let fname = at.fileInfo!=null ? "{at.fileInfo.name}" : ""
            print("\t{k}.{pexpr.__rtti} ->  {v} at {fname}:{int(at.line)}:{int(at.column)}\n")

def is_gpreg_type ( t:TypeDeclPtr )
    if length(t.dim)>0
        return false
    if t.isInteger || t.isPointer || t.baseType==Type tBool
        return true
    return true

def is_for_range1 ( expr:smart_ptr<ExprFor> )                   // for blah in ANY_RANGE
    if length(expr.sources)!=1
        return false
    if length(expr.sources[0]._type.dim)!=0
        return false
    if expr.sources[0]._type.baseType!=Type tRange
        return false
    return true

def is_for_range1_RANGE ( expr:smart_ptr<ExprFor> )             // for blah in range(...)
    if !is_for_range1(expr)
        return false
    if expr.sources[0] is ExprCall
        let ec = expr.sources[0] as ExprCall
        if ec.func.name=="range" && ec.func._module.name=="$"
            return true
    return false

def is_for_range1_with_unused_var ( expr:smart_ptr<ExprFor> )   // for blah in ANY_RANGE, but blah is unused
    if !is_for_range1(expr)
        return false
    let flags = expr.iteratorVariables[0].access_flags
    if !flags.access_ref && !flags.access_get
        return true
    return false

class JitVisitor : AstVisitor
    verbose : bool
    context : EvContext
    failed_to_generate : bool
    visitor_type : string
    def JitVisitor ( var ctx:EvContext )
        context <- ctx
    def error ( txt:string; at:LineInfo )
        failed_to_generate = true
        let fname = at.fileInfo!=null ? "{at.fileInfo.name}" : ""
        print("\nERROR jit_x86_64({visitor_type}): {txt} at {fname}:{int(at.line)}:{int(at.column)}\n")
        stackwalk(false,false)
    def failed ( txt:string; at:LineInfo )
        failed_to_generate = true
        let fname = at.fileInfo!=null ? "{at.fileInfo.name}" : ""
        print("\nTODO jit_x86_64({visitor_type}): {txt} at {fname}:{int(at.line)}:{int(at.column)}\n")
        stackwalk(false,false)
    def log(text:string)
        if verbose
            print(text)
    def logAt(text:string; at:LineInfo)
        if verbose
            let fname = at.fileInfo!=null ? "{at.fileInfo.name}" : ""
            print("{text} at {fname}:{int(at.line)}:{int(at.column)}\n")
    def evSpecialsGet ( expr:ExpressionPtr ) : Specials
        return context.specials?[intptr(expr)] ?? [[Specials]]
    def evSpecialsHas ( expr:ExpressionPtr; regs:Specials ) : bool
        let spc = context.specials?[intptr(expr)] ?? [[Specials]]
        return (spc & regs)==regs
    def evResSet ( expr:ExpressionPtr ) : EvResult &
        unsafe
            return context.expr_res[intptr(expr)]
    def evResSetp ( expr:Expression? ) : EvResult &
        unsafe
            return context.expr_res[intptr(expr)]
    def evResGet ( expr:ExpressionPtr ) : EvResult const &
        unsafe
            return context.expr_res[intptr(expr)]
    def evResGetp ( expr:Expression? ) : EvResult const &
        unsafe
            return context.expr_res[intptr(expr)]
