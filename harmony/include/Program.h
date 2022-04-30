#include "SDL.h"
#include "Memory.h"
#include "ProgramComponent.h"
#undef main
#include <string>
#include <vector>
#include <functional>
#include "bx/allocator.h"

namespace harmony
{
	typedef std::function<void()> Callback;

	/// <summary>
	/// Top level container for program
	/// </summary>
	/// 
	class Program
	{
	public:
		Program(std::string name);
		~Program();
		void Init();
		void Run(Callback callback);
	private:
		void Cleanup();

		void InitSDL();
		void InitBGFX();
		void InitImGui();


		std::string p_AppName;
		std::vector<Ref<ProgramComponent>> p_ProgramComponents;
		bool p_Run;

		const uint32_t p_StartingWidth = 1280;
		const uint32_t p_StartingHeight = 720;

		bx::DefaultAllocator* p_ImGuiAllocator;
		SDL_Window* p_Window;

	public:

		template<typename T, typename ... Args>
		WeakRef<T> AddProgramComponent(Args&& ... args)
		{
			static_assert(std::is_base_of<ProgramComponent, T>());
			Ref<T> pc = CreateRef<T>(std::forward<Args>(args)...);
			p_ProgramComponents.emplace_back(pc);
			return GetWeakRef<T>(pc);
		}

		template<typename T>
		WeakRef<T> GetProgramComponent()
		{
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
		
	};
};