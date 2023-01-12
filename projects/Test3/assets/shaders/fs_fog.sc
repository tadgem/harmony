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
    vec4 fogColor = vec4(0.03, 0.03, 0.03, 1.0);

    float fogDistance = 0.0;

    vec4 depthColor = texture2D(u_depth_att, v_texcoord0);
    // todo: change 300 to far clip plane distance
    float depth = (1.0 - depthColor.x) * 300.0;

    float fogFactor = (depth - fogDistance);
    fogFactor = clamp(fogFactor, 0.0, 1.0);

    vec4 color = mix(fogColor, pixelColor, fogFactor);
    gl_FragColor = color;
}