#include <bgfx_shader.sh>
#include "shaderlib.sh"

#define MAX_NUM_POINT_LIGHTS 64
#define MAX_NUM_SPOT_LIGHTS 8

// Light Params
// X = Dir Light Active ( > 0), Y = Num Active Point Lights, Z = Num Active Spot Lights
uniform vec4 Light_Params;

#define DirectionalLight_Active floatBitsToUint(Light_Params.x)
#define PointLights_NumActive floatBitsToUint(Light_Params.y)
#define SpotLights_NumActive floatBitsToUint(Light_Params.z)

// Directional Light
uniform vec4 DirectionalLight_Direction;
uniform vec4 DirectionalLight_Diffuse;
uniform vec4 DirectionalLight_Ambient;

// POINT LIGHTS
uniform vec4 PointLights_Position[MAX_NUM_POINT_LIGHTS];
uniform vec4 PointLights_Diffuse[MAX_NUM_POINT_LIGHTS];
uniform vec4 PointLights_Ambient[MAX_NUM_POINT_LIGHTS];
// X = Radius, Y = EMPTY, Z = EMPTY, W = EMPTY
uniform vec4 PointLights_Params[MAX_NUM_POINT_LIGHTS];

// SPOT LIGHTS
uniform vec4 SpotLights_Position[MAX_NUM_SPOT_LIGHTS];
uniform vec4 SpotLights_Direction[MAX_NUM_SPOT_LIGHTS];
uniform vec4 SpotLights_Diffuse[MAX_NUM_SPOT_LIGHTS];
uniform vec4 SpotLights_Ambient[MAX_NUM_SPOT_LIGHTS];
// X = Radius, Y = Angle, Z = EMPTY, W = EMPTY
uniform vec4 SpotLights_Params[MAX_NUM_SPOT_LIGHTS];

vec3 BlinnPhong_Directional(vec3 position, vec3 normal, vec3 materialAmbient, vec3 materialDiffuse, vec3 materialSpecular, float shininess)
{
    vec3 lightDir = normalize(-DirectionalLight_Direction.xyz);
    float diff = max(dot(normal, lightDir), 0.0);
    float s = pow(max(dot(normal, lightDir), 0.0), shininess);

    vec3    ambient     = DirectionalLight_Ambient.xyz * materialAmbient;
    vec3    diffuse     = DirectionalLight_Diffuse.xyz * diff * materialDiffuse;
	vec3    spec        = DirectionalLight_Diffuse.xyz * s * materialSpecular;

    return (ambient + diffuse + spec);
}

vec3 BlinnPhong_Point(int lightIdx, vec3 position, vec3 normal, vec3 materialAmbient, vec3 materialDiffuse, vec3 materialSpecular, float shininess)
{
    vec3    ambient    = PointLights_Ambient[lightIdx].xyz * materialAmbient;
    vec3    s          = normalize(PointLights_Position[lightIdx].xyz - position);
    float   sDotN      = max(dot(s, normal), 0.0);
    vec3    diffuse    = materialDiffuse * sDotN;
    vec3    spec       = vec3(0.0, 0.0, 0.0);
    
    if(sDotN > 0.0)
    {
        vec3 v = normalize(-position);
        vec3 h = normalize(v + s);
        spec =  materialSpecular * pow(max(dot(h, normal), 0.0), shininess);
    }

    float attenuation = 1.0 / PointLights_Params[lightIdx].x;

    ambient     *= attenuation;
    diffuse     *= attenuation;
    spec        *= attenuation;

    return ambient + PointLights_Diffuse[lightIdx].xyz * (diffuse + spec);
}

vec3 BlinnPhong_Spot(int lightIdx, vec3 position, vec3 normal, vec3 materialAmbient, vec3 materialDiffuse, vec3 materialSpecular, float shininess)
{
    vec3    ambient    = SpotLights_Ambient[lightIdx].xyz * materialAmbient;
    vec3    diffuse    = vec3(0.0, 0.0, 0.0);
    vec3    spec       = vec3(0.0, 0.0, 0.0);

    vec3    s          = normalize(SpotLights_Position[lightIdx].xyz - position);

    float cosAngle     = dot(-s, normalize(SpotLights_Direction[lightIdx].xyz));
    float angle        = acos(cosAngle);
    float spotScale    = 0.0;

    if(angle < SpotLights_Params[lightIdx].y)
    {
        spotScale   = pow(cosAngle, SpotLights_Params[lightIdx].x);
        float sDotN = max(dot(s, normal), 0.0);
        diffuse    = materialDiffuse * sDotN;
        if(sDotN > 0.0)
        {
            vec3 v = normalize(-position);
            vec3 h = normalize(v + s);
            spec =  materialSpecular * pow(max(dot(h, normal), 0.0), shininess);
        }
    }

    return ambient + spotScale * SpotLights_Diffuse[lightIdx].xyz  * (diffuse + spec);
}