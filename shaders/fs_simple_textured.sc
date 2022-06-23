$input v_texcoord0

/*
 * Copyright 2011-2022 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "common.sh"

SAMPLER2D(s_texColor, 0);

void main()
{
    vec3 rgb = decodeRGBE8(texture2D(s_texColor, v_texcoord0) );
    gl_FragColor = toGamma(vec4(rgb, 1.0) );
}