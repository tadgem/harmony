$input a_position, a_texcoord0
$output v_texcoord0

/*
 * Copyright 2011-2022 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "bgfx_shader.sh"

uniform mat4 u_mtx;

void main()
{
	gl_Position = mul(u_modelViewProj, vec4(a_position, 1.0) );
	v_texcoord0 = a_texcoord0;
}

// shaderc-win.exe -f assets/shaders/vs_simple_textured.sc -i assets/shaders/include -o F:\repos\harmony\projects\JoltTest//assets/shaders/bin/dx11/vs_simple_textured.bin --type v --varyingdef F:\repos\harmony\projects\JoltTest\assets/shaders/varying.def.sc -p vs_5_0
