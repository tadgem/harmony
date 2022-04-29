// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasIMGUI.h"
#include "need_dasIMGUI.h"
namespace das {
#include "dasIMGUI.func.aot.decl.inc"
void Module_dasIMGUI::initFunctions_26() {
	using _method_146 = das::das_call_member< void (ImFontAtlas::*)(const ImFontAtlasCustomRect *,ImVec2 *,ImVec2 *) const,&ImFontAtlas::CalcCustomRectUV >;
	addExtern<DAS_CALL_METHOD(_method_146)>(*this,lib,"CalcCustomRectUV",SideEffects::worstDefault,"das_call_member< void (ImFontAtlas::*)(const ImFontAtlasCustomRect *,ImVec2 *,ImVec2 *) const , &ImFontAtlas::CalcCustomRectUV >::invoke")
		->args({"self","rect","out_uv_min","out_uv_max"});
	using _method_147 = das::das_call_member< bool (ImFontAtlas::*)(int,ImVec2 *,ImVec2 *,ImVec2 [2],ImVec2 [2]),&ImFontAtlas::GetMouseCursorTexData >;
	addExtern<DAS_CALL_METHOD(_method_147)>(*this,lib,"GetMouseCursorTexData",SideEffects::worstDefault,"das_call_member< bool (ImFontAtlas::*)(int,ImVec2 *,ImVec2 *,ImVec2 [2],ImVec2 [2]) , &ImFontAtlas::GetMouseCursorTexData >::invoke")
		->args({"self","cursor","out_offset","out_size","out_uv_border","out_uv_fill"})
		->arg_type(1,makeType<ImGuiMouseCursor_>(lib));
	addCtorAndUsing<ImFont>(*this,lib,"ImFont","ImFont");
	using _method_148 = das::das_call_member< const ImFontGlyph * (ImFont::*)(unsigned short) const,&ImFont::FindGlyph >;
	addExtern<DAS_CALL_METHOD(_method_148)>(*this,lib,"FindGlyph",SideEffects::worstDefault,"das_call_member< const ImFontGlyph * (ImFont::*)(unsigned short) const , &ImFont::FindGlyph >::invoke")
		->args({"self","c"});
	using _method_149 = das::das_call_member< const ImFontGlyph * (ImFont::*)(unsigned short) const,&ImFont::FindGlyphNoFallback >;
	addExtern<DAS_CALL_METHOD(_method_149)>(*this,lib,"FindGlyphNoFallback",SideEffects::worstDefault,"das_call_member< const ImFontGlyph * (ImFont::*)(unsigned short) const , &ImFont::FindGlyphNoFallback >::invoke")
		->args({"self","c"});
	using _method_150 = das::das_call_member< float (ImFont::*)(unsigned short) const,&ImFont::GetCharAdvance >;
	addExtern<DAS_CALL_METHOD(_method_150)>(*this,lib,"GetCharAdvance",SideEffects::worstDefault,"das_call_member< float (ImFont::*)(unsigned short) const , &ImFont::GetCharAdvance >::invoke")
		->args({"self","c"});
	using _method_151 = das::das_call_member< bool (ImFont::*)() const,&ImFont::IsLoaded >;
	addExtern<DAS_CALL_METHOD(_method_151)>(*this,lib,"IsLoaded",SideEffects::worstDefault,"das_call_member< bool (ImFont::*)() const , &ImFont::IsLoaded >::invoke")
		->args({"self"});
	using _method_152 = das::das_call_member< const char * (ImFont::*)() const,&ImFont::GetDebugName >;
	addExtern<DAS_CALL_METHOD(_method_152)>(*this,lib,"GetDebugName",SideEffects::worstDefault,"das_call_member< const char * (ImFont::*)() const , &ImFont::GetDebugName >::invoke")
		->args({"self"});
	using _method_153 = das::das_call_member< ImVec2 (ImFont::*)(float,float,float,const char *,const char *,const char **) const,&ImFont::CalcTextSizeA >;
	addExtern<DAS_CALL_METHOD(_method_153)>(*this,lib,"CalcTextSizeA",SideEffects::worstDefault,"das_call_member< ImVec2 (ImFont::*)(float,float,float,const char *,const char *,const char **) const , &ImFont::CalcTextSizeA >::invoke")
		->args({"self","size","max_width","wrap_width","text_begin","text_end","remaining"})
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_init(6,make_smart<ExprConstPtr>());
	using _method_154 = das::das_call_member< const char * (ImFont::*)(float,const char *,const char *,float) const,&ImFont::CalcWordWrapPositionA >;
	addExtern<DAS_CALL_METHOD(_method_154)>(*this,lib,"CalcWordWrapPositionA",SideEffects::worstDefault,"das_call_member< const char * (ImFont::*)(float,const char *,const char *,float) const , &ImFont::CalcWordWrapPositionA >::invoke")
		->args({"self","scale","text","text_end","wrap_width"});
	using _method_155 = das::das_call_member< void (ImFont::*)(ImDrawList *,float,ImVec2,unsigned int,unsigned short) const,&ImFont::RenderChar >;
	addExtern<DAS_CALL_METHOD(_method_155)>(*this,lib,"RenderChar",SideEffects::worstDefault,"das_call_member< void (ImFont::*)(ImDrawList *,float,ImVec2,unsigned int,unsigned short) const , &ImFont::RenderChar >::invoke")
		->args({"self","draw_list","size","pos","col","c"});
	using _method_156 = das::das_call_member< void (ImFont::*)(ImDrawList *,float,ImVec2,unsigned int,const ImVec4 &,const char *,const char *,float,bool) const,&ImFont::RenderText >;
	addExtern<DAS_CALL_METHOD(_method_156)>(*this,lib,"RenderText",SideEffects::worstDefault,"das_call_member< void (ImFont::*)(ImDrawList *,float,ImVec2,unsigned int,const ImVec4 &,const char *,const char *,float,bool) const , &ImFont::RenderText >::invoke")
		->args({"self","draw_list","size","pos","col","clip_rect","text_begin","text_end","wrap_width","cpu_fine_clip"})
		->arg_init(8,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(9,make_smart<ExprConstBool>(false));
	using _method_157 = das::das_call_member< void (ImFont::*)(),&ImFont::BuildLookupTable >;
	addExtern<DAS_CALL_METHOD(_method_157)>(*this,lib,"BuildLookupTable",SideEffects::worstDefault,"das_call_member< void (ImFont::*)() , &ImFont::BuildLookupTable >::invoke")
		->args({"self"});
	using _method_158 = das::das_call_member< void (ImFont::*)(),&ImFont::ClearOutputData >;
	addExtern<DAS_CALL_METHOD(_method_158)>(*this,lib,"ClearOutputData",SideEffects::worstDefault,"das_call_member< void (ImFont::*)() , &ImFont::ClearOutputData >::invoke")
		->args({"self"});
	using _method_159 = das::das_call_member< void (ImFont::*)(int),&ImFont::GrowIndex >;
	addExtern<DAS_CALL_METHOD(_method_159)>(*this,lib,"GrowIndex",SideEffects::worstDefault,"das_call_member< void (ImFont::*)(int) , &ImFont::GrowIndex >::invoke")
		->args({"self","new_size"});
	using _method_160 = das::das_call_member< void (ImFont::*)(const ImFontConfig *,unsigned short,float,float,float,float,float,float,float,float,float),&ImFont::AddGlyph >;
	addExtern<DAS_CALL_METHOD(_method_160)>(*this,lib,"AddGlyph",SideEffects::worstDefault,"das_call_member< void (ImFont::*)(const ImFontConfig *,unsigned short,float,float,float,float,float,float,float,float,float) , &ImFont::AddGlyph >::invoke")
		->args({"self","src_cfg","c","x0","y0","x1","y1","u0","v0","u1","v1","advance_x"});
	using _method_161 = das::das_call_member< void (ImFont::*)(unsigned short,unsigned short,bool),&ImFont::AddRemapChar >;
	addExtern<DAS_CALL_METHOD(_method_161)>(*this,lib,"AddRemapChar",SideEffects::worstDefault,"das_call_member< void (ImFont::*)(unsigned short,unsigned short,bool) , &ImFont::AddRemapChar >::invoke")
		->args({"self","dst","src","overwrite_dst"})
		->arg_init(3,make_smart<ExprConstBool>(true));
	using _method_162 = das::das_call_member< void (ImFont::*)(unsigned short,bool),&ImFont::SetGlyphVisible >;
	addExtern<DAS_CALL_METHOD(_method_162)>(*this,lib,"SetGlyphVisible",SideEffects::worstDefault,"das_call_member< void (ImFont::*)(unsigned short,bool) , &ImFont::SetGlyphVisible >::invoke")
		->args({"self","c","visible"});
	using _method_163 = das::das_call_member< void (ImFont::*)(unsigned short),&ImFont::SetFallbackChar >;
	addExtern<DAS_CALL_METHOD(_method_163)>(*this,lib,"SetFallbackChar",SideEffects::worstDefault,"das_call_member< void (ImFont::*)(unsigned short) , &ImFont::SetFallbackChar >::invoke")
		->args({"self","c"});
	using _method_164 = das::das_call_member< bool (ImFont::*)(unsigned int,unsigned int),&ImFont::IsGlyphRangeUnused >;
	addExtern<DAS_CALL_METHOD(_method_164)>(*this,lib,"IsGlyphRangeUnused",SideEffects::worstDefault,"das_call_member< bool (ImFont::*)(unsigned int,unsigned int) , &ImFont::IsGlyphRangeUnused >::invoke")
		->args({"self","c_begin","c_last"});
}
}

