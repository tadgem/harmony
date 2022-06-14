#pragma once
#include "Core/Memory.h"
#include "bgfx/bgfx.h"

namespace harmony
{
    struct BGFXFramebufferHandle
    {
        bgfx::FrameBufferHandle m_Handle;
        
    };

    class Framebuffer
    {
        public: 
        Framebuffer();

        uint32_t m_Width;
        uint32_t m_Height;

    };
};