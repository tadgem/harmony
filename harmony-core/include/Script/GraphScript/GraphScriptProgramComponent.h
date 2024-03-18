//
// Created by liam_ on 5/1/2023.
//

#ifndef HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H
#define HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H

#include "Core/Memory.h"
#include "Core/ProgramComponent.h"

namespace harmony {

    class GraphScriptProgramComponent : public ProgramComponent {
    public:
        GraphScriptProgramComponent();

        ~GraphScriptProgramComponent();

        void Init() override;

        void Update() override;

        void Render() override;

        void Cleanup() override;

        Json ToJson() override;

        void FromJson(const Json &json) override;

    };
} // namespace harmony

#endif // HARMONY_DOJO_GRAPHSCRIPTPROGRAMCOMPONENT_H
