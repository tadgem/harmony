#pragma once

#include "ECS/CameraComponent.h"
#include "ECS/Entity.h"
#include "ECS/LightComponents.h"
#include "ECS/MaterialComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/TransformComponent.h"

namespace harmony
{
	class Scene;
	class LuaScriptEntity : public Entity
	{
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
		bool Valid();

	protected:
		Scene *p_Scene;
	};
} // namespace harmony