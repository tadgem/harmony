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
void Module_dasIMGUI_NODE_EDITOR::initFunctions_4() {
	addExtern< bool (*)() , ax::NodeEditor::HasSelectionChanged >(*this,lib,"HasSelectionChanged",SideEffects::worstDefault,"ax::NodeEditor::HasSelectionChanged");
	addExtern< int (*)() , ax::NodeEditor::GetSelectedObjectCount >(*this,lib,"GetSelectedObjectCount",SideEffects::worstDefault,"ax::NodeEditor::GetSelectedObjectCount");
	addExtern< int (*)(ax::NodeEditor::NodeId *,int) , ax::NodeEditor::GetSelectedNodes >(*this,lib,"GetSelectedNodes",SideEffects::worstDefault,"ax::NodeEditor::GetSelectedNodes")
		->args({"nodes","size"});
	addExtern< int (*)(ax::NodeEditor::LinkId *,int) , ax::NodeEditor::GetSelectedLinks >(*this,lib,"GetSelectedLinks",SideEffects::worstDefault,"ax::NodeEditor::GetSelectedLinks")
		->args({"links","size"});
	addExtern< void (*)() , ax::NodeEditor::ClearSelection >(*this,lib,"ClearSelection",SideEffects::worstDefault,"ax::NodeEditor::ClearSelection");
	addExtern< void (*)(ax::NodeEditor::NodeId,bool) , ax::NodeEditor::SelectNode >(*this,lib,"SelectNode",SideEffects::worstDefault,"ax::NodeEditor::SelectNode")
		->args({"nodeId","append"})
		->arg_init(1,make_smart<ExprConstBool>(false));
	addExtern< void (*)(ax::NodeEditor::LinkId,bool) , ax::NodeEditor::SelectLink >(*this,lib,"SelectLink",SideEffects::worstDefault,"ax::NodeEditor::SelectLink")
		->args({"linkId","append"})
		->arg_init(1,make_smart<ExprConstBool>(false));
	addExtern< void (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::DeselectNode >(*this,lib,"DeselectNode",SideEffects::worstDefault,"ax::NodeEditor::DeselectNode")
		->args({"nodeId"});
	addExtern< void (*)(ax::NodeEditor::LinkId) , ax::NodeEditor::DeselectLink >(*this,lib,"DeselectLink",SideEffects::worstDefault,"ax::NodeEditor::DeselectLink")
		->args({"linkId"});
	addExtern< bool (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::DeleteNode >(*this,lib,"DeleteNode",SideEffects::worstDefault,"ax::NodeEditor::DeleteNode")
		->args({"nodeId"});
	addExtern< bool (*)(ax::NodeEditor::LinkId) , ax::NodeEditor::DeleteLink >(*this,lib,"DeleteLink",SideEffects::worstDefault,"ax::NodeEditor::DeleteLink")
		->args({"linkId"});
	addExtern< void (*)(float) , ax::NodeEditor::NavigateToContent >(*this,lib,"NavigateToContent",SideEffects::worstDefault,"ax::NodeEditor::NavigateToContent")
		->args({"duration"})
		->arg_init(0,make_smart<ExprConstFloat>(-1.00000000000000000));
	addExtern< void (*)(bool,float) , ax::NodeEditor::NavigateToSelection >(*this,lib,"NavigateToSelection",SideEffects::worstDefault,"ax::NodeEditor::NavigateToSelection")
		->args({"zoomIn","duration"})
		->arg_init(0,make_smart<ExprConstBool>(false))
		->arg_init(1,make_smart<ExprConstFloat>(-1.00000000000000000));
	addExtern< bool (*)(ax::NodeEditor::NodeId *) , ax::NodeEditor::ShowNodeContextMenu >(*this,lib,"ShowNodeContextMenu",SideEffects::worstDefault,"ax::NodeEditor::ShowNodeContextMenu")
		->args({"nodeId"});
	addExtern< bool (*)(ax::NodeEditor::PinId *) , ax::NodeEditor::ShowPinContextMenu >(*this,lib,"ShowPinContextMenu",SideEffects::worstDefault,"ax::NodeEditor::ShowPinContextMenu")
		->args({"pinId"});
	addExtern< bool (*)(ax::NodeEditor::LinkId *) , ax::NodeEditor::ShowLinkContextMenu >(*this,lib,"ShowLinkContextMenu",SideEffects::worstDefault,"ax::NodeEditor::ShowLinkContextMenu")
		->args({"linkId"});
	addExtern< bool (*)() , ax::NodeEditor::ShowBackgroundContextMenu >(*this,lib,"ShowBackgroundContextMenu",SideEffects::worstDefault,"ax::NodeEditor::ShowBackgroundContextMenu");
	addExtern< void (*)(bool) , ax::NodeEditor::EnableShortcuts >(*this,lib,"EnableShortcuts",SideEffects::worstDefault,"ax::NodeEditor::EnableShortcuts")
		->args({"enable"});
	addExtern< bool (*)() , ax::NodeEditor::AreShortcutsEnabled >(*this,lib,"AreShortcutsEnabled",SideEffects::worstDefault,"ax::NodeEditor::AreShortcutsEnabled");
	addExtern< bool (*)() , ax::NodeEditor::BeginShortcut >(*this,lib,"BeginShortcut",SideEffects::worstDefault,"ax::NodeEditor::BeginShortcut");
}
}

