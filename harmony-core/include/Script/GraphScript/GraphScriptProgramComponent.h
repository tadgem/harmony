//
// Created by liam_ on 5/1/2023.
//

#ifndef HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H
#define HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H

#include "Core/Memory.h"
#include "Core/ProgramComponent.h"

namespace harmony {

    namespace GraphScript {
        class NodeRegistry;
    }
    class GraphScriptProgramComponent : public ProgramComponent {
    public:
        GraphScriptProgramComponent();

        ~GraphScriptProgramComponent();

        void Init() override;

        void Update() override;

        void Render() override;

        void Cleanup() override;

        GraphScript::NodeRegistry *GetNodeRegistry();

        nlohmann::json ToJson() override;

        void FromJson(const nlohmann::json &json) override;

    protected:
        UniquePtr<GraphScript::NodeRegistry> p_NodeRegistry;
    };
} // namespace harmony

#endif // HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H
