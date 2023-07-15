$input v_texcoord0

#include "harmony_shader.sh"

#define THRESHOLD 1.0

SAMPLER2D(u_pos,        0);
SAMPLER2D(u_normal,     1);
SAMPLER2D(u_color,      2);
//SAMPLER2D(u_depth,      3);
//SAMPLER2D(u_uv,         4);
//SAMPLER2D(u_crossHatch, 5);

// ref: (in japanese)
// https://imagingsolution.net/imaging/canny-edge-detector/
#define tickness 1.0
#define STRENGTH 0.8

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
    float np = getAve(uv + (vec2(-1,+1) + dir ) * texel * tickness);
    float zp = getAve(uv + (vec2( 0,+1) + dir ) * texel * tickness);
    float pp = getAve(uv + (vec2(+1,+1) + dir ) * texel * tickness);

    float nz = getAve(uv + (vec2(-1, 0) + dir ) * texel * tickness);
    // zz = 0
    float pz = getAve(uv + (vec2(+1, 0) + dir ) * texel * tickness);

    float nn = getAve(uv + (vec2(-1,-1) + dir ) * texel * tickness);
    float zn = getAve(uv + (vec2( 0,-1) + dir ) * texel * tickness);
    float pn = getAve(uv + (vec2(+1,-1) + dir ) * texel * tickness);

    // np zp pp
    // nz zz pz
    // nn zn pn

    #if 0
    float gx = (np-1. + nz-2. + nn-1. + pp * 1. + pz * 2. + pn * 1.);
    float gy = (np-1. + zp-2. + pp-1. + nn * 1. + zn * 2. + pn * 1.);
    #else
    // https://www.shadertoy.com/view/Wds3Rl
    float gx = (np*-3. + nz*-10. + nn*-3. + pp * 3. + pz * 10. + pn * 3.);
    float gy = (np*-3. + zp*-10. + pp*-3. + nn * 3. + zn * 10. + pn * 3.);
    #endif

    vec2 G = vec2(gx,gy);

    float grad = length(G);

    float angle = atan2(G.y, G.x);

    return vec4(G, grad, angle);
}

// Make edge thinner.
vec2 hysteresisThr(vec2 fragCoord, float mn, float mx){

    vec4 edge = sobel(u_color, fragCoord, vec2(0,0));

    vec2 dir = vec2(cos(edge.w), sin(edge.w));
    dir = vec2(-1,1); // rotate 90 degrees.

    vec4 edgep = sobel(u_color, fragCoord, dir);
    vec4 edgen = sobel(u_color, fragCoord, -dir);

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
    vec2 pixelCoord = v_texcoord0.xy;
    vec4 pixelColour = texture2D(u_color, pixelCoord);

    if(pixelColour.w < 0.05)
    {
        discard;
    } 

    float edge = cannyEdge(pixelCoord, 1.0 - STRENGTH, 1.0 - STRENGTH);
    vec3 col = mix(vec3(0.145,0.118,0.055), pixelColour.xyz,  1.-edge);
    gl_FragColor = vec4(col,1.0);
}