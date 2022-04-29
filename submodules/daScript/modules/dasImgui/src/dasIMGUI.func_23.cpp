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
void Module_dasIMGUI::initFunctions_23() {
	using _method_91 = das::das_call_member< void (ImDrawList::*)(int),&ImDrawList::ChannelsSetCurrent >;
	addExtern<DAS_CALL_METHOD(_method_91)>(*this,lib,"ChannelsSetCurrent",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(int) , &ImDrawList::ChannelsSetCurrent >::invoke")
		->args({"self","n"});
	using _method_92 = das::das_call_member< void (ImDrawList::*)(int,int),&ImDrawList::PrimReserve >;
	addExtern<DAS_CALL_METHOD(_method_92)>(*this,lib,"PrimReserve",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(int,int) , &ImDrawList::PrimReserve >::invoke")
		->args({"self","idx_count","vtx_count"});
	using _method_93 = das::das_call_member< void (ImDrawList::*)(int,int),&ImDrawList::PrimUnreserve >;
	addExtern<DAS_CALL_METHOD(_method_93)>(*this,lib,"PrimUnreserve",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(int,int) , &ImDrawList::PrimUnreserve >::invoke")
		->args({"self","idx_count","vtx_count"});
	using _method_94 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::PrimRect >;
	addExtern<DAS_CALL_METHOD(_method_94)>(*this,lib,"PrimRect",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::PrimRect >::invoke")
		->args({"self","a","b","col"});
	using _method_95 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::PrimRectUV >;
	addExtern<DAS_CALL_METHOD(_method_95)>(*this,lib,"PrimRectUV",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::PrimRectUV >::invoke")
		->args({"self","a","b","uv_a","uv_b","col"});
	using _method_96 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::PrimQuadUV >;
	addExtern<DAS_CALL_METHOD(_method_96)>(*this,lib,"PrimQuadUV",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::PrimQuadUV >::invoke")
		->args({"self","a","b","c","d","uv_a","uv_b","uv_c","uv_d","col"});
	using _method_97 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::PrimWriteVtx >;
	addExtern<DAS_CALL_METHOD(_method_97)>(*this,lib,"PrimWriteVtx",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::PrimWriteVtx >::invoke")
		->args({"self","pos","uv","col"});
	using _method_98 = das::das_call_member< void (ImDrawList::*)(unsigned int),&ImDrawList::PrimWriteIdx >;
	addExtern<DAS_CALL_METHOD(_method_98)>(*this,lib,"PrimWriteIdx",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(unsigned int) , &ImDrawList::PrimWriteIdx >::invoke")
		->args({"self","idx"});
	using _method_99 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::PrimVtx >;
	addExtern<DAS_CALL_METHOD(_method_99)>(*this,lib,"PrimVtx",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::PrimVtx >::invoke")
		->args({"self","pos","uv","col"});
	using _method_100 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::_ResetForNewFrame >;
	addExtern<DAS_CALL_METHOD(_method_100)>(*this,lib,"_ResetForNewFrame",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::_ResetForNewFrame >::invoke")
		->args({"self"});
	using _method_101 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::_ClearFreeMemory >;
	addExtern<DAS_CALL_METHOD(_method_101)>(*this,lib,"_ClearFreeMemory",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::_ClearFreeMemory >::invoke")
		->args({"self"});
	using _method_102 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::_PopUnusedDrawCmd >;
	addExtern<DAS_CALL_METHOD(_method_102)>(*this,lib,"_PopUnusedDrawCmd",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::_PopUnusedDrawCmd >::invoke")
		->args({"self"});
	using _method_103 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::_OnChangedClipRect >;
	addExtern<DAS_CALL_METHOD(_method_103)>(*this,lib,"_OnChangedClipRect",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::_OnChangedClipRect >::invoke")
		->args({"self"});
	using _method_104 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::_OnChangedTextureID >;
	addExtern<DAS_CALL_METHOD(_method_104)>(*this,lib,"_OnChangedTextureID",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::_OnChangedTextureID >::invoke")
		->args({"self"});
	using _method_105 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::_OnChangedVtxOffset >;
	addExtern<DAS_CALL_METHOD(_method_105)>(*this,lib,"_OnChangedVtxOffset",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::_OnChangedVtxOffset >::invoke")
		->args({"self"});
	using _method_106 = das::das_call_member< int (ImDrawList::*)(float) const,&ImDrawList::_CalcCircleAutoSegmentCount >;
	addExtern<DAS_CALL_METHOD(_method_106)>(*this,lib,"_CalcCircleAutoSegmentCount",SideEffects::worstDefault,"das_call_member< int (ImDrawList::*)(float) const , &ImDrawList::_CalcCircleAutoSegmentCount >::invoke")
		->args({"self","radius"});
	using _method_107 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,float,int,int,int),&ImDrawList::_PathArcToFastEx >;
	addExtern<DAS_CALL_METHOD(_method_107)>(*this,lib,"_PathArcToFastEx",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,float,int,int,int) , &ImDrawList::_PathArcToFastEx >::invoke")
		->args({"self","center","radius","a_min_sample","a_max_sample","a_step"});
	using _method_108 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,float,float,float,int),&ImDrawList::_PathArcToN >;
	addExtern<DAS_CALL_METHOD(_method_108)>(*this,lib,"_PathArcToN",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,float,float,float,int) , &ImDrawList::_PathArcToN >::invoke")
		->args({"self","center","radius","a_min","a_max","num_segments"});
	addCtorAndUsing<ImDrawData>(*this,lib,"ImDrawData","ImDrawData");
	using _method_109 = das::das_call_member< void (ImDrawData::*)(),&ImDrawData::Clear >;
	addExtern<DAS_CALL_METHOD(_method_109)>(*this,lib,"Clear",SideEffects::worstDefault,"das_call_member< void (ImDrawData::*)() , &ImDrawData::Clear >::invoke")
		->args({"self"});
}
}

