$input v_texcoord0

#include "harmony_shader.sh"

SAMPLER2D(u_pos,      0);
SAMPLER2D(u_normal,   1);
SAMPLER2D(u_color,    2);

void main()
{
	gl_FragData[0] = vec4(v_wpos, 1.0);
	gl_FragData[1] = vec4(encodeNormalUint(v_normal), 1.0);
	gl_FragData[2] = texture2D(s_texColor, v_texcoord0);
}
