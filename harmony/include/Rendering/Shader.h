#pragma once

#include "bgfx/bgfx.h"
#include "Assets/Asset.h"

namespace harmony
{
	class ShaderStage : public Asset
	{
	public:

		enum class Type
		{
			Vertex,
			Fragment, 
			Compute
		};

		ShaderStage(Type shaderType);

		const Type m_Type;
		bgfx::UniformInfo m_UniformInfo;
	};

	class ShaderProgram
	{
	public:

	};
};