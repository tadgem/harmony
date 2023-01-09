#include <bgfx_shader.sh>
#include "shaderlib.sh"

uniform vec4 u_post_process_params;

float remap(float val, float oldMin, float oldMax, float newMin, float newMax)
{
    // Y = (X-A)/(B-A) * (D-C) + C
    float remapped_val = (val - oldMin) / (oldMax - oldMin) * (newMax, newMin) + newMin;
    return remapped_val;
}

float ScreenSpaceToViewSpaceDepth( float screenDepth, float cameraClipNear, float cameraClipFar )
{
	// Set your depthLinearizeMul and depthLinearizeAdd to:
	float depthLinearizeMul = ( cameraClipFar * cameraClipNear) / ( cameraClipFar - cameraClipNear );
	float depthLinearizeAdd = cameraClipFar / ( cameraClipFar - cameraClipNear );

	return depthLinearizeMul / ( depthLinearizeAdd - screenDepth );
}