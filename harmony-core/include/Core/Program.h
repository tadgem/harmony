#pragma once
#include "STL/TypeTraits.h"
#include "STL/String.h"
#include "STL/Vector.h"
#include "STL/Functional.h"
#include "bx/platform.h"

#	if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
#define SDL_VIDEO_DRIVER_X11
#endif

#include "SDL.h"

#undef main

#include "Core/Thread.h"
#include "Core/Memory.h"
#include "Core/ProgramComponent.h"
#include "Assets/AssetManager.h"
#include "Rendering/Renderer.h"
#include "Core/Scene.h"
#include "ECS/System.h"
#include "Project.h"
#include "Core/BGFXDebugCallback.h"
#include "ImGui/imgui.h"

namespace harmony {

    // Forward defs
    class EntityTemplate;

    /// <summary>
    /// Top level container for program
    /// </summary>
    class Program {
    public:
        Program(const String &name);

        ~Program();

        virtual void Init();

        void PreRunInit();

        virtual void Run();

        virtual void Run(const String &projectPath);

        virtual void Exit();

        virtual void CreateProject(const String &name, const String &path);

        virtual void SaveProject();

        virtual void LoadProject(const String &path);

        virtual void CloseActiveProject();

        virtual void CreateScene(const String &name);

        virtual void SaveScene(const String &path);

        virtual void LoadScene(const String &path);

        virtual void OpenScene(uint32_t index);

        virtual void CloseActiveScene();

        WeakPtr<Scene> GetActiveScene();

        void RunProgramComponentInit();

        void RunProgramComponentUpdate();

        void RunProgramComponentRender();

        void RunProgramComponentCleanup();

        void RunSystemInit();

        void RunSystemUpdate();

        void RunSystemRender();

        void RunSystemCleanup();

        void RunRendererPreUpdate();

        void RunRendererPostUpdate();

        String GetWorkingDirectory();

        SDL_Window* GetWindow() const;

        const Vector<RefCntPtr<System>>& GetSystems();
    protected:

        virtual void LoadBuiltInAssets();

        virtual void SetupBGFXCapabilities(bgfx::Init &init);

        String GetVendorName(uint16_t vendorId);

        void ChangeWorkingDirectory(const String &directory);

        void Cleanup();

        void InitSDL();

        void InitBGFX();

        void InitImGui();


        void UpdateTimeVariables();

        void ProfilerBeginFrame();

        void RunProgramLoop();

        virtual void ResizeApplicationWindow(int w, int h);

        void HandleSDLEvent();

        void HandleInputEvent(SDL_Event &event);

        void ImGuiPreUpdate();

        void ImGuiPostUpdate();

        void SetStyle();

        void ListCapabilities();

        void SaveImGuiSettings();

        void LoadImGuiSettings();

        void UpdateProjectDirectory(const String &path);

        void Frame();


        String p_AppName;
        String p_LoadedProjectPath;
        Vector<RefCntPtr<ProgramComponent>> p_ProgramComponents;
        Vector<RefCntPtr<System>> p_ECSSystems;
        RefCntPtr<Scene> p_ActiveScene;
        bool p_Run;
        bool p_ResizedThisFrame;
        float p_DPIScale;
        SDL_Window *p_Window;
        bx::DefaultAllocator *p_ImGuiAllocator;
        BgfxCallback p_DebugCallback;
        inline static Program *s_Instance = nullptr;
    public:
        inline static uint16_t p_WindowWidth;
        inline static uint16_t p_WindowHeight;

        template<typename T, typename ... Args>
        WeakPtr<T> AddProgramComponent(Args &&... args) {

            static_assert(IsBaseOf<ProgramComponent, T>());
            RefCntPtr<T> pc = CreateRef<T>(Forward<Args>(args)...);
            p_ProgramComponents.emplace_back(pc);
            return GetWeakRef<T>(pc);
        }

        template<typename T, typename ... Args>
        WeakPtr<T> AddSystem(Args &&... args) {

            static_assert(IsBaseOf<System, T>());
            HashString typeHash = GetTypeHash<T>();
            log::info("Program : Adding System : {}", GetTypeName<T>());
            for(int i = 0; i < p_ECSSystems.size(); i++)
            {
                if(p_ECSSystems[i]->m_TypeHash == typeHash)
                {
                    log::warn("Program : Already have a system with type hash : {}", typeHash.m_Value);
                    return WeakPtr<T>();
                }
            }
            RefCntPtr<T> sys = CreateRef<T>(Forward<Args>(args)...);
            p_ECSSystems.emplace_back(sys);
            return GetWeakRef<T>(sys);
        }

        template<typename T>
        WeakPtr<T> GetProgramComponent() {

            static_assert(IsBaseOf<ProgramComponent, T>(), "Not a program component");
            int index = -1;
            for (int i = 0; i < p_ProgramComponents.size(); i++) {
                HashString typeHash = GetTypeHash<T>();
                if (typeHash == p_ProgramComponents[i]->m_TypeHash)
                {
                    index = i;
                    break;
                }
            }

            if (index >= 0) {
                return SmartPointerCast<T, ProgramComponent>(p_ProgramComponents[index]);
            } else {
                return WeakPtr<T>();
            }
        }

        WeakPtr<ProgramComponent> GetProgramComponent(HashString typeHash)
        {
            int index = -1;
            for (int i = 0; i < p_ProgramComponents.size(); i++) {
                if (typeHash == p_ProgramComponents[i]->m_TypeHash)
                {
                    index = i;
                    break;
                }
            }

            if (index >= 0) {
                return p_ProgramComponents[index];
            } else {
                return WeakPtr<ProgramComponent>();
            }
        }

        template<typename T>
        WeakPtr<T> GetSystem() {

            static_assert(IsBaseOf<System, T>(), "Not a system");
            int index = -1;
            HashString t_type_hash = GetTypeHash<T>();
            for (int i = 0; i < p_ECSSystems.size(); i++) {
                HashString s_type_hash = p_ECSSystems[i]->m_TypeHash;
                if (t_type_hash == s_type_hash) {
                    index = i;
                    break;
                }
            }

            if (index >= 0) {
                return SmartPointerCast<T, System>(p_ECSSystems[index]);
            } else {
                return WeakPtr<T>();
            }
        }

        static Program *Get() {
            if (s_Instance) {
                return s_Instance;
            }
            return nullptr;
        }

        AssetManager m_AssetManager;
        Renderer m_Renderer;
        bgfx::Caps *m_Capabilities;
        RefCntPtr<Project> m_Project;
    };
};