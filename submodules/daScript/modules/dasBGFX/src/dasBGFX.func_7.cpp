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
void Module_dasBGFX::initFunctions_7() {
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_dynamic_vertex_buffer_handle_s,unsigned int,unsigned int) , bgfx_encoder_set_dynamic_vertex_buffer >(*this,lib,"bgfx_encoder_set_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_encoder_set_dynamic_vertex_buffer")
		->args({"_this","_stream","_handle","_startVertex","_numVertices"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_dynamic_vertex_buffer_handle_s,unsigned int,unsigned int,bgfx_vertex_layout_handle_s) , bgfx_encoder_set_dynamic_vertex_buffer_with_layout >(*this,lib,"bgfx_encoder_set_dynamic_vertex_buffer_with_layout",SideEffects::worstDefault,"bgfx_encoder_set_dynamic_vertex_buffer_with_layout")
		->args({"_this","_stream","_handle","_startVertex","_numVertices","_layoutHandle"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,const bgfx_transient_vertex_buffer_s *,unsigned int,unsigned int) , bgfx_encoder_set_transient_vertex_buffer >(*this,lib,"bgfx_encoder_set_transient_vertex_buffer",SideEffects::worstDefault,"bgfx_encoder_set_transient_vertex_buffer")
		->args({"_this","_stream","_tvb","_startVertex","_numVertices"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,const bgfx_transient_vertex_buffer_s *,unsigned int,unsigned int,bgfx_vertex_layout_handle_s) , bgfx_encoder_set_transient_vertex_buffer_with_layout >(*this,lib,"bgfx_encoder_set_transient_vertex_buffer_with_layout",SideEffects::worstDefault,"bgfx_encoder_set_transient_vertex_buffer_with_layout")
		->args({"_this","_stream","_tvb","_startVertex","_numVertices","_layoutHandle"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned int) , bgfx_encoder_set_vertex_count >(*this,lib,"bgfx_encoder_set_vertex_count",SideEffects::worstDefault,"bgfx_encoder_set_vertex_count")
		->args({"_this","_numVertices"});
	addExtern< void (*)(bgfx_encoder_s *,const bgfx_instance_data_buffer_s *,unsigned int,unsigned int) , bgfx_encoder_set_instance_data_buffer >(*this,lib,"bgfx_encoder_set_instance_data_buffer",SideEffects::worstDefault,"bgfx_encoder_set_instance_data_buffer")
		->args({"_this","_idb","_start","_num"});
	addExtern< void (*)(bgfx_encoder_s *,bgfx_vertex_buffer_handle_s,unsigned int,unsigned int) , bgfx_encoder_set_instance_data_from_vertex_buffer >(*this,lib,"bgfx_encoder_set_instance_data_from_vertex_buffer",SideEffects::worstDefault,"bgfx_encoder_set_instance_data_from_vertex_buffer")
		->args({"_this","_handle","_startVertex","_num"});
	addExtern< void (*)(bgfx_encoder_s *,bgfx_dynamic_vertex_buffer_handle_s,unsigned int,unsigned int) , bgfx_encoder_set_instance_data_from_dynamic_vertex_buffer >(*this,lib,"bgfx_encoder_set_instance_data_from_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_encoder_set_instance_data_from_dynamic_vertex_buffer")
		->args({"_this","_handle","_startVertex","_num"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned int) , bgfx_encoder_set_instance_count >(*this,lib,"bgfx_encoder_set_instance_count",SideEffects::worstDefault,"bgfx_encoder_set_instance_count")
		->args({"_this","_numInstances"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_uniform_handle_s,bgfx_texture_handle_s,unsigned int) , bgfx_encoder_set_texture >(*this,lib,"bgfx_encoder_set_texture",SideEffects::worstDefault,"bgfx_encoder_set_texture")
		->args({"_this","_stage","_sampler","_handle","_flags"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned short) , bgfx_encoder_touch >(*this,lib,"bgfx_encoder_touch",SideEffects::worstDefault,"bgfx_encoder_touch")
		->args({"_this","_id"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned short,bgfx_program_handle_s,unsigned int,unsigned char) , bgfx_encoder_submit >(*this,lib,"bgfx_encoder_submit",SideEffects::worstDefault,"bgfx_encoder_submit")
		->args({"_this","_id","_program","_depth","_flags"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned short,bgfx_program_handle_s,bgfx_occlusion_query_handle_s,unsigned int,unsigned char) , bgfx_encoder_submit_occlusion_query >(*this,lib,"bgfx_encoder_submit_occlusion_query",SideEffects::worstDefault,"bgfx_encoder_submit_occlusion_query")
		->args({"_this","_id","_program","_occlusionQuery","_depth","_flags"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned short,bgfx_program_handle_s,bgfx_indirect_buffer_handle_s,unsigned short,unsigned short,unsigned int,unsigned char) , bgfx_encoder_submit_indirect >(*this,lib,"bgfx_encoder_submit_indirect",SideEffects::worstDefault,"bgfx_encoder_submit_indirect")
		->args({"_this","_id","_program","_indirectHandle","_start","_num","_depth","_flags"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_index_buffer_handle_s,bgfx_access) , bgfx_encoder_set_compute_index_buffer >(*this,lib,"bgfx_encoder_set_compute_index_buffer",SideEffects::worstDefault,"bgfx_encoder_set_compute_index_buffer")
		->args({"_this","_stage","_handle","_access"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_vertex_buffer_handle_s,bgfx_access) , bgfx_encoder_set_compute_vertex_buffer >(*this,lib,"bgfx_encoder_set_compute_vertex_buffer",SideEffects::worstDefault,"bgfx_encoder_set_compute_vertex_buffer")
		->args({"_this","_stage","_handle","_access"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_dynamic_index_buffer_handle_s,bgfx_access) , bgfx_encoder_set_compute_dynamic_index_buffer >(*this,lib,"bgfx_encoder_set_compute_dynamic_index_buffer",SideEffects::worstDefault,"bgfx_encoder_set_compute_dynamic_index_buffer")
		->args({"_this","_stage","_handle","_access"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_dynamic_vertex_buffer_handle_s,bgfx_access) , bgfx_encoder_set_compute_dynamic_vertex_buffer >(*this,lib,"bgfx_encoder_set_compute_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_encoder_set_compute_dynamic_vertex_buffer")
		->args({"_this","_stage","_handle","_access"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_indirect_buffer_handle_s,bgfx_access) , bgfx_encoder_set_compute_indirect_buffer >(*this,lib,"bgfx_encoder_set_compute_indirect_buffer",SideEffects::worstDefault,"bgfx_encoder_set_compute_indirect_buffer")
		->args({"_this","_stage","_handle","_access"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_texture_handle_s,unsigned char,bgfx_access,bgfx_texture_format) , bgfx_encoder_set_image >(*this,lib,"bgfx_encoder_set_image",SideEffects::worstDefault,"bgfx_encoder_set_image")
		->args({"_this","_stage","_handle","_mip","_access","_format"});
}
}

