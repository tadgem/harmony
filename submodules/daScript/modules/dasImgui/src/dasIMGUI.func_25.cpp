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
void Module_dasIMGUI::initFunctions_25() {
	using _method_126 = das::das_call_member< void (ImFontAtlas::*)(),&ImFontAtlas::ClearInputData >;
	addExtern<DAS_CALL_METHOD(_method_126)>(*this,lib,"ClearInputData",SideEffects::worstDefault,"das_call_member< void (ImFontAtlas::*)() , &ImFontAtlas::ClearInputData >::invoke")
		->args({"self"});
	using _method_127 = das::das_call_member< void (ImFontAtlas::*)(),&ImFontAtlas::ClearTexData >;
	addExtern<DAS_CALL_METHOD(_method_127)>(*this,lib,"ClearTexData",SideEffects::worstDefault,"das_call_member< void (ImFontAtlas::*)() , &ImFontAtlas::ClearTexData >::invoke")
		->args({"self"});
	using _method_128 = das::das_call_member< void (ImFontAtlas::*)(),&ImFontAtlas::ClearFonts >;
	addExtern<DAS_CALL_METHOD(_method_128)>(*this,lib,"ClearFonts",SideEffects::worstDefault,"das_call_member< void (ImFontAtlas::*)() , &ImFontAtlas::ClearFonts >::invoke")
		->args({"self"});
	using _method_129 = das::das_call_member< void (ImFontAtlas::*)(),&ImFontAtlas::Clear >;
	addExtern<DAS_CALL_METHOD(_method_129)>(*this,lib,"Clear",SideEffects::worstDefault,"das_call_member< void (ImFontAtlas::*)() , &ImFontAtlas::Clear >::invoke")
		->args({"self"});
	using _method_130 = das::das_call_member< bool (ImFontAtlas::*)(),&ImFontAtlas::Build >;
	addExtern<DAS_CALL_METHOD(_method_130)>(*this,lib,"Build",SideEffects::worstDefault,"das_call_member< bool (ImFontAtlas::*)() , &ImFontAtlas::Build >::invoke")
		->args({"self"});
	using _method_131 = das::das_call_member< void (ImFontAtlas::*)(unsigned char **,int *,int *,int *),&ImFontAtlas::GetTexDataAsAlpha8 >;
	addExtern<DAS_CALL_METHOD(_method_131)>(*this,lib,"GetTexDataAsAlpha8",SideEffects::worstDefault,"das_call_member< void (ImFontAtlas::*)(unsigned char **,int *,int *,int *) , &ImFontAtlas::GetTexDataAsAlpha8 >::invoke")
		->args({"self","out_pixels","out_width","out_height","out_bytes_per_pixel"})
		->arg_init(4,make_smart<ExprConstPtr>());
	using _method_132 = das::das_call_member< void (ImFontAtlas::*)(unsigned char **,int *,int *,int *),&ImFontAtlas::GetTexDataAsRGBA32 >;
	addExtern<DAS_CALL_METHOD(_method_132)>(*this,lib,"GetTexDataAsRGBA32",SideEffects::worstDefault,"das_call_member< void (ImFontAtlas::*)(unsigned char **,int *,int *,int *) , &ImFontAtlas::GetTexDataAsRGBA32 >::invoke")
		->args({"self","out_pixels","out_width","out_height","out_bytes_per_pixel"})
		->arg_init(4,make_smart<ExprConstPtr>());
	using _method_133 = das::das_call_member< bool (ImFontAtlas::*)() const,&ImFontAtlas::IsBuilt >;
	addExtern<DAS_CALL_METHOD(_method_133)>(*this,lib,"IsBuilt",SideEffects::worstDefault,"das_call_member< bool (ImFontAtlas::*)() const , &ImFontAtlas::IsBuilt >::invoke")
		->args({"self"});
	using _method_134 = das::das_call_member< void (ImFontAtlas::*)(void *),&ImFontAtlas::SetTexID >;
	addExtern<DAS_CALL_METHOD(_method_134)>(*this,lib,"SetTexID",SideEffects::worstDefault,"das_call_member< void (ImFontAtlas::*)(void *) , &ImFontAtlas::SetTexID >::invoke")
		->args({"self","id"});
	using _method_135 = das::das_call_member< const unsigned short * (ImFontAtlas::*)(),&ImFontAtlas::GetGlyphRangesDefault >;
	addExtern<DAS_CALL_METHOD(_method_135)>(*this,lib,"GetGlyphRangesDefault",SideEffects::worstDefault,"das_call_member< const unsigned short * (ImFontAtlas::*)() , &ImFontAtlas::GetGlyphRangesDefault >::invoke")
		->args({"self"});
	using _method_136 = das::das_call_member< const unsigned short * (ImFontAtlas::*)(),&ImFontAtlas::GetGlyphRangesKorean >;
	addExtern<DAS_CALL_METHOD(_method_136)>(*this,lib,"GetGlyphRangesKorean",SideEffects::worstDefault,"das_call_member< const unsigned short * (ImFontAtlas::*)() , &ImFontAtlas::GetGlyphRangesKorean >::invoke")
		->args({"self"});
	using _method_137 = das::das_call_member< const unsigned short * (ImFontAtlas::*)(),&ImFontAtlas::GetGlyphRangesJapanese >;
	addExtern<DAS_CALL_METHOD(_method_137)>(*this,lib,"GetGlyphRangesJapanese",SideEffects::worstDefault,"das_call_member< const unsigned short * (ImFontAtlas::*)() , &ImFontAtlas::GetGlyphRangesJapanese >::invoke")
		->args({"self"});
	using _method_138 = das::das_call_member< const unsigned short * (ImFontAtlas::*)(),&ImFontAtlas::GetGlyphRangesChineseFull >;
	addExtern<DAS_CALL_METHOD(_method_138)>(*this,lib,"GetGlyphRangesChineseFull",SideEffects::worstDefault,"das_call_member< const unsigned short * (ImFontAtlas::*)() , &ImFontAtlas::GetGlyphRangesChineseFull >::invoke")
		->args({"self"});
	using _method_139 = das::das_call_member< const unsigned short * (ImFontAtlas::*)(),&ImFontAtlas::GetGlyphRangesChineseSimplifiedCommon >;
	addExtern<DAS_CALL_METHOD(_method_139)>(*this,lib,"GetGlyphRangesChineseSimplifiedCommon",SideEffects::worstDefault,"das_call_member< const unsigned short * (ImFontAtlas::*)() , &ImFontAtlas::GetGlyphRangesChineseSimplifiedCommon >::invoke")
		->args({"self"});
	using _method_140 = das::das_call_member< const unsigned short * (ImFontAtlas::*)(),&ImFontAtlas::GetGlyphRangesCyrillic >;
	addExtern<DAS_CALL_METHOD(_method_140)>(*this,lib,"GetGlyphRangesCyrillic",SideEffects::worstDefault,"das_call_member< const unsigned short * (ImFontAtlas::*)() , &ImFontAtlas::GetGlyphRangesCyrillic >::invoke")
		->args({"self"});
	using _method_141 = das::das_call_member< const unsigned short * (ImFontAtlas::*)(),&ImFontAtlas::GetGlyphRangesThai >;
	addExtern<DAS_CALL_METHOD(_method_141)>(*this,lib,"GetGlyphRangesThai",SideEffects::worstDefault,"das_call_member< const unsigned short * (ImFontAtlas::*)() , &ImFontAtlas::GetGlyphRangesThai >::invoke")
		->args({"self"});
	using _method_142 = das::das_call_member< const unsigned short * (ImFontAtlas::*)(),&ImFontAtlas::GetGlyphRangesVietnamese >;
	addExtern<DAS_CALL_METHOD(_method_142)>(*this,lib,"GetGlyphRangesVietnamese",SideEffects::worstDefault,"das_call_member< const unsigned short * (ImFontAtlas::*)() , &ImFontAtlas::GetGlyphRangesVietnamese >::invoke")
		->args({"self"});
	using _method_143 = das::das_call_member< int (ImFontAtlas::*)(int,int),&ImFontAtlas::AddCustomRectRegular >;
	addExtern<DAS_CALL_METHOD(_method_143)>(*this,lib,"AddCustomRectRegular",SideEffects::worstDefault,"das_call_member< int (ImFontAtlas::*)(int,int) , &ImFontAtlas::AddCustomRectRegular >::invoke")
		->args({"self","width","height"});
	using _method_144 = das::das_call_member< int (ImFontAtlas::*)(ImFont *,unsigned short,int,int,float,const ImVec2 &),&ImFontAtlas::AddCustomRectFontGlyph >;
	addExtern<DAS_CALL_METHOD(_method_144)>(*this,lib,"AddCustomRectFontGlyph",SideEffects::worstDefault,"das_call_member< int (ImFontAtlas::*)(ImFont *,unsigned short,int,int,float,const ImVec2 &) , &ImFontAtlas::AddCustomRectFontGlyph >::invoke")
		->args({"self","font","id","width","height","advance_x","offset"});
	using _method_145 = das::das_call_member< ImFontAtlasCustomRect * (ImFontAtlas::*)(int),&ImFontAtlas::GetCustomRectByIndex >;
	addExtern<DAS_CALL_METHOD(_method_145)>(*this,lib,"GetCustomRectByIndex",SideEffects::worstDefault,"das_call_member< ImFontAtlasCustomRect * (ImFontAtlas::*)(int) , &ImFontAtlas::GetCustomRectByIndex >::invoke")
		->args({"self","index"});
}
}

