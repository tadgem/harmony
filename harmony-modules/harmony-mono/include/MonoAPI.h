//
// Created by liam_ on 9/24/2023.
//

#pragma once

#include "MonoUtils.h"
extern "C"
{
    void harmony_mono_log_trace(MonoString* str);
    void harmony_mono_log_info(MonoString* str);
    void harmony_mono_log_warn(MonoString* str);
    void harmony_mono_log_error(MonoString* str);
}