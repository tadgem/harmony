#include <optick.h>
#include "Rendering/VectorGraphics/VectorGraphics.h"
#include "Core/Log.hpp"

#define ARG_PACK(...) __VA_ARGS__

#define HARMONY_VG_IMPL(FUNC_NAME, nanoVgFuncImpl, ...) void harmony::VectorGraphics::FUNC_NAME(Layer layer, __VA_ARGS__) \
{\
    OPTICK_EVENT();\
    for (NVGcontext *context: p_VectorRenderers[layer]) {\
        nvg##FUNC_NAME(context, nanoVgFuncImpl);\
    }\
}

#define HARMONY_VG_IMPL_WITH_RETURN(FUNC_NAME, T, nanoVgFuncImpl, ...) T harmony::VectorGraphics::FUNC_NAME(Layer layer, __VA_ARGS__) \
{\
    OPTICK_EVENT();\
    T empty = {};\
    for (NVGcontext *context: p_VectorRenderers[layer]) {\
        empty = nvg##FUNC_NAME(context, nanoVgFuncImpl);\
    }\
    return empty;\
}

#define HARMONY_VG_PROC(FUNC_NAME) void harmony::VectorGraphics::FUNC_NAME(Layer layer) \
{\
    OPTICK_EVENT();\
    for (NVGcontext *context: p_VectorRenderers[layer]) {\
        nvg##FUNC_NAME(context);\
    }\
}

harmony::Map<harmony::VectorGraphics::Layer, harmony::Vector<NVGcontext *>> harmony::VectorGraphics::p_VectorRenderers = harmony::Map<harmony::VectorGraphics::Layer, harmony::Vector<NVGcontext *>>();
harmony::Map<harmony::String, harmony::Vector<uint8_t>> harmony::VectorGraphics::p_FontDatas = harmony::Map<harmony::String, harmony::Vector<uint8_t>>();

void harmony::VectorGraphics::Init() {
    OPTICK_EVENT();
    p_VectorRenderers.emplace(Layer::One, Vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Two, Vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Three, Vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Four, Vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Five, Vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Six, Vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Seven, Vector<NVGcontext *>());
    p_VectorRenderers.emplace(Layer::Eight, Vector<NVGcontext *>());
}

NVGcontext *harmony::VectorGraphics::AddViewLayer(Layer layer, bgfx::ViewId viewId) {
    OPTICK_EVENT();
    NVGcontext *renderer = nvgCreate(s_UseEdgeAA, viewId);

    for (auto &[name, data]: p_FontDatas) {
        nvgCreateFontMem(renderer, name.c_str(), data.data(), static_cast<int>(data.size()), 0);
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

void harmony::VectorGraphics::AddFont(const String &name, Vector<uint8_t> data) {
    OPTICK_EVENT();
    if (p_FontDatas.find(name) != p_FontDatas.end()) {
        harmony::log::warn("VectorGraphics : Already loaded a font with name {}", name);
        return;
    }
    p_FontDatas.emplace(name, data);
}

void harmony::VectorGraphics::RemoveFont(const String &name) {
    OPTICK_EVENT();
    if (p_FontDatas.find(name) == p_FontDatas.end()) {
        harmony::log::warn("VectorGraphics : No font loaded with name {}", name);
        return;
    }
    p_FontDatas.erase(name);
}

HARMONY_VG_IMPL(FontFace, ARG_PACK(font), const char *font)

HARMONY_VG_IMPL(FontSize, ARG_PACK(size), float size);

HARMONY_VG_IMPL(FontBlur, ARG_PACK(blur), float blur);

HARMONY_VG_IMPL(Text, ARG_PACK(x, y, str, NULL), float x, float y, const char *str)

HARMONY_VG_IMPL(TextLetterSpacing, ARG_PACK(spacing), float spacing);

HARMONY_VG_IMPL(TextLineHeight, ARG_PACK(lineHeight), float lineHeight);

HARMONY_VG_IMPL(TextAlign, ARG_PACK(align), int align);

HARMONY_VG_IMPL(FontFaceId, ARG_PACK(font), int font);

HARMONY_VG_IMPL(TextBox, ARG_PACK(x, y, breakRowWidth, string, end), float x, float y, float breakRowWidth,
                const char *string, const char *end);

HARMONY_VG_IMPL(ShapeAntiAlias, ARG_PACK(enabled), int enabled);

HARMONY_VG_IMPL(StrokeColor, ARG_PACK(color), NVGcolor color);

HARMONY_VG_IMPL(StrokePaint, ARG_PACK(paint), NVGpaint paint);

HARMONY_VG_IMPL(FillColor, ARG_PACK(color), NVGcolor color);

HARMONY_VG_IMPL(FillPaint, ARG_PACK(paint), NVGpaint paint);

HARMONY_VG_IMPL(MiterLimit, ARG_PACK(limit), float limit);

HARMONY_VG_IMPL(StrokeWidth, ARG_PACK(size), float size);

HARMONY_VG_IMPL(LineCap, ARG_PACK(cap), int cap);

HARMONY_VG_IMPL(LineJoin, ARG_PACK(join), int join);

HARMONY_VG_IMPL(GlobalAlpha, ARG_PACK(alpha), float alpha);

HARMONY_VG_PROC(ResetTransform);

HARMONY_VG_IMPL(Transform, ARG_PACK(a, b, c, d, e, f), float a, float b, float c, float d, float e,
                float f);

HARMONY_VG_IMPL(Translate, ARG_PACK(x, y), float x, float y);

HARMONY_VG_IMPL(Rotate, ARG_PACK(angle), float angle);

HARMONY_VG_IMPL(SkewX, ARG_PACK(angle), float angle);

HARMONY_VG_IMPL(SkewY, ARG_PACK(angle), float angle);

HARMONY_VG_IMPL(Scale, ARG_PACK(x, y), float x, float y);

HARMONY_VG_IMPL(CurrentTransform, ARG_PACK(xform), float *xform);

HARMONY_VG_IMPL(UpdateImage, ARG_PACK(image, data), int image, const unsigned char *data);

HARMONY_VG_IMPL(ImageSize, ARG_PACK(image, w, h), int image, int *w, int *h);

HARMONY_VG_IMPL(DeleteImage, ARG_PACK(image), int image);

HARMONY_VG_IMPL(Scissor, ARG_PACK(x, y, w, h), float x, float y, float w, float h);

HARMONY_VG_IMPL(IntersectScissor, ARG_PACK(x, y, w, h), float x, float y, float w, float h);

HARMONY_VG_PROC(ResetScissor);

HARMONY_VG_PROC(BeginPath);

HARMONY_VG_IMPL(MoveTo, ARG_PACK(x, y), float x, float y);

HARMONY_VG_IMPL(LineTo, ARG_PACK(x, y), float x, float y);

HARMONY_VG_IMPL(BezierTo, ARG_PACK(c1x, c1y, c2x, c2y, x, y), float c1x, float c1y, float c2x, float c2y, float x,
                float y);

HARMONY_VG_IMPL(QuadTo, ARG_PACK(cx, cy, x, y), float cx, float cy, float x, float y);

HARMONY_VG_IMPL(ArcTo, ARG_PACK(x1, y1, x2, y2, radius), float x1, float y1, float x2, float y2, float radius);

HARMONY_VG_PROC(ClosePath);

HARMONY_VG_IMPL(PathWinding, ARG_PACK(dir), int dir);

HARMONY_VG_IMPL(Arc, ARG_PACK(cx, cy, r, a0, a1, dir), float cx, float cy, float r, float a0, float a1, int dir);

HARMONY_VG_IMPL(Rect, ARG_PACK(x, y, w, h), float x, float y, float w, float h);

HARMONY_VG_IMPL(RoundedRect, ARG_PACK(x, y, w, h, r), float x, float y, float w, float h, float r);

HARMONY_VG_IMPL(RoundedRectVarying, ARG_PACK(x, y, w, h, radTopLeft, radTopRight, radBottomRight, radBottomLeft),
                float x, float y, float w, float h,
                float radTopLeft, float radTopRight, float radBottomRight,
                float radBottomLeft);

HARMONY_VG_IMPL(Ellipse, ARG_PACK(cx, cy, rx, ry), float cx, float cy, float rx, float ry);

HARMONY_VG_IMPL(Circle, ARG_PACK(cx, cy, r), float cx, float cy, float r);

HARMONY_VG_PROC(Fill);

HARMONY_VG_PROC(Stroke);

HARMONY_VG_IMPL_WITH_RETURN(LinearGradient, NVGpaint, ARG_PACK(sx, sy, ex, ey, icol, ocol), float sx, float sy,
                            float ex, float ey, NVGcolor icol, NVGcolor ocol);

HARMONY_VG_IMPL_WITH_RETURN(BoxGradient, NVGpaint, ARG_PACK(x, y, w, h, r, f, icol, ocol), float x, float y, float w,
                            float h, float r, float f, NVGcolor icol,
                            NVGcolor ocol);

HARMONY_VG_IMPL_WITH_RETURN(RadialGradient, NVGpaint, ARG_PACK(cx, cy, inr, outr, icol, ocol), float cx, float cy,
                            float inr, float outr, NVGcolor icol,
                            NVGcolor ocol);

HARMONY_VG_IMPL_WITH_RETURN(ImagePattern, NVGpaint, ARG_PACK(ox, oy, ex, ey, angle, image, alpha), float ox, float oy,
                            float ex, float ey, float angle, int image,
                            float alpha);