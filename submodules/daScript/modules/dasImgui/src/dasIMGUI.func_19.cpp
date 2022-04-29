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
void Module_dasIMGUI::initFunctions_19() {
	using _method_19 = das::das_call_member< void (ImGuiTextFilter::ImGuiTextRange::*)(char,ImVector<ImGuiTextFilter::ImGuiTextRange> *) const,&ImGuiTextFilter::ImGuiTextRange::split >;
	addExtern<DAS_CALL_METHOD(_method_19)>(*this,lib,"split",SideEffects::worstDefault,"das_call_member< void (ImGuiTextFilter::ImGuiTextRange::*)(char,ImVector<ImGuiTextFilter::ImGuiTextRange> *) const , &ImGuiTextFilter::ImGuiTextRange::split >::invoke")
		->args({"self","separator","out"});
	addCtorAndUsing<ImGuiTextBuffer>(*this,lib,"ImGuiTextBuffer","ImGuiTextBuffer");
	using _method_20 = das::das_call_member< char (ImGuiTextBuffer::*)(int) const,&ImGuiTextBuffer::operator[] >;
	addExtern<DAS_CALL_METHOD(_method_20)>(*this,lib,"[]",SideEffects::worstDefault,"das_call_member< char (ImGuiTextBuffer::*)(int) const , &ImGuiTextBuffer::operator[] >::invoke")
		->args({"self","i"});
	using _method_21 = das::das_call_member< const char * (ImGuiTextBuffer::*)() const,&ImGuiTextBuffer::begin >;
	addExtern<DAS_CALL_METHOD(_method_21)>(*this,lib,"begin",SideEffects::worstDefault,"das_call_member< const char * (ImGuiTextBuffer::*)() const , &ImGuiTextBuffer::begin >::invoke")
		->args({"self"});
	using _method_22 = das::das_call_member< const char * (ImGuiTextBuffer::*)() const,&ImGuiTextBuffer::end >;
	addExtern<DAS_CALL_METHOD(_method_22)>(*this,lib,"end",SideEffects::worstDefault,"das_call_member< const char * (ImGuiTextBuffer::*)() const , &ImGuiTextBuffer::end >::invoke")
		->args({"self"});
	using _method_23 = das::das_call_member< int (ImGuiTextBuffer::*)() const,&ImGuiTextBuffer::size >;
	addExtern<DAS_CALL_METHOD(_method_23)>(*this,lib,"size",SideEffects::worstDefault,"das_call_member< int (ImGuiTextBuffer::*)() const , &ImGuiTextBuffer::size >::invoke")
		->args({"self"});
	using _method_24 = das::das_call_member< bool (ImGuiTextBuffer::*)() const,&ImGuiTextBuffer::empty >;
	addExtern<DAS_CALL_METHOD(_method_24)>(*this,lib,"empty",SideEffects::worstDefault,"das_call_member< bool (ImGuiTextBuffer::*)() const , &ImGuiTextBuffer::empty >::invoke")
		->args({"self"});
	using _method_25 = das::das_call_member< void (ImGuiTextBuffer::*)(),&ImGuiTextBuffer::clear >;
	addExtern<DAS_CALL_METHOD(_method_25)>(*this,lib,"clear",SideEffects::worstDefault,"das_call_member< void (ImGuiTextBuffer::*)() , &ImGuiTextBuffer::clear >::invoke")
		->args({"self"});
	using _method_26 = das::das_call_member< void (ImGuiTextBuffer::*)(int),&ImGuiTextBuffer::reserve >;
	addExtern<DAS_CALL_METHOD(_method_26)>(*this,lib,"reserve",SideEffects::worstDefault,"das_call_member< void (ImGuiTextBuffer::*)(int) , &ImGuiTextBuffer::reserve >::invoke")
		->args({"self","capacity"});
	using _method_27 = das::das_call_member< const char * (ImGuiTextBuffer::*)() const,&ImGuiTextBuffer::c_str >;
	addExtern<DAS_CALL_METHOD(_method_27)>(*this,lib,"c_str",SideEffects::worstDefault,"das_call_member< const char * (ImGuiTextBuffer::*)() const , &ImGuiTextBuffer::c_str >::invoke")
		->args({"self"});
	addCtorAndUsing<ImGuiStorage::ImGuiStoragePair,unsigned int,int>(*this,lib,"ImGuiStoragePair","ImGuiStorage::ImGuiStoragePair")
		->args({"_key","_val_i"});
	addCtorAndUsing<ImGuiStorage::ImGuiStoragePair,unsigned int,float>(*this,lib,"ImGuiStoragePair","ImGuiStorage::ImGuiStoragePair")
		->args({"_key","_val_f"});
	addCtorAndUsing<ImGuiStorage::ImGuiStoragePair,unsigned int,void *>(*this,lib,"ImGuiStoragePair","ImGuiStorage::ImGuiStoragePair")
		->args({"_key","_val_p"});
	using _method_28 = das::das_call_member< void (ImGuiStorage::*)(),&ImGuiStorage::Clear >;
	addExtern<DAS_CALL_METHOD(_method_28)>(*this,lib,"Clear",SideEffects::worstDefault,"das_call_member< void (ImGuiStorage::*)() , &ImGuiStorage::Clear >::invoke")
		->args({"self"});
	using _method_29 = das::das_call_member< int (ImGuiStorage::*)(unsigned int,int) const,&ImGuiStorage::GetInt >;
	addExtern<DAS_CALL_METHOD(_method_29)>(*this,lib,"GetInt",SideEffects::worstDefault,"das_call_member< int (ImGuiStorage::*)(unsigned int,int) const , &ImGuiStorage::GetInt >::invoke")
		->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstInt>(0));
	using _method_30 = das::das_call_member< void (ImGuiStorage::*)(unsigned int,int),&ImGuiStorage::SetInt >;
	addExtern<DAS_CALL_METHOD(_method_30)>(*this,lib,"SetInt",SideEffects::worstDefault,"das_call_member< void (ImGuiStorage::*)(unsigned int,int) , &ImGuiStorage::SetInt >::invoke")
		->args({"self","key","val"});
	using _method_31 = das::das_call_member< bool (ImGuiStorage::*)(unsigned int,bool) const,&ImGuiStorage::GetBool >;
	addExtern<DAS_CALL_METHOD(_method_31)>(*this,lib,"GetBool",SideEffects::worstDefault,"das_call_member< bool (ImGuiStorage::*)(unsigned int,bool) const , &ImGuiStorage::GetBool >::invoke")
		->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstBool>(false));
	using _method_32 = das::das_call_member< void (ImGuiStorage::*)(unsigned int,bool),&ImGuiStorage::SetBool >;
	addExtern<DAS_CALL_METHOD(_method_32)>(*this,lib,"SetBool",SideEffects::worstDefault,"das_call_member< void (ImGuiStorage::*)(unsigned int,bool) , &ImGuiStorage::SetBool >::invoke")
		->args({"self","key","val"});
	using _method_33 = das::das_call_member< float (ImGuiStorage::*)(unsigned int,float) const,&ImGuiStorage::GetFloat >;
	addExtern<DAS_CALL_METHOD(_method_33)>(*this,lib,"GetFloat",SideEffects::worstDefault,"das_call_member< float (ImGuiStorage::*)(unsigned int,float) const , &ImGuiStorage::GetFloat >::invoke")
		->args({"self","key","default_val"})
		->arg_init(2,make_smart<ExprConstFloat>(0.00000000000000000));
	using _method_34 = das::das_call_member< void (ImGuiStorage::*)(unsigned int,float),&ImGuiStorage::SetFloat >;
	addExtern<DAS_CALL_METHOD(_method_34)>(*this,lib,"SetFloat",SideEffects::worstDefault,"das_call_member< void (ImGuiStorage::*)(unsigned int,float) , &ImGuiStorage::SetFloat >::invoke")
		->args({"self","key","val"});
}
}

