#include "Rendering/GPUResourceManager.h"

uint16_t harmony::GPUResourceManager::MAX_FRAMEBUFFER_RESOLUTION_X = UINT16_MAX;
uint16_t harmony::GPUResourceManager::MAX_FRAMEBUFFER_RESOLUTION_Y = UINT16_MAX;

uint16_t harmony::GPUResourceManager::GetMaxFramebufferWidth() {
    return MAX_FRAMEBUFFER_RESOLUTION_X;
}

uint16_t harmony::GPUResourceManager::GetMaxFramebufferHeight() {
    return MAX_FRAMEBUFFER_RESOLUTION_Y;
}
