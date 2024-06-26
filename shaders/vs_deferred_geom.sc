$input a_position, a_normal, a_texcoord0
$output v_wpos, v_normal, v_texcoord0

/*
 * Copyright 2011-2023 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "harmony_shader.sh"

void main()
{
	vec4 spos = mul(u_model[0], vec4(a_position, 1.0));

	vec3 wnormal = mul(u_model[0], vec4(a_normal.xyz, 0.0) ).xyz;

	vec3 viewNormal = normalize(mul(u_view, vec4(wnormal, 0.0) ).xyz);

	gl_Position 	= mul(u_modelViewProj, vec4(a_position, 1.0) );;
	v_texcoord0 = a_texcoord0;

	v_wpos 		= spos.xyz;
	v_normal    = viewNormal.xyz;
}
