#include "MonoProgramComponent.h"
#include "MonoAssemblyAssetFactory.h"
#include "MonoUtils.h"
#include "Core/Memory.h"
#include "Core/Program.h"
#include "Core/Log.hpp"
#include "MonoAPI.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "mono/metadata/mono-debug.h"
#include "mono/metadata/threads.h"
#include "mono/metadata/assembly.h"
#include "mono/metadata/reflection.h"
#include "mono/metadata/image.h"
#include "mono/metadata/blob.h"

#include "bgfx/c99/bgfx.h"
harmony::MonoProgramComponent::MonoProgramComponent(
    AssetManager& assetManager,
    Vector<RefCntPtr<MonoInternalMethodProvider>> methodProviders,
    Vector<RefCntPtr<MonoDelegateInvokeProvider>> delegateInvokers
    ) : ProgramComponent(GetTypeHash<MonoProgramComponent>()),
    p_AssemblyConfig(MonoAssemblyConfiguration::Debug),
    m_AssetManager(assetManager),
    p_MethodProviders(methodProviders),
    p_DelegateInvokers(delegateInvokers)

{
    p_RootDomain = nullptr;
}
void harmony::MonoProgramComponent::Init()
{
    log::info("MonoProgramComponent : Initializing");
    // TODO: Change to the project directory
    std::string root(std::getenv("MONO_PATH"));
    std::string assemblyDir = root + "/lib";
    mono_set_assemblies_path(assemblyDir.c_str());

    if(p_RootDomain == nullptr)
    {
        const char* argv[2] = {
                "--debugger-agent=transport=dt_socket,address=127.0.0.1:2550,server=y,suspend=n,loglevel=3,keepalive=10,setpgid=y,logfile=MonoDebugger.log",
                "--soft-breakpoints"
        };


        mono_jit_parse_options(2, (char**)argv);
        log::info("MonoProgramComponent : Initializing Mono Debug");
        mono_debug_init(MONO_DEBUG_FORMAT_MONO);

        log::info("MonoProgramComponent : Creating root domain");
        p_RootDomain = mono_jit_init(p_RootDomainName.c_str());

        if(p_RootDomain == nullptr)
        {
            harmony::log::error("MonoProgramComponent : Failed to create root domain.");
            return;
        }

        log::info("MonoProgramComponent : Creating Debug domain");
        mono_debug_domain_create(p_RootDomain);

        log::info("MonoProgramComponent : Set Mono Thread to current thread");
        mono_thread_set_main(mono_thread_current());
    }

    log::info("MonoProgramComponent : Binding Native Scripting API");
    BindScriptingAPI();

    log::info("MonoProgramComponent : Creating Application Domain");
    char* APP_DOMAIN_CONFIG = nullptr;
    p_AppDomain = mono_domain_create_appdomain((char*) p_AppDomainName.c_str(), APP_DOMAIN_CONFIG);

    if(p_AppDomain == nullptr)
    {
        harmony::log::error("MonoProgramComponent : Failed to create application domain.");
        return;
    }
    log::info("MonoProgramComponent : Set Application Domain");
    mono_domain_set(p_AppDomain, false);
}

void harmony::MonoProgramComponent::Update()
{
    for(MonoImplementedProgramComponent& c : p_MonoProgramComponents)
    {
        if(!c.m_HasUpdate) continue;
        MonoObject* exception = nullptr;
        mono_runtime_invoke(c.p_Update, c.p_MonoObject, nullptr, &exception);

        if(exception != nullptr)
        {
            log::error("MonoProgramComponent : Update : Exception during update for class. TODO improve");
        }
    }
}

void harmony::MonoProgramComponent::Render()
{
}

void harmony::MonoProgramComponent::Cleanup()
{
    for(MonoImplementedProgramComponent& c : p_MonoProgramComponents)
    {
        if(!c.m_HasCleanup) continue;
        MonoObject* exception = nullptr;
        mono_runtime_invoke(c.p_Cleanup, c.p_MonoObject, nullptr, &exception);

        if(exception != nullptr)
        {
            log::error("MonoProgramComponent : Cleanup : Exception during cleanup for class. TODO improve");
        }
    }
    p_MonoProgramComponents.clear();
    mono_domain_set(mono_get_root_domain(), true);
    mono_domain_unload(p_AppDomain);
}

harmony::Json harmony::MonoProgramComponent::ToJson()
{
    auto j = Json();

    auto& scripts = j["program-components"];

    for(auto mpc : p_MonoProgramComponents)
    {
        auto pcJson = Json();
        pcJson["asset"] = mpc.m_AseemblyAsset;
        pcJson["typeInfo"] = mpc.m_TypeInfo;
        scripts.emplace_back(pcJson);
    }

    return j;
}

void harmony::MonoProgramComponent::FromJson(const Json& json)
{
    if(!json.contains("program-components"))
    {
        return;
    }

    for(auto programComponentJson : json["program-components"])
    {
        AssetHandle assemblyAssetHandle = programComponentJson["asset"];
        MonoUtils::CsTypeInfo csTypeInfo = programComponentJson["typeInfo"];

        auto monoAssembly = m_AssetManager.GetAsset<MonoAssemblyAsset>(assemblyAssetHandle).lock();

        if(!monoAssembly)
        {
            log::error("MonoProgramComponent : FromJson : Failed to find mono assembly from {}", assemblyAssetHandle.Path);
            continue;
        }

        AddMonoImplementedProgramComponent(monoAssembly, csTypeInfo);
    }
    auto assemblyHandles = m_AssetManager.GetLoadedAssets<MonoAssemblyAsset>();

    for (auto& handle : assemblyHandles)
    {
        auto assembly = m_AssetManager.GetAsset<MonoAssemblyAsset>(handle).lock();

        if (!assembly)
        {
            continue;
        }

        // Do modules
        for (auto& interfaceImplInfo : assembly->m_InterfaceImplInfos)
        {
            // if derivative of Module
            if (interfaceImplInfo.m_InterfaceNamespace == p_MonoModuleNamespace)
            {
                if (interfaceImplInfo.m_InterfaceName == p_InitInterfaceName)
                {
                    MonoUtils::CsTypeInfo& typeInfo = assembly->m_TypeInfos[interfaceImplInfo.m_ClassIndex];
                    MonoObject* classObject = MonoUtils::CreateMonoObject(p_AppDomain, typeInfo);

                    // Grab interface methods to call
                    MonoClass* instanceClass = mono_object_get_class(classObject);
                    MonoMethod* initMethod = nullptr;

                    initMethod = mono_class_get_method_from_name(instanceClass, p_InitMethodName.c_str(), 0);
                    if (initMethod == nullptr) {
                        log::error("MonoProgramComponent : Init : Module Type {} implements IOnInit but does not have an Init method.", typeInfo.m_TypeName);
                        continue;
                    }

                    MonoObject* exception = nullptr;
                    mono_runtime_invoke(initMethod, classObject, nullptr, &exception);
                    if (exception != nullptr)
                    {
                        MonoClass* exceptionKlass = mono_object_get_class(exception);
                        log::error("MonoProgramComponent : Init : Module : exception encountered during init for type {} : {}", typeInfo.m_TypeName, mono_class_get_name(exceptionKlass));
                    }

                }
            }
        }
    }

	// have to temporarily cache refcntptrs as they are passed over C# as raw ptrs
	harmony_mono_renderer_clear_cached_objects();
}


void harmony::MonoProgramComponent::BindScriptingAPI()
{
    // Log
    mono_add_internal_call("Harmony.Log::Trace", harmony_mono_log_trace);
    mono_add_internal_call("Harmony.Log::Info", harmony_mono_log_info);
    mono_add_internal_call("Harmony.Log::Warn", harmony_mono_log_warn);
    mono_add_internal_call("Harmony.Log::Error", harmony_mono_log_error);

    // Time
    mono_add_internal_call("Harmony.Time::GetFrameTime", harmony_mono_get_frame_time);
    mono_add_internal_call("Harmony.Time::GetFrameTimeUnscaled", harmony_mono_get_frame_time_unscaled);
    mono_add_internal_call("Harmony.Time::GetTimeScale", harmony_mono_get_time_scale);
    mono_add_internal_call("Harmony.Time::SetTimeScale", harmony_mono_set_time_scale);

    // Input
    mono_add_internal_call("Harmony.Input::GetMousePosition", harmony_mono_get_mouse_position);
    mono_add_internal_call("Harmony.Input::GetMousePositionLastFrame", harmony_mono_get_mouse_position_last_frame);
    mono_add_internal_call("Harmony.Input::GetMouseVelocity", harmony_mono_get_mouse_velocity);
    mono_add_internal_call("Harmony.Input::GetMouseVelocityLastFrame", harmony_mono_get_mouse_velocity_last_frame);
    mono_add_internal_call("Harmony.Input::GetMouseButton", harmony_mono_get_mouse_button);
    mono_add_internal_call("Harmony.Input::GetMouseButtonJustPressed", harmony_mono_get_mouse_button_just_pressed);
    mono_add_internal_call("Harmony.Input::GetMouseButtonJustReleased", harmony_mono_get_mouse_button_just_released);
    mono_add_internal_call("Harmony.Input::GetKeyButton", harmony_mono_get_key);
    mono_add_internal_call("Harmony.Input::GetKeyButtonJustPressed", harmony_mono_get_key_just_pressed);
    mono_add_internal_call("Harmony.Input::GetKeyButtonJustReleased", harmony_mono_get_key_just_released);
    mono_add_internal_call("Harmony.Input::GetGamepadButton", harmony_mono_get_gamepad_button);
    mono_add_internal_call("Harmony.Input::GetGamepadButtonJustPressed", harmony_mono_get_gamepad_button_just_pressed);
    mono_add_internal_call("Harmony.Input::GetGamepadButtonJustReleased", harmony_mono_get_gamepad_button_just_released);
    mono_add_internal_call("Harmony.Input::GetGamepadTrigger", harmony_mono_get_gamepad_trigger);
    mono_add_internal_call("Harmony.Input::GetGamepadStick", harmony_mono_get_gamepad_stick);

    // Debug Draw
    mono_add_internal_call("Harmony.DebugDraw::SetColour", harmony_mono_debug_draw_set_colour);
    mono_add_internal_call("Harmony.DebugDraw::SetStipple", harmony_mono_debug_draw_set_stipple);
    mono_add_internal_call("Harmony.DebugDraw::SetWireframe", harmony_mono_debug_draw_set_wireframe);
    mono_add_internal_call("Harmony.DebugDraw::SetTranslate", harmony_mono_debug_draw_set_translate);
    mono_add_internal_call("Harmony.DebugDraw::MoveTo", harmony_mono_debug_draw_move_to);
    mono_add_internal_call("Harmony.DebugDraw::LineTo", harmony_mono_debug_draw_line_to);
    mono_add_internal_call("Harmony.DebugDraw::Circle", harmony_mono_debug_draw_circle);
    mono_add_internal_call("Harmony.DebugDraw::Quad", harmony_mono_debug_draw_quad);
    mono_add_internal_call("Harmony.DebugDraw::Sphere", harmony_mono_debug_draw_sphere);
    mono_add_internal_call("Harmony.DebugDraw::Cylinder", harmony_mono_debug_draw_cylinder);
    mono_add_internal_call("Harmony.DebugDraw::Capsule", harmony_mono_debug_draw_capsule);
    mono_add_internal_call("Harmony.DebugDraw::Cone", harmony_mono_debug_draw_cone);
    mono_add_internal_call("Harmony.DebugDraw::Grid", harmony_mono_debug_draw_grid);
    mono_add_internal_call("Harmony.DebugDraw::Orb", harmony_mono_debug_draw_orb);

    // Vector Graphics
    mono_add_internal_call("Harmony.VectorGraphics::FontFace", harmony_mono_vg_font_face);
    mono_add_internal_call("Harmony.VectorGraphics::FontSize", harmony_mono_vg_font_size);
    mono_add_internal_call("Harmony.VectorGraphics::FontBlur", harmony_mono_vg_font_blur);
    mono_add_internal_call("Harmony.VectorGraphics::Text", harmony_mono_vg_text);
    mono_add_internal_call("Harmony.VectorGraphics::TextLetterSpacing", harmony_mono_vg_text_letter_spacing);
    mono_add_internal_call("Harmony.VectorGraphics::TextLineHeight", harmony_mono_vg_text_line_height);
    mono_add_internal_call("Harmony.VectorGraphics::TextAlign", harmony_mono_vg_text_align);
    mono_add_internal_call("Harmony.VectorGraphics::FontFaceId", harmony_mono_vg_font_face_id);
    mono_add_internal_call("Harmony.VectorGraphics::TextBox", harmony_mono_vg_text_box);
    mono_add_internal_call("Harmony.VectorGraphics::ShapeAntiAlias", harmony_mono_vg_shape_anti_alias);
    mono_add_internal_call("Harmony.VectorGraphics::StrokeColor", harmony_mono_vg_stroke_color);
    mono_add_internal_call("Harmony.VectorGraphics::StrokePaint", harmony_mono_vg_stroke_paint);
    mono_add_internal_call("Harmony.VectorGraphics::FillColor", harmony_mono_vg_fill_color);
    mono_add_internal_call("Harmony.VectorGraphics::FillPaint", harmony_mono_vg_fill_paint);
    mono_add_internal_call("Harmony.VectorGraphics::MiterLimit", harmony_mono_vg_miter_limit);
    mono_add_internal_call("Harmony.VectorGraphics::StrokeWidth", harmony_mono_vg_stroke_width);
    mono_add_internal_call("Harmony.VectorGraphics::LineCap", harmony_mono_vg_line_cap);
    mono_add_internal_call("Harmony.VectorGraphics::LineJoin", harmony_mono_vg_line_join);
    mono_add_internal_call("Harmony.VectorGraphics::GlobalAlpha", harmony_mono_vg_global_alpha);
    mono_add_internal_call("Harmony.VectorGraphics::ResetTransform", harmony_mono_vg_reset_transform);
    mono_add_internal_call("Harmony.VectorGraphics::Transform", harmony_mono_vg_transform);
    mono_add_internal_call("Harmony.VectorGraphics::Translate", harmony_mono_vg_translate);
    mono_add_internal_call("Harmony.VectorGraphics::Rotate", harmony_mono_vg_rotate);
    mono_add_internal_call("Harmony.VectorGraphics::SkewX", harmony_mono_vg_skew_x);
    mono_add_internal_call("Harmony.VectorGraphics::SkewY", harmony_mono_vg_skew_y);
    mono_add_internal_call("Harmony.VectorGraphics::Scale", harmony_mono_vg_scale);
    mono_add_internal_call("Harmony.VectorGraphics::CurrentTransform", harmony_mono_vg_current_transform);
    mono_add_internal_call("Harmony.VectorGraphics::ImageSize", harmony_mono_vg_image_size);
    mono_add_internal_call("Harmony.VectorGraphics::DeleteImage", harmony_mono_vg_delete_image);
    mono_add_internal_call("Harmony.VectorGraphics::Scissor", harmony_mono_vg_scissor);
    mono_add_internal_call("Harmony.VectorGraphics::IntersectScissor", harmony_mono_vg_intersect_scissor);
    mono_add_internal_call("Harmony.VectorGraphics::ResetScissor", harmony_mono_vg_reset_scissor);
    mono_add_internal_call("Harmony.VectorGraphics::BeginPath", harmony_mono_vg_begin_path);
    mono_add_internal_call("Harmony.VectorGraphics::MoveTo", harmony_mono_vg_move_to);
    mono_add_internal_call("Harmony.VectorGraphics::LineTo", harmony_mono_vg_line_to);
    mono_add_internal_call("Harmony.VectorGraphics::BezierTo", harmony_mono_vg_bezier_to);
    mono_add_internal_call("Harmony.VectorGraphics::QuadTo", harmony_mono_vg_quad_to);
    mono_add_internal_call("Harmony.VectorGraphics::ArcTo", harmony_mono_vg_arc_to);
    mono_add_internal_call("Harmony.VectorGraphics::ClosePath", harmony_mono_vg_close_path);
    mono_add_internal_call("Harmony.VectorGraphics::PathWinding", harmony_mono_vg_path_winding);
    mono_add_internal_call("Harmony.VectorGraphics::Arc", harmony_mono_vg_arc);
    mono_add_internal_call("Harmony.VectorGraphics::Rect", harmony_mono_vg_rect);
    mono_add_internal_call("Harmony.VectorGraphics::RoundedRect", harmony_mono_vg_rounded_rect);
    mono_add_internal_call("Harmony.VectorGraphics::RoundedRectVarying", harmony_mono_vg_rounded_rect_varying);
    mono_add_internal_call("Harmony.VectorGraphics::Ellipse", harmony_mono_vg_ellipse);
    mono_add_internal_call("Harmony.VectorGraphics::Circle", harmony_mono_vg_circle);
    mono_add_internal_call("Harmony.VectorGraphics::Fill", harmony_mono_vg_fill);
    mono_add_internal_call("Harmony.VectorGraphics::Stroke", harmony_mono_vg_stroke);
    mono_add_internal_call("Harmony.VectorGraphics::LinearGradient", harmony_mono_vg_linear_gradient);
    mono_add_internal_call("Harmony.VectorGraphics::BoxGradient", harmony_mono_vg_box_gradient);
    mono_add_internal_call("Harmony.VectorGraphics::RadialGradient", harmony_mono_vg_radial_gradient);
    mono_add_internal_call("Harmony.VectorGraphics::ImagePattern", harmony_mono_vg_image_pattern);

    // Assets
    mono_add_internal_call("Harmony.AssetMethods::GetAssetsAtPath", harmony_mono_assets_get_assets_at_path);
    mono_add_internal_call("Harmony.AssetMethods::GetTextureAsset", harmony_mono_assets_get_texture_asset);
    mono_add_internal_call("Harmony.AssetMethods::GetMeshAsset", harmony_mono_assets_get_mesh_asset);

    // Renderer
    mono_add_internal_call("Harmony.Renderer::GetView", harmony_mono_renderer_get_view);
    mono_add_internal_call("Harmony.Renderer::GetViewPipeline", harmony_mono_renderer_get_view_pipeline);
    mono_add_internal_call("Harmony.Renderer::GetShader", harmony_mono_renderer_get_shader);
    mono_add_internal_call("Harmony.Renderer::GetPipelineStageRendererInternal", harmony_mono_renderer_get_pipeline_stage_renderer);

    mono_add_internal_call("Harmony.Renderer::AddFramebuffer", harmony_mono_renderer_pipeline_add_framebuffer);
    mono_add_internal_call("Harmony.Renderer::SetOutputFramebuffer", harmony_mono_renderer_pipeline_set_output_framebuffer);
    mono_add_internal_call("Harmony.Renderer::AddStage", harmony_mono_renderer_pipeline_add_stage);
    mono_add_internal_call("Harmony.Renderer::AddDataSource", harmony_mono_renderer_pipeline_stage_add_data_source);

    mono_add_internal_call("Harmony.Renderer::CreatePipelineDrawStageInternal", harmony_mono_renderer_create_pipeline_draw_stage);
    mono_add_internal_call("Harmony.Renderer::CreateDrawScreenTextureStageInternal", harmony_mono_renderer_create_draw_screen_texture_stage);
    mono_add_internal_call("Harmony.Renderer::CreateSkyStageInternal", harmony_mono_renderer_create_sky_stage);
    mono_add_internal_call("Harmony.Renderer::CreateDebugDrawStageInternal", harmony_mono_renderer_create_debug_draw_stage);
    mono_add_internal_call("Harmony.Renderer::CreateVectorGraphicsStageInternal", harmony_mono_renderer_create_vector_graphics_stage);
    mono_add_internal_call("Harmony.Renderer::CreateScreenQuadRendererInternal", harmony_mono_renderer_create_screen_quad_renderer);
    mono_add_internal_call("Harmony.Renderer::CreateDeferredDataSourceInternal", harmony_mono_renderer_create_deferred_data_source);
    mono_add_internal_call("Harmony.Renderer::CreateTextureAssetSourceInternal", harmony_mono_renderer_create_texture_asset_source);
	mono_add_internal_call("Harmony.Renderer::CreateBlinnPhongDataSourceInternal", harmony_mono_renderer_create_blinn_phong_data_source);

    // Program
    mono_add_internal_call("Harmony.ProgramMethods::GetProgram", harmony_mono_get_program);

    // Scene / ECS
    mono_add_internal_call("Harmony.SceneMethods::GetActiveScene", harmony_mono_get_active_scene);
    mono_add_internal_call("Harmony.SceneMethods::CloseActiveScene", harmony_mono_close_active_scene);
    mono_add_internal_call("Harmony.SceneMethods::LoadScene", harmony_mono_load_scene);
    mono_add_internal_call("Harmony.SceneMethods::SaveScene", harmony_mono_save_scene);
    mono_add_internal_call("Harmony.SceneMethods::CreateEntity", harmony_mono_create_entity);
    mono_add_internal_call("Harmony.SceneMethods::DeleteEntity", harmony_mono_delete_entity);
    mono_add_internal_call("Harmony.SceneMethods::GetEntityByID", harmony_mono_get_entity_by_id);
    mono_add_internal_call("Harmony.SceneMethods::GetEntityByName", harmony_mono_get_entity_by_name);
    mono_add_internal_call("Harmony.SceneMethods::GetEntityScriptBehaviours", harmony_mono_get_entity_script_behaviours);

    // Transform
    mono_add_internal_call("Harmony.ECSMethods::GetEntityTransform", harmony_mono_get_transform);
    mono_add_internal_call("Harmony.ECSMethods::GetTransformPosition", harmony_mono_get_transform_position);
    mono_add_internal_call("Harmony.ECSMethods::GetTransformEuler", harmony_mono_get_transform_euler);
    mono_add_internal_call("Harmony.ECSMethods::GetTransformScale", harmony_mono_get_transform_scale);
    mono_add_internal_call("Harmony.ECSMethods::GetTransformForward", harmony_mono_get_transform_forward);
    mono_add_internal_call("Harmony.ECSMethods::GetTransformRight", harmony_mono_get_transform_right);
    mono_add_internal_call("Harmony.ECSMethods::GetTransformUp", harmony_mono_get_transform_up);
    mono_add_internal_call("Harmony.ECSMethods::SetTransformPosition", harmony_mono_set_transform_position);
    mono_add_internal_call("Harmony.ECSMethods::SetTransformEuler", harmony_mono_set_transform_euler);
    mono_add_internal_call("Harmony.ECSMethods::SetTransformScale", harmony_mono_set_transform_scale);

	// Mesh
    mono_add_internal_call("Harmony.ECSMethods::GetEntityMesh", harmony_mono_get_mesh);
    mono_add_internal_call("Harmony.ECSMethods::GetMeshAsset", harmony_mono_mesh_get_asset);
    mono_add_internal_call("Harmony.ECSMethods::SetMeshAsset", harmony_mono_mesh_set_asset);

	// Material
    mono_add_internal_call("Harmony.ECSMethods::GetEntityMaterial", harmony_mono_get_material);

	// Directional Light
    mono_add_internal_call("Harmony.ECSMethods::GetEntityDirectionalLight", harmony_mono_get_directional_light);
    mono_add_internal_call("Harmony.ECSMethods::GetDirectionalLightDiffuse", harmony_mono_directional_light_get_diffuse);
    mono_add_internal_call("Harmony.ECSMethods::SetDirectionalLightDiffuse", harmony_mono_directional_light_set_diffuse);
	mono_add_internal_call("Harmony.ECSMethods::GetDirectionalLightAmbient", harmony_mono_directional_light_get_ambient);
	mono_add_internal_call("Harmony.ECSMethods::GetDirectionalLightAmbient", harmony_mono_directional_light_get_ambient);
	
    // Point Light
    mono_add_internal_call("Harmony.ECSMethods::GetEntityPointLight", harmony_mono_get_point_light);
	mono_add_internal_call("Harmony.ECSMethods::GetPointLightDiffuse", harmony_mono_point_light_get_diffuse);
	mono_add_internal_call("Harmony.ECSMethods::SetPointLightDiffuse", harmony_mono_point_light_set_diffuse);
	mono_add_internal_call("Harmony.ECSMethods::GetPointLightAmbient", harmony_mono_point_light_get_ambient);
	mono_add_internal_call("Harmony.ECSMethods::GetPointLightAmbient", harmony_mono_point_light_set_ambient);
	mono_add_internal_call("Harmony.ECSMethods::GetPointLightIntensity", harmony_mono_point_light_get_intensity);
	mono_add_internal_call("Harmony.ECSMethods::GetPointLightIntensity", harmony_mono_point_light_get_intensity);
	mono_add_internal_call("Harmony.ECSMethods::GetPointLightRadius", harmony_mono_point_light_get_radius);
	mono_add_internal_call("Harmony.ECSMethods::GetPointLightRadius", harmony_mono_point_light_set_radius);


	// Spot Light
    mono_add_internal_call("Harmony.ECSMethods::GetEntitySpotLight", harmony_mono_get_spot_light);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightDiffuse", harmony_mono_spot_light_get_diffuse);
	mono_add_internal_call("Harmony.ECSMethods::SetSpotLightDiffuse", harmony_mono_spot_light_set_diffuse);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightAmbient", harmony_mono_spot_light_get_ambient);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightAmbient", harmony_mono_spot_light_set_ambient);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightIntensity", harmony_mono_spot_light_get_intensity);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightIntensity", harmony_mono_spot_light_get_intensity);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightRadius", harmony_mono_spot_light_get_radius);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightRadius", harmony_mono_spot_light_set_radius);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightAngle", harmony_mono_spot_light_get_angle);
	mono_add_internal_call("Harmony.ECSMethods::GetSpotLightAngle", harmony_mono_spot_light_set_angle);

	// Sky
    mono_add_internal_call("Harmony.ECSMethods::GetEntitySky", harmony_mono_get_sky);
    mono_add_internal_call("Harmony.ECSMethods::GetSkySunSize", harmony_mono_get_sky_sun_size);
    mono_add_internal_call("Harmony.ECSMethods::GetSkySunBloom", harmony_mono_get_sky_sun_bloom);
    mono_add_internal_call("Harmony.ECSMethods::GetSkyExposition", harmony_mono_get_sky_exposition);
    mono_add_internal_call("Harmony.ECSMethods::GetSkyTurbidity", harmony_mono_get_sky_turbidity);
    mono_add_internal_call("Harmony.ECSMethods::GetSkyLuminance", harmony_mono_get_sky_luminance);
	mono_add_internal_call("Harmony.ECSMethods::SetSkySunSize", harmony_mono_set_sky_sun_size);
	mono_add_internal_call("Harmony.ECSMethods::SetSkySunBloom", harmony_mono_set_sky_sun_bloom);
	mono_add_internal_call("Harmony.ECSMethods::SetSkyExposition", harmony_mono_set_sky_exposition);
	mono_add_internal_call("Harmony.ECSMethods::SetSkyTurbidity", harmony_mono_set_sky_turbidity);
	mono_add_internal_call("Harmony.ECSMethods::SetSkyLuminance", harmony_mono_set_sky_luminance);

	// Camera
    mono_add_internal_call("Harmony.ECSMethods::GetEntityCamera", harmony_mono_get_camera);

    // BGFX
    mono_add_internal_call("Harmony.bgfx::attachment_init", bgfx_attachment_init);
    mono_add_internal_call("Harmony.bgfx::vertex_layout_begin", bgfx_vertex_layout_begin);
    mono_add_internal_call("Harmony.bgfx::vertex_layout_add", bgfx_vertex_layout_add);
    mono_add_internal_call("Harmony.bgfx::vertex_layout_decode", bgfx_vertex_layout_decode);
    mono_add_internal_call("Harmony.bgfx::vertex_layout_has", bgfx_vertex_layout_has);
    mono_add_internal_call("Harmony.bgfx::vertex_layout_skip", bgfx_vertex_layout_skip);
    mono_add_internal_call("Harmony.bgfx::vertex_layout_end", bgfx_vertex_layout_end);
    mono_add_internal_call("Harmony.bgfx::vertex_pack", bgfx_vertex_pack);
    mono_add_internal_call("Harmony.bgfx::vertex_unpack", bgfx_vertex_unpack);
    mono_add_internal_call("Harmony.bgfx::vertex_convert", bgfx_vertex_convert);
    mono_add_internal_call("Harmony.bgfx::weld_vertices", bgfx_weld_vertices);
    mono_add_internal_call("Harmony.bgfx::topology_convert", bgfx_topology_convert);
    mono_add_internal_call("Harmony.bgfx::topology_sort_tri_list", bgfx_topology_sort_tri_list);
    mono_add_internal_call("Harmony.bgfx::get_supported_renderers", bgfx_get_supported_renderers);
    mono_add_internal_call("Harmony.bgfx::get_renderer_name", bgfx_get_renderer_name);
    mono_add_internal_call("Harmony.bgfx::init_ctor", bgfx_init_ctor);
    mono_add_internal_call("Harmony.bgfx::init", bgfx_init);
    mono_add_internal_call("Harmony.bgfx::shutdown", bgfx_shutdown);
    mono_add_internal_call("Harmony.bgfx::reset", bgfx_reset);
    mono_add_internal_call("Harmony.bgfx::frame", bgfx_frame);
    mono_add_internal_call("Harmony.bgfx::get_renderer_type", bgfx_get_renderer_type);
    mono_add_internal_call("Harmony.bgfx::get_caps", bgfx_get_caps);
    mono_add_internal_call("Harmony.bgfx::get_stats", bgfx_get_stats);
    mono_add_internal_call("Harmony.bgfx::alloc", bgfx_alloc);
    mono_add_internal_call("Harmony.bgfx::copy", bgfx_copy);
    mono_add_internal_call("Harmony.bgfx::make_ref", bgfx_make_ref);
    mono_add_internal_call("Harmony.bgfx::make_ref_release", bgfx_make_ref_release);
    mono_add_internal_call("Harmony.bgfx::set_debug", bgfx_set_debug);
    mono_add_internal_call("Harmony.bgfx::dbg_text_clear", bgfx_dbg_text_clear);
    mono_add_internal_call("Harmony.bgfx::dbg_text_printf", bgfx_dbg_text_printf);
    mono_add_internal_call("Harmony.bgfx::dbg_text_vprintf", bgfx_dbg_text_vprintf);
    mono_add_internal_call("Harmony.bgfx::dbg_text_image", bgfx_dbg_text_image);
    mono_add_internal_call("Harmony.bgfx::create_index_buffer", bgfx_create_index_buffer);
    mono_add_internal_call("Harmony.bgfx::set_index_buffer_name", bgfx_set_index_buffer_name);
    mono_add_internal_call("Harmony.bgfx::destroy_index_buffer", bgfx_destroy_index_buffer);
    mono_add_internal_call("Harmony.bgfx::create_vertex_layout", bgfx_create_vertex_layout);
    mono_add_internal_call("Harmony.bgfx::destroy_vertex_layout", bgfx_destroy_vertex_layout);
    mono_add_internal_call("Harmony.bgfx::create_vertex_buffer", bgfx_create_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::set_vertex_buffer_name", bgfx_set_vertex_buffer_name);
    mono_add_internal_call("Harmony.bgfx::destroy_vertex_buffer", bgfx_destroy_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::create_dynamic_index_buffer", bgfx_create_dynamic_index_buffer);
    mono_add_internal_call("Harmony.bgfx::create_dynamic_index_buffer_mem", bgfx_create_dynamic_index_buffer_mem);
    mono_add_internal_call("Harmony.bgfx::update_dynamic_index_buffer", bgfx_update_dynamic_index_buffer);
    mono_add_internal_call("Harmony.bgfx::destroy_dynamic_index_buffer", bgfx_destroy_dynamic_index_buffer);
    mono_add_internal_call("Harmony.bgfx::create_dynamic_vertex_buffer", bgfx_create_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::create_dynamic_vertex_buffer_mem", bgfx_create_dynamic_vertex_buffer_mem);
    mono_add_internal_call("Harmony.bgfx::update_dynamic_vertex_buffer", bgfx_update_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::destroy_dynamic_vertex_buffer", bgfx_destroy_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::get_avail_transient_index_buffer", bgfx_get_avail_transient_index_buffer);
    mono_add_internal_call("Harmony.bgfx::get_avail_transient_vertex_buffer", bgfx_get_avail_transient_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::get_avail_instance_data_buffer", bgfx_get_avail_instance_data_buffer);
    mono_add_internal_call("Harmony.bgfx::alloc_transient_index_buffer", bgfx_alloc_transient_index_buffer);
    mono_add_internal_call("Harmony.bgfx::alloc_transient_vertex_buffer", bgfx_alloc_transient_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::alloc_transient_buffers", bgfx_alloc_transient_buffers);
    mono_add_internal_call("Harmony.bgfx::alloc_instance_data_buffer", bgfx_alloc_instance_data_buffer);
    mono_add_internal_call("Harmony.bgfx::create_indirect_buffer", bgfx_create_indirect_buffer);
    mono_add_internal_call("Harmony.bgfx::destroy_indirect_buffer", bgfx_destroy_indirect_buffer);
    mono_add_internal_call("Harmony.bgfx::create_shader", bgfx_create_shader);
    mono_add_internal_call("Harmony.bgfx::get_shader_uniforms", bgfx_get_shader_uniforms);
    mono_add_internal_call("Harmony.bgfx::set_shader_name", bgfx_set_shader_name);
    mono_add_internal_call("Harmony.bgfx::destroy_shader", bgfx_destroy_shader);
    mono_add_internal_call("Harmony.bgfx::create_program", bgfx_create_program);
    mono_add_internal_call("Harmony.bgfx::create_compute_program", bgfx_create_compute_program);
    mono_add_internal_call("Harmony.bgfx::destroy_program", bgfx_destroy_program);
    mono_add_internal_call("Harmony.bgfx::is_texture_valid", bgfx_is_texture_valid);
    mono_add_internal_call("Harmony.bgfx::is_frame_buffer_valid", bgfx_is_frame_buffer_valid);
    mono_add_internal_call("Harmony.bgfx::calc_texture_size", bgfx_calc_texture_size);
    mono_add_internal_call("Harmony.bgfx::create_texture", bgfx_create_texture);
    mono_add_internal_call("Harmony.bgfx::create_texture_2d", bgfx_create_texture_2d);
    mono_add_internal_call("Harmony.bgfx::create_texture_2d_scaled", bgfx_create_texture_2d_scaled);
    mono_add_internal_call("Harmony.bgfx::create_texture_3d", bgfx_create_texture_3d);
    mono_add_internal_call("Harmony.bgfx::create_texture_cube", bgfx_create_texture_cube);
    mono_add_internal_call("Harmony.bgfx::update_texture_2d", bgfx_update_texture_2d);
    mono_add_internal_call("Harmony.bgfx::update_texture_3d", bgfx_update_texture_3d);
    mono_add_internal_call("Harmony.bgfx::update_texture_cube", bgfx_update_texture_cube);
    mono_add_internal_call("Harmony.bgfx::read_texture", bgfx_read_texture);
    mono_add_internal_call("Harmony.bgfx::set_texture_name", bgfx_set_texture_name);
    mono_add_internal_call("Harmony.bgfx::get_direct_access_ptr", bgfx_get_direct_access_ptr);
    mono_add_internal_call("Harmony.bgfx::destroy_texture", bgfx_destroy_texture);
    mono_add_internal_call("Harmony.bgfx::create_frame_buffer", bgfx_create_frame_buffer);
    mono_add_internal_call("Harmony.bgfx::create_frame_buffer_scaled", bgfx_create_frame_buffer_scaled);
    mono_add_internal_call("Harmony.bgfx::create_frame_buffer_from_handles", bgfx_create_frame_buffer_from_handles);
    mono_add_internal_call("Harmony.bgfx::create_frame_buffer_from_attachment", bgfx_create_frame_buffer_from_attachment);
    mono_add_internal_call("Harmony.bgfx::create_frame_buffer_from_nwh", bgfx_create_frame_buffer_from_nwh);
    mono_add_internal_call("Harmony.bgfx::set_frame_buffer_name", bgfx_set_frame_buffer_name);
    mono_add_internal_call("Harmony.bgfx::get_texture", bgfx_get_texture);
    mono_add_internal_call("Harmony.bgfx::destroy_frame_buffer", bgfx_destroy_frame_buffer);
    mono_add_internal_call("Harmony.bgfx::create_uniform", bgfx_create_uniform);
    mono_add_internal_call("Harmony.bgfx::get_uniform_info", bgfx_get_uniform_info);
    mono_add_internal_call("Harmony.bgfx::destroy_uniform", bgfx_destroy_uniform);
    mono_add_internal_call("Harmony.bgfx::create_occlusion_query", bgfx_create_occlusion_query);
    mono_add_internal_call("Harmony.bgfx::get_result", bgfx_get_result);
    mono_add_internal_call("Harmony.bgfx::destroy_occlusion_query", bgfx_destroy_occlusion_query);
    mono_add_internal_call("Harmony.bgfx::set_palette_color", bgfx_set_palette_color);
    mono_add_internal_call("Harmony.bgfx::set_palette_color_rgba8", bgfx_set_palette_color_rgba8);
    mono_add_internal_call("Harmony.bgfx::set_view_name", bgfx_set_view_name);
    mono_add_internal_call("Harmony.bgfx::set_view_rect", bgfx_set_view_rect);
    mono_add_internal_call("Harmony.bgfx::set_view_rect_ratio", bgfx_set_view_rect_ratio);
    mono_add_internal_call("Harmony.bgfx::set_view_scissor", bgfx_set_view_scissor);
    mono_add_internal_call("Harmony.bgfx::set_view_clear", bgfx_set_view_clear);
    mono_add_internal_call("Harmony.bgfx::set_view_clear_mrt", bgfx_set_view_clear_mrt);
    mono_add_internal_call("Harmony.bgfx::set_view_mode", bgfx_set_view_mode);
    mono_add_internal_call("Harmony.bgfx::set_view_frame_buffer", bgfx_set_view_frame_buffer);
    mono_add_internal_call("Harmony.bgfx::set_view_transform", bgfx_set_view_transform);
    mono_add_internal_call("Harmony.bgfx::set_view_order", bgfx_set_view_order);
    mono_add_internal_call("Harmony.bgfx::reset_view", bgfx_reset_view);
    mono_add_internal_call("Harmony.bgfx::encoder_begin", bgfx_encoder_begin);
    mono_add_internal_call("Harmony.bgfx::encoder_end", bgfx_encoder_end);
    mono_add_internal_call("Harmony.bgfx::encoder_set_marker", bgfx_encoder_set_marker);
    mono_add_internal_call("Harmony.bgfx::encoder_set_state", bgfx_encoder_set_state);
    mono_add_internal_call("Harmony.bgfx::encoder_set_condition", bgfx_encoder_set_condition);
    mono_add_internal_call("Harmony.bgfx::encoder_set_stencil", bgfx_encoder_set_stencil);
    mono_add_internal_call("Harmony.bgfx::encoder_set_scissor", bgfx_encoder_set_scissor);
    mono_add_internal_call("Harmony.bgfx::encoder_set_scissor_cached", bgfx_encoder_set_scissor_cached);
    mono_add_internal_call("Harmony.bgfx::encoder_set_transform", bgfx_encoder_set_transform);
    mono_add_internal_call("Harmony.bgfx::encoder_set_transform_cached", bgfx_encoder_set_transform_cached);
    mono_add_internal_call("Harmony.bgfx::encoder_alloc_transform", bgfx_encoder_alloc_transform);
    mono_add_internal_call("Harmony.bgfx::encoder_set_uniform", bgfx_encoder_set_uniform);
    mono_add_internal_call("Harmony.bgfx::encoder_set_index_buffer", bgfx_encoder_set_index_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_dynamic_index_buffer", bgfx_encoder_set_dynamic_index_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_transient_index_buffer", bgfx_encoder_set_transient_index_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_vertex_buffer", bgfx_encoder_set_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_vertex_buffer_with_layout", bgfx_encoder_set_vertex_buffer_with_layout);
    mono_add_internal_call("Harmony.bgfx::encoder_set_dynamic_vertex_buffer", bgfx_encoder_set_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_dynamic_vertex_buffer_with_layout", bgfx_encoder_set_dynamic_vertex_buffer_with_layout);
    mono_add_internal_call("Harmony.bgfx::encoder_set_transient_vertex_buffer", bgfx_encoder_set_transient_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_transient_vertex_buffer_with_layout", bgfx_encoder_set_transient_vertex_buffer_with_layout);
    mono_add_internal_call("Harmony.bgfx::encoder_set_vertex_count", bgfx_encoder_set_vertex_count);
    mono_add_internal_call("Harmony.bgfx::encoder_set_instance_data_buffer", bgfx_encoder_set_instance_data_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_instance_data_from_vertex_buffer", bgfx_encoder_set_instance_data_from_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_instance_data_from_dynamic_vertex_buffer", bgfx_encoder_set_instance_data_from_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_instance_count", bgfx_encoder_set_instance_count);
    mono_add_internal_call("Harmony.bgfx::encoder_set_texture", bgfx_encoder_set_texture);
    mono_add_internal_call("Harmony.bgfx::encoder_touch", bgfx_encoder_touch);
    mono_add_internal_call("Harmony.bgfx::encoder_submit", bgfx_encoder_submit);
    mono_add_internal_call("Harmony.bgfx::encoder_submit_occlusion_query", bgfx_encoder_submit_occlusion_query);
    mono_add_internal_call("Harmony.bgfx::encoder_submit_indirect", bgfx_encoder_submit_indirect);
    mono_add_internal_call("Harmony.bgfx::encoder_submit_indirect_count", bgfx_encoder_submit_indirect_count);
    mono_add_internal_call("Harmony.bgfx::encoder_set_compute_index_buffer", bgfx_encoder_set_compute_index_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_compute_vertex_buffer", bgfx_encoder_set_compute_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_compute_dynamic_index_buffer", bgfx_encoder_set_compute_dynamic_index_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_compute_dynamic_vertex_buffer", bgfx_encoder_set_compute_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_compute_indirect_buffer", bgfx_encoder_set_compute_indirect_buffer);
    mono_add_internal_call("Harmony.bgfx::encoder_set_image", bgfx_encoder_set_image);
    mono_add_internal_call("Harmony.bgfx::encoder_dispatch", bgfx_encoder_dispatch);
    mono_add_internal_call("Harmony.bgfx::encoder_dispatch_indirect", bgfx_encoder_dispatch_indirect);
    mono_add_internal_call("Harmony.bgfx::encoder_discard", bgfx_encoder_discard);
    mono_add_internal_call("Harmony.bgfx::encoder_blit", bgfx_encoder_blit);
    mono_add_internal_call("Harmony.bgfx::request_screen_shot", bgfx_request_screen_shot);
    mono_add_internal_call("Harmony.bgfx::render_frame", bgfx_render_frame);
    mono_add_internal_call("Harmony.bgfx::set_platform_data", bgfx_set_platform_data);
    mono_add_internal_call("Harmony.bgfx::get_internal_data", bgfx_get_internal_data);
    mono_add_internal_call("Harmony.bgfx::override_internal_texture_ptr", bgfx_override_internal_texture_ptr);
    mono_add_internal_call("Harmony.bgfx::override_internal_texture", bgfx_override_internal_texture);
    mono_add_internal_call("Harmony.bgfx::set_marker", bgfx_set_marker);
    mono_add_internal_call("Harmony.bgfx::set_state", bgfx_set_state);
    mono_add_internal_call("Harmony.bgfx::set_condition", bgfx_set_condition);
    mono_add_internal_call("Harmony.bgfx::set_stencil", bgfx_set_stencil);
    mono_add_internal_call("Harmony.bgfx::set_scissor", bgfx_set_scissor);
    mono_add_internal_call("Harmony.bgfx::set_scissor_cached", bgfx_set_scissor_cached);
    mono_add_internal_call("Harmony.bgfx::set_transform", bgfx_set_transform);
    mono_add_internal_call("Harmony.bgfx::set_transform_cached", bgfx_set_transform_cached);
    mono_add_internal_call("Harmony.bgfx::alloc_transform", bgfx_alloc_transform);
    mono_add_internal_call("Harmony.bgfx::set_uniform", bgfx_set_uniform);
    mono_add_internal_call("Harmony.bgfx::set_index_buffer", bgfx_set_index_buffer);
    mono_add_internal_call("Harmony.bgfx::set_dynamic_index_buffer", bgfx_set_dynamic_index_buffer);
    mono_add_internal_call("Harmony.bgfx::set_transient_index_buffer", bgfx_set_transient_index_buffer);
    mono_add_internal_call("Harmony.bgfx::set_vertex_buffer", bgfx_set_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::set_vertex_buffer_with_layout", bgfx_set_vertex_buffer_with_layout);
    mono_add_internal_call("Harmony.bgfx::set_dynamic_vertex_buffer", bgfx_set_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::set_dynamic_vertex_buffer_with_layout", bgfx_set_dynamic_vertex_buffer_with_layout);
    mono_add_internal_call("Harmony.bgfx::set_transient_vertex_buffer", bgfx_set_transient_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::set_transient_vertex_buffer_with_layout", bgfx_set_transient_vertex_buffer_with_layout);
    mono_add_internal_call("Harmony.bgfx::set_vertex_count", bgfx_set_vertex_count);
    mono_add_internal_call("Harmony.bgfx::set_instance_data_buffer", bgfx_set_instance_data_buffer);
    mono_add_internal_call("Harmony.bgfx::set_instance_data_from_vertex_buffer", bgfx_set_instance_data_from_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::set_instance_data_from_dynamic_vertex_buffer", bgfx_set_instance_data_from_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::set_instance_count", bgfx_set_instance_count);
    mono_add_internal_call("Harmony.bgfx::set_texture", bgfx_set_texture);
    mono_add_internal_call("Harmony.bgfx::touch", bgfx_touch);
    mono_add_internal_call("Harmony.bgfx::submit", bgfx_submit);
    mono_add_internal_call("Harmony.bgfx::submit_occlusion_query", bgfx_submit_occlusion_query);
    mono_add_internal_call("Harmony.bgfx::submit_indirect", bgfx_submit_indirect);
    mono_add_internal_call("Harmony.bgfx::submit_indirect_count", bgfx_submit_indirect_count);
    mono_add_internal_call("Harmony.bgfx::set_compute_index_buffer", bgfx_set_compute_index_buffer);
    mono_add_internal_call("Harmony.bgfx::set_compute_vertex_buffer", bgfx_set_compute_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::set_compute_dynamic_index_buffer", bgfx_set_compute_dynamic_index_buffer);
    mono_add_internal_call("Harmony.bgfx::set_compute_dynamic_vertex_buffer", bgfx_set_compute_dynamic_vertex_buffer);
    mono_add_internal_call("Harmony.bgfx::set_compute_indirect_buffer", bgfx_set_compute_indirect_buffer);
    mono_add_internal_call("Harmony.bgfx::set_image", bgfx_set_image);
    mono_add_internal_call("Harmony.bgfx::dispatch", bgfx_dispatch);
    mono_add_internal_call("Harmony.bgfx::dispatch_indirect", bgfx_dispatch_indirect);
    mono_add_internal_call("Harmony.bgfx::discard", bgfx_discard);
    mono_add_internal_call("Harmony.bgfx::blit", bgfx_blit);

    for(RefCntPtr<MonoInternalMethodProvider> mp : p_MethodProviders)
    {
        if(mp)
        {
            mp->BindInternalMethods();
            mp.reset();
        }
    }

}

MonoType* harmony::MonoProgramComponent::GetType(String& name)
{

//	/* we start the count from 1 because we skip the special type <Module> */
//	for (i = 1; i < rows; ++i) {
//		klass = mono_class_get(image, (i + 1) | MONO_TOKEN_TYPE_DEF);
//		printf("Class name: %s.%s\n", mono_class_get_namespace(klass),
//			mono_class_get_name(klass));
//	}
//}
    auto monoAssemblies = m_AssetManager.GetLoadedAssets<MonoAssemblyAsset>();

    for (auto h : monoAssemblies)
    {
        RefCntPtr<MonoAssemblyAsset> assembly = m_AssetManager.GetAsset<MonoAssemblyAsset>(h).lock();
        MonoImage* img =  mono_assembly_get_image(assembly->p_MonoAssembly);

        /*
        int rows = mono_image_get_table_rows(img, MONO_TABLE_TYPEDEF);
		for (int i = 1; i < rows; ++i) {
            MonoClass* klass = mono_class_get(img, (i | MonoMetaTableEnum::MONO_TABLE_TYPEDEF));
			log::info("Class name: %s.%s\n", mono_class_get_namespace(klass),
			mono_class_get_name(klass));
		}
        */
        MonoType* t = mono_reflection_type_from_name(name.data(), img);
        if (t != nullptr)
        {
            return t;
        }
    }
    return nullptr;
}

MonoDomain* harmony::MonoProgramComponent::GetAppDomain()
{
    return p_AppDomain;
}

void
harmony::MonoProgramComponent::AddMonoImplementedProgramComponent(harmony::WeakPtr<harmony::MonoAssemblyAsset> assembly,
                                                                  harmony::MonoUtils::CsTypeInfo typeInfo) {

    for(auto c : p_MonoProgramComponents)
    {
        if(c.m_TypeInfo == typeInfo)
        {
            log::warn("MonoProgramComponent : AddMonoImplementedProgramComponent : Already created a program component of type {}", typeInfo.m_TypeName);
            return;
        }
    }

    auto a = assembly.lock();
    if(!a)
    {
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Assembly is expired");
        return;
    }
    // Ensure type implements one of the program component behaviours
    bool implementsInit = false;
    bool implementsUpdate = false;
    bool implementsCleanup = false;

    for(MonoUtils::CsInterfaceImplInfo interfaceInfo : a->m_InterfaceImplInfos)    {
        if( interfaceInfo.m_ClassName == typeInfo.m_TypeName &&
            interfaceInfo.m_ClassNamespace == typeInfo.m_TypeNamespace)        {
            if(interfaceInfo.m_InterfaceNamespace == p_MonoProgramComponentNamespace) {
                if(interfaceInfo.m_InterfaceName == p_InitInterfaceName) {
                    implementsInit = true;
                }
                if(interfaceInfo.m_InterfaceName == p_UpdateInterfaceName) {
                    implementsUpdate = true;
                }
                if(interfaceInfo.m_InterfaceName == p_CleanupInterfaceName) {
                    implementsCleanup = true;
                }
            }
        }
    }
    if(!implementsInit && !implementsUpdate && !implementsCleanup)    {
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} does not implement any ProgramComponent aspects.", typeInfo.m_TypeName);
        return;
    }

    if(!typeInfo.m_MonoClass)
    {
        typeInfo.m_MonoClass = MonoUtils::GetClassInAssembly(a->p_MonoAssembly, typeInfo.m_TypeNamespace.c_str(), typeInfo.m_TypeName.c_str());
    }

    if(!typeInfo.m_MonoClass)
    {
        log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Could not find MonoClass for Type {}", typeInfo.m_TypeName);
        return;
    }

    // Create instance
    MonoObject* classObject   = MonoUtils::CreateMonoObject(p_AppDomain, typeInfo);

    // Grab interface methods to call
    MonoClass * instanceClass = mono_object_get_class(classObject);
    MonoMethod* initMethod      = nullptr;
    MonoMethod* updateMethod    = nullptr;
    MonoMethod* cleanupMethod   = nullptr;

    if(implementsInit)    {
        initMethod = mono_class_get_method_from_name(instanceClass, p_InitMethodName.c_str(), 0);
        if(initMethod == nullptr) {
            log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} implements IOnInit but does not have an Init method.", typeInfo.m_TypeName);
            return;
        }
        MonoObject * exception = nullptr;
        mono_runtime_invoke(initMethod, classObject, nullptr, &exception);
        if(exception != nullptr)
        {
            log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : exception encountered during init for type {}", typeInfo.m_TypeName);
        }
    }

    if(implementsUpdate)    {
        updateMethod = mono_class_get_method_from_name(instanceClass, p_UpdateMethodName.c_str(), 0);
        if(updateMethod == nullptr) {
            log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} implements IOnUpdate but does not have an Update method.", typeInfo.m_TypeName);
            return;
        }
    }

    if(implementsCleanup) {
        cleanupMethod = mono_class_get_method_from_name(instanceClass, p_CleanupMethodName.c_str(), 0);
        if(cleanupMethod == nullptr) {
            log::error("MonoProgramComponent : AddMonoImplementedProgramComponent : Type {} implements IOnCleanup but does not have a Cleanup method.", typeInfo.m_TypeName);
            return;
        }
    }

    // Wrap in MonoImplementedProgramComponent
    MonoImplementedProgramComponent c = MonoImplementedProgramComponent(typeInfo, a->m_Handle, classObject, initMethod, updateMethod, cleanupMethod);

    // add to collection
    p_MonoProgramComponents.emplace_back(c);
}

harmony::MonoImplementedProgramComponent::~MonoImplementedProgramComponent() {
}

harmony::MonoImplementedProgramComponent::MonoImplementedProgramComponent(MonoUtils::CsTypeInfo typeInfo, AssetHandle assemblyAssetHandle, MonoObject *object, MonoMethod *init,
                                                                          MonoMethod *update, MonoMethod *cleanup) : p_MonoObject(object), m_AseemblyAsset(assemblyAssetHandle),
                                                                                                                     m_TypeInfo(typeInfo)
{
    p_Init = init;
    m_HasInit = p_Init != nullptr;
    p_Update = update;
    m_HasUpdate = p_Update != nullptr;
    p_Cleanup = cleanup;
    m_HasCleanup = p_Cleanup != nullptr;
}
