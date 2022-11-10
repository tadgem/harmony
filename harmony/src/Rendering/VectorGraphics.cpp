#include "Rendering/VectorGraphics.h"

VectorGraphics::VectorGraphics()
{
    p_VectorRenderers.emplace(Layer::One, std::vector<NVGcontext*>());
    p_VectorRenderers.emplace(Layer::Two, std::vector<NVGcontext*>());
    p_VectorRenderers.emplace(Layer::Three, std::vector<NVGcontext*>());
    p_VectorRenderers.emplace(Layer::Four, std::vector<NVGcontext*>());
    p_VectorRenderers.emplace(Layer::Five, std::vector<NVGcontext*>());
    p_VectorRenderers.emplace(Layer::Six, std::vector<NVGcontext*>());
    p_VectorRenderers.emplace(Layer::Seven, std::vector<NVGcontext*>());
    p_VectorRenderers.emplace(Layer::Eight, std::vector<NVGcontext*>());
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

NVGcontext* VectorGraphics::AddViewLayer(Layer layer, bgfx::ViewId viewId)
{
    NVGcontext* renderer = nvgCreate(s_UseEdgeAA, viewId);
    p_VectorRenderers[layer].emplace_back(renderer);

    return renderer;
}

void VectorGraphics::RemoveViewLayer(Layer layer, NVGcontext* renderer)
{
    int indexToRemove = -1;
    for (int i = 0; i < p_VectorRenderers[layer].size(); i++)
    {
        if (p_VectorRenderers[layer][i] == renderer)
        {
            indexToRemove = i;
        }
    }

    if (indexToRemove >= 0)
    {
        p_VectorRenderers[layer].erase(p_VectorRenderers[layer].begin() + indexToRemove);
        nvgDelete(renderer);
        renderer = nullptr;
    }
}
