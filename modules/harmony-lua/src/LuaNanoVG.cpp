#include "LuaNanoVG.hpp"
#include "Rendering/VectorGraphics.h"


NVGcolor rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return nvgRGBA(r, g, b, a);
}

NVGcolor rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return nvgRGB(r, g, b);
}

void beginPath()
{
	nvgBeginPath(VectorGraphics::GetNVGContext());
}

void rect(float x, float y, float w, float h)
{
	nvgRect(VectorGraphics::GetNVGContext(), x, y, w, h);
}

void circle(float cx, float cy, float r)
{
	nvgCircle(VectorGraphics::GetNVGContext(), cx, cy, r);
}

void pathWinding(int dir)
{
	nvgPathWinding(VectorGraphics::GetNVGContext(), dir);
}

void fillColor(NVGcolor color)
{
	nvgFillColor(VectorGraphics::GetNVGContext(), color);
}

void fill(NVGcolor color)
{
	nvgFill(VectorGraphics::GetNVGContext());
}

void harmony::InitNanoVG(sol::state& state)
{
	sol::table nvg = state.create_named_table("nvg");

	// structs / types
	nvg.new_usertype<NVGcolor>("color", "r", &NVGcolor::r, "g", &NVGcolor::g, "b", &NVGcolor::b, "a", &NVGcolor::a);
	nvg.new_usertype<NVGpaint>("paint", 
		"xform",	&NVGpaint::xform, 
		"extent", &NVGpaint::extent,
		"radius", &NVGpaint::radius,
		"feather", &NVGpaint::feather,
		"innerColor", &NVGpaint::innerColor,
		"outerColor", &NVGpaint::outerColor,
		"image", &NVGpaint::image
		);

	// enums
	nvg.new_enum("winding", "ccw", NVG_CCW, "cw", NVG_CW);
	nvg.new_enum("solidity", "solid", NVG_SOLID, "hole", NVG_HOLE);
	nvg.new_enum("lineCap", 
		"butt"	, NVG_BUTT, 
		"round"	, NVG_ROUND, 
		"square", NVG_SQUARE, 
		"bevel"	, NVG_BEVEL,
		"miter"	, NVG_MITER);
	nvg.new_enum("align",
		"left"		, NVG_ALIGN_LEFT,
		"center"	, NVG_ALIGN_CENTER,
		"right"		, NVG_ALIGN_RIGHT,
		"top"		, NVG_ALIGN_TOP,
		"middle"	, NVG_ALIGN_MIDDLE,
		"bottom"	, NVG_ALIGN_BOTTOM,
		"baseline"	, NVG_ALIGN_BASELINE);
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
		"flipY", N)

	// functiona
	nvg.set_function("rgb", rgb);
	nvg.set_function("rgba", rgba);

	nvg.set_function("beginPath", beginPath);
	nvg.set_function("rect", rect);
	nvg.set_function("circle", circle);
	nvg.set_function("pathWinding", pathWinding);
	nvg.set_function("fill", fill);
	nvg.set_function("fillColor", fillColor);

}
