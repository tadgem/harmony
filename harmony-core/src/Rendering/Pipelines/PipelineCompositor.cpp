//
// Created by liam_ on 5/24/2023.
//

#include "Rendering/Pipelines/PipelineCompositor.h"

#include <optick.h>
#include "Core/Log.hpp"
#include "Core/SerializationKeys.h"
#include "Rendering/Pipelines/PipelineStack.h"
#include "Rendering/Shapes.h"
#include "Rendering/Renderer.h"
#include "Rendering/View.h"
#include "Rendering/Pipelines/PostProcessStage.h"

void harmony::PipelineCompositor::Render(entt::registry &registry, harmony::WeakRef<harmony::View> view)
{
    OPTICK_EVENT();

}

void harmony::PipelineCompositor::Composite(entt::registry &registry, WeakRef<View> view)
{
    OPTICK_EVENT();
}
