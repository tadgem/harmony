#include "Rendering/ShaderDataSources/BlinnPhongDataSource.h"
#include "ECS/LightComponents.h"
#include "Rendering/Shader.h"
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

	auto dirLightView		= registry.view<DirectionalLight>();
	auto pointLightView	= registry.view<PointLight>();
	auto spotLightView	= registry.view<SpotLight>();

	unsigned int dirLightActive		= 0;
	unsigned int numPointLights		= 0;
	unsigned int numSpotLights		= 0;

	// Update uniform vals;

	// Light params
	float dla = reinterpret_cast<float>(dirLightActive);
	bgfx::setUniform(m_LightParamsUniform, &m_LightParams[0]);

	// Directional Light
	bgfx::setUniform(m_DirectionalLightAmbientUniform, &m_DirectionalLightAmbient[0]);
	bgfx::setUniform(m_DirectionalLightDiffuseUniform, &m_DirectionalLightDiffuse[0]);
	bgfx::setUniform(m_DirectionalLightDirectionUniform, &m_DirectionalLightDirection[0]);

	// Point Light
	bgfx::setUniform(m_PointLightAmbientArrayUniform,	&m_PointLightAmbient[0],	m_PointLightAmbientArrayUniform.ArraySize);
	bgfx::setUniform(m_PointLightDiffuseArrayUniform,	&m_PointLightDiffuse[0],	m_PointLightDiffuseArrayUniform.ArraySize);
	bgfx::setUniform(m_PointLightPositionArrayUniform,	&m_PointLightPosition[0],	m_PointLightPositionArrayUniform.ArraySize);
	bgfx::setUniform(m_PointLightParamsArrayUniform,		&m_PointLightParams[0],	m_PointLightParamsArrayUniform.ArraySize);

	// Spot Light	
	bgfx::setUniform(m_SpotLightAmbientArrayUniform,		&m_SpotLightAmbient[0],	m_SpotLightAmbientArrayUniform.ArraySize);
	bgfx::setUniform(m_SpotLightDiffuseArrayUniform,		&m_SpotLightDiffuse[0],	m_SpotLightDiffuseArrayUniform.ArraySize);
	bgfx::setUniform(m_SpotLightPositionArrayUniform,	&m_SpotLightPosition[0],	m_SpotLightPositionArrayUniform.ArraySize);
	bgfx::setUniform(m_SpotLightDirectionArrayUniform,	&m_SpotLightDirection[0],	m_SpotLightDirectionArrayUniform.ArraySize);
	bgfx::setUniform(m_SpotLightParamsArrayUniform,		&m_SpotLightParams[0],	m_SpotLightParamsArrayUniform.ArraySize);
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