$input v_texcoord0

#include "harmony_shader.sh"

#define MAX_NUM_LIGHTS 16

uniform DirectionalLight s_DirLight;
uniform PointLight       s_PointLights[MAX_NUM_LIGHTS];

SAMPLER2D(s_texColor, 0);

void main()
{
    vec4 color = texture2D(s_texColor, v_texcoord0);
    gl_FragColor = color;
}