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
void Module_dasBGFX::initFunctions_1() {
	addExtern< void (*)(bgfx_attachment_s *,bgfx_texture_handle_s,bgfx_access,unsigned short,unsigned short,unsigned short,unsigned char) , bgfx_attachment_init >(*this,lib,"bgfx_attachment_init",SideEffects::worstDefault,"bgfx_attachment_init")
		->args({"_this","_handle","_access","_layer","_numLayers","_mip","_resolve"});
	addExtern< bgfx_vertex_layout_s * (*)(bgfx_vertex_layout_s *,bgfx_renderer_type) , bgfx_vertex_layout_begin >(*this,lib,"bgfx_vertex_layout_begin",SideEffects::worstDefault,"bgfx_vertex_layout_begin")
		->args({"_this","_rendererType"});
	addExtern< bgfx_vertex_layout_s * (*)(bgfx_vertex_layout_s *,bgfx_attrib,unsigned char,bgfx_attrib_type,bool,bool) , bgfx_vertex_layout_add >(*this,lib,"bgfx_vertex_layout_add",SideEffects::worstDefault,"bgfx_vertex_layout_add")
		->args({"_this","_attrib","_num","_type","_normalized","_asInt"});
	addExtern< void (*)(const bgfx_vertex_layout_s *,bgfx_attrib,unsigned char *,bgfx_attrib_type *,bool *,bool *) , bgfx_vertex_layout_decode >(*this,lib,"bgfx_vertex_layout_decode",SideEffects::worstDefault,"bgfx_vertex_layout_decode")
		->args({"_this","_attrib","_num","_type","_normalized","_asInt"});
	addExtern< bool (*)(const bgfx_vertex_layout_s *,bgfx_attrib) , bgfx_vertex_layout_has >(*this,lib,"bgfx_vertex_layout_has",SideEffects::worstDefault,"bgfx_vertex_layout_has")
		->args({"_this","_attrib"});
	addExtern< bgfx_vertex_layout_s * (*)(bgfx_vertex_layout_s *,unsigned char) , bgfx_vertex_layout_skip >(*this,lib,"bgfx_vertex_layout_skip",SideEffects::worstDefault,"bgfx_vertex_layout_skip")
		->args({"_this","_num"});
	addExtern< void (*)(bgfx_vertex_layout_s *) , bgfx_vertex_layout_end >(*this,lib,"bgfx_vertex_layout_end",SideEffects::worstDefault,"bgfx_vertex_layout_end")
		->args({"_this"});
	addExtern< void (*)(float const[4],bool,bgfx_attrib,const bgfx_vertex_layout_s *,void *,unsigned int) , bgfx_vertex_pack >(*this,lib,"bgfx_vertex_pack",SideEffects::worstDefault,"bgfx_vertex_pack")
		->args({"_input","_inputNormalized","_attr","_layout","_data","_index"});
	addExtern< void (*)(float [4],bgfx_attrib,const bgfx_vertex_layout_s *,const void *,unsigned int) , bgfx_vertex_unpack >(*this,lib,"bgfx_vertex_unpack",SideEffects::worstDefault,"bgfx_vertex_unpack")
		->args({"_output","_attr","_layout","_data","_index"});
	addExtern< void (*)(const bgfx_vertex_layout_s *,void *,const bgfx_vertex_layout_s *,const void *,unsigned int) , bgfx_vertex_convert >(*this,lib,"bgfx_vertex_convert",SideEffects::worstDefault,"bgfx_vertex_convert")
		->args({"_dstLayout","_dstData","_srcLayout","_srcData","_num"});
	addExtern< unsigned int (*)(void *,const bgfx_vertex_layout_s *,const void *,unsigned int,bool,float) , bgfx_weld_vertices >(*this,lib,"bgfx_weld_vertices",SideEffects::worstDefault,"bgfx_weld_vertices")
		->args({"_output","_layout","_data","_num","_index32","_epsilon"});
	addExtern< unsigned int (*)(bgfx_topology_convert_t,void *,unsigned int,const void *,unsigned int,bool) , bgfx_topology_convert >(*this,lib,"bgfx_topology_convert",SideEffects::worstDefault,"bgfx_topology_convert")
		->args({"_conversion","_dst","_dstSize","_indices","_numIndices","_index32"});
	addExtern< void (*)(bgfx_topology_sort,void *,unsigned int,float const[3],float const[3],const void *,unsigned int,const void *,unsigned int,bool) , bgfx_topology_sort_tri_list >(*this,lib,"bgfx_topology_sort_tri_list",SideEffects::worstDefault,"bgfx_topology_sort_tri_list")
		->args({"_sort","_dst","_dstSize","_dir","_pos","_vertices","_stride","_indices","_numIndices","_index32"});
	addExtern< unsigned char (*)(unsigned char,bgfx_renderer_type *) , bgfx_get_supported_renderers >(*this,lib,"bgfx_get_supported_renderers",SideEffects::worstDefault,"bgfx_get_supported_renderers")
		->args({"_max","_enum"});
	addExtern< const char * (*)(bgfx_renderer_type) , bgfx_get_renderer_name >(*this,lib,"bgfx_get_renderer_name",SideEffects::worstDefault,"bgfx_get_renderer_name")
		->args({"_type"});
	addExtern< void (*)(bgfx_init_s *) , bgfx_init_ctor >(*this,lib,"bgfx_init_ctor",SideEffects::worstDefault,"bgfx_init_ctor")
		->args({"_init"});
	addExtern< bool (*)(const bgfx_init_s *) , bgfx_init >(*this,lib,"bgfx_init",SideEffects::worstDefault,"bgfx_init")
		->args({"_init"});
	addExtern< void (*)() , bgfx_shutdown >(*this,lib,"bgfx_shutdown",SideEffects::worstDefault,"bgfx_shutdown");
	addExtern< void (*)(unsigned int,unsigned int,unsigned int,bgfx_texture_format) , bgfx_reset >(*this,lib,"bgfx_reset",SideEffects::worstDefault,"bgfx_reset")
		->args({"_width","_height","_flags","_format"});
	addExtern< unsigned int (*)(bool) , bgfx_frame >(*this,lib,"bgfx_frame",SideEffects::worstDefault,"bgfx_frame")
		->args({"_capture"});
}
}

