#include <optick.h>
#include "Rendering/Pipelines/PipelineStageRenderer.h"

harmony::PipelineStageRenderer::PipelineStageRenderer(const std::string &name) : m_Name(name) {
    OPTICK_EVENT();
}
