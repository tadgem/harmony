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
		EditorMainMenuBar(Program& prog);

		void OnImGui();

		void MenuBar();
		void Dialogs();
		void Popups();

	protected:
		Program& p_Prog;

		char p_ProjectNameInput[64]{ "" };
		char p_ProjectPathInput[256]{ "" };
		char p_SceneNameInput[256]{ "" };

		bool p_CreateProjectMenu;
		bool p_CreateSceneMenu;
	};
}