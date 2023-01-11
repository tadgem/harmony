#include "LuaHarmony.hpp"
#include "Core/Program.h"
#include "Core/Input.h"
#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"
#include "LuaSystem.h"
harmony::Entity lua_GetEntity()
{
	auto lwr = harmony::Program::Get()->GetSystem<harmony::LuaSystem>();
	if (lwr.expired()) return harmony::Entity();

	return harmony::Entity(lwr.lock()->GetCurrentEntity() );
}

void lua_LoadScene(const std::string& path)
{
	harmony::Program::Get()->LoadScene(path);
}

void lua_OpenScene(uint32_t index)
{
	harmony::Program::Get()->OpenScene(index);
}

harmony::Scene* lua_GetActiveScene()
{
	auto sceneWr = harmony::Program::Get()->GetActiveScene();
	if (sceneWr.expired())
	{
		return nullptr;
	}
	return sceneWr.lock().get();
}

harmony::Entity lua_AddEntity()
{
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		return scene->AddEntity();
	}
	return harmony::Entity();
}

glm::vec3 lua_GetEntityPosition()
{
	auto e = lua_GetEntity();
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		if (scene->m_Registry.any_of<harmony::TransformComponent>(e.m_Handle))
		{
			auto t = scene->m_Registry.get<harmony::TransformComponent>(e.m_Handle);
			return t.Position;
		}
	}
	return glm::vec3();
}

void lua_SetEntityPosition(glm::vec3 position)
{
	auto e = lua_GetEntity();
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		if (scene->m_Registry.any_of<harmony::TransformComponent>(e.m_Handle))
		{
			auto& t = scene->m_Registry.get<harmony::TransformComponent>(e.m_Handle);
			t.Position = position;
		}
	}
}

glm::vec3 lua_GetEntityEuler()
{
	auto e = lua_GetEntity();
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		if (scene->m_Registry.any_of<harmony::TransformComponent>(e.m_Handle))
		{
			auto t = scene->m_Registry.get<harmony::TransformComponent>(e.m_Handle);
			return t.Euler;
		}
	}
	return glm::vec3();
}

void lua_SetEntityEuler(glm::vec3 euler)
{
	auto e = lua_GetEntity();
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		if (scene->m_Registry.any_of<harmony::TransformComponent>(e.m_Handle))
		{
			auto& t = scene->m_Registry.get<harmony::TransformComponent>(e.m_Handle);
			t.Euler = euler;
		}
	}
}

glm::vec3 lua_GetEntityScale()
{
	auto e = lua_GetEntity();
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		if (scene->m_Registry.any_of<harmony::TransformComponent>(e.m_Handle))
		{
			auto t = scene->m_Registry.get<harmony::TransformComponent>(e.m_Handle);
			return t.Scale;
		}
	}
	return glm::vec3();
}

void lua_SetEntityScale(glm::vec3 scale)
{
	auto e = lua_GetEntity();
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		if (scene->m_Registry.any_of<harmony::TransformComponent>(e.m_Handle))
		{
			auto& t = scene->m_Registry.get<harmony::TransformComponent>(e.m_Handle);
			t.Scale = scale;
		}
	}
}

void harmony::InitHarmony(sol::state& state)
{
	sol::table h = state.create_named_table("harmony");

	h.new_enum("gamePadButton",
		"FaceNorth", harmony::Gamepad::Button::FaceNorth,
		"FaceEast", harmony::Gamepad::Button::FaceEast,
		"FaceSouth", harmony::Gamepad::Button::FaceSouth,
		"FaceWest", harmony::Gamepad::Button::FaceWest,
		"Up", harmony::Gamepad::Button::Up,
		"Right", harmony::Gamepad::Button::Right,
		"Down", harmony::Gamepad::Button::Down,
		"Left", harmony::Gamepad::Button::Left,
		"RB", harmony::Gamepad::Button::RightBumper,
		"LB", harmony::Gamepad::Button::LeftBumper,
		"Home", harmony::Gamepad::Button::Home,
		"Back", harmony::Gamepad::Button::Select,
		"Start", harmony::Gamepad::Button::Start
		);

	h.new_enum("gamePadStick",
		"LS", harmony::Gamepad::Stick::LS,
		"RS", harmony::Gamepad::Stick::RS
	);

	h.new_enum("gamePadTrigger",
		"LT", harmony::Gamepad::Trigger::LT,
		"RT", harmony::Gamepad::Trigger::RT
	);

	h.new_enum("mouseButton",
		"Left", harmony::Mouse::Button::Left,
		"Right", harmony::Mouse::Button::Right,
		"Middle", harmony::Mouse::Button::Middle
	);

	h.new_enum("key",
		"A", A,
		"B", B,
		"C", C,
		"D", D,
		"E", E,
		"F", F,
		"G", G,
		"H", H,
		"I", I,
		"J", J,
		"K", K,
		"L", L,
		"M", M,
		"N", N,
		"O", O,
		"P", P,
		"Q", Q,
		"R", R,
		"S", S,
		"T", T,
		"U", U,
		"V", V,
		"W", W,
		"X", X,
		"Y", Y,
		"Z", Z,
		"Zero", Zero,
		"One", One,
		"Two", Two,
		"Three", Three,
		"Four", Four,
		"Five", Five,
		"Six", Six,
		"Seven", Seven,
		"Eight", Eight,
		"Nine", Nine,
		"Minus", Minus,
		"Underscore", Underscore,
		"Equals", Equals,
		"Plus", Plus,
		"Backspace", Backspace,
		"Enter", Enter,
		"Space", Space,
		"Tab", Tab,
		"CapsLock", CapsLock,
		"Tilde", Tilde,
		"LeftShift", LeftShift,
		"LeftControl", LeftControl,
		"LeftAlt", LeftAlt,
		"RightShift", RightShift,
		"RightControl", RightControl,
		"RightAlt", RightAlt,
		"F1", F1,
		"F2", F2,
		"F3", F3,
		"F4", F4,
		"F5", F5,
		"F6", F6,
		"F7", F7,
		"F8", F8,
		"F9", F9,
		"F10", F10,
		"F11", F11,
		"F12", F12,
		"Insert", Insert,
		"Home", Home,
		"PageUp", PageUp,
		"PageDown", PageDown,
		"Delete", Delete,
		"End", End,
		"Up", Up,
		"Down", Down,
		"Left", Left,
		"Right", Right
		);

	// High level
	auto entityHandleDef	= h.new_usertype<entt::entity>("entity_handle");
	auto entityDef		= h.new_usertype<harmony::Entity>("entity", "handle", &harmony::Entity::m_Handle);
	auto registryDef		= h.new_usertype<entt::registry>("registry");
	auto sceneDef			= h.new_usertype<harmony::Scene>("scene", "name", &harmony::Scene::m_Name, "registry", &harmony::Scene::m_Registry);

	h.set_function("LoadScene", lua_LoadScene);
	h.set_function("OpenScene", lua_OpenScene);
	h.set_function("GetScene", lua_GetActiveScene);
	h.set_function("GetEntity", lua_GetEntity);

	h.set_function("Input.GetKey", harmony::Input::GetGamepadButton);

	sceneDef["AddEntity"] = lua_AddEntity;

	entityDef["GetPosition"]	= lua_GetEntityPosition;
	entityDef["SetPosition"]	= lua_SetEntityPosition;
	entityDef["GetEuler"]		= lua_GetEntityEuler;
	entityDef["SetEuler"]		= lua_SetEntityEuler;
	entityDef["GetScale"]		= lua_GetEntityScale;
	entityDef["SetScale"]		= lua_SetEntityScale;
}
