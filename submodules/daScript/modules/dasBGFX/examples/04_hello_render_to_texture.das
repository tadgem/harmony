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
var [[uniform]] f_tex : sampler2D
var [[uniform]] f_offset : float4
var [[uniform]] v_ortho : float4x4

[bgfx_vertex_program]
def vs_main
    v_color0 = a_color0
    v_texcoord0 = a_texcoord0
    gl_Position = v_ortho * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program]
def fs_main
    gl_FragColor = texture2D(f_tex,v_texcoord0+f_offset.xy) * float4(v_color0, 1.0)

def checker(uv:float2; checkSize:float=8.0)
    let fmodResult = (floor(checkSize * uv.x) + floor(checkSize * uv.y)) % 2.0
    return max(sign(fmodResult), 0.0);

def greyscale(color:float3)
    return dot(color,float3(0.2126,0.7152,0.0722))

[bgfx_vertex_program]
def vs_display_main
    v_texcoord0 = a_texcoord0
    gl_Position = v_ortho * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program]
def fs_display_main
    let f = checker(v_texcoord0.xy)
    let trgb = texture2D(f_tex,float2(v_texcoord0.x,v_texcoord0.y * f_offset.w)).xyz
    let tgrey = greyscale(trgb)
    gl_FragColor.xyz = trgb*f + float3(tgrey)*(1.0-f)
    gl_FragColor.w = 1.

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

let VIEW_MAIN = 0u
let VIEW_FB = 1u

[export]
def main
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    glfwWindowHint(int(GLFW_CLIENT_API), GLFW_NO_API)
    var window = glfwCreateWindow(1280, 720, "BGFX - Hello render to texture", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetNativeWindow(window)
    bgfx_set_platform_data(safe_addr(pd))
    bgfx_init(1280,720)
    // bgfx_init(1280,720,bgfx_renderer_type DIRECT3D12)
    // bgfx_init(1280,720,bgfx_renderer_type OPENGL)
    glfwSetWindowTitle(window, "BGFX - Hello render to texture - {bgfx_get_renderer_type()}")
    var pcvl_decl = bgfx_create_vertex_layout(type<Vertex>)
    var vbh = bgfx_create_vertex_buffer(bgfx_make_ref(vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    var ibh = bgfx_create_index_buffer(bgfx_make_ref(indices), BGFX_BUFFER_INDEX32)
    var program = bgfx_create_shader_program(@@vs_main,@@fs_main)
    var display_program = bgfx_create_shader_program(@@vs_display_main,@@fs_display_main)
    var texture = bgfx_load_image_from_file("{get_das_root()}/modules/dasBgfx/examples/image.png")
    var frame_buffer = bgfx_create_frame_buffer(256u, 256u, bgfx_texture_format RGBA8, BGFX_TEXTURE_NONE)
    bgfx_set_view_name(VIEW_MAIN, "main")
    bgfx_set_view_clear(VIEW_MAIN, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    bgfx_set_view_frame_buffer(VIEW_MAIN, [[bgfx_frame_buffer_handle_s idx=BGFX_INVALID_HANDLE]])
    bgfx_set_view_name(VIEW_FB, "fb")
    bgfx_set_view_clear(VIEW_FB, BGFX_CLEAR_COLOR, 0u, 1.0f, 0u)
    v_ortho = bgfx_mat_ortho(-1.,1.,-1.,1.,-100.,100.,0.,bgfx_get_caps().homogeneousDepth,false)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetWindowSize(window, safe_addr(display_w), safe_addr(display_h))
        bgfx_reset(uint(display_w), uint(display_h), BGFX_RESET_VSYNC, bgfx_texture_format COUNT)
        // fb
        bgfx_set_view_frame_buffer(VIEW_FB,frame_buffer)
        bgfx_set_view_rect(VIEW_FB, 0u, 0u, 256u, 256u)
        let t = glfwGetTime()
        if t > 1lf
            glfwSetTime(t - 1lf)
        let ft = float(t)
        f_offset = float4(ft,sin(ft*PI*2.)*0.25,0.,bgfx_get_caps().originBottomLeft ? -1. : 1.)
        bgfx_set_vertex_buffer(0u, vbh)
        bgfx_set_index_buffer(ibh)
        f_tex := texture
        vs_main_bind_uniform()
        fs_main_bind_uniform()
        bgfx_set_state(BGFX_STATE_WRITE_RGB, 0u)
        bgfx_submit(VIEW_FB, program, 1u, BGFX_DISCARD_NONE)
        // now to main window
        bgfx_set_view_rect(VIEW_MAIN, 0u, 0u, uint(display_w), uint(display_h))
        bgfx_set_vertex_buffer(0u, vbh)
        bgfx_set_index_buffer(ibh)
        f_tex := bgfx_get_texture(frame_buffer,0u)
        vs_display_main_bind_uniform()
        fs_display_main_bind_uniform()
        bgfx_set_state(BGFX_STATE_DEFAULT, 0u)
        bgfx_submit(VIEW_MAIN, display_program, 1u, BGFX_DISCARD_NONE)
        bgfx_frame(false)
    bgfx_shutdown()
