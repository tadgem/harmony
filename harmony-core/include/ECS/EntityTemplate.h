//
// Created by liam_ on 12/30/2023.
//

#pragma once
#include "STL/HashMap.h"
#include "STL/Json.hpp"
#include "STL/Memory.h"
#include "Assets/TextAsset.h"
#include "Assets/AssetManager.h"

namespace harmony
{
	class System;
	class Scene;

	using SingleEntityTemplateData = HashMap<uint64_t, Json>;

	class EntityTemplate : public JSONAsset
	{
	public:
		void AddComponentData(uint32_t entity, HashString systemTypeHash, Json entityJson);

		static EntityTemplate			CreateEntityTemplate(WeakPtr<Scene> scene, entt::entity e);
		static WeakPtr<EntityTemplate>	SaveEntityTemplate(WeakPtr<Scene> scene, entt::entity e, String name);
		static void						LoadEntityTemplate(WeakPtr<Scene> scene, WeakPtr<EntityTemplate> entityTemplate);

		HashMap<uint32_t, SingleEntityTemplateData> m_TemplateData;

		virtual Json ToJSON() override;
		virtual void FromJSON(const Json& input) override;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(EntityTemplate, m_TemplateData)
	};
}