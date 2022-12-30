#include <bgfx_shader.sh>
#include "shaderlib.sh"

#define MAX_NUM_POINT_LIGHTS 64
#define MAX_NUM_SPOT_LIGHTS 8

#define ATTENUATION_CONSTANT 1.0
#define ATTENUATION_LINEAR_CONSTANT 4.5
#define ATTENUATION_QUADRATIC_CONSTANT 75.0

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
// X = Radius, Y = Intensity, Z = EMPTY, W = EMPTY
uniform vec4 PointLights_Params[MAX_NUM_POINT_LIGHTS];

// SPOT LIGHTS
uniform vec4 SpotLights_Position[MAX_NUM_SPOT_LIGHTS];
uniform vec4 SpotLights_Direction[MAX_NUM_SPOT_LIGHTS];
uniform vec4 SpotLights_Diffuse[MAX_NUM_SPOT_LIGHTS];
uniform vec4 SpotLights_Ambient[MAX_NUM_SPOT_LIGHTS];
// X = Radius, Y = Angle, Z = Intensity, W = EMPTY
uniform vec4 SpotLights_Params[MAX_NUM_SPOT_LIGHTS];

//float attenuation = 1.0 / (light.constant + light.linear * distance + 
//    		    light.quadratic * (distance * distance));    
float BlinnPhong_Attenuation(float range, float dist)
{
    float l     = ATTENUATION_LINEAR_CONSTANT / range;
    float q     = ATTENUATION_QUADRATIC_CONSTANT / range;

    return 1.0 / (ATTENUATION_CONSTANT + l * dist + q * (dist * dist));
}

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
    vec3    plDir      = PointLights_Position[lightIdx].xyz - position;
    vec3    s          = normalize(plDir);
    float   sDotN      = max(dot(s, normal), 0.0);
    vec3    diffuse    = materialDiffuse * sDotN;
    vec3    spec       = vec3(0.0, 0.0, 0.0);
    
    if(sDotN > 0.0)
    {
        vec3 v = normalize(-position);
        vec3 h = normalize(v + s);
        spec =  materialSpecular * pow(max(dot(h, normal), 0.0), shininess);
    }
    float range     = PointLights_Params[lightIdx].x;
    float intensity = PointLights_Params[lightIdx].y;

    float attenuation = BlinnPhong_Attenuation(range, length(plDir));

    ambient     *= attenuation;
    diffuse     *= attenuation;
    spec        *= attenuation;

    return (ambient + PointLights_Diffuse[lightIdx].xyz * (diffuse + spec)) * intensity;
}

vec3 BlinnPhong_Spot(int lightIdx, vec3 position, vec3 normal, vec3 materialAmbient, vec3 materialDiffuse, vec3 materialSpecular, float shininess)
{
    vec3    ambient    = SpotLights_Ambient[lightIdx].xyz * materialAmbient;
    vec3    diffuse    = vec3(0.0, 0.0, 0.0);
    vec3    spec       = vec3(0.0, 0.0, 0.0);
    vec3    slDir      = SpotLights_Position[lightIdx].xyz - position;
    vec3    s          = normalize(slDir);

    float cosAngle     = dot(-s, normalize(SpotLights_Direction[lightIdx].xyz));
    float angle        = acos(cosAngle);
    float range        = 0.0;

    if(angle < SpotLights_Params[lightIdx].y)
    {
        range   = pow(cosAngle, SpotLights_Params[lightIdx].x);
        float sDotN = max(dot(s, normal), 0.0);
        diffuse    = materialDiffuse * sDotN;
        if(sDotN > 0.0)
        {
            vec3 v = normalize(-position);
            vec3 h = normalize(v + s);
            spec =  materialSpecular * pow(max(dot(h, normal), 0.0), shininess);
        }
    }

    float attenuation = BlinnPhong_Attenuation(range, length(slDir));

    ambient     *= attenuation;
    diffuse     *= attenuation;
    spec        *= attenuation;

    return ambient + range * SpotLights_Diffuse[lightIdx].xyz  * (diffuse + spec);
}