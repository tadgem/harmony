#include <optick.h>
#include "Rendering/Pipelines/PipelineStage.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/View.h"
#include "Core/SerializationKeys.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/GPUResourceManager.h"
harmony::PipelineStage::PipelineStage(const std::string &name, Type pipelineStageType, Vector<AttachmentType> requiredAttachments,
                                      WeakRef<ShaderProgram> shader, WeakRef<PipelineStageRenderer> stageRenderer)
        : m_Name(name), m_StageType(pipelineStageType), m_Attachments(requiredAttachments), p_Shader(shader),
          p_Renderer(stageRenderer) {
    OPTICK_EVENT();
}

harmony::Ref<harmony::Framebuffer>
harmony::PipelineStage::Init(entt::registry &registry, WeakRef<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    if (view.expired()) {
        harmony::log::error("trying to run pipeline init for view that does not exist.");
    }

    Ref<View> _view = view.lock();
    uint16_t fbWidth = GPUResourceManager::GetMaxFramebufferWidth();
    uint16_t fbHeight = GPUResourceManager::GetMaxFramebufferHeight();
    Resolution fBResolution {fbWidth, fbHeight};
    Ref<Framebuffer> fb = CreateRef<Framebuffer>(fBResolution);

    for(AttachmentType& type : m_Attachments)
    {
        if(type & AttachmentType::RGBA16F || type & AttachmentType::RGBA32F)
        {
            m_HasHDRAttachment = true;
        }

        if(type & AttachmentType::Depth)
        {
            m_HasDepthAttachment = true;
        }

        fb->CreateAttachment(type);
    }

    fb->Build();

//
//
//    if (m_HasHDRAttachment) {
//        bgfx::TextureFormat::Enum format = bgfx::TextureFormat::Unknown;
//        AttachmentType type = AttachmentType::UnknownAttachmentType;
//        if (m_Attachments && AttachmentType::RGBA16F) {
//            format = bgfx::TextureFormat::RGBA16F;
//            type = AttachmentType::RGBA16F;
//        } else if (m_Attachments && AttachmentType::RGBA32F) {
//            format = bgfx::TextureFormat::RGBA32F;
//            type = AttachmentType::RGBA32F;
//        } else {
//            harmony::log::warn("PipelineStage : {} : Invalid attachment format specified, defaulting to RGBA16F",
//                               m_Name);
//            format = bgfx::TextureFormat::RGBA16F;
//            type = AttachmentType::RGBA16F;
//        }
//        bgfx::TextureHandle textureHandle = bgfx::createTexture2D(
//                _view->m_Width, _view->m_Height, false, 1, format, BGFX_TEXTURE_RT | BGFX_TEXTURE_MSAA_SAMPLE
//        );
//
//        Attachment a{
//                textureHandle,
//                type
//        };
//
//        attachments.emplace(type, a);
//        attachmentTextureHandles.emplace_back(textureHandle);
//    } else {
//        AttachmentType type = AttachmentType::RGBA8;
//        bgfx::TextureHandle textureHandle = bgfx::createTexture2D(
//                _view->m_Width, _view->m_Height, false, 1, bgfx::TextureFormat::BGRA8,
//                BGFX_TEXTURE_RT | BGFX_TEXTURE_MSAA_SAMPLE
//        );
//
//        Attachment a{
//                textureHandle,
//                type
//        };
//        attachments.emplace(type, a);
//        attachmentTextureHandles.emplace_back(textureHandle);
//    }
//
//    if (m_HasDepthAttachment) {
//        bgfx::TextureFormat::Enum format = bgfx::TextureFormat::Unknown;
//        AttachmentType type = AttachmentType::UnknownAttachmentType;
//        if (m_Attachments && AttachmentType::Depth32F) {
//            format = bgfx::TextureFormat::D32F;
//            type = AttachmentType::Depth32F;
//        } else if (m_Attachments && AttachmentType::Depth24F) {
//            format = bgfx::TextureFormat::D24F;
//            type = AttachmentType::Depth24F;
//        } else if (m_Attachments && AttachmentType::Depth16F) {
//            format = bgfx::TextureFormat::D16F;
//            type = AttachmentType::Depth16F;
//        } else {
//            harmony::log::warn("PipelineStage : {} : Invalid depth attachment format specified, defaulting to D16F",
//                               m_Name);
//            format = bgfx::TextureFormat::D16F;
//            type = AttachmentType::Depth16F;
//        }
//        bgfx::TextureHandle textureHandle = bgfx::createTexture2D(
//                _view->m_Width, _view->m_Height, false, 1, format,
//                BGFX_TEXTURE_RT | BGFX_STATE_DEPTH_TEST_LEQUAL | BGFX_TEXTURE_BLIT_DST
//        );
//
//        Attachment a{
//                textureHandle,
//                type
//        };
//
//        attachments.emplace(type, a);
//        attachmentTextureHandles.emplace_back(textureHandle);
//    }
//
//    bgfx::FrameBufferHandle fbh = bgfx::createFrameBuffer(attachmentTextureHandles.size(),
//                                                          attachmentTextureHandles.data(), false);
//    // this needs to be moved to the Viewport or PipelineStack
//    bgfx::setViewFrameBuffer(viewId, fbh);
//    bgfx::setViewRect(viewId, 0, 0, bgfx::BackbufferRatio::Equal);
//    bgfx::setViewName(viewId, m_Name.c_str());
//
//    Data data
//            {
//                    fbh,
//                    attachments
//            };

    return fb;
}

void harmony::PipelineStage::Cleanup(WeakRef<View> view, bgfx::ViewId viewId) {
    OPTICK_EVENT();
}

void harmony::PipelineStage::AddShaderDataSource(WeakRef<ShaderDataSource> source) {
    OPTICK_EVENT();
    if (source.expired()) return;
    for (int i = 0; i < p_DataSources.size(); i++) {
        if (p_DataSources[i].expired()) {
            continue;
        }
        if (p_DataSources[i].lock() == source.lock()) {
            harmony::log::warn("PipelineStage : Stage {} already has data source : {}", m_Name, source.lock()->m_Name);
            return;
        }
    }
    p_DataSources.emplace_back(source);
}

nlohmann::json harmony::PipelineStage::Serialize() {
    OPTICK_EVENT();
    nlohmann::json j;
    j[sk_PipelineStageName] = m_Name;
    j[sk_PipelineStageAttachments] = m_Attachments;
    j[sk_PipelineStageType] = m_StageType;
    j[sk_PipelineStageShader] = *p_Shader.lock();

    if (p_Renderer.expired()) {
        j[sk_PipelineStageRenderer] = nlohmann::json();
    } else {
        j[sk_PipelineStageRenderer] = *p_Renderer.lock();
    }
    return j;
}

void harmony::PipelineStage::Deserialize(nlohmann::json j) {
    OPTICK_EVENT();
    m_Name = j[sk_PipelineStageName];
    // m_Attachments = j[sk_PipelineStageAttachments];
    m_StageType = j[sk_PipelineStageType];
}