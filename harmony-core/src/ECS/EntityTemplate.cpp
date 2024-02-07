//
// Created by liam_ on 12/30/2023.
//
#include "ECS/EntityTemplate.h"
#include "Core/Scene.h"
#include "ECS/System.h"


void RecurseEntityHierarchy(harmony::WeakPtr<harmony::Scene> scene, harmony::HashMap<uint32_t, uint32_t>& hierarchy, const uint32_t e)
{
	using namespace harmony;
	
	
	auto s = scene.lock();

	if (!s)
	{
		// log an error?
		return;
	}

	auto children = s->GetChildEntities((entt::entity)e);

	for (entt::entity childEntity : children)
	{
		uint32_t child = (uint32_t)childEntity;
		if (hierarchy.find(child) != hierarchy.end())
		{
			log::error("EntityTemplate :: RecurseEntityHierarchy :: hierarchy already contains an entry for entity {}, what is happening?", e);
			continue;
		}

		hierarchy.emplace(child, e);
		RecurseEntityHierarchy(scene, hierarchy, child);
	}

}

harmony::EntityTemplate harmony::EntityTemplate::CreateEntityTemplate(Vector<RefCntPtr<System>> systems, WeakPtr<Scene> scene, entt::entity e)
{
	auto s = scene.lock();
	if (!s)
	{
		return {};
	}

	HashMap<uint32_t, uint32_t> hierarchy = {};

	RecurseEntityHierarchy(scene, hierarchy, (uint32_t)e);


	// get all entities that are children
	// create a mapping of entity to parent
	// where no parent == UINT32_MAX
	// do we need this encoding in the serialized data?

	EntityTemplate t;

	for (auto& sys : systems)
	{
		// t.AddComponentData(sys->m_TypeHash, sys->SerializeEntity(s->m_Registry, e));
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
		//if (et->m_ComponentData.find(sys->m_TypeHash.m_Value) != et->m_ComponentData.end())
		{
			//sys->DeserializeEntity(s->m_Registry, e, et->m_ComponentData[sys->m_TypeHash.m_Value]);
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
