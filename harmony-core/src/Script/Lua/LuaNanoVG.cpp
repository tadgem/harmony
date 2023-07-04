#include "Script/Lua/LuaNanoVG.hpp"
#include "Rendering/VectorGraphics/VectorGraphics.h"
#define HARMONY_LUA_VG_BIND(X)     nvg["X"] = &harmony::VectorGraphics::X;
NVGcolor rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return nvgRGBA(r, g, b, a);
}

NVGcolor rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return nvgRGB(r, g, b);
}

void harmony::InitNanoVG(sol::state &state)
{
	sol::table nvg = state.create_named_table("nvg");

	// structs / types
	nvg.new_usertype<NVGcolor>("color", "r", &NVGcolor::r, "g", &NVGcolor::g, "b", &NVGcolor::b, "a", &NVGcolor::a);
	nvg.new_usertype<NVGpaint>("paint",
							   "xform", &NVGpaint::xform,
							   "extent", &NVGpaint::extent,
							   "radius", &NVGpaint::radius,
							   "feather", &NVGpaint::feather,
							   "innerColor", &NVGpaint::innerColor,
							   "outerColor", &NVGpaint::outerColor,
							   "image", &NVGpaint::image
	);


	// enums

	nvg.new_enum("layer",
				 "one", VectorGraphics::Layer::One,
				 "two", VectorGraphics::Layer::Two,
				 "three", VectorGraphics::Layer::Three,
				 "four", VectorGraphics::Layer::Four,
				 "five", VectorGraphics::Layer::Five,
				 "six", VectorGraphics::Layer::Six,
				 "seven", VectorGraphics::Layer::Seven,
				 "eight", VectorGraphics::Layer::Eight
	);

	nvg.new_enum("winding", "ccw", NVG_CCW, "cw", NVG_CW);
	nvg.new_enum("solidity", "solid", NVG_SOLID, "hole", NVG_HOLE);
	nvg.new_enum("lineCap",
				 "butt", NVG_BUTT,
				 "round", NVG_ROUND,
				 "square", NVG_SQUARE,
				 "bevel", NVG_BEVEL,
				 "miter", NVG_MITER);
	nvg.new_enum("align",
				 "left", NVG_ALIGN_LEFT,
				 "center", NVG_ALIGN_CENTER,
				 "right", NVG_ALIGN_RIGHT,
				 "top", NVG_ALIGN_TOP,
				 "middle", NVG_ALIGN_MIDDLE,
				 "bottom", NVG_ALIGN_BOTTOM,
				 "baseline", NVG_ALIGN_BASELINE);

	nvg.new_enum("blendFactor",
				 "zero", NVG_ZERO,
				 "one", NVG_ONE,
				 "srcColor", NVG_SRC_COLOR,
				 "oneMinusSrcColor", NVG_ONE_MINUS_SRC_COLOR,
				 "dstColor", NVG_DST_COLOR,
				 "oneMinusDstColor", NVG_ONE_MINUS_DST_COLOR,
				 "srcAlpha", NVG_SRC_ALPHA,
				 "oneMinusSrcAlpha", NVG_ONE_MINUS_SRC_ALPHA,
				 "dstAlpha", NVG_DST_ALPHA,
				 "oneMinusDstAlpha", NVG_ONE_MINUS_DST_ALPHA,
				 "srcAlphaSaturate", NVG_SRC_ALPHA_SATURATE
	);

	nvg.new_enum("compOp",
				 "srcOver", NVG_SOURCE_OVER,
				 "srcIn", NVG_SOURCE_IN,
				 "srcOut", NVG_SOURCE_OUT,
				 "atop", NVG_ATOP,
				 "dstOver", NVG_DESTINATION_OVER,
				 "dstIn", NVG_DESTINATION_OVER,
				 "dstOut", NVG_DESTINATION_OUT,
				 "dstAtop", NVG_DESTINATION_ATOP,
				 "ligher", NVG_LIGHTER,
				 "copy", NVG_COPY,
				 "xor", NVG_XOR);

	nvg.new_enum("imageFlags",
				 "repeatX", NVG_IMAGE_REPEATX,
				 "repeatY", NVG_IMAGE_REPEATY,
				 "flipY", NVG_IMAGE_FLIPY,
				 "premultiplied", NVG_IMAGE_PREMULTIPLIED,
				 "nearest", NVG_IMAGE_NEAREST);

	nvg.new_enum("texture",
				 "alpha", NVG_TEXTURE_ALPHA,
				 "rgba", NVG_TEXTURE_RGBA);

	// functiona
	nvg.set_function("rgb", rgb);
	nvg.set_function("rgba", rgba);

    HARMONY_LUA_VG_BIND(FontFace)
    HARMONY_LUA_VG_BIND(FontSize);
    HARMONY_LUA_VG_BIND(FontBlur);
    HARMONY_LUA_VG_BIND(Text);
    HARMONY_LUA_VG_BIND(TextLetterSpacing);
    HARMONY_LUA_VG_BIND(TextLineHeight);
    HARMONY_LUA_VG_BIND(TextAlign);
    HARMONY_LUA_VG_BIND(FontFaceId);
    HARMONY_LUA_VG_BIND(TextBox);
    HARMONY_LUA_VG_BIND(ShapeAntiAlias);
    HARMONY_LUA_VG_BIND(StrokeColor);
    HARMONY_LUA_VG_BIND(StrokePaint);
    HARMONY_LUA_VG_BIND(FillColor);
    HARMONY_LUA_VG_BIND(FillPaint);
    HARMONY_LUA_VG_BIND(MiterLimit);
    HARMONY_LUA_VG_BIND(StrokeWidth);
    HARMONY_LUA_VG_BIND(LineCap);
    HARMONY_LUA_VG_BIND(LineJoin);
    HARMONY_LUA_VG_BIND(GlobalAlpha);
    HARMONY_LUA_VG_BIND(ResetTransform);
    HARMONY_LUA_VG_BIND(Transform);
    HARMONY_LUA_VG_BIND(Translate);
    HARMONY_LUA_VG_BIND(Rotate);
    HARMONY_LUA_VG_BIND(SkewX);
    HARMONY_LUA_VG_BIND(SkewY);
    HARMONY_LUA_VG_BIND(Scale);
    HARMONY_LUA_VG_BIND(CurrentTransform);
    HARMONY_LUA_VG_BIND(UpdateImage);
    HARMONY_LUA_VG_BIND(ImageSize);
    HARMONY_LUA_VG_BIND(DeleteImage);
    HARMONY_LUA_VG_BIND(Scissor);
    HARMONY_LUA_VG_BIND(IntersectScissor);
    HARMONY_LUA_VG_BIND(ResetScissor);
    HARMONY_LUA_VG_BIND(BeginPath);
    HARMONY_LUA_VG_BIND(MoveTo);
    HARMONY_LUA_VG_BIND(LineTo);
    HARMONY_LUA_VG_BIND(BezierTo)
    HARMONY_LUA_VG_BIND(QuadTo);
    HARMONY_LUA_VG_BIND(ArcTo);
    HARMONY_LUA_VG_BIND(ClosePath);
    HARMONY_LUA_VG_BIND(PathWinding);
    HARMONY_LUA_VG_BIND(Arc);
    HARMONY_LUA_VG_BIND(Rect);
    HARMONY_LUA_VG_BIND(RoundedRect);
    HARMONY_LUA_VG_BIND(RoundedRectVarying);
    HARMONY_LUA_VG_BIND(Ellipse);
    HARMONY_LUA_VG_BIND(Circle);
    HARMONY_LUA_VG_BIND(Fill);
    HARMONY_LUA_VG_BIND(Stroke);
    HARMONY_LUA_VG_BIND(LinearGradient)
    HARMONY_LUA_VG_BIND(BoxGradient)
    HARMONY_LUA_VG_BIND(RadialGradient)
    HARMONY_LUA_VG_BIND(ImagePattern)
}
