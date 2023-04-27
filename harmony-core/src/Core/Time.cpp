#include "Core/Time.h"

double harmony::Time::GetFrameTime() {
    return p_FrameTime * p_TimeScale;
}

double harmony::Time::GetFrameTimeUnscaled() {
    return p_FrameTime;
}

double harmony::Time::GetTimeScale() {
    return p_FrameTime;
}

void harmony::Time::SetTimeScale(double timeScale) {
    p_TimeScale = timeScale;
}
