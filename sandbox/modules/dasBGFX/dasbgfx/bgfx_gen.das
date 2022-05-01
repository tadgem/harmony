options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module bgfx_gen public

require dasbgfx/bgfx_boost public
require geometry/geom_gen public
require daslib/safe_addr
require math

[bgfx_vertex_buffer]
struct private PreviewVertex
    position : float3
    [[normalized=true]] normal : float3
    texcoord0 : float2

struct bgfx_geometry_gramgnet
    vbh : bgfx_vertex_buffer_handle_s
    ibh : bgfx_index_buffer_handle_s

def public finalize ( var frag:bgfx_geometry_gramgnet )
    with frag
        bgfx_destroy_vertex_buffer(vbh)
        bgfx_destroy_index_buffer(ibh)

def public bgfx_create_geometry_fragment ( var geometry:GeometryFragment; kill_geometry:bool=true )
    var fragment : bgfx_geometry_gramgnet
    with fragment
        var pcvl_decl = bgfx_create_vertex_layout(type<PreviewVertex>)
        vbh = bgfx_create_vertex_buffer(bgfx_copy(geometry.vertices), safe_addr(pcvl_decl), BGFX_BUFFER_NONE)
        ibh = bgfx_create_index_buffer(bgfx_copy(geometry.indices), BGFX_BUFFER_INDEX32)
        assert(geometry.prim==GeometryFragmentType triangles)
        if kill_geometry
            delete geometry
    return <- fragment

def public bgfx_draw_geometry_fragment ( view:uint; var program:bgfx_program_handle_s; var frag:bgfx_geometry_gramgnet )
    with frag
        bgfx_set_vertex_buffer(0u, vbh)
        bgfx_set_index_buffer(ibh)
        bgfx_submit(view, program, 1u, BGFX_DISCARD_NONE)

def public bgfx_create_texture ( var surf:ImageSurface; kill_pixels:bool=true )
    if length(surf.pixels) == 0
        return [[bgfx_texture_handle_s]]
    unsafe
        var tex = bgfx_load_image_from_bytes(surf.width, surf.height, addr(surf.pixels[0]))
        if kill_pixels
            delete surf.pixels
        return tex
