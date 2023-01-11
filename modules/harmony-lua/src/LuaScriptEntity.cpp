#include "LuaScriptEntity.h"

harmony::LuaScriptEntity::LuaScriptEntity()
{
	p_Scene		= nullptr;
	m_Handle	= entt::entity();
}

harmony::LuaScriptEntity::LuaScriptEntity(Scene* scene, entt::entity entity) : Entity(entity)
{
	p_Scene = scene;
}

harmony::TransformComponent harmony::LuaScriptEntity::GetTransform()
{
	if (Valid())
	{
		if (p_Scene->m_Registry.any_of<TransformComponent>(m_Handle))
		{
			return p_Scene->m_Registry.get<TransformComponent>(m_Handle);
		}
	}
	
	return harmony::TransformComponent();
	
}

void harmony::LuaScriptEntity::SetTransform(TransformComponent t)
{
	if (Valid())
	{
		if (p_Scene->m_Registry.any_of<TransformComponent>(m_Handle))
		{
			auto& trans =  p_Scene->m_Registry.get<TransformComponent>(m_Handle);
			trans = t;
		}
	}
}

harmony::MeshComponent harmony::LuaScriptEntity::GetMesh()
{
	if (Valid())
	{
		if (p_Scene->m_Registry.any_of<MeshComponent>(m_Handle))
		{
			return p_Scene->m_Registry.get<MeshComponent>(m_Handle);
		}
	}

	return harmony::MeshComponent();
}

void harmony::LuaScriptEntity::SetMesh(MeshComponent m)
{
	if (Valid())
	{
		if (p_Scene->m_Registry.any_of<MeshComponent>(m_Handle))
		{
			auto& mesh = p_Scene->m_Registry.get<MeshComponent>(m_Handle);
			mesh= m;
		}
	}
}

harmony::CameraComponent harmony::LuaScriptEntity::GetCamera()
{
	if (Valid())
	{
		if (p_Scene->m_Registry.any_of<CameraComponent>(m_Handle))
		{
			return p_Scene->m_Registry.get<CameraComponent>(m_Handle);
		}
	}

	return harmony::CameraComponent();
}

void harmony::LuaScriptEntity::SetCamera(CameraComponent c)
{
	if (Valid())
	{
		if (p_Scene->m_Registry.any_of<CameraComponent>(m_Handle))
		{
			auto& cam = p_Scene->m_Registry.get<CameraComponent>(m_Handle);
			cam = c;
		}
	}
}

harmony::MaterialComponent harmony::LuaScriptEntity::GetMaterial()
{
	if (Valid())
	{
		if (p_Scene->m_Registry.any_of<MaterialComponent>(m_Handle))
		{
			return p_Scene->m_Registry.get<MaterialComponent>(m_Handle);
		}
	}

	return harmony::MaterialComponent();
}

void harmony::LuaScriptEntity::SetMaterial(MaterialComponent c)
{
	if (Valid())
	{
		if (p_Scene->m_Registry.any_of<MaterialComponent>(m_Handle))
		{
			auto& mat = p_Scene->m_Registry.get<MaterialComponent>(m_Handle);
			mat = c;
		}
	}
}

bool harmony::LuaScriptEntity::Valid()
{
	return p_Scene != nullptr;
}
