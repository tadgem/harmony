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
void Module_dasIMGUI::initFunctions_7() {
	addExtern< unsigned int (*)(const void *) , ImGui::GetID >(*this,lib,"GetID",SideEffects::worstDefault,"ImGui::GetID")
		->args({"ptr_id"});
	addExtern< bool (*)(const char *,const ImVec2 &) , ImGui::Button >(*this,lib,"Button",SideEffects::worstDefault,"ImGui::Button")
		->args({"label","size"});
	addExtern< bool (*)(const char *) , ImGui::SmallButton >(*this,lib,"SmallButton",SideEffects::worstDefault,"ImGui::SmallButton")
		->args({"label"});
	addExtern< bool (*)(const char *,const ImVec2 &,int) , ImGui::InvisibleButton >(*this,lib,"InvisibleButton",SideEffects::worstDefault,"ImGui::InvisibleButton")
		->args({"str_id","size","flags"})
		->arg_type(2,makeType<ImGuiButtonFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiButtonFlags_>(lib)));
	addExtern< bool (*)(const char *,int) , ImGui::ArrowButton >(*this,lib,"ArrowButton",SideEffects::worstDefault,"ImGui::ArrowButton")
		->args({"str_id","dir"})
		->arg_type(1,makeType<ImGuiDir_>(lib));
	addExtern< void (*)(void *,const ImVec2 &,const ImVec2 &,const ImVec2 &,const ImVec4 &,const ImVec4 &) , ImGui::Image >(*this,lib,"Image",SideEffects::worstDefault,"ImGui::Image")
		->args({"user_texture_id","size","uv0","uv1","tint_col","border_col"});
	addExtern< bool (*)(void *,const ImVec2 &,const ImVec2 &,const ImVec2 &,int,const ImVec4 &,const ImVec4 &) , ImGui::ImageButton >(*this,lib,"ImageButton",SideEffects::worstDefault,"ImGui::ImageButton")
		->args({"user_texture_id","size","uv0","uv1","frame_padding","bg_col","tint_col"})
		->arg_init(4,make_smart<ExprConstInt>(-1));
	addExtern< bool (*)(const char *,bool *) , ImGui::Checkbox >(*this,lib,"Checkbox",SideEffects::worstDefault,"ImGui::Checkbox")
		->args({"label","v"});
	addExtern< bool (*)(const char *,int *,int) , ImGui::CheckboxFlags >(*this,lib,"CheckboxFlags",SideEffects::worstDefault,"ImGui::CheckboxFlags")
		->args({"label","flags","flags_value"});
	addExtern< bool (*)(const char *,unsigned int *,unsigned int) , ImGui::CheckboxFlags >(*this,lib,"CheckboxFlags",SideEffects::worstDefault,"ImGui::CheckboxFlags")
		->args({"label","flags","flags_value"});
	addExtern< bool (*)(const char *,bool) , ImGui::RadioButton >(*this,lib,"RadioButton",SideEffects::worstDefault,"ImGui::RadioButton")
		->args({"label","active"});
	addExtern< bool (*)(const char *,int *,int) , ImGui::RadioButton >(*this,lib,"RadioButton",SideEffects::worstDefault,"ImGui::RadioButton")
		->args({"label","v","v_button"});
	addExtern< void (*)(float,const ImVec2 &,const char *) , ImGui::ProgressBar >(*this,lib,"ProgressBar",SideEffects::worstDefault,"ImGui::ProgressBar")
		->args({"fraction","size_arg","overlay"})
		->arg_init(2,make_smart<ExprConstString>(""));
	addExtern< void (*)() , ImGui::Bullet >(*this,lib,"Bullet",SideEffects::worstDefault,"ImGui::Bullet");
	addExtern< bool (*)(const char *,const char *,int) , ImGui::BeginCombo >(*this,lib,"BeginCombo",SideEffects::worstDefault,"ImGui::BeginCombo")
		->args({"label","preview_value","flags"})
		->arg_type(2,makeType<ImGuiComboFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiComboFlags_>(lib)));
	addExtern< void (*)() , ImGui::EndCombo >(*this,lib,"EndCombo",SideEffects::worstDefault,"ImGui::EndCombo");
	addExtern< bool (*)(const char *,int *,const char *const[],int,int) , ImGui::Combo >(*this,lib,"Combo",SideEffects::worstDefault,"ImGui::Combo")
		->args({"label","current_item","items","items_count","popup_max_height_in_items"})
		->arg_init(4,make_smart<ExprConstInt>(-1));
	addExtern< bool (*)(const char *,int *,const char *,int) , ImGui::Combo >(*this,lib,"Combo",SideEffects::worstDefault,"ImGui::Combo")
		->args({"label","current_item","items_separated_by_zeros","popup_max_height_in_items"})
		->arg_init(3,make_smart<ExprConstInt>(-1));
	addExtern< bool (*)(const char *,float *,float,float,float,const char *,int) , ImGui::DragFloat >(*this,lib,"DragFloat",SideEffects::worstDefault,"ImGui::DragFloat")
		->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(3,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(4,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float [2],float,float,float,const char *,int) , ImGui::DragFloat2 >(*this,lib,"DragFloat2",SideEffects::worstDefault,"ImGui::DragFloat2")
		->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(3,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(4,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
}
}

