#pragma once

#include "Core/Alias.h"
#include "Rendering/Attachment.h"

namespace harmony {

    class Framebuffer {
    public:
        explicit Framebuffer(
                const String &name, Resolution res,
                Resolution::Type resolutionType = Resolution::Type::FullScale);

        ~Framebuffer();

        Attachment CreateAttachment(AttachmentType attachmentType);

        bool Build();

        bool IsBuilt();

        void Resize(uint16_t w, uint16_t h);

        void Clear();

        Resolution m_VirtualResoltuion;
        Resolution m_FramebufferResolution;
        bgfx::FrameBufferHandle m_FBH;
        bgfx::ViewId m_ViewID;
        Resolution::Type m_ResolutionType;
        Vector<Attachment> m_Attachments;
        const String m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Framebuffer, m_ResolutionType,
                                       m_FramebufferResolution)

    protected:
        void UpdateVirtualResolution(uint16_t w, uint16_t h);

        bgfx::TextureHandle CreateAttachmentInternal(Resolution res,
                                                     AttachmentType type);

        Resolution GetScaledResolution(Resolution::Type type, Resolution res);

        friend class Renderer;
    };
}; // namespace harmony