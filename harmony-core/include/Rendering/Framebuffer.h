#pragma once

#include "Core/Alias.h"
#include "bgfx/bgfx.h"

namespace harmony {
    struct Attachment;
    enum AttachmentType : int;

    class Framebuffer {
    public:
        Framebuffer();

        Attachment AddAttachment(AttachmentType attachmentType);

    protected:
        Vector<Attachment> p_Attachments;
    };
};