#include "Rendering/GPUResourceManager.h"
#include "Rendering/Framebuffer.h"

uint16_t harmony::GPUResourceManager::MAX_FRAMEBUFFER_RESOLUTION_X = UINT16_MAX;
uint16_t harmony::GPUResourceManager::MAX_FRAMEBUFFER_RESOLUTION_Y = UINT16_MAX;

uint16_t harmony::GPUResourceManager::GetMaxFramebufferWidth() {
    return MAX_FRAMEBUFFER_RESOLUTION_X;
}

uint16_t harmony::GPUResourceManager::GetMaxFramebufferHeight() {
    return MAX_FRAMEBUFFER_RESOLUTION_Y;
}

harmony::Ref<harmony::Framebuffer>
harmony::GPUResourceManager::CreateFramebuffer(const std::string &name, harmony::Resolution resolution,
                                               harmony::Resolution::Type resolutionType) {
    return CreateRef<harmony::Framebuffer>(name, resolution, resolutionType);
}

harmony::Ref<harmony::Attachment>
harmony::GPUResourceManager::CreateAttachment(harmony::Resolution resolution, harmony::AttachmentType type) {
    return harmony::Ref<harmony::Attachment>();
}

uint16_t harmony::GPUResourceManager::GetNumActiveFramebuffers() {
    return 0;
}

uint16_t harmony::GPUResourceManager::GetNumActiveAttachments() {
    return 0;
}
