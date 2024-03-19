#pragma once

#include "ImGui/imgui.h"
#include "Core/Program.h"
#include "Assets/AssetManager.h"
#include "Rendering/Renderer.h"

void ProjectDetailsImGui(harmony::Program &program);


void Vec4Input(const harmony::String &name, glm::vec4 &v);