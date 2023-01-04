#include "Rendering/PipelineStage.h"
#include "Rendering/View.h"

harmony::PipelineStage::PipelineStage(const std::string& name, Type pipelineStageType, Attachment::Type attachments) : m_Name(name), m_StageType(pipelineStageType), m_Attachments(attachments)
{
}

harmony::PipelineStage::Data harmony::PipelineStage::Init(entt::registry& registry, WeakRef<View> view, bgfx::ViewId viewId)
{
	if (view.expired())
	{
		harmony::log::error("trying to run pipeline init for view that does not exist.");
	}

	Ref<View> _view = view.lock();
	std::map<Attachment::Type, Attachment> attachments = std::map<Attachment::Type, Attachment>();
	std::vector<bgfx::TextureHandle> attachmentTextureHandles = std::vector<bgfx::TextureHandle>();

	if (m_Attachments && Attachment::Type::RGBA16F ||
		m_Attachments && Attachment::Type::RGBA32F)
	{
		m_HasHDRAttachment = true;
	}

	if (m_Attachments && Attachment::Type::Depth16F ||
		m_Attachments && Attachment::Type::Depth24F ||
		m_Attachments && Attachment::Type::Depth32F)
	{
		m_HasDepthAttachment = true;
	}


	if (m_HasHDRAttachment)
	{
		bgfx::TextureFormat::Enum format = bgfx::TextureFormat::Unknown;
		Attachment::Type type = Attachment::Type::Unknown;
		if (m_Attachments & Attachment::Type::RGBA16F)
		{
			format = bgfx::TextureFormat::RGBA16F;
			type = Attachment::Type::RGBA16F;
		}
		else if (m_Attachments & Attachment::Type::RGBA32F)
		{
			format = bgfx::TextureFormat::RGBA32F;
			type = Attachment::Type::RGBA32F;
		}
		else
		{
			harmony::log::error("Invalid attachment format specified, defaulting to RGBA16F");
			format = bgfx::TextureFormat::RGBA16F;
			type = Attachment::Type::RGBA16F;
		}
		bgfx::TextureHandle textureHandle = bgfx::createTexture2D(
			_view->m_Width
			, _view->m_Height
			, false
			, 1
			, format
			, BGFX_TEXTURE_RT
		);

		Attachment a{
			textureHandle,
			type
		};

		attachments.emplace(type, a);
		attachmentTextureHandles.emplace_back(textureHandle);
	}
	else
	{
		Attachment::Type type = Attachment::Type::RGBA8F;
		bgfx::TextureHandle textureHandle = bgfx::createTexture2D(
			_view->m_Width
			, _view->m_Height
			, false
			, 1
			, bgfx::TextureFormat::BGRA8
			, BGFX_TEXTURE_RT
		);

		Attachment a{
			textureHandle,
			type
		};
		attachments.emplace(type, a);
		attachmentTextureHandles.emplace_back(textureHandle);
	}

	if (m_HasDepthAttachment)
	{
		bgfx::TextureFormat::Enum format = bgfx::TextureFormat::Unknown;
		Attachment::Type type = Attachment::Type::Unknown;
		if (m_Attachments & Attachment::Type::Depth32F)
		{
			format = bgfx::TextureFormat::D32F;
			type = Attachment::Type::Depth32F;
		}
		else if (m_Attachments & Attachment::Type::Depth24F)
		{
			format = bgfx::TextureFormat::D24F;
			type = Attachment::Type::Depth24F;
		}
		else if (m_Attachments & Attachment::Type::Depth16F)
		{
			format = bgfx::TextureFormat::D16F;
			type = Attachment::Type::Depth16F;
		}
		else
		{
			harmony::log::error("Invalid depth attachment format specified, defaulting to D16F");
			format = bgfx::TextureFormat::D16F;
			type = Attachment::Type::Depth16F;
		}
		bgfx::TextureHandle textureHandle = bgfx::createTexture2D(
			_view->m_Width
			, _view->m_Height
			, false
			, 1
			, format
			, BGFX_TEXTURE_RT | BGFX_STATE_DEPTH_TEST_LESS | BGFX_TEXTURE_BLIT_DST
		);

		Attachment a{
			textureHandle,
			type
		};

		attachments.emplace(type, a);
		attachmentTextureHandles.emplace_back(textureHandle);
	}

	bgfx::FrameBufferHandle fbh = bgfx::createFrameBuffer(attachmentTextureHandles.size(), attachmentTextureHandles.data(), false);
	// this needs to be moved to the Viewport or PipelineStack
	bgfx::setViewFrameBuffer(viewId, fbh);
	bgfx::setViewRect(viewId, 0, 0, bgfx::BackbufferRatio::Equal);
	bgfx::setViewName(viewId, m_Name.c_str());

	Data data
	{
		fbh,
		attachments
	};

	return data;
}

void harmony::PipelineStage::Cleanup(WeakRef<View> view, bgfx::ViewId viewId)
{
}
harmony::Attachment::Type harmony::PipelineStage::Data::GetDepthType()
{
	if (m_Attachments.find(Attachment::Type::Depth16F) != m_Attachments.end())
	{
		return Attachment::Type::Depth16F;
	}
	if (m_Attachments.find(Attachment::Type::Depth24F) != m_Attachments.end())
	{
		return Attachment::Type::Depth24F;
	}
	if (m_Attachments.find(Attachment::Type::Depth32F) != m_Attachments.end())
	{
		return Attachment::Type::Depth32F;
	}

	return Attachment::Type::Unknown;
}
