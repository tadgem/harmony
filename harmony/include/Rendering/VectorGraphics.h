#pragma once
#include "Rendering/nanovg/nanovg.h"
#include "bgfx/bgfx.h"


class VectorGraphics
{
public:
	static VectorGraphics* Get();
	static void SetInstanceContext(NVGcontext* context);
	static NVGcontext* GetNVGContext();
private:
	VectorGraphics();
	inline static VectorGraphics* p_Instance = nullptr;
	NVGcontext* s_VectorGraphicsContext = nullptr;
};