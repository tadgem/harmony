#include "Script/Lua/LuaHarmony.hpp"
#include "Core/Program.h"
#include "Core/Input.h"
#include "Core/Time.h"
#include "ECS/TransformSystem.h"
#include "ECS/TransformComponent.h"
#include "Script/Lua/LuaSystem.h"
#include "Script/Lua/LuaScriptEntity.h"
#include "Rendering/Views/RuntimeView.h"
#include "glm.hpp"
#include "glm/detail/type_mat3x3.hpp"
#include "Collision/CollisionShapes.h"
#include "Rendering/Debug/GfxDebug.h"
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"

glm::vec2 lua_Vec2Multiply(glm::vec2 &a, glm::vec2 &b) {
    return a * b;
}

glm::vec2 lua_Vec2Add(glm::vec2 &a, glm::vec2 &b) {
    return a + b;
}

glm::vec2 lua_Vec2Subtract(glm::vec2 &a, glm::vec2 &b) {
    return a - b;
}

glm::vec2 lua_Vec2MulF(glm::vec2 &a, float b) {
    return a * b;
}

glm::vec2 lua_Vec2Norm(glm::vec2 &a) {
    return glm::normalize(a);
}

float lua_Vec2Mag(glm::vec2 &a) {
    return glm::length(a);
}

glm::vec3 lua_Vec3Multiply(glm::vec3 &a, glm::vec3 &b) {
    return a * b;
}

glm::vec3 lua_Vec3Add(glm::vec3 &a, glm::vec3 &b) {
    return a + b;
}

glm::vec3 lua_Vec3Subtract(glm::vec3 &a, glm::vec3 &b) {
    return a - b;
}

glm::vec3 lua_Vec3MulF(glm::vec3 &a, float b) {
    return a * b;
}

glm::vec3 lua_Vec3Norm(glm::vec3 &a) {
    return glm::normalize(a);
}

float lua_Vec3Mag(glm::vec3 &a) {
    return glm::length(a);
}

glm::vec3 lua_Vec4Multiply(glm::vec3 &a, glm::vec3 &b) {
    return a * b;
}

glm::vec3 lua_Vec4Add(glm::vec3 &a, glm::vec3 &b) {
    return a + b;
}

glm::vec4 lua_Vec4Subtract(glm::vec4 &a, glm::vec4 &b) {
    return a - b;
}

glm::vec4 lua_Vec4MulF(glm::vec4 &a, float b) {
    return a * b;
}

glm::vec4 lua_Vec4Norm(glm::vec4 &a) {
    return glm::normalize(a);
}

float lua_Vec4Mag(glm::vec4 &a) {
    return glm::length(a);
}

float lua_Abs(float v) {
    return glm::abs(v);
}

float lua_Random() {
    return ((float) rand() / (RAND_MAX)) + 1;
}

harmony::Scene *lua_GetActiveScene() {
    auto sceneWr = harmony::Program::Get()->GetActiveScene();
    if (sceneWr.expired()) {
        return nullptr;
    }
    return sceneWr.lock().get();
}

harmony::Renderer *lua_GetRenderer() {
    auto prog = harmony::Program::Get();
    if (prog) {
        return &prog->m_Renderer;
    }
    return nullptr;
}

harmony::LuaScriptEntity lua_GetEntity() {
    auto lwr = harmony::Program::Get()->GetSystem<harmony::LuaSystem>();
    if (lwr.expired()) {
        return harmony::LuaScriptEntity();
    }

    return harmony::LuaScriptEntity(lua_GetActiveScene(), lwr.lock()->GetCurrentEntity());
}

void lua_LoadScene(const harmony::String &path) {
    harmony::Program::Get()->LoadScene(path);
}

void lua_OpenScene(uint32_t index) {
    harmony::Program::Get()->OpenScene(index);
}

harmony::ShaderProgram *lua_GetShader(const harmony::String &name) {
    auto r = lua_GetRenderer();
    if (r) {
        auto swr = r->GetShader(name);
        if (!swr.expired()) {
            auto s = swr.lock();
            return s.get();
        }
    }
    return nullptr;
}

harmony::View *lua_GetView(const harmony::String &viewName) {
    auto r = lua_GetRenderer();
    if (r) {
        auto vwr = r->GetView(viewName);
        if (!vwr.expired()) {
            auto v = vwr.lock();
            return v.get();
        }
    }
    return nullptr;
}

harmony::LuaScriptEntity lua_AddEntity() {
    auto scene = lua_GetActiveScene();
    if (scene) {
        return harmony::LuaScriptEntity(scene, scene->AddEntity().m_Handle);
    }
    return harmony::LuaScriptEntity();
}

harmony::LuaScriptEntity lua_GetViewEntity(harmony::View *view) {
    harmony::RuntimeView *rtv = static_cast<harmony::RuntimeView *>(view);
    if (rtv) {
        auto scene = lua_GetActiveScene();
        entt::entity cameraEntity = rtv->CameraEntity;

        if (view && rtv && scene) {
            return harmony::LuaScriptEntity(scene, cameraEntity);
        }
    }
    return harmony::LuaScriptEntity();
}

#if HARMONY_DEBUG

void lua_DrawLine(glm::vec3 b, glm::vec3 e) {
    harmony::GfxDebug::Get()->drawCylinder(harmony::GfxDebug::Channel::Editor, bx::Vec3(b.x, b.y, b.z),
                                           bx::Vec3(e.x, e.y, e.z), 0.05f);
}

#endif

union char_int {
    uint8_t chars[4];
    int32_t val;
};

#if HARMONY_DEBUG

void lua_DrawSphere(glm::vec3 p, float r) {
    harmony::GfxDebug::Get()->draw(harmony::GfxDebug::Channel::Editor, bx::Sphere{bx::Vec3(p.x, p.y, p.z), r});
}

#endif

#if HARMONY_DEBUG

void lua_SetColour(float r, float g, float b, float a) {
    char_int col;
    col.chars[0] = static_cast<uint8_t>(r);
    col.chars[1] = static_cast<uint8_t>(g);
    col.chars[2] = static_cast<uint8_t>(b);
    col.chars[3] = static_cast<uint8_t>(a);

    harmony::GfxDebug::Get()->setColor(harmony::GfxDebug::Channel::Editor, col.val);
}

#endif

void harmony::InitHarmony(sol::state &state) {
    sol::table h = state.create_named_table("harmony");
    sol::table i = state.create_named_table("input");
    sol::table t = state.create_named_table("time");
    sol::table m = state.create_named_table("math");
    InitGLM(state, m);
    InitHarmonyTime(state, t);
    InitHarmonyRendering(state, h);
    InitHarmonyInput(state, i);
    InitHarmonyECS(state, h);
#if HARMONY_DEBUG
    sol::table d = state.create_named_table("debug");
    InitHarmonyDebug(state, d);
#endif
}

#if HARMONY_DEBUG

void harmony::InitHarmonyDebug(sol::state &state, sol::table &h) {
    h["DrawLine"] = &lua_DrawLine;
    h["DrawSphere"] = &lua_DrawSphere;
    h["SetColour"] = &lua_SetColour;
}

#endif

void harmony::InitHarmonyAssets(sol::state &state, sol::table &h) {
    h.new_usertype<harmony::AssetHandle>("AssetHandle", "path", &AssetHandle::Path, "index", &AssetHandle::Index,
                                         "typeHash", &AssetHandle::TypeHash);
}

void harmony::InitHarmonyRendering(sol::state &state, sol::table &h) {
    auto viewDef = h.new_usertype<harmony::View>("View", "width", &harmony::View::m_Width, "height",
                                                 &harmony::View::m_Height);
    auto rendererDef = h.new_usertype<harmony::Renderer>("Renderer");

    auto shaderDef = h.new_usertype<harmony::ShaderProgram>("ShaderProgram", "name", &harmony::ShaderProgram::m_Name);

    auto pipelineStageRenderer = h.new_usertype<harmony::PipelineStageRenderer>("PipelineStageRenderer");

    auto attachmentTypeEnumDef = h.new_enum("AttachmentType",
                                            "UnknownAttachmentType", AttachmentType::UnknownAttachmentType,
                                            "RGBA8", AttachmentType::RGBA8,
                                            "RGBA16F", AttachmentType::RGBA16F,
                                            "RGBA32F", AttachmentType::RGBA32F,
                                            "RGBA", AttachmentType::RGBA,
                                            "Depth16f", AttachmentType::Depth16F,
                                            "Depth24f", AttachmentType::Depth24F,
                                            "Depth32f", AttachmentType::Depth32F,
                                            "Depth", AttachmentType::Depth
    );

    auto resolutionTypeEnumDef = h.new_enum("ResolutionType",
                                            "FullScale", Resolution::Type::FullScale,
                                            "HalfScale", Resolution::Type::HalfScale,
                                            "QuarterScale", Resolution::Type::QuarterScale,
                                            "EighthScale", Resolution::Type::EighthScale,
                                            "SixteenthScale", Resolution::Type::SixteenthScale,
                                            "Custom", Resolution::Type::Custom
    );

    // attachment type def
    auto attachmentDef = h.new_usertype<harmony::Attachment>("Attachment");

    // framebuffer def
    auto framebufferDef = h.new_usertype<harmony::PipelineV2>("Framebuffer");
    // virtual + real resolution
    // attachments
    // resolution type
    // name

    // Pipeline def
    auto pipelineDef = h.new_usertype<harmony::PipelineV2>("Pipeline");
    pipelineDef["AddPipelineStage"] = &harmony::PipelineV2::AddPipelineStage;
    pipelineDef["AddFramebuffer"] = &harmony::PipelineV2::AddFramebuffer;
    pipelineDef["GetOutputFramebuffer"] = &harmony::PipelineV2::GetOutputFramebuffer;
    pipelineDef["HasOutputFramebuffer"] = &harmony::PipelineV2::HasOutputFramebuffer;
    pipelineDef["SetOutputFramebuffer"] = &harmony::PipelineV2::SetOutputFramebuffer;

    // pipeline draw stage def
    auto pipelineDrawStageDef = h.new_usertype<harmony::PipelineDrawStage>("Pipeline");
    // basically just creation?

    // screen quad renderer type def

    // shader data source def (& ability to create one in Lua)

    // texture asset def

    // renderer
    rendererDef["GetViewPipeline"] = &harmony::Renderer::GetViewPipelineFromName;
    // get / add shader data source
    // get / add shader
    // get / add pipeline stage renderer
    h["GetRenderer"] = &lua_GetRenderer;
    h["GetView"] = &lua_GetView;
    h["GetViewEntity"] = &lua_GetViewEntity;
    h["GetShader"] = &lua_GetShader;
}

void harmony::InitHarmonyInput(sol::state &state, sol::table &h) {
    h.new_enum("GamePadButton",
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

    h.new_enum("GamePadStick",
               "LS", harmony::Gamepad::Stick::LS,
               "RS", harmony::Gamepad::Stick::RS
    );

    h.new_enum("GamePadTrigger",
               "LT", harmony::Gamepad::Trigger::LT,
               "RT", harmony::Gamepad::Trigger::RT
    );

    h.new_enum("MouseButton",
               "Left", harmony::Mouse::Button::Left,
               "Right", harmony::Mouse::Button::Right,
               "Middle", harmony::Mouse::Button::Middle
    );

    h.new_enum("Key",
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

void harmony::InitHarmonyECS(sol::state &state, sol::table &h) {
    // High level
    auto entityHandleDef = h.new_usertype<entt::entity>("EntityHandle");
    auto entityDef = h.new_usertype<harmony::LuaScriptEntity>("Entity", "handle", &harmony::Entity::m_Handle);
    auto registryDef = h.new_usertype<entt::registry>("Registry");
    auto sceneDef = h.new_usertype<harmony::Scene>("Scene", "name", &harmony::Scene::m_Name, "registry",
                                                   &harmony::Scene::m_Registry);

    h.new_usertype<harmony::TransformComponent>("Transform",
                                                "position", &TransformComponent::Position,
                                                "euler", &TransformComponent::Euler,
                                                "scale", &TransformComponent::Scale,
                                                "forward", &TransformComponent::Forward,
                                                "right", &TransformComponent::Right,
                                                "up", &TransformComponent::Up
    );

    h.new_usertype<harmony::MeshComponent>("Mesh",
                                           "mesh", &MeshComponent::MeshAsset,
                                           "castShadow", &MeshComponent::CastShadow
    );

    h.new_usertype<harmony::MaterialComponent>("Material");

    h.new_usertype<harmony::Camera>("Camera",
                                    "fov", &harmony::Camera::FOV,
                                    "nearClip", &harmony::Camera::NearClipPlane,
                                    "farClip", &harmony::Camera::FarClipPlane);

    h.new_usertype<harmony::CameraComponent>("CameraComponent",
                                             "cam", &harmony::CameraComponent::Cam);

    h.new_usertype<harmony::DirectionalLight>("DirectionalLight",
                                              "diffuse", &harmony::DirectionalLight::Diffuse,
                                              "ambient", &harmony::DirectionalLight::Ambient
    );

    h.new_usertype<harmony::PointLight>("PointLight",
                                        "diffuse", &harmony::PointLight::Diffuse,
                                        "ambient", &harmony::PointLight::Ambient,
                                        "radius", &harmony::PointLight::Radius,
                                        "intensity", &harmony::PointLight::Intensity
    );

    h.new_usertype<harmony::SpotLight>("SpotLight",
                                       "diffuse", &harmony::SpotLight::Diffuse,
                                       "ambient", &harmony::SpotLight::Ambient,
                                       "radius", &harmony::SpotLight::Radius,
                                       "angle", &harmony::SpotLight::Angle,
                                       "intensity", &harmony::SpotLight::Intensity
    );

    h.set_function("LoadScene", lua_LoadScene);
    h.set_function("OpenScene", lua_OpenScene);
    h.set_function("GetForegroundScene", lua_GetActiveScene);
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

}


void harmony::InitHarmonyTime(sol::state &state, sol::table &h) {
    h["GetFrameTime"] = &Time::GetFrameTime;
    h["GetFrameTimeUnscaled"] = &Time::GetFrameTimeUnscaled;
    h["GetTimeccale"] = &Time::GetTimeScale;
    h["SetTimescale"] = &Time::SetTimeScale;
}

void harmony::InitGLM(sol::state &state, sol::table &h) {
    auto vec2type = h.new_usertype<glm::vec2>("vec2", "x", &glm::vec2::x, "y", &glm::vec2::y);
    auto vec3type = h.new_usertype<glm::vec3>("vec3", "x", &glm::vec3::x, "y", &glm::vec3::y, "z", &glm::vec3::z);
    auto vec4type = h.new_usertype<glm::vec4>("vec4", "x", &glm::vec4::x, "y", &glm::vec4::y, "z", &glm::vec4::z, "z",
                                              &glm::vec4::w);

    // Todo add matrix support

    vec2type.set(sol::meta_function::multiplication, &lua_Vec2Multiply);
    vec2type.set(sol::meta_function::addition, &lua_Vec2Add);
    vec2type.set(sol::meta_function::subtraction, &lua_Vec2Subtract);
    vec2type.set("Normalize", &lua_Vec2Norm);
    vec2type.set("Multiply", &lua_Vec2MulF);
    vec2type.set("Magnitude", &lua_Vec2Mag);


    vec3type.set(sol::meta_function::multiplication, &lua_Vec3Multiply);
    vec3type.set(sol::meta_function::addition, &lua_Vec3Add);
    vec3type.set(sol::meta_function::subtraction, &lua_Vec3Subtract);
    vec3type.set("Normalize", &lua_Vec3Norm);
    vec3type.set("Multiply", &lua_Vec3MulF);
    vec3type.set("Magnitude", &lua_Vec3Mag);

    vec4type.set(sol::meta_function::multiplication, &lua_Vec4Multiply);
    vec4type.set(sol::meta_function::addition, &lua_Vec4Add);
    vec4type.set(sol::meta_function::subtraction, &lua_Vec4Subtract);
    vec4type.set("Normalize", &lua_Vec4Norm);
    vec4type.set("Multiply", &lua_Vec4MulF);
    vec4type.set("Magnitude", &lua_Vec4Mag);


    h["abs"] = lua_Abs;
    h["random"] = lua_Random;
}
