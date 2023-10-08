//
// Created by liam_ on 9/24/2023.
//

#pragma once

#include "MonoUtils.h"
#include "Core/Scene.h"

namespace harmony {
    struct TransformComponent;
}
extern "C"
{
    // Type Defs
    typedef uint32_t entt_entity;

    struct glm_vec3
    {
        float x;
        float y;
        float z;
    };

    glm_vec3 harmony_glm_vec3_default();
    // Log
    void harmony_mono_log_trace(MonoString* str);
    void harmony_mono_log_info(MonoString* str);
    void harmony_mono_log_warn(MonoString* str);
    void harmony_mono_log_error(MonoString* str);

    // Time
    double harmony_mono_get_frame_time();
    double harmony_mono_get_frame_time_unscaled();
    double harmony_mono_get_time_scale();
    void  harmony_mono_set_time_scale(double newTimeScale);

    // Program
    harmony::Program*   harmony_mono_get_program();

    // Scene
    harmony::Scene*     harmony_mono_get_active_scene();
    void                harmony_mono_close_active_scene();
    void                harmony_mono_load_scene(const char* path);
    void                harmony_mono_save_scene(const char* path);

    // ECS
    harmony::TransformComponent* harmony_mono_get_transform(harmony::Scene* scene, entt_entity entity);
    void harmony_mono_set_transform_position(harmony::TransformComponent* t, glm_vec3 position);
    void harmony_mono_set_transform_euler(harmony::TransformComponent* t, glm_vec3 euler);
    void harmony_mono_set_transform_scale(harmony::TransformComponent* t, glm_vec3 scale);

    glm_vec3 harmony_mono_get_transform_position    (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_euler       (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_scale       (harmony::TransformComponent* t);


}