require dasbgfx/bgfx_boost
require imgui/imgui_boost
require daslib/safe_addr
require daslib/static_let
require math
require strings

[export]
def init
    print("testscript.das init")

[export]
def update
    static_let <|
        var show_window = true
    Begin("daScript ImGui Window 2 Electric Boogaloo", safe_addr(show_window))
    End()

[export]
def cleanup
    print("testscript.das init")