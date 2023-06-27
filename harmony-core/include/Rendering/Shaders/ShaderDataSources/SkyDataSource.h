//
// Created by liam_ on 6/24/2023.
//

#ifndef HARMONY_DOJO_SKYDATASOURCE_H
#define HARMONY_DOJO_SKYDATASOURCE_H

#include "Rendering/Shaders/ShaderDataSource.h"

namespace harmony {
    class SkyDataSource : public ShaderDataSource {
    public:

        SkyDataSource();


        void OnPreUpdate(entt::registry &registry, Ref<ShaderProgram> shader) override;

        void OnPostUpdate(entt::registry &registry, Ref<ShaderProgram> shader) override;

    protected:
        bool p_UniformsCollected;

        void CollectUniforms(Ref<ShaderProgram> prog);

        void ComputePerezCoeff(float _turbidity);


        const std::string g_ParametersUniformName = "u_parameters";
        const std::string g_SunDirectionUniformName = "u_sunDirection";
        const std::string g_SkyLuminanceXYZUniformName = "u_skyLuminanceXYZ";
        const std::string g_PerezCoeffUniformName = "u_perezCoeff";

        glm::vec4 p_SunDirection;
        glm::vec4 p_SkyLuminanceXYZ;
        // x - sun size, y - sun bloom, z - exposition
        glm::vec4 p_Parameters;
        glm::vec4 p_PerezCoefficients[5];


        ShaderUniform m_ParametersUniform;
        ShaderUniform m_SunDirectionUniform;
        ShaderUniform m_SkyLuminanceXYZUniform;
        ShaderUniform m_PerezCoeffUniform;


    };
}
#endif //HARMONY_DOJO_SKYDATASOURCE_H
