#pragma once

#include "ThirdParty/json.hpp"
#include "bgfx/bgfx.h"

namespace harmony {
    struct Attachment {
        enum Type {
            Unknown = 1,
            RGBA8F = 2,
            RGBA16F = 4,
            RGBA32F = 8,
            Depth16F = 16,
            Depth24F = 32,
            Depth32F = 64,

        };

        friend Type operator|(Type a, Type b) {
            return static_cast<Type>(static_cast<int>(a) | static_cast<int>(b));
        }

        friend Type operator&(Type a, Type b) {
            return static_cast<Type>(static_cast<int>(a) & static_cast<int>(b));
        }

        friend Type operator^(Type a, Type b) {
            return static_cast<Type>(static_cast<int>(a) ^ static_cast<int>(b));
        }

        friend Type &operator|=(Type &a, Type b) {
            return (Type &) ((int &) a |= (int) b);
        }

        friend Type &operator&=(Type &a, Type b) {
            return (Type &) ((int &) a &= (int) b);
        }

        friend Type &operator^=(Type &a, Type b) {
            return (Type &) ((int &) a ^= (int) b);
        }

        friend Type operator~(Type a) {
            return static_cast<Type>(~static_cast<int>(a));
        }


        NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
            { Unknown, "unknown" },
            { RGBA8F, "rgba8" },
            { RGBA16F, "rgba16" },
            { RGBA32F, "rgba32" },
            { Depth16F, "d16" },
            { Depth24F, "d24" },
            { Depth32F, "d32" }
        })

        bgfx::TextureHandle m_Handle;
        Type m_Type;
    };
}