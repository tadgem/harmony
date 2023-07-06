$input v_texcoord0

#include "harmony_shader.sh"

SAMPLER2D(u_pos,      0);
SAMPLER2D(u_normal,   1);
SAMPLER2D(u_color,    2);

vec4 sobel(sampler2D tex, vec2 uv)
{
    vec4 n[9];
    mat3 m;
	Kernel(tex, uv, n);

    vec4 sobel_edge_h = n[2] + (2.0*n[5]) + n[8] - (n[0] + (2.0*n[3]) + n[6]);
  	vec4 sobel_edge_v = n[0] + (2.0*n[1]) + n[2] - (n[6] + (2.0*n[7]) + n[8]);
	vec4 sobel = sqrt((sobel_edge_h * sobel_edge_h) + (sobel_edge_v * sobel_edge_v));

    return sobel;
}

void main()
{
    vec4 norm = sobel(u_normal, v_texcoord0);
    vec4 color  = sobel(u_color, v_texcoord0);
    vec4 final = max(norm, color);
    final.w = 700.0;
    gl_FragColor = final;
    gl_FragColor.a = 1.0;
}
