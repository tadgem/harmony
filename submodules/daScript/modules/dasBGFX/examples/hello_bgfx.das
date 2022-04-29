require glfw/glfw_boost
require daslib/defer
require daslib/safe_addr

require dasbgfx/bgfx_boost

[export]
def main

    let WNDW_WIDTH = 1280
    let WNDW_HEIGHT = 720

    if glfwInit()==0
		panic("can't init glfw")
    defer <|
        glfwTerminate()
    glfwWindowHint(int(GLFW_CLIENT_API), GLFW_NO_API)
    var window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "Testing BGFX", null, null)
    if window==null
		panic("can't create window")
    defer <|
        glfwDestroyWindow(window)

    var pd: bgfx_platform_data_s
    pd.nwh = glfwGetNativeWindow(window)
    bgfx_set_platform_data(safe_addr(pd))

    var init: bgfx_init_s
    bgfx_init_ctor(safe_addr(init))

    init._type = bgfx_renderer_type COUNT
    init.resolution.width = uint(WNDW_WIDTH)
    init.resolution.height = uint(WNDW_HEIGHT)
    init.resolution.reset = BGFX_RESET_VSYNC
    bgfx_init(safe_addr(init))

    bgfx_set_view_clear(0u, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0u)

	bgfx_set_debug(BGFX_DEBUG_TEXT)

    while glfwWindowShouldClose(window)==0
        glfwPollEvents()
        var display_w, display_h : int
        glfwGetFramebufferSize(window, display_w, display_h)

        bgfx_set_view_rect(0u, 0u, 0u, uint(display_w), uint(display_h))

		// This dummy draw call is here to make sure that view 0 is cleared
		// if no other draw calls are submitted to view 0.
		let encoder = bgfx_encoder_begin(true)
		bgfx_encoder_touch(encoder, 0u)
		bgfx_encoder_end(encoder)

		bgfx_dbg_text_clear(0u, false)
		bgfx_dbg_text_printf(1u, 1u, 0x0f, "Hello BGFX")

        bgfx_frame(true)


    bgfx_shutdown()
