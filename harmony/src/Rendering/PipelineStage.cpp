#include "Rendering/PipelineStage.h"
#include "Rendering/ViewManager.h"

harmony::PipelineStage::PipelineStage(Type stageType, WeakRef<ShaderProgram> shader) : m_ViewId(ViewManager::GetViewID()), m_StageType(stageType), p_Shader(shader)
{
}