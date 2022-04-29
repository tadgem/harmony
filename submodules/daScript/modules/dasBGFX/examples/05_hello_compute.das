require glfw/glfw_boost
require dasbgfx/bgfx_boost
require daslib/defer
require daslib/math_boost
require daslib/safe_addr

var [[in]] a_position : float2
var [[in]] a_color0 : float3
var [[in]] a_texcoord0 : float2
var [[inout]] v_color0 : float3
var [[inout]] v_texcoord0 : float2
var [[uniform, stage=0]] f_tex : sampler2D
var [[uniform, format=rgba8, stage=0, writeonly]] c_destTex : image2D
var [[uniform, format=rgba32f, stage=1, readwrite]] c_matTex : image2D
var [[uniform]] c_offset : float4
var [[uniform]] c_mat_z : float4x4
var [[uniform]] v_ortho : float4x4

[bgfx_vertex_program]
def vs_main
    v_color0 = a_color0
    v_texcoord0 = a_texcoord0
    gl_Position = v_ortho * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program]
def fs_main
    gl_FragColor = texture2D(f_tex,v_texcoord0) * float4(v_color0, 1.0)

[bgfx_compute_program(local_size_x=16,local_size_y=16)]
def compute_effect
    let storePos = int2(gl_GlobalInvocationID.xy)
    let bitPos = storePos + int2(int(c_offset.x)*3,int(c_offset.x)*3)
    let bit = (bitPos.x>>4) & (bitPos.y>>4) & 1
    if bit != 0
        imageStore(c_destTex,storePos, float4(storePos.x,storePos.y,0,255)/255.)
    else
        imageStore(c_destTex,storePos, float4(1.,.5,.25,1.))
    if gl_GlobalInvocationID.xy==uint2(0u,0u)
        var c_mat_a, c_mat_b : float4x4
        // unpack
        c_mat_a[0] = imageLoad(c_matTex, int2(0,0))
        c_mat_a[1] = imageLoad(c_matTex, int2(1,0))
        c_mat_a[2] = imageLoad(c_matTex, int2(2,0))
        c_mat_a[3] = imageLoad(c_matTex, int2(3,0))
        c_mat_b[0] = imageLoad(c_matTex, int2(0,1))
        c_mat_b[1] = imageLoad(c_matTex, int2(1,1))
        c_mat_b[2] = imageLoad(c_matTex, int2(2,1))
        c_mat_b[3] = imageLoad(c_matTex, int2(3,1))
        let a_times_b = c_mat_a * c_mat_b
        let b_times_a = c_mat_b * c_mat_a
        let a_times_1234 = c_mat_a * float4(1,2,3,4)
        let b_times_1234 = c_mat_b * float4(1,2,3,4)
        // pack
        imageStore(c_matTex, int2(0,2), a_times_b[0])
        imageStore(c_matTex, int2(1,2), a_times_b[1])
        imageStore(c_matTex, int2(2,2), a_times_b[2])
        imageStore(c_matTex, int2(3,2), a_times_b[3])
        imageStore(c_matTex, int2(0,3), b_times_a[0])
        imageStore(c_matTex, int2(1,3), b_times_a[1])
        imageStore(c_matTex, int2(2,3), b_times_a[2])
        imageStore(c_matTex, int2(3,3), b_times_a[3])
        imageStore(c_matTex, int2(0,4), a_times_1234)
        imageStore(c_matTex, int2(1,4), b_times_1234)
        imageStore(c_matTex, int2(2,4), float4(0,0,0,0))
        imageStore(c_matTex, int2(3,4), float4(0,0,0,0))
        imageStore(c_matTex, int2(0,5), c_mat_z[0])
        imageStore(c_matTex, int2(1,5), c_mat_z[1])
        imageStore(c_matTex, int2(2,5), c_mat_z[2])
        imageStore(c_matTex, int2(3,5), c_mat_z[3])

[bgfx_vertex_buffer]
struct Vertex
    position  : float2
    color0    : float3
    texcoord0 : float2

let vertices = [[Vertex
        position=float2(-1.0, 1.0), color0=float3(0.0,0.0,0.0), texcoord0=float2(0.0,0.0);
        position=float2( 1.0, 1.0), color0=float3(1.0,1.0,0.0), texcoord0=float2(1.0,0.0);
        position=float2( 1.0,-1.0), color0=float3(1.0,0.0,0.0), texcoord0=float2(1.0,1.0);
        position=float2(-1.0,-1.0), color0=float3(1.0,1.0,0.0), texcoord0=float2(0.0,1.0)
]]

let indices = [[int 0; 2; 1; 2; 0; 3]]

struct CMat
    a, b, c, d, e, z : float4x4

def set_cmat ( var tex:bgfx_texture_handle_s; m : CMat )
    var mem = bgfx_copy(unsafe(addr(m)), uint(typeinfo(sizeof m)))
    bgfx_update_texture_2d(tex, 0u, 0u, 0u, 0u, 4u, 6u, mem, uint(4*4*typeinfo(sizeof type<float>)))

def get_cmat ( var tex:bgfx_texture_handle_s; var m : CMat )
    return bgfx_read_texture(tex, unsafe(addr(m)), 0u)

[export]
def main
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    glfwWindowHint(int(GLFW_CLIENT_API), GLFW_NO_API)
    var window = glfwCreateWindow(1280, 720, "BGFX - Hello compute", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetNativeWindow(window)
    bgfx_set_platform_data(safe_addr(pd))
    // bgfx_init(1280,720,bgfx_renderer_type DIRECT3D11,true)
    bgfx_init(1280,720,bgfx_renderer_type DIRECT3D12)
    // bgfx_init(1280,720,bgfx_renderer_type OPENGL)
    glfwSetWindowTitle(window, "BGFX - Hello compute - {bgfx_get_renderer_type()}")
    var can_read_back = false
    if (bgfx_get_caps().supported & BGFX_CAPS_TEXTURE_READ_BACK) != 0ul
        can_read_back = true
    var pcvl_decl = bgfx_create_vertex_layout(type<Vertex>)
    var vbh = bgfx_create_vertex_buffer(bgfx_make_ref(vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    var ibh = bgfx_create_index_buffer(bgfx_make_ref(indices), BGFX_BUFFER_INDEX32)
    var compute_program = bgfx_create_compute_shader_program(@@compute_effect)
    var program = bgfx_create_shader_program(@@vs_main,@@fs_main)
    var texture = bgfx_create_texture_2d(256u, 256u, false, 1u, bgfx_texture_format RGBA8, BGFX_TEXTURE_COMPUTE_WRITE, null)
    if texture.idx==uint16(0xffff)
        panic("can't create texture")
    var mat_texture = bgfx_create_texture_2d(4u, 6u, false, 1u, bgfx_texture_format RGBA32F,
        BGFX_TEXTURE_COMPUTE_WRITE  | BGFX_TEXTURE_READ_BACK, null)
    if mat_texture.idx==uint16(0xffff)
        panic("can't create texture")
    v_ortho = bgfx_mat_ortho(-1.,1.,-1.,1.,-100.,100.,0.,bgfx_get_caps().homogeneousDepth,false)
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    var ioffset = 0
    var c_mat_res : CMat
    var c_res_frame = 0u
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetWindowSize(window, safe_addr(display_w), safe_addr(display_h))
        bgfx_reset(uint(display_w), uint(display_h), BGFX_RESET_VSYNC, bgfx_texture_format COUNT)
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
        var c_mat : CMat
        let rot = un_quat_from_unit_vec_ang(normalize(float3(1.,0.,0.)), PI*0.25)
        c_mat.a = compose(float4(0.), rot, float4(1.))
        c_mat.b = translation(float3(1.,2.,3.))
        identity(c_mat.c)
        identity(c_mat.d)
        set_cmat(mat_texture, c_mat)
        c_mat_z[0] = float4(1,2,3,4)
        c_mat_z[1] = float4(5,6,7,8)
        c_mat_z[2] = float4(9,10,11,12)
        c_mat_z[3] = float4(13,14,15,16)
        c_offset.x = float(ioffset++)
        c_destTex := texture
        c_matTex := mat_texture
        compute_effect_bind_uniform()
        bgfx_dispatch(0u, compute_program, 256u/16u, 256u/16u, 1u, 0u)
        bgfx_set_vertex_buffer(0u, vbh)
        bgfx_set_index_buffer(ibh)
        f_tex := texture
        vs_main_bind_uniform()
        fs_main_bind_uniform()
        bgfx_set_state(BGFX_STATE_DEFAULT, 0u)
        bgfx_submit(0u, program, 1u, BGFX_DISCARD_NONE)
        if c_res_frame==0u
            c_res_frame = get_cmat(mat_texture, c_mat_res)
        let n_frame = bgfx_frame(false)
        if n_frame>=c_res_frame && c_res_frame!=0u
            var e_mat = c_mat
            e_mat.c = e_mat.a * e_mat.b
            e_mat.d = e_mat.b * e_mat.a
            e_mat.e[0] = e_mat.a * float4(1,2,3,4)
            e_mat.e[1] = e_mat.b * float4(1,2,3,4)
            e_mat.z = c_mat_z
            if can_read_back
                if c_mat_res.c[0].x!=0.
                    if c_mat_res.c != e_mat.c
                        print("{c_mat_res.c} vs {e_mat.c}\n")
                    if c_mat_res.d != e_mat.d
                        print("{c_mat_res.d} vs {e_mat.d}\n")
                    if c_mat_res.e[0] != e_mat.e[0]
                        print("{c_mat_res.e[0]} vs {e_mat.e[0]}\n")
                    if c_mat_res.e[1]!=e_mat.e[1]
                        print("{c_mat_res.e[1]} vs {e_mat.e[1]}\n")
                    if c_mat_res.z!=c_mat_z
                        print("{c_mat_res.z} vs {c_mat_z}\n")
            c_res_frame = 0u
    bgfx_shutdown()
