#pragma once

#include "Rendering/VectorGraphics/nanovg/nanovg.h"
#include "ThirdParty/json.hpp"
#include "bgfx/bgfx.h"

// #define MACRO(s, ...) printf(s, __VA_ARGS__)
#define HARMONY_VG_DEF(funcName, ...) void funcName(Layer layer, __VA_ARGS__);
#define HARMONY_VG_DEF_WITH_RETURN(funcName, T, ...)                           \
  T funcName(Layer layer, __VA_ARGS__);

namespace harmony
{
	class VectorGraphics
	{
	protected:
		VectorGraphics();
		inline static VectorGraphics *p_Instance = nullptr;

	public:
		enum Layer : char
		{
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

		static VectorGraphics *Get();
		NVGcontext *AddViewLayer(Layer layer, bgfx::ViewId viewId);
		void RemoveViewLayer(Layer layer, NVGcontext *renderer);
		void AddFont(const std::string &name, std::vector<uint8_t> data);
		void RemoveFont(const std::string &name);
		HARMONY_VG_DEF(FontFace, const char *font)
		HARMONY_VG_DEF(FontSize, float size);
		HARMONY_VG_DEF(FontBlur, int blur);
		HARMONY_VG_DEF(Text, float x, float y, const char *str);
		HARMONY_VG_DEF(FontBlur, float blur);
		HARMONY_VG_DEF(TextLetterSpacing, float spacing);
		HARMONY_VG_DEF(TextLineHeight, float lineHeight);
		HARMONY_VG_DEF(TextAlign, int align);
		HARMONY_VG_DEF(FontFaceId, int font);
		HARMONY_VG_DEF(Text, float x, float y, const char *string, const char *end);
		HARMONY_VG_DEF(TextBox, float x, float y, float breakRowWidth,
					   const char *string, const char *end);
		HARMONY_VG_DEF(ShapeAntiAlias, int enabled);
		HARMONY_VG_DEF(StrokeColor, NVGcolor color);
		HARMONY_VG_DEF(StrokePaint, NVGpaint paint);
		HARMONY_VG_DEF(FillColor, NVGcolor color);
		HARMONY_VG_DEF(FillPaint, NVGpaint paint);
		HARMONY_VG_DEF(MiterLimit, float limit);
		HARMONY_VG_DEF(StrokeWidth, float size);
		HARMONY_VG_DEF(LineCap, int cap);
		HARMONY_VG_DEF(LineJoin, int join);
		HARMONY_VG_DEF(GlobalAlpha, float alpha);
		HARMONY_VG_DEF(ResetTransform);
		HARMONY_VG_DEF(Transform, float a, float b, float c, float d, float e,
					   float f);
		HARMONY_VG_DEF(Translate, float x, float y);
		HARMONY_VG_DEF(Rotate, float angle);
		HARMONY_VG_DEF(SkewX, float angle);
		HARMONY_VG_DEF(SkewY, float angle);
		HARMONY_VG_DEF(Scale, float x, float y);
		HARMONY_VG_DEF(CurrentTransform, float *xform);
		HARMONY_VG_DEF(UpdateImage, int image, const unsigned char *data);
		HARMONY_VG_DEF(ImageSize, int image, int *w, int *h);
		HARMONY_VG_DEF(DeleteImage, int image);
		HARMONY_VG_DEF(Scissor, float x, float y, float w, float h);
		HARMONY_VG_DEF(IntersectScissor, float x, float y, float w, float h);
		HARMONY_VG_DEF(ResetScissor);
		HARMONY_VG_DEF(BeginPath);
		HARMONY_VG_DEF(MoveTo, float x, float y);
		HARMONY_VG_DEF(LineTo, float x, float y);
		HARMONY_VG_DEF(BezierTo, float c1x, float c1y, float c2x, float c2y, float x,
					   float y);
		HARMONY_VG_DEF(QuadTo, float cx, float cy, float x, float y);
		HARMONY_VG_DEF(ArcTo, float x1, float y1, float x2, float y2, float radius);
		HARMONY_VG_DEF(ClosePath);
		HARMONY_VG_DEF(PathWinding, int dir);
		HARMONY_VG_DEF(Arc, float cx, float cy, float r, float a0, float a1, int dir);
		HARMONY_VG_DEF(Rect, float x, float y, float w, float h);
		HARMONY_VG_DEF(RoundedRect, float x, float y, float w, float h, float r);
		HARMONY_VG_DEF(RoundedRectVarying, float x, float y, float w, float h,
					   float radTopLeft, float radTopRight, float radBottomRight,
					   float radBottomLeft);
		HARMONY_VG_DEF(Ellipse, float cx, float cy, float rx, float ry);
		HARMONY_VG_DEF(Circle, float cx, float cy, float r);
		HARMONY_VG_DEF(Fill);
		HARMONY_VG_DEF(Stroke);

		HARMONY_VG_DEF_WITH_RETURN(CreateImageRGBA, int, int w, int h, int imageFlags,
								   const unsigned char *data);
		HARMONY_VG_DEF_WITH_RETURN(CreateFont, int, const char *name,
								   const char *filename);
		HARMONY_VG_DEF_WITH_RETURN(CreateFontMem, int, const char *name,
								   unsigned char *data, int ndata, int freeData);
		HARMONY_VG_DEF_WITH_RETURN(FindFont, int, const char *name);
		HARMONY_VG_DEF_WITH_RETURN(AddFallbackFontId, int, int baseFont,
								   int fallbackFont);
		HARMONY_VG_DEF_WITH_RETURN(AddFallbackFont, int, const char *baseFont,
								   const char *fallbackFont);
		HARMONY_VG_DEF_WITH_RETURN(LinearGradient, NVGpaint, float sx, float sy,
								   float ex, float ey, NVGcolor icol, NVGcolor ocol);
		HARMONY_VG_DEF_WITH_RETURN(BoxGradient, NVGpaint, float x, float y, float w,
								   float h, float r, float f, NVGcolor icol,
								   NVGcolor ocol);
		HARMONY_VG_DEF_WITH_RETURN(RadialGradient, NVGpaint, float cx, float cy,
								   float inr, float outr, NVGcolor icol,
								   NVGcolor ocol);
		HARMONY_VG_DEF_WITH_RETURN(ImagePattern, NVGpaint, float ox, float oy,
								   float ex, float ey, float angle, int image,
								   float alpha);

	protected:
		std::map<Layer, std::vector<NVGcontext *>> p_VectorRenderers;
		std::map<std::string, std::vector<uint8_t>> p_FontDatas;
		friend class FontAssetFactory;
		inline static const int s_UseEdgeAA = 0;
	};
} // namespace harmony