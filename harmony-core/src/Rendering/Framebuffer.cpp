#include "Rendering/Framebuffer.h"
#include "Rendering/Attachment.h"
#include "Core/Log.hpp"
harmony::Attachment harmony::Framebuffer::AddAttachment(harmony::AttachmentType attachmentType)
{
    return harmony::Attachment();
}

harmony::Framebuffer::Framebuffer()
{
    p_Initialized = false;
}

harmony::Framebuffer::~Framebuffer()
{
    harmony::log::info("Framebuffer : Destructor called for framebuffer : {}. Attachments will be destroyed.", m_FBH.idx);
    p_Attachments.clear();
}
