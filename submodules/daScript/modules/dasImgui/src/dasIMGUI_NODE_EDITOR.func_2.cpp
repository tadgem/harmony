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
void Module_dasIMGUI_NODE_EDITOR::initFunctions_2() {
	addExtern< void (*)(const ImVec2 &) , ax::NodeEditor::PinPivotSize >(*this,lib,"PinPivotSize",SideEffects::worstDefault,"ax::NodeEditor::PinPivotSize")
		->args({"size"});
	addExtern< void (*)(const ImVec2 &) , ax::NodeEditor::PinPivotScale >(*this,lib,"PinPivotScale",SideEffects::worstDefault,"ax::NodeEditor::PinPivotScale")
		->args({"scale"});
	addExtern< void (*)(const ImVec2 &) , ax::NodeEditor::PinPivotAlignment >(*this,lib,"PinPivotAlignment",SideEffects::worstDefault,"ax::NodeEditor::PinPivotAlignment")
		->args({"alignment"});
	addExtern< void (*)() , ax::NodeEditor::EndPin >(*this,lib,"EndPin",SideEffects::worstDefault,"ax::NodeEditor::EndPin");
	addExtern< void (*)(const ImVec2 &) , ax::NodeEditor::Group >(*this,lib,"Group",SideEffects::worstDefault,"ax::NodeEditor::Group")
		->args({"size"});
	addExtern< void (*)() , ax::NodeEditor::EndNode >(*this,lib,"EndNode",SideEffects::worstDefault,"ax::NodeEditor::EndNode");
	addExtern< bool (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::BeginGroupHint >(*this,lib,"BeginGroupHint",SideEffects::worstDefault,"ax::NodeEditor::BeginGroupHint")
		->args({"nodeId"});
	addExtern< ImVec2 (*)() , ax::NodeEditor::GetGroupMin >(*this,lib,"GetGroupMin",SideEffects::worstDefault,"ax::NodeEditor::GetGroupMin");
	addExtern< ImVec2 (*)() , ax::NodeEditor::GetGroupMax >(*this,lib,"GetGroupMax",SideEffects::worstDefault,"ax::NodeEditor::GetGroupMax");
	addExtern< ImDrawList * (*)() , ax::NodeEditor::GetHintForegroundDrawList >(*this,lib,"GetHintForegroundDrawList",SideEffects::worstDefault,"ax::NodeEditor::GetHintForegroundDrawList");
	addExtern< ImDrawList * (*)() , ax::NodeEditor::GetHintBackgroundDrawList >(*this,lib,"GetHintBackgroundDrawList",SideEffects::worstDefault,"ax::NodeEditor::GetHintBackgroundDrawList");
	addExtern< void (*)() , ax::NodeEditor::EndGroupHint >(*this,lib,"EndGroupHint",SideEffects::worstDefault,"ax::NodeEditor::EndGroupHint");
	addExtern< ImDrawList * (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::GetNodeBackgroundDrawList >(*this,lib,"GetNodeBackgroundDrawList",SideEffects::worstDefault,"ax::NodeEditor::GetNodeBackgroundDrawList")
		->args({"nodeId"});
	addExtern< bool (*)(ax::NodeEditor::LinkId,ax::NodeEditor::PinId,ax::NodeEditor::PinId,const ImVec4 &,float) , ax::NodeEditor::Link >(*this,lib,"Link",SideEffects::worstDefault,"ax::NodeEditor::Link")
		->args({"id","startPinId","endPinId","color","thickness"})
		->arg_init(4,make_smart<ExprConstFloat>(1.00000000000000000));
	addExtern< void (*)(ax::NodeEditor::LinkId) , ax::NodeEditor::Flow >(*this,lib,"Flow",SideEffects::worstDefault,"ax::NodeEditor::Flow")
		->args({"linkId"});
	addExtern< bool (*)(const ImVec4 &,float) , ax::NodeEditor::BeginCreate >(*this,lib,"BeginCreate",SideEffects::worstDefault,"ax::NodeEditor::BeginCreate")
		->args({"color","thickness"})
		->arg_init(1,make_smart<ExprConstFloat>(1.00000000000000000));
	addExtern< bool (*)(ax::NodeEditor::PinId *,ax::NodeEditor::PinId *) , ax::NodeEditor::QueryNewLink >(*this,lib,"QueryNewLink",SideEffects::worstDefault,"ax::NodeEditor::QueryNewLink")
		->args({"startId","endId"});
	addExtern< bool (*)(ax::NodeEditor::PinId *,ax::NodeEditor::PinId *,const ImVec4 &,float) , ax::NodeEditor::QueryNewLink >(*this,lib,"QueryNewLink",SideEffects::worstDefault,"ax::NodeEditor::QueryNewLink")
		->args({"startId","endId","color","thickness"})
		->arg_init(3,make_smart<ExprConstFloat>(1.00000000000000000));
	addExtern< bool (*)(ax::NodeEditor::PinId *) , ax::NodeEditor::QueryNewNode >(*this,lib,"QueryNewNode",SideEffects::worstDefault,"ax::NodeEditor::QueryNewNode")
		->args({"pinId"});
	addExtern< bool (*)(ax::NodeEditor::PinId *,const ImVec4 &,float) , ax::NodeEditor::QueryNewNode >(*this,lib,"QueryNewNode",SideEffects::worstDefault,"ax::NodeEditor::QueryNewNode")
		->args({"pinId","color","thickness"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000));
}
}

