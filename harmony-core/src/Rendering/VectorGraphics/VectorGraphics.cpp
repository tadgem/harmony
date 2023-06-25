#include <optick.h>
#include "Rendering/VectorGraphics/VectorGraphics.h"
#include "Core/Log.hpp"

//void harmony::VectorGraphics::Text(Layer layer, float x, float y, const char *str) {
//    OPTICK_EVENT();
//    for (NVGcontext *context: p_VectorRenderers[layer]) {
//        nvgText(context, x, y, str, NULL);
//    }
//}

#define ARG_PACK(...) __VA_ARGS__

#define HARMONY_VG_IMPL(funcName, nanoVgName, nanoVgFuncImpl, ...) void harmony::VectorGraphics::funcName(Layer layer, __VA_ARGS__) \
{\
OPTICK_EVENT();\
for (NVGcontext *context: p_VectorRenderers[layer]) {\
nanoVgName(context, nanoVgFuncImpl);}}\


harmony::VectorGraphics::VectorGraphics() {
    OPTICK_EVENT();
    p_VectorRenderers.emplace(Layer::One, std::vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Two, std::vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Three, std::vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Four, std::vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Five, std::vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Six, std::vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Seven, std::vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Eight, std::vector<NVGcontext *>());
}

harmony::VectorGraphics *harmony::VectorGraphics::Get() {
    OPTICK_EVENT();
    if (p_Instance) {
        return p_Instance;
    }
    p_Instance = new VectorGraphics();
    return p_Instance;
}

NVGcontext *harmony::VectorGraphics::AddViewLayer(Layer layer, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    NVGcontext *renderer = nvgCreate(s_UseEdgeAA, viewId);

    for (auto &[name, data]: p_FontDatas) {
        nvgCreateFontMem(renderer, name.c_str(), data.data(), data.size(), 0);
    }
    p_VectorRenderers[layer].emplace_back(renderer);

    return renderer;
}

void harmony::VectorGraphics::RemoveViewLayer(Layer layer, NVGcontext *renderer) {
    OPTICK_EVENT();
    int indexToRemove = -1;
    for (int i = 0; i < p_VectorRenderers[layer].size(); i++) {
        if (p_VectorRenderers[layer][i] == renderer) {
            indexToRemove = i;
        }
    }

    if (indexToRemove >= 0) {
        p_VectorRenderers[layer].erase(p_VectorRenderers[layer].begin() + indexToRemove);
        nvgDelete(renderer);
        renderer = nullptr;
    }
}

void harmony::VectorGraphics::AddFont(const std::string &name, std::vector<uint8_t> data) {
    OPTICK_EVENT();
    if (p_FontDatas.find(name) != p_FontDatas.end()) {
        harmony::log::warn("VectorGraphics : Already loaded a font with name {}", name);
        return;
    }
    p_FontDatas.emplace(name, data);
}

void harmony::VectorGraphics::RemoveFont(const std::string &name) {
    OPTICK_EVENT();
    if (p_FontDatas.find(name) == p_FontDatas.end()) {
        harmony::log::warn("VectorGraphics : No font loaded with name {}", name);
        return;
    }
    p_FontDatas.erase(name);
}

HARMONY_VG_IMPL(FontFace, nvgFontFace, ARG_PACK(font), const char* font)
HARMONY_VG_IMPL(Text, nvgText, ARG_PACK(x,y,str, NULL), float x, float y, const char *str)
HARMONY_VG_IMPL(FontSize, nvgFontSize, ARG_PACK(size), float size);
HARMONY_VG_IMPL(FontBlur, nvgFontBlur, ARG_PACK(size), int size);
HARMONY_VG_IMPL(FillColor, nvgFillColor, ARG_PACK(color), NVGcolor color);