$input v_texcoord0

/*
 * Copyright 2011-2022 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "harmony_post_process.sh"

SAMPLER2D(u_color, 0);
SAMPLER2D(u_depth_att, 1);

void main()
{
    vec4 pixelColor = texture2D(u_color, v_texcoord0);
    vec4 fogColor = vec4(0.43, 0.2, 0.2, 1.0);

    float fogMaxDist = 1.0;
    float fogMinDist = 0.5;

    vec4 depthColor = texture2D(u_depth_att, v_texcoord0);

    float d = (1.0 - depthColor.x) * 1000.0;

    float fogFactor = (fogMinDist - d) / (fogMinDist - fogMaxDist);
    fogFactor = clamp(fogFactor, 0.0, 1.0);

    vec4 color = mix(fogColor, pixelColor, fogFactor);
    gl_FragColor = color;
}