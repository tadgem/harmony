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
    enum harmony_gamepad_button {
        ButtonInvalid = -1,
        FaceNorth,
        FaceSouth,
        FaceEast,
        FaceWest,
        Up,
        Down,
        Left,
        Right,
        RightBumper,
        LeftBumper,
        Home,
        Select,
        Start,
        LS_BUTTON,
        RS_BUTTON
    };
    enum harmony_gamepad_stick {
        StickInvalid = -1,
        LS,
        RS
    };
    enum harmony_gamepad_trigger {
        Invalid = -1,
        LT,
        RT
    };
    enum harmony_mouse_button {
        MouseButtonInvalid = -1,
        MouseButtonLeft,
        MouseButtonMiddle,
        MouseButtonRight,
        Extra1,
        Extra2,
        Extra3
    };
    enum harmony_keyboard_key {
        KeyInvalid = -1,
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H,
        I,
        J,
        K,
        L,
        M,
        N,
        O,
        P,
        Q,
        R,
        S,
        T,
        U,
        V,
        W,
        X,
        Y,
        Z,
        Zero,
        One,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Minus,
        Underscore,
        Equals,
        Plus,
        Backspace,
        Enter,
        Space,
        Tab,
        CapsLock,
        Tilde,
        LeftShift,
        LeftControl,
        LeftAlt,
        RightShift,
        RightControl,
        RightAlt,
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        Insert,
        HomeKey,
        PageUp,
        PageDown,
        Delete,
        End,
        UpKey,
        DownKey,
        LeftKey,
        RightKey,
        Escape

    };

    typedef uint32_t entt_entity;

    struct glm_vec2
    {
        float x;
        float y;
    };
    struct glm_vec3
    {
        float x;
        float y;
        float z;
    };

    glm_vec2 harmony_glm_vec2_default();
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

    // Input
    glm_vec2 harmony_mono_get_mouse_position();
    glm_vec2 harmony_mono_get_mouse_position_last_frame();
    glm_vec2 harmony_mono_get_mouse_velocity();
    glm_vec2 harmony_mono_get_mouse_velocity_last_frame();
    bool harmony_mono_get_mouse_button(harmony_mouse_button button);
    bool harmony_mono_get_mouse_button_just_pressed(harmony_mouse_button button);
    bool harmony_mono_get_mouse_button_just_released(harmony_mouse_button button);
    bool harmony_mono_get_key(harmony_keyboard_key key);
    bool harmony_mono_get_key_just_pressed(harmony_keyboard_key key);
    bool harmony_mono_get_key_just_released(harmony_keyboard_key key);
    bool harmony_mono_get_gamepad_button(int gamepad_index, harmony_gamepad_button button);
    bool harmony_mono_get_gamepad_button_just_pressed(int gamepad_index, harmony_gamepad_button button);
    bool harmony_mono_get_gamepad_button_just_released(int gamepad_index, harmony_gamepad_button button);
    float harmony_mono_get_gamepad_trigger(int gamepad_index, harmony_gamepad_trigger trigger);
    glm_vec2 harmony_mono_get_gamepad_stick(int gamepad_index, harmony_gamepad_stick stick);

    // ECS
    harmony::TransformComponent* harmony_mono_get_transform(harmony::Scene* scene, entt_entity entity);
    void harmony_mono_set_transform_position(harmony::TransformComponent* t, glm_vec3 position);
    void harmony_mono_set_transform_euler(harmony::TransformComponent* t, glm_vec3 euler);
    void harmony_mono_set_transform_scale(harmony::TransformComponent* t, glm_vec3 scale);

    glm_vec3 harmony_mono_get_transform_position    (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_euler       (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_scale       (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_forward     (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_right       (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_up          (harmony::TransformComponent* t);


}