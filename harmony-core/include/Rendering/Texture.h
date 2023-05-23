#pragma once

#include "Assets/Asset.h"
#include "bgfx/bgfx.h"
#include <bimg/bimg.h>
#include <bimg/decode.h>

namespace harmony {
    struct BGFXTextureHandle {
        bgfx::TextureHandle BgfxHandle = BGFX_INVALID_HANDLE;
        bgfx::TextureInfo Info;
        AssetHandle Handle;
        uint8_t SamplerSlot;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(BGFXTextureHandle, Handle)
    };

    class Texture : public Asset {
    public:
        Texture(const std::string &path, bimg::ImageContainer *imageContainer);

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