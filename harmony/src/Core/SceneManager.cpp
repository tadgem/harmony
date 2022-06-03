#include "Core/SceneManager.h"

harmony::SceneManager::SceneManager()
{
    p_ActiveScene = nullptr;
}

harmony::WeakRef<harmony::Scene> harmony::SceneManager::LoadScene(nlohmann::json sceneJson)
{
    return WeakRef<Scene>();
}

nlohmann::json harmony::SceneManager::SerializeScene(WeakRef<Scene> scene)
{
    return nlohmann::json();
}

harmony::WeakRef<harmony::Scene> harmony::SceneManager::GetActiveScene()
{
    return WeakRef<Scene>();
}
