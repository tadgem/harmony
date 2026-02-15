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
  Engine engine = Engine::Init<WGPUBackend>(1920, 1080, enableSwapchainMSAA, GIGABYTES(4),
                               enableVulkanValidation);

  AssetHandle sh{};
  String someString = "Hello";
  SerializableAssetHandle handle(someString, AssetType::Audio);
  Timer t;

  printf("Handle Str : %s\n", handle.mPath.c_str());
//  {
//    lvk::Vector3 someUniqueData = {10, 20, 30};
//    AssetT<lvk::Vector3, AssetType::Audio> asset(someString, someUniqueData);
//    AssetIntermediateT<lvk::Vector3, lvk::Vector3, AssetType::Audio> inter(
//        static_cast<Asset *>(&asset), lvk::Vector3{0.0f, 0.0f, 0.0f});
//
//    lvk::Vector3 result = asset.mData;
//  }

  flecs::world ecs{};
  flecs::entity e = ecs.entity();

  Json someJson;
  someJson["dad"] = 3;
  int64 val = someJson["dad"];

  auto ms = t.ElapsedMillisecondsF();
  auto ns = t.ElapsedNanosecondsF();

  while (engine.ShouldRun()) {
    engine.PreFrame();

    engine.EndFrame();
  }
  return 0;
}
