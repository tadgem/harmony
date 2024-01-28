//
// Created by liam_ on 9/24/2023.
//

#pragma once

#include "MonoUtils.h"
#include "Core/Scene.h"
#include "Rendering/Framebuffer.h"
#include "Rendering/Pipelines/PipelineStageRenderer.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/ShaderDataSource.h"

// Forward def
namespace harmony {
    class DrawScreenTextureStage;
    class TextureAssetSource;
    class DeferredDataSource;
	class BlinnPhongDataSource;
    class ScreenQuadRenderer;
    class PipelineDrawStage;
    class PipelineStageRenderer;
    class ShaderDataSource;
    class PipelineStage;
    class Framebuffer;
    class PipelineV2;
    class View;
    class ShaderProgram;
    class ProgramComponent;
    class Mesh;
    class TextureAsset;
    class ShaderStage;
    class SkyStage;
    class VectorGraphicsStage;
    class DebugDrawStage;
	struct TransformComponent;
	struct MeshComponent;
	struct MaterialComponent;
	struct SkyComponent;
	struct CameraComponent;
	struct DirectionalLight;
	struct PointLight;
	struct SpotLight;
}
extern "C"
{
    struct NVGpaint;
    struct NVGcolor;

    enum harmony_debug_draw_channel : char
    {
        Editor, 
        Game
    };
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

    enum harmony_attachment_type : int {
        UnknownAttachmentType = 1,
        RGBA8 = 2,
        RGBA16F = 4,
        RGBA32F = 8,
        RGBA = RGBA8 | RGBA16F | RGBA32F,
        Depth16F = 16,
        Depth24F = 32,
        Depth32F = 64,
        Depth = Depth16F | Depth24F | Depth32F

    };

    enum harmony_resolution_type {
        FullScale,
        HalfScale,
        QuarterScale,
        EighthScale,
        SixteenthScale,
        Custom
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

    struct asset_handle
    {
        MonoString* path;
        uint32_t index;
        uint64_t type_hash;
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
    entt_entity         harmony_mono_create_entity(harmony::Scene* scene);
    void                harmony_mono_delete_entity(harmony::Scene* scene, entt_entity e);
    MonoArray*          harmony_mono_get_entity_script_behaviours(harmony::Scene* scene, entt_entity e);

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

    // Debug Draw
    void        harmony_mono_debug_draw_set_colour(harmony_debug_draw_channel channel, uint32_t rgba);
    void        harmony_mono_debug_draw_set_stipple(harmony_debug_draw_channel channel, bool stipple, float scale, float offset);
    void        harmony_mono_debug_draw_set_wireframe(harmony_debug_draw_channel channel, bool wireframe);
    void        harmony_mono_debug_draw_set_translate(harmony_debug_draw_channel channel, glm_vec3 translate);
    void        harmony_mono_debug_draw_move_to(harmony_debug_draw_channel channel, glm_vec3 translate);
    void        harmony_mono_debug_draw_line_to(harmony_debug_draw_channel channel, glm_vec3 translate);
    void        harmony_mono_debug_draw_circle(harmony_debug_draw_channel channel, glm_vec3 normal, glm_vec3 center, float radius, float weight);
    void        harmony_mono_debug_draw_quad(harmony_debug_draw_channel channel, glm_vec3 normal, glm_vec3 center, float size);
    void        harmony_mono_debug_draw_sphere(harmony_debug_draw_channel channel, glm_vec3 center, float radius);
    void        harmony_mono_debug_draw_cylinder(harmony_debug_draw_channel channel, glm_vec3 from, glm_vec3 to, float radius);
    void        harmony_mono_debug_draw_capsule(harmony_debug_draw_channel channel, glm_vec3 from, glm_vec3 to, float radius);
    void        harmony_mono_debug_draw_cone(harmony_debug_draw_channel channel, glm_vec3 from, glm_vec3 to, float radius);
    void        harmony_mono_debug_draw_grid(harmony_debug_draw_channel channel, glm_vec3 normal, glm_vec3 center, uint32_t size, float step);
    void        harmony_mono_debug_draw_orb(harmony_debug_draw_channel channel, glm_vec3 center, float radius);
    
    // Vector Graphics
    void        harmony_mono_vg_font_face(harmony_vg_layer layer, MonoString *font);
    void        harmony_mono_vg_font_size(harmony_vg_layer layer, float size);
    void        harmony_mono_vg_font_blur(harmony_vg_layer layer, float blur);
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

    // Assets
    MonoArray*              harmony_mono_assets_get_assets_at_path(MonoString* path);
    harmony::Mesh*          harmony_mono_assets_get_mesh_asset(asset_handle handle);
    harmony::TextureAsset*  harmony_mono_assets_get_texture_asset(asset_handle handle);

    // Rendering
    harmony::View*                  harmony_mono_renderer_get_view(MonoString* name);
    harmony::PipelineV2*            harmony_mono_renderer_get_view_pipeline(harmony::View* view);
    harmony::ShaderProgram*         harmony_mono_renderer_get_shader(MonoString* name);
    harmony::PipelineStageRenderer* harmony_mono_renderer_get_pipeline_stage_renderer(MonoString* name);

    harmony::Framebuffer*           harmony_mono_renderer_pipeline_add_framebuffer(harmony::PipelineV2* pipeline, MonoString* name, MonoArray* attachments, harmony_resolution_type resolutionType);
    void                            harmony_mono_renderer_pipeline_set_output_framebuffer(harmony::PipelineV2* pipeline, harmony::Framebuffer* fb);
    void                            harmony_mono_renderer_pipeline_add_stage(harmony::PipelineV2* pipeline, harmony::Framebuffer* fb, harmony::PipelineStage* stage);
    void                            harmony_mono_renderer_pipeline_stage_add_data_source(harmony::PipelineStage* fb, harmony::ShaderDataSource* source);

    harmony::PipelineDrawStage*         harmony_mono_renderer_create_pipeline_draw_stage(MonoString* name, harmony::ShaderProgram* shader, harmony::PipelineStageRenderer* renderer);
    harmony::DrawScreenTextureStage*    harmony_mono_renderer_create_draw_screen_texture_stage(harmony::PipelineV2* pipeline, harmony::ShaderProgram* shader, harmony_attachment_type attachmentType, MonoArray* framebufferArray);
    harmony::SkyStage*                  harmony_mono_renderer_create_sky_stage();
    harmony::VectorGraphicsStage*       harmony_mono_renderer_create_vector_graphics_stage(harmony_vg_layer layer);
    harmony::DebugDrawStage*            harmony_mono_renderer_create_debug_draw_stage(harmony_debug_draw_channel channel);
    harmony::ScreenQuadRenderer*        harmony_mono_renderer_create_screen_quad_renderer();
    harmony::DeferredDataSource*        harmony_mono_renderer_create_deferred_data_source(harmony::PipelineV2* pipeline, harmony::Framebuffer* framebuffer);
    harmony::TextureAssetSource*        harmony_mono_renderer_create_texture_asset_source(uint16_t samplerIndex, MonoString* uniformName, harmony::TextureAsset* textureAsset);
	harmony::BlinnPhongDataSource*      harmony_mono_renderer_create_blinn_phong_data_source();
    // Create / destroy built in stages...
    // Need to call this after modules are loaded
    // if we create a ref in a method and return raw ptr object is make delete
    // have a temporary static vector we push them to as we process modules, then clear
    void                            harmony_mono_renderer_clear_cached_objects();
    
    // ECS
    // Transform
    harmony::TransformComponent* harmony_mono_get_transform(harmony::Scene* scene, entt_entity e);
    void harmony_mono_set_transform_position(harmony::TransformComponent* t, glm_vec3 position);
    void harmony_mono_set_transform_euler(harmony::TransformComponent* t, glm_vec3 euler);
    void harmony_mono_set_transform_scale(harmony::TransformComponent* t, glm_vec3 scale);

    glm_vec3 harmony_mono_get_transform_position    (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_euler       (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_scale       (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_forward     (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_right       (harmony::TransformComponent* t);
    glm_vec3 harmony_mono_get_transform_up          (harmony::TransformComponent* t);

    // Mesh
    harmony::MeshComponent* harmony_mono_get_mesh(harmony::Scene* scene, entt::entity e);
    
    // Material
    harmony::MaterialComponent* harmony_mono_get_material(harmony::Scene* scene, entt::entity e);

    // Directional Light
    harmony::DirectionalLight* harmony_mono_get_directional_light(harmony::Scene* scene, entt::entity e);
    
    // Point Light
    harmony::PointLight* harmony_mono_get_point_light(harmony::Scene* scene, entt::entity e);

    // Spot Light
    harmony::SpotLight* harmony_mono_get_spot_light(harmony::Scene* scene, entt::entity e);

    // Sky
    harmony::SkyComponent* harmony_mono_get_sky(harmony::Scene* scene, entt::entity e);

    // Camera
    harmony::CameraComponent* harmony_mono_get_camera(harmony::Scene* scene, entt::entity e);
}