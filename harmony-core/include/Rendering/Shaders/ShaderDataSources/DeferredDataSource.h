//
// Created by liam_ on 7/6/2023.
//

#ifndef HARMONY_DOJO_DEFERREDDATASOURCE_H
#define HARMONY_DOJO_DEFERREDDATASOURCE_H

#include "Rendering/Shaders/ShaderDataSource.h"
#include "Rendering/Framebuffer.h"

namespace harmony {
    class DeferredDataSource : public ShaderDataSource {
    public:
        DeferredDataSource(RefCntPtr<Framebuffer> gBuffer);

        void OnPreUpdate(entt::registry &registry, RefCntPtr<ShaderProgram> shader) override;

        void OnPostUpdate(entt::registry &registry, RefCntPtr<ShaderProgram> shader) override;

    protected:

        WeakPtr<Framebuffer> m_GBuffer;

        bool p_UniformsCollected;

        void CollectUniforms(RefCntPtr<ShaderProgram> prog);

        const String g_Position = "u_pos";
        const String g_Normal = "u_normal";
        const String g_Color = "u_color";
        const String g_UV = "u_uv";
        const String g_Depth = "u_depth";


        ShaderUniform m_PositionTextureUniform;
        ShaderUniform m_NormalTextureUniform;
        ShaderUniform m_ColorTextureUniform;
        ShaderUniform m_UVTextureUniform;
        ShaderUniform m_DepthTextureUniform;
    };
}

#endif //HARMONY_DOJO_DEFERREDDATASOURCE_H
