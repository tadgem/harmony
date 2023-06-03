#include "Rendering/Framebuffer.h"
#include "Core/Log.hpp"
#include "Rendering/GPUResourceManager.h"
#include "Rendering/Renderer.h"
harmony::Attachment harmony::Framebuffer::CreateAttachment(harmony::AttachmentType attachmentType)
{
    bgfx::TextureHandle textureHandle = CreateAttachmentInternal(m_FramebufferResolution, attachmentType);
    Attachment attachment {textureHandle, attachmentType, m_FramebufferResolution};

    m_Attachments.emplace_back(attachment);

    return attachment;
}

harmony::Framebuffer::~Framebuffer()
{
    harmony::log::info("Framebuffer : Destructor called for framebuffer : {}. Attachments will be destroyed.", m_FBH.idx);
    m_Attachments.clear();
}

bool harmony::Framebuffer::Build() {
    Vector<bgfx::TextureHandle> textureAttachments;
    for(Attachment& a : m_Attachments)
    {
        textureAttachments.emplace_back(a.m_Handle);
    }
    m_FBH = bgfx::createFrameBuffer(textureAttachments.size(), textureAttachments.data());
    return IsBuilt();
}

bgfx::TextureHandle harmony::Framebuffer::CreateAttachmentInternal(Resolution res, harmony::AttachmentType type)
{
    // TODO: Add support for mips
    const uint16_t NUM_TEXTURE_LAYERS = 1;
    const uint64_t ATTACHMENT_FLAGS  = BGFX_TEXTURE_RT | BGFX_TEXTURE_BLIT_DST;
    bgfx::TextureFormat::Enum format = harmony::GetBGFXTextureFormat(type);
    return bgfx::createTexture2D(res.Width,res.Height,false, NUM_TEXTURE_LAYERS, format, ATTACHMENT_FLAGS);
}

bool harmony::Framebuffer::IsBuilt() {
    return m_FBH.idx != UINT16_MAX;
}

void harmony::Framebuffer::UpdateVirtualResolution(uint16_t w, uint16_t h)
{
    Resolution newVirtualResolution = GetScaledResolution(m_ResolutionType, {w,h});

    if(newVirtualResolution.Width > m_FramebufferResolution.Width)
    {
        harmony::log::warn("Framebuffer : ID {} : new virtual width is greater than the framebuffer resolution! : Requested width : {} : Framebuffer Width : {}", m_FBH.idx, newVirtualResolution.Width, m_FramebufferResolution.Width);
        newVirtualResolution.Width = m_FramebufferResolution.Width;
    }

    if(newVirtualResolution.Height > m_FramebufferResolution.Height)
    {
        harmony::log::warn("Framebuffer : ID {} : new virtual height is greater than the framebuffer resolution! : Requested height : {} : Framebuffer Height : {}", m_FBH.idx, newVirtualResolution.Height, m_FramebufferResolution.Height);
        newVirtualResolution.Height = m_FramebufferResolution.Height;
    }

    m_VirtualResoltuion = newVirtualResolution;

    bgfx::setViewRect(m_ViewID, 0, 0, m_VirtualResoltuion.Width, m_VirtualResoltuion.Height);
    bgfx::setViewScissor(m_ViewID, 0, 0, m_VirtualResoltuion.Width, m_VirtualResoltuion.Height);

}

harmony::Framebuffer::Framebuffer(Resolution res, harmony::Framebuffer::ResolutionType resType)
{
    m_FBH.idx = UINT16_MAX;
    m_ViewID = Renderer::GetViewID();
    m_ResolutionType = resType;

    if(m_ResolutionType == ResolutionType::Custom)
    {
        m_FramebufferResolution = res;
        return;
    }

    m_FramebufferResolution = GetScaledResolution(resType, {GPUResourceManager::GetMaxFramebufferWidth(), GPUResourceManager::GetMaxFramebufferHeight()});
    m_VirtualResoltuion = m_FramebufferResolution;
}

harmony::Resolution harmony::Framebuffer::GetScaledResolution(harmony::Framebuffer::ResolutionType type, harmony::Resolution res) {
    Resolution finalRes {0,0};

    switch(m_ResolutionType)
    {
        case ResolutionType::Custom:
        case ResolutionType::FullScale:
            finalRes.Width = res.Width;
            finalRes.Height = res.Height;
            break;
        case ResolutionType::HalfScale:
            finalRes.Width =  res.Width / 2;
            finalRes.Height = res.Height / 2;
            break;
        case ResolutionType::QuarterScale:
            finalRes.Width = res.Width / 4;
            finalRes.Height = res.Height / 4;
            break;
        case ResolutionType::EighthScale:
            finalRes.Width = res.Width / 8;
            finalRes.Height = res.Height / 8;
            break;
        case ResolutionType::SixteenthScale:
            finalRes.Width = res.Width / 8;
            finalRes.Height = res.Height / 8;
            break;
    }

    return finalRes;
}
