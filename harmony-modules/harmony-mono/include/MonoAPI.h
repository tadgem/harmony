//
// Created by liam_ on 9/24/2023.
//

#pragma once

#include "MonoUtils.h"
#include "Core/Scene.h"

extern "C"
{
    void harmony_mono_log_trace(MonoString* str);
    void harmony_mono_log_info(MonoString* str);
    void harmony_mono_log_warn(MonoString* str);
    void harmony_mono_log_error(MonoString* str);

    float harmony_mono_get_frame_time();
    float harmony_mono_get_frame_time_unscaled();
    float harmony_mono_get_time_scale();
    void  harmony_mono_set_time_scale(float newTimeScale);

    harmony::Program*   harmony_mono_get_program();
    harmony::Scene*     harmony_mono_get_active_scene();

}