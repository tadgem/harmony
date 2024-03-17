//
// Created by liam_ on 12/30/2023.
//
#include "ECS/EntityTemplate.h"
#include "Core/Scene.h"
#include "ECS/System.h"

void harmony::EntityTemplate::AddComponentData(HashString systemTypeHash, nlohmann::json entityJson)
{
	if(entityJson.empty())
	{
		return;
	}

	if(m_ComponentData.find(systemTypeHash) != m_ComponentData.end())
	{
		m_ComponentData[systemTypeHash] = entityJson;
		return;
	}

	m_ComponentData.emplace(systemTypeHash, entityJson);
}

harmony::EntityTemplate harmony::EntityTemplate::CreateEntityTemplate(Vector<RefCntPtr<System>> systems, WeakPtr<Scene> scene, entt::entity e)
{
	auto s = scene.lock();
	if (!s)
	{
		return {};
	}

	EntityTemplate t;

	for (auto& sys : systems)
	{
		t.AddComponentData(sys->m_TypeHash, sys->SerializeEntity(s->m_Registry, e));
	}
	return t;
}

harmony::WeakPtr<harmony::EntityTemplate> harmony::EntityTemplate::SaveEntityTemplate(Vector<RefCntPtr<System>> systems, AssetManager& assetManager, WeakPtr<Scene> scene, entt::entity e, String name)
{
	EntityTemplate et = CreateEntityTemplate(systems, scene, e);
	nlohmann::json templateJson = et;
	Utils::SaveJsonToPath(templateJson, name);

	Vector<AssetHandle> assetHandles = assetManager.LoadAsset<EntityTemplate>(name);
	if (assetHandles.empty())
	{
		log::warn("Program : Failed to open entity template at path {}", name);
		return {};
	}

	return assetManager.GetAsset<EntityTemplate>(assetHandles[0]);
}

void harmony::EntityTemplate::LoadEntityTemplate(Vector<RefCntPtr<System>> systems, WeakPtr<Scene> scene, WeakPtr<EntityTemplate> entityTemplate)
{
	RefCntPtr<Scene> s = scene.lock();
	RefCntPtr<EntityTemplate> et = entityTemplate.lock();

	if (!s || !et)
	{
		return;
	}

	entt::entity e = s->m_Registry.create();

	for (auto& sys : systems)
	{
		if (et->m_ComponentData.find(sys->m_TypeHash.m_Value) != et->m_ComponentData.end())
		{
			sys->DeserializeEntity(s->m_Registry, e, et->m_ComponentData[sys->m_TypeHash.m_Value]);
		}
	}
}

nlohmann::json harmony::EntityTemplate::ToJSON()
{
	return *this;
}

void harmony::EntityTemplate::FromJSON(const nlohmann::json& input)
{
	*this = input;
}
