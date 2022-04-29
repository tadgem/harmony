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
void Module_dasBGFX::initFunctions_9() {
	addExtern< void (*)(bgfx_index_buffer_handle_s,unsigned int,unsigned int) , bgfx_set_index_buffer >(*this,lib,"bgfx_set_index_buffer",SideEffects::worstDefault,"bgfx_set_index_buffer")
		->args({"_handle","_firstIndex","_numIndices"});
	addExtern< void (*)(bgfx_dynamic_index_buffer_handle_s,unsigned int,unsigned int) , bgfx_set_dynamic_index_buffer >(*this,lib,"bgfx_set_dynamic_index_buffer",SideEffects::worstDefault,"bgfx_set_dynamic_index_buffer")
		->args({"_handle","_firstIndex","_numIndices"});
	addExtern< void (*)(const bgfx_transient_index_buffer_s *,unsigned int,unsigned int) , bgfx_set_transient_index_buffer >(*this,lib,"bgfx_set_transient_index_buffer",SideEffects::worstDefault,"bgfx_set_transient_index_buffer")
		->args({"_tib","_firstIndex","_numIndices"});
	addExtern< void (*)(unsigned char,bgfx_vertex_buffer_handle_s,unsigned int,unsigned int) , bgfx_set_vertex_buffer >(*this,lib,"bgfx_set_vertex_buffer",SideEffects::worstDefault,"bgfx_set_vertex_buffer")
		->args({"_stream","_handle","_startVertex","_numVertices"});
	addExtern< void (*)(unsigned char,bgfx_vertex_buffer_handle_s,unsigned int,unsigned int,bgfx_vertex_layout_handle_s) , bgfx_set_vertex_buffer_with_layout >(*this,lib,"bgfx_set_vertex_buffer_with_layout",SideEffects::worstDefault,"bgfx_set_vertex_buffer_with_layout")
		->args({"_stream","_handle","_startVertex","_numVertices","_layoutHandle"});
	addExtern< void (*)(unsigned char,bgfx_dynamic_vertex_buffer_handle_s,unsigned int,unsigned int) , bgfx_set_dynamic_vertex_buffer >(*this,lib,"bgfx_set_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_set_dynamic_vertex_buffer")
		->args({"_stream","_handle","_startVertex","_numVertices"});
	addExtern< void (*)(unsigned char,bgfx_dynamic_vertex_buffer_handle_s,unsigned int,unsigned int,bgfx_vertex_layout_handle_s) , bgfx_set_dynamic_vertex_buffer_with_layout >(*this,lib,"bgfx_set_dynamic_vertex_buffer_with_layout",SideEffects::worstDefault,"bgfx_set_dynamic_vertex_buffer_with_layout")
		->args({"_stream","_handle","_startVertex","_numVertices","_layoutHandle"});
	addExtern< void (*)(unsigned char,const bgfx_transient_vertex_buffer_s *,unsigned int,unsigned int) , bgfx_set_transient_vertex_buffer >(*this,lib,"bgfx_set_transient_vertex_buffer",SideEffects::worstDefault,"bgfx_set_transient_vertex_buffer")
		->args({"_stream","_tvb","_startVertex","_numVertices"});
	addExtern< void (*)(unsigned char,const bgfx_transient_vertex_buffer_s *,unsigned int,unsigned int,bgfx_vertex_layout_handle_s) , bgfx_set_transient_vertex_buffer_with_layout >(*this,lib,"bgfx_set_transient_vertex_buffer_with_layout",SideEffects::worstDefault,"bgfx_set_transient_vertex_buffer_with_layout")
		->args({"_stream","_tvb","_startVertex","_numVertices","_layoutHandle"});
	addExtern< void (*)(unsigned int) , bgfx_set_vertex_count >(*this,lib,"bgfx_set_vertex_count",SideEffects::worstDefault,"bgfx_set_vertex_count")
		->args({"_numVertices"});
	addExtern< void (*)(const bgfx_instance_data_buffer_s *,unsigned int,unsigned int) , bgfx_set_instance_data_buffer >(*this,lib,"bgfx_set_instance_data_buffer",SideEffects::worstDefault,"bgfx_set_instance_data_buffer")
		->args({"_idb","_start","_num"});
	addExtern< void (*)(bgfx_vertex_buffer_handle_s,unsigned int,unsigned int) , bgfx_set_instance_data_from_vertex_buffer >(*this,lib,"bgfx_set_instance_data_from_vertex_buffer",SideEffects::worstDefault,"bgfx_set_instance_data_from_vertex_buffer")
		->args({"_handle","_startVertex","_num"});
	addExtern< void (*)(bgfx_dynamic_vertex_buffer_handle_s,unsigned int,unsigned int) , bgfx_set_instance_data_from_dynamic_vertex_buffer >(*this,lib,"bgfx_set_instance_data_from_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_set_instance_data_from_dynamic_vertex_buffer")
		->args({"_handle","_startVertex","_num"});
	addExtern< void (*)(unsigned int) , bgfx_set_instance_count >(*this,lib,"bgfx_set_instance_count",SideEffects::worstDefault,"bgfx_set_instance_count")
		->args({"_numInstances"});
	addExtern< void (*)(unsigned char,bgfx_uniform_handle_s,bgfx_texture_handle_s,unsigned int) , bgfx_set_texture >(*this,lib,"bgfx_set_texture",SideEffects::worstDefault,"bgfx_set_texture")
		->args({"_stage","_sampler","_handle","_flags"});
	addExtern< void (*)(unsigned short) , bgfx_touch >(*this,lib,"bgfx_touch",SideEffects::worstDefault,"bgfx_touch")
		->args({"_id"});
	addExtern< void (*)(unsigned short,bgfx_program_handle_s,unsigned int,unsigned char) , bgfx_submit >(*this,lib,"bgfx_submit",SideEffects::worstDefault,"bgfx_submit")
		->args({"_id","_program","_depth","_flags"});
	addExtern< void (*)(unsigned short,bgfx_program_handle_s,bgfx_occlusion_query_handle_s,unsigned int,unsigned char) , bgfx_submit_occlusion_query >(*this,lib,"bgfx_submit_occlusion_query",SideEffects::worstDefault,"bgfx_submit_occlusion_query")
		->args({"_id","_program","_occlusionQuery","_depth","_flags"});
	addExtern< void (*)(unsigned short,bgfx_program_handle_s,bgfx_indirect_buffer_handle_s,unsigned short,unsigned short,unsigned int,unsigned char) , bgfx_submit_indirect >(*this,lib,"bgfx_submit_indirect",SideEffects::worstDefault,"bgfx_submit_indirect")
		->args({"_id","_program","_indirectHandle","_start","_num","_depth","_flags"});
	addExtern< void (*)(unsigned char,bgfx_index_buffer_handle_s,bgfx_access) , bgfx_set_compute_index_buffer >(*this,lib,"bgfx_set_compute_index_buffer",SideEffects::worstDefault,"bgfx_set_compute_index_buffer")
		->args({"_stage","_handle","_access"});
}
}

