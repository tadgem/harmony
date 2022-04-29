options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module glsl_internal_bgfx shared

require glsl/glsl_internal
require daslib/ast_boost
require daslib/strings_boost

require bgfx

class GlslBgfxShader : GlslShader
    override write_version = false
    override output_inout = false
    override output_inout_stub = true
    override output_inout_decl = true
    override output_shader_lines = false
    override replace_hlsl_incompatible_operations = true
    override restrict_uniform_types = true                      // only vec4, mat3x3 and mat4x4
    override restrict_vertex_attribute_names = true             // only a_position, a_color0, etc
    override output_unfirom_macro_declarations = true           // SAMPLER2D(...) instead of unifor sampler2D ...;
    override output_compatibility_constructors = true           // hlsl-compatible numeric constructors (hi HLSL)
    override output_hlsl_style_compute_layout = true            // NUM_THREADS(16,16,1) right before main
    override output_structure_initializers = true               // produce structure initializers (hi HLSLS)
    override restrict_array_as_result = true                    // returning float[13] and such is prohibited (hi HLSL)
    override allow_unitialized_local_arrays = true              // var a : float[9] can be uninitialized local variable (hi HLSL)
    override resolve_supported_semantics = true                 // resolve semantic from a_position, v_color0, etc
    def override get_glsl_prefix
        if shaderType==ShaderType compute
            return "\n#include <bgfx_compute.sh>\n\n"
        elif shaderType==ShaderType vertex || shaderType==ShaderType fragment
            return "\n#include <bgfx_shader.sh>\n\n"
        else
            return ""
    def override generate_bind_uniform_dummy ( var func:FunctionPtr )
        generate_bgfx_bind_uniform_dummy(func)
    def override generate_bind_uniform(fnMain:FunctionPtr; var fn:FunctionPtr)
        generate_bgfx_bind_uniform(fnMain, fn)

[macro_function]
def private generate_bgfx_bind_uniform_dummy(fnMain:FunctionPtr)
    var fn <- new [[Function() at = fnMain.at, atDecl = fnMain.at, name := bind_uniform_function_name(fnMain)]]
    fn.flags |= FunctionFlags generated
    fn.flags |= FunctionFlags exports   // note: this is temporary, until we are done with dependency collecting etc
    fn.result <- new [[TypeDecl() baseType=Type tVoid, at=fnMain.at]]
    fn.body <- new [[ExprBlock() at=fnMain.at]]
    if !(compiling_module() |> add_function(fn))
        panic("can't setup")
    return true

[macro_function]
def private generate_bgfx_bind_uniform(fnMain:FunctionPtr; var fn:FunctionPtr)
    var blk <- new [[ExprBlock() at=fn.at]]
    collect_dependencies(fnMain) <| $ ( vfun, vvar )
        for vv in vvar
            if find_arg("uniform", vv.annotation) is tBool
                if "{vv._module.name}" |> find("glsl_") == -1
                    var cll_uni <- new [[ExprCall() at=vv.at, name:="bgfx_any_uniform"]]
                    cll_uni.arguments |> emplace_new() <| new [[ExprConstString() at=vv.at, value:=vv.name]]
                    if vv._type.baseType==Type tStructure
                        let sname = string(vv._type.structType.name)
                        if sname|>find("sampler")!=-1
                            let stage = (find_arg("stage",vv.annotation) ?as tInt) ?? 0
                            var sampler_flags = 0u
                            for arg in vv.annotation
                                if arg.name=="sampler" && arg.basicType==Type tString
                                    if arg.sValue=="U_CLAMP"
                                        sampler_flags |= BGFX_SAMPLER_U_CLAMP
                                    elif arg.sValue=="U_MIRROR"
                                        sampler_flags |= BGFX_SAMPLER_U_MIRROR
                                    elif arg.sValue=="V_CLAMP"
                                        sampler_flags |= BGFX_SAMPLER_V_CLAMP
                                    elif arg.sValue=="V_MIRROR"
                                        sampler_flags |= BGFX_SAMPLER_V_MIRROR
                                    elif arg.sValue=="W_CLAMP"
                                        sampler_flags |= BGFX_SAMPLER_W_CLAMP
                                    elif arg.sValue=="W_MIRROR"
                                        sampler_flags |= BGFX_SAMPLER_W_MIRROR
                                    elif arg.sValue=="MIN_POINT"
                                        sampler_flags |= BGFX_SAMPLER_MIN_POINT
                                    elif arg.sValue=="MAG_POINT"
                                        sampler_flags |= BGFX_SAMPLER_MAG_POINT
                                    elif arg.sValue=="MIN_ANISOTROPIC"
                                        sampler_flags |= BGFX_SAMPLER_MIN_ANISOTROPIC
                                    elif arg.sValue=="MAG_ANISOTROPIC"
                                        sampler_flags |= BGFX_SAMPLER_MAG_ANISOTROPIC
                            cll_uni.arguments |> emplace_new() <| new [[ExprConstUInt() at=vv.at, value=uint(stage)]]
                            cll_uni.arguments |> emplace_new() <| new [[ExprConstUInt() at=vv.at, value=sampler_flags]]
                        if sname|>find("image")!=-1
                            let stage = (find_arg("stage",vv.annotation) ?as tInt) ?? 0
                            var access = "READWRITE"
                            for arg in vv.annotation
                                if arg.name=="writeonly" && arg.basicType==Type tBool
                                    access = "WRITE"
                                elif arg.name=="readonly" && arg.basicType==Type tBool
                                    access = "READ"
                            cll_uni.arguments |> emplace_new() <| new [[ExprConstUInt() at=vv.at, value=uint(stage)]]
                            let access_enum_t = typeinfo(ast_typedecl type<bgfx_access>).enumType
                            cll_uni.arguments |> emplace_new() <| new [[ExprConstEnumeration() at=vv.at, enumType:=access_enum_t, value:=access]]
                    cll_uni.arguments |> emplace_new() <| new [[ExprVar() at=vv.at, name:=vv.name]]
                    blk.list |>emplace(cll_uni)
    fn.body := blk
    if DEBUG_SHADER_BINDINGS
        print("{describe(fn)}\n")

[function_macro(name="bgfx_vertex_program")]
class GlslBgfxVertexProgram : GlslBgfxShader
    override shaderType = ShaderType vertex

[function_macro(name="bgfx_fragment_program")]
class GlslBgfxPixelProgram : GlslBgfxShader
    override shaderType = ShaderType fragment

[function_macro(name="bgfx_compute_program")]
class GlslBgfxComputeProgram : GlslBgfxShader
    override shaderType = ShaderType compute
