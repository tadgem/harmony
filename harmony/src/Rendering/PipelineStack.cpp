#include "Rendering/PipelineStack.h"

harmony::PipelineStack::PipelineStack(WeakRef<View> view) : p_View(view.lock())
{
}
