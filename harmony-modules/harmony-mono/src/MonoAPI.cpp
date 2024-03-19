//
// Created by liam_ on 9/24/2023.
//
#include "MonoAPI.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "Core/Program.h"
#include "Core/Alias.h"
#include "Core/Input.h"
#include "ECS/TransformComponent.h"
#include "ECS/MeshComponent.h"
#include "ECS/MaterialComponent.h"
#include "ECS/SkyComponent.h"
#include "ECS/CameraComponent.h"
#include "ECS/LightComponents.h"
#include "ThirdParty/entt.hpp"
#include "Rendering/VectorGraphics/VectorGraphics.h"
#include "MonoUtils.h"
#include "Rendering/Debug/GfxDebug.h"
#include "MonoSystem.h"
#include "MonoProgramComponent.h"
#include "Rendering/Mesh.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/View.h"
#include "Rendering/Pipelines/PipelineV2.h"
#include "Rendering/Pipelines/PipelineStages/PipelineDrawStage.h"
#include "Rendering/Pipelines/PipelineStageRenderers/ScreenQuadRenderer.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipelines/PipelineStages/SkyStage.h"
#include "Rendering/Pipelines/PipelineStages/DrawScreenTextureStage.h"
#include "Rendering/Pipelines/BuiltIn/DebugDrawPipeline.h"
#include "Rendering/Pipelines/BuiltIn/VectorPipeline.h"
#include "Rendering/Shaders/ShaderDataSources/TextureAssetSource.h"
#include "Rendering/Shaders/ShaderDataSources/DeferredDataSource.h"
#include "Rendering/Shaders/ShaderDataSources/BlinnPhongDataSource.h"

#define MONO_GET_COMPONENT_IMPL(T) if(!scene) return nullptr;\
\
entt::entity& entity = (entt::entity&)e;\
\
if (!scene->m_Registry.any_of<T>(entity))\
{\
	return nullptr;\
}\
\
return &scene->m_Registry.get<T>(entity);\

static MonoClass* s_AssetHandleClass = nullptr;
static MonoClass* s_AttachmentTypeClass = nullptr;

void GetTypesForArrays()
{
    auto mono = harmony::Program::Get()->
        GetProgramComponent<harmony::MonoProgramComponent>().lock();

    MonoType* rrt = mono->GetType(harmony::String("Harmony.AssetHandle"));
    
    if (rrt == nullptr)
    {
        harmony::log::error("MonoAPI::GetTypesForArrays: failed to get asset handle type from image");
    } else
    {
        s_AssetHandleClass = mono_type_get_class(rrt);
    }

    rrt = mono->GetType(harmony::String("Harmony.AttachmentType"));

    if (rrt == nullptr)
    {
        harmony::log::error("MonoAPI::GetTypesForArrays: failed to get attachment type type from image");
    }
    else
    {
        s_AttachmentTypeClass = mono_type_get_class(rrt);
    }

}

void harmony_mono_log_trace(MonoString *str) {
    harmony::log::trace("C# : {}", harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_info(MonoString *str) {
    harmony::log::info("C# : {}", harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_warn(MonoString *str) {
    harmony::log::warn("C# : {}", harmony::MonoUtils::GetStringFromMonoString(str));
}

void harmony_mono_log_error(MonoString *str) {
    harmony::log::error("C# : {}", harmony::MonoUtils::GetStringFromMonoString(str));
}

double harmony_mono_get_frame_time() {
    return harmony::Time::GetFrameTime();
}

double harmony_mono_get_frame_time_unscaled() {
    return harmony::Time::GetFrameTimeUnscaled();
}

double harmony_mono_get_time_scale() {
    return harmony::Time::GetTimeScale();
}

void harmony_mono_set_time_scale(double newTimeScale)
{
    harmony::Time::SetTimeScale(newTimeScale);
}

entt::registry* harmony_mono_internal_get_active_reg()
{
    auto scene = harmony_mono_get_active_scene();
    if(scene)
    {
        return &scene->m_Registry;
    }
    return nullptr;
}

harmony::Program *harmony_mono_get_program() {
    return harmony::Program::Get();
}

harmony::MonoProgramComponent* harmony_get_mono() {
    return harmony::Program::Get()->GetProgramComponent<harmony::MonoProgramComponent>().lock().get();
}

entt_entity harmony_entity_default()
{
	return (entt_entity)UINT32_MAX;
}

harmony::ProgramComponent* harmony_mono_get_program_component(const uint64_t type_hash)
{
    const harmony::WeakPtr<harmony::ProgramComponent> wr = harmony::Program::Get()->GetProgramComponent(harmony::HashString(type_hash));
    if (wr.expired()) {
        // also need to check mono implemented program components
        return nullptr;
    }
    return wr.lock().get();
}


harmony::Scene *harmony_mono_get_active_scene() {
    // TODO error checking
    auto sr =  harmony::Program::Get()->GetActiveScene().lock();

    if(!sr)
    {
        return nullptr;
    }
    return sr.get();
}

void harmony_mono_close_active_scene() {
    harmony::Program::Get()->CloseActiveScene();
}

void harmony_mono_load_scene(MonoString *path) {
    harmony::Program::Get()->LoadScene(harmony::MonoUtils::GetStringFromMonoString(path));
}

void harmony_mono_save_scene(MonoString *path) {
    harmony::Program::Get()->SaveScene(harmony::MonoUtils::GetStringFromMonoString(path));
}

entt_entity harmony_mono_create_entity(harmony::Scene* scene)
{
    entt_entity ret = { UINT32_MAX };
    if (scene)
    {
        auto e = scene->AddEntity();
        ret = (entt_entity) e.m_Handle;
    }

    return ret;
}

entt_entity harmony_mono_get_entity_by_id(harmony::Scene* scene, uint32_t index)
{
    entt_entity e = harmony_entity_default();
    if (!scene)
    {
        return e;

    }

    if (!scene->m_Registry.valid((entt::entity)e))
    {
        return e;
    }

	e = index;
    return e;
}

entt_entity harmony_mono_get_entity_by_name(harmony::Scene* scene, MonoString* name)
{
    using namespace harmony;

    if (!scene)
    {
        return harmony_entity_default();
    }

    String c_name = MonoUtils::GetStringFromMonoString(name);

    auto data_view = scene->m_Registry.view<EntityData>();

    for (auto [e, data] : data_view.each())
    {
        if (data.m_Name == c_name)
        {
            return (entt_entity)e;
        }
    }

    return harmony_entity_default();
}

void harmony_mono_delete_entity(harmony::Scene* scene, entt_entity e)
{
    if (scene)
    {
        scene->m_Registry.destroy((entt::entity)e);
    }
}

MonoArray* harmony_mono_get_entity_script_behaviours(harmony::Scene* scene, entt_entity e)
{    
    MonoArray* arr = nullptr;
    if (scene)
    {
        auto mono = harmony::Program::Get()->
            GetProgramComponent<harmony::MonoProgramComponent>().lock();

        if (scene->m_Registry.any_of<harmony::MonoBehaviourComponent>((entt::entity)e))
        {
            harmony::MonoBehaviourComponent& monoBehaviour = scene->m_Registry.get<harmony::MonoBehaviourComponent>((entt::entity)e);
            uint32_t numBehaviours = monoBehaviour.m_Behaviours.size();
            arr = mono_array_new(mono->GetAppDomain(), mono_get_object_class(), numBehaviours);

            for (int i = 0; i < numBehaviours; i++)
            {
                mono_array_set(arr, MonoObject*, i, monoBehaviour.m_Behaviours[i].m_Object);
            }
        }
    }

    return arr;
}

glm_vec2    harmony_mono_get_mouse_position(){
    auto pos = harmony::Input::GetMousePosition();
    return glm_vec2 {pos.x, pos.y};
}

glm_vec2    harmony_mono_get_mouse_position_last_frame(){
    auto pos = harmony::Input::GetMousePositionLastFrame();
    return glm_vec2 {pos.x, pos.y};
}

glm_vec2    harmony_mono_get_mouse_velocity(){
    auto vel = harmony::Input::GetMouseVelocity();
    return glm_vec2 {vel.x, vel.y};
}

glm_vec2    harmony_mono_get_mouse_velocity_last_frame(){
    auto vel = harmony::Input::GetMouseVelocityLastFrame();
    return glm_vec2 {vel.x, vel.y};
}

bool        harmony_mono_get_mouse_button(harmony_mouse_button button){
    harmony::Mouse::Button b = static_cast<harmony::Mouse::Button>(button);
    return harmony::Input::GetMouseButton(b);

}

bool        harmony_mono_get_mouse_button_just_pressed(harmony_mouse_button button){
    harmony::Mouse::Button b = static_cast<harmony::Mouse::Button>(button);
    return harmony::Input::GetMouseButtonJustPressed(b);
}

bool        harmony_mono_get_mouse_button_just_released(harmony_mouse_button button){
    harmony::Mouse::Button b = static_cast<harmony::Mouse::Button>(button);
    return harmony::Input::GetMouseButtonJustReleased(b);
}

bool        harmony_mono_get_key(harmony_keyboard_key key){
    harmony::Key k = static_cast<harmony::Key>(key);
    return harmony::Input::GetKey(k);

}

bool        harmony_mono_get_key_just_pressed(harmony_keyboard_key key){
    harmony::Key k = static_cast<harmony::Key>(key);
    return harmony::Input::GetKeyJustPressed(k);
}

bool        harmony_mono_get_key_just_released(harmony_keyboard_key key){
    harmony::Key k = static_cast<harmony::Key>(key);
    return harmony::Input::GetKeyJustReleased(k);
}

bool        harmony_mono_get_gamepad_button(int gamepad_index, harmony_gamepad_button button){
    harmony::Gamepad::Button b = static_cast<harmony::Gamepad::Button>(button);
    return harmony::Input::GetGamepadButton(gamepad_index,b);
}

bool        harmony_mono_get_gamepad_button_just_pressed(int gamepad_index, harmony_gamepad_button button){
    harmony::Gamepad::Button b = static_cast<harmony::Gamepad::Button>(button);
    return harmony::Input::GetGamepadButtonJustPressed(gamepad_index,b);
}

bool        harmony_mono_get_gamepad_button_just_released(int gamepad_index, harmony_gamepad_button button){
    harmony::Gamepad::Button b = static_cast<harmony::Gamepad::Button>(button);
    return harmony::Input::GetGamepadButtonJustReleased(gamepad_index,b);
}

bx::Vec3 glm_to_bx_vec3(glm_vec3& v)
{
    return bx::Vec3(v.x, v.y, v.z);
}

void harmony_mono_debug_draw_set_colour(harmony_debug_draw_channel channel, uint32_t rgba)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->setColor(c, rgba);
}

void harmony_mono_debug_draw_set_stipple(harmony_debug_draw_channel channel, bool stipple, float scale, float offset)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->setStipple(c, stipple, scale, offset);
}

void harmony_mono_debug_draw_set_wireframe(harmony_debug_draw_channel channel, bool wireframe)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->setWireframe(c, wireframe);
}

void harmony_mono_debug_draw_set_translate(harmony_debug_draw_channel channel, glm_vec3 t)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->setTranslate(c, t.x, t.y, t.z);
}

void harmony_mono_debug_draw_move_to(harmony_debug_draw_channel channel, glm_vec3 t)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->moveTo(c, t.x, t.y, t.z);
}

void harmony_mono_debug_draw_line_to(harmony_debug_draw_channel channel, glm_vec3 t)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->lineTo(c, t.x, t.y, t.z);
}

void harmony_mono_debug_draw_circle(harmony_debug_draw_channel channel, glm_vec3 normal, glm_vec3 center, float radius, float weight)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->drawCircle(c, glm_to_bx_vec3(normal), glm_to_bx_vec3(center), radius, weight);
}

void harmony_mono_debug_draw_quad(harmony_debug_draw_channel channel, glm_vec3 normal, glm_vec3 center, float size)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->drawQuad(c, glm_to_bx_vec3(normal), glm_to_bx_vec3(center), size);
}

void harmony_mono_debug_draw_sphere(harmony_debug_draw_channel channel, glm_vec3 center, float radius)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    bx::Sphere s{ glm_to_bx_vec3(center), radius };
    dd->draw(c, s);
}

void harmony_mono_debug_draw_cylinder(harmony_debug_draw_channel channel, glm_vec3 from, glm_vec3 to, float radius)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->drawCylinder(c, glm_to_bx_vec3(from), glm_to_bx_vec3(to), radius);
}

void harmony_mono_debug_draw_capsule(harmony_debug_draw_channel channel, glm_vec3 from, glm_vec3 to, float radius)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->drawCapsule(c, glm_to_bx_vec3(from), glm_to_bx_vec3(to), radius);
}

void harmony_mono_debug_draw_cone(harmony_debug_draw_channel channel, glm_vec3 from, glm_vec3 to, float radius)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->drawCone(c, glm_to_bx_vec3(from), glm_to_bx_vec3(to), radius);
}

void harmony_mono_debug_draw_grid(harmony_debug_draw_channel channel, glm_vec3 normal, glm_vec3 center, uint32_t size, float step)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->drawGrid(c, glm_to_bx_vec3(normal), glm_to_bx_vec3(center), size, step);
}

void harmony_mono_debug_draw_orb(harmony_debug_draw_channel channel, glm_vec3 center, float radius)
{
    auto* dd = harmony::GfxDebug::Get();
    harmony::GfxDebug::Channel c = (harmony::GfxDebug::Channel)channel;
    dd->drawOrb(c, center.x, center.y, center.z, radius);
}


float       harmony_mono_get_gamepad_trigger(int gamepad_index, harmony_gamepad_trigger trigger){
    harmony::Gamepad::Trigger t = static_cast<harmony::Gamepad::Trigger>(trigger);
    return harmony::Input::GetGamepadTrigger(gamepad_index,t);
}

glm_vec2    harmony_mono_get_gamepad_stick(int gamepad_index, harmony_gamepad_stick stick){
    harmony::Gamepad::Stick s = static_cast<harmony::Gamepad::Stick>(stick);
    glm::vec2 v = harmony::Input::GetGamepadStick(gamepad_index,s);
    return glm_vec2{v.x, v.y};
}

harmony::TransformComponent *harmony_mono_get_transform(harmony::Scene *scene, entt_entity e) {
    MONO_GET_COMPONENT_IMPL(harmony::TransformComponent)
}

void harmony_mono_set_transform_position(harmony::TransformComponent *t, glm_vec3 position) {
    if(!t) return;

    t->Position = glm::vec3(position.x, position.y, position.z);
}

void harmony_mono_set_transform_euler(harmony::TransformComponent *t, glm_vec3 euler) {
    if(!t) return;

    t->Euler = glm::vec3(euler.x, euler.y, euler.z);
}

void harmony_mono_set_transform_scale(harmony::TransformComponent *t, glm_vec3 scale) {
    if(!t) return;

    t->Scale = glm::vec3(scale.x, scale.y, scale.z);
}

glm_vec3 harmony_mono_get_transform_position    (harmony::TransformComponent* t)
{
    if(!t) return harmony_glm_vec3_default();
    return glm_vec3 {t->Position.x, t->Position.y, t->Position.z};
}
glm_vec3 harmony_mono_get_transform_euler       (harmony::TransformComponent* t)
{
    if(!t) return harmony_glm_vec3_default();
    return glm_vec3 {t->Euler.x, t->Euler.y, t->Euler.z};
}
glm_vec3 harmony_mono_get_transform_scale       (harmony::TransformComponent* t)
{
    if(!t) return harmony_glm_vec3_default();
    return glm_vec3 {t->Scale.x, t->Scale.y, t->Scale.z};
}

asset_handle harmony_asset_handle_default() {
    return asset_handle{ nullptr, UINT32_MAX, UINT64_MAX };
}


glm_vec2 harmony_glm_vec2_default() {
    return glm_vec2{0.0f, 0.0f};
}

glm_vec3 harmony_glm_vec3_default() {
    return glm_vec3{0.0f, 0.0f, 0.0f};
}

glm_vec4 harmony_glm_vec4_default() {
	return glm_vec4{ 0.0f, 0.0f, 0.0f, 0.0f };
}

glm_vec3 harmony_mono_get_transform_forward(harmony::TransformComponent *t) {
    if(!t) return harmony_glm_vec3_default();
    return glm_vec3 {t->Forward.x, t->Forward.y, t->Forward.z};
}

glm_vec3 harmony_mono_get_transform_right(harmony::TransformComponent *t) {
    if(!t) return harmony_glm_vec3_default();
    return glm_vec3 {t->Right.x, t->Right.y, t->Right.z};
}

glm_vec3 harmony_mono_get_transform_up(harmony::TransformComponent *t) {
    if(!t) return harmony_glm_vec3_default();
    return glm_vec3 {t->Up.x, t->Up.y, t->Up.z};
}

harmony::MeshComponent* harmony_mono_get_mesh(harmony::Scene* scene, entt::entity e)
{
    MONO_GET_COMPONENT_IMPL(harmony::MeshComponent)
}

void harmony_mono_mesh_set_asset(harmony::MeshComponent* mesh, asset_handle asset)
{
    using namespace harmony;
    if (!mesh)
    {
        return;
    }

    if (!asset.path)
    {
        return;
    }

    String assetPath = MonoUtils::GetStringFromMonoString(asset.path);
    AssetHandle ah{ assetPath, asset.index, asset.type_hash };

    RefCntPtr<Mesh> m = Program::Get()->m_AssetManager.GetAsset<Mesh>(ah).lock();

    if (!m)
    {
        return;
    }

    mesh->MeshAsset = ah;
    mesh->MeshHandle = m->m_Handle;
}

asset_handle harmony_mono_mesh_get_asset(harmony::MeshComponent* mesh)
{
    if (!mesh) return harmony_asset_handle_default();
    return asset_handle{
        mono_string_new(harmony_get_mono()->GetAppDomain(), mesh->MeshAsset.Path.c_str()),
        mesh->MeshAsset.Index,
        mesh->MeshAsset.TypeHash
    };
}

harmony::MaterialComponent* harmony_mono_get_material(harmony::Scene* scene, entt::entity e)
{
    MONO_GET_COMPONENT_IMPL(harmony::MaterialComponent)
}

harmony::DirectionalLight* harmony_mono_get_directional_light(harmony::Scene* scene, entt::entity e)
{
    MONO_GET_COMPONENT_IMPL(harmony::DirectionalLight)
}

void harmony_mono_directional_light_set_diffuse(harmony::DirectionalLight* l, glm_vec4 diffuse)
{
    if (!l)
    {
        return;
    }

    l->Diffuse = glm::vec4(diffuse.x, diffuse.y, diffuse.z, diffuse.w);
}

void harmony_mono_directional_light_set_ambient(harmony::DirectionalLight* l, glm_vec4 ambient)
{
	if (!l)
	{
		return;
	}

	l->Ambient = glm::vec4(ambient.x, ambient.y, ambient.z, ambient.w);
}

glm_vec4 harmony_mono_directional_light_get_diffuse(harmony::DirectionalLight* l)
{
    if (!l)
    {
        return harmony_glm_vec4_default();
    }
    return glm_vec4{ l->Diffuse.x,l->Diffuse.y, l->Diffuse.z, l->Diffuse.w };
}

glm_vec4 harmony_mono_directional_light_get_ambient(harmony::DirectionalLight* l)
{
	if (!l)
	{
		return harmony_glm_vec4_default();
	}
	return glm_vec4{ l->Ambient.x,l->Ambient.y, l->Ambient.z, l->Ambient.w };
}

harmony::PointLight* harmony_mono_get_point_light(harmony::Scene* scene, entt::entity e)
{
	MONO_GET_COMPONENT_IMPL(harmony::PointLight)
}

void harmony_mono_point_light_set_diffuse(harmony::PointLight* l, glm_vec4 diffuse)
{
	if (!l)
	{
		return;
	}

	l->Diffuse = glm::vec4(diffuse.x, diffuse.y, diffuse.z, diffuse.w);
}

void harmony_mono_point_light_set_ambient(harmony::PointLight* l, glm_vec4 ambient)
{
	if (!l)
	{
		return;
	}

	l->Ambient = glm::vec4(ambient.x, ambient.y, ambient.z, ambient.w);
}

void harmony_mono_point_light_set_radius(harmony::PointLight* l, float radius)
{
    if (!l)
    {
        return;
    }
    l->Radius = radius;
}

void harmony_mono_point_light_set_intensity(harmony::PointLight* l, float intensity)
{
	if (!l)
	{
		return;
	}
	l->Intensity = intensity;
}

glm_vec4 harmony_mono_point_light_get_diffuse(harmony::PointLight* l)
{
	if (!l)
	{
		return harmony_glm_vec4_default();
	}
	return glm_vec4{ l->Diffuse.x,l->Diffuse.y, l->Diffuse.z, l->Diffuse.w };
}

glm_vec4 harmony_mono_point_light_get_ambient(harmony::PointLight* l)
{
	if (!l)
	{
		return harmony_glm_vec4_default();
	}
	return glm_vec4{ l->Ambient.x,l->Ambient.y, l->Ambient.z, l->Ambient.w };
}

float harmony_mono_point_light_get_radius(harmony::PointLight* l)
{
    if (!l)
    {
        return 0.0f;
    }
    return l->Radius;
}

float harmony_mono_point_light_get_intensity(harmony::PointLight* l)
{
	if (!l)
	{
		return 0.0f;
	}
	return l->Intensity;
}

harmony::SpotLight* harmony_mono_get_spot_light(harmony::Scene* scene, entt::entity e)
{
    MONO_GET_COMPONENT_IMPL(harmony::SpotLight)
}


void harmony_mono_spot_light_set_diffuse(harmony::SpotLight* l, glm_vec4 diffuse)
{
	if (!l)
	{
		return;
	}

	l->Diffuse = glm::vec4(diffuse.x, diffuse.y, diffuse.z, diffuse.w);
}

void harmony_mono_spot_light_set_ambient(harmony::SpotLight* l, glm_vec4 ambient)
{
	if (!l)
	{
		return;
	}

	l->Ambient = glm::vec4(ambient.x, ambient.y, ambient.z, ambient.w);
}

void harmony_mono_spot_light_set_radius(harmony::SpotLight* l, float radius)
{
	if (!l)
	{
		return;
	}
	l->Radius = radius;
}

void harmony_mono_spot_light_set_intensity(harmony::SpotLight* l, float intensity)
{
	if (!l)
	{
		return;
	}
	l->Intensity = intensity;
}

void harmony_mono_spot_light_set_angle(harmony::SpotLight* l, float angle)
{
	if (!l)
	{
		return;
	}
	l->Angle = angle;
}

glm_vec4 harmony_mono_spot_light_get_diffuse(harmony::SpotLight* l)
{
	if (!l)
	{
		return harmony_glm_vec4_default();
	}
	return glm_vec4{ l->Diffuse.x,l->Diffuse.y, l->Diffuse.z, l->Diffuse.w };
}

glm_vec4 harmony_mono_spot_light_get_ambient(harmony::SpotLight* l)
{
	if (!l)
	{
		return harmony_glm_vec4_default();
	}
	return glm_vec4{ l->Ambient.x,l->Ambient.y, l->Ambient.z, l->Ambient.w };
}

float harmony_mono_spot_light_get_radius(harmony::SpotLight* l)
{
	if (!l)
	{
		return 0.0f;
	}
	return l->Radius;
}

float harmony_mono_spot_light_get_intensity(harmony::SpotLight* l)
{
	if (!l)
	{
		return 0.0f;
	}
	return l->Intensity;
}

float harmony_mono_spot_light_get_angle(harmony::SpotLight* l)
{
	if (!l)
	{
		return 0.0f;
	}
	return l->Angle;
}

harmony::SkyComponent* harmony_mono_get_sky(harmony::Scene* scene, entt::entity e)
{
    MONO_GET_COMPONENT_IMPL(harmony::SkyComponent)
}

void harmony_mono_set_sky_sun_size(harmony::SkyComponent* sky, float sun_size)
{
    if (!sky)
    {
        return;
    }
    sky->SunSize = sun_size;
}

void harmony_mono_set_sky_sun_bloom(harmony::SkyComponent* sky, float bloom)
{
	if (!sky)
	{
		return;
	}
    sky->SunBloom = bloom;
}

void harmony_mono_set_sky_exposition(harmony::SkyComponent* sky, float exposition)
{
	if (!sky)
	{
		return;
	}

    sky->Exposition = exposition;
}

void harmony_mono_set_sky_turbidity(harmony::SkyComponent* sky, float turbidity)
{
	if (!sky)
	{
		return;
	}
    sky->Turbidity = turbidity;
}

void harmony_mono_set_sky_luminance(harmony::SkyComponent* sky, glm_vec3 luminance)
{
	if (!sky)
	{
		return;
	}
    sky->SkyLuminance = glm::vec3(luminance.x, luminance.y, luminance.z);
}

float harmony_mono_get_sky_sun_size(harmony::SkyComponent* sky)
{
    if (!sky) return 0.0;
    return sky->SunSize;
}

float harmony_mono_get_sky_sun_bloom(harmony::SkyComponent* sky)
{
    if (!sky) return 0.0;
    return sky->SunBloom;
}

float harmony_mono_get_sky_exposition(harmony::SkyComponent* sky)
{
    if (!sky) return 0.0;
    return sky->Exposition;
}

float harmony_mono_get_sky_turbidity(harmony::SkyComponent* sky)
{
    if (!sky) return 0.0;
    return sky->Turbidity;
}

glm_vec3 harmony_mono_get_sky_luminance(harmony::SkyComponent* sky)
{
	if (!sky) return harmony_glm_vec3_default();
	return glm_vec3{ sky->SkyLuminance.x, sky->SkyLuminance.y, sky->SkyLuminance.z };
}

harmony::CameraComponent* harmony_mono_get_camera(harmony::Scene* scene, entt::entity e)
{
    MONO_GET_COMPONENT_IMPL(harmony::CameraComponent)
}


void        harmony_mono_vg_font_face(harmony_vg_layer layer, MonoString *font)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::FontFace(l, harmony::MonoUtils::GetStringFromMonoString(font).c_str());
}

void        harmony_mono_vg_font_size(harmony_vg_layer layer, float size)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::FontSize(l, size);
}

void        harmony_mono_vg_font_blur(harmony_vg_layer layer, float blur)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::FontBlur(l, blur);
}

void        harmony_mono_vg_text(harmony_vg_layer layer, float x, float y, MonoString *str)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Text(l, x, y, harmony::MonoUtils::GetStringFromMonoString(str).c_str());
}

void        harmony_mono_vg_text_letter_spacing(harmony_vg_layer layer, float spacing)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::TextLetterSpacing(l, spacing);
}

void        harmony_mono_vg_text_line_height(harmony_vg_layer layer, float lineHeight)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::TextLineHeight(l, lineHeight);
}

void        harmony_mono_vg_text_align(harmony_vg_layer layer, int align)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::TextAlign(l, align);
}

void        harmony_mono_vg_font_face_id(harmony_vg_layer layer, int font)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::FontFaceId(l, font);
}

void        harmony_mono_vg_text_box(harmony_vg_layer layer, float x, float y, float breakRowWidth, MonoString *string, MonoString *end)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::TextBox(l, x, y, breakRowWidth,
        harmony::MonoUtils::GetStringFromMonoString(string).c_str(),
            harmony::MonoUtils::GetStringFromMonoString(end).c_str());
}

void        harmony_mono_vg_shape_anti_alias(harmony_vg_layer layer, int enabled)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::ShapeAntiAlias(l, enabled);
}

void        harmony_mono_vg_stroke_color(harmony_vg_layer layer, NVGcolor color)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::StrokeColor(l, color);
}

void        harmony_mono_vg_stroke_paint(harmony_vg_layer layer, NVGpaint paint)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::StrokePaint(l, paint);
}

void        harmony_mono_vg_fill_color(harmony_vg_layer layer, NVGcolor color)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::FillColor(l, color);
}
void        harmony_mono_vg_fill_paint(harmony_vg_layer layer, NVGpaint paint)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::FillPaint(l, paint);
}
void        harmony_mono_vg_miter_limit(harmony_vg_layer layer, float limit)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::MiterLimit(l, limit);
}
void        harmony_mono_vg_stroke_width(harmony_vg_layer layer, float size)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::StrokeWidth(l, size);
}

void        harmony_mono_vg_line_cap(harmony_vg_layer layer, int cap)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::LineCap(l, cap);
}

void        harmony_mono_vg_line_join(harmony_vg_layer layer, int join)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::LineJoin(l, join);
}

void        harmony_mono_vg_global_alpha(harmony_vg_layer layer, float alpha)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::GlobalAlpha(l, alpha);
}

void        harmony_mono_vg_reset_transform(harmony_vg_layer layer)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::ResetTransform(l);
}

void        harmony_mono_vg_transform(harmony_vg_layer layer, float a, float b, float c, float d, float e, float f)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Transform(l, a, b, c, d, e, f);
}

void        harmony_mono_vg_translate(harmony_vg_layer layer, float x, float y)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Translate(l, x, y);
}

void        harmony_mono_vg_rotate(harmony_vg_layer layer, float angle)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Rotate(l, angle);
}

void        harmony_mono_vg_skew_x(harmony_vg_layer layer, float angle)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::SkewX(l, angle);
}

void        harmony_mono_vg_skew_y(harmony_vg_layer layer, float angle)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::SkewY(l, angle);
}

void        harmony_mono_vg_scale(harmony_vg_layer layer, float x, float y)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Scale(l, x, y);
}

void        harmony_mono_vg_current_transform(harmony_vg_layer layer, float *xform)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::CurrentTransform(l, xform);
}

void        harmony_mono_vg_update_image(harmony_vg_layer layer, int image, const unsigned char *data)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::UpdateImage(l, image, data);
}

void        harmony_mono_vg_image_size(harmony_vg_layer layer, int image, int *w, int *h)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::ImageSize(l, image, w, h);
}

void        harmony_mono_vg_delete_image(harmony_vg_layer layer, int image)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::DeleteImage(l, image);
}

void        harmony_mono_vg_scissor(harmony_vg_layer layer, float x, float y, float w, float h)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Scissor(l, x, y, w, h);
}

void        harmony_mono_vg_intersect_scissor(harmony_vg_layer layer, float x, float y, float w, float h)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::IntersectScissor(l, x, y, w, h);
}

void        harmony_mono_vg_reset_scissor(harmony_vg_layer layer)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::ResetScissor(l);
}

void        harmony_mono_vg_begin_path(harmony_vg_layer layer)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::BeginPath(l);
}

void        harmony_mono_vg_move_to(harmony_vg_layer layer, float x, float y)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::MoveTo(l, x, y);
}

void        harmony_mono_vg_line_to(harmony_vg_layer layer, float x, float y)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::LineTo(l, x, y);
}

void        harmony_mono_vg_bezier_to(harmony_vg_layer layer, float c1x, float c1y, float c2x, float c2y, float x, float y)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::BezierTo(l, c1x, c1y, c2x, c2y, x, y);
}

void        harmony_mono_vg_quad_to(harmony_vg_layer layer, float cx, float cy, float x, float y)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::QuadTo(l, cx, cy, x, y);
}

void        harmony_mono_vg_arc_to(harmony_vg_layer layer, float x1, float y1, float x2, float y2, float radius)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::ArcTo(l, x1, y1, x2, y2, radius);
}

void        harmony_mono_vg_close_path(harmony_vg_layer layer)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::ClosePath(l);
}

void        harmony_mono_vg_path_winding(harmony_vg_layer layer, int dir)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::PathWinding(l, dir);
}

void        harmony_mono_vg_arc(harmony_vg_layer layer, float cx, float cy, float r, float a0, float a1, int dir)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Arc(l, cx, cy, r, a0, a1, dir);
}

void        harmony_mono_vg_rect(harmony_vg_layer layer, float x, float y, float w, float h)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Rect(l, x, y, w, h);
}

void        harmony_mono_vg_rounded_rect(harmony_vg_layer layer, float x, float y, float w, float h, float r)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::RoundedRect(l, x, y, w, h, r);
}

void        harmony_mono_vg_rounded_rect_varying(harmony_vg_layer layer, float x, float y, float w, float h, float radTopLeft, float radTopRight, float radBottomRight, float radBottomLeft)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::RoundedRectVarying(l, x, y, w,  h, radTopLeft, radTopRight, radBottomRight, radBottomLeft);
}

void        harmony_mono_vg_ellipse(harmony_vg_layer layer, float cx, float cy, float rx, float ry)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Ellipse(l, cx, cy, rx, ry);
}

void        harmony_mono_vg_circle(harmony_vg_layer layer, float cx, float cy, float r)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Circle(l, cx, cy, r);
}

void        harmony_mono_vg_fill(harmony_vg_layer layer)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Fill(l);
}

void        harmony_mono_vg_stroke(harmony_vg_layer layer)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    harmony::VectorGraphics::Stroke(l);
}

NVGpaint    harmony_mono_vg_linear_gradient(harmony_vg_layer layer, float sx, float sy, float ex, float ey, NVGcolor icol, NVGcolor ocol)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    return harmony::VectorGraphics::LinearGradient(l, sx, sy, ex, ey, icol, ocol);
}

NVGpaint    harmony_mono_vg_box_gradient(harmony_vg_layer layer, float x, float y, float w, float h, float r, float f, NVGcolor icol, NVGcolor ocol)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    return harmony::VectorGraphics::BoxGradient(l, x, y,  w,  h,  r,  f,  icol,  ocol);
}

NVGpaint    harmony_mono_vg_radial_gradient(harmony_vg_layer layer, float cx, float cy, float inr, float outr, NVGcolor icol, NVGcolor ocol)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    return harmony::VectorGraphics::RadialGradient(l,  cx,  cy,  inr,  outr,  icol,  ocol);
}

NVGpaint    harmony_mono_vg_image_pattern(harmony_vg_layer layer, float ox, float oy, float ex, float ey, float angle, int image, float alpha)
{
    auto l = static_cast<harmony::VectorGraphics::Layer>(layer);
    return harmony::VectorGraphics::ImagePattern(l,  ox,  oy,  ex,  ey,  angle,  image,  alpha);
}

MonoArray* harmony_mono_assets_get_assets_at_path(MonoString* path)
{
    using namespace harmony;
    String c_path = String(mono_string_to_utf8(path));
    AssetManager& am = Program::Get()->m_AssetManager;

    Vector<AssetHandle> handles = am.GetAssetsAtPath(c_path);

    if (s_AssetHandleClass == nullptr)
    {
        GetTypesForArrays();
    }

    auto mono = harmony::Program::Get()->
        GetProgramComponent<harmony::MonoProgramComponent>().lock();

    MonoArray* arr = mono_array_new(mono->GetAppDomain(), s_AssetHandleClass, handles.size());
    for (int i = 0; i < handles.size(); i++)
    {
        asset_handle handle{ 
            mono_string_new(mono->GetAppDomain(), 
            
            handles[i].Path.c_str()), 
            handles[i].Index, 
            handles[i].TypeHash.m_Value 
        };

        mono_array_set(arr, asset_handle, i, handle);
    }

    return arr;
}

harmony::Mesh* harmony_mono_assets_get_mesh_asset(asset_handle handle)
{
    using namespace harmony;
    String c_path = String(mono_string_to_utf8(handle.path));
    AssetHandle h{ c_path, handle.index, HashString {handle.type_hash} };

    WeakPtr<Mesh> m = Program::Get()->m_AssetManager.GetAsset<Mesh>(h);

    if (m.expired())
    {
        return nullptr;
    }

    return m.lock().get();
}

harmony::TextureAsset* harmony_mono_assets_get_texture_asset(asset_handle handle)
{
    using namespace harmony;
    String c_path = String(mono_string_to_utf8(handle.path));
    AssetHandle h{ c_path, handle.index, HashString {handle.type_hash} };

    WeakPtr<TextureAsset> t = Program::Get()->m_AssetManager.GetAsset<TextureAsset>(h);

    if (t.expired())
    {
        return nullptr;
    }

    return t.lock().get();
}

harmony::ShaderProgram* harmony_mono_renderer_get_shader(MonoString* name)
{
    harmony::String c_name = harmony::String(mono_string_to_utf8(name));
    auto shaderWr = harmony::Program::Get()->m_Renderer.GetShader(c_name);

    if(shaderWr.expired())
    {
        return nullptr;
    }

    return shaderWr.lock().get();
}

harmony::View* harmony_mono_renderer_get_view(MonoString* name)
{
    auto viewWr = harmony::Program::Get()->m_Renderer.GetView(harmony::String(mono_string_to_utf8(name)));

    if(viewWr.expired())
    {
        return nullptr;
    }

    return viewWr.lock().get();
}

harmony::PipelineV2* harmony_mono_renderer_get_view_pipeline(harmony::View* view)
{
    auto viewWr = harmony::Program::Get()->m_Renderer.GetView(view->m_Name);

    if(viewWr.expired())
    {
        return nullptr;
    }

    auto pipelineWr = harmony::Program::Get()->m_Renderer.GetViewPipeline(viewWr);
    if(pipelineWr.expired())
    {
        return nullptr;
    }

    return pipelineWr.lock().get();
}

harmony::Framebuffer* harmony_mono_renderer_pipeline_add_framebuffer(harmony::PipelineV2* pipeline, MonoString* name, MonoArray* attachments,
    harmony_resolution_type resolutionType)
{
    using namespace harmony;
    String fbName = String(mono_string_to_utf8(name));
    Resolution::Type rt = static_cast<Resolution::Type>(resolutionType);
    Vector<AttachmentType> attachmentTypes = Vector<AttachmentType>();
    uint32_t arrLength = mono_array_length(attachments);
    for(int i = 0; i < arrLength; i++)
    {
        AttachmentType& attachmentType = mono_array_get(attachments, AttachmentType, i);
        attachmentTypes.push_back(attachmentType);
    }
    if(pipeline)
    {
        auto fb = pipeline->AddFramebuffer(fbName, attachmentTypes, rt).lock();

        if(fb)
        {
            return fb.get();
        }
    }
    return nullptr;
}

void harmony_mono_renderer_pipeline_set_output_framebuffer(harmony::PipelineV2* pipeline, harmony::Framebuffer* fb)
{
    using namespace harmony;
    if(!pipeline || !fb)
    {
        return;
    }
    WeakPtr<Framebuffer> pipelineFB = pipeline->GetFramebuffer(fb->m_Name);

    if(pipelineFB.expired())
    {
        return;
    }

    pipeline->SetOutputFramebuffer(pipelineFB);
}

harmony::PipelineStageRenderer* harmony_mono_renderer_get_pipeline_stage_renderer(MonoString* name)
{
    using namespace harmony;
    RefCntPtr<PipelineStageRenderer> renderer = Program::Get()->m_Renderer.GetPipelineStageRenderer(String(mono_string_to_utf8(name))).lock();
    if(renderer)
    {
        return renderer.get();
    }
    return nullptr;
}

static harmony::Vector<harmony::RefCntPtr<harmony::PipelineStage>>          s_PipelineStageCache;
static harmony::Vector<harmony::RefCntPtr<harmony::PipelineStageRenderer>>  s_PipelineStageRendererCache;
static harmony::Vector<harmony::RefCntPtr<harmony::ShaderDataSource>>       s_ShaderDataSourceCache;
static harmony::Vector<harmony::RefCntPtr<harmony::ShaderProgram>>          s_ShaderProgramCache;

void harmony_mono_renderer_pipeline_add_stage(harmony::PipelineV2* pipeline, harmony::Framebuffer* fb, harmony::PipelineStage* stage)
{
    using namespace harmony;

    if(!pipeline || !fb || !stage)
    {
        return;
    }
    RefCntPtr<PipelineStage> stageRefCntPtr;
    for (auto& ps : s_PipelineStageCache)
    {
        if (ps.get() == stage)
        {
            stageRefCntPtr = ps;
        }
    }

    if (!stageRefCntPtr)
    {
        return;
    }

    WeakPtr<Framebuffer> framebuffer = pipeline->GetFramebuffer(fb->m_Name);
    pipeline->AddPipelineStage(framebuffer, stageRefCntPtr);
}

void harmony_mono_renderer_pipeline_stage_add_data_source(harmony::PipelineStage* stage,
    harmony::ShaderDataSource* source)
{
    using namespace harmony;

    if(!source || !stage)
    {
        return;
    }
    RefCntPtr<ShaderDataSource> sourceRefCntPtr;

	for (auto& sds : s_ShaderDataSourceCache)
	{
		if (sds.get() == source)
		{
            sourceRefCntPtr = sds;
		}
	}

	if (!sourceRefCntPtr)
	{
		return;
	}
    
    stage->AddShaderDataSource(sourceRefCntPtr);
}

void harmony_mono_renderer_clear_cached_objects()
{
    s_PipelineStageCache.clear();
    s_ShaderDataSourceCache.clear();
    s_PipelineStageRendererCache.clear();
    s_ShaderProgramCache.clear();
}

harmony::PipelineDrawStage* harmony_mono_renderer_create_pipeline_draw_stage(MonoString* name,
    harmony::ShaderProgram* shader, harmony::PipelineStageRenderer* renderer)
{
    using namespace harmony;

    String stageName = String(mono_string_to_utf8(name));

    WeakPtr<ShaderProgram> s = Program::Get()->m_Renderer.GetShader(shader->m_Name);

	RefCntPtr<PipelineStageRenderer> rendererRef;

	for (auto& r : s_PipelineStageRendererCache)
	{
		if (r.get() == renderer)
		{
			rendererRef = r;
		}
	}

    if (!rendererRef)
    {
        rendererRef = Program::Get()->m_Renderer.GetPipelineStageRenderer(renderer->m_Name).lock();
    }

	if (!rendererRef)
	{
		return nullptr;
	}

    RefCntPtr<PipelineDrawStage> stage = CreateRef<PipelineDrawStage>(
        stageName,
        PipelineDrawStage::Type::PrimaryDraw,
        s,
        rendererRef
    );

    s_PipelineStageCache.emplace_back(stage);

    return stage.get();
}

harmony::DrawScreenTextureStage* harmony_mono_renderer_create_draw_screen_texture_stage(harmony::PipelineV2* pipeline, harmony::ShaderProgram* shader,
    harmony_attachment_type attachmentType, MonoArray* framebufferArray)
{
    using namespace harmony;

	uint32_t arrLength = mono_array_length(framebufferArray);
    Vector<WeakPtr<Framebuffer>> framebuffers;
	for (int i = 0; i < arrLength; i++)
	{
		Framebuffer* f = mono_array_get(framebufferArray, Framebuffer*, i);
        framebuffers.push_back(pipeline->TryGetFramebuffer(f->m_Name));
	}
    if (!shader)
    {
        return nullptr;
    }

    auto s = Program::Get()->m_Renderer.GetShader(shader->m_Name).lock();


    RefCntPtr<DrawScreenTextureStage> drawScreenTextureStage = CreateRef<DrawScreenTextureStage>(
        s,
        (AttachmentType)attachmentType,
        framebuffers
    );

    s_PipelineStageCache.push_back(drawScreenTextureStage);
    return drawScreenTextureStage.get();
}

harmony::SkyStage* harmony_mono_renderer_create_sky_stage()
{
    using namespace harmony;
	auto skyShader = Program::Get()->m_Renderer.GetShader("Sky");
	RefCntPtr<SkyStage> skyStage = CreateRef<SkyStage>(skyShader);
    s_PipelineStageCache.emplace_back(skyStage);
    return skyStage.get();
}

harmony::VectorGraphicsStage* harmony_mono_renderer_create_vector_graphics_stage(harmony_vg_layer layer)
{
    using namespace harmony;
    auto l = (VectorGraphics::Layer)layer;
    RefCntPtr<VectorGraphicsStage> vectorStage = CreateRef<VectorGraphicsStage>(l);
    s_PipelineStageCache.emplace_back(vectorStage);
    return vectorStage.get();
}

harmony::DebugDrawStage* harmony_mono_renderer_create_debug_draw_stage(harmony_debug_draw_channel channel)
{
	using namespace harmony;
	auto c = (GfxDebug::Channel) channel;
	RefCntPtr<DebugDrawStage> debugDrawStage = CreateRef<DebugDrawStage>(c);
	s_PipelineStageCache.emplace_back(debugDrawStage);
	return debugDrawStage.get();
}

harmony::ScreenQuadRenderer* harmony_mono_renderer_create_screen_quad_renderer()
{
    using namespace harmony;
    RefCntPtr<ScreenQuadRenderer> quad_renderer = CreateRef<ScreenQuadRenderer>();
    s_PipelineStageRendererCache.emplace_back(SmartPointerCast<PipelineStageRenderer, ScreenQuadRenderer>(quad_renderer));
    return quad_renderer.get();
}

harmony::DeferredDataSource* harmony_mono_renderer_create_deferred_data_source(harmony::PipelineV2* pipeline, harmony::Framebuffer* framebuffer)
{
    using namespace harmony;
    auto fb = pipeline->TryGetFramebuffer(framebuffer->m_Name).lock();
    RefCntPtr<DeferredDataSource> deferredDataSource = CreateRef<DeferredDataSource>(fb);
    s_ShaderDataSourceCache.emplace_back(deferredDataSource);
    return deferredDataSource.get();
}

harmony::TextureAssetSource* harmony_mono_renderer_create_texture_asset_source(uint16_t samplerIndex,
    MonoString* uniformName, harmony::TextureAsset* textureAsset)
{
    using namespace harmony;
    String uname = harmony::MonoUtils::GetStringFromMonoString(uniformName);
    WeakPtr<TextureAsset> asset = Program::Get()->m_AssetManager.GetAsset<TextureAsset>(textureAsset->m_Handle);
    RefCntPtr<TextureAssetSource> textureSource = CreateRef<TextureAssetSource>(samplerIndex, uname, asset);
    s_ShaderDataSourceCache.emplace_back(textureSource);
    return textureSource.get();
}


harmony::BlinnPhongDataSource* harmony_mono_renderer_create_blinn_phong_data_source()
{
    using namespace harmony;

    RefCntPtr<BlinnPhongDataSource> blinnPhongDataSource = CreateRef<BlinnPhongDataSource>();
    s_ShaderDataSourceCache.emplace_back(blinnPhongDataSource);
    return blinnPhongDataSource.get();
}
