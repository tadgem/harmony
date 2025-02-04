$input v_texcoord0

#include "harmony_shader.sh"
#include "harmony_forward.sh"

SAMPLER2D(u_pos,        0);
SAMPLER2D(u_normal,     1);
SAMPLER2D(u_color,      2);
SAMPLER2D(u_uv,         3);
SAMPLER2D(u_depth,      4);
SAMPLER2D(u_crossHatch, 5);

// Params
#define THICKNESS 1.0
// inverse, effective 0.0-0.1 range
#define STRENGTH 0.075
#define NOISE_SCALE 0.0005
#define CROSSHATCH_TILE 24
#define LIGHT_MAX 0.25
#define LIGHT_FACTOR 1.0

float getAve(vec2 uv){
    vec3 rgb = texture2D(u_color, uv).rgb;
    vec3 lum = vec3(0.299, 0.587, 0.114);
    return dot(lum, rgb);
}

// Detect edge.
vec4 sobel(sampler2D _tex, vec2 fragCoord, vec2 dir){
    vec2 resolution = u_viewRect.zw;
    vec2 uv = fragCoord;
    vec2 texel = vec2(1.0, 1.0) / resolution;
    float np = getAve(uv + (vec2(-1,+1) + dir ) * texel * THICKNESS);
    float zp = getAve(uv + (vec2( 0,+1) + dir ) * texel * THICKNESS);
    float pp = getAve(uv + (vec2(+1,+1) + dir ) * texel * THICKNESS);

    float nz = getAve(uv + (vec2(-1, 0) + dir ) * texel * THICKNESS);
    // zz = 0
    float pz = getAve(uv + (vec2(+1, 0) + dir ) * texel * THICKNESS);

    float nn = getAve(uv + (vec2(-1,-1) + dir ) * texel * THICKNESS);
    float zn = getAve(uv + (vec2( 0,-1) + dir ) * texel * THICKNESS);
    float pn = getAve(uv + (vec2(+1,-1) + dir ) * texel * THICKNESS);

    // np zp pp
    // nz zz pz
    // nn zn pn

    // #if 0
    float gx = (np*-1. + nz*-2. + nn*-1. + pp * 1. + pz * 2. + pn * 1.);
    float gy = (np*-1. + zp*-2. + pp*-1. + nn * 1. + zn * 2. + pn * 1.);
    // #else
    // float gx = (np*-3. + nz*-10. + nn*-3. + pp * 3. + pz * 10. + pn * 3.);
    // float gy = (np*-3. + zp*-10. + pp*-3. + nn * 3. + zn * 10. + pn * 3.);
    // #endif

    vec2 G = vec2(gx,gy);

    float grad = length(G);

    float angle = atan2(G.y, G.x);

    return vec4(G, grad, angle);
}

// Make edge thinner.
vec2 hysteresisThr(vec2 fragCoord, float mn, float mx){

    vec4 edge = sobel(u_pos, fragCoord, vec2(0,0));

    vec2 dir = vec2(cos(edge.w), sin(edge.w));
    dir = vec2(-1,1); // rotate 90 degrees.

    vec4 edgep = sobel(u_pos, fragCoord, dir);
    vec4 edgen = sobel(u_pos, fragCoord, -dir);

    if(edge.z < edgep.z || edge.z < edgen.z ) edge.z = 0.;

    return vec2(
        (edge.z > mn) ? edge.z : 0.,
        (edge.z > mx) ? edge.z : 0.
    );
}

float cannyEdge(vec2 fragCoord, float mn, float mx){

    vec2 np = hysteresisThr(fragCoord + vec2(-1,+1), mn, mx);
    vec2 zp = hysteresisThr(fragCoord + vec2( 0,+1), mn, mx);
    vec2 pp = hysteresisThr(fragCoord + vec2(+1,+1), mn, mx);

    vec2 nz = hysteresisThr(fragCoord + vec2(-1, 0), mn, mx);
    vec2 zz = hysteresisThr(fragCoord + vec2( 0, 0), mn, mx);
    vec2 pz = hysteresisThr(fragCoord + vec2(+1, 0), mn, mx);

    vec2 nn = hysteresisThr(fragCoord + vec2(-1,-1), mn, mx);
    vec2 zn = hysteresisThr(fragCoord + vec2( 0,-1), mn, mx);
    vec2 pn = hysteresisThr(fragCoord + vec2(+1,-1), mn, mx);

    // np zp pp
    // nz zz pz
    // nn zn pn
    //return min(1., step(1e-3, zz.x) (zp.y + nz.y + pz.y + zn.y)8.);
    //return min(1., step(1e-3, zz.x) (np.y + pp.y + nn.y + pn.y)8.);
    return min(1., step(1e-2, zz.x*8.) * smoothstep(.0, .3, np.y + zp.y + pp.y + nz.y + pz.y + nn.y + zn.y + pn.y)*8.);
}

void main()
{
    float xNoise = ShadertoyNoise(v_texcoord0.xy) * NOISE_SCALE;
    float yNoise = ShadertoyNoise(v_texcoord0.yx) * NOISE_SCALE;
    vec2 pixelCoord = v_texcoord0.xy + vec2(xNoise, yNoise);
    vec4 pixelColour        = texture2D(u_color, pixelCoord);
    if(pixelColour.w < 0.05)
    {
        discard;
    } 
    vec3 pixelPosition      = texture2D(u_pos, pixelCoord).xyz;
    vec3 pixelNormal        = texture2D(u_normal, v_texcoord0.xy).xyz;
    vec3 pixelDepth         = texture2D(u_depth, v_texcoord0.xy).xyz;
    
    vec4 pixelUV            = texture2D(u_uv, v_texcoord0.xy);
    vec2 crosshatchTiling = vec2(CROSSHATCH_TILE, CROSSHATCH_TILE);
    vec4 pixelCrosshatch    = texture2D(u_crossHatch, (pixelUV.xy + vec2(xNoise, yNoise)) * crosshatchTiling);
    
    vec3 outlineColor = vec3(0.1,0.1,0.1);
    float edge = cannyEdge(pixelCoord, (toClipSpaceDepth(pixelDepth.x) * STRENGTH), (toClipSpaceDepth(pixelDepth.x)  * STRENGTH));
    vec3 col = mix(outlineColor, pixelColour.xyz,  1.-edge);
    vec3 ambient = vec3(0.0,0.0,0.0);
    vec3 spec = vec3(0.0,0.0,0.0);
    vec3 output     = vec3(0.0, 0.0, 0.0);
    float shininess = 0.0;
    if(DirectionalLight_Active > 0)
    {
        output += BlinnPhong_Directional(pixelPosition, pixelNormal, ambient, col, spec, shininess);
    }

    for(int i = 0; i < PointLights_NumActive; i++)
    {
        output += BlinnPhong_Point(i, pixelPosition, pixelNormal, ambient, col, spec, shininess);
    }

    for(int i = 0; i < SpotLights_NumActive; i++)
    {
        output += BlinnPhong_Spot(i, pixelPosition, pixelNormal, ambient, col, spec, shininess);
    }

    float crosshatch = 0.0;
    float mag = length(output);
    float lightMax = LIGHT_MAX;
    float partialLit = lightMax * 1.0;
    float partialOccluded = lightMax * 0.75;
    float occluded = lightMax * 0.5;

    crosshatch += (pixelCrosshatch.z * (1.0 -mag) * partialLit);
    crosshatch += (pixelCrosshatch.y * (1.0 -mag) * partialOccluded);
    crosshatch += (pixelCrosshatch.x * (1.0 -mag) * occluded);

    if(mag < 0.01)
    {
        output = vec3(0.1, 0.1, 0.1);
    }
    
    vec3 finalColor = col * (normalize(output) * LIGHT_FACTOR);
    if(crosshatch  > 0.1)    
    {
        crosshatch = 1.0;
    }
    
    if(crosshatch < 0.0)
    {
        crosshatch  = 0.0;
    }

    col = mix(finalColor, outlineColor, crosshatch);

    gl_FragColor = vec4(col, 1.0);
}