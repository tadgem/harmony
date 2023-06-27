//
// Created by liam_ on 5/1/2023.
//

#ifndef HARMONY_DOJO_GRAPHSCRIPTSYSTEM_H
#define HARMONY_DOJO_GRAPHSCRIPTSYSTEM_H

#include "Core/Memory.h"
#include "ECS/System.h"

namespace harmony
{
	class GraphScriptProgramComponent;
	class GraphScriptSystem : public System
	{
	public:
		GraphScriptSystem(Ref<GraphScriptProgramComponent> gspc);
		void Init(entt::registry &registry) override;
		void Update(entt::registry &registry) override;
		void Render(entt::registry &registry) override;
		void Cleanup(entt::registry &registry) override;
		nlohmann::json SerializeSystem(entt::registry &registry) override;
		void DeserializeSystem(entt::registry &registry,
							   nlohmann::json systemJson) override;

	protected:
		void Refresh() override;

	protected:
		Ref<GraphScriptProgramComponent> p_ProgramComponent;
	};
} // namespace harmony

#endif // HARMONY_DOJO_GRAPHSCRIPTSYSTEM_H
