require glfw/glfw_boost
require dasbgfx/bgfx_boost
require daslib/defer
require daslib/math_boost
require daslib/safe_addr

// NOTE
//  this sample demonstrates overwrites for most attributes

var [[in, semantics=POSITION]]     a_position  : float2
var [[in, semantics=COLOR0]]       a_color0    : float3
var [[in, semantics=TEXCOORD0]]    a_texcoord0 : float2
var [[inout, semantics=COLOR0]]    v_color0    : float3
var [[inout, semantics=TEXCOORD0]] v_texcoord0 : float2
var [[uniform, stage=0]] f_tex : sampler2D
var [[uniform]] v_ortho : float4x4

[bgfx_vertex_program]
def vs_main
    v_color0 = a_color0
    v_texcoord0 = a_texcoord0
    gl_Position = v_ortho * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program]
def fs_main
    gl_FragColor = texture2D(f_tex,v_texcoord0) * float4(v_color0, 1.0)

[bgfx_vertex_buffer]
struct Vertex
    [[type=FLOAT, size=2, semantics=POSITION,  normalized=false, as_int=false]] xy : float2
    [[type=FLOAT, size=3, semantics=COLOR0,    normalized=false, as_int=false]] rgb : float3
    [[type=FLOAT, size=2, semantics=TEXCOORD0, normalized=false, as_int=false]] uv : float2

let vertices = [[Vertex
    xy=float2(-0.5, 0.5), rgb=float3(0.0,0.0,0.0), uv=float2(0.0,0.0);
    xy=float2( 0.5, 0.5), rgb=float3(1.0,1.0,0.0), uv=float2(1.0,0.0);
    xy=float2( 0.5,-0.5), rgb=float3(1.0,0.0,0.0), uv=float2(1.0,1.0);
    xy=float2(-0.5,-0.5), rgb=float3(1.0,1.0,0.0), uv=float2(0.0,1.0)
]]

let indices = [[int 0; 2; 1; 2; 0; 3]]

[export]
def main
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    glfwWindowHint(int(GLFW_CLIENT_API), GLFW_NO_API)
    var window = glfwCreateWindow(1280, 720, "BGFX - Hello image", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetNativeWindow(window)
    bgfx_set_platform_data(safe_addr(pd))
    bgfx_init(1280,720)
    glfwSetWindowTitle(window, "BGFX - Hello image - {bgfx_get_renderer_type()}")
    var pcvl_decl = bgfx_create_vertex_layout(type<Vertex>)
    var vbh = bgfx_create_vertex_buffer(bgfx_make_ref(vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    var ibh = bgfx_create_index_buffer(bgfx_make_ref(indices), BGFX_BUFFER_INDEX32)
    var program = bgfx_create_shader_program(@@vs_main, @@fs_main)
    var texture = bgfx_load_image_from_file("{get_das_root()}/modules/dasBgfx/examples/image.png")
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    v_ortho = bgfx_mat_ortho(-1.,1.,-1.,1.,-100.,100.,0.,bgfx_get_caps().homogeneousDepth,false)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetWindowSize(window, safe_addr(display_w), safe_addr(display_h))
        bgfx_reset(uint(display_w), uint(display_h), BGFX_RESET_VSYNC, bgfx_texture_format COUNT)
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
        bgfx_set_vertex_buffer(0u, vbh)
        bgfx_set_index_buffer(ibh)
        f_tex := texture
        vs_main_bind_uniform()
        fs_main_bind_uniform()
        bgfx_set_state(BGFX_STATE_DEFAULT, 0u)
        bgfx_submit(0u, program, 1u, BGFX_DISCARD_NONE)
        bgfx_frame(false)
    bgfx_shutdown()
