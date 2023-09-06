#pragma once

#include "ECS/Entity.h"
#include "Rendering/View.h"

namespace harmony {
    class Program;

    class Renderer;

    class RuntimeView : public View {
    public:
        RuntimeView(Program &prog);

        virtual void OnPreUpdate(entt::registry &registry) override;

        virtual void OnResized(uint32_t w, uint32_t h);

#if HARMONY_DEBUG

        virtual void OnImGui() override;

        virtual void OnImGuiOptions() override;

#endif

        virtual nlohmann::json Serialize() override;

        virtual void Deserialize(nlohmann::json &json) override;

        entt::entity CameraEntity;

    protected:
        Program &p_Program;
        Renderer &p_Renderer;
    };
} // namespace harmony