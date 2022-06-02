#pragma once

#include "Assets/Asset.h"
#include "bgfx/bgfx.h"
#include <bimg/bimg.h>
#include <bimg/decode.h>

namespace harmony
{
	struct BGFXTextureHandle
	{
		bgfx::TextureHandle m_Handle;
		bgfx::TextureInfo m_Info;
	};

    class Texture : public Asset
    {
	public:
		Texture(bimg::ImageContainer* imageContainer);

	protected:
		bimg::ImageContainer* p_ImageContainer;
		const bgfx::Memory* p_Memory;

	private:
		friend class TextureAssetFactory;
		friend class Renderer;
		static void BGFXImageReleaseCallback(void* _ptr, void* _userData);
    };
};