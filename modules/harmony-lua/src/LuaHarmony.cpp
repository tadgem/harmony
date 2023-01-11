#include "LuaHarmony.hpp"
#include "Core/Program.h"
#include "Core/Input.h"
#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"
#include "LuaSystem.h"
#include "LuaScriptEntity.h"

harmony::Scene* lua_GetActiveScene()
{
	auto sceneWr = harmony::Program::Get()->GetActiveScene();
	if (sceneWr.expired())
	{
		return nullptr;
	}
	return sceneWr.lock().get();
}

harmony::LuaScriptEntity lua_GetEntity()
{
	auto lwr = harmony::Program::Get()->GetSystem<harmony::LuaSystem>();
	if (lwr.expired()) return harmony::LuaScriptEntity();

	return harmony::LuaScriptEntity(lua_GetActiveScene(), lwr.lock()->GetCurrentEntity() );
}

void lua_LoadScene(const std::string& path)
{
	harmony::Program::Get()->LoadScene(path);
}

void lua_OpenScene(uint32_t index)
{
	harmony::Program::Get()->OpenScene(index);
}


harmony::Entity lua_AddEntity()
{
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		return harmony::LuaScriptEntity(scene, scene->AddEntity().m_Handle);
	}
	return harmony::Entity();
}

void harmony::InitHarmony(sol::state& state)
{
	sol::table h = state.create_named_table("harmony");

	InitHarmonyInput(state, h);
	InitHarmonyECS(state, h);
}
	

void harmony::InitHarmonyAssets(sol::state& state, sol::table& h)
{
	h.new_usertype<harmony::AssetHandle>("assetHandle", "path", &AssetHandle::Path, "index", &AssetHandle::Index, "typeHash", &AssetHandle::TypeHash);
}

void harmony::InitHarmonyInput(sol::state& state, sol::table& h)
{
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
	// gamepad
	state.set_function("Input.GetGamepadButton", harmony::Input::GetGamepadButton);
	state.set_function("Input.GetGamepadButtonJustPressed", harmony::Input::GetGamepadButtonJustPressed);
	state.set_function("Input.GetGamepadButtonJustReleased", harmony::Input::GetGamepadButtonJustReleased);

	state.set_function("Input.GetGamepadTrigger", &harmony::Input::GetGamepadTrigger);
	state.set_function("Input.GetGamepadStick", &harmony::Input::GetGamepadStick);

	// keyboard
	state.set_function("Input.GetKey", &harmony::Input::GetKey);
	state.set_function("Input.GetKeyJustPressed", &harmony::Input::GetKeyJustPressed);
	state.set_function("Input.GetKeyJustReleased", &harmony::Input::GetKeyJustReleased);

	// mouse
	state.set_function("Input.GetMousePosition", &harmony::Input::GetMousePosition);
	state.set_function("Input.GetMousePositionLastFrame", &harmony::Input::GetMousePositionLastFrame);
	state.set_function("Input.GetMouseVelocity", &harmony::Input::GetMouseVelocity);
	state.set_function("Input.GetMouseVelocityLastFrame", &harmony::Input::GetMouseVelocityLastFrame);

	state.set_function("Input.GetMouseButton", &harmony::Input::GetMouseButton);
	state.set_function("Input.GetMouseButtonJustPressed", &harmony::Input::GetMouseButtonJustPressed);
	state.set_function("Input.GetMouseButtonJustReleased", &harmony::Input::GetMouseButtonJustReleased);

}

void harmony::InitHarmonyECS(sol::state& state, sol::table& h)
{
	// High level
	auto entityHandleDef	= h.new_usertype<entt::entity>("entity_handle");
	auto entityDef		= h.new_usertype<harmony::LuaScriptEntity>("entity", "handle", &harmony::Entity::m_Handle);
	auto registryDef		= h.new_usertype<entt::registry>("registry");
	auto sceneDef			= h.new_usertype<harmony::Scene>("scene", "name", &harmony::Scene::m_Name, "registry", &harmony::Scene::m_Registry);

	h.new_usertype<harmony::TransformComponent>("transform", 
		"position", &TransformComponent::Position, 
		"euler", &TransformComponent::Euler, 
		"scale",&TransformComponent::Scale
		);

	h.new_usertype<harmony::MeshComponent>("mesh",
		"asset", &MeshComponent::MeshAsset,
		"castShadow", &MeshComponent::CastShadow
		);

	h.new_usertype<harmony::MaterialComponent>("material");

	h.new_usertype<harmony::Camera>("camera", 
		"fov", &harmony::Camera::FOV, 
		"nearClip", &harmony::Camera::NearClipPlane, 
		"farClip", &harmony::Camera::FarClipPlane);

	h.new_usertype<harmony::CameraComponent>("cameraComponent",
		"cam", &harmony::CameraComponent::Cam);

	h.new_usertype<harmony::DirectionalLight>("directionalLight", 
		"diffuse", &harmony::DirectionalLight::Diffuse, 
		"ambient", &harmony::DirectionalLight::Ambient
		);

	h.new_usertype<harmony::PointLight>("pointLight", 
		"diffuse", &harmony::PointLight::Diffuse, 
		"ambient", &harmony::PointLight::Ambient, 
		"radius", &harmony::PointLight::Radius, 
		"intensity", &harmony::PointLight::Intensity
		);

	h.new_usertype<harmony::SpotLight>("spotLight",
		"diffuse", &harmony::SpotLight::Diffuse,
		"ambient", &harmony::SpotLight::Ambient,
		"radius", &harmony::SpotLight::Radius,
		"angle", &harmony::SpotLight::Angle ,
		"intensity", &harmony::SpotLight::Intensity
		);

	h.set_function("LoadScene", lua_LoadScene);
	h.set_function("OpenScene", lua_OpenScene);
	h.set_function("GetScene", lua_GetActiveScene);
	h.set_function("GetEntity", lua_GetEntity);

	sceneDef["AddEntity"] = lua_AddEntity;

	entityDef["GetTransform"] = &harmony::LuaScriptEntity::GetTransform;
	entityDef["SetTransform"] = &harmony::LuaScriptEntity::SetTransform;

	entityDef["GetCamera"] = &harmony::LuaScriptEntity::GetCamera;
	entityDef["SetCamera"] = &harmony::LuaScriptEntity::SetCamera;

	entityDef["GetMesh"] = &harmony::LuaScriptEntity::GetMesh;
	entityDef["SetMesh"] = &harmony::LuaScriptEntity::SetMesh;

	entityDef["GetMaterial"] = &harmony::LuaScriptEntity::GetMaterial;
	entityDef["SetMaterial"] = &harmony::LuaScriptEntity::SetMaterial;
}
