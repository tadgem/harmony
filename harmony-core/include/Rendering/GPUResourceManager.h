//
// Created by Admin on 5/27/2023.
//

#ifndef HARMONY_DOJO_GPURESOURCEMANAGER_H
#define HARMONY_DOJO_GPURESOURCEMANAGER_H

#include "Core/Memory.h"
#include "Rendering/TypeDef.h"
#include <cstdint>

namespace harmony {
    class Framebuffer;

    struct Attachment;

    class GPUResourceManager {
    public:
        static uint16_t GetMaxFramebufferWidth();

        static uint16_t GetMaxFramebufferHeight();

        static uint16_t GetNumActiveFramebuffers();

        static uint16_t GetNumActiveAttachments();

        static Ref<Framebuffer> CreateFramebuffer(const std::string &name,
                                                  Resolution resolution,
                                                  Resolution::Type resolutionType);

        static Ref<Attachment> CreateAttachment(Resolution resolution,
                                                AttachmentType type);

    protected:
        static uint16_t MAX_FRAMEBUFFER_RESOLUTION_X;
        static uint16_t MAX_FRAMEBUFFER_RESOLUTION_Y;

        friend class Program;
    };
} // namespace harmony

#endif // HARMONY_DOJO_GPURESOURCEMANAGER_H
