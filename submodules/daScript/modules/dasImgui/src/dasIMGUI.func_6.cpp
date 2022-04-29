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
void Module_dasIMGUI::initFunctions_6() {
	addExtern< float (*)() , ImGui::GetCursorPosX >(*this,lib,"GetCursorPosX",SideEffects::worstDefault,"ImGui::GetCursorPosX");
	addExtern< float (*)() , ImGui::GetCursorPosY >(*this,lib,"GetCursorPosY",SideEffects::worstDefault,"ImGui::GetCursorPosY");
	addExtern< void (*)(const ImVec2 &) , ImGui::SetCursorPos >(*this,lib,"SetCursorPos",SideEffects::worstDefault,"ImGui::SetCursorPos")
		->args({"local_pos"});
	addExtern< void (*)(float) , ImGui::SetCursorPosX >(*this,lib,"SetCursorPosX",SideEffects::worstDefault,"ImGui::SetCursorPosX")
		->args({"local_x"});
	addExtern< void (*)(float) , ImGui::SetCursorPosY >(*this,lib,"SetCursorPosY",SideEffects::worstDefault,"ImGui::SetCursorPosY")
		->args({"local_y"});
	addExtern< ImVec2 (*)() , ImGui::GetCursorStartPos >(*this,lib,"GetCursorStartPos",SideEffects::worstDefault,"ImGui::GetCursorStartPos");
	addExtern< ImVec2 (*)() , ImGui::GetCursorScreenPos >(*this,lib,"GetCursorScreenPos",SideEffects::worstDefault,"ImGui::GetCursorScreenPos");
	addExtern< void (*)(const ImVec2 &) , ImGui::SetCursorScreenPos >(*this,lib,"SetCursorScreenPos",SideEffects::worstDefault,"ImGui::SetCursorScreenPos")
		->args({"pos"});
	addExtern< void (*)() , ImGui::AlignTextToFramePadding >(*this,lib,"AlignTextToFramePadding",SideEffects::worstDefault,"ImGui::AlignTextToFramePadding");
	addExtern< float (*)() , ImGui::GetTextLineHeight >(*this,lib,"GetTextLineHeight",SideEffects::worstDefault,"ImGui::GetTextLineHeight");
	addExtern< float (*)() , ImGui::GetTextLineHeightWithSpacing >(*this,lib,"GetTextLineHeightWithSpacing",SideEffects::worstDefault,"ImGui::GetTextLineHeightWithSpacing");
	addExtern< float (*)() , ImGui::GetFrameHeight >(*this,lib,"GetFrameHeight",SideEffects::worstDefault,"ImGui::GetFrameHeight");
	addExtern< float (*)() , ImGui::GetFrameHeightWithSpacing >(*this,lib,"GetFrameHeightWithSpacing",SideEffects::worstDefault,"ImGui::GetFrameHeightWithSpacing");
	addExtern< void (*)(const char *) , ImGui::PushID >(*this,lib,"PushID",SideEffects::worstDefault,"ImGui::PushID")
		->args({"str_id"});
	addExtern< void (*)(const char *,const char *) , ImGui::PushID >(*this,lib,"PushID",SideEffects::worstDefault,"ImGui::PushID")
		->args({"str_id_begin","str_id_end"});
	addExtern< void (*)(const void *) , ImGui::PushID >(*this,lib,"PushID",SideEffects::worstDefault,"ImGui::PushID")
		->args({"ptr_id"});
	addExtern< void (*)(int) , ImGui::PushID >(*this,lib,"PushID",SideEffects::worstDefault,"ImGui::PushID")
		->args({"int_id"});
	addExtern< void (*)() , ImGui::PopID >(*this,lib,"PopID",SideEffects::worstDefault,"ImGui::PopID");
	addExtern< unsigned int (*)(const char *) , ImGui::GetID >(*this,lib,"GetID",SideEffects::worstDefault,"ImGui::GetID")
		->args({"str_id"});
	addExtern< unsigned int (*)(const char *,const char *) , ImGui::GetID >(*this,lib,"GetID",SideEffects::worstDefault,"ImGui::GetID")
		->args({"str_id_begin","str_id_end"});
}
}

