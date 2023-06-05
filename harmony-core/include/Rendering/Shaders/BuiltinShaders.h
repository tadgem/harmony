#pragma once

#include "Shader.h"
#include "Rendering/Shaders/ShaderBinaries/vs_simple_textured.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_simple_textured.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_normal.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_normal.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_nanovg_fill.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_nanovg_fill.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_blinn_phong_textured.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_blinn_phong_textured.bin.h"
#include "bgfx/embedded_shader.h"

static const bgfx::EmbeddedShader s_BuiltInShader[] =
        {
                BGFX_EMBEDDED_SHADER(vs_simple_textured),
                BGFX_EMBEDDED_SHADER(fs_simple_textured),
                BGFX_EMBEDDED_SHADER(vs_normal),
                BGFX_EMBEDDED_SHADER(fs_normal),
                BGFX_EMBEDDED_SHADER(vs_nanovg_fill),
                BGFX_EMBEDDED_SHADER(fs_nanovg_fill),
                BGFX_EMBEDDED_SHADER(vs_blinn_phong_textured),
                BGFX_EMBEDDED_SHADER(fs_blinn_phong_textured),
                BGFX_EMBEDDED_SHADER_END()
        };