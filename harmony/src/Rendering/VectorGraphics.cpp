#include "Rendering/VectorGraphics.h"

VectorGraphics::VectorGraphics()
{
}

VectorGraphics* VectorGraphics::Get()
{
    if (p_Instance)
    {
        return p_Instance;
    }
    p_Instance = new VectorGraphics();
    return p_Instance;
}

void VectorGraphics::SetInstanceContext(NVGcontext* context)
{
    if (p_Instance)
    {
        if (p_Instance->s_VectorGraphicsContext)
        {
            return;
        }
        p_Instance->s_VectorGraphicsContext = context;
    }

}

NVGcontext* VectorGraphics::GetNVGContext()
{
    if (p_Instance)
    {
        if (p_Instance->s_VectorGraphicsContext)
        {
            return p_Instance->s_VectorGraphicsContext;
        }
    }
    return nullptr;
}
