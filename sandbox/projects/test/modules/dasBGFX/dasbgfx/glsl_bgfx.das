options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module glsl_bgfx shared public

require glsl/glsl_common public

require dasbgfx/glsl_internal_bgfx public

require math public

let BGFX_CONFIG_MAX_BONES = 32

var [[uniform]] u_viewRect : float4
var [[uniform]] u_viewTexel : float4

var [[uniform]] u_view : float4x4
var [[uniform]] u_invView : float4x4
var [[uniform]] u_proj : float4x4
var [[uniform]] u_invProj : float4x4
var [[uniform]] u_viewProj : float4x4
var [[uniform]] u_invViewProj : float4x4
var [[uniform]] u_model : float4x4[BGFX_CONFIG_MAX_BONES]
var [[uniform]] u_modelView : float4x4
var [[uniform]] u_modelViewProj : float4x4

var [[uniform]] u_alphaRef4 : float4
