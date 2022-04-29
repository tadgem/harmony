// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasIMNODES.h"
#include "need_dasIMNODES.h"
namespace das {
#include "dasIMNODES.func.aot.decl.inc"
void Module_dasIMNODES::initFunctions_1() {
	addCtorAndUsing<imnodes::IO::EmulateThreeButtonMouse>(*this,lib,"EmulateThreeButtonMouse","imnodes::IO::EmulateThreeButtonMouse");
	addCtorAndUsing<imnodes::IO::LinkDetachWithModifierClick>(*this,lib,"LinkDetachWithModifierClick","imnodes::IO::LinkDetachWithModifierClick");
	addCtorAndUsing<imnodes::IO>(*this,lib,"IO","imnodes::IO");
	addCtorAndUsing<imnodes::Style>(*this,lib,"Style","imnodes::Style");
	addExtern< void (*)(ImGuiContext *) , imnodes::SetImGuiContext >(*this,lib,"SetImGuiContext",SideEffects::worstDefault,"imnodes::SetImGuiContext")
		->args({"ctx"});
	addExtern< imnodes::Context * (*)() , imnodes::CreateContext >(*this,lib,"CreateContext",SideEffects::worstDefault,"imnodes::CreateContext");
	addExtern< void (*)(imnodes::Context *) , imnodes::DestroyContext >(*this,lib,"DestroyContext",SideEffects::worstDefault,"imnodes::DestroyContext")
		->args({"ctx"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< imnodes::Context * (*)() , imnodes::GetCurrentContext >(*this,lib,"GetCurrentContext",SideEffects::worstDefault,"imnodes::GetCurrentContext");
	addExtern< void (*)(imnodes::Context *) , imnodes::SetCurrentContext >(*this,lib,"SetCurrentContext",SideEffects::worstDefault,"imnodes::SetCurrentContext")
		->args({"ctx"});
	addExtern< imnodes::EditorContext * (*)() , imnodes::EditorContextCreate >(*this,lib,"EditorContextCreate",SideEffects::worstDefault,"imnodes::EditorContextCreate");
	addExtern< void (*)(imnodes::EditorContext *) , imnodes::EditorContextFree >(*this,lib,"EditorContextFree",SideEffects::worstDefault,"imnodes::EditorContextFree")
		->args({""});
	addExtern< void (*)(imnodes::EditorContext *) , imnodes::EditorContextSet >(*this,lib,"EditorContextSet",SideEffects::worstDefault,"imnodes::EditorContextSet")
		->args({""});
	addExtern< ImVec2 (*)() , imnodes::EditorContextGetPanning >(*this,lib,"EditorContextGetPanning",SideEffects::worstDefault,"imnodes::EditorContextGetPanning");
	addExtern< void (*)(const ImVec2 &) , imnodes::EditorContextResetPanning >(*this,lib,"EditorContextResetPanning",SideEffects::worstDefault,"imnodes::EditorContextResetPanning")
		->args({"pos"});
	addExtern< void (*)(const int) , imnodes::EditorContextMoveToNode >(*this,lib,"EditorContextMoveToNode",SideEffects::worstDefault,"imnodes::EditorContextMoveToNode")
		->args({"node_id"});
	addExtern< imnodes::IO & (*)() , imnodes::GetIO , SimNode_ExtFuncCallRef>(*this,lib,"GetIO",SideEffects::worstDefault,"imnodes::GetIO");
	addExtern< imnodes::Style & (*)() , imnodes::GetStyle , SimNode_ExtFuncCallRef>(*this,lib,"GetStyle",SideEffects::worstDefault,"imnodes::GetStyle");
	addExtern< void (*)() , imnodes::StyleColorsDark >(*this,lib,"StyleColorsDark",SideEffects::worstDefault,"imnodes::StyleColorsDark");
	addExtern< void (*)() , imnodes::StyleColorsClassic >(*this,lib,"StyleColorsClassic",SideEffects::worstDefault,"imnodes::StyleColorsClassic");
	addExtern< void (*)() , imnodes::StyleColorsLight >(*this,lib,"StyleColorsLight",SideEffects::worstDefault,"imnodes::StyleColorsLight");
}
}

