/*
    Harmony Shader Lib
*/

#include "bgfx_shader.sh"
#include "shaderlib.sh"

void Kernel(sampler2D _tex, vec2 uv, inout vec4 n[9])
{
    float w = 1.0 / u_viewRect.z;
    float h = 1.0 / u_viewRect.w;

    n[0] = texture2D(_tex, uv + vec2( -w, -h));
	n[1] = texture2D(_tex, uv + vec2(0.0, -h));
	n[2] = texture2D(_tex, uv + vec2(  w, -h));
	n[3] = texture2D(_tex, uv + vec2( -w, 0.0));
	n[4] = texture2D(_tex, uv);
	n[5] = texture2D(_tex, uv + vec2(  w, 0.0));
	n[6] = texture2D(_tex, uv + vec2( -w, h));
	n[7] = texture2D(_tex, uv + vec2(0.0, h));
	n[8] = texture2D(_tex, uv + vec2(  w, h));
}

// Usage
//	vec2 pixelCoord = texCoord.xy * u_viewRect.zw;
//	float random = ShadertoyNoise(pixelCoord + vec2(314.0, 159.0)*u_frameIdx);
float ShadertoyNoise (vec2 uv) {
	return fract(sin(dot(uv.xy, vec2(12.9898,78.233))) * 43758.5453123);
}