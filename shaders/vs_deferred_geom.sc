$input a_position, a_normal, a_texcoord0
$output v_wpos, v_normal, v_texcoord0

/*
 * Copyright 2011-2023 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "harmony_shader.sh"

void main()
{
	vec4 spos =  mul(u_modelViewProj, vec4(a_position, 1.0));
	gl_Position = spos;

	v_wpos = spos.xyz;
	vec4 snorm = mul(u_modelViewProj, vec4(a_normal, 1.0));
	v_normal    = a_normal.xyz;

	v_texcoord0 = a_texcoord0;
}
