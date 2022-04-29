// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasIMGUI_NODE_EDITOR.h"
#include "need_dasIMGUI_NODE_EDITOR.h"
namespace das {
#include "dasIMGUI_NODE_EDITOR.func.aot.decl.inc"
void Module_dasIMGUI_NODE_EDITOR::initFunctions_5() {
	addExtern< bool (*)() , ax::NodeEditor::AcceptCut >(*this,lib,"AcceptCut",SideEffects::worstDefault,"ax::NodeEditor::AcceptCut");
	addExtern< bool (*)() , ax::NodeEditor::AcceptCopy >(*this,lib,"AcceptCopy",SideEffects::worstDefault,"ax::NodeEditor::AcceptCopy");
	addExtern< bool (*)() , ax::NodeEditor::AcceptPaste >(*this,lib,"AcceptPaste",SideEffects::worstDefault,"ax::NodeEditor::AcceptPaste");
	addExtern< bool (*)() , ax::NodeEditor::AcceptDuplicate >(*this,lib,"AcceptDuplicate",SideEffects::worstDefault,"ax::NodeEditor::AcceptDuplicate");
	addExtern< bool (*)() , ax::NodeEditor::AcceptCreateNode >(*this,lib,"AcceptCreateNode",SideEffects::worstDefault,"ax::NodeEditor::AcceptCreateNode");
	addExtern< int (*)() , ax::NodeEditor::GetActionContextSize >(*this,lib,"GetActionContextSize",SideEffects::worstDefault,"ax::NodeEditor::GetActionContextSize");
	addExtern< int (*)(ax::NodeEditor::NodeId *,int) , ax::NodeEditor::GetActionContextNodes >(*this,lib,"GetActionContextNodes",SideEffects::worstDefault,"ax::NodeEditor::GetActionContextNodes")
		->args({"nodes","size"});
	addExtern< int (*)(ax::NodeEditor::LinkId *,int) , ax::NodeEditor::GetActionContextLinks >(*this,lib,"GetActionContextLinks",SideEffects::worstDefault,"ax::NodeEditor::GetActionContextLinks")
		->args({"links","size"});
	addExtern< void (*)() , ax::NodeEditor::EndShortcut >(*this,lib,"EndShortcut",SideEffects::worstDefault,"ax::NodeEditor::EndShortcut");
	addExtern< float (*)() , ax::NodeEditor::GetCurrentZoom >(*this,lib,"GetCurrentZoom",SideEffects::worstDefault,"ax::NodeEditor::GetCurrentZoom");
	addExtern< ax::NodeEditor::NodeId (*)() , ax::NodeEditor::GetDoubleClickedNode >(*this,lib,"GetDoubleClickedNode",SideEffects::worstDefault,"ax::NodeEditor::GetDoubleClickedNode");
	addExtern< ax::NodeEditor::PinId (*)() , ax::NodeEditor::GetDoubleClickedPin >(*this,lib,"GetDoubleClickedPin",SideEffects::worstDefault,"ax::NodeEditor::GetDoubleClickedPin");
	addExtern< ax::NodeEditor::LinkId (*)() , ax::NodeEditor::GetDoubleClickedLink >(*this,lib,"GetDoubleClickedLink",SideEffects::worstDefault,"ax::NodeEditor::GetDoubleClickedLink");
	addExtern< bool (*)() , ax::NodeEditor::IsBackgroundClicked >(*this,lib,"IsBackgroundClicked",SideEffects::worstDefault,"ax::NodeEditor::IsBackgroundClicked");
	addExtern< bool (*)() , ax::NodeEditor::IsBackgroundDoubleClicked >(*this,lib,"IsBackgroundDoubleClicked",SideEffects::worstDefault,"ax::NodeEditor::IsBackgroundDoubleClicked");
	addExtern< bool (*)(ax::NodeEditor::PinId) , ax::NodeEditor::PinHadAnyLinks >(*this,lib,"PinHadAnyLinks",SideEffects::worstDefault,"ax::NodeEditor::PinHadAnyLinks")
		->args({"pinId"});
	addExtern< ImVec2 (*)() , ax::NodeEditor::GetScreenSize >(*this,lib,"GetScreenSize",SideEffects::worstDefault,"ax::NodeEditor::GetScreenSize");
	addExtern< ImVec2 (*)(const ImVec2 &) , ax::NodeEditor::ScreenToCanvas >(*this,lib,"ScreenToCanvas",SideEffects::worstDefault,"ax::NodeEditor::ScreenToCanvas")
		->args({"pos"});
	addExtern< ImVec2 (*)(const ImVec2 &) , ax::NodeEditor::CanvasToScreen >(*this,lib,"CanvasToScreen",SideEffects::worstDefault,"ax::NodeEditor::CanvasToScreen")
		->args({"pos"});
}
}

