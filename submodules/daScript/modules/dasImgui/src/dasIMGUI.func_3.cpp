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
void Module_dasIMGUI::initFunctions_3() {
	addExtern< void (*)(float) , ImGui::SetNextWindowBgAlpha >(*this,lib,"SetNextWindowBgAlpha",SideEffects::worstDefault,"ImGui::SetNextWindowBgAlpha")
		->args({"alpha"});
	addExtern< void (*)(const ImVec2 &,int) , ImGui::SetWindowPos >(*this,lib,"SetWindowPos",SideEffects::worstDefault,"ImGui::SetWindowPos")
		->args({"pos","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)(const ImVec2 &,int) , ImGui::SetWindowSize >(*this,lib,"SetWindowSize",SideEffects::worstDefault,"ImGui::SetWindowSize")
		->args({"size","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)(bool,int) , ImGui::SetWindowCollapsed >(*this,lib,"SetWindowCollapsed",SideEffects::worstDefault,"ImGui::SetWindowCollapsed")
		->args({"collapsed","cond"})
		->arg_type(1,makeType<ImGuiCond_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)() , ImGui::SetWindowFocus >(*this,lib,"SetWindowFocus",SideEffects::worstDefault,"ImGui::SetWindowFocus");
	addExtern< void (*)(float) , ImGui::SetWindowFontScale >(*this,lib,"SetWindowFontScale",SideEffects::worstDefault,"ImGui::SetWindowFontScale")
		->args({"scale"});
	addExtern< void (*)(const char *,const ImVec2 &,int) , ImGui::SetWindowPos >(*this,lib,"SetWindowPos",SideEffects::worstDefault,"ImGui::SetWindowPos")
		->args({"name","pos","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)(const char *,const ImVec2 &,int) , ImGui::SetWindowSize >(*this,lib,"SetWindowSize",SideEffects::worstDefault,"ImGui::SetWindowSize")
		->args({"name","size","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)(const char *,bool,int) , ImGui::SetWindowCollapsed >(*this,lib,"SetWindowCollapsed",SideEffects::worstDefault,"ImGui::SetWindowCollapsed")
		->args({"name","collapsed","cond"})
		->arg_type(2,makeType<ImGuiCond_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)(const char *) , ImGui::SetWindowFocus >(*this,lib,"SetWindowFocus",SideEffects::worstDefault,"ImGui::SetWindowFocus")
		->args({"name"});
	addExtern< ImVec2 (*)() , ImGui::GetContentRegionAvail >(*this,lib,"GetContentRegionAvail",SideEffects::worstDefault,"ImGui::GetContentRegionAvail");
	addExtern< ImVec2 (*)() , ImGui::GetContentRegionMax >(*this,lib,"GetContentRegionMax",SideEffects::worstDefault,"ImGui::GetContentRegionMax");
	addExtern< ImVec2 (*)() , ImGui::GetWindowContentRegionMin >(*this,lib,"GetWindowContentRegionMin",SideEffects::worstDefault,"ImGui::GetWindowContentRegionMin");
	addExtern< ImVec2 (*)() , ImGui::GetWindowContentRegionMax >(*this,lib,"GetWindowContentRegionMax",SideEffects::worstDefault,"ImGui::GetWindowContentRegionMax");
	addExtern< float (*)() , ImGui::GetWindowContentRegionWidth >(*this,lib,"GetWindowContentRegionWidth",SideEffects::worstDefault,"ImGui::GetWindowContentRegionWidth");
	addExtern< float (*)() , ImGui::GetScrollX >(*this,lib,"GetScrollX",SideEffects::worstDefault,"ImGui::GetScrollX");
	addExtern< float (*)() , ImGui::GetScrollY >(*this,lib,"GetScrollY",SideEffects::worstDefault,"ImGui::GetScrollY");
	addExtern< void (*)(float) , ImGui::SetScrollX >(*this,lib,"SetScrollX",SideEffects::worstDefault,"ImGui::SetScrollX")
		->args({"scroll_x"});
	addExtern< void (*)(float) , ImGui::SetScrollY >(*this,lib,"SetScrollY",SideEffects::worstDefault,"ImGui::SetScrollY")
		->args({"scroll_y"});
	addExtern< float (*)() , ImGui::GetScrollMaxX >(*this,lib,"GetScrollMaxX",SideEffects::worstDefault,"ImGui::GetScrollMaxX");
}
}

