#pragma once

#include "imgui/imgui_bgfx.h"

namespace das {

void bgfx_imgui_create ( float fontSize );
void bgfx_imgui_destroy ();
void bgfx_imgui_begin_frame(uint32_t viewId);
void bgfx_imgui_end_frame();

}
