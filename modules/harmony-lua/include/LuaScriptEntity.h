#pragma once
#include "ECS/Entity.h"
#include "ECS/TransformComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/CameraComponent.h"
#include "ECS/MaterialComponent.h"
#include "ECS/LightComponents.h"

namespace harmony
{
	class Scene;
	class LuaScriptEntity : public Entity
	{
	public:
		LuaScriptEntity();
		LuaScriptEntity(Scene* scene, entt::entity entity);

		TransformComponent*	GetTransform();
		void				SetTransform(TransformComponent* t);

		MeshComponent*		GetMesh();
		void				SetMesh(MeshComponent* m);

		CameraComponent*		GetCamera();
		void				SetCamera(CameraComponent* c);

		MaterialComponent*	GetMaterial();
		void				SetMaterial(MaterialComponent* c);

		bool Valid();
	protected:
		Scene* p_Scene;
	};
}