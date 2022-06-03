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
#include "bx/allocator.h"
#include <bx/allocator.h>
#include <bx/file.h>
#include <bx/string.h>
#include <bx/debug.h>
#include "ImGui/imgui.h"

namespace harmony
{
	struct BgfxCallback : public bgfx::CallbackI
	{
		virtual ~BgfxCallback()
		{
		}

		virtual void fatal(const char* _filePath, uint16_t _line, bgfx::Fatal::Enum _code, const char* _str) override
		{
			BX_UNUSED(_filePath, _line);

			// Something unexpected happened, inform user and bail out.
			bx::debugPrintf("Fatal error: 0x%08x: %s", _code, _str);

			// Must terminate, continuing will cause crash anyway.
			abort();
		}

		virtual void traceVargs(const char* _filePath, uint16_t _line, const char* _format, va_list _argList) override
		{
			bx::debugPrintfVargs(_format, _argList);
		}

		virtual void profilerBegin(const char* /*_name*/, uint32_t /*_abgr*/, const char* /*_filePath*/, uint16_t /*_line*/) override
		{
		}

		virtual void profilerBeginLiteral(const char* /*_name*/, uint32_t /*_abgr*/, const char* /*_filePath*/, uint16_t /*_line*/) override
		{
		}

		virtual void profilerEnd() override
		{
		}

		virtual uint32_t cacheReadSize(uint64_t _id) override
		{
			return 0;
		}

		virtual bool cacheRead(uint64_t _id, void* _data, uint32_t _size) override
		{
			return false;
		}

		virtual void cacheWrite(uint64_t _id, const void* _data, uint32_t _size) override
		{
			
		}

		virtual void screenShot(const char* _filePath, uint32_t _width, uint32_t _height, uint32_t _pitch, const void* _data, uint32_t /*_size*/, bool _yflip) override
		{
		}

		virtual void captureBegin(uint32_t _width, uint32_t _height, uint32_t /*_pitch*/, bgfx::TextureFormat::Enum /*_format*/, bool _yflip) override
		{
		}

		virtual void captureEnd() override
		{
		}

		virtual void captureFrame(const void* _data, uint32_t /*_size*/) override
		{
		}
	};
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
		void Run();
		void SaveProject(Project& proj);
		void LoadProject(Project& proj);

		void RunProgramComponentInit();
		void RunProgramComponentUpdate();
		void RunProgramComponentRender();
		void RunProgramComponentCleanup();

		void RunSystemInit();
		void RunSystemUpdate();
		void RunSystemRender();
		void RunSystemCleanup();
	private:
		void Cleanup();

		void InitSDL();
		void InitBGFX();
		void InitImGui();
		void SetStyle();

		std::string							p_AppName;
		std::vector<Ref<ProgramComponent>>	p_ProgramComponents;
		std::vector<Ref<System>>			p_ECSSystems;
		Ref<Scene>							p_ActiveScene;
		bool p_Run;

		const uint32_t p_StartingWidth = 1280;
		const uint32_t p_StartingHeight = 720;

		SDL_Window* p_Window;
		bx::DefaultAllocator* p_ImGuiAllocator;
		BgfxCallback p_DebugCallback;

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

		AssetManager m_AssetManager;
		Renderer m_Renderer;
	};
};