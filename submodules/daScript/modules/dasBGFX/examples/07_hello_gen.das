require glfw/glfw_boost
require daslib/defer
require daslib/safe_addr
require daslib/math_boost
require dasbgfx/bgfx_boost
require dasbgfx/bgfx_gen

require dasbgfx/glsl_bgfx

var [[in]] a_position : float3
var [[in]] a_normal : float3
var [[in]] a_texcoord0 : float2
var [[uniform]] v_model : float4x4
var [[uniform]] v_view : float4x4
var [[uniform]] v_projection : float4x4
var [[inout]] v_texcoord0 : float2
var [[inout]] v_normal : float3
var [[inout]] v_texcoord1 : float3
var [[uniform]] f_camera_position : float3
var [[uniform, stage=0, sampler=MIN_POINT, sampler=MAG_POINT]] f_tex : sampler2D

[bgfx_vertex_program]
def vs_preview
    v_texcoord0 = a_texcoord0
    v_normal = normalize ( float3x3(v_model) * a_normal )
    let tpos = v_model * float4(a_position, 1.0)
    v_texcoord1 = tpos.xyz
    gl_Position = v_projection * v_view * tpos

[bgfx_fragment_program]
def fs_preview
    let pS = 24.0
    let light_dir = normalize(float3(-1,-2,-3))
    let camera_dir = normalize(v_texcoord1)
    let normal = normalize(v_normal)
    let k = -dot(light_dir,normal)
    let diffuse = float3(saturate(k))
    let refl = normalize ( reflect(camera_dir,normal) )
    let kS = saturate(dot(-light_dir,refl))
    let specular = float3(pow(kS,pS)*kS)
    gl_FragColor.xyz = texture2D(f_tex,v_texcoord0).xyz * diffuse + specular
    gl_FragColor.w = 1.

[export]
def main
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    glfwWindowHint(int(GLFW_CLIENT_API), GLFW_NO_API)
    var window = glfwCreateWindow(1280, 720, "BGFX - Hello generated geometry", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetNativeWindow(window)
    bgfx_set_platform_data(safe_addr(pd))
    bgfx_init(1280,720)
    glfwSetWindowTitle(window, "BGFX - Hello generated geometry - {bgfx_get_renderer_type()}")
    var program = bgfx_create_shader_program(@@vs_preview,@@fs_preview)
    var sphere <- gen_sphere(32,16,false) |> bgfx_create_geometry_fragment
    var cube <- gen_cube() |> bgfx_create_geometry_fragment
    var cylinder <- gen_cylinder(GenDirection xz, 32) |> bgfx_create_geometry_fragment
    let checkerboard_texture = gen_image_checkerboard(16,16, 0xff404040 , 0xff808080) |> bgfx_create_texture
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
        f_camera_position = float3(0,0,8)
        v_view = look_at_rh(f_camera_position,float3(0,0,0),float3(0,1,0))
        let rot = un_quat_from_unit_vec_ang(normalize(float3(1.,1.,0.)), float(t)*PI*2.*0.1)
        v_projection = bgfx_mat_projection(45., float(display_w), float(display_h), 0.1, 50., bgfx_get_caps().homogeneousDepth,false)
        f_tex := checkerboard_texture
        // cube
        v_model = compose(float4(-3,0,0,0), rot, float4(1.0))
        vs_preview_bind_uniform()
        fs_preview_bind_uniform()
        bgfx_set_state(BGFX_STATE_DEFAULT,0u)
        bgfx_draw_geometry_fragment(0u, program, cube)
        // sphere
        v_model = compose(float4(0,0,0,0), rot, float4(1.0))
        vs_preview_bind_uniform()
        fs_preview_bind_uniform()
        bgfx_set_state(BGFX_STATE_DEFAULT,0u)
        bgfx_draw_geometry_fragment(0u, program, sphere)
        // cylinder
        v_model = compose(float4(3,0,0,0), rot, float4(1.0))
        vs_preview_bind_uniform()
        fs_preview_bind_uniform()
        bgfx_set_state(BGFX_STATE_DEFAULT,0u)
        bgfx_draw_geometry_fragment(0u, program, cylinder)
        bgfx_frame(true)
    bgfx_shutdown()
