#include "Rendering/Attachment.h"
#include "Rendering/GPUResourceManager.h"
#include "Core/Log.hpp"

harmony::AttachmentType harmony::operator|(harmony::AttachmentType a, harmony::AttachmentType b) {
    return static_cast<AttachmentType>(static_cast<int>(a) | static_cast<int>(b));
}

harmony::AttachmentType harmony::operator&(harmony::AttachmentType a, harmony::AttachmentType b) {
    {
        return static_cast<AttachmentType>(static_cast<int>(a) & static_cast<int>(b));
    }
}

harmony::AttachmentType harmony::operator^(harmony::AttachmentType a, harmony::AttachmentType b) {
    {
        return static_cast<AttachmentType>(static_cast<int>(a) ^ static_cast<int>(b));
    }
}

harmony::AttachmentType &harmony::operator|=(harmony::AttachmentType &a, harmony::AttachmentType b) {
    {
        return (AttachmentType &) ((int &) a |= (int) b);
    }
}

harmony::AttachmentType &harmony::operator&=(harmony::AttachmentType &a, harmony::AttachmentType b) {
    {
        return (AttachmentType &) ((int &) a &= (int) b);
    }
}

harmony::AttachmentType &harmony::operator^=(harmony::AttachmentType &a, harmony::AttachmentType b) {
    {
        return (AttachmentType &) ((int &) a ^= (int) b);
    }
}

harmony::AttachmentType harmony::operator~(harmony::AttachmentType a) {
    {
        return static_cast<AttachmentType>(~static_cast<int>(a));
    }
}

uint32_t harmony::GetAttachmentTypePixelSize(harmony::AttachmentType type) {
    uint32_t size = 0;
    switch (type) {
        case AttachmentType::RGBA8:
            size = 4;
            break;
        case AttachmentType::RGBA16F:
            size = 8;
            break;
        case AttachmentType::RGBA32F:
            size = 16;
            break;
        case AttachmentType::Depth16F:
            size = 2;
            break;
        case AttachmentType::Depth24F:
            size = 3;
            break;
        case AttachmentType::Depth32F:
            size = 4;
    }

    return size;
}

bgfx::TextureFormat::Enum harmony::GetBGFXTextureFormat(harmony::AttachmentType type) {
    bgfx::TextureFormat::Enum format = bgfx::TextureFormat::Count;

    switch (type) {
        case AttachmentType::RGBA8:
            format = bgfx::TextureFormat::RGBA8;
            break;
        case AttachmentType::RGBA16F:
            format = bgfx::TextureFormat::RGBA16F;
            break;
        case AttachmentType::RGBA32F:
            format = bgfx::TextureFormat::RGBA32F;
            break;
        case AttachmentType::Depth16F:
            format = bgfx::TextureFormat::D16F;
            break;
        case AttachmentType::Depth24F:
            format = bgfx::TextureFormat::D24F;
            break;
        case AttachmentType::Depth32F:
            format = bgfx::TextureFormat::D32F;
            break;
    }
    return format;

}

uint32_t harmony::Attachment::CalculateAttachmentSize() {
    return GetAttachmentTypePixelSize(m_Type) * m_Resolution.Width * m_Resolution.Height;
}

harmony::Attachment::~Attachment() {
    if (m_Handle.idx == UINT16_MAX) {
        return;
    }
    // TODO: We should limit the texture handle to scope of attachment
    // bgfx::destroy(m_Handle);
}
