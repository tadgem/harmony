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
void Module_dasIMGUI_NODE_EDITOR::initFunctions_1() {
	addCtorAndUsing<ax::NodeEditor::Config>(*this,lib,"Config","ax::NodeEditor::Config");
	addCtorAndUsing<ax::NodeEditor::Style>(*this,lib,"Style","ax::NodeEditor::Style");
	addExtern< void (*)(ax::NodeEditor::EditorContext *) , ax::NodeEditor::SetCurrentEditor >(*this,lib,"SetCurrentEditor",SideEffects::worstDefault,"ax::NodeEditor::SetCurrentEditor")
		->args({"ctx"});
	addExtern< ax::NodeEditor::EditorContext * (*)() , ax::NodeEditor::GetCurrentEditor >(*this,lib,"GetCurrentEditor",SideEffects::worstDefault,"ax::NodeEditor::GetCurrentEditor");
	addExtern< ax::NodeEditor::EditorContext * (*)(const ax::NodeEditor::Config *) , ax::NodeEditor::CreateEditor >(*this,lib,"CreateEditor",SideEffects::worstDefault,"ax::NodeEditor::CreateEditor")
		->args({"config"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< void (*)(ax::NodeEditor::EditorContext *) , ax::NodeEditor::DestroyEditor >(*this,lib,"DestroyEditor",SideEffects::worstDefault,"ax::NodeEditor::DestroyEditor")
		->args({"ctx"});
	addExtern< ax::NodeEditor::Style & (*)() , ax::NodeEditor::GetStyle , SimNode_ExtFuncCallRef>(*this,lib,"GetStyle",SideEffects::worstDefault,"ax::NodeEditor::GetStyle");
	addExtern< const char * (*)(ax::NodeEditor::StyleColor) , ax::NodeEditor::GetStyleColorName >(*this,lib,"GetStyleColorName",SideEffects::worstDefault,"ax::NodeEditor::GetStyleColorName")
		->args({"colorIndex"});
	addExtern< void (*)(ax::NodeEditor::StyleColor,const ImVec4 &) , ax::NodeEditor::PushStyleColor >(*this,lib,"PushStyleColor",SideEffects::worstDefault,"ax::NodeEditor::PushStyleColor")
		->args({"colorIndex","color"});
	addExtern< void (*)(int) , ax::NodeEditor::PopStyleColor >(*this,lib,"PopStyleColor",SideEffects::worstDefault,"ax::NodeEditor::PopStyleColor")
		->args({"count"})
		->arg_init(0,make_smart<ExprConstInt>(1));
	addExtern< void (*)(ax::NodeEditor::StyleVar,float) , ax::NodeEditor::PushStyleVar >(*this,lib,"PushStyleVar",SideEffects::worstDefault,"ax::NodeEditor::PushStyleVar")
		->args({"varIndex","value"});
	addExtern< void (*)(ax::NodeEditor::StyleVar,const ImVec2 &) , ax::NodeEditor::PushStyleVar >(*this,lib,"PushStyleVar",SideEffects::worstDefault,"ax::NodeEditor::PushStyleVar")
		->args({"varIndex","value"});
	addExtern< void (*)(ax::NodeEditor::StyleVar,const ImVec4 &) , ax::NodeEditor::PushStyleVar >(*this,lib,"PushStyleVar",SideEffects::worstDefault,"ax::NodeEditor::PushStyleVar")
		->args({"varIndex","value"});
	addExtern< void (*)(int) , ax::NodeEditor::PopStyleVar >(*this,lib,"PopStyleVar",SideEffects::worstDefault,"ax::NodeEditor::PopStyleVar")
		->args({"count"})
		->arg_init(0,make_smart<ExprConstInt>(1));
	addExtern< void (*)(const char *,const ImVec2 &) , ax::NodeEditor::Begin >(*this,lib,"Begin",SideEffects::worstDefault,"ax::NodeEditor::Begin")
		->args({"id","size"});
	addExtern< void (*)() , ax::NodeEditor::End >(*this,lib,"End",SideEffects::worstDefault,"ax::NodeEditor::End");
	addExtern< void (*)(ax::NodeEditor::NodeId) , ax::NodeEditor::BeginNode >(*this,lib,"BeginNode",SideEffects::worstDefault,"ax::NodeEditor::BeginNode")
		->args({"id"});
	addExtern< void (*)(ax::NodeEditor::PinId,ax::NodeEditor::PinKind) , ax::NodeEditor::BeginPin >(*this,lib,"BeginPin",SideEffects::worstDefault,"ax::NodeEditor::BeginPin")
		->args({"id","kind"});
	addExtern< void (*)(const ImVec2 &,const ImVec2 &) , ax::NodeEditor::PinRect >(*this,lib,"PinRect",SideEffects::worstDefault,"ax::NodeEditor::PinRect")
		->args({"a","b"});
	addExtern< void (*)(const ImVec2 &,const ImVec2 &) , ax::NodeEditor::PinPivotRect >(*this,lib,"PinPivotRect",SideEffects::worstDefault,"ax::NodeEditor::PinPivotRect")
		->args({"a","b"});
}
}

