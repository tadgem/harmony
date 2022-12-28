$input v_texcoord0, v_normal, v_position

#include "harmony_forward.sh"

SAMPLER2D(s_texColor, 0);

void main()
{
    vec4 color = texture2D(s_texColor, v_texcoord0);

    vec3 output = vec3(0.0, 0.0, 0.0);
    if(DirectionalLight_Active > 0)
    {
        output += BlinnPhong_Directional(v_position, v_normal, color.xyz * 0.2, color.xyz, vec3(0.0,0.0, 0.0), 0.0);
    }
    gl_FragColor = color;
}