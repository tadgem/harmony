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
void Module_dasIMGUI::initFunctions_13() {
	addExtern< float (*)(int) , ImGui::GetColumnWidth >(*this,lib,"GetColumnWidth",SideEffects::worstDefault,"ImGui::GetColumnWidth")
		->args({"column_index"})
		->arg_init(0,make_smart<ExprConstInt>(-1));
	addExtern< void (*)(int,float) , ImGui::SetColumnWidth >(*this,lib,"SetColumnWidth",SideEffects::worstDefault,"ImGui::SetColumnWidth")
		->args({"column_index","width"});
	addExtern< float (*)(int) , ImGui::GetColumnOffset >(*this,lib,"GetColumnOffset",SideEffects::worstDefault,"ImGui::GetColumnOffset")
		->args({"column_index"})
		->arg_init(0,make_smart<ExprConstInt>(-1));
	addExtern< void (*)(int,float) , ImGui::SetColumnOffset >(*this,lib,"SetColumnOffset",SideEffects::worstDefault,"ImGui::SetColumnOffset")
		->args({"column_index","offset_x"});
	addExtern< int (*)() , ImGui::GetColumnsCount >(*this,lib,"GetColumnsCount",SideEffects::worstDefault,"ImGui::GetColumnsCount");
	addExtern< bool (*)(const char *,int) , ImGui::BeginTabBar >(*this,lib,"BeginTabBar",SideEffects::worstDefault,"ImGui::BeginTabBar")
		->args({"str_id","flags"})
		->arg_type(1,makeType<ImGuiTabBarFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTabBarFlags_>(lib)));
	addExtern< void (*)() , ImGui::EndTabBar >(*this,lib,"EndTabBar",SideEffects::worstDefault,"ImGui::EndTabBar");
	addExtern< bool (*)(const char *,bool *,int) , ImGui::BeginTabItem >(*this,lib,"BeginTabItem",SideEffects::worstDefault,"ImGui::BeginTabItem")
		->args({"label","p_open","flags"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_type(2,makeType<ImGuiTabItemFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTabItemFlags_>(lib)));
	addExtern< void (*)() , ImGui::EndTabItem >(*this,lib,"EndTabItem",SideEffects::worstDefault,"ImGui::EndTabItem");
	addExtern< bool (*)(const char *,int) , ImGui::TabItemButton >(*this,lib,"TabItemButton",SideEffects::worstDefault,"ImGui::TabItemButton")
		->args({"label","flags"})
		->arg_type(1,makeType<ImGuiTabItemFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTabItemFlags_>(lib)));
	addExtern< void (*)(const char *) , ImGui::SetTabItemClosed >(*this,lib,"SetTabItemClosed",SideEffects::worstDefault,"ImGui::SetTabItemClosed")
		->args({"tab_or_docked_window_label"});
	addExtern< void (*)(int) , ImGui::LogToTTY >(*this,lib,"LogToTTY",SideEffects::worstDefault,"ImGui::LogToTTY")
		->args({"auto_open_depth"})
		->arg_init(0,make_smart<ExprConstInt>(-1));
	addExtern< void (*)(int,const char *) , ImGui::LogToFile >(*this,lib,"LogToFile",SideEffects::worstDefault,"ImGui::LogToFile")
		->args({"auto_open_depth","filename"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
		->arg_init(1,make_smart<ExprConstString>(""));
	addExtern< void (*)(int) , ImGui::LogToClipboard >(*this,lib,"LogToClipboard",SideEffects::worstDefault,"ImGui::LogToClipboard")
		->args({"auto_open_depth"})
		->arg_init(0,make_smart<ExprConstInt>(-1));
	addExtern< void (*)() , ImGui::LogFinish >(*this,lib,"LogFinish",SideEffects::worstDefault,"ImGui::LogFinish");
	addExtern< void (*)() , ImGui::LogButtons >(*this,lib,"LogButtons",SideEffects::worstDefault,"ImGui::LogButtons");
	addExtern< bool (*)(int) , ImGui::BeginDragDropSource >(*this,lib,"BeginDragDropSource",SideEffects::worstDefault,"ImGui::BeginDragDropSource")
		->args({"flags"})
		->arg_type(0,makeType<ImGuiDragDropFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiDragDropFlags_>(lib)));
	addExtern< bool (*)(const char *,const void *,size_t,int) , ImGui::SetDragDropPayload >(*this,lib,"SetDragDropPayload",SideEffects::worstDefault,"ImGui::SetDragDropPayload")
		->args({"type","data","sz","cond"})
		->arg_type(3,makeType<ImGuiCond_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiCond_>(lib)));
	addExtern< void (*)() , ImGui::EndDragDropSource >(*this,lib,"EndDragDropSource",SideEffects::worstDefault,"ImGui::EndDragDropSource");
	addExtern< bool (*)() , ImGui::BeginDragDropTarget >(*this,lib,"BeginDragDropTarget",SideEffects::worstDefault,"ImGui::BeginDragDropTarget");
}
}

