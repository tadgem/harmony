#pragma once

#include "Rendering/Shaders/ShaderBinaries/fs_blinn_phong_textured.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_fxaa.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_nanovg_fill.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_normal.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_simple_textured.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_sky.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_deferred_geom.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_blinn_phong_textured.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_nanovg_fill.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_normal.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_simple_textured.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_sky.bin.h"
#include "Rendering/Shaders/ShaderBinaries/vs_deferred_geom.bin.h"
#include "Rendering/Shaders/ShaderBinaries/fs_moebius.bin.h"
#include "Shader.h"
#include "bgfx/embedded_shader.h"

static const bgfx::EmbeddedShader s_BuiltInShader[] = {
        BGFX_EMBEDDED_SHADER(vs_simple_textured),
        BGFX_EMBEDDED_SHADER(fs_simple_textured),
        BGFX_EMBEDDED_SHADER(vs_normal),
        BGFX_EMBEDDED_SHADER(fs_normal),
        BGFX_EMBEDDED_SHADER(vs_nanovg_fill),
        BGFX_EMBEDDED_SHADER(fs_nanovg_fill),
        BGFX_EMBEDDED_SHADER(vs_blinn_phong_textured),
        BGFX_EMBEDDED_SHADER(fs_blinn_phong_textured),
        BGFX_EMBEDDED_SHADER(fs_fxaa),
        BGFX_EMBEDDED_SHADER(vs_sky),
        BGFX_EMBEDDED_SHADER(fs_sky),
        BGFX_EMBEDDED_SHADER(vs_deferred_geom),
        BGFX_EMBEDDED_SHADER(fs_deferred_geom),
        BGFX_EMBEDDED_SHADER(fs_moebius),
        BGFX_EMBEDDED_SHADER_END()};