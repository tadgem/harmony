#pragma once

#include "Rendering/ShaderDataSource.h"

namespace harmony
{
    class BlinnPhongDataSource : public ShaderDataSource
    {
    public:
        BlinnPhongDataSource();

        virtual void OnPreUpdate    (entt::registry& registry, Ref<ShaderProgram> shader) override;
        virtual void OnPostUpdate   (entt::registry& registry, Ref<ShaderProgram> shader) override;

        unsigned int m_NumActivePointLights;
        unsigned int m_NumActiveSpotLights;

        const unsigned int g_MaxNumPointLights = 64;
        const unsigned int g_MaxNumSpotLights = 8;

        // Light Params (vec4)
        // X = Dir Light Active ( > 0), Y = Num Active Point Lights, Z = Num Active Spot Lights
        const std::string g_LightParamsUniform = "Light_Params";

        // Directional Light
        const std::string g_DirectionalLightDirectionUniform    = "DirectionalLight_Direction";
        const std::string g_DirectionalLightDiffuseUniform      = "DirectionalLight_Diffuse";
        const std::string g_DirectionalLightAmbientUniform      = "DirectionalLight_Ambient";

        // Point Lights
        const std::string g_PointLightPositionUniformPrefix     = "PointLights_Position[";
        const std::string g_PointLightDiffuseUniformPrefix      = "PointLights_Diffuse[";
        const std::string g_PointLightAmbientUniformPrefix      = "PointLights_Ambient[";
        // X = Radius, Y = EMPTY, Z = EMPTY, W = EMPTY
        const std::string g_PointLightParamsUniformPrefix       = "PointLights_Params[";

        // Spot Lights
        const std::string g_SpotLightPositionUniformPrefix      = "SpotLights_Position[";
        const std::string g_SpotLightDirectionUniformPrefix     = "SpotLights_Direction[";
        const std::string g_SpotLightDiffuseUniformPrefix       = "SpotLights_Diffuse[";
        const std::string g_SpotLightAmbientUniformPrefix       = "SpotLights_Ambient[";
        // X = Radius, Y = Angle, Z = EMPTY, W = EMPTY
        const std::string g_SpotLightParamsUniformPrefix        = "SpotLights_Params[";
        

    };
}