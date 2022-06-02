#include "Rendering/Texture.h"
#include "bx/readerwriter.h"

harmony::Texture::Texture(bimg::ImageContainer* imageContainer) : Asset(GetTypeHash<Texture>()), p_ImageContainer(imageContainer)
{
    p_Memory = bgfx::makeRef(
        imageContainer->m_data
        , imageContainer->m_size
        , BGFXImageReleaseCallback
        , imageContainer
    );
}


void harmony::Texture::BGFXImageReleaseCallback(void* _ptr, void* _userData)
{
    BX_UNUSED(_ptr);
    bimg::ImageContainer* imageContainer = (bimg::ImageContainer*)_userData;
    bimg::imageFree(imageContainer);
}
