#pragma once

#include "STL/Vector.h"
#include "STL/Map.h"
#include "STL/Json.hpp"
#include "STL/String.h"
#include "STL/Thread.h"
#include "Rendering/VectorGraphics/nanovg/nanovg.h"
#include "bgfx/bgfx.h"
// #define MACRO(s, ...) printf(s, __VA_ARGS__)

namespace harmony {
    class VectorGraphics {
    public:
        enum Layer : char {
            One,
            Two,
            Three,
            Four,
            Five,
            Six,
            Seven,
            Eight
        };

        NLOHMANN_JSON_SERIALIZE_ENUM(Layer, {
            { One, "1" },
            { Two, "2" },
            { Three, "3" },
            { Four, "4" },
            { Five, "5" },
            { Six, "6" },
            { Seven, "7" },
            { Eight, "8" },
        })

        static void Init();

        static NVGcontext *AddViewLayer(Layer layer, bgfx::ViewId viewId);

        static void RemoveViewLayer(Layer layer, NVGcontext *renderer);

        static void AddFont(const String &name, Vector<uint8_t> data);

        static void RemoveFont(const String &name);

        static void FontFace(Layer layer, const char *font);

        static void FontSize(Layer layer, float size);

        static void FontBlur(Layer layer, float blur);

        static void Text(Layer layer, float x, float y, const char *str);

        static void TextLetterSpacing(Layer layer, float spacing);

        static void TextLineHeight(Layer layer, float lineHeight);

        static void TextAlign(Layer layer, int align);

        static void FontFaceId(Layer layer, int font);

        static void TextBox(Layer layer, float x, float y, float breakRowWidth, const char *string, const char *end);

        static void ShapeAntiAlias(Layer layer, int enabled);

        static void StrokeColor(Layer layer, NVGcolor color);

        static void StrokePaint(Layer layer, NVGpaint paint);

        static void FillColor(Layer layer, NVGcolor color);

        static void FillPaint(Layer layer, NVGpaint paint);

        static void MiterLimit(Layer layer, float limit);

        static void StrokeWidth(Layer layer, float size);

        static void LineCap(Layer layer, int cap);

        static void LineJoin(Layer layer, int join);

        static void GlobalAlpha(Layer layer, float alpha);

        static void ResetTransform(Layer layer);

        static void Transform(Layer layer, float a, float b, float c, float d, float e, float f);

        static void Translate(Layer layer, float x, float y);

        static void Rotate(Layer layer, float angle);

        static void SkewX(Layer layer, float angle);

        static void SkewY(Layer layer, float angle);

        static void Scale(Layer layer, float x, float y);

        static void CurrentTransform(Layer layer, float *xform);

        static void UpdateImage(Layer layer, int image, const unsigned char *data);

        static void ImageSize(Layer layer, int image, int *w, int *h);

        static void DeleteImage(Layer layer, int image);

        static void Scissor(Layer layer, float x, float y, float w, float h);

        static void IntersectScissor(Layer layer, float x, float y, float w, float h);

        static void ResetScissor(Layer layer);

        static void BeginPath(Layer layer);

        static void MoveTo(Layer layer, float x, float y);

        static void LineTo(Layer layer, float x, float y);

        static void BezierTo(Layer layer, float c1x, float c1y, float c2x, float c2y, float x, float y);

        static void QuadTo(Layer layer, float cx, float cy, float x, float y);

        static void ArcTo(Layer layer, float x1, float y1, float x2, float y2, float radius);

        static void ClosePath(Layer layer);

        static void PathWinding(Layer layer, int dir);

        static void Arc(Layer layer, float cx, float cy, float r, float a0, float a1, int dir);

        static void Rect(Layer layer, float x, float y, float w, float h);

        static void RoundedRect(Layer layer, float x, float y, float w, float h, float r);

        static void
        RoundedRectVarying(Layer layer, float x, float y, float w, float h, float radTopLeft, float radTopRight,
                           float radBottomRight, float radBottomLeft);

        static void Ellipse(Layer layer, float cx, float cy, float rx, float ry);

        static void Circle(Layer layer, float cx, float cy, float r);

        static void Fill(Layer layer);

        static void Stroke(Layer layer);

        static NVGpaint
        LinearGradient(Layer layer, float sx, float sy, float ex, float ey, NVGcolor icol, NVGcolor ocol);

        static NVGpaint
        BoxGradient(Layer layer, float x, float y, float w, float h, float r, float f, NVGcolor icol, NVGcolor ocol);

        static NVGpaint
        RadialGradient(Layer layer, float cx, float cy, float inr, float outr, NVGcolor icol, NVGcolor ocol);

        static NVGpaint
        ImagePattern(Layer layer, float ox, float oy, float ex, float ey, float angle, int image, float alpha);

    protected:
        static Map<Layer, Vector<NVGcontext *>> p_VectorRenderers;
        static Map<String, Vector<uint8_t>> p_FontDatas;

        friend class FontAssetFactory;

        inline static const int s_UseEdgeAA = 0;
    };
} // namespace harmony