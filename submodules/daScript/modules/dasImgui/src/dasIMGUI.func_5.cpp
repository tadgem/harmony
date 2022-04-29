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
void Module_dasIMGUI::initFunctions_5() {
	addExtern< float (*)() , ImGui::CalcItemWidth >(*this,lib,"CalcItemWidth",SideEffects::worstDefault,"ImGui::CalcItemWidth");
	addExtern< void (*)(float) , ImGui::PushTextWrapPos >(*this,lib,"PushTextWrapPos",SideEffects::worstDefault,"ImGui::PushTextWrapPos")
		->args({"wrap_local_pos_x"})
		->arg_init(0,make_smart<ExprConstFloat>(0.00000000000000000));
	addExtern< void (*)() , ImGui::PopTextWrapPos >(*this,lib,"PopTextWrapPos",SideEffects::worstDefault,"ImGui::PopTextWrapPos");
	addExtern< ImFont * (*)() , ImGui::GetFont >(*this,lib,"GetFont",SideEffects::worstDefault,"ImGui::GetFont");
	addExtern< float (*)() , ImGui::GetFontSize >(*this,lib,"GetFontSize",SideEffects::worstDefault,"ImGui::GetFontSize");
	addExtern< ImVec2 (*)() , ImGui::GetFontTexUvWhitePixel >(*this,lib,"GetFontTexUvWhitePixel",SideEffects::worstDefault,"ImGui::GetFontTexUvWhitePixel");
	addExtern< unsigned int (*)(int,float) , ImGui::GetColorU32 >(*this,lib,"GetColorU32",SideEffects::worstDefault,"ImGui::GetColorU32")
		->args({"idx","alpha_mul"})
		->arg_type(0,makeType<ImGuiCol_>(lib))
		->arg_init(1,make_smart<ExprConstFloat>(1.00000000000000000));
	addExtern< unsigned int (*)(const ImVec4 &) , ImGui::GetColorU32 >(*this,lib,"GetColorU32",SideEffects::worstDefault,"ImGui::GetColorU32")
		->args({"col"});
	addExtern< unsigned int (*)(unsigned int) , ImGui::GetColorU32 >(*this,lib,"GetColorU32",SideEffects::worstDefault,"ImGui::GetColorU32")
		->args({"col"});
	addExtern< const ImVec4 & (*)(int) , ImGui::GetStyleColorVec4 , SimNode_ExtFuncCallRef>(*this,lib,"GetStyleColorVec4",SideEffects::worstDefault,"ImGui::GetStyleColorVec4")
		->args({"idx"})
		->arg_type(0,makeType<ImGuiCol_>(lib));
	addExtern< void (*)() , ImGui::Separator >(*this,lib,"Separator",SideEffects::worstDefault,"ImGui::Separator");
	addExtern< void (*)(float,float) , ImGui::SameLine >(*this,lib,"SameLine",SideEffects::worstDefault,"ImGui::SameLine")
		->args({"offset_from_start_x","spacing"})
		->arg_init(0,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(1,make_smart<ExprConstFloat>(-1.00000000000000000));
	addExtern< void (*)() , ImGui::NewLine >(*this,lib,"NewLine",SideEffects::worstDefault,"ImGui::NewLine");
	addExtern< void (*)() , ImGui::Spacing >(*this,lib,"Spacing",SideEffects::worstDefault,"ImGui::Spacing");
	addExtern< void (*)(const ImVec2 &) , ImGui::Dummy >(*this,lib,"Dummy",SideEffects::worstDefault,"ImGui::Dummy")
		->args({"size"});
	addExtern< void (*)(float) , ImGui::Indent >(*this,lib,"Indent",SideEffects::worstDefault,"ImGui::Indent")
		->args({"indent_w"})
		->arg_init(0,make_smart<ExprConstFloat>(0.00000000000000000));
	addExtern< void (*)(float) , ImGui::Unindent >(*this,lib,"Unindent",SideEffects::worstDefault,"ImGui::Unindent")
		->args({"indent_w"})
		->arg_init(0,make_smart<ExprConstFloat>(0.00000000000000000));
	addExtern< void (*)() , ImGui::BeginGroup >(*this,lib,"BeginGroup",SideEffects::worstDefault,"ImGui::BeginGroup");
	addExtern< void (*)() , ImGui::EndGroup >(*this,lib,"EndGroup",SideEffects::worstDefault,"ImGui::EndGroup");
	addExtern< ImVec2 (*)() , ImGui::GetCursorPos >(*this,lib,"GetCursorPos",SideEffects::worstDefault,"ImGui::GetCursorPos");
}
}

