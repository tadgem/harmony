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
void Module_dasIMGUI::initFunctions_21() {
	using _method_51 = das::das_call_member< void (ImDrawList::*)(ImVec2,ImVec2,bool),&ImDrawList::PushClipRect >;
	addExtern<DAS_CALL_METHOD(_method_51)>(*this,lib,"PushClipRect",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(ImVec2,ImVec2,bool) , &ImDrawList::PushClipRect >::invoke")
		->args({"self","clip_rect_min","clip_rect_max","intersect_with_current_clip_rect"})
		->arg_init(3,make_smart<ExprConstBool>(false));
	using _method_52 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::PushClipRectFullScreen >;
	addExtern<DAS_CALL_METHOD(_method_52)>(*this,lib,"PushClipRectFullScreen",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::PushClipRectFullScreen >::invoke")
		->args({"self"});
	using _method_53 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::PopClipRect >;
	addExtern<DAS_CALL_METHOD(_method_53)>(*this,lib,"PopClipRect",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::PopClipRect >::invoke")
		->args({"self"});
	using _method_54 = das::das_call_member< void (ImDrawList::*)(void *),&ImDrawList::PushTextureID >;
	addExtern<DAS_CALL_METHOD(_method_54)>(*this,lib,"PushTextureID",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(void *) , &ImDrawList::PushTextureID >::invoke")
		->args({"self","texture_id"});
	using _method_55 = das::das_call_member< void (ImDrawList::*)(),&ImDrawList::PopTextureID >;
	addExtern<DAS_CALL_METHOD(_method_55)>(*this,lib,"PopTextureID",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)() , &ImDrawList::PopTextureID >::invoke")
		->args({"self"});
	using _method_56 = das::das_call_member< ImVec2 (ImDrawList::*)() const,&ImDrawList::GetClipRectMin >;
	addExtern<DAS_CALL_METHOD(_method_56)>(*this,lib,"GetClipRectMin",SideEffects::worstDefault,"das_call_member< ImVec2 (ImDrawList::*)() const , &ImDrawList::GetClipRectMin >::invoke")
		->args({"self"});
	using _method_57 = das::das_call_member< ImVec2 (ImDrawList::*)() const,&ImDrawList::GetClipRectMax >;
	addExtern<DAS_CALL_METHOD(_method_57)>(*this,lib,"GetClipRectMax",SideEffects::worstDefault,"das_call_member< ImVec2 (ImDrawList::*)() const , &ImDrawList::GetClipRectMax >::invoke")
		->args({"self"});
	using _method_58 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int,float),&ImDrawList::AddLine >;
	addExtern<DAS_CALL_METHOD(_method_58)>(*this,lib,"AddLine",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int,float) , &ImDrawList::AddLine >::invoke")
		->args({"self","p1","p2","col","thickness"})
		->arg_init(4,make_smart<ExprConstFloat>(1.00000000000000000));
	using _method_59 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int,float,int,float),&ImDrawList::AddRect >;
	addExtern<DAS_CALL_METHOD(_method_59)>(*this,lib,"AddRect",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int,float,int,float) , &ImDrawList::AddRect >::invoke")
		->args({"self","p_min","p_max","col","rounding","flags","thickness"})
		->arg_init(4,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_type(5,makeType<ImDrawFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImDrawFlags_>(lib)))
		->arg_init(6,make_smart<ExprConstFloat>(1.00000000000000000));
	using _method_60 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int,float,int),&ImDrawList::AddRectFilled >;
	addExtern<DAS_CALL_METHOD(_method_60)>(*this,lib,"AddRectFilled",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int,float,int) , &ImDrawList::AddRectFilled >::invoke")
		->args({"self","p_min","p_max","col","rounding","flags"})
		->arg_init(4,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_type(5,makeType<ImDrawFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImDrawFlags_>(lib)));
	using _method_61 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int,unsigned int,unsigned int,unsigned int),&ImDrawList::AddRectFilledMultiColor >;
	addExtern<DAS_CALL_METHOD(_method_61)>(*this,lib,"AddRectFilledMultiColor",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,unsigned int,unsigned int,unsigned int,unsigned int) , &ImDrawList::AddRectFilledMultiColor >::invoke")
		->args({"self","p_min","p_max","col_upr_left","col_upr_right","col_bot_right","col_bot_left"});
	using _method_62 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float),&ImDrawList::AddQuad >;
	addExtern<DAS_CALL_METHOD(_method_62)>(*this,lib,"AddQuad",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float) , &ImDrawList::AddQuad >::invoke")
		->args({"self","p1","p2","p3","p4","col","thickness"})
		->arg_init(6,make_smart<ExprConstFloat>(1.00000000000000000));
	using _method_63 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::AddQuadFilled >;
	addExtern<DAS_CALL_METHOD(_method_63)>(*this,lib,"AddQuadFilled",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::AddQuadFilled >::invoke")
		->args({"self","p1","p2","p3","p4","col"});
	using _method_64 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float),&ImDrawList::AddTriangle >;
	addExtern<DAS_CALL_METHOD(_method_64)>(*this,lib,"AddTriangle",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int,float) , &ImDrawList::AddTriangle >::invoke")
		->args({"self","p1","p2","p3","col","thickness"})
		->arg_init(5,make_smart<ExprConstFloat>(1.00000000000000000));
	using _method_65 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int),&ImDrawList::AddTriangleFilled >;
	addExtern<DAS_CALL_METHOD(_method_65)>(*this,lib,"AddTriangleFilled",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,const ImVec2 &,const ImVec2 &,unsigned int) , &ImDrawList::AddTriangleFilled >::invoke")
		->args({"self","p1","p2","p3","col"});
	using _method_66 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,float,unsigned int,int,float),&ImDrawList::AddCircle >;
	addExtern<DAS_CALL_METHOD(_method_66)>(*this,lib,"AddCircle",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,float,unsigned int,int,float) , &ImDrawList::AddCircle >::invoke")
		->args({"self","center","radius","col","num_segments","thickness"})
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstFloat>(1.00000000000000000));
	using _method_67 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,float,unsigned int,int),&ImDrawList::AddCircleFilled >;
	addExtern<DAS_CALL_METHOD(_method_67)>(*this,lib,"AddCircleFilled",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,float,unsigned int,int) , &ImDrawList::AddCircleFilled >::invoke")
		->args({"self","center","radius","col","num_segments"})
		->arg_init(4,make_smart<ExprConstInt>(0));
	using _method_68 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,float,unsigned int,int,float),&ImDrawList::AddNgon >;
	addExtern<DAS_CALL_METHOD(_method_68)>(*this,lib,"AddNgon",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,float,unsigned int,int,float) , &ImDrawList::AddNgon >::invoke")
		->args({"self","center","radius","col","num_segments","thickness"})
		->arg_init(5,make_smart<ExprConstFloat>(1.00000000000000000));
	using _method_69 = das::das_call_member< void (ImDrawList::*)(const ImVec2 &,float,unsigned int,int),&ImDrawList::AddNgonFilled >;
	addExtern<DAS_CALL_METHOD(_method_69)>(*this,lib,"AddNgonFilled",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 &,float,unsigned int,int) , &ImDrawList::AddNgonFilled >::invoke")
		->args({"self","center","radius","col","num_segments"});
	using _method_70 = das::das_call_member< void (ImDrawList::*)(const ImVec2 *,int,unsigned int,int,float),&ImDrawList::AddPolyline >;
	addExtern<DAS_CALL_METHOD(_method_70)>(*this,lib,"AddPolyline",SideEffects::worstDefault,"das_call_member< void (ImDrawList::*)(const ImVec2 *,int,unsigned int,int,float) , &ImDrawList::AddPolyline >::invoke")
		->args({"self","points","num_points","col","flags","thickness"})
		->arg_type(4,makeType<ImDrawFlags_>(lib));
}
}

