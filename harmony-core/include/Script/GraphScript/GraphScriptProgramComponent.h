//
// Created by liam_ on 5/1/2023.
//

#ifndef HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H
#define HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H

#include "Core/ProgramComponent.h"
#include "Core/Memory.h"

namespace harmony
{
    class GraphScriptNodeRegistry;

    class GraphScriptProgramComponent : public ProgramComponent
    {
    public:
        GraphScriptProgramComponent();
        ~GraphScriptProgramComponent();

        void Init() override;

        void Update() override;

        void Render() override;

        void Cleanup() override;

        GraphScriptNodeRegistry* GetBuilder();

        nlohmann::json ToJson() override;

        void FromJson(const nlohmann::json &json) override;

    protected:
        Unique<GraphScriptNodeRegistry> p_Builder;

    };
}

#endif //HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H
