require glfw/glfw_boost
require dasbgfx/bgfx_boost
require dasbgfx/bgfx_ttf
require daslib/defer
require daslib/math_boost
require daslib/safe_addr

[export]
def main
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    glfwWindowHint(int(GLFW_CLIENT_API), GLFW_NO_API)
    var window = glfwCreateWindow(1280, 720, "BGFX - Hello ttf", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetNativeWindow(window)
    bgfx_set_platform_data(safe_addr(pd))
    bgfx_init(1280,720) //,bgfx_renderer_type OPENGL)
    glfwSetWindowTitle(window, "BGFX - Hello ttf - {bgfx_get_renderer_type()}")
    bgfx_create_ttf_objects()
    let font <- load_ttf("{get_das_root()}/modules/dasBGFX/bgfx/bgfx/examples/runtime/font/droidsansmono.ttf")
    var hw_text <- font |> create_quads("Hello, world")
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    let dim = quads_dim(hw_text)
    let model = quads_view(hw_text, float2(3./(dim.vmax.x-dim.vmin.x)))
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetWindowSize(window, safe_addr(display_w), safe_addr(display_h))
        bgfx_reset(uint(display_w), uint(display_h), BGFX_RESET_VSYNC, bgfx_texture_format COUNT)
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
        // model-view-projection setup
        let view = translation(float3(0.0f, 0.0f, -4.0f))
        let projection = bgfx_mat_projection(45., float(display_w), float(display_h), 0.1, 50., bgfx_get_caps().homogeneousDepth,false)
        let mvp = projection * view * model
        font |> bgfx_draw_quads(0u, hw_text, mvp)
        font |> bgfx_draw_quads_2d(0u, hw_text, display_w, display_h, 100, 100)
        bgfx_frame(false)
    bgfx_shutdown()
