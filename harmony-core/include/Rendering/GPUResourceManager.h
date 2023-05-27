//
// Created by Admin on 5/27/2023.
//

#ifndef HARMONY_DOJO_GPURESOURCEMANAGER_H
#define HARMONY_DOJO_GPURESOURCEMANAGER_H

#include <cstdint>

namespace harmony
{
    class GPUResourceManager
    {
    public:
        static uint16_t GetMaxFramebufferWidth();
        static uint16_t GetMaxFramebufferHeight();

    protected:
        static uint16_t MAX_FRAMEBUFFER_RESOLUTION_X;
        static uint16_t MAX_FRAMEBUFFER_RESOLUTION_Y;

        friend class Program;

    };
}

#endif //HARMONY_DOJO_GPURESOURCEMANAGER_H
