$input v_texcoord0

#include "harmony_shader.sh"

SAMPLER2D(u_pos,      0);
SAMPLER2D(u_normal,   1);
SAMPLER2D(u_color,    2);

vec4 sobel(vec2 uv)
{
    vec4 n[9];
    mat3 m;
	Kernel(u_normal, uv, n);

    vec4 sobel_edge_h = n[2] + (2.0*n[5]) + n[8] - (n[0] + (2.0*n[3]) + n[6]);
  	vec4 sobel_edge_v = n[0] + (2.0*n[1]) + n[2] - (n[6] + (2.0*n[7]) + n[8]);
	vec4 sobel = sqrt((sobel_edge_h * sobel_edge_h) + (sobel_edge_v * sobel_edge_v));

    return sobel;
}

void main()
{
    gl_FragColor = sobel(v_texcoord0);
}
