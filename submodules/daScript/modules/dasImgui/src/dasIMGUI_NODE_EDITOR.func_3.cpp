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
void Module_dasIMGUI_NODE_EDITOR::initFunctions_3() {
	addExtern< bool (*)() , ax::NodeEditor::AcceptNewItem >(*this,lib,"AcceptNewItem",SideEffects::worstDefault,"ax::NodeEditor::AcceptNewItem");
	addExtern< bool (*)(const ImVec4 &,float) , ax::NodeEditor::AcceptNewItem >(*this,lib,"AcceptNewItem",SideEffects::worstDefault,"ax::NodeEditor::AcceptNewItem")
		->args({"color","thickness"})
		->arg_init(1,make_smart<ExprConstFloat>(1.00000000000000000));
	addExtern< void (*)() , ax::NodeEditor::RejectNewItem >(*this,lib,"RejectNewItem",SideEffects::worstDefault,"ax::NodeEditor::RejectNewItem");
	addExtern< void (*)(const ImVec4 &,float) , ax::NodeEditor::RejectNewItem >(*this,lib,"RejectNewItem",SideEffects::worstDefault,"ax::NodeEditor::RejectNewItem")
		->args({"color","thickness"})
		->arg_init(1,make_smart<ExprConstFloat>(1.00000000000000000));
	addExtern< void (*)() , ax::NodeEditor::EndCreate >(*this,lib,"EndCreate",SideEffects::worstDefault,"ax::NodeEditor::EndCreate");
	addExtern< bool (*)() , ax::NodeEditor::BeginDelete >(*this,lib,"BeginDelete",SideEffects::worstDefault,"ax::NodeEditor::BeginDelete");
	addExtern< bool (*)(ax::NodeEditor::LinkId *,ax::NodeEditor::PinId *,ax::NodeEditor::PinId *) , ax::NodeEditor::QueryDeletedLink >(*this,lib,"QueryDeletedLink",SideEffects::worstDefault,"ax::NodeEditor::QueryDeletedLink")
		->args({"linkId","startId","endId"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_init(2,make_smart<ExprConstPtr>());
	addExtern< bool (*)(ax::NodeEditor::NodeId *) , ax::NodeEditor::QueryDeletedNode >(*this,lib,"QueryDeletedNode",SideEffects::worstDefault,"ax::NodeEditor::QueryDeletedNode")
		->args({"nodeId"});
	addExtern< bool (*)() , ax::NodeEditor::AcceptDeletedItem >(*this,lib,"AcceptDeletedItem",SideEffects::worstDefault,"ax::NodeEditor::AcceptDeletedItem");
	addExtern< void (*)() , ax::NodeEditor::RejectDeletedItem >(*this,lib,"RejectDeletedItem",SideEffects::worstDefault,"ax::NodeEditor::RejectDeletedItem");
	addExtern< void (*)() , ax::NodeEditor::EndDelete >(*this,lib,"EndDelete",SideEffects::worstDefault,"ax::NodeEditor::EndDelete");
	addExtern< void (*)(ax::NodeEditor::NodeId,const ImVec2 &) , ax::NodeEditor::SetNodePosition >(*this,lib,"SetNodePosition",SideEffects::worstDefault,"ax::NodeEditor::SetNodePosition")
		->args({"nodeId","editorPosition"});
	addExtern< ImVec2 (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::GetNodePosition >(*this,lib,"GetNodePosition",SideEffects::worstDefault,"ax::NodeEditor::GetNodePosition")
		->args({"nodeId"});
	addExtern< ImVec2 (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::GetNodeSize >(*this,lib,"GetNodeSize",SideEffects::worstDefault,"ax::NodeEditor::GetNodeSize")
		->args({"nodeId"});
	addExtern< void (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::CenterNodeOnScreen >(*this,lib,"CenterNodeOnScreen",SideEffects::worstDefault,"ax::NodeEditor::CenterNodeOnScreen")
		->args({"nodeId"});
	addExtern< void (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::RestoreNodeState >(*this,lib,"RestoreNodeState",SideEffects::worstDefault,"ax::NodeEditor::RestoreNodeState")
		->args({"nodeId"});
	addExtern< void (*)() , ax::NodeEditor::Suspend >(*this,lib,"Suspend",SideEffects::worstDefault,"ax::NodeEditor::Suspend");
	addExtern< void (*)() , ax::NodeEditor::Resume >(*this,lib,"Resume",SideEffects::worstDefault,"ax::NodeEditor::Resume");
	addExtern< bool (*)() , ax::NodeEditor::IsSuspended >(*this,lib,"IsSuspended",SideEffects::worstDefault,"ax::NodeEditor::IsSuspended");
	addExtern< bool (*)() , ax::NodeEditor::IsActive >(*this,lib,"IsActive",SideEffects::worstDefault,"ax::NodeEditor::IsActive");
}
}

