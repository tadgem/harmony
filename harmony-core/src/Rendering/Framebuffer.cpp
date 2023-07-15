#include "Rendering/Framebuffer.h"
#include "Core/Log.hpp"
#include "Rendering/GPUResourceManager.h"
#include "Rendering/Renderer.h"

harmony::Attachment harmony::Framebuffer::CreateAttachment(harmony::AttachmentType attachmentType)
{
	bgfx::TextureHandle textureHandle = CreateAttachmentInternal(m_FramebufferResolution, attachmentType);
	Attachment attachment{textureHandle, attachmentType, m_FramebufferResolution};

	m_Attachments.emplace_back(attachment);

	return attachment;
}

harmony::Framebuffer::~Framebuffer()
{
	// harmony::log::info("Framebuffer : Destructor called for framebuffer : {}. Attachments will be destroyed.", m_FBH.idx);
	m_Attachments.clear();
}

bool harmony::Framebuffer::Build()
{
	Vector<bgfx::TextureHandle> textureAttachments;
	for (Attachment &a: m_Attachments)
	{
		textureAttachments.emplace_back(a.m_Handle);
	}
	m_FBH = bgfx::createFrameBuffer(textureAttachments.size(), textureAttachments.data());
	bgfx::setViewMode(m_ViewID, bgfx::ViewMode::Sequential);
	bgfx::setViewFrameBuffer(m_ViewID, m_FBH);
	bgfx::setViewName(m_ViewID, m_Name.c_str());
	bgfx::setViewRect(m_ViewID, 0, 0, m_VirtualResoltuion.Width, m_VirtualResoltuion.Height);
	UpdateVirtualResolution(m_VirtualResoltuion.Width, m_VirtualResoltuion.Height);
	return IsBuilt();
}

bgfx::TextureHandle harmony::Framebuffer::CreateAttachmentInternal(Resolution res, harmony::AttachmentType type)
{
	// TODO: Add support for mips
	const uint16_t NUM_TEXTURE_LAYERS = 1;
	uint64_t ATTACHMENT_FLAGS = BGFX_TEXTURE_RT | BGFX_TEXTURE_BLIT_DST;
	if (type & AttachmentType::Depth)
	{
		ATTACHMENT_FLAGS = BGFX_TEXTURE_RT | BGFX_STATE_DEPTH_TEST_LEQUAL;
	}
	bgfx::TextureFormat::Enum format = harmony::GetBGFXTextureFormat(type);
	return bgfx::createTexture2D(res.Width, res.Height, false, NUM_TEXTURE_LAYERS, format, ATTACHMENT_FLAGS);
}

bool harmony::Framebuffer::IsBuilt()
{
	return m_FBH.idx != UINT16_MAX;
}

void harmony::Framebuffer::UpdateVirtualResolution(uint16_t w, uint16_t h)
{
	Resolution newVirtualResolution = GetScaledResolution(m_ResolutionType, {w, h});

	if (newVirtualResolution.Width > m_FramebufferResolution.Width)
	{
		harmony::log::warn(
				"Framebuffer : ID {} : new virtual width is greater than the framebuffer resolution! : Requested width : {} : Framebuffer Width : {}",
				m_FBH.idx, newVirtualResolution.Width, m_FramebufferResolution.Width);
		newVirtualResolution.Width = m_FramebufferResolution.Width;
	}

	if (newVirtualResolution.Height > m_FramebufferResolution.Height)
	{
		harmony::log::warn(
				"Framebuffer : ID {} : new virtual height is greater than the framebuffer resolution! : Requested height : {} : Framebuffer Height : {}",
				m_FBH.idx, newVirtualResolution.Height, m_FramebufferResolution.Height);
		newVirtualResolution.Height = m_FramebufferResolution.Height;
	}

	m_VirtualResoltuion = newVirtualResolution;

	bgfx::setViewRect(m_ViewID, 0, 0, m_VirtualResoltuion.Width, m_VirtualResoltuion.Height);
	bgfx::setViewScissor(m_ViewID, 0, 0, m_VirtualResoltuion.Width, m_VirtualResoltuion.Height);

}

harmony::Framebuffer::Framebuffer(const String &name, Resolution res, harmony::Resolution::Type resType) : m_Name(
		name)
{
	m_FBH.idx = UINT16_MAX;
	m_ViewID = Renderer::GetViewID();
	m_ResolutionType = resType;

	if (m_ResolutionType == Resolution::Type::Custom)
	{
		m_FramebufferResolution = res;
		return;
	}

	m_FramebufferResolution = GetScaledResolution(resType, {GPUResourceManager::GetMaxFramebufferWidth(),
															GPUResourceManager::GetMaxFramebufferHeight()});
	UpdateVirtualResolution(m_FramebufferResolution.Width, m_FramebufferResolution.Height);
}

harmony::Resolution harmony::Framebuffer::GetScaledResolution(harmony::Resolution::Type type, harmony::Resolution res)
{
	Resolution finalRes{0, 0};

	switch (m_ResolutionType)
	{
		case Resolution::Type::Custom:
		case Resolution::Type::FullScale:
			finalRes.Width = res.Width;
			finalRes.Height = res.Height;
			break;
		case Resolution::Type::HalfScale:
			finalRes.Width = res.Width / 2;
			finalRes.Height = res.Height / 2;
			break;
		case Resolution::Type::QuarterScale:
			finalRes.Width = res.Width / 4;
			finalRes.Height = res.Height / 4;
			break;
		case Resolution::Type::EighthScale:
			finalRes.Width = res.Width / 8;
			finalRes.Height = res.Height / 8;
			break;
		case Resolution::Type::SixteenthScale:
			finalRes.Width = res.Width / 8;
			finalRes.Height = res.Height / 8;
			break;
	}

	return finalRes;
}

void harmony::Framebuffer::Resize(uint16_t w, uint16_t h)
{
	Clear();
	UpdateVirtualResolution(w,h);
}

void harmony::Framebuffer::Clear()
{
	bgfx::setViewRect(m_ViewID, 0,0, m_FramebufferResolution.Width, m_FramebufferResolution.Height);
	bgfx::setViewScissor(m_ViewID, 0, 0, m_FramebufferResolution.Width, m_FramebufferResolution.Height);
	bgfx::setViewClear(m_ViewID, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x00000000, 1.0f);
	bgfx::setViewRect(m_ViewID, 0,0, m_VirtualResoltuion.Width, m_VirtualResoltuion.Height);
	bgfx::setViewScissor(m_ViewID, 0, 0, m_VirtualResoltuion.Width, m_VirtualResoltuion.Height);
}
