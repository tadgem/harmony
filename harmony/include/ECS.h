#pragma once
#include "Json.h"
#include "STL.h"
#define FLECS_USE_OS_ALLOC
#include "flecs.h"
#include "flecs/addons/cpp/flecs.hpp"

namespace harmony {
class Entity {
public:
  flecs::entity handle;
  Entity(const flecs::entity &e) : handle(e) {}

  void destroy() { handle.destruct(); }

  template <typename _Ty, typename... Args> _Ty &add_component(Args &&...args) {
    handle.add<_Ty>(std::forward<Args>(args)...);
    return handle.get_mut<_Ty>();
  }

  template <typename _Ty> _Ty &get_component() {
    return handle.get_mut<_Ty>();
  }
};

class Scene {
public:
  flecs::world world;
  String name;

  Scene() : name("Default Scene Name") {};
  Scene(const String &sceneName) : name(sceneName) {}

  Entity create_entity();
};

class System {
public:
  const str_hash sys_hash;
  System(const str_hash &systemHash) : sys_hash(systemHash) {}
  System(const String &systemName) : sys_hash(HashString(systemName)) {}

  /// <summary>
  /// Initialize callbacks and operations
  /// for component data which interacts with this sytem
  /// </summary>
  /// <param name="s"></param>
  virtual void init(Scene &s) = 0;

  /// <summary>
  /// Remove callbacks
  /// </summary>
  /// <param name="s"></param>
  virtual void cleanup(Scene &s) = 0;

  /// <summary>
  /// Return JSON representing the system state
  /// </summary>
  /// <param name="s">Scene to serialize</param>
  /// <returns>JSON representing the systems serializable state for all
  /// entities</returns>
  virtual json serialize(Scene &s) = 0;

  /// <summary>
  /// Given some json, deserialize and create appropriate components for a
  /// collection of entities
  /// </summary>
  /// <param name="s"></param>
  /// <param name="sceneJson"></param>
  virtual void deserialize(Scene &s, json sceneJson) = 0;

  /// <summary>
  /// Serialize all components on a given entity for this systems
  /// managed components
  /// </summary>
  /// <param name="s"></param>
  /// <param name="e"></param>
  /// <returns></returns>
  virtual json serialize_entity(Scene &s, Entity &e) = 0;

  /// <summary>
  /// Given some json, deserialize and create appropriate components for a
  /// single entity
  /// </summary>
  /// <param name="s">Scene to deserialize into</param>
  /// <param name="e">Entity to deserialize into</param>
  /// <param name="sceneJson">JSON to be deserialized</param>
  virtual void deserialize_entity(Scene &s, Entity &e, json sceneJson) = 0;

  static String get_entity_id_as_string(Entity &e);
  static uint64 get_entity_id_from_string(const String &entity);
};

} // namespace harmony