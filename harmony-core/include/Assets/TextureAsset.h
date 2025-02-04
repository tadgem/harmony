#pragma once

#include "Assets/Asset.h"
#include "bgfx/bgfx.h"
#include <bimg/bimg.h>
#include <bimg/decode.h>

namespace harmony {
    struct BGFXTextureHandle {
        bgfx::TextureHandle BgfxHandle = BGFX_INVALID_HANDLE;
        bgfx::TextureInfo Info = {};
        AssetHandle Handle = {};
        uint8_t SamplerSlot = 0;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(BGFXTextureHandle, Handle)
    };

    // TODO: Move to assets, need a pure rendering texture class.
    class TextureAsset : public Asset {
    public:
        TextureAsset(const String &path, bimg::ImageContainer *imageContainer);

        BGFXTextureHandle m_TextureHandle;
        bool m_SubmittedToGPU;

    protected:
        bimg::ImageContainer *p_ImageContainer;
        const bgfx::Memory *p_Memory;

    private:
        friend class TextureAssetFactory;

        friend class Renderer;

        static void BGFXImageReleaseCallback(void *_ptr, void *_userData);
    };
};