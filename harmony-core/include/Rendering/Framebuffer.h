#pragma once

#include "Core/Alias.h"
#include "bgfx/bgfx.h"

namespace harmony {
    struct BGFXFramebufferHandle {
        bgfx::FrameBufferHandle m_FB;

    };

    class Framebuffer {
    public:
        Framebuffer();

        uint32_t m_Width;
        uint32_t m_Height;

    };
};