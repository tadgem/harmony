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
		void AddComponentData(HashString systemTypeHash, Json entityJson);

		static EntityTemplate CreateEntityTemplate(Vector<RefCntPtr<System>> systems, WeakPtr<Scene> scene, entt::entity e);
		static WeakPtr<EntityTemplate> SaveEntityTemplate(Vector<RefCntPtr<System>> systems, AssetManager& assetManager, WeakPtr<Scene> scene, entt::entity e, String name);
		static void LoadEntityTemplate(Vector<RefCntPtr<System>> systems, WeakPtr<Scene> scene, WeakPtr<EntityTemplate> entityTemplate);

		SingleEntityTemplateData m_ComponentData;

		virtual Json ToJSON() override;
		virtual void FromJSON(const Json& input) override;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE(EntityTemplate, m_ComponentData)
	};
}