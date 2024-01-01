//
// Created by liam_ on 12/30/2023.
//

#pragma once
#include "Core/Alias.h"
#include "Assets/TextAsset.h"

namespace harmony
{
	class EntityTemplate : public JSONAsset
	{
	public:
		void AddComponentData(HashString systemTypeHash, nlohmann::json entityJson);

		HashMap<uint64_t, nlohmann::json> m_ComponentData;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(EntityTemplate, m_ComponentData)
	};
}