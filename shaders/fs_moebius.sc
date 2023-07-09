$input v_texcoord0

#include "harmony_shader.sh"

#define THRESHOLD 0.2

SAMPLER2D(u_pos,      0);
SAMPLER2D(u_normal,   1);
SAMPLER2D(u_color,    2);

vec4 sobel(sampler2D tex, vec2 uv)
{
    vec4 n[9];
    mat3 m;
	KernelLuma(tex, uv, n);

    vec4 sobel_edge_h = n[2] + (2.0*n[5]) + n[8] - (n[0] + (2.0*n[3]) + n[6]);
  	vec4 sobel_edge_v = n[0] + (2.0*n[1]) + n[2] - (n[6] + (2.0*n[7]) + n[8]);
	vec4 sobel = sqrt((sobel_edge_h * sobel_edge_h) + (sobel_edge_v * sobel_edge_v));

    return sobel;
}

float get_sobel_max(vec4 sobelCol)
{
    return (sobelCol.x + sobelCol.y + sobelCol.z) / 3.0;
}

void main()
{
    float noiseFactor = 0.0303;

    vec2 pixelCoord = v_texcoord0.xy * u_viewRect.zw;
	float random = ShadertoyNoise(pixelCoord) * noiseFactor;

    vec2 uv = vec2(v_texcoord0.x + random, v_texcoord0.y + random);
    //vec2 uv = vec2(v_texcoord0.x, v_texcoord0.y);
    vec4 col  = sobel(u_color, uv);

    float finalMax = get_sobel_max(col);
    if(finalMax < THRESHOLD)
    {
        vec4 tex = texture2D(u_color, v_texcoord0);
        if(tex.w < 0.05)
        {
            discard;
        }
        vec4 final = vec4(0.765,0.67, 0.644, 1.0);
        gl_FragColor = final;
    }
    else
    {
        vec4 final = vec4(0.0, 0.0, 0.0, finalMax);
        gl_FragColor = final;
    }

    //gl_FragColor = step(THRESHOLD, finalMax) * vec4(finalMax, finalMax, finalMax, 1.0);

}
