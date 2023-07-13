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

mat3 intensityMatrix(vec4 n[9]){
    mat3 o;
    o[0] = vec3(sqrt(dot(n[0].xyz, n[0].xyz)), sqrt(dot(n[3].xyz, n[3].xyz)), sqrt(dot(n[6].xyz, n[6].xyz)));
    o[1] = vec3(sqrt(dot(n[1].xyz, n[1].xyz)), sqrt(dot(n[4].xyz, n[4].xyz)), sqrt(dot(n[7].xyz, n[7].xyz)));
    o[2] = vec3(sqrt(dot(n[2].xyz, n[2].xyz)), sqrt(dot(n[5].xyz, n[5].xyz)), sqrt(dot(n[8].xyz, n[8].xyz)));
    return o;
}

float convolution(mat3 x, mat3 y) {
 return dot(x[0],y[0]) + dot(x[1],y[1]) + dot(x[2],y[2]);
}


float get_sobel_max(vec4 sobelCol)
{
    return (sobelCol.x + sobelCol.y + sobelCol.z) / 3.0;
}

void main()
{
    vec2 pixelCoord = v_texcoord0.xy;

    vec4 n[9];
	KernelLuma(u_color, pixelCoord, n);
	// float random = ShadertoyNoise(pixelCoord) * noiseFactor;
    mat3 intensity = intensityMatrix(n);

    mat3 Gx = mat3(0.0, 1.0,  0.0, // 1. column
                   0.0, 0.0,  -1.0,  // 2. column
                   0.0, 0.0,  0.0); // 3. column
    
    mat3 Gy = mat3(0.0, 0.0,   1.0,  // 1. column
                   0.0, -1.0, 0.0,  // 2. column
                   0.0, 0.0, 0.0); // 3. column

    // vec2 uv = vec2(v_texcoord0.x , v_texcoord0.y);
    // vec4 col  = sobel(u_color, uv);

    float gx = convolution(intensity,Gx);
    float gy = convolution(intensity,Gy);
    float color = sqrt((gx*gx) + (gy*gy));

    vec4 tex = texture2D(u_color, v_texcoord0);
    if(tex.w < 0.05)
    {
        discard;
    }

    if(color > THRESHOLD)
    {
        vec4 final = vec4(0.0,0.0, 0.0, 1.0);
        gl_FragColor = final;
    }
    else
    {
        vec4 final = vec4(0.520,0.45, 0.51, 1.0);
        gl_FragColor = final;
    }


}
