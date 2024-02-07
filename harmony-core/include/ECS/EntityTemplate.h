//
// Created by liam_ on 12/30/2023.
//

#pragma once
#include "Core/Alias.h"
#include "Assets/TextAsset.h"
#include "Assets/AssetManager.h"

namespace harmony
{
	class System;
	class Scene;
	using EntityTemplateData = HashMap<uint64_t, nlohmann::json>;
	class EntityTemplate : public JSONAsset
	{
	public:
		static EntityTemplate CreateEntityTemplate(Vector<RefCntPtr<System>> systems, WeakPtr<Scene> scene, entt::entity e);
		static WeakPtr<EntityTemplate> SaveEntityTemplate(Vector<RefCntPtr<System>> systems, AssetManager& assetManager, WeakPtr<Scene> scene, entt::entity e, String name);
		static void LoadEntityTemplate(Vector<RefCntPtr<System>> systems, WeakPtr<Scene> scene, WeakPtr<EntityTemplate> entityTemplate);

		HashMap<uint64_t, EntityTemplateData> m_EntityData;

		virtual nlohmann::json ToJSON() override;
		virtual void FromJSON(const nlohmann::json& input) override;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(EntityTemplate, m_EntityData)
	};
}