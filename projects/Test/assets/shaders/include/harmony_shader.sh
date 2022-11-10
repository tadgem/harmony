/*
    Harmony Shader Lib
*/
#include "bgfx_shader.sh"
struct DirectionalLight
{
    vec4 Direction;
    vec4 Colour;
};

struct PointLight
{
    vec4 Position;
    vec4 Colour;

    float Radius;
};