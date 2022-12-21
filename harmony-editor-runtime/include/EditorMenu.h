#pragma once
#include "Core/Memory.h"
#include "Core/Scene.h"
#include "Core/Program.h"
#include "ThirdParty/entt.hpp"

namespace harmony
{
	class Editor;
	class EditorMainMenuBar
	{
	public:
		EditorMainMenuBar(Editor& prog);

		void OnImGui();

		void MenuBar();
		void Dialogs();
		void Popups();

		ImVec2 m_MenuBarSize;

	protected:
		Editor& p_Prog;

		char p_ProjectNameInput[64]{ "" };
		char p_ProjectPathInput[256]{ "" };
		char p_SceneNameInput[256]{ "" };

		bool p_CreateProjectMenu;
		bool p_CreateSceneMenu;
	};
}