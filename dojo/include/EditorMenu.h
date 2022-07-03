#pragma once
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Core/Program.h"
#include "entt.hpp"

namespace harmony
{
	class EditorMainMenuBar
	{
	public:
		EditorMainMenuBar();

		void OnImGui();
	};
}