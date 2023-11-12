//
// Created by liam_ on 9/24/2023.
//

#pragma once

#include "MonoUtils.h"
#include "Core/Scene.h"

namespace harmony {
    struct TransformComponent;

    class ProgramComponent;
}
extern "C"
{
    // Forward defs
    struct NVGpaint;
    struct NVGcolor;

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

    enum harmony_vg_layer : char {
        LayerOne,
        LayerTwo,
        LayerThree,
        LayerFour,
        LayerFive,
        LayerSix,
        LayerSeven,
        LayerEight
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

    // Default constructor
    glm_vec2 harmony_glm_vec2_default();
    glm_vec3 harmony_glm_vec3_default();

    // Log
    void harmony_mono_log_trace(MonoString* str);
    void harmony_mono_log_info(MonoString* str);
    void harmony_mono_log_warn(MonoString* str);
    void harmony_mono_log_error(MonoString* str);

    // Time
    double  harmony_mono_get_frame_time();
    double  harmony_mono_get_frame_time_unscaled();
    double  harmony_mono_get_time_scale();
    void    harmony_mono_set_time_scale(double newTimeScale);

    // Program
    harmony::Program*           harmony_mono_get_program();
    harmony::ProgramComponent*  harmony_mono_get_program_component(uint64_t type_hash);

    // Scene
    harmony::Scene*     harmony_mono_get_active_scene();
    void                harmony_mono_close_active_scene();
    void                harmony_mono_load_scene(MonoString* path);
    void                harmony_mono_save_scene(MonoString* path);

    // Input
    glm_vec2    harmony_mono_get_mouse_position();
    glm_vec2    harmony_mono_get_mouse_position_last_frame();
    glm_vec2    harmony_mono_get_mouse_velocity();
    glm_vec2    harmony_mono_get_mouse_velocity_last_frame();
    glm_vec2    harmony_mono_get_gamepad_stick(int gamepad_index, harmony_gamepad_stick stick);
    float       harmony_mono_get_gamepad_trigger(int gamepad_index, harmony_gamepad_trigger trigger);
    bool        harmony_mono_get_mouse_button(harmony_mouse_button button);
    bool        harmony_mono_get_mouse_button_just_pressed(harmony_mouse_button button);
    bool        harmony_mono_get_mouse_button_just_released(harmony_mouse_button button);
    bool        harmony_mono_get_key(harmony_keyboard_key key);
    bool        harmony_mono_get_key_just_pressed(harmony_keyboard_key key);
    bool        harmony_mono_get_key_just_released(harmony_keyboard_key key);
    bool        harmony_mono_get_gamepad_button(int gamepad_index, harmony_gamepad_button button);
    bool        harmony_mono_get_gamepad_button_just_pressed(int gamepad_index, harmony_gamepad_button button);
    bool        harmony_mono_get_gamepad_button_just_released(int gamepad_index, harmony_gamepad_button button);

    // Vector Graphics
    void        harmony_mono_vg_font_face(harmony_vg_layer layer, MonoString *font);
    void        harmony_mono_vg_font_size(harmony_vg_layer layer, float size);
    void        harmony_mono_vg_font_blur(harmony_vg_layer layer, int blur);
    void        harmony_mono_vg_text(harmony_vg_layer layer, float x, float y, MonoString *str);
    void        harmony_mono_vg_text_letter_spacing(harmony_vg_layer layer, float spacing);
    void        harmony_mono_vg_text_line_height(harmony_vg_layer layer, float line_height);
    void        harmony_mono_vg_text_align(harmony_vg_layer layer, int align);
    void        harmony_mono_vg_font_face_id(harmony_vg_layer layer, int font);
    void        harmony_mono_vg_text_box(harmony_vg_layer layer, float x, float y, float break_row_width, MonoString *string, MonoString *end);
    void        harmony_mono_vg_shape_anti_alias(harmony_vg_layer layer, int enabled);
    void        harmony_mono_vg_stroke_color(harmony_vg_layer layer, NVGcolor color);
    void        harmony_mono_vg_stroke_paint(harmony_vg_layer layer, NVGpaint paint);
    void        harmony_mono_vg_fill_color(harmony_vg_layer layer, NVGcolor color);
    void        harmony_mono_vg_fill_paint(harmony_vg_layer layer, NVGpaint paint);
    void        harmony_mono_vg_miter_limit(harmony_vg_layer layer, float limit);
    void        harmony_mono_vg_stroke_width(harmony_vg_layer layer, float size);
    void        harmony_mono_vg_line_cap(harmony_vg_layer layer, int cap);
    void        harmony_mono_vg_line_join(harmony_vg_layer layer, int join);
    void        harmony_mono_vg_global_alpha(harmony_vg_layer layer, float alpha);
    void        harmony_mono_vg_reset_transform(harmony_vg_layer layer);
    void        harmony_mono_vg_transform(harmony_vg_layer layer, float a, float b, float c, float d, float e, float f);
    void        harmony_mono_vg_translate(harmony_vg_layer layer, float x, float y);
    void        harmony_mono_vg_rotate(harmony_vg_layer layer, float angle);
    void        harmony_mono_vg_skew_x(harmony_vg_layer layer, float angle);
    void        harmony_mono_vg_skew_y(harmony_vg_layer layer, float angle);
    void        harmony_mono_vg_scale(harmony_vg_layer layer, float x, float y);
    void        harmony_mono_vg_current_transform(harmony_vg_layer layer, float *xform);
    void        harmony_mono_vg_image_size(harmony_vg_layer layer, int image, int *w, int *h);
    void        harmony_mono_vg_delete_image(harmony_vg_layer layer, int image);
    void        harmony_mono_vg_scissor(harmony_vg_layer layer, float x, float y, float w, float h);
    void        harmony_mono_vg_intersect_scissor(harmony_vg_layer layer, float x, float y, float w, float h);
    void        harmony_mono_vg_reset_scissor(harmony_vg_layer layer);
    void        harmony_mono_vg_begin_path(harmony_vg_layer layer);
    void        harmony_mono_vg_move_to(harmony_vg_layer layer, float x, float y);
    void        harmony_mono_vg_line_to(harmony_vg_layer layer, float x, float y);
    void        harmony_mono_vg_bezier_to(harmony_vg_layer layer, float c1x, float c1y, float c2x, float c2y, float x, float y);
    void        harmony_mono_vg_quad_to(harmony_vg_layer layer, float cx, float cy, float x, float y);
    void        harmony_mono_vg_arc_to(harmony_vg_layer layer, float x1, float y1, float x2, float y2, float radius);
    void        harmony_mono_vg_close_path(harmony_vg_layer layer);
    void        harmony_mono_vg_path_winding(harmony_vg_layer layer, int dir);
    void        harmony_mono_vg_arc(harmony_vg_layer layer, float cx, float cy, float r, float a0, float a1, int dir);
    void        harmony_mono_vg_rect(harmony_vg_layer layer, float x, float y, float w, float h);
    void        harmony_mono_vg_rounded_rect(harmony_vg_layer layer, float x, float y, float w, float h, float r);
    void        harmony_mono_vg_rounded_rect_varying(harmony_vg_layer layer, float x, float y, float w, float h, float rad_top_left, float rad_top_right, float rad_bottom_right, float rad_bottom_left);
    void        harmony_mono_vg_ellipse(harmony_vg_layer layer, float cx, float cy, float rx, float ry);
    void        harmony_mono_vg_circle(harmony_vg_layer layer, float cx, float cy, float r);
    void        harmony_mono_vg_fill(harmony_vg_layer layer);
    void        harmony_mono_vg_stroke(harmony_vg_layer layer);
    NVGpaint    harmony_mono_vg_linear_gradient(harmony_vg_layer layer, float sx, float sy, float ex, float ey, NVGcolor icol, NVGcolor ocol);
    NVGpaint    harmony_mono_vg_box_gradient(harmony_vg_layer layer, float x, float y, float w, float h, float r, float f, NVGcolor icol, NVGcolor ocol);
    NVGpaint    harmony_mono_vg_radial_gradient(harmony_vg_layer layer, float cx, float cy, float inr, float outr, NVGcolor icol, NVGcolor ocol);
    NVGpaint    harmony_mono_vg_image_pattern(harmony_vg_layer layer, float ox, float oy, float ex, float ey, float angle, int image, float alpha);

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