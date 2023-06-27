//
// Created by Admin on 5/27/2023.
//

#ifndef HARMONY_CORE_TEXTURE_H
#define HARMONY_CORE_TEXTURE_H

#include "Rendering/TypeDef.h"

namespace harmony
{

	struct Attachment
	{
		~Attachment();
		bgfx::TextureHandle m_Handle{UINT16_MAX};
		AttachmentType m_Type;
		Resolution m_Resolution;
		uint32_t CalculateAttachmentSize();

		bool operator==(const Attachment &rhs) const
		{
			return m_Handle.idx == rhs.m_Handle.idx && m_Type == rhs.m_Type;
		}

		bool operator!=(const Attachment &rhs) const
		{
			return !(rhs == *this);
		}
	};
} // namespace harmony
#endif