#pragma once
#include <string>
#include <vector>
#include <functional>
#include "SDL.h"
#undef main
#include "Memory.h"
#include "Core/ProgramComponent.h"
#include "Core/Profile.hpp"
#include "Assets/AssetManager.h"
#include "Rendering/Renderer.h"
#include "Core/Scene.h"
#include "ECS/System.h"
#include "Project.h"
#include "Core/BGFXDebugCallback.h"
#include "ImGui/imgui.h"

namespace harmony
{
	typedef std::function<void()> Callback;

	/// <summary>
	/// Top level container for program
	/// </summary>
	class Program
	{
	public:
		Program(std::string name);
		~Program();
		void Init();
		void Run(Callback callback);

		void CreateProject(const std::string& name, const std::string& path);
		void SaveProject();
		void LoadProject(const std::string& path);
		void CloseActiveProject();

		void CreateScene(const std::string& name);
		void SaveScene(const std::string& path);
		void LoadScene(const std::string& path);
		void CloseActiveScene();
		WeakRef<Scene> GetActiveScene();

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
	private:
		void ChangeWorkingDirectory(const std::string& directory);
		void Cleanup();

		void InitSDL();
		void InitBGFX();
		void InitImGui();

		void ResizeApplicationWindow(int w, int h);

		void SetStyle();

		std::string							p_AppName;
		std::string							p_LoadedProjectPath;
		std::vector<Ref<ProgramComponent>>	p_ProgramComponents;
		std::vector<Ref<System>>			p_ECSSystems;
		Ref<Scene>							p_ActiveScene;
		bool p_Run;

		const uint16_t p_StartingWidth = 1600;
		const uint16_t p_StartingHeight = 900;
		uint16_t p_WindowWidth;
		uint16_t p_WindowHeight;

		SDL_Window*				p_Window;
		bx::DefaultAllocator*	p_ImGuiAllocator;
		BgfxCallback			p_DebugCallback;

		inline static Program* s_Instance = nullptr;
	public:

		template<typename T, typename ... Args>
		WeakRef<T> AddProgramComponent(Args&& ... args)
		{
			HARMONY_PROFILE_FUNCTION()
			static_assert(std::is_base_of<ProgramComponent, T>());
			Ref<T> pc = CreateRef<T>(std::forward<Args>(args)...);
			p_ProgramComponents.emplace_back(pc);
			return GetWeakRef<T>(pc);
		}
		template<typename T, typename ... Args>
		WeakRef<T> AddSystem(Args&& ... args)
		{
			HARMONY_PROFILE_FUNCTION()
			static_assert(std::is_base_of<System, T>());
			Ref<T> sys = CreateRef<T>(std::forward<Args>(args)...);
			p_ECSSystems.emplace_back(sys);
			return GetWeakRef<T>(sys);
		}

		template<typename T>
		WeakRef<T> GetProgramComponent()
		{
			HARMONY_PROFILE_FUNCTION()
			static_assert(std::is_base_of<ProgramComponent, T>("Not a program component"));
			int index = -1;
			for (int i = 0; i < p_ProgramComponents.size(); i++)
			{
				if (typeid(T).hash_code() == typeid(p_ProgramComponent[i]).hash_code())
				{
					index = i;
				}
			}

			if (index >= 0)
			{
				return GetWeakRef<T>(p_ProgramComponents[index]);
			}
			else
			{
				return GetWeakRef<T>(nullptr);
			}
		}
		template<typename T>
		WeakRef<T> GetSystem()
		{
			HARMONY_PROFILE_FUNCTION()
			static_assert(std::is_base_of<System, T>("Not a system"));
			int index = -1;
			for (int i = 0; i < p_ECSSystems.size(); i++)
			{
				if (typeid(T).hash_code() == typeid(p_ECSSystems[i]).hash_code())
				{
					index = i;
				}
			}

			if (index >= 0)
			{
				return GetWeakRef<T>(p_ECSSystems[index]);
			}
			else
			{
				return GetWeakRef<T>(nullptr);
			}
		}

		static Program* Get()
		{
			if (s_Instance)
			{
				return s_Instance;
			}
			return nullptr;
		}

		AssetManager	m_AssetManager;
		Renderer		m_Renderer;
		bgfx::Caps		m_Capabilities;

		Ref<Project>	m_Project;
	};
};