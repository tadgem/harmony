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
void Module_dasIMGUI::initFunctions_2() {
	addExtern< void (*)(ImGuiStyle *) , ImGui::StyleColorsClassic >(*this,lib,"StyleColorsClassic",SideEffects::worstDefault,"ImGui::StyleColorsClassic")
		->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< bool (*)(const char *,bool *,int) , ImGui::Begin >(*this,lib,"Begin",SideEffects::worstDefault,"ImGui::Begin")
		->args({"name","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)));
	addExtern< void (*)() , ImGui::End >(*this,lib,"End",SideEffects::worstDefault,"ImGui::End");
	addExtern< bool (*)(const char *,const ImVec2 &,bool,int) , ImGui::BeginChild >(*this,lib,"BeginChild",SideEffects::worstDefault,"ImGui::BeginChild")
		->args({"str_id","size","border","flags"})
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_type(3,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)));
	addExtern< bool (*)(unsigned int,const ImVec2 &,bool,int) , ImGui::BeginChild >(*this,lib,"BeginChild",SideEffects::worstDefault,"ImGui::BeginChild")
		->args({"id","size","border","flags"})
		->arg_init(2,make_smart<ExprConstBool>(false))
		->arg_type(3,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)));
	addExtern< void (*)() , ImGui::EndChild >(*this,lib,"EndChild",SideEffects::worstDefault,"ImGui::EndChild");
	addExtern< bool (*)() , ImGui::IsWindowAppearing >(*this,lib,"IsWindowAppearing",SideEffects::worstDefault,"ImGui::IsWindowAppearing");
	addExtern< bool (*)() , ImGui::IsWindowCollapsed >(*this,lib,"IsWindowCollapsed",SideEffects::worstDefault,"ImGui::IsWindowCollapsed");
	addExtern< bool (*)(int) , ImGui::IsWindowFocused >(*this,lib,"IsWindowFocused",SideEffects::worstDefault,"ImGui::IsWindowFocused")
		->args({"flags"})
		->arg_type(0,makeType<ImGuiFocusedFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiFocusedFlags_>(lib)));
	addExtern< bool (*)(int) , ImGui::IsWindowHovered >(*this,lib,"IsWindowHovered",SideEffects::worstDefault,"ImGui::IsWindowHovered")
		->args({"flags"})
		->arg_type(0,makeType<ImGuiHoveredFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiHoveredFlags_>(lib)));
	addExtern< ImDrawList * (*)() , ImGui::GetWindowDrawList >(*this,lib,"GetWindowDrawList",SideEffects::worstDefault,"ImGui::GetWindowDrawList");
	addExtern< ImVec2 (*)() , ImGui::GetWindowPos >(*this,lib,"GetWindowPos",SideEffects::worstDefault,"ImGui::GetWindowPos");
	addExtern< ImVec2 (*)() , ImGui::GetWindowSize >(*this,lib,"GetWindowSize",SideEffects::worstDefault,"ImGui::GetWindowSize");
	addExtern< float (*)() , ImGui::GetWindowWidth >(*this,lib,"GetWindowWidth",SideEffects::worstDefault,"ImGui::GetWindowWidth");
	addExtern< float (*)() , ImGui::GetWindowHeight >(*this,lib,"GetWindowHeight",SideEffects::worstDefault,"ImGui::GetWindowHeight");
	addExtern< void (*)(const ImVec2 &,int,const ImVec2 &) , ImGui::SetNextWindowPos >(*this,lib,"SetNextWindowPos",SideEffects::worstDefault,"ImGui::SetNextWindowPos")
		->args({"pos","cond","pivot"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)(const ImVec2 &,int) , ImGui::SetNextWindowSize >(*this,lib,"SetNextWindowSize",SideEffects::worstDefault,"ImGui::SetNextWindowSize")
		->args({"size","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)(const ImVec2 &) , ImGui::SetNextWindowContentSize >(*this,lib,"SetNextWindowContentSize",SideEffects::worstDefault,"ImGui::SetNextWindowContentSize")
		->args({"size"});
	addExtern< void (*)(bool,int) , ImGui::SetNextWindowCollapsed >(*this,lib,"SetNextWindowCollapsed",SideEffects::worstDefault,"ImGui::SetNextWindowCollapsed")
		->args({"collapsed","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)() , ImGui::SetNextWindowFocus >(*this,lib,"SetNextWindowFocus",SideEffects::worstDefault,"ImGui::SetNextWindowFocus");
}
}

