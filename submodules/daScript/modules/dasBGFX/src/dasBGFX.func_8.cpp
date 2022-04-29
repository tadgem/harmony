// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasBGFX.h"
#include "need_dasBGFX.h"
namespace das {
void Module_dasBGFX::initFunctions_8() {
	addExtern< void (*)(bgfx_encoder_s *,unsigned short,bgfx_program_handle_s,unsigned int,unsigned int,unsigned int,unsigned char) , bgfx_encoder_dispatch >(*this,lib,"bgfx_encoder_dispatch",SideEffects::worstDefault,"bgfx_encoder_dispatch")
		->args({"_this","_id","_program","_numX","_numY","_numZ","_flags"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned short,bgfx_program_handle_s,bgfx_indirect_buffer_handle_s,unsigned short,unsigned short,unsigned char) , bgfx_encoder_dispatch_indirect >(*this,lib,"bgfx_encoder_dispatch_indirect",SideEffects::worstDefault,"bgfx_encoder_dispatch_indirect")
		->args({"_this","_id","_program","_indirectHandle","_start","_num","_flags"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char) , bgfx_encoder_discard >(*this,lib,"bgfx_encoder_discard",SideEffects::worstDefault,"bgfx_encoder_discard")
		->args({"_this","_flags"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned short,bgfx_texture_handle_s,unsigned char,unsigned short,unsigned short,unsigned short,bgfx_texture_handle_s,unsigned char,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short) , bgfx_encoder_blit >(*this,lib,"bgfx_encoder_blit",SideEffects::worstDefault,"bgfx_encoder_blit")
		->args({"_this","_id","_dst","_dstMip","_dstX","_dstY","_dstZ","_src","_srcMip","_srcX","_srcY","_srcZ","_width","_height","_depth"});
	addExtern< void (*)(bgfx_frame_buffer_handle_s,const char *) , bgfx_request_screen_shot >(*this,lib,"bgfx_request_screen_shot",SideEffects::worstDefault,"bgfx_request_screen_shot")
		->args({"_handle","_filePath"});
	addExtern< bgfx_render_frame_t (*)(int) , bgfx_render_frame >(*this,lib,"bgfx_render_frame",SideEffects::worstDefault,"bgfx_render_frame")
		->args({"_msecs"});
	addExtern< void (*)(const bgfx_platform_data_s *) , bgfx_set_platform_data >(*this,lib,"bgfx_set_platform_data",SideEffects::worstDefault,"bgfx_set_platform_data")
		->args({"_data"});
	addExtern< const bgfx_internal_data_s * (*)() , bgfx_get_internal_data >(*this,lib,"bgfx_get_internal_data",SideEffects::worstDefault,"bgfx_get_internal_data");
	addExtern< uintptr_t (*)(bgfx_texture_handle_s,uintptr_t) , bgfx_override_internal_texture_ptr >(*this,lib,"bgfx_override_internal_texture_ptr",SideEffects::worstDefault,"bgfx_override_internal_texture_ptr")
		->args({"_handle","_ptr"});
	addExtern< uintptr_t (*)(bgfx_texture_handle_s,unsigned short,unsigned short,unsigned char,bgfx_texture_format,uint64_t) , bgfx_override_internal_texture >(*this,lib,"bgfx_override_internal_texture",SideEffects::worstDefault,"bgfx_override_internal_texture")
		->args({"_handle","_width","_height","_numMips","_format","_flags"});
	addExtern< void (*)(const char *) , bgfx_set_marker >(*this,lib,"bgfx_set_marker",SideEffects::worstDefault,"bgfx_set_marker")
		->args({"_marker"});
	addExtern< void (*)(uint64_t,unsigned int) , bgfx_set_state >(*this,lib,"bgfx_set_state",SideEffects::worstDefault,"bgfx_set_state")
		->args({"_state","_rgba"});
	addExtern< void (*)(bgfx_occlusion_query_handle_s,bool) , bgfx_set_condition >(*this,lib,"bgfx_set_condition",SideEffects::worstDefault,"bgfx_set_condition")
		->args({"_handle","_visible"});
	addExtern< void (*)(unsigned int,unsigned int) , bgfx_set_stencil >(*this,lib,"bgfx_set_stencil",SideEffects::worstDefault,"bgfx_set_stencil")
		->args({"_fstencil","_bstencil"});
	addExtern< unsigned short (*)(unsigned short,unsigned short,unsigned short,unsigned short) , bgfx_set_scissor >(*this,lib,"bgfx_set_scissor",SideEffects::worstDefault,"bgfx_set_scissor")
		->args({"_x","_y","_width","_height"});
	addExtern< void (*)(unsigned short) , bgfx_set_scissor_cached >(*this,lib,"bgfx_set_scissor_cached",SideEffects::worstDefault,"bgfx_set_scissor_cached")
		->args({"_cache"});
	addExtern< unsigned int (*)(const void *,unsigned short) , bgfx_set_transform >(*this,lib,"bgfx_set_transform",SideEffects::worstDefault,"bgfx_set_transform")
		->args({"_mtx","_num"});
	addExtern< void (*)(unsigned int,unsigned short) , bgfx_set_transform_cached >(*this,lib,"bgfx_set_transform_cached",SideEffects::worstDefault,"bgfx_set_transform_cached")
		->args({"_cache","_num"});
	addExtern< unsigned int (*)(bgfx_transform_s *,unsigned short) , bgfx_alloc_transform >(*this,lib,"bgfx_alloc_transform",SideEffects::worstDefault,"bgfx_alloc_transform")
		->args({"_transform","_num"});
	addExtern< void (*)(bgfx_uniform_handle_s,const void *,unsigned short) , bgfx_set_uniform >(*this,lib,"bgfx_set_uniform",SideEffects::worstDefault,"bgfx_set_uniform")
		->args({"_handle","_value","_num"});
}
}

