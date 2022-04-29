// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

class Enumeration_imnodes_ColorStyle : public das::Enumeration {
public:
	Enumeration_imnodes_ColorStyle() : das::Enumeration("ColorStyle") {
		external = true;
		cppName = "imnodes::ColorStyle";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("NodeBackground", "ColorStyle_NodeBackground", int64_t(imnodes::ColorStyle::ColorStyle_NodeBackground), das::LineInfo());
		addIEx("NodeBackgroundHovered", "ColorStyle_NodeBackgroundHovered", int64_t(imnodes::ColorStyle::ColorStyle_NodeBackgroundHovered), das::LineInfo());
		addIEx("NodeBackgroundSelected", "ColorStyle_NodeBackgroundSelected", int64_t(imnodes::ColorStyle::ColorStyle_NodeBackgroundSelected), das::LineInfo());
		addIEx("NodeOutline", "ColorStyle_NodeOutline", int64_t(imnodes::ColorStyle::ColorStyle_NodeOutline), das::LineInfo());
		addIEx("TitleBar", "ColorStyle_TitleBar", int64_t(imnodes::ColorStyle::ColorStyle_TitleBar), das::LineInfo());
		addIEx("TitleBarHovered", "ColorStyle_TitleBarHovered", int64_t(imnodes::ColorStyle::ColorStyle_TitleBarHovered), das::LineInfo());
		addIEx("TitleBarSelected", "ColorStyle_TitleBarSelected", int64_t(imnodes::ColorStyle::ColorStyle_TitleBarSelected), das::LineInfo());
		addIEx("Link", "ColorStyle_Link", int64_t(imnodes::ColorStyle::ColorStyle_Link), das::LineInfo());
		addIEx("LinkHovered", "ColorStyle_LinkHovered", int64_t(imnodes::ColorStyle::ColorStyle_LinkHovered), das::LineInfo());
		addIEx("LinkSelected", "ColorStyle_LinkSelected", int64_t(imnodes::ColorStyle::ColorStyle_LinkSelected), das::LineInfo());
		addIEx("Pin", "ColorStyle_Pin", int64_t(imnodes::ColorStyle::ColorStyle_Pin), das::LineInfo());
		addIEx("PinHovered", "ColorStyle_PinHovered", int64_t(imnodes::ColorStyle::ColorStyle_PinHovered), das::LineInfo());
		addIEx("BoxSelector", "ColorStyle_BoxSelector", int64_t(imnodes::ColorStyle::ColorStyle_BoxSelector), das::LineInfo());
		addIEx("BoxSelectorOutline", "ColorStyle_BoxSelectorOutline", int64_t(imnodes::ColorStyle::ColorStyle_BoxSelectorOutline), das::LineInfo());
		addIEx("GridBackground", "ColorStyle_GridBackground", int64_t(imnodes::ColorStyle::ColorStyle_GridBackground), das::LineInfo());
		addIEx("GridLine", "ColorStyle_GridLine", int64_t(imnodes::ColorStyle::ColorStyle_GridLine), das::LineInfo());
		addIEx("Count", "ColorStyle_Count", int64_t(imnodes::ColorStyle::ColorStyle_Count), das::LineInfo());
	}
};

class Enumeration_imnodes_StyleVar : public das::Enumeration {
public:
	Enumeration_imnodes_StyleVar() : das::Enumeration("StyleVar") {
		external = true;
		cppName = "imnodes::StyleVar";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("GridSpacing", "StyleVar_GridSpacing", int64_t(imnodes::StyleVar::StyleVar_GridSpacing), das::LineInfo());
		addIEx("NodeCornerRounding", "StyleVar_NodeCornerRounding", int64_t(imnodes::StyleVar::StyleVar_NodeCornerRounding), das::LineInfo());
		addIEx("NodePaddingHorizontal", "StyleVar_NodePaddingHorizontal", int64_t(imnodes::StyleVar::StyleVar_NodePaddingHorizontal), das::LineInfo());
		addIEx("NodePaddingVertical", "StyleVar_NodePaddingVertical", int64_t(imnodes::StyleVar::StyleVar_NodePaddingVertical), das::LineInfo());
		addIEx("NodeBorderThickness", "StyleVar_NodeBorderThickness", int64_t(imnodes::StyleVar::StyleVar_NodeBorderThickness), das::LineInfo());
		addIEx("LinkThickness", "StyleVar_LinkThickness", int64_t(imnodes::StyleVar::StyleVar_LinkThickness), das::LineInfo());
		addIEx("LinkLineSegmentsPerLength", "StyleVar_LinkLineSegmentsPerLength", int64_t(imnodes::StyleVar::StyleVar_LinkLineSegmentsPerLength), das::LineInfo());
		addIEx("LinkHoverDistance", "StyleVar_LinkHoverDistance", int64_t(imnodes::StyleVar::StyleVar_LinkHoverDistance), das::LineInfo());
		addIEx("PinCircleRadius", "StyleVar_PinCircleRadius", int64_t(imnodes::StyleVar::StyleVar_PinCircleRadius), das::LineInfo());
		addIEx("PinQuadSideLength", "StyleVar_PinQuadSideLength", int64_t(imnodes::StyleVar::StyleVar_PinQuadSideLength), das::LineInfo());
		addIEx("PinTriangleSideLength", "StyleVar_PinTriangleSideLength", int64_t(imnodes::StyleVar::StyleVar_PinTriangleSideLength), das::LineInfo());
		addIEx("PinLineThickness", "StyleVar_PinLineThickness", int64_t(imnodes::StyleVar::StyleVar_PinLineThickness), das::LineInfo());
		addIEx("PinHoverRadius", "StyleVar_PinHoverRadius", int64_t(imnodes::StyleVar::StyleVar_PinHoverRadius), das::LineInfo());
		addIEx("PinOffset", "StyleVar_PinOffset", int64_t(imnodes::StyleVar::StyleVar_PinOffset), das::LineInfo());
	}
};

class Enumeration_imnodes_StyleFlags : public das::Enumeration {
public:
	Enumeration_imnodes_StyleFlags() : das::Enumeration("StyleFlags") {
		external = true;
		cppName = "imnodes::StyleFlags";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("None", "StyleFlags_None", int64_t(imnodes::StyleFlags::StyleFlags_None), das::LineInfo());
		addIEx("NodeOutline", "StyleFlags_NodeOutline", int64_t(imnodes::StyleFlags::StyleFlags_NodeOutline), das::LineInfo());
		addIEx("GridLines", "StyleFlags_GridLines", int64_t(imnodes::StyleFlags::StyleFlags_GridLines), das::LineInfo());
	}
};

class Enumeration_imnodes_PinShape : public das::Enumeration {
public:
	Enumeration_imnodes_PinShape() : das::Enumeration("PinShape") {
		external = true;
		cppName = "imnodes::PinShape";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("Circle", "PinShape_Circle", int64_t(imnodes::PinShape::PinShape_Circle), das::LineInfo());
		addIEx("CircleFilled", "PinShape_CircleFilled", int64_t(imnodes::PinShape::PinShape_CircleFilled), das::LineInfo());
		addIEx("Triangle", "PinShape_Triangle", int64_t(imnodes::PinShape::PinShape_Triangle), das::LineInfo());
		addIEx("TriangleFilled", "PinShape_TriangleFilled", int64_t(imnodes::PinShape::PinShape_TriangleFilled), das::LineInfo());
		addIEx("Quad", "PinShape_Quad", int64_t(imnodes::PinShape::PinShape_Quad), das::LineInfo());
		addIEx("QuadFilled", "PinShape_QuadFilled", int64_t(imnodes::PinShape::PinShape_QuadFilled), das::LineInfo());
	}
};

class Enumeration_imnodes_AttributeFlags : public das::Enumeration {
public:
	Enumeration_imnodes_AttributeFlags() : das::Enumeration("AttributeFlags") {
		external = true;
		cppName = "imnodes::AttributeFlags";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("None", "AttributeFlags_None", int64_t(imnodes::AttributeFlags::AttributeFlags_None), das::LineInfo());
		addIEx("EnableLinkDetachWithDragClick", "AttributeFlags_EnableLinkDetachWithDragClick", int64_t(imnodes::AttributeFlags::AttributeFlags_EnableLinkDetachWithDragClick), das::LineInfo());
		addIEx("EnableLinkCreationOnSnap", "AttributeFlags_EnableLinkCreationOnSnap", int64_t(imnodes::AttributeFlags::AttributeFlags_EnableLinkCreationOnSnap), das::LineInfo());
	}
};

