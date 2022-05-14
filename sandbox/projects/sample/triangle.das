require dasbgfx/bgfx_boost
require imgui/imgui_boost
require daslib/safe_addr
require daslib/static_let
require math
require strings
require daslib/defer
require daslib/math_boost

var [[in]] a_position : float2
var [[in]] a_color0 : float3
var [[inout]] v_color0 : float3
var [[uniform]] v_ortho : float4x4

[bgfx_vertex_program]
def vs_main
    v_color0 = a_color0
    gl_Position = v_ortho * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program]
def fs_main
    gl_FragColor = float4(v_color0, 1.0)

[bgfx_vertex_buffer]
struct Vertex
    position : float2
    color0 : float3

var vertices = [[Vertex
    position=float2(-0.5, 0.5), color0=float3(0.0,0.0,0.0);
    position=float2( 0.5,-0.5), color0=float3(1.0,0.0,0.0);
    position=float2( 0.5, 0.5), color0=float3(1.0,1.0,0.0)
]]

struct Submission
    vbh : bgfx_vertex_buffer_handle_s
    ibh : bgfx_index_buffer_handle_s
    program : bgfx_program_handle_s

let indices = [[int 0;1;2]]

var state : Submission

[export]
def init
    var pcvl_decl = bgfx_create_vertex_layout(type<Vertex>)
    state.vbh = bgfx_create_vertex_buffer(bgfx_make_ref(vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
    state.ibh = bgfx_create_index_buffer(bgfx_make_ref(indices), BGFX_BUFFER_INDEX32)
    state.program = bgfx_create_shader_program(@@vs_main, @@fs_main)
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    v_ortho = bgfx_mat_ortho(-1.,1.,-1.,1.,-100.,100.,0.,bgfx_get_caps().homogeneousDepth,false)

[export]
def update
    static_let <|
        var show_window = true
    Begin("daScript ImGui Window", safe_addr(show_window))
    End()

    bgfx_set_vertex_buffer(0u, state.vbh)
    bgfx_set_index_buffer(state.ibh)
    vs_main_bind_uniform()
    fs_main_bind_uniform()
    bgfx_set_state(BGFX_STATE_DEFAULT, 0u)
    bgfx_submit(0u, state.program, 1u, BGFX_DISCARD_NONE)

[export]
def cleanup
    print("sample.das init")