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
void Module_dasBGFX::initFunctions_4() {
	addExtern< void (*)(bgfx_program_handle_s) , bgfx_destroy_program >(*this,lib,"bgfx_destroy_program",SideEffects::worstDefault,"bgfx_destroy_program")
		->args({"_handle"});
	addExtern< bool (*)(unsigned short,bool,unsigned short,bgfx_texture_format,uint64_t) , bgfx_is_texture_valid >(*this,lib,"bgfx_is_texture_valid",SideEffects::worstDefault,"bgfx_is_texture_valid")
		->args({"_depth","_cubeMap","_numLayers","_format","_flags"});
	addExtern< bool (*)(unsigned char,const bgfx_attachment_s *) , bgfx_is_frame_buffer_valid >(*this,lib,"bgfx_is_frame_buffer_valid",SideEffects::worstDefault,"bgfx_is_frame_buffer_valid")
		->args({"_num","_attachment"});
	addExtern< void (*)(bgfx_texture_info_s *,unsigned short,unsigned short,unsigned short,bool,bool,unsigned short,bgfx_texture_format) , bgfx_calc_texture_size >(*this,lib,"bgfx_calc_texture_size",SideEffects::worstDefault,"bgfx_calc_texture_size")
		->args({"_info","_width","_height","_depth","_cubeMap","_hasMips","_numLayers","_format"});
	addExtern< bgfx_texture_handle_s (*)(const bgfx_memory_s *,uint64_t,unsigned char,bgfx_texture_info_s *) , bgfx_create_texture ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_texture",SideEffects::worstDefault,"bgfx_create_texture")
		->args({"_mem","_flags","_skip","_info"});
	addExtern< bgfx_texture_handle_s (*)(unsigned short,unsigned short,bool,unsigned short,bgfx_texture_format,uint64_t,const bgfx_memory_s *) , bgfx_create_texture_2d ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_texture_2d",SideEffects::worstDefault,"bgfx_create_texture_2d")
		->args({"_width","_height","_hasMips","_numLayers","_format","_flags","_mem"});
	addExtern< bgfx_texture_handle_s (*)(bgfx_backbuffer_ratio,bool,unsigned short,bgfx_texture_format,uint64_t) , bgfx_create_texture_2d_scaled ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_texture_2d_scaled",SideEffects::worstDefault,"bgfx_create_texture_2d_scaled")
		->args({"_ratio","_hasMips","_numLayers","_format","_flags"});
	addExtern< bgfx_texture_handle_s (*)(unsigned short,unsigned short,unsigned short,bool,bgfx_texture_format,uint64_t,const bgfx_memory_s *) , bgfx_create_texture_3d ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_texture_3d",SideEffects::worstDefault,"bgfx_create_texture_3d")
		->args({"_width","_height","_depth","_hasMips","_format","_flags","_mem"});
	addExtern< bgfx_texture_handle_s (*)(unsigned short,bool,unsigned short,bgfx_texture_format,uint64_t,const bgfx_memory_s *) , bgfx_create_texture_cube ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_texture_cube",SideEffects::worstDefault,"bgfx_create_texture_cube")
		->args({"_size","_hasMips","_numLayers","_format","_flags","_mem"});
	addExtern< void (*)(bgfx_texture_handle_s,unsigned short,unsigned char,unsigned short,unsigned short,unsigned short,unsigned short,const bgfx_memory_s *,unsigned short) , bgfx_update_texture_2d >(*this,lib,"bgfx_update_texture_2d",SideEffects::worstDefault,"bgfx_update_texture_2d")
		->args({"_handle","_layer","_mip","_x","_y","_width","_height","_mem","_pitch"});
	addExtern< void (*)(bgfx_texture_handle_s,unsigned char,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,const bgfx_memory_s *) , bgfx_update_texture_3d >(*this,lib,"bgfx_update_texture_3d",SideEffects::worstDefault,"bgfx_update_texture_3d")
		->args({"_handle","_mip","_x","_y","_z","_width","_height","_depth","_mem"});
	addExtern< void (*)(bgfx_texture_handle_s,unsigned short,unsigned char,unsigned char,unsigned short,unsigned short,unsigned short,unsigned short,const bgfx_memory_s *,unsigned short) , bgfx_update_texture_cube >(*this,lib,"bgfx_update_texture_cube",SideEffects::worstDefault,"bgfx_update_texture_cube")
		->args({"_handle","_layer","_side","_mip","_x","_y","_width","_height","_mem","_pitch"});
	addExtern< unsigned int (*)(bgfx_texture_handle_s,void *,unsigned char) , bgfx_read_texture >(*this,lib,"bgfx_read_texture",SideEffects::worstDefault,"bgfx_read_texture")
		->args({"_handle","_data","_mip"});
	addExtern< void (*)(bgfx_texture_handle_s,const char *,int) , bgfx_set_texture_name >(*this,lib,"bgfx_set_texture_name",SideEffects::worstDefault,"bgfx_set_texture_name")
		->args({"_handle","_name","_len"});
	addExtern< void * (*)(bgfx_texture_handle_s) , bgfx_get_direct_access_ptr >(*this,lib,"bgfx_get_direct_access_ptr",SideEffects::worstDefault,"bgfx_get_direct_access_ptr")
		->args({"_handle"});
	addExtern< void (*)(bgfx_texture_handle_s) , bgfx_destroy_texture >(*this,lib,"bgfx_destroy_texture",SideEffects::worstDefault,"bgfx_destroy_texture")
		->args({"_handle"});
	addExtern< bgfx_frame_buffer_handle_s (*)(unsigned short,unsigned short,bgfx_texture_format,uint64_t) , bgfx_create_frame_buffer ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_frame_buffer",SideEffects::worstDefault,"bgfx_create_frame_buffer")
		->args({"_width","_height","_format","_textureFlags"});
	addExtern< bgfx_frame_buffer_handle_s (*)(bgfx_backbuffer_ratio,bgfx_texture_format,uint64_t) , bgfx_create_frame_buffer_scaled ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_frame_buffer_scaled",SideEffects::worstDefault,"bgfx_create_frame_buffer_scaled")
		->args({"_ratio","_format","_textureFlags"});
	addExtern< bgfx_frame_buffer_handle_s (*)(unsigned char,const bgfx_texture_handle_s *,bool) , bgfx_create_frame_buffer_from_handles ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_frame_buffer_from_handles",SideEffects::worstDefault,"bgfx_create_frame_buffer_from_handles")
		->args({"_num","_handles","_destroyTexture"});
	addExtern< bgfx_frame_buffer_handle_s (*)(unsigned char,const bgfx_attachment_s *,bool) , bgfx_create_frame_buffer_from_attachment ,SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"bgfx_create_frame_buffer_from_attachment",SideEffects::worstDefault,"bgfx_create_frame_buffer_from_attachment")
		->args({"_num","_attachment","_destroyTexture"});
}
}

