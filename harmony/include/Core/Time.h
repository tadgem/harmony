#pragma once

namespace harmony
{
    class Time
    {
    public:
        static double   GetFrameTime();
        static double   GetFrameTimeUnscaled();
        static double   GetTimeScale();
        static void     SetTimeScale(double timeScale);
    protected:
        friend class Program;

        inline static double p_FrameTime = 0.0;
        inline static double p_TimeScale = 1.0;
    };
};