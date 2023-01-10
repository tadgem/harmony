#include "LuaHarmony.hpp"
#include "Core/Program.h"
#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"

void lua_LoadScene(const std::string& path)
{
	harmony::Program::Get()->LoadScene(path);
}

void lua_OpenScene(uint32_t index)
{
	harmony::Program::Get()->OpenScene(index);
}

harmony::Scene* lua_GetActiveScene()
{
	auto sceneWr = harmony::Program::Get()->GetActiveScene();
	if (sceneWr.expired())
	{
		return nullptr;
	}
	return sceneWr.lock().get();
}

entt::entity lua_AddEntity()
{
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		return scene->AddEntity().m_Handle;
	}
	return entt::entity();
}


void harmony::InitHarmony(sol::state& state)
{
	sol::table h = state.create_named_table("harmony");

	// High level
	auto entityDef = h.new_usertype<entt::entity>("entity");
	auto registryDef	= h.new_usertype<entt::registry>("registry");
	auto sceneDef		= h.new_usertype<harmony::Scene>("scene", "name", &harmony::Scene::m_Name, "registry", &harmony::Scene::m_Registry);

	h.set_function("LoadScene", lua_LoadScene);
	h.set_function("OpenScene", lua_OpenScene);
	h.set_function("GetScene", lua_GetActiveScene);

	sceneDef["AddEntity"] = lua_AddEntity;
}
