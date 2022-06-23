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
        inline static double p_FrameTime = 0.0;
        inline static double p_TimeScale = 1.0;
        friend class Program;


        /*int64_t now = bx::getHPCounter();
        static int64_t last = now;
        const int64_t frameTime = now - last;
        last = now;
        const double freq = double(bx::getHPFrequency());*/
    };
};