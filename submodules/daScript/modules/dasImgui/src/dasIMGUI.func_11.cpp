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
void Module_dasIMGUI::initFunctions_11() {
	addExtern< void (*)(const char *,float,const char *) , ImGui::Value >(*this,lib,"Value",SideEffects::worstDefault,"ImGui::Value")
		->args({"prefix","v","float_format"})
		->arg_init(2,make_smart<ExprConstString>(""));
	addExtern< bool (*)() , ImGui::BeginMenuBar >(*this,lib,"BeginMenuBar",SideEffects::worstDefault,"ImGui::BeginMenuBar");
	addExtern< void (*)() , ImGui::EndMenuBar >(*this,lib,"EndMenuBar",SideEffects::worstDefault,"ImGui::EndMenuBar");
	addExtern< bool (*)() , ImGui::BeginMainMenuBar >(*this,lib,"BeginMainMenuBar",SideEffects::worstDefault,"ImGui::BeginMainMenuBar");
	addExtern< void (*)() , ImGui::EndMainMenuBar >(*this,lib,"EndMainMenuBar",SideEffects::worstDefault,"ImGui::EndMainMenuBar");
	addExtern< bool (*)(const char *,bool) , ImGui::BeginMenu >(*this,lib,"BeginMenu",SideEffects::worstDefault,"ImGui::BeginMenu")
		->args({"label","enabled"})
		->arg_init(1,make_smart<ExprConstBool>(true));
	addExtern< void (*)() , ImGui::EndMenu >(*this,lib,"EndMenu",SideEffects::worstDefault,"ImGui::EndMenu");
	addExtern< bool (*)(const char *,const char *,bool,bool) , ImGui::MenuItem >(*this,lib,"MenuItem",SideEffects::worstDefault,"ImGui::MenuItem")
		->args({"label","shortcut","selected","enabled"})
		->arg_init(1,make_smart<ExprConstString>(""))
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_init(3,make_smart<ExprConstBool>(true));
	addExtern< bool (*)(const char *,const char *,bool *,bool) , ImGui::MenuItem >(*this,lib,"MenuItem",SideEffects::worstDefault,"ImGui::MenuItem")
		->args({"label","shortcut","p_selected","enabled"})
		->arg_init(3,make_smart<ExprConstBool>(true));
	addExtern< void (*)() , ImGui::BeginTooltip >(*this,lib,"BeginTooltip",SideEffects::worstDefault,"ImGui::BeginTooltip");
	addExtern< void (*)() , ImGui::EndTooltip >(*this,lib,"EndTooltip",SideEffects::worstDefault,"ImGui::EndTooltip");
	addExtern< bool (*)(const char *,int) , ImGui::BeginPopup >(*this,lib,"BeginPopup",SideEffects::worstDefault,"ImGui::BeginPopup")
		->args({"str_id","flags"})
		->arg_type(1,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)));
	addExtern< bool (*)(const char *,bool *,int) , ImGui::BeginPopupModal >(*this,lib,"BeginPopupModal",SideEffects::worstDefault,"ImGui::BeginPopupModal")
		->args({"name","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)));
	addExtern< void (*)() , ImGui::EndPopup >(*this,lib,"EndPopup",SideEffects::worstDefault,"ImGui::EndPopup");
	addExtern< void (*)(const char *,int) , ImGui::OpenPopup >(*this,lib,"OpenPopup",SideEffects::worstDefault,"ImGui::OpenPopup")
		->args({"str_id","popup_flags"})
		->arg_type(1,makeType<ImGuiPopupFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiPopupFlags_>(lib)));
	addExtern< void (*)(const char *,int) , ImGui::OpenPopupOnItemClick >(*this,lib,"OpenPopupOnItemClick",SideEffects::worstDefault,"ImGui::OpenPopupOnItemClick")
		->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_type(1,makeType<ImGuiPopupFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(1,makeType<ImGuiPopupFlags_>(lib)));
	addExtern< void (*)() , ImGui::CloseCurrentPopup >(*this,lib,"CloseCurrentPopup",SideEffects::worstDefault,"ImGui::CloseCurrentPopup");
	addExtern< bool (*)(const char *,int) , ImGui::BeginPopupContextItem >(*this,lib,"BeginPopupContextItem",SideEffects::worstDefault,"ImGui::BeginPopupContextItem")
		->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_type(1,makeType<ImGuiPopupFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(1,makeType<ImGuiPopupFlags_>(lib)));
	addExtern< bool (*)(const char *,int) , ImGui::BeginPopupContextWindow >(*this,lib,"BeginPopupContextWindow",SideEffects::worstDefault,"ImGui::BeginPopupContextWindow")
		->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_type(1,makeType<ImGuiPopupFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(1,makeType<ImGuiPopupFlags_>(lib)));
	addExtern< bool (*)(const char *,int) , ImGui::BeginPopupContextVoid >(*this,lib,"BeginPopupContextVoid",SideEffects::worstDefault,"ImGui::BeginPopupContextVoid")
		->args({"str_id","popup_flags"})
		->arg_init(0,make_smart<ExprConstString>(""))
		->arg_type(1,makeType<ImGuiPopupFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(1,makeType<ImGuiPopupFlags_>(lib)));
}
}

