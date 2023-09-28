#ifndef HARMONY_RENDERING_MODULES_MOEBIUS_H
#define HARMONY_RENDERING_MODULES_MOEBIUS_H

#include "Core/Memory.h"
#include "Rendering/Renderer.h"

namespace harmony {
    class PipelineV2;

    class Framebuffer;

    class Moebius {
    public:
        static WeakPtr<Framebuffer>
        AddMoebiusToPipeline(Renderer &renderer, RefCntPtr<PipelineV2> pipeline, RefCntPtr<TextureAsset> crossHatchTexture);

    };
}
#endif