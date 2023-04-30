#include <optick.h>
#include "Core/Time.h"

double harmony::Time::GetFrameTime() {
    OPTICK_EVENT();
    return p_FrameTime * p_TimeScale;
}

double harmony::Time::GetFrameTimeUnscaled() {
    OPTICK_EVENT();
    return p_FrameTime;
}

double harmony::Time::GetTimeScale() {
    OPTICK_EVENT();
    return p_FrameTime;
}

void harmony::Time::SetTimeScale(double timeScale) {
    OPTICK_EVENT();
    p_TimeScale = timeScale;
}
