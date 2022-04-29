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
void Module_dasBGFX::initFunctions_2() {
	addExtern< bgfx_renderer_type (*)() , bgfx_get_renderer_type >(*this,lib,"bgfx_get_renderer_type",SideEffects::worstDefault,"bgfx_get_renderer_type");
	addExtern< const bgfx_caps_s * (*)() , bgfx_get_caps >(*this,lib,"bgfx_get_caps",SideEffects::worstDefault,"bgfx_get_caps");
	addExtern< const bgfx_stats_s * (*)() , bgfx_get_stats >(*this,lib,"bgfx_get_stats",SideEffects::worstDefault,"bgfx_get_stats");
	addExtern< const bgfx_memory_s * (*)(unsigned int) , bgfx_alloc >(*this,lib,"bgfx_alloc",SideEffects::worstDefault,"bgfx_alloc")
		->args({"_size"});
	addExtern< const bgfx_memory_s * (*)(const void *,unsigned int) , bgfx_copy >(*this,lib,"bgfx_copy",SideEffects::worstDefault,"bgfx_copy")
		->args({"_data","_size"});
	addExtern< const bgfx_memory_s * (*)(const void *,unsigned int) , bgfx_make_ref >(*this,lib,"bgfx_make_ref",SideEffects::worstDefault,"bgfx_make_ref")
		->args({"_data","_size"});
	addExtern< void (*)(unsigned int) , bgfx_set_debug >(*this,lib,"bgfx_set_debug",SideEffects::worstDefault,"bgfx_set_debug")
		->args({"_debug"});
	addExtern< void (*)(unsigned char,bool) , bgfx_dbg_text_clear >(*this,lib,"bgfx_dbg_text_clear",SideEffects::worstDefault,"bgfx_dbg_text_clear")
		->args({"_attr","_small"});
	addExtern< void (*)(unsigned short,unsigned short,unsigned short,unsigned short,const void *,unsigned short) , bgfx_dbg_text_image >(*this,lib,"bgfx_dbg_text_image",SideEffects::worstDefault,"bgfx_dbg_text_image")
		->args({"_x","_y","_width","_height","_data","_pitch"});
	addExtern< bgfx_index_buffer_handle_s (*)(const bgfx_memory_s *,unsigned short) , bgfx_create_index_buffer ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_index_buffer",SideEffects::worstDefault,"bgfx_create_index_buffer")
		->args({"_mem","_flags"});
	addExtern< void (*)(bgfx_index_buffer_handle_s,const char *,int) , bgfx_set_index_buffer_name >(*this,lib,"bgfx_set_index_buffer_name",SideEffects::worstDefault,"bgfx_set_index_buffer_name")
		->args({"_handle","_name","_len"});
	addExtern< void (*)(bgfx_index_buffer_handle_s) , bgfx_destroy_index_buffer >(*this,lib,"bgfx_destroy_index_buffer",SideEffects::worstDefault,"bgfx_destroy_index_buffer")
		->args({"_handle"});
	addExtern< bgfx_vertex_layout_handle_s (*)(const bgfx_vertex_layout_s *) , bgfx_create_vertex_layout ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_vertex_layout",SideEffects::worstDefault,"bgfx_create_vertex_layout")
		->args({"_layout"});
	addExtern< void (*)(bgfx_vertex_layout_handle_s) , bgfx_destroy_vertex_layout >(*this,lib,"bgfx_destroy_vertex_layout",SideEffects::worstDefault,"bgfx_destroy_vertex_layout")
		->args({"_layoutHandle"});
	addExtern< bgfx_vertex_buffer_handle_s (*)(const bgfx_memory_s *,const bgfx_vertex_layout_s *,unsigned short) , bgfx_create_vertex_buffer ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_vertex_buffer",SideEffects::worstDefault,"bgfx_create_vertex_buffer")
		->args({"_mem","_layout","_flags"});
	addExtern< void (*)(bgfx_vertex_buffer_handle_s,const char *,int) , bgfx_set_vertex_buffer_name >(*this,lib,"bgfx_set_vertex_buffer_name",SideEffects::worstDefault,"bgfx_set_vertex_buffer_name")
		->args({"_handle","_name","_len"});
	addExtern< void (*)(bgfx_vertex_buffer_handle_s) , bgfx_destroy_vertex_buffer >(*this,lib,"bgfx_destroy_vertex_buffer",SideEffects::worstDefault,"bgfx_destroy_vertex_buffer")
		->args({"_handle"});
	addExtern< bgfx_dynamic_index_buffer_handle_s (*)(unsigned int,unsigned short) , bgfx_create_dynamic_index_buffer ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_dynamic_index_buffer",SideEffects::worstDefault,"bgfx_create_dynamic_index_buffer")
		->args({"_num","_flags"});
	addExtern< bgfx_dynamic_index_buffer_handle_s (*)(const bgfx_memory_s *,unsigned short) , bgfx_create_dynamic_index_buffer_mem ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_dynamic_index_buffer_mem",SideEffects::worstDefault,"bgfx_create_dynamic_index_buffer_mem")
		->args({"_mem","_flags"});
	addExtern< void (*)(bgfx_dynamic_index_buffer_handle_s,unsigned int,const bgfx_memory_s *) , bgfx_update_dynamic_index_buffer >(*this,lib,"bgfx_update_dynamic_index_buffer",SideEffects::worstDefault,"bgfx_update_dynamic_index_buffer")
		->args({"_handle","_startIndex","_mem"});
}
}

