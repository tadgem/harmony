#pragma once

#include "sol/sol.hpp"
#include "ImGui/imgui.h"

static void bind_imgui(sol::state& state)
{
	sol::table imgui = state.create_named_table("imgui");
	// imgui.Begin('My Window Name')
	imgui.set_function("Begin", [](std::string name) {
			return ImGui::Begin(name.c_str());
		});
	// imgui.End()
	imgui.set_function("End", []() {
			ImGui::End();
		});
	// imgui.Text('My Text')
	imgui.set_function("Text", [](std::string text) {
			ImGui::Text(text.c_str());
		});
	// imgui.Separator()
	imgui.set_function("Separator", []() {
			ImGui::Separator();
		});
	// imgui.Button('My Button Name')
	imgui.set_function("Button", [](std::string name) {
		return ImGui::Button(name.c_str());
		});

}