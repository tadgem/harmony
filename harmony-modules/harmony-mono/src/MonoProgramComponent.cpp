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

nlohmann::json harmony::MonoProgramComponent::ToJson()
{
    auto j = nlohmann::json();

    auto& scripts = j["program-components"];

    for(auto mpc : p_MonoProgramComponents)
    {
        auto pcJson = nlohmann::json();
        pcJson["asset"] = mpc.m_AseemblyAsset;
        pcJson["typeInfo"] = mpc.m_TypeInfo;
        scripts.emplace_back(pcJson);
    }

    return j;
}

void harmony::MonoProgramComponent::FromJson(const nlohmann::json& json)
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

    // Debug


    // Program
    mono_add_internal_call("Harmony.ProgramMethods::GetProgram", harmony_mono_get_program);

    // Scene / ECS
    mono_add_internal_call("Harmony.SceneMethods::GetActiveScene", harmony_mono_get_active_scene);
    mono_add_internal_call("Harmony.SceneMethods::CloseActiveScene", harmony_mono_close_active_scene);
    mono_add_internal_call("Harmony.SceneMethods::LoadScene", harmony_mono_load_scene);
    mono_add_internal_call("Harmony.SceneMethods::SaveScene", harmony_mono_save_scene);

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
    auto monoAssemblies = m_AssetManager.GetLoadedAssets<MonoAssemblyAsset>();

    for (auto h : monoAssemblies)
    {
        RefCntPtr<MonoAssemblyAsset> assembly = m_AssetManager.GetAsset<MonoAssemblyAsset>(h).lock();
        MonoImage* img =  mono_assembly_get_image(assembly->p_MonoAssembly);
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
