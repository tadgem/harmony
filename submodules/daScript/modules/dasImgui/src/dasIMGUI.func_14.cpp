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
void Module_dasIMGUI::initFunctions_14() {
	addExtern< const ImGuiPayload * (*)(const char *,int) , ImGui::AcceptDragDropPayload >(*this,lib,"AcceptDragDropPayload",SideEffects::worstDefault,"ImGui::AcceptDragDropPayload")
		->args({"type","flags"})
		->arg_type(1,makeType<ImGuiDragDropFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiDragDropFlags_>(lib)));
	addExtern< void (*)() , ImGui::EndDragDropTarget >(*this,lib,"EndDragDropTarget",SideEffects::worstDefault,"ImGui::EndDragDropTarget");
	addExtern< const ImGuiPayload * (*)() , ImGui::GetDragDropPayload >(*this,lib,"GetDragDropPayload",SideEffects::worstDefault,"ImGui::GetDragDropPayload");
	addExtern< void (*)(const ImVec2 &,const ImVec2 &,bool) , ImGui::PushClipRect >(*this,lib,"PushClipRect",SideEffects::worstDefault,"ImGui::PushClipRect")
		->args({"clip_rect_min","clip_rect_max","intersect_with_current_clip_rect"});
	addExtern< void (*)() , ImGui::PopClipRect >(*this,lib,"PopClipRect",SideEffects::worstDefault,"ImGui::PopClipRect");
	addExtern< void (*)() , ImGui::SetItemDefaultFocus >(*this,lib,"SetItemDefaultFocus",SideEffects::worstDefault,"ImGui::SetItemDefaultFocus");
	addExtern< void (*)(int) , ImGui::SetKeyboardFocusHere >(*this,lib,"SetKeyboardFocusHere",SideEffects::worstDefault,"ImGui::SetKeyboardFocusHere")
		->args({"offset"})
		->arg_init(0,make_smart<ExprConstInt>(0));
	addExtern< bool (*)(int) , ImGui::IsItemHovered >(*this,lib,"IsItemHovered",SideEffects::worstDefault,"ImGui::IsItemHovered")
		->args({"flags"})
		->arg_type(0,makeType<ImGuiHoveredFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiHoveredFlags_>(lib)));
	addExtern< bool (*)() , ImGui::IsItemActive >(*this,lib,"IsItemActive",SideEffects::worstDefault,"ImGui::IsItemActive");
	addExtern< bool (*)() , ImGui::IsItemFocused >(*this,lib,"IsItemFocused",SideEffects::worstDefault,"ImGui::IsItemFocused");
	addExtern< bool (*)(int) , ImGui::IsItemClicked >(*this,lib,"IsItemClicked",SideEffects::worstDefault,"ImGui::IsItemClicked")
		->args({"mouse_button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)));
	addExtern< bool (*)() , ImGui::IsItemVisible >(*this,lib,"IsItemVisible",SideEffects::worstDefault,"ImGui::IsItemVisible");
	addExtern< bool (*)() , ImGui::IsItemEdited >(*this,lib,"IsItemEdited",SideEffects::worstDefault,"ImGui::IsItemEdited");
	addExtern< bool (*)() , ImGui::IsItemActivated >(*this,lib,"IsItemActivated",SideEffects::worstDefault,"ImGui::IsItemActivated");
	addExtern< bool (*)() , ImGui::IsItemDeactivated >(*this,lib,"IsItemDeactivated",SideEffects::worstDefault,"ImGui::IsItemDeactivated");
	addExtern< bool (*)() , ImGui::IsItemDeactivatedAfterEdit >(*this,lib,"IsItemDeactivatedAfterEdit",SideEffects::worstDefault,"ImGui::IsItemDeactivatedAfterEdit");
	addExtern< bool (*)() , ImGui::IsItemToggledOpen >(*this,lib,"IsItemToggledOpen",SideEffects::worstDefault,"ImGui::IsItemToggledOpen");
	addExtern< bool (*)() , ImGui::IsAnyItemHovered >(*this,lib,"IsAnyItemHovered",SideEffects::worstDefault,"ImGui::IsAnyItemHovered");
	addExtern< bool (*)() , ImGui::IsAnyItemActive >(*this,lib,"IsAnyItemActive",SideEffects::worstDefault,"ImGui::IsAnyItemActive");
	addExtern< bool (*)() , ImGui::IsAnyItemFocused >(*this,lib,"IsAnyItemFocused",SideEffects::worstDefault,"ImGui::IsAnyItemFocused");
}
}

