#pragma once

#include "ImGui/imgui.h"
#include "Core/Program.h"
#include "Assets/AssetManager.h"
#include "Rendering/Renderer.h"

void ProjectDetailsImGui(harmony::Program &program);


void Vec4Input(const std::string &name, glm::vec4 &v);