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
void Module_dasBGFX::initFunctions_5() {
	addExtern< bgfx_frame_buffer_handle_s (*)(void *,unsigned short,unsigned short,bgfx_texture_format,bgfx_texture_format) , bgfx_create_frame_buffer_from_nwh ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_frame_buffer_from_nwh",SideEffects::worstDefault,"bgfx_create_frame_buffer_from_nwh")
		->args({"_nwh","_width","_height","_format","_depthFormat"});
	addExtern< void (*)(bgfx_frame_buffer_handle_s,const char *,int) , bgfx_set_frame_buffer_name >(*this,lib,"bgfx_set_frame_buffer_name",SideEffects::worstDefault,"bgfx_set_frame_buffer_name")
		->args({"_handle","_name","_len"});
	addExtern< bgfx_texture_handle_s (*)(bgfx_frame_buffer_handle_s,unsigned char) , bgfx_get_texture ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_get_texture",SideEffects::worstDefault,"bgfx_get_texture")
		->args({"_handle","_attachment"});
	addExtern< void (*)(bgfx_frame_buffer_handle_s) , bgfx_destroy_frame_buffer >(*this,lib,"bgfx_destroy_frame_buffer",SideEffects::worstDefault,"bgfx_destroy_frame_buffer")
		->args({"_handle"});
	addExtern< bgfx_uniform_handle_s (*)(const char *,bgfx_uniform_type,unsigned short) , bgfx_create_uniform ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_uniform",SideEffects::worstDefault,"bgfx_create_uniform")
		->args({"_name","_type","_num"});
	addExtern< void (*)(bgfx_uniform_handle_s,bgfx_uniform_info_s *) , bgfx_get_uniform_info >(*this,lib,"bgfx_get_uniform_info",SideEffects::worstDefault,"bgfx_get_uniform_info")
		->args({"_handle","_info"});
	addExtern< void (*)(bgfx_uniform_handle_s) , bgfx_destroy_uniform >(*this,lib,"bgfx_destroy_uniform",SideEffects::worstDefault,"bgfx_destroy_uniform")
		->args({"_handle"});
	addExtern< bgfx_occlusion_query_handle_s (*)() , bgfx_create_occlusion_query ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_occlusion_query",SideEffects::worstDefault,"bgfx_create_occlusion_query");
	addExtern< bgfx_occlusion_query_result (*)(bgfx_occlusion_query_handle_s,int *) , bgfx_get_result >(*this,lib,"bgfx_get_result",SideEffects::worstDefault,"bgfx_get_result")
		->args({"_handle","_result"});
	addExtern< void (*)(bgfx_occlusion_query_handle_s) , bgfx_destroy_occlusion_query >(*this,lib,"bgfx_destroy_occlusion_query",SideEffects::worstDefault,"bgfx_destroy_occlusion_query")
		->args({"_handle"});
	addExtern< void (*)(unsigned char,float const[4]) , bgfx_set_palette_color >(*this,lib,"bgfx_set_palette_color",SideEffects::worstDefault,"bgfx_set_palette_color")
		->args({"_index","_rgba"});
	addExtern< void (*)(unsigned char,unsigned int) , bgfx_set_palette_color_rgba8 >(*this,lib,"bgfx_set_palette_color_rgba8",SideEffects::worstDefault,"bgfx_set_palette_color_rgba8")
		->args({"_index","_rgba"});
	addExtern< void (*)(unsigned short,const char *) , bgfx_set_view_name >(*this,lib,"bgfx_set_view_name",SideEffects::worstDefault,"bgfx_set_view_name")
		->args({"_id","_name"});
	addExtern< void (*)(unsigned short,unsigned short,unsigned short,unsigned short,unsigned short) , bgfx_set_view_rect >(*this,lib,"bgfx_set_view_rect",SideEffects::worstDefault,"bgfx_set_view_rect")
		->args({"_id","_x","_y","_width","_height"});
	addExtern< void (*)(unsigned short,unsigned short,unsigned short,bgfx_backbuffer_ratio) , bgfx_set_view_rect_ratio >(*this,lib,"bgfx_set_view_rect_ratio",SideEffects::worstDefault,"bgfx_set_view_rect_ratio")
		->args({"_id","_x","_y","_ratio"});
	addExtern< void (*)(unsigned short,unsigned short,unsigned short,unsigned short,unsigned short) , bgfx_set_view_scissor >(*this,lib,"bgfx_set_view_scissor",SideEffects::worstDefault,"bgfx_set_view_scissor")
		->args({"_id","_x","_y","_width","_height"});
	addExtern< void (*)(unsigned short,unsigned short,unsigned int,float,unsigned char) , bgfx_set_view_clear >(*this,lib,"bgfx_set_view_clear",SideEffects::worstDefault,"bgfx_set_view_clear")
		->args({"_id","_flags","_rgba","_depth","_stencil"});
	addExtern< void (*)(unsigned short,unsigned short,float,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char,unsigned char) , bgfx_set_view_clear_mrt >(*this,lib,"bgfx_set_view_clear_mrt",SideEffects::worstDefault,"bgfx_set_view_clear_mrt")
		->args({"_id","_flags","_depth","_stencil","_c0","_c1","_c2","_c3","_c4","_c5","_c6","_c7"});
	addExtern< void (*)(unsigned short,bgfx_view_mode) , bgfx_set_view_mode >(*this,lib,"bgfx_set_view_mode",SideEffects::worstDefault,"bgfx_set_view_mode")
		->args({"_id","_mode"});
	addExtern< void (*)(unsigned short,bgfx_frame_buffer_handle_s) , bgfx_set_view_frame_buffer >(*this,lib,"bgfx_set_view_frame_buffer",SideEffects::worstDefault,"bgfx_set_view_frame_buffer")
		->args({"_id","_handle"});
}
}

