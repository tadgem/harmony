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
    gl_FragColor = sepia(pixelColor);
}