#include "Rendering/ShaderDataSources/BlinnPhongDataSource.h"
#include "ECS/LightComponents.h"
#include "ECS/TransformComponent.h"
#include "Rendering/Shader.h"
#include "Core/Utils.h"
#include <bit>
harmony::BlinnPhongDataSource::BlinnPhongDataSource() : ShaderDataSource("BlinnPhong"), p_UniformsCollected(false)
{
}

void harmony::BlinnPhongDataSource::OnPreUpdate(entt::registry& registry, Ref<ShaderProgram> shader)
{

	if (!p_UniformsCollected)
	{
		GetShaderUniforms(shader);
	}

	auto dirLightView		= registry.view<DirectionalLight, TransformComponent>();
	auto pointLightView	= registry.view<PointLight, TransformComponent>();
	auto spotLightView	= registry.view<SpotLight, TransformComponent>();

	unsigned int dirLightActive		= 0;
	unsigned int numPointLights		= 0;
	unsigned int numSpotLights		= 0;

	// Update uniform vals;
	for (auto& [entity, dl, t] : dirLightView.each())
	{
		m_DirectionalLightAmbient	= dl.Ambient;
		m_DirectionalLightDiffuse	= dl.Diffuse;
		m_DirectionalLightDirection = glm::vec4(t.Forward, 0.0);
		dirLightActive = 1;
	}

	for (auto& [entity, pl, t] : pointLightView.each())
	{
		m_PointLightAmbient[numPointLights]		= pl.Ambient;
		m_PointLightDiffuse[numPointLights]		= pl.Diffuse;
		m_PointLightPosition[numPointLights]	= glm::vec4(t.Position, 0.0f);
		m_PointLightParams[numPointLights]		= glm::vec4(pl.Radius, pl.Intensity, 0.0, 0.0);
		numPointLights++;
	}

	for (auto& [entity, sl, t] : spotLightView.each())
	{
		m_SpotLightAmbient[numSpotLights] = sl.Ambient;
		m_SpotLightDiffuse[numSpotLights] = sl.Diffuse;
		m_SpotLightPosition[numSpotLights] = glm::vec4(t.Position, 0.0f);
		m_SpotLightPosition[numSpotLights] = glm::vec4(t.Forward, 0.0f);
		m_SpotLightParams[numSpotLights] = glm::vec4(sl.Radius, sl.Angle, 0.0, 0.0);
		numSpotLights++;
	}

	// Light params
	m_LightParams.x = Utils::GetIntAsFloat(dirLightActive);
	m_LightParams.y = Utils::GetIntAsFloat(numPointLights);
	m_LightParams.z = Utils::GetIntAsFloat(numSpotLights);

	if (dirLightActive == 0 && numPointLights == 0 && numSpotLights == 0)
	{
		return;
	}
	bgfx::setUniform(m_LightParamsUniform, &m_LightParams[0]);

	if (dirLightActive)
	{
		// Directional Light
		bgfx::setUniform(m_DirectionalLightAmbientUniform, &m_DirectionalLightAmbient[0]);
		bgfx::setUniform(m_DirectionalLightDiffuseUniform, &m_DirectionalLightDiffuse[0]);
		bgfx::setUniform(m_DirectionalLightDirectionUniform, &m_DirectionalLightDirection[0]);
	}
	if (numPointLights > 0)
	{
		// Point Light
		bgfx::setUniform(m_PointLightAmbientArrayUniform, &m_PointLightAmbient[0], m_PointLightAmbientArrayUniform.ArraySize);
		bgfx::setUniform(m_PointLightDiffuseArrayUniform, &m_PointLightDiffuse[0], m_PointLightDiffuseArrayUniform.ArraySize);
		bgfx::setUniform(m_PointLightPositionArrayUniform, &m_PointLightPosition[0], m_PointLightPositionArrayUniform.ArraySize);
		bgfx::setUniform(m_PointLightParamsArrayUniform, &m_PointLightParams[0], m_PointLightParamsArrayUniform.ArraySize);
	}
	if (numSpotLights > 0)
	{
		// Spot Light	
		bgfx::setUniform(m_SpotLightAmbientArrayUniform, &m_SpotLightAmbient[0], m_SpotLightAmbientArrayUniform.ArraySize);
		bgfx::setUniform(m_SpotLightDiffuseArrayUniform, &m_SpotLightDiffuse[0], m_SpotLightDiffuseArrayUniform.ArraySize);
		bgfx::setUniform(m_SpotLightPositionArrayUniform, &m_SpotLightPosition[0], m_SpotLightPositionArrayUniform.ArraySize);
		bgfx::setUniform(m_SpotLightDirectionArrayUniform, &m_SpotLightDirection[0], m_SpotLightDirectionArrayUniform.ArraySize);
		bgfx::setUniform(m_SpotLightParamsArrayUniform, &m_SpotLightParams[0], m_SpotLightParamsArrayUniform.ArraySize);
	}
}

void harmony::BlinnPhongDataSource::OnPostUpdate(entt::registry& registry, Ref<ShaderProgram> shader)
{
	
}

void harmony::BlinnPhongDataSource::GetShaderUniforms(Ref<ShaderProgram> shader)
{
	for (ShaderUniform& uniform : shader->m_Uniforms)
	{
		// Light Params
		if (uniform.Name == g_LightParamsUniform)
		{
			m_LightParamsUniform = uniform;
			continue;
		}

		// Directional Light
		if (uniform.Name == g_DirectionalLightDirectionUniformName)
		{
			m_DirectionalLightDirectionUniform = uniform;
			continue;
		}

		if (uniform.Name == g_DirectionalLightAmbientUniformName)
		{
			m_DirectionalLightAmbientUniform = uniform;
			continue;
		}

		if (uniform.Name == g_DirectionalLightDiffuseUniformName)
		{
			m_DirectionalLightDiffuseUniform = uniform;
			continue;
		}

		// Point Light
		if (uniform.Name == g_PointLightAmbientUniformName)
		{
			m_PointLightAmbientArrayUniform = uniform;
			continue;
		}

		if (uniform.Name == g_PointLightDiffuseUniformName)
		{
			m_PointLightDiffuseArrayUniform = uniform;
			continue;
		}

		if (uniform.Name == g_PointLightPositionUniformName)
		{
			m_PointLightPositionArrayUniform = uniform;
			continue;
		}

		if (uniform.Name == g_PointLightParamsUniformName)
		{
			m_PointLightParamsArrayUniform = uniform;
			continue;
		}

		// Spot Light
		if (uniform.Name == g_SpotLightAmbientUniformName)
		{
			m_SpotLightAmbientArrayUniform = uniform;
			continue;
		}

		if (uniform.Name == g_SpotLightDiffuseUniformName)
		{
			m_SpotLightDiffuseArrayUniform = uniform;
			continue;
		}

		if (uniform.Name == g_SpotLightPositionUniformName)
		{
			m_SpotLightPositionArrayUniform = uniform;
			continue;
		}

		if (uniform.Name == g_SpotLightDirectionUniformName)
		{
			m_SpotLightDirectionArrayUniform = uniform;
			continue;
		}

		if (uniform.Name == g_SpotLightParamsUniformName)
		{
			m_SpotLightParamsArrayUniform = uniform;
			continue;
		}

	}

	p_UniformsCollected;
}