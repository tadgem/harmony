#pragma once
#include "Core/Scene.h"
#include "Core/Memory.h"
namespace harmony
{
    class SceneManager
    {
    public:
        SceneManager();

        WeakRef<Scene> LoadScene(nlohmann::json sceneJson);
        nlohmann::json SerializeScene(WeakRef<Scene> scene);

        WeakRef<Scene> GetActiveScene();

    protected:
        std::vector<Ref<Scene>> p_Scenes;
        Ref<Scene> p_ActiveScene;
    };
};