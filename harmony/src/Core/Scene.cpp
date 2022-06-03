#include "Core/Scene.h"
#include "Core/Profile.hpp"

harmony::Scene::Scene()
{
	HARMONY_PROFILE_FUNCTION()
}

void harmony::Scene::UpdateSceneSystemSerializationAttributes(std::vector<Ref<System>>& systems)
{
	nlohmann::json sceneJson;
	for (int i = 0; i < systems.size(); i++)
	{
		Ref<System> system = systems[i];
		nlohmann::json sceneSystemJson = system->SerializeSystem(m_Registry);
	}
}
