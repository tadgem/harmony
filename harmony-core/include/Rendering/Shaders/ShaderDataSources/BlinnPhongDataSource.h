#pragma once

#include "Rendering/Shaders/ShaderDataSource.h"

namespace harmony {
    class BlinnPhongDataSource : public ShaderDataSource {
    public:

        BlinnPhongDataSource();

        virtual void OnPreUpdate(entt::registry &registry, Ref<ShaderProgram> shader) override;

        virtual void OnPostUpdate(entt::registry &registry, Ref<ShaderProgram> shader) override;

        unsigned int m_NumActivePointLights;
        unsigned int m_NumActiveSpotLights;

        static const unsigned int g_MaxNumPointLights = 64;
        static const unsigned int g_MaxNumSpotLights = 8;

        ShaderUniform m_LightParamsUniform;
        glm::vec4 m_LightParams;

        ShaderUniform m_DirectionalLightAmbientUniform;
        ShaderUniform m_DirectionalLightDiffuseUniform;
        ShaderUniform m_DirectionalLightDirectionUniform;

        glm::vec4 m_DirectionalLightAmbient;
        glm::vec4 m_DirectionalLightDiffuse;
        glm::vec4 m_DirectionalLightDirection;

        ShaderUniform m_PointLightAmbientArrayUniform;
        ShaderUniform m_PointLightDiffuseArrayUniform;
        ShaderUniform m_PointLightPositionArrayUniform;
        ShaderUniform m_PointLightParamsArrayUniform;

        glm::vec4 m_PointLightAmbient[g_MaxNumPointLights];
        glm::vec4 m_PointLightDiffuse[g_MaxNumPointLights];
        glm::vec4 m_PointLightPosition[g_MaxNumPointLights];
        glm::vec4 m_PointLightParams[g_MaxNumPointLights];

        ShaderUniform m_SpotLightAmbientArrayUniform;
        ShaderUniform m_SpotLightDiffuseArrayUniform;
        ShaderUniform m_SpotLightPositionArrayUniform;
        ShaderUniform m_SpotLightDirectionArrayUniform;
        ShaderUniform m_SpotLightParamsArrayUniform;

        glm::vec4 m_SpotLightAmbient[g_MaxNumSpotLights];
        glm::vec4 m_SpotLightDiffuse[g_MaxNumSpotLights];
        glm::vec4 m_SpotLightPosition[g_MaxNumSpotLights];
        glm::vec4 m_SpotLightDirection[g_MaxNumSpotLights];
        glm::vec4 m_SpotLightParams[g_MaxNumSpotLights];

        // Light Params (vec4)
        // X = Dir Light Active ( > 0), Y = Num Active Point Lights, Z = Num Active Spot Lights
        const std::string g_LightParamsUniform = "Light_Params";

        // Directional Light
        const std::string g_DirectionalLightDirectionUniformName = "DirectionalLight_Direction";
        const std::string g_DirectionalLightDiffuseUniformName = "DirectionalLight_Diffuse";
        const std::string g_DirectionalLightAmbientUniformName = "DirectionalLight_Ambient";

        // Point Lights
        const std::string g_PointLightPositionUniformName = "PointLights_Position";
        const std::string g_PointLightDiffuseUniformName = "PointLights_Diffuse";
        const std::string g_PointLightAmbientUniformName = "PointLights_Ambient";
        // X = Radius, Y = EMPTY, Z = EMPTY, W = EMPTY
        const std::string g_PointLightParamsUniformName = "PointLights_Params";

        // Spot Lights
        const std::string g_SpotLightPositionUniformName = "SpotLights_Position";
        const std::string g_SpotLightDirectionUniformName = "SpotLights_Direction";
        const std::string g_SpotLightDiffuseUniformName = "SpotLights_Diffuse";
        const std::string g_SpotLightAmbientUniformName = "SpotLights_Ambient";
        // X = Radius, Y = Angle, Z = EMPTY, W = EMPTY
        const std::string g_SpotLightParamsUniformName = "SpotLights_Params";

    protected:

        void GetShaderUniforms(Ref<ShaderProgram> shader);

        bool p_UniformsCollected;
    };
}