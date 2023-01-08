$input v_texcoord0

/*
 * Copyright 2011-2022 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "harmony_post_process.sh"

SAMPLER2D(u_color,      0);
SAMPLER2D(u_depth_att,  1);

#define FXAA_SPAN_MAX 8.0
#define FXAA_REDUCE_MUL   (1.0/FXAA_SPAN_MAX)
#define FXAA_REDUCE_MIN   (1.0/128.0)
#define FXAA_SUBPIX_SHIFT (1.0/4.0)

vec3 fxaa(vec2 uv, vec2 add)
{
    vec3 rgbNW = texture2D(u_color, uv.yx).xyz;
    vec3 rgbNE = texture2D(u_color, uv + vec2(1,0)*add).xyz;
    vec3 rgbSW = texture2D(u_color, uv + vec2(0,1)*add).xyz;
    vec3 rgbSE = texture2D(u_color, uv + vec2(1,1)*add).xyz;
    vec3 rgbM  = texture2D(u_color, uv, 0.0).xyz;
    //textureLod(tex, uv.zw, 0.0).xyz;
    // vec3 rgbNE = textureLod(tex, uv.zw + vec2(1,0)*rcpFrame.xy, 0.0).xyz;
    // vec3 rgbSW = textureLod(tex, uv.zw + vec2(0,1)*rcpFrame.xy, 0.0).xyz;
    // vec3 rgbSE = textureLod(tex, uv.zw + vec2(1,1)*rcpFrame.xy, 0.0).xyz;
    // vec3 rgbM  = textureLod(tex, uv.xy, 0.0).xyz;

    vec3 luma = vec3(0.299, 0.587, 0.114);
    float lumaNW = dot(rgbNW, luma);
    float lumaNE = dot(rgbNE, luma);
    float lumaSW = dot(rgbSW, luma);
    float lumaSE = dot(rgbSE, luma);
    float lumaM  = dot(rgbM,  luma);

    float lumaMin = min(lumaM, min(min(lumaNW, lumaNE), min(lumaSW, lumaSE)));
    float lumaMax = max(lumaM, max(max(lumaNW, lumaNE), max(lumaSW, lumaSE)));

    vec2 dir;
    dir.x = -((lumaNW + lumaNE) - (lumaSW + lumaSE));
    dir.y =  ((lumaNW + lumaSW) - (lumaNE + lumaSE));

    float dirReduce = max(
        (lumaNW + lumaNE + lumaSW + lumaSE) * (0.25 * FXAA_REDUCE_MUL),
        FXAA_REDUCE_MIN);
    float rcpDirMin = 1.0/(min(abs(dir.x), abs(dir.y)) + dirReduce);

    dir = min(vec2( FXAA_SPAN_MAX,  FXAA_SPAN_MAX),
          max(vec2(-FXAA_SPAN_MAX, -FXAA_SPAN_MAX),
          dir * rcpDirMin)) * add;

    vec3 rgbA = (1.0/2.0) * (
        texture2D(u_color, uv + dir * (1.0/3.0 - 0.5)).xyz +
        texture2D(u_color, uv + dir * (2.0/3.0 - 0.5)).xyz);

    vec3 rgbB = rgbA * (1.0/2.0) + (1.0/4.0) * (
        texture2D(u_color, uv + dir * (0.0/3.0 - 0.5)).xyz +
        texture2D(u_color, uv + dir * (3.0/3.0 - 0.5)).xyz);

    float lumaB = dot(rgbB, luma);

    if((lumaB < lumaMin) || (lumaB > lumaMax)) return rgbA;
    
    return rgbB; 
}

void main()
{
    vec2 resolution = vec2(u_post_process_params.x, u_post_process_params.y);
    vec2 add = vec2(1.0, 1.0) / resolution;
    vec4 pixelColor = vec4(fxaa(v_texcoord0, add), 1.0);
    //vec4 pixelColor = texture2D(u_color, v_texcoord0);
    gl_FragColor = pixelColor;
}