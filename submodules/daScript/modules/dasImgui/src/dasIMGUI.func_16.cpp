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
void Module_dasIMGUI::initFunctions_16() {
	addExtern< void (*)(float,float,float,float &,float &,float &) , ImGui::ColorConvertRGBtoHSV >(*this,lib,"ColorConvertRGBtoHSV",SideEffects::worstDefault,"ImGui::ColorConvertRGBtoHSV")
		->args({"r","g","b","out_h","out_s","out_v"});
	addExtern< void (*)(float,float,float,float &,float &,float &) , ImGui::ColorConvertHSVtoRGB >(*this,lib,"ColorConvertHSVtoRGB",SideEffects::worstDefault,"ImGui::ColorConvertHSVtoRGB")
		->args({"h","s","v","out_r","out_g","out_b"});
	addExtern< int (*)(int) , ImGui::GetKeyIndex >(*this,lib,"GetKeyIndex",SideEffects::worstDefault,"ImGui::GetKeyIndex")
		->args({"imgui_key"})
		->arg_type(0,makeType<ImGuiKey_>(lib));
	addExtern< bool (*)(int) , ImGui::IsKeyDown >(*this,lib,"IsKeyDown",SideEffects::worstDefault,"ImGui::IsKeyDown")
		->args({"user_key_index"});
	addExtern< bool (*)(int,bool) , ImGui::IsKeyPressed >(*this,lib,"IsKeyPressed",SideEffects::worstDefault,"ImGui::IsKeyPressed")
		->args({"user_key_index","repeat"})
		->arg_init(1,make_smart<ExprConstBool>(true));
	addExtern< bool (*)(int) , ImGui::IsKeyReleased >(*this,lib,"IsKeyReleased",SideEffects::worstDefault,"ImGui::IsKeyReleased")
		->args({"user_key_index"});
	addExtern< int (*)(int,float,float) , ImGui::GetKeyPressedAmount >(*this,lib,"GetKeyPressedAmount",SideEffects::worstDefault,"ImGui::GetKeyPressedAmount")
		->args({"key_index","repeat_delay","rate"});
	addExtern< void (*)(bool) , ImGui::CaptureKeyboardFromApp >(*this,lib,"CaptureKeyboardFromApp",SideEffects::worstDefault,"ImGui::CaptureKeyboardFromApp")
		->args({"want_capture_keyboard_value"})
		->arg_init(0,make_smart<ExprConstBool>(true));
	addExtern< bool (*)(int) , ImGui::IsMouseDown >(*this,lib,"IsMouseDown",SideEffects::worstDefault,"ImGui::IsMouseDown")
		->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib));
	addExtern< bool (*)(int,bool) , ImGui::IsMouseClicked >(*this,lib,"IsMouseClicked",SideEffects::worstDefault,"ImGui::IsMouseClicked")
		->args({"button","repeat"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(1,make_smart<ExprConstBool>(false));
	addExtern< bool (*)(int) , ImGui::IsMouseReleased >(*this,lib,"IsMouseReleased",SideEffects::worstDefault,"ImGui::IsMouseReleased")
		->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib));
	addExtern< bool (*)(int) , ImGui::IsMouseDoubleClicked >(*this,lib,"IsMouseDoubleClicked",SideEffects::worstDefault,"ImGui::IsMouseDoubleClicked")
		->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib));
	addExtern< bool (*)(const ImVec2 &,const ImVec2 &,bool) , ImGui::IsMouseHoveringRect >(*this,lib,"IsMouseHoveringRect",SideEffects::worstDefault,"ImGui::IsMouseHoveringRect")
		->args({"r_min","r_max","clip"})
		->arg_init(2,make_smart<ExprConstBool>(true));
	addExtern< bool (*)(const ImVec2 *) , ImGui::IsMousePosValid >(*this,lib,"IsMousePosValid",SideEffects::worstDefault,"ImGui::IsMousePosValid")
		->args({"mouse_pos"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< bool (*)() , ImGui::IsAnyMouseDown >(*this,lib,"IsAnyMouseDown",SideEffects::worstDefault,"ImGui::IsAnyMouseDown");
	addExtern< ImVec2 (*)() , ImGui::GetMousePos >(*this,lib,"GetMousePos",SideEffects::worstDefault,"ImGui::GetMousePos");
	addExtern< ImVec2 (*)() , ImGui::GetMousePosOnOpeningCurrentPopup >(*this,lib,"GetMousePosOnOpeningCurrentPopup",SideEffects::worstDefault,"ImGui::GetMousePosOnOpeningCurrentPopup");
	addExtern< bool (*)(int,float) , ImGui::IsMouseDragging >(*this,lib,"IsMouseDragging",SideEffects::worstDefault,"ImGui::IsMouseDragging")
		->args({"button","lock_threshold"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(1,make_smart<ExprConstFloat>(-1.00000000000000000));
	addExtern< ImVec2 (*)(int,float) , ImGui::GetMouseDragDelta >(*this,lib,"GetMouseDragDelta",SideEffects::worstDefault,"ImGui::GetMouseDragDelta")
		->args({"button","lock_threshold"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)))
		->arg_init(1,make_smart<ExprConstFloat>(-1.00000000000000000));
	addExtern< void (*)(int) , ImGui::ResetMouseDragDelta >(*this,lib,"ResetMouseDragDelta",SideEffects::worstDefault,"ImGui::ResetMouseDragDelta")
		->args({"button"})
		->arg_type(0,makeType<ImGuiMouseButton_>(lib))
		->arg_init(0,make_smart<ExprConstEnumeration>(0,makeType<ImGuiMouseButton_>(lib)));
}
}

