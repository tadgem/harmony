#include "LuaHarmony.hpp"
#include "Core/Program.h"
#include "Core/Input.h"
#include "Core/Time.h"
#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"
#include "LuaSystem.h"
#include "LuaScriptEntity.h"
#include "Rendering/Views/RuntimeView.h"
#include "glm.hpp"
#include "glm/detail/type_mat3x3.hpp"
#include "ECS/SimpleCollisionSystem.h"
#include "ECS/SimpleCollisionComponent.h"
#include "Collision/CollisionShapes.h"
#include "Rendering/Debug/GfxDebug.h"


glm::vec2 lua_Vec2Multiply(glm::vec2& a, glm::vec2& b)
{
	return a * b;
}

glm::vec2 lua_Vec2Add(glm::vec2& a, glm::vec2& b)
{
	return a + b;
}

glm::vec2 lua_Vec2Subtract(glm::vec2& a, glm::vec2& b)
{
	return a - b;
}

glm::vec2 lua_Vec2MulF(glm::vec2& a, float b)
{
	return a * b;
}

glm::vec3 lua_Vec3Multiply(glm::vec3& a, glm::vec3& b)
{
	return a * b;
}

glm::vec3 lua_Vec3Add(glm::vec3& a, glm::vec3& b)
{
	return a + b;
}
glm::vec3 lua_Vec3Subtract(glm::vec3& a, glm::vec3& b)
{
	return a - b;
}

glm::vec3 lua_Vec3MulF(glm::vec3& a, float b)
{
	return a * b;
}

glm::vec3 lua_Vec4Multiply(glm::vec3& a, glm::vec3& b)
{
	return a * b;
}

glm::vec3 lua_Vec4Add(glm::vec3& a, glm::vec3& b)
{
	return a + b;
}

glm::vec4 lua_Vec4Subtract(glm::vec4& a, glm::vec4& b)
{
	return a - b;
}

glm::vec4 lua_Vec4MulF(glm::vec4& a, float b)
{
	return a * b;
}

float lua_Abs(float v)
{
	return glm::abs(v);
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

harmony::Renderer* lua_GetRenderer()
{
	auto prog = harmony::Program::Get();
	if (prog)
	{
		return &prog->m_Renderer;
	}
	return nullptr;
}

harmony::SimpleCollisionSystem* lua_GetCollisionSystem()
{
	auto prog = harmony::Program::Get();

	if (prog)
	{
		auto sysWr = prog->GetSystem<harmony::SimpleCollisionSystem>();
		if (!sysWr.expired())
		{
			return sysWr.lock().get();
		}
	}

	return nullptr;
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

harmony::View* lua_GetView(const std::string& viewName)
{
	auto r = lua_GetRenderer();
	if (r)
	{
		auto vwr = r->GetView(viewName);
		if (!vwr.expired())
		{
			auto v = vwr.lock();
			return v.get();
		}
	}
	return nullptr;
}

harmony::LuaScriptEntity lua_AddEntity()
{
	auto scene = lua_GetActiveScene();
	if (scene)
	{
		return harmony::LuaScriptEntity(scene, scene->AddEntity().m_Handle);
	}
	return harmony::LuaScriptEntity();
}

harmony::LuaScriptEntity lua_GetViewEntity(harmony::View* view)
{
	harmony::RuntimeView* rtv = static_cast<harmony::RuntimeView*>(view);
	if (rtv)
	{
		auto scene = lua_GetActiveScene();
		entt::entity cameraEntity = rtv->CameraEntity;

		if (view && rtv && scene)
		{
			return harmony::LuaScriptEntity(scene, cameraEntity);
		}
	}
	return harmony::LuaScriptEntity();
}

std::vector<harmony::Hit> lua_Raycast(glm::vec3 origin, glm::vec3 dir)
{
	auto collisionSystem = lua_GetCollisionSystem();
	auto scene = lua_GetActiveScene();

	auto hits = std::vector<harmony::Hit>();

	if (scene && collisionSystem)
	{
		harmony::Ray ray{ origin, dir };
		return collisionSystem->Raycast(ray, scene->m_Registry);
	}

	return hits;
}

#if HARMONY_DEBUG
void lua_DrawLine(glm::vec3 b, glm::vec3 e)
{
	harmony::GfxDebug::Get()->drawCapsule(harmony::GfxDebug::Channel::Editor, bx::Vec3(b.x, b.y, b.z), bx::Vec3(e.x, e.y, e.z), 0.1f);
}
#endif

union char_int
{
	uint8_t chars[4];
	int32_t val;
};

#if HARMONY_DEBUG
void lua_DrawSphere(glm::vec3 p, float r)
{
	harmony::GfxDebug::Get()->draw(harmony::GfxDebug::Channel::Editor, bx::Sphere{ bx::Vec3(p.x, p.y, p.z), r });
}
#endif

#if HARMONY_DEBUG
void lua_SetColour(float r, float g, float b, float a)
{

	char_int col;
	col.chars[0] = r;
	col.chars[1] = g;
	col.chars[2] = b;
	col.chars[3] = a;

	harmony::GfxDebug::Get()->setColor(harmony::GfxDebug::Channel::Editor,col.val);
}
#endif

void harmony::InitHarmony(sol::state& state)
{
	sol::table h = state.create_named_table("harmony");
	sol::table i = state.create_named_table("input");
	sol::table t = state.create_named_table("time");
	sol::table m = state.create_named_table("math");
	sol::table c = state.create_named_table("collision");
	sol::table d = state.create_named_table("debug");
	InitGLM(state, m);
	InitHarmonyTime(state, t);
	InitHarmonyRendering(state, h);
	InitHarmonyInput(state, i);
	InitHarmonyECS(state, h);
	InitHarmonyCollision(state, c);
#if HARMONY_DEBUG
	InitHarmonyDebug(state, d);
#endif
}
#if HARMONY_DEBUG
void harmony::InitHarmonyDebug(sol::state& state, sol::table& h)
{
	h["DrawLine"] = &lua_DrawLine;
	h["DrawSphere"] = &lua_DrawSphere;
	h["SetColour"] = &lua_SetColour;
}
#endif


// script 'Modules'

void harmony::InitHarmonyAssets(sol::state& state, sol::table& h)
{
	h.new_usertype<harmony::AssetHandle>("assetHandle", "path", &AssetHandle::Path, "index", &AssetHandle::Index, "typeHash", &AssetHandle::TypeHash);
}

void harmony::InitHarmonyRendering(sol::state& state, sol::table& h)
{
	auto viewDef = h.new_usertype<harmony::View>("view", "width", &harmony::View::m_Width, "height", &harmony::View::m_Height);
	auto rendererDef = h.new_usertype<harmony::Renderer>("renderer");
	h["GetRenderer"] = &lua_GetRenderer;
	h["GetView"] = &lua_GetView;
	h["GetViewEntity"] = &lua_GetViewEntity;
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
		"A", harmony::Key::A,
		"B", harmony::Key::B,
		"C", harmony::Key::C,
		"D", harmony::Key::D,
		"E", harmony::Key::E,
		"F", harmony::Key::F,
		"G", harmony::Key::G,
		"H", harmony::Key::H,
		"I", harmony::Key::I,
		"J", harmony::Key::J,
		"K", harmony::Key::K,
		"L", harmony::Key::L,
		"M", harmony::Key::M,
		"N", harmony::Key::N,
		"O", harmony::Key::O,
		"P", harmony::Key::P,
		"Q", harmony::Key::Q,
		"R", harmony::Key::R,
		"S", harmony::Key::S,
		"T", harmony::Key::T,
		"U", harmony::Key::U,
		"V", harmony::Key::V,
		"W", harmony::Key::W,
		"X", harmony::Key::X,
		"Y", harmony::Key::Y,
		"Z", harmony::Key::Z,
		"Zero", harmony::Key::Zero,
		"One", harmony::Key::One,
		"Two", harmony::Key::Two,
		"Three", harmony::Key::Three,
		"Four", harmony::Key::Four,
		"Five", harmony::Key::Five,
		"Six", harmony::Key::Six,
		"Seven", harmony::Key::Seven,
		"Eight", harmony::Key::Eight,
		"Nine", harmony::Key::Nine,
		"Minus", harmony::Key::Minus,
		"Underscore", harmony::Key::Underscore,
		"Equals", harmony::Key::Equals,
		"Plus", harmony::Key::Plus,
		"Backspace", harmony::Key::Backspace,
		"Enter", harmony::Key::Enter,
		"Space", harmony::Key::Space,
		"Tab", harmony::Key::Tab,
		"CapsLock", harmony::Key::CapsLock,
		"Tilde", harmony::Key::Tilde,
		"LeftShift", harmony::Key::LeftShift,
		"LeftControl", harmony::Key::LeftControl,
		"LeftAlt", harmony::Key::LeftAlt,
		"RightShift", harmony::Key::RightShift,
		"RightControl", harmony::Key::RightControl,
		"RightAlt", harmony::Key::RightAlt,
		"F1", harmony::Key::F1,
		"F2", harmony::Key::F2,
		"F3", harmony::Key::F3,
		"F4", harmony::Key::F4,
		"F5", harmony::Key::F5,
		"F6", harmony::Key::F6,
		"F7", harmony::Key::F7,
		"F8", harmony::Key::F8,
		"F9", harmony::Key::F9,
		"F10", harmony::Key::F10,
		"F11", harmony::Key::F11,
		"F12", harmony::Key::F12,
		"Insert", harmony::Key::Insert,
		"Home", harmony::Key::Home,
		"PageUp", harmony::Key::PageUp,
		"PageDown", harmony::Key::PageDown,
		"Delete", harmony::Key::Delete,
		"End", harmony::Key::End,
		"Up", harmony::Key::Up,
		"Down", harmony::Key::Down,
		"Left", harmony::Key::Left,
		"Right", harmony::Key::Right
	);

	// gamepad
	h["GetGamepadButton"] = harmony::Input::GetGamepadButton;
	h["GetGamepadButtonJustPressed"] = harmony::Input::GetGamepadButtonJustPressed;
	h["GetGamepadButtonJustReleased"] = harmony::Input::GetGamepadButtonJustReleased;
	h["GetGamepadTrigger"] = &harmony::Input::GetGamepadTrigger;
	h["GetGamepadStick"] = &harmony::Input::GetGamepadStick;

	h["GetKey"] = &harmony::Input::GetKey;
	h["GetKeyJustPressed"] = &harmony::Input::GetKeyJustPressed;
	h["GetKeyJustReleased"] = &harmony::Input::GetKeyJustReleased;
	
	h["GetMousePosition"] = &harmony::Input::GetMousePosition;
	h["GetMousePositionLastFrame"] = &harmony::Input::GetMousePositionLastFrame;
	h["GetMouseVelocity"] = &harmony::Input::GetMouseVelocity;
	h["GetMouseVelocityLastFrame"] = &harmony::Input::GetMouseVelocityLastFrame;
	h["GetMouseButton"] = &harmony::Input::GetMouseButton;
	h["GetMouseButtonJustPressed"] = &harmony::Input::GetMouseButtonJustPressed;
	h["GetMouseButtonJustReleased"] = &harmony::Input::GetMouseButtonJustReleased;

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
		"scale", &TransformComponent::Scale,
		"forward", &TransformComponent::Forward,
		"right", &TransformComponent::Right,
		"up", &TransformComponent::Up
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

	h.new_usertype<harmony::AABBColliderComponent>("aabb",
		"colliders", &AABBColliderComponent::m_Colliders
		);

	h.new_usertype<harmony::SphereColliderComponent>("sphere",
		"colliders",&SphereColliderComponent::m_Colliders
		);

	h.set_function("LoadScene", lua_LoadScene);
	h.set_function("OpenScene", lua_OpenScene);
	h.set_function("GetScene", lua_GetActiveScene);
	h.set_function("GetEntity", lua_GetEntity);

	sceneDef["AddEntity"] = lua_AddEntity;

	entityDef["Destroy"] = &harmony::LuaScriptEntity::Destroy;

	entityDef["AddTransform"] = &harmony::LuaScriptEntity::AddTransform;
	entityDef["GetTransform"] = &harmony::LuaScriptEntity::GetTransform;
	entityDef["SetTransform"] = &harmony::LuaScriptEntity::SetTransform;

	entityDef["AddCamera"] = &harmony::LuaScriptEntity::AddCamera;
	entityDef["GetCamera"] = &harmony::LuaScriptEntity::GetCamera;
	entityDef["SetCamera"] = &harmony::LuaScriptEntity::SetCamera;

	entityDef["AddMesh"] = &harmony::LuaScriptEntity::AddMesh;
	entityDef["GetMesh"] = &harmony::LuaScriptEntity::GetMesh;
	entityDef["SetMesh"] = &harmony::LuaScriptEntity::SetMesh;

	entityDef["AddMaterial"] = &harmony::LuaScriptEntity::AddMaterial;
	entityDef["GetMaterial"] = &harmony::LuaScriptEntity::GetMaterial;
	entityDef["SetMaterial"] = &harmony::LuaScriptEntity::SetMaterial;

	entityDef["AddAABB"] = &harmony::LuaScriptEntity::AddAABB;
	entityDef["GetAABB"] = &harmony::LuaScriptEntity::GetAABB;
	entityDef["SetAABB"] = &harmony::LuaScriptEntity::SetAABB;

	entityDef["AddSphere"] = &harmony::LuaScriptEntity::AddSphere;
	entityDef["GetSphere"] = &harmony::LuaScriptEntity::GetSphere;
	entityDef["SetSphere"] = &harmony::LuaScriptEntity::SetSphere;
}

void harmony::InitHarmonyCollision(sol::state& state, sol::table& h)
{
	h.new_usertype<harmony::SimpleCollisionSystem>("collision");
	h.new_usertype<harmony::Ray>("ray", "origin", &harmony::Ray::Origin, "direction", &harmony::Ray::Direction);
	h.new_usertype<harmony::Hit>("hit", "position", &harmony::Hit::Position, "hit", &harmony::Hit::DidHit);
	h["raycast"] = &lua_Raycast;
}

void harmony::InitHarmonyTime(sol::state& state, sol::table& h)
{
	h["GetFrameTime"]			= &Time::GetFrameTime;
	h["GetFrameTimeUnscaled"]	= &Time::GetFrameTimeUnscaled;
	h["GetTimeScale"]			= &Time::GetTimeScale;
	h["GetTimescale"]			= &Time::SetTimeScale;
}

void harmony::InitGLM(sol::state& state, sol::table& h)
{
	auto vec2type = h.new_usertype<glm::vec2>("vec2", "x", &glm::vec2::x, "y", &glm::vec2::y);
	auto vec3type = h.new_usertype<glm::vec3>("vec3", "x", &glm::vec3::x, "y", &glm::vec3::y, "z", &glm::vec3::z);
	auto vec4type = h.new_usertype<glm::vec4>("vec4", "x", &glm::vec4::x, "y", &glm::vec4::y, "z", &glm::vec4::z, "z", &glm::vec4::w);

	h["addVec2"]	= lua_Vec2Add;
	h["subVec2"]	= lua_Vec2Subtract;
	h["mulVec2"]	= lua_Vec2Multiply;
	h["mulVec2f"]	= lua_Vec2MulF;
	h["addVec3"]	= lua_Vec3Add;
	h["subVec3"]	= lua_Vec3Subtract;
	h["mulVec3"]	= lua_Vec3Multiply;
	h["mulVec3f"]	= lua_Vec3MulF;
	h["addVec4"]	= lua_Vec4Add;
	h["subVec4"]	= lua_Vec4Subtract;
	h["mulVec4"]	= lua_Vec4Multiply;
	h["mulVec4f"]	= lua_Vec4MulF;

	h["abs"] = lua_Abs;
}
