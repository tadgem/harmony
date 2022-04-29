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
void Module_dasBGFX::initFunctions_10() {
	addExtern< void (*)(unsigned char,bgfx_vertex_buffer_handle_s,bgfx_access) , bgfx_set_compute_vertex_buffer >(*this,lib,"bgfx_set_compute_vertex_buffer",SideEffects::worstDefault,"bgfx_set_compute_vertex_buffer")
		->args({"_stage","_handle","_access"});
	addExtern< void (*)(unsigned char,bgfx_dynamic_index_buffer_handle_s,bgfx_access) , bgfx_set_compute_dynamic_index_buffer >(*this,lib,"bgfx_set_compute_dynamic_index_buffer",SideEffects::worstDefault,"bgfx_set_compute_dynamic_index_buffer")
		->args({"_stage","_handle","_access"});
	addExtern< void (*)(unsigned char,bgfx_dynamic_vertex_buffer_handle_s,bgfx_access) , bgfx_set_compute_dynamic_vertex_buffer >(*this,lib,"bgfx_set_compute_dynamic_vertex_buffer",SideEffects::worstDefault,"bgfx_set_compute_dynamic_vertex_buffer")
		->args({"_stage","_handle","_access"});
	addExtern< void (*)(unsigned char,bgfx_indirect_buffer_handle_s,bgfx_access) , bgfx_set_compute_indirect_buffer >(*this,lib,"bgfx_set_compute_indirect_buffer",SideEffects::worstDefault,"bgfx_set_compute_indirect_buffer")
		->args({"_stage","_handle","_access"});
	addExtern< void (*)(unsigned char,bgfx_texture_handle_s,unsigned char,bgfx_access,bgfx_texture_format) , bgfx_set_image >(*this,lib,"bgfx_set_image",SideEffects::worstDefault,"bgfx_set_image")
		->args({"_stage","_handle","_mip","_access","_format"});
	addExtern< void (*)(unsigned short,bgfx_program_handle_s,unsigned int,unsigned int,unsigned int,unsigned char) , bgfx_dispatch >(*this,lib,"bgfx_dispatch",SideEffects::worstDefault,"bgfx_dispatch")
		->args({"_id","_program","_numX","_numY","_numZ","_flags"});
	addExtern< void (*)(unsigned short,bgfx_program_handle_s,bgfx_indirect_buffer_handle_s,unsigned short,unsigned short,unsigned char) , bgfx_dispatch_indirect >(*this,lib,"bgfx_dispatch_indirect",SideEffects::worstDefault,"bgfx_dispatch_indirect")
		->args({"_id","_program","_indirectHandle","_start","_num","_flags"});
	addExtern< void (*)(unsigned char) , bgfx_discard >(*this,lib,"bgfx_discard",SideEffects::worstDefault,"bgfx_discard")
		->args({"_flags"});
	addExtern< void (*)(unsigned short,bgfx_texture_handle_s,unsigned char,unsigned short,unsigned short,unsigned short,bgfx_texture_handle_s,unsigned char,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short,unsigned short) , bgfx_blit >(*this,lib,"bgfx_blit",SideEffects::worstDefault,"bgfx_blit")
		->args({"_id","_dst","_dstMip","_dstX","_dstY","_dstZ","_src","_srcMip","_srcX","_srcY","_srcZ","_width","_height","_depth"});
}
}

