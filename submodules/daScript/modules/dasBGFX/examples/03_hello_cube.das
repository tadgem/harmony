require glfw/glfw_boost
require daslib/defer
require daslib/safe_addr
require daslib/math_boost
require dasbgfx/bgfx_boost

require dasbgfx/glsl_bgfx

var [[in]] a_position  : float3
var [[in]] a_normal    : float3
var [[in]] a_texcoord0 : float2
var [[inout]] v_color0 : float3
var [[inout]] v_texcoord0 : float2
var [[uniform, stage=0]] f_tex : sampler2D
var [[uniform]] v_model : float4x4
var [[uniform]] v_view : float4x4
var [[uniform]] v_projection : float4x4

[bgfx_fragment_program]
def fs_cube_main
    gl_FragColor.xyz = texture2D(f_tex,v_texcoord0).xyz * v_color0
    gl_FragColor.w = 1.

[bgfx_vertex_program]
def vs_cube_main
    let light = normalize(float3(1,-1,-1))
    let norm = normalize ( float3x3(v_model) * a_normal )
    gl_Position = v_projection * v_view * v_model * float4(a_position, 1.0)
    v_color0 = float3(saturate(-dot(norm,light)))
    v_texcoord0 = a_texcoord0

[bgfx_vertex_buffer]
struct Vertex
    position : float3
    [[normalized=true]] normal : float3
    texcoord0 : float2

let vertices = [[Vertex
    position=float3( 1, 1, 1), normal=float3(  0, 0, 1),  texcoord0=float2(0,0); // v0 (front)
    position=float3(-1, 1, 1), normal=float3(  0, 0, 1),  texcoord0=float2(1,0); // v1
    position=float3(-1,-1, 1), normal=float3(  0, 0, 1),  texcoord0=float2(1,1); // v2
    position=float3( 1,-1, 1), normal=float3(  0, 0, 1),  texcoord0=float2(0,1); // v3
    position=float3( 1, 1, 1), normal=float3(  1, 0, 0),  texcoord0=float2(0,0); // v0 (right)
    position=float3( 1,-1, 1), normal=float3(  1, 0, 0),  texcoord0=float2(1,0); // v3
    position=float3( 1,-1,-1), normal=float3(  1, 0, 0),  texcoord0=float2(1,1); // v4
    position=float3( 1, 1,-1), normal=float3(  1, 0, 0),  texcoord0=float2(0,1); // v5
    position=float3( 1, 1, 1), normal=float3(  0, 1, 0),  texcoord0=float2(0,0); // v0 (top)
    position=float3( 1, 1,-1), normal=float3(  0, 1, 0),  texcoord0=float2(1,0); // v5
    position=float3(-1, 1,-1), normal=float3(  0, 1, 0),  texcoord0=float2(1,1); // v6
    position=float3(-1, 1, 1), normal=float3(  0, 1, 0),  texcoord0=float2(0,1); // v1
    position=float3(-1, 1, 1), normal=float3( -1, 0, 0),  texcoord0=float2(0,0); // v1 (left)
    position=float3(-1, 1,-1), normal=float3( -1, 0, 0),  texcoord0=float2(1,0); // v6
    position=float3(-1,-1,-1), normal=float3( -1, 0, 0),  texcoord0=float2(1,1); // v7
    position=float3(-1,-1, 1), normal=float3( -1, 0, 0),  texcoord0=float2(0,1); // v2
    position=float3(-1,-1,-1), normal=float3(  0,-1, 0),  texcoord0=float2(0,0); // v7 (bottom)
    position=float3( 1,-1,-1), normal=float3(  0,-1, 0),  texcoord0=float2(1,0); // v4
    position=float3( 1,-1, 1), normal=float3(  0,-1, 0),  texcoord0=float2(1,1); // v3
    position=float3(-1,-1, 1), normal=float3(  0,-1, 0),  texcoord0=float2(0,1); // v2
    position=float3( 1,-1,-1), normal=float3(  0, 0,-1),  texcoord0=float2(0,0); // v4 (back)
    position=float3(-1,-1,-1), normal=float3(  0, 0,-1),  texcoord0=float2(1,0); // v7
    position=float3(-1, 1,-1), normal=float3(  0, 0,-1),  texcoord0=float2(1,1); // v6
    position=float3( 1, 1,-1), normal=float3(  0, 0,-1),  texcoord0=float2(0,1)  // v5
]]

let indices = [[int
     0; 1; 2;   2; 3; 0; // front
     4; 5; 6;   6; 7; 4; // right
     8; 9;10;  10;11; 8; // top
    12;13;14;  14;15;12; // left
    16;17;18;  18;19;16; // bottom
    20;21;22;  22;23;20  // back
]]

[export]
def main
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    glfwWindowHint(int(GLFW_CLIENT_API), GLFW_NO_API)
    var window = glfwCreateWindow(1280, 720, "BGFX - Hello cube", null, null)
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
    glfwSetWindowTitle(window, "BGFX - Hello cube - {bgfx_get_renderer_type()}")
    var pcvl_decl = bgfx_create_vertex_layout(type<Vertex>)
    var vbh = bgfx_create_vertex_buffer(bgfx_make_ref(vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    var ibh = bgfx_create_index_buffer(bgfx_make_ref(indices), BGFX_BUFFER_INDEX32)
    var program = bgfx_create_shader_program(@@vs_cube_main, @@fs_cube_main)
    var texture = bgfx_load_image_from_file("{get_das_root()}/modules/dasBgfx/examples/image.png")
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetWindowSize(window, safe_addr(display_w), safe_addr(display_h))
        bgfx_reset(uint(display_w), uint(display_h), BGFX_RESET_VSYNC, bgfx_texture_format COUNT)
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
        let t = glfwGetTime()
        if t > 10lf
            glfwSetTime(t - 10lf)
        let rot = un_quat_from_unit_vec_ang(normalize(float3(1.,1.,0.)), float(t)*PI*2.*0.1)
        v_view = look_at_rh(float3(0,0,10),float3(0,0,0),float3(0,1,0))
        v_model = compose(float4(0,0,0,0), rot, float4(1.0))
        v_projection = bgfx_mat_projection(45., float(display_w), float(display_h), 0.1, 50., bgfx_get_caps().homogeneousDepth,false)
        bgfx_set_vertex_buffer(0u, vbh)
        bgfx_set_index_buffer(ibh)
        f_tex := texture
        vs_cube_main_bind_uniform()
        fs_cube_main_bind_uniform()
        bgfx_set_state(BGFX_STATE_DEFAULT,0u)
        bgfx_submit(0u, program, 1u, BGFX_DISCARD_NONE)
        bgfx_frame(true)
    bgfx_shutdown()
