options indenting = 4
options no_unused_block_arguments = false
options no_unused_function_arguments = false

module bgfx_ttf shared private

require dasbgfx/bgfx_boost
require ttf/stb_ttf_common public
require daslib/safe_addr
require daslib/math_boost

var [[in]] a_position : float2
var [[in]] a_texcoord0 : float2
var [[inout]] v_texcoord0 : float2
var [[uniform, stage=0]] f_tex : sampler2D
var [[uniform]] v_mvp : float4x4
var [[uniform]] f_tint : float4

[bgfx_vertex_program]
def TTF_vs_main
    v_texcoord0 = a_texcoord0
    gl_Position = v_mvp * float4(a_position, 0.0, 1.0)

[bgfx_fragment_program]
def TTF_fs_main
    let tex = texture2D(f_tex,v_texcoord0)
    gl_FragColor = float4(f_tint.xyz,tex.w)

[bgfx_vertex_buffer]
struct TTF_FontVertex
    position  : float2
    texcoord0 : float2

class BGFXTTFApiAdapter : TTFApiAdapter
    def override create_font_texture ( dim:int2; data:array<uint8> ) : uint64
        unsafe
            var mem = bgfx_copy(addr(data[0]),uint(length(data)))
            var tex = bgfx_create_texture_2d(uint(dim.x), uint(dim.y), false, 1u, bgfx_texture_format A8, 0ul, mem)
            return uint64(tex.idx)
    def override destroy_font_texture ( tex:uint64 ) : void
        var th = [[bgfx_texture_handle_s idx=uint16(tex)]]
        bgfx_destroy_texture(th)

var private program : bgfx_program_handle_s
var private font_vertex_decl : bgfx_vertex_layout_s

def public bgfx_create_ttf_objects
    set_api_adapter <| new BGFXTTFApiAdapter()
    font_vertex_decl = bgfx_create_vertex_layout(type<TTF_FontVertex>)
    program = bgfx_create_shader_program(@@TTF_vs_main,@@TTF_fs_main)
    return program

def public bgfx_draw_quads_2d ( font:Font; stream:uint; quads : array<FontVertex>; w,h,x,y:int; tint:float3 = float3(1.) )
    let view = translation(float3(x, y, 0))
    let projection = bgfx_mat_ortho(0.,float(w),float(h),0.,-1.,1.,0.,bgfx_get_caps().homogeneousDepth,false)
    let mvp = projection * view
    font |> bgfx_draw_quads(stream, quads, mvp, tint)

def public bgfx_draw_quads ( font:Font; stream:uint; quads : array<FontVertex>; mvp:float4x4; tint:float3 = float3(1.) )
    assert(program.idx!=uint16(0),"missing create_ttf_objects or cache_ttf_objects somewhere in the initialization")
    if empty(quads)
        return
    let totalq = uint(length(quads))
    let totalidx = totalq /4u * 6u
    var tvb : bgfx_transient_vertex_buffer_s
    var tib : bgfx_transient_index_buffer_s
    if ! bgfx_alloc_transient_buffers(safe_addr(tvb), safe_addr(font_vertex_decl), totalq, safe_addr(tib), totalidx, true)
        print("WARNING: out of transient buffers, ttf will not be displayed")
        return
    unsafe
        var pq : FontVertex? = reinterpret<FontVertex?> tvb.data
        for v in quads
            *pq = v
            pq ++
        var pi : uint? = reinterpret<uint?> tib.data
        for idx in urange(totalq / 4u)
            pi[0] = idx*4u+0u
            pi[1] = idx*4u+1u
            pi[2] = idx*4u+2u
            pi[3] = idx*4u+2u
            pi[4] = idx*4u+3u
            pi[5] = idx*4u+0u
            pi += 6
    let stateBlendFont = (0ul
        | BGFX_STATE_WRITE_RGB
        | BGFX_STATE_WRITE_A
        | BGFX_STATE_DEPTH_TEST_ALWAYS
        | BGFX_STATE_MSAA
        | BGFX_STATE_BLEND_ALPHA
    )
    bgfx_set_transient_vertex_buffer(0u, safe_addr(tvb), 0u, totalq)
    bgfx_set_transient_index_buffer(safe_addr(tib), 0u, totalidx)
    f_tex.texture2D = uint(font.tex)
    v_mvp = mvp
    f_tint = float4(tint, 1.)
    TTF_vs_main_bind_uniform()
    TTF_fs_main_bind_uniform()
    bgfx_set_state(stateBlendFont, 0u)
    bgfx_submit(stream, program, 1u, BGFX_DISCARD_NONE)

