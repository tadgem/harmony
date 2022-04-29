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
void Module_dasIMNODES::initFunctions_3() {
	addExtern< void (*)(int,const bool) , imnodes::SetNodeDraggable >(*this,lib,"SetNodeDraggable",SideEffects::worstDefault,"imnodes::SetNodeDraggable")
		->args({"node_id","draggable"});
	addExtern< void (*)(int,const ImVec2 &) , imnodes::SetNodeScreenSpacePos >(*this,lib,"SetNodeScreenSpacePos",SideEffects::worstDefault,"imnodes::SetNodeScreenSpacePos")
		->args({"node_id","screen_space_pos"});
	addExtern< void (*)(int,const ImVec2 &) , imnodes::SetNodeEditorSpacePos >(*this,lib,"SetNodeEditorSpacePos",SideEffects::worstDefault,"imnodes::SetNodeEditorSpacePos")
		->args({"node_id","editor_space_pos"});
	addExtern< void (*)(int,const ImVec2 &) , imnodes::SetNodeGridSpacePos >(*this,lib,"SetNodeGridSpacePos",SideEffects::worstDefault,"imnodes::SetNodeGridSpacePos")
		->args({"node_id","grid_pos"});
	addExtern< ImVec2 (*)(const int) , imnodes::GetNodeScreenSpacePos >(*this,lib,"GetNodeScreenSpacePos",SideEffects::worstDefault,"imnodes::GetNodeScreenSpacePos")
		->args({"node_id"});
	addExtern< ImVec2 (*)(const int) , imnodes::GetNodeEditorSpacePos >(*this,lib,"GetNodeEditorSpacePos",SideEffects::worstDefault,"imnodes::GetNodeEditorSpacePos")
		->args({"node_id"});
	addExtern< ImVec2 (*)(const int) , imnodes::GetNodeGridSpacePos >(*this,lib,"GetNodeGridSpacePos",SideEffects::worstDefault,"imnodes::GetNodeGridSpacePos")
		->args({"node_id"});
	addExtern< bool (*)() , imnodes::IsEditorHovered >(*this,lib,"IsEditorHovered",SideEffects::worstDefault,"imnodes::IsEditorHovered");
	addExtern< bool (*)(int *) , imnodes::IsNodeHovered >(*this,lib,"IsNodeHovered",SideEffects::worstDefault,"imnodes::IsNodeHovered")
		->args({"node_id"});
	addExtern< bool (*)(int *) , imnodes::IsLinkHovered >(*this,lib,"IsLinkHovered",SideEffects::worstDefault,"imnodes::IsLinkHovered")
		->args({"link_id"});
	addExtern< bool (*)(int *) , imnodes::IsPinHovered >(*this,lib,"IsPinHovered",SideEffects::worstDefault,"imnodes::IsPinHovered")
		->args({"attribute_id"});
	addExtern< int (*)() , imnodes::NumSelectedNodes >(*this,lib,"NumSelectedNodes",SideEffects::worstDefault,"imnodes::NumSelectedNodes");
	addExtern< int (*)() , imnodes::NumSelectedLinks >(*this,lib,"NumSelectedLinks",SideEffects::worstDefault,"imnodes::NumSelectedLinks");
	addExtern< void (*)(int *) , imnodes::GetSelectedNodes >(*this,lib,"GetSelectedNodes",SideEffects::worstDefault,"imnodes::GetSelectedNodes")
		->args({"node_ids"});
	addExtern< void (*)(int *) , imnodes::GetSelectedLinks >(*this,lib,"GetSelectedLinks",SideEffects::worstDefault,"imnodes::GetSelectedLinks")
		->args({"link_ids"});
	addExtern< void (*)() , imnodes::ClearNodeSelection >(*this,lib,"ClearNodeSelection",SideEffects::worstDefault,"imnodes::ClearNodeSelection");
	addExtern< void (*)() , imnodes::ClearLinkSelection >(*this,lib,"ClearLinkSelection",SideEffects::worstDefault,"imnodes::ClearLinkSelection");
	addExtern< bool (*)() , imnodes::IsAttributeActive >(*this,lib,"IsAttributeActive",SideEffects::worstDefault,"imnodes::IsAttributeActive");
	addExtern< bool (*)(int *) , imnodes::IsAnyAttributeActive >(*this,lib,"IsAnyAttributeActive",SideEffects::worstDefault,"imnodes::IsAnyAttributeActive")
		->args({"attribute_id"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< bool (*)(int *) , imnodes::IsLinkStarted >(*this,lib,"IsLinkStarted",SideEffects::worstDefault,"imnodes::IsLinkStarted")
		->args({"started_at_attribute_id"});
}
}

