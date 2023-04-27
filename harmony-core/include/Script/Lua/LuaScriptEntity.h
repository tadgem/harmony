#pragma once

#include "ECS/Entity.h"
#include "ECS/TransformComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/CameraComponent.h"
#include "ECS/MaterialComponent.h"
#include "ECS/LightComponents.h"
#include "ECS/SimpleCollisionComponent.h"

namespace harmony {
    class Scene;

    class LuaScriptEntity : public Entity {
    public:
        LuaScriptEntity();

        LuaScriptEntity(Scene *scene, entt::entity entity);

        void Destroy();

        TransformComponent *AddTransform();

        TransformComponent *GetTransform();

        void SetTransform(TransformComponent *t);

        MeshComponent *AddMesh();

        MeshComponent *GetMesh();

        void SetMesh(MeshComponent *m);

        CameraComponent *AddCamera();

        CameraComponent *GetCamera();

        void SetCamera(CameraComponent *c);

        MaterialComponent *AddMaterial();

        MaterialComponent *GetMaterial();

        void SetMaterial(MaterialComponent *c);

        AABBColliderComponent *AddAABB();

        AABBColliderComponent *GetAABB();

        void SetAABB(AABBColliderComponent *c);

        SphereColliderComponent *AddSphere();

        SphereColliderComponent *GetSphere();

        void SetSphere(SphereColliderComponent *c);

        bool Valid();

    protected:
        Scene *p_Scene;
    };
}