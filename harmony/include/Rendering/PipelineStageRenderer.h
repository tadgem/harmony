#pragma once
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/Shader.h"
#include "entt.hpp"


namespace harmony {
	class Drawable;
	class PipelineStageRenderer
	{
	public:
		PipelineStageRenderer();

		// need to think of a way to type constrain this to 
		// the correct derivative of drawable.
		virtual void Draw(entt::registry& scene, Ref<ShaderProgram> shader, bgfx::ViewId viewId) = 0;
	};
};