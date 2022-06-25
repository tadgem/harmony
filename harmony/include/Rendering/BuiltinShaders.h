#pragma once
#include "Rendering/Shader.h"
#include "Rendering/ShaderBinaries/vs_simple_textured.bin.h"
#include "Rendering/ShaderBinaries/fs_simple_textured.bin.h"
#include "bgfx/embedded_shader.h"

static const bgfx::EmbeddedShader s_BuiltInShader[] =
{
	BGFX_EMBEDDED_SHADER(vs_simple_textured),
	BGFX_EMBEDDED_SHADER(fs_simple_textured),
	BGFX_EMBEDDED_SHADER_END()
};

static bgfx::EmbeddedShader GetBuiltInShader(const std::string& name)
{
	auto size = BX_COUNTOF(s_BuiltInShader);
	for (uint32_t i = 0; i < size; i++)
	{
		if (s_BuiltInShader->name == name.c_str())
		{
			return s_BuiltInShader[i];
		}
	}
	return bgfx::EmbeddedShader();
}