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
void Module_dasBGFX::initFunctions_3() {
	addExtern< void (*)(bgfx_dynamic_index_buffer_handle_s) , bgfx_destroy_dynamic_index_buffer >(*this,lib,"bgfx_destroy_dynamic_index_buffer",SideEffects::worstDefault,"bgfx_destroy_dynamic_index_buffer")
		->args({"_handle"});
	addExtern< bgfx_dynamic_vertex_buffer_handle_s (*)(unsigned int,const bgfx_vertex_layout_s *,unsigned short) , bgfx_create_dynamic_vertex_buffer ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_create_dynamic_vertex_buffer")
		->args({"_num","_layout","_flags"});
	addExtern< bgfx_dynamic_vertex_buffer_handle_s (*)(const bgfx_memory_s *,const bgfx_vertex_layout_s *,unsigned short) , bgfx_create_dynamic_vertex_buffer_mem ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_dynamic_vertex_buffer_mem",SideEffects::worstDefault,"bgfx_create_dynamic_vertex_buffer_mem")
		->args({"_mem","_layout","_flags"});
	addExtern< void (*)(bgfx_dynamic_vertex_buffer_handle_s,unsigned int,const bgfx_memory_s *) , bgfx_update_dynamic_vertex_buffer >(*this,lib,"bgfx_update_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_update_dynamic_vertex_buffer")
		->args({"_handle","_startVertex","_mem"});
	addExtern< void (*)(bgfx_dynamic_vertex_buffer_handle_s) , bgfx_destroy_dynamic_vertex_buffer >(*this,lib,"bgfx_destroy_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_destroy_dynamic_vertex_buffer")
		->args({"_handle"});
	addExtern< unsigned int (*)(unsigned int,bool) , bgfx_get_avail_transient_index_buffer >(*this,lib,"bgfx_get_avail_transient_index_buffer",SideEffects::worstDefault,"bgfx_get_avail_transient_index_buffer")
		->args({"_num","_index32"});
	addExtern< unsigned int (*)(unsigned int,const bgfx_vertex_layout_s *) , bgfx_get_avail_transient_vertex_buffer >(*this,lib,"bgfx_get_avail_transient_vertex_buffer",SideEffects::worstDefault,"bgfx_get_avail_transient_vertex_buffer")
		->args({"_num","_layout"});
	addExtern< unsigned int (*)(unsigned int,unsigned short) , bgfx_get_avail_instance_data_buffer >(*this,lib,"bgfx_get_avail_instance_data_buffer",SideEffects::worstDefault,"bgfx_get_avail_instance_data_buffer")
		->args({"_num","_stride"});
	addExtern< void (*)(bgfx_transient_index_buffer_s *,unsigned int,bool) , bgfx_alloc_transient_index_buffer >(*this,lib,"bgfx_alloc_transient_index_buffer",SideEffects::worstDefault,"bgfx_alloc_transient_index_buffer")
		->args({"_tib","_num","_index32"});
	addExtern< void (*)(bgfx_transient_vertex_buffer_s *,unsigned int,const bgfx_vertex_layout_s *) , bgfx_alloc_transient_vertex_buffer >(*this,lib,"bgfx_alloc_transient_vertex_buffer",SideEffects::worstDefault,"bgfx_alloc_transient_vertex_buffer")
		->args({"_tvb","_num","_layout"});
	addExtern< bool (*)(bgfx_transient_vertex_buffer_s *,const bgfx_vertex_layout_s *,unsigned int,bgfx_transient_index_buffer_s *,unsigned int,bool) , bgfx_alloc_transient_buffers >(*this,lib,"bgfx_alloc_transient_buffers",SideEffects::worstDefault,"bgfx_alloc_transient_buffers")
		->args({"_tvb","_layout","_numVertices","_tib","_numIndices","_index32"});
	addExtern< void (*)(bgfx_instance_data_buffer_s *,unsigned int,unsigned short) , bgfx_alloc_instance_data_buffer >(*this,lib,"bgfx_alloc_instance_data_buffer",SideEffects::worstDefault,"bgfx_alloc_instance_data_buffer")
		->args({"_idb","_num","_stride"});
	addExtern< bgfx_indirect_buffer_handle_s (*)(unsigned int) , bgfx_create_indirect_buffer ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_indirect_buffer",SideEffects::worstDefault,"bgfx_create_indirect_buffer")
		->args({"_num"});
	addExtern< void (*)(bgfx_indirect_buffer_handle_s) , bgfx_destroy_indirect_buffer >(*this,lib,"bgfx_destroy_indirect_buffer",SideEffects::worstDefault,"bgfx_destroy_indirect_buffer")
		->args({"_handle"});
	addExtern< bgfx_shader_handle_s (*)(const bgfx_memory_s *) , bgfx_create_shader ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_shader",SideEffects::worstDefault,"bgfx_create_shader")
		->args({"_mem"});
	addExtern< unsigned short (*)(bgfx_shader_handle_s,bgfx_uniform_handle_s *,unsigned short) , bgfx_get_shader_uniforms >(*this,lib,"bgfx_get_shader_uniforms",SideEffects::worstDefault,"bgfx_get_shader_uniforms")
		->args({"_handle","_uniforms","_max"});
	addExtern< void (*)(bgfx_shader_handle_s,const char *,int) , bgfx_set_shader_name >(*this,lib,"bgfx_set_shader_name",SideEffects::worstDefault,"bgfx_set_shader_name")
		->args({"_handle","_name","_len"});
	addExtern< void (*)(bgfx_shader_handle_s) , bgfx_destroy_shader >(*this,lib,"bgfx_destroy_shader",SideEffects::worstDefault,"bgfx_destroy_shader")
		->args({"_handle"});
	addExtern< bgfx_program_handle_s (*)(bgfx_shader_handle_s,bgfx_shader_handle_s,bool) , bgfx_create_program ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_program",SideEffects::worstDefault,"bgfx_create_program")
		->args({"_vsh","_fsh","_destroyShaders"});
	addExtern< bgfx_program_handle_s (*)(bgfx_shader_handle_s,bool) , bgfx_create_compute_program ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_compute_program",SideEffects::worstDefault,"bgfx_create_compute_program")
		->args({"_csh","_destroyShaders"});
}
}

