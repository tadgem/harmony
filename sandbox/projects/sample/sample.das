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
[export]
def init
    print("sample.das init")
    var program = bgfx_create_shader_program(@@vs_main, @@fs_main)

[export]
def update
    static_let <|
        var show_window = true
    Begin("daScript ImGui Window", safe_addr(show_window))
    End()

[export]
def cleanup
    print("sample.das init")