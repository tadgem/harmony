#include "Rendering/PipelineStage.h"

harmony::PipelineStage::PipelineStage(bgfx::ViewId viewId, Type stageType, WeakRef<ShaderProgram> shader) : m_ViewId(viewId), m_StageType(stageType), p_Shader(shader)
{
}