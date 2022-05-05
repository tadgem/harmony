options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module bgfx_boost shared public

require bgfx public

require daslib/safe_addr
require daslib/strings_boost
require daslib/algorithm
require math
require fio
require stbimage

require dasbgfx/bgfx_boost_internal public
require dasbgfx/glsl_bgfx public

let VERBOSE_COMPILER = false

let BGFX_INVALID_HANDLE = uint16(0xffff)

let BGFX_STATE_WRITE_RGB = (0ul
    | BGFX_STATE_WRITE_R
    | BGFX_STATE_WRITE_G
    | BGFX_STATE_WRITE_B
)

let BGFX_STATE_DEFAULT = (0ul
    | BGFX_STATE_WRITE_RGB
    | BGFX_STATE_WRITE_A
    | BGFX_STATE_WRITE_Z
    | BGFX_STATE_DEPTH_TEST_LESS
    | BGFX_STATE_CULL_CW
    | BGFX_STATE_MSAA
)

let BGFX_STATE_BLEND_ALPHA = BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA)

def BGFX_STATE_BLEND_FUNC_SEPARATE(_srcRGB, _dstRGB, _srcA, _dstA : uint64)
    return ( 0ul
	    | (  _srcRGB|(_dstRGB<<4ul))
	    | (( _srcA  |(_dstA  <<4ul))<<8ul)
	)

def BGFX_STATE_BLEND_EQUATION_SEPARATE(_equationRGB, _equationA : uint64)
    return  _equationRGB | (_equationA<<3ul)

def BGFX_STATE_BLEND_FUNC(_src, _dst : uint64)
    return BGFX_STATE_BLEND_FUNC_SEPARATE(_src, _dst, _src, _dst)

def BGFX_STATE_BLEND_EQUATION(_equation : uint64)
    return  BGFX_STATE_BLEND_EQUATION_SEPARATE(_equation, _equation)

def UCOLOR_TO_BGFX_UCOLOR ( col:uint )
    let r = (col & 0x00ff0000) >> 16u
    let g = (col & 0x0000ff00) >> 8u
    let b = (col & 0x000000ff)
    let a = (col & 0xff000000) >> 24u
    return (b<<24u) | (g<<16u) | (r<<8u) | (a)

def RGBA_TO_BGFX_UCOLOR(r,g,b,a:float)
    return pack_float_to_byte(float4(a,b,g,r)*255.)

struct private BgfxUniform
    handle : bgfx_uniform_handle_s
    utype  : bgfx_uniform_type
    ucount : uint

var private g_bgfxUniform : table<string; BgfxUniform>

def public bgfx_cache_uniform ( name:string; utype:bgfx_uniform_type; ucount:uint )
    assert(ucount!=0u)
    var unf & = unsafe(g_bgfxUniform[name])
    if unf.ucount==0u
        unf.handle = bgfx_create_uniform(name, utype, ucount)
        if unf.handle.idx==uint16(0xffff)
            panic("invalid uniform {name} {utype}[{ucount}]")
        unf.utype = utype
        unf.ucount = ucount
    else
        if unf.utype!=utype || unf.ucount!=ucount
            panic("uniform {name} type mismatch. expecting {utype}[{ucount}], got {unf.utype}[{unf.ucount!=ucount}]")
    return unf.handle

def public bgfx_reset_uniform_cache
    for val in values(g_bgfxUniform)
        bgfx_destroy_uniform(val.handle)
    delete g_bgfxUniform

def public bgfx_any_uniform ( name:string; stage:uint; access:bgfx_access; value:image2D )
    bgfx_set_image(stage, [[bgfx_texture_handle_s idx=uint16(value.texture2D)]], 0u,
        access, bgfx_texture_format COUNT)

def public bgfx_any_uniform ( name:string; stage:uint; sampler_flags:uint; value:sampler2D )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type SAMPLER, 1u)
    bgfx_set_texture(stage, handle, [[bgfx_texture_handle_s idx=uint16(value.texture2D)]], sampler_flags)

def public bgfx_any_uniform ( name:string; _value:uint )
    var value = [[bgfx_texture_handle_s idx=uint16(_value)]]
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type SAMPLER, 1u)
    bgfx_set_uniform(handle, unsafe(addr(value)), 0xffff)

def public bgfx_any_uniform ( name:string; value:float4 )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type VEC4, 1u)
    bgfx_set_uniform(handle, unsafe(addr(value)), 0xffff)

[generic]
def public bgfx_any_uniform ( name:string; value:float4[] )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type VEC4, uint(length(value)))
    bgfx_set_uniform(handle, unsafe(addr(value)), 0xffff)

def public bgfx_any_uniform ( name:string; value:float3x3 )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type MAT3, 1u)
    bgfx_set_uniform(handle, unsafe(addr(value)), 0xffff)

def public bgfx_any_uniform ( name:string; value:float3x3[] )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type MAT3, uint(length(value)))
    bgfx_set_uniform(handle, unsafe(addr(value)), 0xffff)

def public bgfx_any_uniform ( name:string; _value:float4x4 )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type MAT4, 1u)
    if transpose_uniform_mat
        var value = transpose(_value)
        bgfx_set_uniform(handle, unsafe(addr(value)), 0xffff)
    else
        bgfx_set_uniform(handle, unsafe(addr(_value)), 0xffff)

def public bgfx_any_uniform ( name:string; _value:float4x4[] )
    var handle = bgfx_cache_uniform(name, bgfx_uniform_type MAT4, uint(length(value)))
    if transpose_uniform_mat
        var value : float4x4[length(_value)]
        for v,_v in value,_value
            v = transpose(_v)
        bgfx_set_uniform(handle, safe_addr(value), 0xffff)
    else
        bgfx_set_uniform(handle, unsafe(addr(_value)), 0xffff)

def public clone ( var image:image2D; tex:bgfx_texture_handle_s )
    image.texture2D = uint(tex.idx)

def public clone ( var sampler:sampler2D; tex:bgfx_texture_handle_s )
    sampler.texture2D = uint(tex.idx)

def private get_temp_dir
    let temp_dir = "{get_das_root()}/temp"
    mkdir(temp_dir)
    return temp_dir

def public bgfx_create_compute_shader_program ( cs : string; render_type : bgfx_renderer_type )
    let cs_bin_name = bgfx_cache_shader_file(cs, "", "c", render_type)
    var csh = bgfx_load_shader_from_bin(cs_bin_name)
    let prog = bgfx_create_compute_program(csh,true)
    if prog.idx==uint16(0xffff)
        panic("failed to create compute program")
    return prog

def public bgfx_create_compute_shader_program ( cs : string; func:function<void>; render_type : bgfx_renderer_type )
    if render_type == bgfx_renderer_type OPENGL
        invoke(func)
    return bgfx_create_compute_shader_program(cs, render_type)

def public bgfx_create_shader_program ( vs, vd, fs, fd : string; render_type : bgfx_renderer_type )
    var vda <- split(vd,"\n")
    var pda <- split(fd,"\n")
    var vpda <- combine(vda, pda)
    sort_unique(vpda)
    delete vda
    delete pda
    let decl = build_string <| $ ( writer )
        for t in vpda
            if length(t)>0
                writer |> write("{t}\n")
    delete vpda
    let vs_bin_name = bgfx_cache_shader_file(vs,decl,"v",render_type)
    let fs_bin_name = bgfx_cache_shader_file(fs,decl,"f",render_type)
    var vsh = bgfx_load_shader_from_bin(vs_bin_name)
    var fsh = bgfx_load_shader_from_bin(fs_bin_name)
    let prog = bgfx_create_program(vsh, fsh, true)
    if prog.idx==uint16(0xffff)
        panic("failed to create program")
    return prog

def public bgfx_cache_shader_file ( shader_const, shader_decl, shader_type : string; render_type : bgfx_renderer_type )
    let shader_const_hash = hash(shader_const)  // TODO: get better hash function
    let shader_decl_hash  = hash(shader_decl)   // TODO: get better hash function
    let temp_dir = get_temp_dir()
    let shader_file_name = "{shader_type}_{int(render_type)}_{shader_const_hash}_{shader_decl_hash}"
    var sh_name = "{temp_dir}/{shader_file_name}.sc"
    let sh_bin_name = "{temp_dir}/{shader_file_name}.bin"
    var fs : FStat
    if !stat(sh_bin_name,fs)
        fopen(sh_name,"wb") <| $ ( fsh )
            fwrite ( fsh, shader_const )
        if shader_type!="c"
            fopen("{temp_dir}/varying.def.sc","wb") <| $ ( fsh )
                fwrite ( fsh, shader_decl )
        if !bgfx_compile_shader_file ( sh_name, sh_bin_name, shader_type, render_type )
            panic("can't compile {sh_name}")
        verify(stat(sh_bin_name,fs),"missing output")
    return sh_bin_name

def public bgfx_compile_shader_file ( fin, fout, ftype:string; rt : bgfx_renderer_type )
    var platform = ""
    var profile = ""
    if rt==bgfx_renderer_type NOOP
        pass
    elif rt==bgfx_renderer_type AGC || rt==bgfx_renderer_type GNM
        platform = "orbis"
        profile = "pssl"
    elif rt==bgfx_renderer_type DIRECT3D9
        platform = "windows"
        if ftype=="v"
            profile = "vs_3_0"
        elif ftype=="f"
            profile = "ps_3_0"
        elif ftype=="c"
            profile = "cs_3_0"
    elif rt==bgfx_renderer_type DIRECT3D11 || rt==bgfx_renderer_type DIRECT3D12
        platform = "windows"
        if ftype=="v"
            profile = "vs_5_0"
        elif ftype=="f"
            profile = "ps_5_0"
        elif ftype=="c"
            profile = "cs_5_0"
    elif rt==bgfx_renderer_type METAL
        platform = "osx"
        profile = "metal"
    elif rt==bgfx_renderer_type NVN
        panic("unsupported?")
    elif rt==bgfx_renderer_type OPENGLES
        platform = "android"
    elif rt==bgfx_renderer_type OPENGL
        platform = "linux"
        profile = ftype=="c" ? "430" : "120"
    elif rt==bgfx_renderer_type VULKAN || rt==bgfx_renderer_type WEBGPU
        platform = "linux"
        profile = "spirv"
    let shaderc = "{get_das_root()}/modules/dasBGFX/bin/{BGFX_SHADERC_NAME}"
    let incl = "{get_das_root()}/modules/dasBGFX/bgfx/bgfx/src"
    let prof = profile=="" ? "" : " --profile {profile}"
    let sys = "\"{shaderc}\" -i {incl} -f {fin} -o {fout} --type {ftype} --platform {platform}{prof}"
    if VERBOSE_COMPILER
        print("{sys}\n")
    unsafe
        var text : array<string>
        let ex_code = popen(sys) <| $ ( f )
            if f != null
                while !feof(f)
                    let st = fgets(f)
                    text |> push(st)
            else
                print("das: can't popen shaderc: {shaderc}\n")
        if ex_code!=0 || VERBOSE_COMPILER
            for t in text
                print(t)
        if VERBOSE_COMPILER
            print("exit code {ex_code}\n")
        return ex_code==0

def public bgfx_load_shader_from_bin ( fileName:string )
    var sha : bgfx_shader_handle_s
    fopen(fileName,"rb") <| $ ( f )
        if f==null
            panic("can't open {fileName}")
        fmap(f) <| $ ( data )
            var mem = bgfx_alloc(uint(length(data)))
            var arr : array<uint8>
            unsafe
                _builtin_make_temp_array(arr, mem.data, int(mem.size) )
            for d,s in arr,data
                d = s
            sha = bgfx_create_shader(mem)
    return sha

def public bgfx_make_ref ( arr:array<auto(TT)> )
    unsafe
        return bgfx_make_ref(addr(arr[0]), uint(length(arr)*typeinfo(sizeof arr[0])))

def public bgfx_make_ref ( arr:auto(TT)[] )
    return bgfx_make_ref(unsafe(addr(arr[0])), uint(length(arr)*typeinfo(sizeof arr[0])))

def public bgfx_copy ( arr:array<auto(TT)> )
    unsafe
        return bgfx_copy(addr(arr[0]), uint(length(arr)*typeinfo(sizeof arr[0])))

def public bgfx_copy ( arr:auto(TT)[] )
    return bgfx_copy(unsafe(addr(arr[0])), uint(length(arr)*typeinfo(sizeof arr[0])))

def bgfx_load_image_from_bytes ( width,height:int; data:void? )
    var mem = bgfx_copy(data, uint(width*height*4))
    let sampler_flags = BGFX_SAMPLER_U_CLAMP | BGFX_SAMPLER_V_CLAMP
    let handle = bgfx_create_texture_2d(uint(width), uint(height), false, 1u,
        bgfx_texture_format RGBA8, BGFX_TEXTURE_NONE | uint64(sampler_flags), mem)
    return handle

def bgfx_load_image_from_file ( fname:string implicit; canfail:bool=false )
    var x, y, comp : int
    let data = stbi_load(fname, safe_addr(x), safe_addr(y), safe_addr(comp), 4)
    if data == null
        if !canfail
            let reason = stbi_failure_reason()
            panic(reason)
        return [[bgfx_texture_handle_s idx=uint16(0xffff)]]
    else
        var texture_id = bgfx_load_image_from_bytes(x, y, data)
        stbi_image_free(data)
        return texture_id

var private transpose_uniform_mat = false

def public bgfx_init ( winw,winh:int; rt:bgfx_renderer_type = bgfx_renderer_type COUNT; dbgfx:bool = false )
    var init : bgfx_init_s
    bgfx_init_ctor(safe_addr(init))
    init._type = rt
    init.resolution.width = uint(winw)
    init.resolution.height = uint(winh)
    init.resolution.reset = BGFX_RESET_VSYNC
    if dbgfx
        bgfx_init_debug(init)
    bgfx_init(safe_addr(init))
    let render_type = bgfx_get_renderer_type()
    if render_type==bgfx_renderer_type DIRECT3D11
        transpose_uniform_mat = true
    elif render_type==bgfx_renderer_type DIRECT3D12
        transpose_uniform_mat = true
    elif render_type==bgfx_renderer_type METAL
        transpose_uniform_mat = true
    else
        transpose_uniform_mat = false

/*
TODO: which of this transpose uniform mat?
    BGFX_RENDERER_TYPE_DIRECT3D9
    BGFX_RENDERER_TYPE_NOOP,
    BGFX_RENDERER_TYPE_AGC,
    BGFX_RENDERER_TYPE_DIRECT3D9,
    BGFX_RENDERER_TYPE_GNM,
    BGFX_RENDERER_TYPE_NVN,
    BGFX_RENDERER_TYPE_OPENGLES,
    BGFX_RENDERER_TYPE_OPENGL,
    BGFX_RENDERER_TYPE_VULKAN,
    BGFX_RENDERER_TYPE_WEBGPU,
*/