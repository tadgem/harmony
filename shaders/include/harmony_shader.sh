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


void KernelLuma(sampler2D _tex, vec2 uv, inout vec4 n[9])
{
    float w = 1.0 / u_viewRect.z;
    float h = 1.0 / u_viewRect.w;

    n[0] = texture2D(_tex, uv + vec2( -w, h));
	n[1] = texture2D(_tex, uv + vec2(0.0, h));
	n[2] = texture2D(_tex, uv + vec2(  w, h));
	n[3] = texture2D(_tex, uv + vec2( -w, 0.0));
	n[4] = texture2D(_tex, uv);
	n[5] = texture2D(_tex, uv + vec2(  w, 0.0));
	n[6] = texture2D(_tex, uv + vec2( -w, -h));
	n[7] = texture2D(_tex, uv + vec2(0.0, -h));
	n[8] = texture2D(_tex, uv + vec2(  w, -h));

	float n0 = dot(n[0].xyz, vec3(0.299, 0.587, 0.114));
	float n1 = dot(n[1].xyz, vec3(0.299, 0.587, 0.114));
	float n2 = dot(n[2].xyz, vec3(0.299, 0.587, 0.114));
	float n3 = dot(n[3].xyz, vec3(0.299, 0.587, 0.114));
	float n4 = dot(n[4].xyz, vec3(0.299, 0.587, 0.114));
	float n5 = dot(n[5].xyz, vec3(0.299, 0.587, 0.114));
	float n6 = dot(n[6].xyz, vec3(0.299, 0.587, 0.114));
	float n7 = dot(n[7].xyz, vec3(0.299, 0.587, 0.114));
	float n8 = dot(n[8].xyz, vec3(0.299, 0.587, 0.114));

	n[0] = vec4(n0,n0,n0,n0);
	n[1] = vec4(n1,n1,n1,n1);
	n[2] = vec4(n2,n2,n2,n2);
	n[3] = vec4(n3,n3,n3,n3);
	n[4] = vec4(n4,n4,n4,n4);
	n[5] = vec4(n5,n5,n5,n5);
	n[6] = vec4(n6,n6,n6,n6);
	n[7] = vec4(n7,n7,n7,n7);
	n[8] = vec4(n8,n8,n8,n8);
}

// Usage
//	vec2 pixelCoord = texCoord.xy * u_viewRect.zw;
//	float random = ShadertoyNoise(pixelCoord + vec2(314.0, 159.0)*u_frameIdx);
float ShadertoyNoise (vec2 uv) {
	return fract(sin(dot(uv.xy, vec2(12.9898,78.233))) * 43758.5453123);
}