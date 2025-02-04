//
// Created by liam_ on 6/24/2023.
//

#ifndef HARMONY_DOJO_SKYDATASOURCE_H
#define HARMONY_DOJO_SKYDATASOURCE_H

#include "STL/Array.h"
#include "Rendering/Shaders/ShaderDataSource.h"
namespace harmony {
    class SkyDataSource : public ShaderDataSource {
    public:
        SkyDataSource();

        void OnPreUpdate(entt::registry &registry,
                         RefCntPtr<ShaderProgram> shader) override;

        void OnPostUpdate(entt::registry &registry,
                          RefCntPtr<ShaderProgram> shader) override;

    protected:
        bool p_UniformsCollected;

        void CollectUniforms(RefCntPtr<ShaderProgram> prog);

        void ComputePerezCoeff(float _turbidity);

        const String g_ParametersUniformName = "u_parameters";
        const String g_SunDirectionUniformName = "u_sunDirection";
        const String g_SkyLuminanceXYZUniformName = "u_skyLuminanceXYZ";
        const String g_PerezCoeffUniformName = "u_perezCoeff";
        glm::vec4 p_SunDirection;
        glm::vec4 p_SkyLuminanceXYZ;
        // x - sun size, y - sun bloom, z - exposition
        glm::vec4 p_Parameters;
        Array<glm::vec4, 5> p_PerezCoefficients;
        ShaderUniform m_ParametersUniform;
        ShaderUniform m_SunDirectionUniform;
        ShaderUniform m_SkyLuminanceXYZUniform;
        ShaderUniform m_PerezCoeffUniform;
    };
} // namespace harmony
#endif // HARMONY_DOJO_SKYDATASOURCE_H
