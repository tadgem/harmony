#include "Rendering/Texture.h"
#include "bx/readerwriter.h"

harmony::Texture::Texture(const std::string &path, bimg::ImageContainer *imageContainer) : Asset(
        AssetHandle{path, 0, GetTypeHash<Texture>()}), p_ImageContainer(imageContainer) {
    m_SubmittedToGPU = false;
    p_Memory = bgfx::makeRef(
            imageContainer->m_data, imageContainer->m_size, BGFXImageReleaseCallback, imageContainer
    );
}


void harmony::Texture::BGFXImageReleaseCallback(void *_ptr, void *_userData) {
    BX_UNUSED(_ptr);
    bimg::ImageContainer *imageContainer = (bimg::ImageContainer *) _userData;
    bimg::imageFree(imageContainer);
}
