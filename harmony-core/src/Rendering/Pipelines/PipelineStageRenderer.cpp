#include <optick.h>
#include "Rendering/Pipelines/PipelineStageRenderer.h"

harmony::PipelineStageRenderer::PipelineStageRenderer(const String &name) : m_Name(name) {
    OPTICK_EVENT();
}
