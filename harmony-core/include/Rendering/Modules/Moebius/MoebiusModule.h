#ifndef HARMONY_RENDERING_MODULES_MOEBIUS_H
#define HARMONY_RENDERING_MODULES_MOEBIUS_H

#include "Core/Memory.h"
#include "Rendering/Renderer.h"

namespace harmony {
    class PipelineV2;

    class Framebuffer;

    class Moebius {
    public:
        static WeakRef<Framebuffer>
        AddMoebiusToPipeline(Renderer &renderer, Ref<PipelineV2> pipeline, Ref<TextureAsset> crossHatchTexture);

    };
}
#endif