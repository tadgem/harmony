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
void Module_dasIMGUI::initFunctions_1() {
	addExtern< ImGuiContext * (*)(ImFontAtlas *) , ImGui::CreateContext >(*this,lib,"CreateContext",SideEffects::worstDefault,"ImGui::CreateContext")
		->args({"shared_font_atlas"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< void (*)(ImGuiContext *) , ImGui::DestroyContext >(*this,lib,"DestroyContext",SideEffects::worstDefault,"ImGui::DestroyContext")
		->args({"ctx"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< ImGuiContext * (*)() , ImGui::GetCurrentContext >(*this,lib,"GetCurrentContext",SideEffects::worstDefault,"ImGui::GetCurrentContext");
	addExtern< void (*)(ImGuiContext *) , ImGui::SetCurrentContext >(*this,lib,"SetCurrentContext",SideEffects::worstDefault,"ImGui::SetCurrentContext")
		->args({"ctx"});
	addExtern< ImGuiIO & (*)() , ImGui::GetIO , SimNode_ExtFuncCallRef>(*this,lib,"GetIO",SideEffects::worstDefault,"ImGui::GetIO");
	addExtern< ImGuiStyle & (*)() , ImGui::GetStyle , SimNode_ExtFuncCallRef>(*this,lib,"GetStyle",SideEffects::worstDefault,"ImGui::GetStyle");
	addExtern< void (*)() , ImGui::NewFrame >(*this,lib,"NewFrame",SideEffects::worstDefault,"ImGui::NewFrame");
	addExtern< void (*)() , ImGui::EndFrame >(*this,lib,"EndFrame",SideEffects::worstDefault,"ImGui::EndFrame");
	addExtern< void (*)() , ImGui::Render >(*this,lib,"Render",SideEffects::worstDefault,"ImGui::Render");
	addExtern< ImDrawData * (*)() , ImGui::GetDrawData >(*this,lib,"GetDrawData",SideEffects::worstDefault,"ImGui::GetDrawData");
	addExtern< void (*)(bool *) , ImGui::ShowDemoWindow >(*this,lib,"ShowDemoWindow",SideEffects::worstDefault,"ImGui::ShowDemoWindow")
		->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< void (*)(bool *) , ImGui::ShowMetricsWindow >(*this,lib,"ShowMetricsWindow",SideEffects::worstDefault,"ImGui::ShowMetricsWindow")
		->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< void (*)(bool *) , ImGui::ShowAboutWindow >(*this,lib,"ShowAboutWindow",SideEffects::worstDefault,"ImGui::ShowAboutWindow")
		->args({"p_open"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< void (*)(ImGuiStyle *) , ImGui::ShowStyleEditor >(*this,lib,"ShowStyleEditor",SideEffects::worstDefault,"ImGui::ShowStyleEditor")
		->args({"ref"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< bool (*)(const char *) , ImGui::ShowStyleSelector >(*this,lib,"ShowStyleSelector",SideEffects::worstDefault,"ImGui::ShowStyleSelector")
		->args({"label"});
	addExtern< void (*)(const char *) , ImGui::ShowFontSelector >(*this,lib,"ShowFontSelector",SideEffects::worstDefault,"ImGui::ShowFontSelector")
		->args({"label"});
	addExtern< void (*)() , ImGui::ShowUserGuide >(*this,lib,"ShowUserGuide",SideEffects::worstDefault,"ImGui::ShowUserGuide");
	addExtern< const char * (*)() , ImGui::GetVersion >(*this,lib,"GetVersion",SideEffects::worstDefault,"ImGui::GetVersion");
	addExtern< void (*)(ImGuiStyle *) , ImGui::StyleColorsDark >(*this,lib,"StyleColorsDark",SideEffects::worstDefault,"ImGui::StyleColorsDark")
		->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< void (*)(ImGuiStyle *) , ImGui::StyleColorsLight >(*this,lib,"StyleColorsLight",SideEffects::worstDefault,"ImGui::StyleColorsLight")
		->args({"dst"})
		->arg_init(0,make_smart<ExprConstPtr>());
}
}

