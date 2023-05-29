//
// Created by Admin on 5/27/2023.
//

#ifndef HARMONY_CORE_TEXTURE_H
#define HARMONY_CORE_TEXTURE_H
#include "ThirdParty/json.hpp"
#include "bgfx/bgfx.h"

namespace harmony {

    struct Resolution
    {
        uint16_t Width = 0, Height = 0;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Resolution, Width, Height)
    };

    enum AttachmentType : int {
        UnknownAttachmentType = 1,
        RGBA8 = 2,
        RGBA16F = 4,
        RGBA32F = 8,
        RGBA = RGBA8 | RGBA16F | RGBA32F,
        Depth16F = 16,
        Depth24F = 32,
        Depth32F = 64,
        Depth = Depth16F | Depth24F | Depth32F

    };

    AttachmentType operator|(AttachmentType a, AttachmentType b);

    AttachmentType operator&(AttachmentType a, AttachmentType b);

    AttachmentType operator^(AttachmentType a, AttachmentType b);

    AttachmentType &operator|=(AttachmentType &a, AttachmentType b);

    AttachmentType &operator&=(AttachmentType &a, AttachmentType b);

    AttachmentType &operator^=(AttachmentType &a, AttachmentType b);

    AttachmentType operator~(AttachmentType a);

    NLOHMANN_JSON_SERIALIZE_ENUM(AttachmentType, {
        { UnknownAttachmentType, "unknown" },
        { RGBA8, "rgba8" },
        { RGBA16F, "rgba16" },
        { RGBA32F, "rgba32" },
        { RGBA, "rgba"},
        { Depth16F, "d16" },
        { Depth24F, "d24" },
        { Depth32F, "d32" },
        { Depth, "depth"}
    })

    uint32_t GetAttachmentTypePixelSize(AttachmentType type);

    bgfx::TextureFormat::Enum GetBGFXTextureFormat(AttachmentType type);

    struct Attachment {

        ~Attachment();
        bgfx::TextureHandle m_Handle { UINT16_MAX};
        AttachmentType m_Type;

        uint16_t m_Width, m_Height;

        uint32_t CalculateAttachmentSize();

        bool operator==(const Attachment &rhs) const {
            return m_Handle.idx == rhs.m_Handle.idx &&
                   m_Type == rhs.m_Type;
        }

        bool operator!=(const Attachment &rhs) const {
            return !(rhs == *this);
        }
    };
}
#endif