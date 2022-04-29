require glfw/glfw_boost
require dasbgfx/bgfx_boost
require daslib/defer
require daslib/math_boost
require daslib/safe_addr

require imgui
require imgui_app
require bgfx_imgui

[export]
def main
    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    glfwWindowHint(int(GLFW_CLIENT_API), GLFW_NO_API)
    var window = glfwCreateWindow(1280, 720, "BGFX - Hello IMGUI", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)
    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetNativeWindow(window)
    bgfx_set_platform_data(safe_addr(pd))
    bgfx_init(1280,720) // ,bgfx_renderer_type OPENGL)
    glfwSetWindowTitle(window, "BGFX - Hello IMGUI - {bgfx_get_renderer_type()}")
    bgfx_imgui_create(24.)
    ImGui_ImplGlfw_InitForOther(window, true)
    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, RGBA_TO_BGFX_UCOLOR(0.2,0.2,0.2,1.0), 1.0f, 0u)
    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetWindowSize(window, safe_addr(display_w), safe_addr(display_h))
        bgfx_reset(uint(display_w), uint(display_h), BGFX_RESET_VSYNC, bgfx_texture_format COUNT)
        bgfx_imgui_begin_frame(0u)
        ImGui_ImplGlfw_NewFrame()
        // now  go on with the framer
        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))
		// This dummy draw call is here to make sure that view 0 is cleared
		// if no other draw calls are submitted to view 0.
		let encoder = bgfx_encoder_begin(true)
		bgfx_encoder_touch(encoder, 0u)
		bgfx_encoder_end(encoder)
        ShowDemoWindow()
        bgfx_imgui_end_frame()
        bgfx_frame(true)
    ImGui_ImplGlfw_Shutdown()
    bgfx_imgui_destroy()
    bgfx_shutdown()
