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
void Module_dasIMGUI::initFunctions_22() {
	using _method_71 = das::das_call_member< void (ImDrawList::*)(const ImVec2 *,int,unsigned int),&ImDrawList::AddConvexPolyFilled >;
	addExtern<DAS_CALL_METHOD(_method_71)>(*this,lib,"AddConvexPolyFilled",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 *,int,unsigned int) , &ImDrawList::AddConvexPolyFilled >::invoke")
		->args({"self","points","num_points","col"});
	using _method_72 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float,int),&ImDrawList::AddBezierCubic >;
	addExtern<DAS_CALL_METHOD(_method_72)>(*this,lib,"AddBezierCubic",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float,int) , &ImDrawList::AddBezierCubic >::invoke")
		->args({"self","p1","p2","p3","p4","col","thickness","num_segments"})
		->arg_init(7,make_smart<ExprConstInt>(0));
	using _method_73 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float,int),&ImDrawList::AddBezierQuadratic >;
	addExtern<DAS_CALL_METHOD(_method_73)>(*this,lib,"AddBezierQuadratic",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float,int) , &ImDrawList::AddBezierQuadratic >::invoke")
		->args({"self","p1","p2","p3","col","thickness","num_segments"})
		->arg_init(6,make_smart<ExprConstInt>(0));
	using _method_74 = das::das_call_member< void (ImDrawList::*)(void *,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::AddImage >;
	addExtern<DAS_CALL_METHOD(_method_74)>(*this,lib,"AddImage",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(void *,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::AddImage >::invoke")
		->args({"self","user_texture_id","p_min","p_max","uv_min","uv_max","col"})
		->arg_init(6,make_smart<ExprConstUInt>(0xffffffff));
	using _method_75 = das::das_call_member< void (ImDrawList::*)(void *,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::AddImageQuad >;
	addExtern<DAS_CALL_METHOD(_method_75)>(*this,lib,"AddImageQuad",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(void *,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::AddImageQuad >::invoke")
		->args({"self","user_texture_id","p1","p2","p3","p4","uv1","uv2","uv3","uv4","col"})
		->arg_init(10,make_smart<ExprConstUInt>(0xffffffff));
	using _method_76 = das::das_call_member< void (ImDrawList::*)(void *,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float,int),&ImDrawList::AddImageRounded >;
	addExtern<DAS_CALL_METHOD(_method_76)>(*this,lib,"AddImageRounded",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(void *,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float,int) , &ImDrawList::AddImageRounded >::invoke")
		->args({"self","user_texture_id","p_min","p_max","uv_min","uv_max","col","rounding","flags"})
		->arg_type(8,makeType<ImDrawFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImDrawFlags_>(lib)));
	using _method_77 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::PathClear >;
	addExtern<DAS_CALL_METHOD(_method_77)>(*this,lib,"PathClear",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::PathClear >::invoke")
		->args({"self"});
	using _method_78 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &),&ImDrawList::PathLineTo >;
	addExtern<DAS_CALL_METHOD(_method_78)>(*this,lib,"PathLineTo",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &) , &ImDrawList::PathLineTo >::invoke")
		->args({"self","pos"});
	using _method_79 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &),&ImDrawList::PathLineToMergeDuplicate >;
	addExtern<DAS_CALL_METHOD(_method_79)>(*this,lib,"PathLineToMergeDuplicate",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &) , &ImDrawList::PathLineToMergeDuplicate >::invoke")
		->args({"self","pos"});
	using _method_80 = das::das_call_member< void (ImDrawList::*)(unsigned int),&ImDrawList::PathFillConvex >;
	addExtern<DAS_CALL_METHOD(_method_80)>(*this,lib,"PathFillConvex",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(unsigned int) , &ImDrawList::PathFillConvex >::invoke")
		->args({"self","col"});
	using _method_81 = das::das_call_member< void (ImDrawList::*)(unsigned int,int,float),&ImDrawList::PathStroke >;
	addExtern<DAS_CALL_METHOD(_method_81)>(*this,lib,"PathStroke",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(unsigned int,int,float) , &ImDrawList::PathStroke >::invoke")
		->args({"self","col","flags","thickness"})
		->arg_type(2,makeType<ImDrawFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImDrawFlags_>(lib)))
		->arg_init(3,make_smart<ExprConstFloat>(1.00000000000000000));
	using _method_82 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,float,float,float,int),&ImDrawList::PathArcTo >;
	addExtern<DAS_CALL_METHOD(_method_82)>(*this,lib,"PathArcTo",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,float,float,float,int) , &ImDrawList::PathArcTo >::invoke")
		->args({"self","center","radius","a_min","a_max","num_segments"})
		->arg_init(5,make_smart<ExprConstInt>(0));
	using _method_83 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,float,int,int),&ImDrawList::PathArcToFast >;
	addExtern<DAS_CALL_METHOD(_method_83)>(*this,lib,"PathArcToFast",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,float,int,int) , &ImDrawList::PathArcToFast >::invoke")
		->args({"self","center","radius","a_min_of_12","a_max_of_12"});
	using _method_84 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,int),&ImDrawList::PathBezierCubicCurveTo >;
	addExtern<DAS_CALL_METHOD(_method_84)>(*this,lib,"PathBezierCubicCurveTo",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,int) , &ImDrawList::PathBezierCubicCurveTo >::invoke")
		->args({"self","p2","p3","p4","num_segments"})
		->arg_init(4,make_smart<ExprConstInt>(0));
	using _method_85 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,int),&ImDrawList::PathBezierQuadraticCurveTo >;
	addExtern<DAS_CALL_METHOD(_method_85)>(*this,lib,"PathBezierQuadraticCurveTo",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,int) , &ImDrawList::PathBezierQuadraticCurveTo >::invoke")
		->args({"self","p2","p3","num_segments"})
		->arg_init(3,make_smart<ExprConstInt>(0));
	using _method_86 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,float,int),&ImDrawList::PathRect >;
	addExtern<DAS_CALL_METHOD(_method_86)>(*this,lib,"PathRect",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,float,int) , &ImDrawList::PathRect >::invoke")
		->args({"self","rect_min","rect_max","rounding","flags"})
		->arg_init(3,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_type(4,makeType<ImDrawFlags_>(lib))
		->arg_init(4,make_smart<ExprConstEnumeration>(0,makeType<ImDrawFlags_>(lib)));
	using _method_87 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::AddDrawCmd >;
	addExtern<DAS_CALL_METHOD(_method_87)>(*this,lib,"AddDrawCmd",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::AddDrawCmd >::invoke")
		->args({"self"});
	using _method_88 = das::das_call_member< ImDrawList * (ImDrawList::*)() const,&ImDrawList::CloneOutput >;
	addExtern<DAS_CALL_METHOD(_method_88)>(*this,lib,"CloneOutput",SideEffects::worstDefault,"das_call_member< ImDrawList * (ImDrawList::*)() const , &ImDrawList::CloneOutput >::invoke")
		->args({"self"});
	using _method_89 = das::das_call_member< void (ImDrawList::*)(int),&ImDrawList::ChannelsSplit >;
	addExtern<DAS_CALL_METHOD(_method_89)>(*this,lib,"ChannelsSplit",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(int) , &ImDrawList::ChannelsSplit >::invoke")
		->args({"self","count"});
	using _method_90 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::ChannelsMerge >;
	addExtern<DAS_CALL_METHOD(_method_90)>(*this,lib,"ChannelsMerge",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::ChannelsMerge >::invoke")
		->args({"self"});
}
}

