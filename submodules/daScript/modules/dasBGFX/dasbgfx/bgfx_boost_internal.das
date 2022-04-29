options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module bgfx_boost_internal shared

require daslib/ast_boost
require daslib/templates
require daslib/templates_boost
require daslib/safe_addr
require daslib/strings_boost

require glsl/glsl_internal

require bgfx

[tag_function(compile_shader_tag)]
def public bgfx_create_shader_program ( vs_main, ps_main : function<void> ) : bgfx_program_handle_s
    panic("somehow we are in this is temporary stub for the resolved bgfx_create_shader_program")
    return [[bgfx_program_handle_s idx=uint16(0xffff)]]

[tag_function(compile_compute_shader_tag)]
def public bgfx_create_compute_shader_program ( cs_main : function<void> ) : bgfx_program_handle_s
    panic("somehow we are in this is temporary stub for the resolved bgfx_create_compute_shader_program")
    return [[bgfx_program_handle_s idx=uint16(0xffff)]]

[macro_function]
def get_shader_const_name ( arg:ExpressionPtr; var errors:das_string )
    var aAddr = arg ?as ExprAddr
    if aAddr==null
        errors := "expecting @@shader_function"
        return ""
    if aAddr.func==null
        errors := "function not found yet"
        return ""
    for ann in aAddr.func.annotations
        if ann.annotation.name=="bgfx_vertex_program" || ann.annotation.name=="bgfx_fragment_program" || ann.annotation.name=="bgfx_compute_program"
            let cname = find_arg("name",ann.arguments) ?as tString ?? ""
            if cname==""
                return "{aAddr.func.name}`shader_text"
            else
                return cname
    errors := "function needs to be annotated as bgfx_vertex_program, bgfx_fragment_program, or bgfx_compute_program"
    return ""

[tag_function_macro(tag="compile_shader_tag")]
class BgfxCompileShaderFunctionAnnotation : AstFunctionAnnotation
    def override transform ( var call : smart_ptr<ExprCallFunc>; var errors : das_string ) : ExpressionPtr
        // see if there
        if call.arguments[0]._type==null || call.arguments[1]._type==null
            return [[ExpressionPtr]]
        let vs_name = get_shader_const_name(call.arguments[0],errors)
        if vs_name==""
            return [[ExpressionPtr]]
        let fs_name = get_shader_const_name(call.arguments[1],errors)
        if fs_name==""
            return [[ExpressionPtr]]
        var cll <- new [[ExprCall() at=call.at, name:="bgfx_create_shader_program"]]
        cll.arguments |> emplace_new <| new [[ExprVar() at=call.at, name:=vs_name]]
        cll.arguments |> emplace_new <| new [[ExprVar() at=call.at, name:="{vs_name}_DECL"]]
        cll.arguments |> emplace_new <| new [[ExprVar() at=call.at, name:=fs_name]]
        cll.arguments |> emplace_new <| new [[ExprVar() at=call.at, name:="{fs_name}_DECL"]]
        cll.arguments |> emplace_new <| new [[ExprCall() at=call.at, name:="bgfx_get_renderer_type"]]
        return <- cll

[tag_function_macro(tag="compile_compute_shader_tag")]
class BgfxCompileComputeShaderFunctionAnnotation : AstFunctionAnnotation
    def override transform ( var call : smart_ptr<ExprCallFunc>; var errors : das_string ) : ExpressionPtr
        // see if there
        if call.arguments[0]._type==null
            return [[ExpressionPtr]]
        let cs_name = get_shader_const_name(call.arguments[0],errors)
        if cs_name==""
            return [[ExpressionPtr]]
        let func = (call.arguments[0] as ExprAddr).func
        let target = func._module.name!="" ? "{func._module.name}::{func.name}" : "{func.name}"
        var cll <- new [[ExprCall() at=call.at, name:="bgfx_create_compute_shader_program"]]
        cll.arguments |> emplace_new <| new [[ExprVar() at=call.at, name:=cs_name]]
        cll.arguments |> emplace_new <| new [[ExprAddr() at=call.at, target:="{target}_bind_uniform"]]
        cll.arguments |> emplace_new <| new [[ExprCall() at=call.at, name:="bgfx_get_renderer_type"]]
        return <- cll

[structure_macro(name="bgfx_vertex_buffer")]
class BgfxVertexBuffer : AstStructureAnnotation
    def override apply ( var st:StructurePtr; var group:ModuleGroup; args:AnnotationArgumentList; var errors : das_string ) : bool
        var fn <- new [[Function() at = st.at, atDecl = st.at, name := "bgfx_create_vertex_layout"]]
        fn.flags |= FunctionFlags generated
        fn.result <- new [[TypeDecl() baseType=Type autoinfer, at=st.at]]
        fn.arguments |> emplace_new() <| new [[Variable() at=st.at,
            name := "self",
            _type <- new [[TypeDecl() at=st.at,
                baseType=Type tStructure,
                structType=get_ptr(st)
            ]]
        ]]
        fn.arguments |> emplace_new() <| new [[Variable() at=st.at,
            name := "render_type",
            _type <- clone_type() <| typeinfo(ast_typedecl type<bgfx_renderer_type>),
            init <- new [[ExprCall() at=st.at, name:="bgfx_get_renderer_type"]]
        ]]
        var qblk <- quote() <|
            var pcv_decl : bgfx_vertex_layout_s
            bgfx_vertex_layout_begin(safe_addr(pcv_decl), render_type)
            declarations_go_here
            bgfx_vertex_layout_end(safe_addr(pcv_decl))
            return pcv_decl
        var blk <- new [[ExprBlock() at=st.at]]
        var saddr <- new [[ExprCall() at=st.at, name:="safe_addr"]]
        saddr.arguments |> emplace_new <| new [[ExprVar() at=st.at, name:="pcv_decl"]]
        let bgfx_attr_enum_t = typeinfo(ast_typedecl type<bgfx_attrib>).enumType
        let bgfx_attr_type_enum_t = typeinfo(ast_typedecl type<bgfx_attrib_type>).enumType
        for fld in st.fields
            var semantics = find_arg("semantics", fld.annotation) ?as tString ?? ""
            if semantics==""
                let fldname = to_upper(string(fld.name))
                if glsl_supported_semantics |> key_exists(fldname)
                    semantics = fldname
            if semantics==""
                errors := "field {fld.name} is missing 'semantics'"
                return false
            var dinfo = get_decl_info(fld._type, fld.annotation)
            if !dinfo.ok
                errors := "field {fld.name} is missing type information"
                return false
            var ttname = ""
            if dinfo.info.typet==Type tFloat
                ttname = "FLOAT"
            elif dinfo.info.typet==Type tUInt
                ttname = "UINT8"
            elif dinfo.info.typet==Type tInt16
                ttname = "INT16"
            else
                errors := "field {fld.name} type {dinfo.info.typet} is not supported"
                return false
            // bgfx_vertex_layout_add(safe_addr(pcv_decl), bgfx_attrib POSITION, 3u, bgfx_attrib_type FLOAT, false, false)
            var cll_vap <- new [[ExprCall() at=fld.at, name:="bgfx_vertex_layout_add"]]
            cll_vap.arguments |> emplace_new() <| clone_expression(saddr)
            cll_vap.arguments |> emplace_new() <| new [[ExprConstEnumeration() at=st.at, enumType:=bgfx_attr_enum_t, value:=semantics]]
            cll_vap.arguments |> emplace_new() <| new [[ExprConstUInt() at=st.at, value=uint(dinfo.info.sizei)]]
            cll_vap.arguments |> emplace_new() <| new [[ExprConstEnumeration() at=st.at, enumType:=bgfx_attr_type_enum_t, value:=ttname]]
            cll_vap.arguments |> emplace_new() <| new [[ExprConstBool() at=st.at, value=dinfo.info.normalized]]
            cll_vap.arguments |> emplace_new() <| new [[ExprConstBool() at=st.at, value=dinfo.info.as_int]]
            blk.list |> emplace(cll_vap)
        saddr := null
        apply_template(qblk) <| $ ( rules )
            rules |> replaceVariable("declarations_go_here") <| blk
        var qres <- move_unquote_block(qblk)
        qres.blockFlags &= ~ExprBlockFlags isClosure
        fn.body <- qres
        append_annotation(fn,"templates","template",[{auto[]
            [[auto "self", [[RttiValue tBool=true]] ]]
        }])
        if !(compiling_module() |> add_function(fn))
            panic("can't setup")
        return true


