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
void Module_dasIMGUI::initFunctions_4() {
	addExtern< float (*)() , ImGui::GetScrollMaxY >(*this,lib,"GetScrollMaxY",SideEffects::worstDefault,"ImGui::GetScrollMaxY");
	addExtern< void (*)(float) , ImGui::SetScrollHereX >(*this,lib,"SetScrollHereX",SideEffects::worstDefault,"ImGui::SetScrollHereX")
		->args({"center_x_ratio"})
		->arg_init(0,make_smart<ExprConstFloat>(0.50000000000000000));
	addExtern< void (*)(float) , ImGui::SetScrollHereY >(*this,lib,"SetScrollHereY",SideEffects::worstDefault,"ImGui::SetScrollHereY")
		->args({"center_y_ratio"})
		->arg_init(0,make_smart<ExprConstFloat>(0.50000000000000000));
	addExtern< void (*)(float,float) , ImGui::SetScrollFromPosX >(*this,lib,"SetScrollFromPosX",SideEffects::worstDefault,"ImGui::SetScrollFromPosX")
		->args({"local_x","center_x_ratio"})
		->arg_init(1,make_smart<ExprConstFloat>(0.50000000000000000));
	addExtern< void (*)(float,float) , ImGui::SetScrollFromPosY >(*this,lib,"SetScrollFromPosY",SideEffects::worstDefault,"ImGui::SetScrollFromPosY")
		->args({"local_y","center_y_ratio"})
		->arg_init(1,make_smart<ExprConstFloat>(0.50000000000000000));
	addExtern< void (*)(ImFont *) , ImGui::PushFont >(*this,lib,"PushFont",SideEffects::worstDefault,"ImGui::PushFont")
		->args({"font"});
	addExtern< void (*)() , ImGui::PopFont >(*this,lib,"PopFont",SideEffects::worstDefault,"ImGui::PopFont");
	addExtern< void (*)(int,unsigned int) , ImGui::PushStyleColor >(*this,lib,"PushStyleColor",SideEffects::worstDefault,"ImGui::PushStyleColor")
		->args({"idx","col"})
		->arg_type(0,makeType<ImGuiCol_>(lib));
	addExtern< void (*)(int,const ImVec4 &) , ImGui::PushStyleColor >(*this,lib,"PushStyleColor",SideEffects::worstDefault,"ImGui::PushStyleColor")
		->args({"idx","col"})
		->arg_type(0,makeType<ImGuiCol_>(lib));
	addExtern< void (*)(int) , ImGui::PopStyleColor >(*this,lib,"PopStyleColor",SideEffects::worstDefault,"ImGui::PopStyleColor")
		->args({"count"})
		->arg_init(0,make_smart<ExprConstInt>(1));
	addExtern< void (*)(int,float) , ImGui::PushStyleVar >(*this,lib,"PushStyleVar",SideEffects::worstDefault,"ImGui::PushStyleVar")
		->args({"idx","val"})
		->arg_type(0,makeType<ImGuiStyleVar_>(lib));
	addExtern< void (*)(int,const ImVec2 &) , ImGui::PushStyleVar >(*this,lib,"PushStyleVar",SideEffects::worstDefault,"ImGui::PushStyleVar")
		->args({"idx","val"})
		->arg_type(0,makeType<ImGuiStyleVar_>(lib));
	addExtern< void (*)(int) , ImGui::PopStyleVar >(*this,lib,"PopStyleVar",SideEffects::worstDefault,"ImGui::PopStyleVar")
		->args({"count"})
		->arg_init(0,make_smart<ExprConstInt>(1));
	addExtern< void (*)(bool) , ImGui::PushAllowKeyboardFocus >(*this,lib,"PushAllowKeyboardFocus",SideEffects::worstDefault,"ImGui::PushAllowKeyboardFocus")
		->args({"allow_keyboard_focus"});
	addExtern< void (*)() , ImGui::PopAllowKeyboardFocus >(*this,lib,"PopAllowKeyboardFocus",SideEffects::worstDefault,"ImGui::PopAllowKeyboardFocus");
	addExtern< void (*)(bool) , ImGui::PushButtonRepeat >(*this,lib,"PushButtonRepeat",SideEffects::worstDefault,"ImGui::PushButtonRepeat")
		->args({"repeat"});
	addExtern< void (*)() , ImGui::PopButtonRepeat >(*this,lib,"PopButtonRepeat",SideEffects::worstDefault,"ImGui::PopButtonRepeat");
	addExtern< void (*)(float) , ImGui::PushItemWidth >(*this,lib,"PushItemWidth",SideEffects::worstDefault,"ImGui::PushItemWidth")
		->args({"item_width"});
	addExtern< void (*)() , ImGui::PopItemWidth >(*this,lib,"PopItemWidth",SideEffects::worstDefault,"ImGui::PopItemWidth");
	addExtern< void (*)(float) , ImGui::SetNextItemWidth >(*this,lib,"SetNextItemWidth",SideEffects::worstDefault,"ImGui::SetNextItemWidth")
		->args({"item_width"});
}
}

