#pragma once
#include "Rendering/nanovg/nanovg.h"
#include "bgfx/bgfx.h"
#include "ThirdParty/json.hpp"

class VectorGraphics
{
protected:
	VectorGraphics();
	inline static VectorGraphics* p_Instance = nullptr;
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
		{One, "1"},
		{Two, "2"},
		{Three, "3"},
		{Four, "4"},
		{Five, "5"},
		{Six, "6"},
		{Seven, "7"},
		{Eight, "8"},
	})

	static VectorGraphics*	Get();

	NVGcontext*			AddViewLayer(Layer layer, bgfx::ViewId viewId);
	void				RemoveViewLayer(Layer layer, NVGcontext* renderer);

protected:
	std::map <Layer, std::vector< NVGcontext*>> p_VectorRenderers;
	inline static const int s_UseEdgeAA = 1;
};