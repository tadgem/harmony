#pragma once

#include "Core/Memory.h"
#include "Rendering/Shaders/Shader.h"
#include "ThirdParty/entt.hpp"
#include "STL/Json.hpp"
#include "bgfx/bgfx.h"

namespace harmony {
    class View;

    class PipelineStageRenderer {
    public:
        PipelineStageRenderer(const String &name);

        // need to think of a way to type constrain this to
        // the correct derivative of drawable.
        virtual void Draw(entt::registry &scene, RefCntPtr<ShaderProgram> shader, RefCntPtr<View> view,
                          bgfx::ViewId viewId) {
        }

        String m_Name;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineStageRenderer, m_Name);
    };
}; // namespace harmony