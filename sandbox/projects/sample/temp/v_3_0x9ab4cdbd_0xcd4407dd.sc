$input a_position
$input a_color0
$output v_color0

#include <bgfx_shader.sh>

ivec2 range ( int r ) { return ivec2(0,r); }
ivec2 range ( int f, int t ) { return ivec2(f,t); }
float SATURATE ( float a ) { return clamp(a,0.,1.); }
vec2 SATURATE ( vec2 a ) { return clamp(a,vec2(0.,0.),vec2(1.,1.)); }
vec3 SATURATE ( vec3 a ) { return clamp(a,vec3(0.,0.,0.),vec3(1.,1.,1.)); }
vec4 SATURATE ( vec4 a ) { return clamp(a,vec4(0.,0.,0.,0.),vec4(1.,1.,1.,1.)); }
void sincos ( float a, out float sv, out float cv ) { sv=sin(a); cv=cos(a); }
float length_sq ( vec2 t ) { return dot(t,t); }
float length_sq ( vec3 t ) { return dot(t,t); }
float length_sq ( vec4 t ) { return dot(t,t); }
float mad ( float a, float b, float c ) { return a*b+c; }
vec2 mad ( vec2 a, float b, vec2 c ) { return a*vec2(b,b)+c; }
vec3 mad ( vec3 a, float b, vec3 c ) { return a*vec3(b,b,b)+c; }
vec4 mad ( vec4 a, float b, vec4 c ) { return a*vec4(b,b,b,b)+c; }
vec2 mad ( vec2 a, vec2 b, vec2 c ) { return a*b+c; }
vec3 mad ( vec3 a, vec3 b, vec3 c ) { return a*b+c; }
vec4 mad ( vec4 a, vec4 b, vec4 c ) { return a*b+c; }
float distance_sq ( vec3 a, vec3 b ) { return length_sq(a-b); }
float inv_distance_sq ( vec3 a, vec3 b ) { return 1. / distance_sq(a,b); }
vec2 VEC2(float c) { return vec2(c,c); }
vec2 VEC2(float x, float y) { return vec2(x,y); }
vec2 VEC2(ivec2 c) { return vec2(float(c.x),float(c.y)); }
vec2 VEC2(uvec2 c) { return vec2(float(c.x),float(c.y)); }
vec3 VEC3(float c) { return vec3(c,c,c); }
vec3 VEC3(float x, float y, float z) { return vec3(x,y,z); }
vec3 VEC3(vec2 xy, float z) { return vec3(xy.x,xy.y,z); }
vec3 VEC3(float x, vec2 yz) { return vec3(x,yz.x,yz.y); }
vec3 VEC3(ivec3 c) { return vec3(float(c.x),float(c.y),float(c.z)); }
vec4 VEC4(float c) { return vec4(c,c,c,c); }
vec4 VEC4(vec2 xy, float z, float w) { return vec4(xy.x,xy.y,z,w); }
vec4 VEC4(vec2 xy, vec2 zw) { return vec4(xy.x,xy.y,zw.x,zw.y); }
vec4 VEC4(float x, float y, vec2 zw) { return vec4(x,y,zw.x,zw.y); }
vec4 VEC4(float x, vec2 yz, float w) { return vec4(x,yz.x,yz.y,w); }
vec4 VEC4(vec3 xyz, float w) { return vec4(xyz.x,xyz.y,xyz.z,w); }
vec4 VEC4(float x, vec3 yzw) { return vec4(x,yzw.x,yzw.y,yzw.z); }
vec4 VEC4(float x, float y, float z, float w) { return vec4(x,y,z,w); }
vec4 VEC4(ivec4 c) { return vec4(float(c.x),float(c.y),float(c.z),float(c.w)); }
ivec2 IVEC2(int c) { return ivec2(c,c); }
ivec2 IVEC2(uvec2 c) { return ivec2(int(c.x),int(c.y)); }
ivec2 IVEC2(int x, int y) { return ivec2(x,y); }
ivec3 IVEC3(int c) { return ivec3(c,c,c); }
ivec3 IVEC3(int x, int y, int z) { return ivec3(x,y,z); }
ivec3 IVEC3(ivec2 xy, int z) { return ivec3(xy.x,xy.y,z); }
ivec3 IVEC3(int x, ivec2 yz) { return ivec3(x,yz.x,yz.y); }
ivec4 IVEC4(int c) { return ivec4(c,c,c,c); }
ivec4 IVEC4(ivec2 xy, int z, int w) { return ivec4(xy.x,xy.y,z,w); }
ivec4 IVEC4(ivec2 xy, ivec2 zw) { return ivec4(xy.x,xy.y,zw.x,zw.y); }
ivec4 IVEC4(int x, int y, ivec2 zw) { return ivec4(x,y,zw.x,zw.y); }
ivec4 IVEC4(int x, ivec2 yz, int w) { return ivec4(x,yz.x,yz.y,w); }
ivec4 IVEC4(ivec3 xyz, int w) { return ivec4(xyz.x,xyz.y,xyz.z,w); }
ivec4 IVEC4(int x, ivec3 yzw) { return ivec4(x,yzw.x,yzw.y,yzw.z); }
ivec4 IVEC4(int x, int y, int z, int w) { return ivec4(x,y,z,w); }
uvec2 UVEC2(uint c) { return uvec2(c,c); }
uvec2 UVEC2(ivec2 c) { return uvec2(uint(c.x),uint(c.y)); }
uvec2 UVEC2(uint x, uint y) { return uvec2(x,y); }
uvec3 UVEC3(uint c) { return uvec3(c,c,c); }
uvec3 UVEC3(uint x, uint y, uint z) { return uvec3(x,y,z); }
uvec3 UVEC3(uvec2 xy, uint z) { return uvec3(xy.x,xy.y,z); }
uvec3 UVEC3(uint x, uvec2 yz) { return uvec3(x,yz.x,yz.y); }
uvec4 UVEC4(uint c) { return uvec4(c,c,c,c); }
uvec4 UVEC4(uvec2 xy, uint z, uint w) { return uvec4(xy.x,xy.y,z,w); }
uvec4 UVEC4(uvec2 xy, uvec2 zw) { return uvec4(xy.x,xy.y,zw.x,zw.y); }
uvec4 UVEC4(uint x, uint y, uvec2 zw) { return uvec4(x,y,zw.x,zw.y); }
uvec4 UVEC4(uint x, uvec2 yz, uint w) { return uvec4(x,yz.x,yz.y,w); }
uvec4 UVEC4(uvec3 xyz, uint w) { return uvec4(xyz.x,xyz.y,xyz.z,w); }
uvec4 UVEC4(uint x, uvec3 yzw) { return uvec4(x,yzw.x,yzw.y,yzw.z); }
uvec4 UVEC4(uint x, uint y, uint z, uint w) { return uvec4(x,y,z,w); }
mat3 MAT3(vec3 a, vec3 b, vec3 c) { mat3 res; res[0]=a; res[1]=b; res[2]=c; return res; }
mat3 MAT3(mat4 m) { mat3 res; res[0]=m[0].xyz; res[1]=m[1].xyz; res[2]=m[2].xyz; return res; }
mat4 MAT4(vec4 a, vec4 b, vec4 c, vec4 d) { mat4 res; res[0]=a; res[1]=b; res[2]=c; res[3]=d; return res; }
vec3 MUL(mat3 a, vec3 b) { return a[0]*b.x + a[1]*b.y + a[2]*b.z; }
mat3 MUL(mat3 a, mat3 b) {
                mat3 res;
                res[0] = a[0]*b[0].x + a[1]*b[0].y + a[2]*b[0].z;
                res[1] = a[0]*b[1].x + a[1]*b[1].y + a[2]*b[1].z;
                res[2] = a[0]*b[2].x + a[1]*b[2].y + a[2]*b[2].z;
                return res; }
vec4 MUL(mat4 a, vec4 b) { return a[0]*b.x + a[1]*b.y + a[2]*b.z + a[3]*b.w; }
mat4 MUL(mat4 a, mat4 b) {
                mat4 res;
                res[0] = a[0]*b[0].x + a[1]*b[0].y + a[2]*b[0].z + a[3]*b[0].w;
                res[1] = a[0]*b[1].x + a[1]*b[1].y + a[2]*b[1].z + a[3]*b[1].w;
                res[2] = a[0]*b[2].x + a[1]*b[2].y + a[2]*b[2].z + a[3]*b[2].w;
                res[3] = a[0]*b[3].x + a[1]*b[3].y + a[2]*b[3].z + a[3]*b[3].w;
                return res; }

// in vec2 a_position;

// in vec3 a_color0;

// out vec3 v_color0;

uniform mat4 v_ortho;

void main()
{
	v_color0 = a_color0;
	gl_Position = MUL(v_ortho, VEC4(a_position,0,1));
}

