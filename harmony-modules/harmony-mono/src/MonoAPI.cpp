//
// Created by liam_ on 9/24/2023.
//
#include "MonoAPI.h"
#include "Core/Log.hpp"
#include "Core/Time.h"
#include "Core/Program.h"
#include "Core/Alias.h"
#include "ECS/TransformComponent.h"
#include "ThirdParty/entt.hpp"

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

void harmony_mono_load_scene(const char *path) {
    harmony::Program::Get()->LoadScene(path);
}

void harmony_mono_save_scene(const char *path) {
    harmony::Program::Get()->SaveScene(path);
}

harmony::TransformComponent *harmony_mono_get_transform(harmony::Scene *scene, entt_entity entity) {
    if(!scene) return nullptr;

    entt::entity& e = (entt::entity&)entity;

    if(!scene->m_Registry.any_of<harmony::TransformComponent>(e))
    {
        return nullptr;
    }

    return &scene->m_Registry.get<harmony::TransformComponent>(e);
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

glm_vec3 harmony_glm_vec3_default() {
    return glm_vec3{0.0f, 0.0f, 0.0f};
}


