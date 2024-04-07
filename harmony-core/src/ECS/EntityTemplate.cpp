//
// Created by liam_ on 12/30/2023.
//
#include "ECS/EntityTemplate.h"
#include "Core/Scene.h"
#include "ECS/System.h"
#include "STL/HashMap.h"
#include "STL/Algorithm.h"
#include "Core/Program.h"



void harmony::EntityTemplate::AddComponentData(uint32_t entity, HashString systemTypeHash, Json entityJson)
{
	if (entityJson.empty())
	{
		return;
	}

	if (m_TemplateData.find(entity) == m_TemplateData.end())
	{
		m_TemplateData.emplace(entity, SingleEntityTemplateData {});
	}

	if (m_TemplateData[entity].find(systemTypeHash) != m_TemplateData[entity].end())
	{
		m_TemplateData[entity][systemTypeHash] = entityJson;
		return;
	}

	m_TemplateData[entity].emplace(systemTypeHash, entityJson);
}


void RecurseEntityTemplateDataCollect(harmony::Scene* scene, harmony::Vector<entt::entity>& templateEntities, entt::entity e)
{
	if (harmony::Find(templateEntities.begin(), templateEntities.end(), e) == templateEntities.end())
	{
		templateEntities.push_back(e);
	}

	auto children = scene->GetChildEntities(e);

	for (entt::entity& e : children)
	{
		RecurseEntityTemplateDataCollect(scene, templateEntities, e);
	}
}

harmony::EntityTemplate harmony::EntityTemplate::CreateEntityTemplate(WeakPtr<Scene> scene, entt::entity e)
{
	auto s = scene.lock();
	if (!s)
	{
		return {};
	}

	EntityTemplate t;
	Vector<entt::entity> templateEntities;

	// get all entities
	RecurseEntityTemplateDataCollect(s.get(), templateEntities, e);

	// serialize each entity see ^^
	for (auto& sys : Program::Get()->GetSystems())
	{
		for (entt::entity templateEntity : templateEntities)
		{
			t.AddComponentData(static_cast<uint32_t>(templateEntity), sys->m_TypeHash, sys->SerializeEntity(s->m_Registry, templateEntity));
		}
	}
	return t;
}

harmony::WeakPtr<harmony::EntityTemplate> harmony::EntityTemplate::SaveEntityTemplate(WeakPtr<Scene> scene, entt::entity e, String name)
{
	EntityTemplate et = CreateEntityTemplate(scene, e);
	Json templateJson = et;
	Utils::SaveJsonToPath(templateJson, name);

	AssetManager& assetManager = Program::Get()->m_AssetManager;

	Vector<AssetHandle> assetHandles = assetManager.LoadAsset<EntityTemplate>(name);
	if (assetHandles.empty())
	{
		log::warn("Program : Failed to open entity template at path {}", name);
		return {};
	}

	return assetManager.GetAsset<EntityTemplate>(assetHandles.front());
}

void harmony::EntityTemplate::LoadEntityTemplate( WeakPtr<Scene> scene, WeakPtr<EntityTemplate> entityTemplate)
{
	RefCntPtr<Scene> s = scene.lock();
	RefCntPtr<EntityTemplate> et = entityTemplate.lock();

	if (!s || !et)
	{
		return;
	}

	HashMap<uint32_t, entt::entity> idMapping;

		// for each entity in the data
		for (auto& [entityId, entityTemplateData] : et->m_TemplateData)
		{
			entt::entity e = s->m_Registry.create();
			idMapping.emplace(entityId, e);
			for (auto& sys : Program::Get()->GetSystems())
			{
				// if entity data has system data, deserialize
				if (entityTemplateData.find(sys->m_TypeHash.m_Value) != entityTemplateData.end())
				{
					sys->DeserializeEntity(s->m_Registry, e, entityTemplateData[sys->m_TypeHash.m_Value]);
				}
			}
		}

	// update child entities
	for (auto& [oldIndex, newEntity] : idMapping)
	{
		EntityData& data = s->m_Registry.get<EntityData>(newEntity);
		uint32_t parentIndex = static_cast<uint32_t>(data.m_Parent);

		if (idMapping.find(parentIndex) != idMapping.end())
		{
			data.m_Parent = static_cast<uint32_t>(idMapping[parentIndex]);
		}
			
	}
}

harmony::Json harmony::EntityTemplate::ToJSON()
{
	return *this;
}

void harmony::EntityTemplate::FromJSON(const Json& input)
{
	*this = input;
}
