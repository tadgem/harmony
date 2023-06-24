//
// Created by liam_ on 6/24/2023.
//
#include <optick.h>
#include "Core/Time.h"
#include <ECS/LightComponents.h>
#include "Rendering/Shaders/ShaderDataSources/SkyDataSource.h"
#include "Rendering/Shaders/Shader.h"
#include "ECS/TransformComponent.h"
#include "ECS/SkyComponent.h"


//        uniform vec4 u_sunDirection;
//        uniform vec4 u_skyLuminanceXYZ;
//        uniform vec4 u_parameters; // x - sun size, y - sun bloom, z - exposition, w - time
//        uniform vec4 u_perezCoeff[5];
//        uniform vec4 	u_sunLuminance;

static constexpr float M_XYZ2RGB[] =
        {
                3.240479f, -0.969256f,  0.055648f,
                -1.53715f,   1.875991f, -0.204043f,
                -0.49853f,   0.041556f,  1.057311f,
        };

// Converts color representation from CIE XYZ to RGB color-space.
glm::vec3 xyzToRgb(const glm::vec3& xyz)
{
    glm::vec3 rgb;
    rgb.x = M_XYZ2RGB[0] * xyz.x + M_XYZ2RGB[3] * xyz.y + M_XYZ2RGB[6] * xyz.z;
    rgb.y = M_XYZ2RGB[1] * xyz.x + M_XYZ2RGB[4] * xyz.y + M_XYZ2RGB[7] * xyz.z;
    rgb.z = M_XYZ2RGB[2] * xyz.x + M_XYZ2RGB[5] * xyz.y + M_XYZ2RGB[8] * xyz.z;
    return rgb;
};


harmony::SkyDataSource::SkyDataSource() : ShaderDataSource("Sky")
{
    OPTICK_EVENT()
    p_UniformsCollected = false;
    // reset time.
    p_Parameters[3] = 0.0f;
}

void harmony::SkyDataSource::OnPreUpdate(entt::registry &registry, harmony::Ref<harmony::ShaderProgram> shader)
{
    OPTICK_EVENT()
    if(!p_UniformsCollected)
    {
        CollectUniforms(shader);
    }

    auto lightView = registry.view<DirectionalLight, TransformComponent>();
    auto skyView = registry.view<SkyComponent>();

    // TODO: Make this dynamic
    p_SkyLuminanceXYZ =glm::vec4(xyzToRgb( {0.308f,    0.308f,    0.410f})   , 1.0f );

    for(auto [e, dl, t] : lightView.each())
    {
        p_SunDirection = glm::vec4(glm::normalize(t.Forward), 1.0f);
        break;
    }

    for(auto[e, sky] : skyView.each())
    {
        p_Parameters[0] = sky.SunSize;
        p_Parameters[1] = sky.SunBloom;
        p_Parameters[2] = sky.Exposition;
        p_Parameters[3] += Time::GetFrameTime();

        ComputePerezCoeff(sky.Turbidity);
    }

    bgfx::setUniform(m_SkyLuminanceXYZUniform, &p_SkyLuminanceXYZ[0]);
    bgfx::setUniform(m_SunDirectionUniform.BgfxHandle, &p_SunDirection[0]);
    bgfx::setUniform(m_ParametersUniform.BgfxHandle, &p_Parameters[0]);

    bgfx::setUniform(m_PerezCoeffUniform, &p_PerezCoefficients[0],
                     m_PerezCoeffUniform.ArraySize);
}

void harmony::SkyDataSource::OnPostUpdate(entt::registry &registry, harmony::Ref<harmony::ShaderProgram> shader)
{
    OPTICK_EVENT()
}

void harmony::SkyDataSource::CollectUniforms(Ref<ShaderProgram> prog)
{
    OPTICK_EVENT()
    for (ShaderUniform &uniform: prog->m_Uniforms)
    {
        if(uniform.Name == g_ParametersUniformName)
        {
            m_ParametersUniform = uniform;
            continue;
        }

        if(uniform.Name == g_SunDirectionUniformName)
        {
            m_SunDirectionUniform = uniform;
            continue;
        }

        if(uniform.Name == g_SkyLuminanceXYZUniformName)
        {
            m_SkyLuminanceXYZUniform = uniform;
            continue;
        }

        if(uniform.Name == g_PerezCoeffUniformName)
        {
            m_PerezCoeffUniform = uniform;
            continue;
        }
    }

    p_UniformsCollected = true;
}

static constexpr glm::vec3 ABCDE[] =
        {
                { -0.2592f, -0.2608f, -1.4630f },
                {  0.0008f,  0.0092f,  0.4275f },
                {  0.2125f,  0.2102f,  5.3251f },
                { -0.8989f, -1.6537f, -2.5771f },
                {  0.0452f,  0.0529f,  0.3703f },
        };

static constexpr glm::vec3 ABCDE_t[] =
        {
                { -0.0193f, -0.0167f,  0.1787f },
                { -0.0665f, -0.0950f, -0.3554f },
                { -0.0004f, -0.0079f, -0.0227f },
                { -0.0641f, -0.0441f,  0.1206f },
                { -0.0033f, -0.0109f, -0.0670f },
        };

void harmony::SkyDataSource::ComputePerezCoeff(float _turbidity)
{
    const glm::vec3 turbidity = { _turbidity, _turbidity, _turbidity };
    for (uint32_t ii = 0; ii < 5; ++ii)
    {
        const glm::vec3 tmp = (ABCDE_t[ii] * turbidity) + ABCDE[ii];
        p_PerezCoefficients[ii] = glm::vec4(tmp, 1.0);
    }
}
