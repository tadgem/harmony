#pragma once

#include <string>
#include "bgfx/bgfx.h"
#include "Core/Memory.h"
#include "Rendering/Shader.h"
#include "ThirdParty/entt.hpp"
#include "ThirdParty/json.hpp"

namespace harmony {
    class Drawable;

    class PipelineStageRenderer {
    public:
        PipelineStageRenderer(const std::string &name);

        // need to think of a way to type constrain this to
        // the correct derivative of drawable.
        virtual void Draw(entt::registry &scene, Ref<ShaderProgram> shader, bgfx::ViewId viewId) {}

        std::string m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineStageRenderer, m_Name);
    };
};