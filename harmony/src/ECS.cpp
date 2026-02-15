#include "ECS.h"

harmony::Entity harmony::Scene::create_entity() {
  auto flecs_entity = world.entity();
  return Entity(flecs_entity);
}

harmony::String harmony::System::get_entity_id_as_string(Entity &e) {
  // TODO: Need sprintf
  // Utils::ToString(static_cast<uint64>(e.mFlecsHandle.id()));
  return "";
}

uint64 harmony::System::get_entity_id_from_string(const String &entity) {
  return std::stoull(entity.c_str());
}
