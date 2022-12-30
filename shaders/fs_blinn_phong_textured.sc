$input v_texcoord0, v_normal, v_position, v_fragPosition, v_fragNormal

#include "harmony_forward.sh"

SAMPLER2D(s_texColor, 0);

void main()
{
    vec3 diffuse    = texture2D(s_texColor, v_texcoord0).xyz;
    vec3 ambient    = diffuse * 0.2;
    vec3 spec       = vec3(0.0, 0.0, 0.0);
    float shininess = 0.0;

    vec3 output     = vec3(0.0, 0.0, 0.0);

    if(DirectionalLight_Active > 0)
    {
        output += BlinnPhong_Directional(v_position, v_normal, ambient, diffuse, spec, shininess);
    }

    for(int i = 0; i < PointLights_NumActive; i++)
    {
        output += BlinnPhong_Point(i, v_fragPosition, v_fragNormal, ambient, diffuse, spec, shininess);
    }

    for(int i = 0; i < SpotLights_NumActive; i++)
    {
        output += BlinnPhong_Spot(i, v_fragPosition, v_fragNormal, ambient, diffuse, spec, shininess);
    }

    gl_FragColor = vec4(output, 1.0);
}