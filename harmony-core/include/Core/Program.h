#pragma once

#include <string>
#include <vector>
#include <functional>
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
    typedef std::function<void()> Callback;

    /// <summary>
    /// Top level container for program
    /// </summary>
    class Program {
    public:
        Program(const std::string &name);

        ~Program();

        virtual void Init();

        void PreRunInit();

        virtual void Run();

        virtual void Run(const std::string &projectPath);

        virtual void Exit();

        virtual void CreateProject(const std::string &name, const std::string &path);

        virtual void SaveProject();

        virtual void LoadProject(const std::string &path);

        virtual void CloseActiveProject();

        virtual void CreateScene(const std::string &name);

        virtual void SaveScene(const std::string &path);

        virtual void LoadScene(const std::string &path);

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

        std::string GetWorkingDirectory();

    protected:

        virtual void LoadBuiltInAssets();

        virtual void SetupBGFXCapabilities(bgfx::Init &init);

        std::string GetVendorName(uint16_t vendorId);

        void ChangeWorkingDirectory(const std::string &directory);

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

        void UpdateProjectDirectory(const std::string &path);

        void Frame();

        std::string p_AppName;
        std::string p_LoadedProjectPath;
        std::vector<RefCntPtr<ProgramComponent>> p_ProgramComponents;
        std::vector<RefCntPtr<System>> p_ECSSystems;
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

            static_assert(std::is_base_of<ProgramComponent, T>());
            RefCntPtr<T> pc = CreateRef<T>(std::forward<Args>(args)...);
            p_ProgramComponents.emplace_back(pc);
            return GetWeakRef<T>(pc);
        }

        template<typename T, typename ... Args>
        WeakPtr<T> AddSystem(Args &&... args) {

            static_assert(std::is_base_of<System, T>());
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
            RefCntPtr<T> sys = CreateRef<T>(std::forward<Args>(args)...);
            p_ECSSystems.emplace_back(sys);
            return GetWeakRef<T>(sys);
        }

        template<typename T>
        WeakPtr<T> GetProgramComponent() {

            static_assert(std::is_base_of<ProgramComponent, T>(), "Not a program component");
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
                return std::static_pointer_cast<T, ProgramComponent>(p_ProgramComponents[index]);
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

            static_assert(std::is_base_of<System, T>(), "Not a system");
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
                return std::static_pointer_cast<T, System>(p_ECSSystems[index]);
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