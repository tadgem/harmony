#pragma once

#include "Core/Alias.h"
#include "Rendering/Attachment.h"
namespace harmony {

    class Framebuffer {
    public:

        enum ResolutionType
        {
            FullScale,
            HalfScale,
            QuarterScale,
            Custom
        };

        NLOHMANN_JSON_SERIALIZE_ENUM(ResolutionType, {
            { FullScale, "full"},
            { HalfScale, "half"},
            { QuarterScale, "quarter"},
            { Custom, "custom"},

        })

        explicit Framebuffer(Resolution res, ResolutionType resolutionType = ResolutionType::FullScale);
        ~Framebuffer();

        Attachment AddAttachment(AttachmentType attachmentType);

        bool Build();
        bool IsBuilt();
        void Bind();

        Resolution m_VirtualResoltuion;
        Resolution m_FramebufferResolution;

        bgfx::FrameBufferHandle m_FBH;
        bgfx::ViewId m_ViewID;

        ResolutionType m_ResolutionType;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Framebuffer, m_ResolutionType, m_FramebufferResolution)

    protected:
        void UpdateVirtualResolution(uint16_t w, uint16_t h);
        bgfx::TextureHandle CreateAttachmentInternal(Resolution res, AttachmentType type);
        Resolution GetScaledResolution(ResolutionType type, Resolution res);
        Vector<Attachment> p_Attachments;
        friend class Renderer;
    };
};