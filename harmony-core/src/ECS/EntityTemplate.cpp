//
// Created by liam_ on 12/30/2023.
//
#include "ECS/EntityTemplate.h"

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

nlohmann::json harmony::EntityTemplate::ToJSON()
{
	return *this;
}

void harmony::EntityTemplate::FromJSON(const nlohmann::json& input)
{
	*this = input;
}
