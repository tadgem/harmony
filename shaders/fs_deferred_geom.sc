$input v_wpos, v_normal, v_texcoord0

/*
 * Copyright 2011-2023 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "harmony_shader.sh"

SAMPLER2D(s_texColor,  0);

void main()
{
	vec3 wnormal = normalize(mul(u_invView, vec4(v_normal, 0.0) ).xyz);
	gl_FragData[0] = vec4(v_wpos, 1.0);
	gl_FragData[1] = vec4(wnormal, 1.0);
	gl_FragData[2] = texture2D(s_texColor, v_texcoord0);
	gl_FragData[3] = vec4(v_texcoord0.x, v_texcoord0.y, 0.0, 0.0);
}
