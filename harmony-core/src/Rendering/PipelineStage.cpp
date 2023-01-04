#include "Rendering/PipelineStage.h"

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
