#include <cstdio>


#include "Assets.h"
#include "Engine.h"
#include "Json.h"
#include "Macros.h"
#include "Memory.h"
#include "STL.h"
#include "Timer.h"
#include "WGPUBackend.h"
#define FLECS_USE_OS_ALLOC
#include "flecs.h"
#include "Maths.h"
#include "flecs/addons/cpp/flecs.hpp"

HARMONY_OVERRIDE_GLOBAL_NEW(true)

//void OnImGui(harmony::Engine &e) {
//  if (ImGui::Begin("Hello world!")) {
//  }
//  ImGui::End();
//}
int main() {
	using namespace harmony;
	bool enableSwapchainMSAA = false;
	bool enableVulkanValidation = false;
	Engine engine = Engine::Init<WGPUBackend>(
		1920, 1080,
		enableSwapchainMSAA, GIGABYTES(4), enableVulkanValidation);

	AssetHandle sh{};
	String someString = "Hello";
	SerializableAssetHandle handle(someString, AssetType::Audio);
	Vector<String> strings ;

	strings.push_back("DAD");
	Timer t;

	vec3 v = {0.0, 1.0, 2.0};
	printf("Handle Str : %s\n", handle.path.c_str());

	flecs::world ecs{};
	flecs::entity e = ecs.entity();

	json someJson;
	someJson["dad"] = 3;
	int64 val = someJson["dad"];

	auto ms = t.ElapsedMillisecondsF();
	auto ns = t.ElapsedNanosecondsF();

	while (engine.should_run()) {
		engine.pre_frame();
		engine.end_frame();
  }
  return 0;
}