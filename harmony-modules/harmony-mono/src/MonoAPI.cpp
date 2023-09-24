//
// Created by liam_ on 9/24/2023.
//
#include "MonoAPI.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
void harmony_mono_log_trace(MonoString *str) {
    harmony::log::trace("C# : {}", harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_info(MonoString *str) {
    harmony::log::info("C# : {}", harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_warn(MonoString *str) {
    harmony::log::warn("C# : {}", harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_error(MonoString *str) {
    harmony::log::error("C# : {}", harmony::MonoUtils::GetStringFromMonoString(str));
}

float harmony_mono_get_frame_time() {
    return harmony::Time::GetFrameTime();
}

float harmony_mono_get_frame_time_unscaled() {
    return harmony::Time::GetFrameTimeUnscaled();
}

float harmony_mono_get_time_scale() {
    return harmony::Time::GetTimeScale();
}

void harmony_mono_set_time_scale(float newTimeScale)
{
    harmony::Time::SetTimeScale(newTimeScale);
}


