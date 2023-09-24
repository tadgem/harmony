//
// Created by liam_ on 9/24/2023.
//
#include "MonoAPI.h"
#include "Core/Log.hpp"

void harmony_mono_log_trace(MonoString *str) {
    harmony::log::trace(harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_info(MonoString *str) {
    harmony::log::info(harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_warn(MonoString *str) {
    harmony::log::warn(harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_error(MonoString *str) {
    harmony::log::error(harmony::MonoUtils::GetStringFromMonoString(str));
}

