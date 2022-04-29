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
void Module_dasIMGUI::initFunctions_18() {
	using _method_6 = das::das_call_member< void (ImGuiInputTextCallbackData::*)(int,int),&ImGuiInputTextCallbackData::DeleteChars >;
	addExtern<DAS_CALL_METHOD(_method_6)>(*this,lib,"DeleteChars",SideEffects::worstDefault,"das_call_member< void (ImGuiInputTextCallbackData::*)(int,int) , &ImGuiInputTextCallbackData::DeleteChars >::invoke")
		->args({"self","pos","bytes_count"});
	using _method_7 = das::das_call_member< void (ImGuiInputTextCallbackData::*)(),&ImGuiInputTextCallbackData::SelectAll >;
	addExtern<DAS_CALL_METHOD(_method_7)>(*this,lib,"SelectAll",SideEffects::worstDefault,"das_call_member< void (ImGuiInputTextCallbackData::*)() , &ImGuiInputTextCallbackData::SelectAll >::invoke")
		->args({"self"});
	using _method_8 = das::das_call_member< void (ImGuiInputTextCallbackData::*)(),&ImGuiInputTextCallbackData::ClearSelection >;
	addExtern<DAS_CALL_METHOD(_method_8)>(*this,lib,"ClearSelection",SideEffects::worstDefault,"das_call_member< void (ImGuiInputTextCallbackData::*)() , &ImGuiInputTextCallbackData::ClearSelection >::invoke")
		->args({"self"});
	using _method_9 = das::das_call_member< bool (ImGuiInputTextCallbackData::*)() const,&ImGuiInputTextCallbackData::HasSelection >;
	addExtern<DAS_CALL_METHOD(_method_9)>(*this,lib,"HasSelection",SideEffects::worstDefault,"das_call_member< bool (ImGuiInputTextCallbackData::*)() const , &ImGuiInputTextCallbackData::HasSelection >::invoke")
		->args({"self"});
	addCtorAndUsing<ImGuiPayload>(*this,lib,"ImGuiPayload","ImGuiPayload");
	using _method_10 = das::das_call_member< void (ImGuiPayload::*)(),&ImGuiPayload::Clear >;
	addExtern<DAS_CALL_METHOD(_method_10)>(*this,lib,"Clear",SideEffects::worstDefault,"das_call_member< void (ImGuiPayload::*)() , &ImGuiPayload::Clear >::invoke")
		->args({"self"});
	using _method_11 = das::das_call_member< bool (ImGuiPayload::*)(const char *) const,&ImGuiPayload::IsDataType >;
	addExtern<DAS_CALL_METHOD(_method_11)>(*this,lib,"IsDataType",SideEffects::worstDefault,"das_call_member< bool (ImGuiPayload::*)(const char *) const , &ImGuiPayload::IsDataType >::invoke")
		->args({"self","type"});
	using _method_12 = das::das_call_member< bool (ImGuiPayload::*)() const,&ImGuiPayload::IsPreview >;
	addExtern<DAS_CALL_METHOD(_method_12)>(*this,lib,"IsPreview",SideEffects::worstDefault,"das_call_member< bool (ImGuiPayload::*)() const , &ImGuiPayload::IsPreview >::invoke")
		->args({"self"});
	using _method_13 = das::das_call_member< bool (ImGuiPayload::*)() const,&ImGuiPayload::IsDelivery >;
	addExtern<DAS_CALL_METHOD(_method_13)>(*this,lib,"IsDelivery",SideEffects::worstDefault,"das_call_member< bool (ImGuiPayload::*)() const , &ImGuiPayload::IsDelivery >::invoke")
		->args({"self"});
	addCtorAndUsing<ImGuiTableColumnSortSpecs>(*this,lib,"ImGuiTableColumnSortSpecs","ImGuiTableColumnSortSpecs");
	addCtorAndUsing<ImGuiTableSortSpecs>(*this,lib,"ImGuiTableSortSpecs","ImGuiTableSortSpecs");
	addCtorAndUsing<ImGuiOnceUponAFrame>(*this,lib,"ImGuiOnceUponAFrame","ImGuiOnceUponAFrame");
	addCtorAndUsing<ImGuiTextFilter,const char *>(*this,lib,"ImGuiTextFilter","ImGuiTextFilter")
		->args({"default_filter"})
		->arg_init(0,make_smart<ExprConstString>(""));
	using _method_14 = das::das_call_member< bool (ImGuiTextFilter::*)(const char *,float),&ImGuiTextFilter::Draw >;
	addExtern<DAS_CALL_METHOD(_method_14)>(*this,lib,"Draw",SideEffects::worstDefault,"das_call_member< bool (ImGuiTextFilter::*)(const char *,float) , &ImGuiTextFilter::Draw >::invoke")
		->args({"self","label","width"})
		->arg_init(1,make_smart<ExprConstString>("Filter (inc,-exc)"))
		->arg_init(2,make_smart<ExprConstFloat>(0.00000000000000000));
	using _method_15 = das::das_call_member< void (ImGuiTextFilter::*)(),&ImGuiTextFilter::Build >;
	addExtern<DAS_CALL_METHOD(_method_15)>(*this,lib,"Build",SideEffects::worstDefault,"das_call_member< void (ImGuiTextFilter::*)() , &ImGuiTextFilter::Build >::invoke")
		->args({"self"});
	using _method_16 = das::das_call_member< void (ImGuiTextFilter::*)(),&ImGuiTextFilter::Clear >;
	addExtern<DAS_CALL_METHOD(_method_16)>(*this,lib,"Clear",SideEffects::worstDefault,"das_call_member< void (ImGuiTextFilter::*)() , &ImGuiTextFilter::Clear >::invoke")
		->args({"self"});
	using _method_17 = das::das_call_member< bool (ImGuiTextFilter::*)() const,&ImGuiTextFilter::IsActive >;
	addExtern<DAS_CALL_METHOD(_method_17)>(*this,lib,"IsActive",SideEffects::worstDefault,"das_call_member< bool (ImGuiTextFilter::*)() const , &ImGuiTextFilter::IsActive >::invoke")
		->args({"self"});
	addCtorAndUsing<ImGuiTextFilter::ImGuiTextRange>(*this,lib,"ImGuiTextRange","ImGuiTextFilter::ImGuiTextRange");
	addCtorAndUsing<ImGuiTextFilter::ImGuiTextRange,const char *,const char *>(*this,lib,"ImGuiTextRange","ImGuiTextFilter::ImGuiTextRange")
		->args({"_b","_e"});
	using _method_18 = das::das_call_member< bool (ImGuiTextFilter::ImGuiTextRange::*)() const,&ImGuiTextFilter::ImGuiTextRange::empty >;
	addExtern<DAS_CALL_METHOD(_method_18)>(*this,lib,"empty",SideEffects::worstDefault,"das_call_member< bool (ImGuiTextFilter::ImGuiTextRange::*)() const , &ImGuiTextFilter::ImGuiTextRange::empty >::invoke")
		->args({"self"});
}
}

