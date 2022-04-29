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
void Module_dasIMGUI::initFunctions_12() {
	addExtern< bool (*)(const char *,int) , ImGui::IsPopupOpen >(*this,lib,"IsPopupOpen",SideEffects::worstDefault,"ImGui::IsPopupOpen")
		->args({"str_id","flags"})
		->arg_type(1,makeType<ImGuiPopupFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiPopupFlags_>(lib)));
	addExtern< bool (*)(const char *,int,int,const ImVec2 &,float) , ImGui::BeginTable >(*this,lib,"BeginTable",SideEffects::worstDefault,"ImGui::BeginTable")
		->args({"str_id","column","flags","outer_size","inner_width"})
		->arg_type(2,makeType<ImGuiTableFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTableFlags_>(lib)))
		->arg_init(4,make_smart<ExprConstFloat>(0.00000000000000000));
	addExtern< void (*)() , ImGui::EndTable >(*this,lib,"EndTable",SideEffects::worstDefault,"ImGui::EndTable");
	addExtern< void (*)(int,float) , ImGui::TableNextRow >(*this,lib,"TableNextRow",SideEffects::worstDefault,"ImGui::TableNextRow")
		->args({"row_flags","min_row_height"})
		->arg_type(0,makeType<ImGuiTableRowFlags_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTableRowFlags_>(lib)))
		->arg_init(1,make_smart<ExprConstFloat>(0.00000000000000000));
	addExtern< bool (*)() , ImGui::TableNextColumn >(*this,lib,"TableNextColumn",SideEffects::worstDefault,"ImGui::TableNextColumn");
	addExtern< bool (*)(int) , ImGui::TableSetColumnIndex >(*this,lib,"TableSetColumnIndex",SideEffects::worstDefault,"ImGui::TableSetColumnIndex")
		->args({"column_n"});
	addExtern< void (*)(const char *,int,float,unsigned int) , ImGui::TableSetupColumn >(*this,lib,"TableSetupColumn",SideEffects::worstDefault,"ImGui::TableSetupColumn")
		->args({"label","flags","init_width_or_weight","user_id"})
		->arg_type(1,makeType<ImGuiTableColumnFlags_>(lib))
		->arg_init(1,make_smart<ExprConstEnumeration>(0,makeType<ImGuiTableColumnFlags_>(lib)))
		->arg_init(2,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(3,make_smart<ExprConstUInt>(0x0));
	addExtern< void (*)(int,int) , ImGui::TableSetupScrollFreeze >(*this,lib,"TableSetupScrollFreeze",SideEffects::worstDefault,"ImGui::TableSetupScrollFreeze")
		->args({"cols","rows"});
	addExtern< void (*)() , ImGui::TableHeadersRow >(*this,lib,"TableHeadersRow",SideEffects::worstDefault,"ImGui::TableHeadersRow");
	addExtern< void (*)(const char *) , ImGui::TableHeader >(*this,lib,"TableHeader",SideEffects::worstDefault,"ImGui::TableHeader")
		->args({"label"});
	addExtern< ImGuiTableSortSpecs * (*)() , ImGui::TableGetSortSpecs >(*this,lib,"TableGetSortSpecs",SideEffects::worstDefault,"ImGui::TableGetSortSpecs");
	addExtern< int (*)() , ImGui::TableGetColumnCount >(*this,lib,"TableGetColumnCount",SideEffects::worstDefault,"ImGui::TableGetColumnCount");
	addExtern< int (*)() , ImGui::TableGetColumnIndex >(*this,lib,"TableGetColumnIndex",SideEffects::worstDefault,"ImGui::TableGetColumnIndex");
	addExtern< int (*)() , ImGui::TableGetRowIndex >(*this,lib,"TableGetRowIndex",SideEffects::worstDefault,"ImGui::TableGetRowIndex");
	addExtern< const char * (*)(int) , ImGui::TableGetColumnName >(*this,lib,"TableGetColumnName",SideEffects::worstDefault,"ImGui::TableGetColumnName")
		->args({"column_n"})
		->arg_init(0,make_smart<ExprConstInt>(-1));
	addExtern< int (*)(int) , ImGui::TableGetColumnFlags >(*this,lib,"TableGetColumnFlags",SideEffects::worstDefault,"ImGui::TableGetColumnFlags")
		->args({"column_n"})
		->arg_init(0,make_smart<ExprConstInt>(-1))
		->res_type(makeType<ImGuiTableColumnFlags_>(lib));
	addExtern< void (*)(int,unsigned int,int) , ImGui::TableSetBgColor >(*this,lib,"TableSetBgColor",SideEffects::worstDefault,"ImGui::TableSetBgColor")
		->args({"target","color","column_n"})
		->arg_type(0,makeType<ImGuiTableBgTarget_>(lib))
		->arg_init(2,make_smart<ExprConstInt>(-1));
	addExtern< void (*)(int,const char *,bool) , ImGui::Columns >(*this,lib,"Columns",SideEffects::worstDefault,"ImGui::Columns")
		->args({"count","id","border"})
		->arg_init(0,make_smart<ExprConstInt>(1))
		->arg_init(1,make_smart<ExprConstString>(""))
		->arg_init(2,make_smart<ExprConstBool>(true));
	addExtern< void (*)() , ImGui::NextColumn >(*this,lib,"NextColumn",SideEffects::worstDefault,"ImGui::NextColumn");
	addExtern< int (*)() , ImGui::GetColumnIndex >(*this,lib,"GetColumnIndex",SideEffects::worstDefault,"ImGui::GetColumnIndex");
}
}

