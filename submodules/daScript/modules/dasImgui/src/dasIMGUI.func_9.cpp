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
void Module_dasIMGUI::initFunctions_9() {
	addExtern< bool (*)(const char *,int,void *,int,const void *,const void *,const char *,int) , ImGui::SliderScalarN >(*this,lib,"SliderScalarN",SideEffects::worstDefault,"ImGui::SliderScalarN")
		->args({"label","data_type","p_data","components","p_min","p_max","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,const ImVec2 &,float *,float,float,const char *,int) , ImGui::VSliderFloat >(*this,lib,"VSliderFloat",SideEffects::worstDefault,"ImGui::VSliderFloat")
		->args({"label","size","v","v_min","v_max","format","flags"})
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,const ImVec2 &,int *,int,int,const char *,int) , ImGui::VSliderInt >(*this,lib,"VSliderInt",SideEffects::worstDefault,"ImGui::VSliderInt")
		->args({"label","size","v","v_min","v_max","format","flags"})
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,const ImVec2 &,int,void *,const void *,const void *,const char *,int) , ImGui::VSliderScalar >(*this,lib,"VSliderScalar",SideEffects::worstDefault,"ImGui::VSliderScalar")
		->args({"label","size","data_type","p_data","p_min","p_max","format","flags"})
		->arg_type(2,makeType<ImGuiDataType_>(lib))
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float *,float,float,const char *,int) , ImGui::InputFloat >(*this,lib,"InputFloat",SideEffects::worstDefault,"ImGui::InputFloat")
		->args({"label","v","step","step_fast","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(3,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,float [2],const char *,int) , ImGui::InputFloat2 >(*this,lib,"InputFloat2",SideEffects::worstDefault,"ImGui::InputFloat2")
		->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,float [3],const char *,int) , ImGui::InputFloat3 >(*this,lib,"InputFloat3",SideEffects::worstDefault,"ImGui::InputFloat3")
		->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,float [4],const char *,int) , ImGui::InputFloat4 >(*this,lib,"InputFloat4",SideEffects::worstDefault,"ImGui::InputFloat4")
		->args({"label","v","format","flags"})
		->arg_init(2,make_smart<ExprConstString>("%.3f"))
		->arg_type(3,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(3,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,int *,int,int,int) , ImGui::InputInt >(*this,lib,"InputInt",SideEffects::worstDefault,"ImGui::InputInt")
		->args({"label","v","step","step_fast","flags"})
		->arg_init(2,make_smart<ExprConstInt>(1))
		->arg_init(3,make_smart<ExprConstInt>(100))
		->arg_type(4,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(4,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,int [2],int) , ImGui::InputInt2 >(*this,lib,"InputInt2",SideEffects::worstDefault,"ImGui::InputInt2")
		->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,int [3],int) , ImGui::InputInt3 >(*this,lib,"InputInt3",SideEffects::worstDefault,"ImGui::InputInt3")
		->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,int [4],int) , ImGui::InputInt4 >(*this,lib,"InputInt4",SideEffects::worstDefault,"ImGui::InputInt4")
		->args({"label","v","flags"})
		->arg_type(2,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,double *,double,double,const char *,int) , ImGui::InputDouble >(*this,lib,"InputDouble",SideEffects::worstDefault,"ImGui::InputDouble")
		->args({"label","v","step","step_fast","format","flags"})
		->arg_init(2,make_smart<ExprConstDouble>(0.00000000000000000))
		->arg_init(3,make_smart<ExprConstDouble>(0.00000000000000000))
		->arg_init(4,make_smart<ExprConstString>("%.6f"))
		->arg_type(5,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,int,void *,const void *,const void *,const char *,int) , ImGui::InputScalar >(*this,lib,"InputScalar",SideEffects::worstDefault,"ImGui::InputScalar")
		->args({"label","data_type","p_data","p_step","p_step_fast","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(3,make_smart<ExprConstPtr>())
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_type(6,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,int,void *,int,const void *,const void *,const char *,int) , ImGui::InputScalarN >(*this,lib,"InputScalarN",SideEffects::worstDefault,"ImGui::InputScalarN")
		->args({"label","data_type","p_data","components","p_step","p_step_fast","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiInputTextFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiInputTextFlags_>(lib)));
	addExtern< bool (*)(const char *,float [3],int) , ImGui::ColorEdit3 >(*this,lib,"ColorEdit3",SideEffects::worstDefault,"ImGui::ColorEdit3")
		->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)));
	addExtern< bool (*)(const char *,float [4],int) , ImGui::ColorEdit4 >(*this,lib,"ColorEdit4",SideEffects::worstDefault,"ImGui::ColorEdit4")
		->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)));
	addExtern< bool (*)(const char *,float [3],int) , ImGui::ColorPicker3 >(*this,lib,"ColorPicker3",SideEffects::worstDefault,"ImGui::ColorPicker3")
		->args({"label","col","flags"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)));
	addExtern< bool (*)(const char *,float [4],int,const float *) , ImGui::ColorPicker4 >(*this,lib,"ColorPicker4",SideEffects::worstDefault,"ImGui::ColorPicker4")
		->args({"label","col","flags","ref_col"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)))
		->arg_init(3,make_smart<ExprConstPtr>());
	addExtern< bool (*)(const char *,const ImVec4 &,int,ImVec2) , ImGui::ColorButton >(*this,lib,"ColorButton",SideEffects::worstDefault,"ImGui::ColorButton")
		->args({"desc_id","col","flags","size"})
		->arg_type(2,makeType<ImGuiColorEditFlags_>(lib))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<ImGuiColorEditFlags_>(lib)));
}
}

