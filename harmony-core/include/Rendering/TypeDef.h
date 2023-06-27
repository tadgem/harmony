//
// Created by liam_ on 6/4/2023.
//

#ifndef HARMONY_DOJO_TYPEDEF_H
#define HARMONY_DOJO_TYPEDEF_H

#include "ThirdParty/json.hpp"
#include "bgfx/bgfx.h"

namespace harmony
{
	struct Resolution
	{
		uint16_t Width = 0, Height = 0;
		enum Type
		{
			FullScale,
			HalfScale,
			QuarterScale,
			EighthScale,
			SixteenthScale,
			Custom
		};

		NLOHMANN_JSON_SERIALIZE_ENUM(Type, {
			{ FullScale, "full" },
			{ HalfScale, "half" },
			{ QuarterScale, "quarter" },
			{ EighthScale, "eighth" },
			{ SixteenthScale, "sixteenth" },
			{ Custom, "custom" },

		})

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Resolution, Width, Height)
	};
	enum AttachmentType : int
	{
		UnknownAttachmentType = 1,
		RGBA8 = 2,
		RGBA16F = 4,
		RGBA32F = 8,
		RGBA = RGBA8 | RGBA16F | RGBA32F,
		Depth16F = 16,
		Depth24F = 32,
		Depth32F = 64,
		Depth = Depth16F | Depth24F | Depth32F

	};
	AttachmentType operator|(AttachmentType a, AttachmentType b);
	AttachmentType operator&(AttachmentType a, AttachmentType b);
	AttachmentType operator^(AttachmentType a, AttachmentType b);
	AttachmentType &operator|=(AttachmentType &a, AttachmentType b);
	AttachmentType &operator&=(AttachmentType &a, AttachmentType b);
	AttachmentType &operator^=(AttachmentType &a, AttachmentType b);
	AttachmentType operator~(AttachmentType a);

	NLOHMANN_JSON_SERIALIZE_ENUM(AttachmentType,
								 {
									 { UnknownAttachmentType, "unknown" },
									 { RGBA8, "rgba8" },
									 { RGBA16F, "rgba16" },
									 { RGBA32F, "rgba32" },
									 { RGBA, "rgba" },
									 { Depth16F, "d16" },
									 { Depth24F, "d24" },
									 { Depth32F, "d32" },
									 { Depth, "depth" }
								 })

	uint32_t GetAttachmentTypePixelSize(AttachmentType type);
	bgfx::TextureFormat::Enum GetBGFXTextureFormat(AttachmentType type);
} // namespace harmony

#endif // HARMONY_DOJO_TYPEDEF_H
