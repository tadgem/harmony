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
void Module_dasIMGUI::initFunctions_8() {
	addExtern< bool (*)(const char *,float [3],float,float,float,const char *,int) , ImGui::DragFloat3 >(*this,lib,"DragFloat3",SideEffects::worstDefault,"ImGui::DragFloat3")
		->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(3,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(4,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float [4],float,float,float,const char *,int) , ImGui::DragFloat4 >(*this,lib,"DragFloat4",SideEffects::worstDefault,"ImGui::DragFloat4")
		->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(3,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(4,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(5,make_smart<ExprConstString>("%.3f"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float *,float *,float,float,float,const char *,const char *,int) , ImGui::DragFloatRange2 >(*this,lib,"DragFloatRange2",SideEffects::worstDefault,"ImGui::DragFloatRange2")
		->args({"label","v_current_min","v_current_max","v_speed","v_min","v_max","format","format_max","flags"})
		->arg_init(3,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(4,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(5,make_smart<ExprConstFloat>(0.00000000000000000))
		->arg_init(6,make_smart<ExprConstString>("%.3f"))
		->arg_init(7,make_smart<ExprConstString>(""))
		->arg_type(8,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int *,float,int,int,const char *,int) , ImGui::DragInt >(*this,lib,"DragInt",SideEffects::worstDefault,"ImGui::DragInt")
		->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int [2],float,int,int,const char *,int) , ImGui::DragInt2 >(*this,lib,"DragInt2",SideEffects::worstDefault,"ImGui::DragInt2")
		->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int [3],float,int,int,const char *,int) , ImGui::DragInt3 >(*this,lib,"DragInt3",SideEffects::worstDefault,"ImGui::DragInt3")
		->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int [4],float,int,int,const char *,int) , ImGui::DragInt4 >(*this,lib,"DragInt4",SideEffects::worstDefault,"ImGui::DragInt4")
		->args({"label","v","v_speed","v_min","v_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstString>("%d"))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int *,int *,float,int,int,const char *,const char *,int) , ImGui::DragIntRange2 >(*this,lib,"DragIntRange2",SideEffects::worstDefault,"ImGui::DragIntRange2")
		->args({"label","v_current_min","v_current_max","v_speed","v_min","v_max","format","format_max","flags"})
		->arg_init(3,make_smart<ExprConstFloat>(1.00000000000000000))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstInt>(0))
		->arg_init(6,make_smart<ExprConstString>("%d"))
		->arg_init(7,make_smart<ExprConstString>(""))
		->arg_type(8,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int,void *,float,const void *,const void *,const char *,int) , ImGui::DragScalar >(*this,lib,"DragScalar",SideEffects::worstDefault,"ImGui::DragScalar")
		->args({"label","data_type","p_data","v_speed","p_min","p_max","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(4,make_smart<ExprConstPtr>())
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstString>(""))
		->arg_type(7,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(7,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int,void *,int,float,const void *,const void *,const char *,int) , ImGui::DragScalarN >(*this,lib,"DragScalarN",SideEffects::worstDefault,"ImGui::DragScalarN")
		->args({"label","data_type","p_data","components","v_speed","p_min","p_max","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(5,make_smart<ExprConstPtr>())
		->arg_init(6,make_smart<ExprConstPtr>())
		->arg_init(7,make_smart<ExprConstString>(""))
		->arg_type(8,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(8,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float *,float,float,const char *,int) , ImGui::SliderFloat >(*this,lib,"SliderFloat",SideEffects::worstDefault,"ImGui::SliderFloat")
		->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float [2],float,float,const char *,int) , ImGui::SliderFloat2 >(*this,lib,"SliderFloat2",SideEffects::worstDefault,"ImGui::SliderFloat2")
		->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float [3],float,float,const char *,int) , ImGui::SliderFloat3 >(*this,lib,"SliderFloat3",SideEffects::worstDefault,"ImGui::SliderFloat3")
		->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float [4],float,float,const char *,int) , ImGui::SliderFloat4 >(*this,lib,"SliderFloat4",SideEffects::worstDefault,"ImGui::SliderFloat4")
		->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%.3f"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,float *,float,float,const char *,int) , ImGui::SliderAngle >(*this,lib,"SliderAngle",SideEffects::worstDefault,"ImGui::SliderAngle")
		->args({"label","v_rad","v_degrees_min","v_degrees_max","format","flags"})
		->arg_init(2,make_smart<ExprConstFloat>(-360.00000000000000000))
		->arg_init(3,make_smart<ExprConstFloat>(360.00000000000000000))
		->arg_init(4,make_smart<ExprConstString>("%.0f deg"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int *,int,int,const char *,int) , ImGui::SliderInt >(*this,lib,"SliderInt",SideEffects::worstDefault,"ImGui::SliderInt")
		->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int [2],int,int,const char *,int) , ImGui::SliderInt2 >(*this,lib,"SliderInt2",SideEffects::worstDefault,"ImGui::SliderInt2")
		->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int [3],int,int,const char *,int) , ImGui::SliderInt3 >(*this,lib,"SliderInt3",SideEffects::worstDefault,"ImGui::SliderInt3")
		->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int [4],int,int,const char *,int) , ImGui::SliderInt4 >(*this,lib,"SliderInt4",SideEffects::worstDefault,"ImGui::SliderInt4")
		->args({"label","v","v_min","v_max","format","flags"})
		->arg_init(4,make_smart<ExprConstString>("%d"))
		->arg_type(5,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(5,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
	addExtern< bool (*)(const char *,int,void *,const void *,const void *,const char *,int) , ImGui::SliderScalar >(*this,lib,"SliderScalar",SideEffects::worstDefault,"ImGui::SliderScalar")
		->args({"label","data_type","p_data","p_min","p_max","format","flags"})
		->arg_type(1,makeType<ImGuiDataType_>(lib))
		->arg_init(5,make_smart<ExprConstString>(""))
		->arg_type(6,makeType<ImGuiSliderFlags_>(lib))
		->arg_init(6,make_smart<ExprConstEnumeration>(0,makeType<ImGuiSliderFlags_>(lib)));
}
}

