//
// Created by Admin on 5/27/2023.
//

#ifndef HARMONY_CORE_TEXTURE_H
#define HARMONY_CORE_TEXTURE_H
#include "ThirdParty/json.hpp"
#include "bgfx/bgfx.h"

namespace harmony {

    enum AttachmentType : int {
        Unknown = 1,
        RGBA8F = 2,
        RGBA16F = 4,
        RGBA32F = 8,
        RGBA = RGBA8F | RGBA16F | RGBA32F,
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
        { Unknown, "unknown" },
        { RGBA8F, "rgba8" },
        { RGBA16F, "rgba16" },
        { RGBA32F, "rgba32" },
        { RGBA, "rgba"},
        { Depth16F, "d16" },
        { Depth24F, "d24" },
        { Depth32F, "d32" },
        { Depth, "depth"}
    })

    struct Attachment {


        bgfx::TextureHandle m_Handle;
        AttachmentType m_Type;

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