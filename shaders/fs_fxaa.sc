$input v_texcoord0, v_normal

/*
 * Copyright 2011-2022 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "harmony_post_process.sh"

void main()
{
    vec4 color = texture2D(s_texColor, v_texcoord0);
    gl_FragColor = color;
}