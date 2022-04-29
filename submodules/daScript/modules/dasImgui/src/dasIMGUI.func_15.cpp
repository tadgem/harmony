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
void Module_dasIMGUI::initFunctions_15() {
	addExtern< ImVec2 (*)() , ImGui::GetItemRectMin >(*this,lib,"GetItemRectMin",SideEffects::worstDefault,"ImGui::GetItemRectMin");
	addExtern< ImVec2 (*)() , ImGui::GetItemRectMax >(*this,lib,"GetItemRectMax",SideEffects::worstDefault,"ImGui::GetItemRectMax");
	addExtern< ImVec2 (*)() , ImGui::GetItemRectSize >(*this,lib,"GetItemRectSize",SideEffects::worstDefault,"ImGui::GetItemRectSize");
	addExtern< void (*)() , ImGui::SetItemAllowOverlap >(*this,lib,"SetItemAllowOverlap",SideEffects::worstDefault,"ImGui::SetItemAllowOverlap");
	addExtern< ImGuiViewport * (*)() , ImGui::GetMainViewport >(*this,lib,"GetMainViewport",SideEffects::worstDefault,"ImGui::GetMainViewport");
	addExtern< bool (*)(const ImVec2 &) , ImGui::IsRectVisible >(*this,lib,"IsRectVisible",SideEffects::worstDefault,"ImGui::IsRectVisible")
		->args({"size"});
	addExtern< bool (*)(const ImVec2 &,const ImVec2 &) , ImGui::IsRectVisible >(*this,lib,"IsRectVisible",SideEffects::worstDefault,"ImGui::IsRectVisible")
		->args({"rect_min","rect_max"});
	addExtern< double (*)() , ImGui::GetTime >(*this,lib,"GetTime",SideEffects::worstDefault,"ImGui::GetTime");
	addExtern< int (*)() , ImGui::GetFrameCount >(*this,lib,"GetFrameCount",SideEffects::worstDefault,"ImGui::GetFrameCount");
	addExtern< ImDrawList * (*)() , ImGui::GetBackgroundDrawList >(*this,lib,"GetBackgroundDrawList",SideEffects::worstDefault,"ImGui::GetBackgroundDrawList");
	addExtern< ImDrawList * (*)() , ImGui::GetForegroundDrawList >(*this,lib,"GetForegroundDrawList",SideEffects::worstDefault,"ImGui::GetForegroundDrawList");
	addExtern< ImDrawListSharedData * (*)() , ImGui::GetDrawListSharedData >(*this,lib,"GetDrawListSharedData",SideEffects::worstDefault,"ImGui::GetDrawListSharedData");
	addExtern< const char * (*)(int) , ImGui::GetStyleColorName >(*this,lib,"GetStyleColorName",SideEffects::worstDefault,"ImGui::GetStyleColorName")
		->args({"idx"})
		->arg_type(0,makeType<ImGuiCol_>(lib));
	addExtern< void (*)(ImGuiStorage *) , ImGui::SetStateStorage >(*this,lib,"SetStateStorage",SideEffects::worstDefault,"ImGui::SetStateStorage")
		->args({"storage"});
	addExtern< ImGuiStorage * (*)() , ImGui::GetStateStorage >(*this,lib,"GetStateStorage",SideEffects::worstDefault,"ImGui::GetStateStorage");
	addExtern< void (*)(int,float,int *,int *) , ImGui::CalcListClipping >(*this,lib,"CalcListClipping",SideEffects::worstDefault,"ImGui::CalcListClipping")
		->args({"items_count","items_height","out_items_display_start","out_items_display_end"});
	addExtern< bool (*)(unsigned int,const ImVec2 &,int) , ImGui::BeginChildFrame >(*this,lib,"BeginChildFrame",SideEffects::worstDefault,"ImGui::BeginChildFrame")
		->args({"id","size","flags"})
		->arg_type(2,makeType<ImGuiWindowFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiWindowFlags_>(lib)));
	addExtern< void (*)() , ImGui::EndChildFrame >(*this,lib,"EndChildFrame",SideEffects::worstDefault,"ImGui::EndChildFrame");
	addExtern< ImVec4 (*)(unsigned int) , ImGui::ColorConvertU32ToFloat4 >(*this,lib,"ColorConvertU32ToFloat4",SideEffects::worstDefault,"ImGui::ColorConvertU32ToFloat4")
		->args({"in"});
	addExtern< unsigned int (*)(const ImVec4 &) , ImGui::ColorConvertFloat4ToU32 >(*this,lib,"ColorConvertFloat4ToU32",SideEffects::worstDefault,"ImGui::ColorConvertFloat4ToU32")
		->args({"in"});
}
}

