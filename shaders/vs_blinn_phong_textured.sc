$input a_position, a_normal, a_texcoord0
$output v_texcoord0, v_normal, v_position, v_fragPosition, v_fragNormal

#include "harmony_shader.sh"

uniform mat4 u_mtx;

void main()
{
	gl_Position 	= mul(u_modelViewProj, vec4(a_position, 1.0) );
	v_texcoord0 	= a_texcoord0;
	// v_normal 		= a_normal;
	mat4 transposeModel = transpose(u_model[0]);

	v_position 	= a_position;
	v_normal 	= a_normal;

	v_fragNormal	= mul(transposeModel,  vec4(a_normal, 1.0)).xyz;
	v_fragPosition 	= mul(u_model[0],  vec4(a_position, 1.0)).xyz;
}
