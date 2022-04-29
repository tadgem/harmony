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
void Module_dasIMGUI::initFunctions_20() {
	using _method_35 = das::das_call_member< void * (ImGuiStorage::*)(unsigned int) const,&ImGuiStorage::GetVoidPtr >;
	addExtern<DAS_CALL_METHOD(_method_35)>(*this,lib,"GetVoidPtr",SideEffects::worstDefault,"das_call_member< void * (ImGuiStorage::*)(unsigned int) const , &ImGuiStorage::GetVoidPtr >::invoke")
		->args({"self","key"});
	using _method_36 = das::das_call_member< void (ImGuiStorage::*)(unsigned int,void *),&ImGuiStorage::SetVoidPtr >;
	addExtern<DAS_CALL_METHOD(_method_36)>(*this,lib,"SetVoidPtr",SideEffects::worstDefault,"das_call_member< void (ImGuiStorage::*)(unsigned int,void *) , &ImGuiStorage::SetVoidPtr >::invoke")
		->args({"self","key","val"});
	using _method_37 = das::das_call_member< int * (ImGuiStorage::*)(unsigned int,int),&ImGuiStorage::GetIntRef >;
	addExtern<DAS_CALL_METHOD(_method_37)>(*this,lib,"GetIntRef",SideEffects::worstDefault,"das_call_member< int * (ImGuiStorage::*)(unsigned int,int) , &ImGuiStorage::GetIntRef >::invoke")
		->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstInt>(0));
	using _method_38 = das::das_call_member< bool * (ImGuiStorage::*)(unsigned int,bool),&ImGuiStorage::GetBoolRef >;
	addExtern<DAS_CALL_METHOD(_method_38)>(*this,lib,"GetBoolRef",SideEffects::worstDefault,"das_call_member< bool * (ImGuiStorage::*)(unsigned int,bool) , &ImGuiStorage::GetBoolRef >::invoke")
		->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstBool>(false));
	using _method_39 = das::das_call_member< float * (ImGuiStorage::*)(unsigned int,float),&ImGuiStorage::GetFloatRef >;
	addExtern<DAS_CALL_METHOD(_method_39)>(*this,lib,"GetFloatRef",SideEffects::worstDefault,"das_call_member< float * (ImGuiStorage::*)(unsigned int,float) , &ImGuiStorage::GetFloatRef >::invoke")
		->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstFloat>(0.00000000000000000));
	using _method_40 = das::das_call_member< void ** (ImGuiStorage::*)(unsigned int,void *),&ImGuiStorage::GetVoidPtrRef >;
	addExtern<DAS_CALL_METHOD(_method_40)>(*this,lib,"GetVoidPtrRef",SideEffects::worstDefault,"das_call_member< void ** (ImGuiStorage::*)(unsigned int,void *) , &ImGuiStorage::GetVoidPtrRef >::invoke")
		->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstPtr>());
	using _method_41 = das::das_call_member< void (ImGuiStorage::*)(int),&ImGuiStorage::SetAllInt >;
	addExtern<DAS_CALL_METHOD(_method_41)>(*this,lib,"SetAllInt",SideEffects::worstDefault,"das_call_member< void (ImGuiStorage::*)(int) , &ImGuiStorage::SetAllInt >::invoke")
		->args({"self","val"});
	using _method_42 = das::das_call_member< void (ImGuiStorage::*)(),&ImGuiStorage::BuildSortByKey >;
	addExtern<DAS_CALL_METHOD(_method_42)>(*this,lib,"BuildSortByKey",SideEffects::worstDefault,"das_call_member< void (ImGuiStorage::*)() , &ImGuiStorage::BuildSortByKey >::invoke")
		->args({"self"});
	addCtorAndUsing<ImGuiListClipper>(*this,lib,"ImGuiListClipper","ImGuiListClipper");
	using _method_43 = das::das_call_member< void (ImGuiListClipper::*)(int,float),&ImGuiListClipper::Begin >;
	addExtern<DAS_CALL_METHOD(_method_43)>(*this,lib,"Begin",SideEffects::worstDefault,"das_call_member< void (ImGuiListClipper::*)(int,float) , &ImGuiListClipper::Begin >::invoke")
		->args({"self","items_count","items_height"})
		->arg_init(2,make_smart<ExprConstFloat>(-1.00000000000000000));
	using _method_44 = das::das_call_member< void (ImGuiListClipper::*)(),&ImGuiListClipper::End >;
	addExtern<DAS_CALL_METHOD(_method_44)>(*this,lib,"End",SideEffects::worstDefault,"das_call_member< void (ImGuiListClipper::*)() , &ImGuiListClipper::End >::invoke")
		->args({"self"});
	using _method_45 = das::das_call_member< bool (ImGuiListClipper::*)(),&ImGuiListClipper::Step >;
	addExtern<DAS_CALL_METHOD(_method_45)>(*this,lib,"Step",SideEffects::worstDefault,"das_call_member< bool (ImGuiListClipper::*)() , &ImGuiListClipper::Step >::invoke")
		->args({"self"});
	addCtorAndUsing<ImDrawCmd>(*this,lib,"ImDrawCmd","ImDrawCmd");
	addCtorAndUsing<ImDrawListSplitter>(*this,lib,"ImDrawListSplitter","ImDrawListSplitter");
	using _method_46 = das::das_call_member< void (ImDrawListSplitter::*)(),&ImDrawListSplitter::Clear >;
	addExtern<DAS_CALL_METHOD(_method_46)>(*this,lib,"Clear",SideEffects::worstDefault,"das_call_member< void (ImDrawListSplitter::*)() , &ImDrawListSplitter::Clear >::invoke")
		->args({"self"});
	using _method_47 = das::das_call_member< void (ImDrawListSplitter::*)(),&ImDrawListSplitter::ClearFreeMemory >;
	addExtern<DAS_CALL_METHOD(_method_47)>(*this,lib,"ClearFreeMemory",SideEffects::worstDefault,"das_call_member< void (ImDrawListSplitter::*)() , &ImDrawListSplitter::ClearFreeMemory >::invoke")
		->args({"self"});
	using _method_48 = das::das_call_member< void (ImDrawListSplitter::*)(ImDrawList *,int),&ImDrawListSplitter::Split >;
	addExtern<DAS_CALL_METHOD(_method_48)>(*this,lib,"Split",SideEffects::worstDefault,"das_call_member< void (ImDrawListSplitter::*)(ImDrawList *,int) , &ImDrawListSplitter::Split >::invoke")
		->args({"self","draw_list","count"});
	using _method_49 = das::das_call_member< void (ImDrawListSplitter::*)(ImDrawList *),&ImDrawListSplitter::Merge >;
	addExtern<DAS_CALL_METHOD(_method_49)>(*this,lib,"Merge",SideEffects::worstDefault,"das_call_member< void (ImDrawListSplitter::*)(ImDrawList *) , &ImDrawListSplitter::Merge >::invoke")
		->args({"self","draw_list"});
	using _method_50 = das::das_call_member< void (ImDrawListSplitter::*)(ImDrawList *,int),&ImDrawListSplitter::SetCurrentChannel >;
	addExtern<DAS_CALL_METHOD(_method_50)>(*this,lib,"SetCurrentChannel",SideEffects::worstDefault,"das_call_member< void (ImDrawListSplitter::*)(ImDrawList *,int) , &ImDrawListSplitter::SetCurrentChannel >::invoke")
		->args({"self","draw_list","channel_idx"});
	addCtorAndUsing<ImDrawList,const ImDrawListSharedData *>(*this,lib,"ImDrawList","ImDrawList")
		->args({"shared_data"});
}
}

