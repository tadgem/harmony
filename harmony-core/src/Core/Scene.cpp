#include "Core/Scene.h"
#include "Core/Profile.hpp"

harmony::Scene::Scene()
{
	HARMONY_PROFILE_FUNCTION()
}

harmony::Scene::Scene(const std::string& name) : m_Name(name)
{
	HARMONY_PROFILE_FUNCTION()
}

void harmony::Scene::Deserialize(std::vector<Ref<System>>& systems)
{
	HARMONY_PROFILE_FUNCTION()
	for (int i = 0; i < p_Entities.size(); i++)
	{
		m_Registry.create(p_Entities[i].m_Handle);
	}

	for (auto& [systemTypeHash, json] : p_SystemSerializationAttributes)
	{
		for (int i = 0; i < systems.size(); i++)
		{
			if (systems[i]->m_TypeHash == systemTypeHash)
			{
				systems[i]->DeserializeSystem(m_Registry, json);
				break;
			}
		}
	}
}

void harmony::Scene::UpdateSceneSystemSerializationAttributes(std::vector<Ref<System>>& systems)
{
	HARMONY_PROFILE_FUNCTION()
	p_SystemSerializationAttributes.clear();
	
	for (int i = 0; i < systems.size(); i++)
	{
		Ref<System> system = systems[i];
		nlohmann::json sceneSystemJson = system->SerializeSystem(m_Registry);
		p_SystemSerializationAttributes.emplace(system->m_TypeHash, sceneSystemJson);
	}
	m_NumEntities = m_Registry.size();
}

harmony::Entity harmony::Scene::AddEntity()
{
	HARMONY_PROFILE_FUNCTION()
	entt::entity e = m_Registry.create();
	Entity entity = Entity();
	entity.m_Handle = e;
	p_Entities.emplace_back(entity);
	return entity;
}