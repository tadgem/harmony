#pragma once
#include "Rendering/Shader.h"
#include "Rendering/ShaderBinaries/vs_simple_textured.bin.h"
#include "Rendering/ShaderBinaries/fs_simple_textured.bin.h"
#include "Rendering/ShaderBinaries/vs_normal.bin.h"
#include "Rendering/ShaderBinaries/fs_normal.bin.h"
#include "bgfx/embedded_shader.h"

static const bgfx::EmbeddedShader s_BuiltInShader[] =
{
	BGFX_EMBEDDED_SHADER(vs_simple_textured),
	BGFX_EMBEDDED_SHADER(fs_simple_textured),
	BGFX_EMBEDDED_SHADER(vs_normal),
	BGFX_EMBEDDED_SHADER(fs_normal),
	BGFX_EMBEDDED_SHADER_END()
};