#pragma once

#include "Core/Alias.h"
#include "bgfx/bgfx.h"

namespace harmony {
    struct Attachment;
    enum AttachmentType : int;

    class Framebuffer {
    public:
        Framebuffer();
        ~Framebuffer();
        Attachment AddAttachment(AttachmentType attachmentType);

        uint32_t m_VirtualWidth, m_VirtualHeight;
        uint32_t m_FramebufferWidth, m_FramebufferHeight;
        bgfx::FrameBufferHandle m_FBH;
        bool p_Initialized;
    protected:
        Vector<Attachment> p_Attachments;
        friend class Renderer;
    };
};