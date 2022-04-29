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
void Module_dasBGFX::initFunctions_6() {
	addExtern< void (*)(unsigned short,const void *,const void *) , bgfx_set_view_transform >(*this,lib,"bgfx_set_view_transform",SideEffects::worstDefault,"bgfx_set_view_transform")
		->args({"_id","_view","_proj"});
	addExtern< void (*)(unsigned short,unsigned short,const unsigned short *) , bgfx_set_view_order >(*this,lib,"bgfx_set_view_order",SideEffects::worstDefault,"bgfx_set_view_order")
		->args({"_id","_num","_order"});
	addExtern< void (*)(unsigned short) , bgfx_reset_view >(*this,lib,"bgfx_reset_view",SideEffects::worstDefault,"bgfx_reset_view")
		->args({"_id"});
	addExtern< bgfx_encoder_s * (*)(bool) , bgfx_encoder_begin >(*this,lib,"bgfx_encoder_begin",SideEffects::worstDefault,"bgfx_encoder_begin")
		->args({"_forThread"});
	addExtern< void (*)(bgfx_encoder_s *) , bgfx_encoder_end >(*this,lib,"bgfx_encoder_end",SideEffects::worstDefault,"bgfx_encoder_end")
		->args({"_encoder"});
	addExtern< void (*)(bgfx_encoder_s *,const char *) , bgfx_encoder_set_marker >(*this,lib,"bgfx_encoder_set_marker",SideEffects::worstDefault,"bgfx_encoder_set_marker")
		->args({"_this","_marker"});
	addExtern< void (*)(bgfx_encoder_s *,uint64_t,unsigned int) , bgfx_encoder_set_state >(*this,lib,"bgfx_encoder_set_state",SideEffects::worstDefault,"bgfx_encoder_set_state")
		->args({"_this","_state","_rgba"});
	addExtern< void (*)(bgfx_encoder_s *,bgfx_occlusion_query_handle_s,bool) , bgfx_encoder_set_condition >(*this,lib,"bgfx_encoder_set_condition",SideEffects::worstDefault,"bgfx_encoder_set_condition")
		->args({"_this","_handle","_visible"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned int,unsigned int) , bgfx_encoder_set_stencil >(*this,lib,"bgfx_encoder_set_stencil",SideEffects::worstDefault,"bgfx_encoder_set_stencil")
		->args({"_this","_fstencil","_bstencil"});
	addExtern< unsigned short (*)(bgfx_encoder_s *,unsigned short,unsigned short,unsigned short,unsigned short) , bgfx_encoder_set_scissor >(*this,lib,"bgfx_encoder_set_scissor",SideEffects::worstDefault,"bgfx_encoder_set_scissor")
		->args({"_this","_x","_y","_width","_height"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned short) , bgfx_encoder_set_scissor_cached >(*this,lib,"bgfx_encoder_set_scissor_cached",SideEffects::worstDefault,"bgfx_encoder_set_scissor_cached")
		->args({"_this","_cache"});
	addExtern< unsigned int (*)(bgfx_encoder_s *,const void *,unsigned short) , bgfx_encoder_set_transform >(*this,lib,"bgfx_encoder_set_transform",SideEffects::worstDefault,"bgfx_encoder_set_transform")
		->args({"_this","_mtx","_num"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned int,unsigned short) , bgfx_encoder_set_transform_cached >(*this,lib,"bgfx_encoder_set_transform_cached",SideEffects::worstDefault,"bgfx_encoder_set_transform_cached")
		->args({"_this","_cache","_num"});
	addExtern< unsigned int (*)(bgfx_encoder_s *,bgfx_transform_s *,unsigned short) , bgfx_encoder_alloc_transform >(*this,lib,"bgfx_encoder_alloc_transform",SideEffects::worstDefault,"bgfx_encoder_alloc_transform")
		->args({"_this","_transform","_num"});
	addExtern< void (*)(bgfx_encoder_s *,bgfx_uniform_handle_s,const void *,unsigned short) , bgfx_encoder_set_uniform >(*this,lib,"bgfx_encoder_set_uniform",SideEffects::worstDefault,"bgfx_encoder_set_uniform")
		->args({"_this","_handle","_value","_num"});
	addExtern< void (*)(bgfx_encoder_s *,bgfx_index_buffer_handle_s,unsigned int,unsigned int) , bgfx_encoder_set_index_buffer >(*this,lib,"bgfx_encoder_set_index_buffer",SideEffects::worstDefault,"bgfx_encoder_set_index_buffer")
		->args({"_this","_handle","_firstIndex","_numIndices"});
	addExtern< void (*)(bgfx_encoder_s *,bgfx_dynamic_index_buffer_handle_s,unsigned int,unsigned int) , bgfx_encoder_set_dynamic_index_buffer >(*this,lib,"bgfx_encoder_set_dynamic_index_buffer",SideEffects::worstDefault,"bgfx_encoder_set_dynamic_index_buffer")
		->args({"_this","_handle","_firstIndex","_numIndices"});
	addExtern< void (*)(bgfx_encoder_s *,const bgfx_transient_index_buffer_s *,unsigned int,unsigned int) , bgfx_encoder_set_transient_index_buffer >(*this,lib,"bgfx_encoder_set_transient_index_buffer",SideEffects::worstDefault,"bgfx_encoder_set_transient_index_buffer")
		->args({"_this","_tib","_firstIndex","_numIndices"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_vertex_buffer_handle_s,unsigned int,unsigned int) , bgfx_encoder_set_vertex_buffer >(*this,lib,"bgfx_encoder_set_vertex_buffer",SideEffects::worstDefault,"bgfx_encoder_set_vertex_buffer")
		->args({"_this","_stream","_handle","_startVertex","_numVertices"});
	addExtern< void (*)(bgfx_encoder_s *,unsigned char,bgfx_vertex_buffer_handle_s,unsigned int,unsigned int,bgfx_vertex_layout_handle_s) , bgfx_encoder_set_vertex_buffer_with_layout >(*this,lib,"bgfx_encoder_set_vertex_buffer_with_layout",SideEffects::worstDefault,"bgfx_encoder_set_vertex_buffer_with_layout")
		->args({"_this","_stream","_handle","_startVertex","_numVertices","_layoutHandle"});
}
}

