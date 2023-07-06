//
// Created by liam_ on 7/6/2023.
//

#ifndef HARMONY_DOJO_DEFERREDDATASOURCE_H
#define HARMONY_DOJO_DEFERREDDATASOURCE_H

#include "Rendering/Shaders/ShaderDataSource.h"
#include "Rendering/Framebuffer.h"

namespace harmony
{
	class DeferredDataSource : public ShaderDataSource
	{
	public:
		DeferredDataSource(Ref<Framebuffer> gBuffer);

		void OnPreUpdate(entt::registry &registry, Ref<ShaderProgram> shader) override;
		void OnPostUpdate(entt::registry &registry, Ref<ShaderProgram> shader) override;

	protected:

		WeakRef<Framebuffer> m_GBuffer;

		bool p_UniformsCollected;
		void CollectUniforms(Ref<ShaderProgram> prog);

		const std::string g_Position = "u_pos";
		const std::string g_Normal = "u_normal";
		const std::string g_Color = "u_color";

		ShaderUniform m_PositionTextureUniform;
		ShaderUniform m_NormalTextureUniform;
		ShaderUniform m_ColorTextureUniform;
	};
}

#endif //HARMONY_DOJO_DEFERREDDATASOURCE_H
