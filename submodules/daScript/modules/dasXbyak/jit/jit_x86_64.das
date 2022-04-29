options no_unused_block_arguments = false
options no_unused_function_arguments = false
options indenting = 4

module jit_x86_64 shared public

require jit_x86_64_regs
require jit_x86_64_common
require jit_x86_64_alloc_regs
require jit_x86_64_generate

require daslib/ast_boost
require daslib/strings_boost
require daslib/templates_boost
require math

require dasxbyak/xbyak_boost
require xbyak public
require zydis

require ast public

var public JIT_MAX_OPT_LEVEL = 3
let public JIT_MAX_POSSIBLE_OPT_LEVEL = 3
var public JIT_VERBOSE = false
var public JIT_DISASM = false
var public JIT_REPORT_REG_PRESSURE = false
var public JIT_DISASSEMBLE_SHOW_ADDRESS = false

def private allocate_regs(var func : FunctionPtr; var context:EvContext; verbose:bool; _opt_level:int )
    let opt_level = min(JIT_MAX_OPT_LEVEL, _opt_level)
    if verbose
        print("{func.name} opt_level={opt_level}\n")
    var allocateRegistersVisitor = new AllocateRegistersCodeVisitor(context)
    var allocateRegistersVisitorAdapter <- make_visitor(*allocateRegistersVisitor)
    allocateRegistersVisitor.verbose = verbose
    if opt_level == 3
        allocateRegistersVisitor.put_loop_variables_in_registers = true
        allocateRegistersVisitor.put_local_variables_in_registers = true
    elif opt_level == 2
        allocateRegistersVisitor.put_loop_variables_in_registers = true
        allocateRegistersVisitor.put_local_variables_in_registers = false
    elif opt_level == 1
        allocateRegistersVisitor.put_loop_variables_in_registers = false
        allocateRegistersVisitor.put_local_variables_in_registers = true
    elif opt_level == 0
        allocateRegistersVisitor.put_loop_variables_in_registers = false
        allocateRegistersVisitor.put_local_variables_in_registers = false
    else
        panic("opt_level {opt_level} is not supported")
    visit(func, allocateRegistersVisitorAdapter)
    let f2a = allocateRegistersVisitor.failed_to_generate
    context <- allocateRegistersVisitor.context
    if allocateRegistersVisitor.verbose
        context |> dump
    allocateRegistersVisitorAdapter := null
    unsafe
        delete allocateRegistersVisitor
    if f2a
        return false
    // report register pressure
    let temp_gp = length(context.gpa.regs)
    let temp_xmm = length(context.xmma.regs)
    if JIT_REPORT_REG_PRESSURE
        print("jit_x86_64: {func.name} gp:{temp_gp} xmm:{temp_xmm}\n")
    // verify GP regs
    if temp_gp > MAX_GP_TEMP_REG
        print("jit_x86_64: {func.name}: too many temp gp registers {temp_gp} of {MAX_GP_TEMP_REG}")
        return false
    // verify XMM regis
    if temp_xmm > MAX_XMM_TEMP_REG
        print("jit_x86_64: {func.name}: too many temp xmm registers {temp_xmm} of {MAX_XMM_TEMP_REG}")
        return false
    return true

def public generate_x86_64(var func:FunctionPtr; show_disasm:bool; verbose:bool; opt_level:int; no_exceptions:bool ) : CodeGenerator?
    if JIT_MAX_OPT_LEVEL==-1
        return null
    var context : EvContext
    var ok = false
    ok = allocate_regs(func, context, verbose, opt_level)
    if !ok
        return null
    // generation extra settings
    context.assume_no_exceptions = false
    // generate code
    var gen = new CodeGenerator
    *gen |> inLocalLabel()
    var generateCodeVisitor = new GenerateCodeVisitor(gen,context)
    var generateCodeVisitorAdapter <- make_visitor(*generateCodeVisitor)
    generateCodeVisitor.verbose = verbose
    generateCodeVisitor.assume_no_exceptions = no_exceptions
    visit(func, generateCodeVisitorAdapter)
    let f2g = generateCodeVisitor.failed_to_generate
    generateCodeVisitorAdapter := null
    context <- generateCodeVisitor.context
    *gen |> outLocalLabel()
    unsafe
        delete generateCodeVisitor
    unsafe
        if show_disasm || JIT_DISASM
            let data = *gen |> get_code()
            let dataLength = *gen |> getSize()
            print("{describe_function(func)}data at {intptr(data)} of {int(dataLength)} bytes\n")
            disassemble(data, dataLength, context.labels) <| $ ( address, text )
                let labt = context.labels?[address] ?? ""
                if !empty(labt)
                    print("{labt}:\n")
                if JIT_DISASSEMBLE_SHOW_ADDRESS
                    print(format("%016llx\t",address))
                print("\t{text}\n")
            print("\n")
        let err = reinterpret<GenerationError> GetError()
        if err != GenerationError NONE
            panic("xbyak - generation error {err}")
    if f2g
        print("jit_x86_64: failed to generate {func.name} aka {get_mangled_name(func)}\n")
        unsafe
            delete gen
    return gen

[function_macro(name="jit_x86_64")]
class Jit_x86_64_Macro : AstFunctionAnnotation
    def override apply ( var func:FunctionPtr; var group:ModuleGroup; args:AnnotationArgumentList; var errors : das_string ) : bool
        func.sideEffectFlags |= bitfield(int(SideEffects userScenario))
        var qblock <- quote() <|
            unsafe
                if get_ptr(this_program()) != null
                    var fnptr <- find_module_function_via_rtti(find_module_via_rtti(this_program(),PMOD),PFUN)
                    var gen = generate_x86_64(fnptr,SHOW_DISASM,VERBOSE || JIT_VERBOSE, OPTLEVEL, NO_EXCEPTIONS)
                    if gen != null
                        *gen |> instrument_jit(reinterpret<function> PFUN)
                    else
                        remove_jit(reinterpret<function> PFUN)
                    fnptr := null
                else
                    panic("missing 'options rtti'")
        let show_disasm = find_arg("asm",args) ?as tBool ?? false
        let verbose = find_arg("verbose",args) ?as tBool ?? false
        let opt_level = find_arg("o",args) ?as tInt ?? 3
        let no_exceptions = find_arg("no_exceptions",args) ?as tBool ?? false
        apply_template(qblock) <| $ ( rules )
            rules |> replaceVariable("PFUN") <| new [[ExprAddr() target:=func.name]]
            rules |> replaceVariable("PMOD") <| new [[ExprConstString() value:=compiling_module().name]]
            rules |> replaceVariable("SHOW_DISASM") <| new [[ExprConstBool() value=show_disasm]]
            rules |> replaceVariable("VERBOSE") <| new [[ExprConstBool() value=verbose]]
            rules |> replaceVariable("OPTLEVEL") <| new [[ExprConstInt() value=opt_level]]
            rules |> replaceVariable("NO_EXCEPTIONS") <| new [[ExprConstBool() value=no_exceptions]]
        var qres <- move_unquote_block(qblock)
        qres.blockFlags ^= ExprBlockFlags isClosure
        var reg <- setup_call_list("all`things`jit", func.at, true)
        reg.list |> emplace(qres)
        return true

