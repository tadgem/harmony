#include <optick.h>
#include "Assets/TextureAsset.h"
#include "bx/readerwriter.h"

harmony::TextureAsset::TextureAsset(const std::string &path, bimg::ImageContainer *imageContainer) : Asset(
        AssetHandle{path, 0, GET_TYPE_HASH(TextureAsset)}), p_ImageContainer(imageContainer) {
    OPTICK_EVENT();
    m_SubmittedToGPU = false;
    p_Memory = bgfx::makeRef(
            imageContainer->m_data, imageContainer->m_size, BGFXImageReleaseCallback, imageContainer
    );
}

void harmony::TextureAsset::BGFXImageReleaseCallback(void *_ptr, void *_userData) {
    OPTICK_EVENT();
    BX_UNUSED(_ptr);
    bimg::ImageContainer *imageContainer = (bimg::ImageContainer *) _userData;
    bimg::imageFree(imageContainer);
}
