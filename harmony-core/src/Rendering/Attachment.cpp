#include "Rendering/Attachment.h"
#include "Rendering/GPUResourceManager.h"

harmony::AttachmentType harmony::operator|(harmony::AttachmentType a, harmony::AttachmentType b) {
    return static_cast<AttachmentType>(static_cast<int>(a) | static_cast<int>(b));
}

harmony::AttachmentType harmony::operator&(harmony::AttachmentType a, harmony::AttachmentType b) {
    {
        return static_cast<AttachmentType>(static_cast<int>(a) & static_cast<int>(b));
    }
}

harmony::AttachmentType harmony::operator^(harmony::AttachmentType a, harmony::AttachmentType b) {
    {
        return static_cast<AttachmentType>(static_cast<int>(a) ^ static_cast<int>(b));
    }
}

harmony::AttachmentType &harmony::operator|=(harmony::AttachmentType &a, harmony::AttachmentType b) {
    {
        return (AttachmentType &) ((int &) a |= (int) b);
    }
}

harmony::AttachmentType &harmony::operator&=(harmony::AttachmentType &a, harmony::AttachmentType b) {
    {
        return (AttachmentType &) ((int &) a &= (int) b);
    }
}

harmony::AttachmentType &harmony::operator^=(harmony::AttachmentType &a, harmony::AttachmentType b) {
    {
        return (AttachmentType &) ((int &) a ^= (int) b);
    }
}

harmony::AttachmentType harmony::operator~(harmony::AttachmentType a) {
    {
        return static_cast<AttachmentType>(~static_cast<int>(a));
    }
}
