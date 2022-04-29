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
void Module_dasIMGUI::initFunctions_17() {
	addExtern< int (*)() , ImGui::GetMouseCursor >(*this,lib,"GetMouseCursor",SideEffects::worstDefault,"ImGui::GetMouseCursor")
		->res_type(makeType<ImGuiMouseCursor_>(lib));
	addExtern< void (*)(int) , ImGui::SetMouseCursor >(*this,lib,"SetMouseCursor",SideEffects::worstDefault,"ImGui::SetMouseCursor")
		->args({"cursor_type"})
		->arg_type(0,makeType<ImGuiMouseCursor_>(lib));
	addExtern< void (*)(bool) , ImGui::CaptureMouseFromApp >(*this,lib,"CaptureMouseFromApp",SideEffects::worstDefault,"ImGui::CaptureMouseFromApp")
		->args({"want_capture_mouse_value"})
		->arg_init(0,make_smart<ExprConstBool>(true));
	addExtern< const char * (*)() , ImGui::GetClipboardText >(*this,lib,"GetClipboardText",SideEffects::worstDefault,"ImGui::GetClipboardText");
	addExtern< void (*)(const char *) , ImGui::SetClipboardText >(*this,lib,"SetClipboardText",SideEffects::worstDefault,"ImGui::SetClipboardText")
		->args({"text"});
	addExtern< void (*)(const char *) , ImGui::LoadIniSettingsFromDisk >(*this,lib,"LoadIniSettingsFromDisk",SideEffects::worstDefault,"ImGui::LoadIniSettingsFromDisk")
		->args({"ini_filename"});
	addExtern< void (*)(const char *,size_t) , ImGui::LoadIniSettingsFromMemory >(*this,lib,"LoadIniSettingsFromMemory",SideEffects::worstDefault,"ImGui::LoadIniSettingsFromMemory")
		->args({"ini_data","ini_size"})
		->arg_init(1,make_smart<ExprConstUInt64>(0x0));
	addExtern< void (*)(const char *) , ImGui::SaveIniSettingsToDisk >(*this,lib,"SaveIniSettingsToDisk",SideEffects::worstDefault,"ImGui::SaveIniSettingsToDisk")
		->args({"ini_filename"});
	addExtern< const char * (*)(size_t *) , ImGui::SaveIniSettingsToMemory >(*this,lib,"SaveIniSettingsToMemory",SideEffects::worstDefault,"ImGui::SaveIniSettingsToMemory")
		->args({"out_ini_size"})
		->arg_init(0,make_smart<ExprConstPtr>());
	addExtern< bool (*)(const char *,size_t,size_t,size_t,size_t,size_t,size_t) , ImGui::DebugCheckVersionAndDataLayout >(*this,lib,"DebugCheckVersionAndDataLayout",SideEffects::worstDefault,"ImGui::DebugCheckVersionAndDataLayout")
		->args({"version_str","sz_io","sz_style","sz_vec2","sz_vec4","sz_drawvert","sz_drawidx"});
	addExtern< void * (*)(size_t) , ImGui::MemAlloc >(*this,lib,"MemAlloc",SideEffects::worstDefault,"ImGui::MemAlloc")
		->args({"size"});
	addExtern< void (*)(void *) , ImGui::MemFree >(*this,lib,"MemFree",SideEffects::worstDefault,"ImGui::MemFree")
		->args({"ptr"});
	addCtorAndUsing<ImGuiStyle>(*this,lib,"ImGuiStyle","ImGuiStyle");
	using _method_1 = das::das_call_member< void (ImGuiStyle::*)(float),&ImGuiStyle::ScaleAllSizes >;
	addExtern<DAS_CALL_METHOD(_method_1)>(*this,lib,"ScaleAllSizes",SideEffects::worstDefault,"das_call_member< void (ImGuiStyle::*)(float) , &ImGuiStyle::ScaleAllSizes >::invoke")
		->args({"self","scale_factor"});
	using _method_2 = das::das_call_member< void (ImGuiIO::*)(unsigned int),&ImGuiIO::AddInputCharacter >;
	addExtern<DAS_CALL_METHOD(_method_2)>(*this,lib,"AddInputCharacter",SideEffects::worstDefault,"das_call_member< void (ImGuiIO::*)(unsigned int) , &ImGuiIO::AddInputCharacter >::invoke")
		->args({"self","c"});
	using _method_3 = das::das_call_member< void (ImGuiIO::*)(unsigned short),&ImGuiIO::AddInputCharacterUTF16 >;
	addExtern<DAS_CALL_METHOD(_method_3)>(*this,lib,"AddInputCharacterUTF16",SideEffects::worstDefault,"das_call_member< void (ImGuiIO::*)(unsigned short) , &ImGuiIO::AddInputCharacterUTF16 >::invoke")
		->args({"self","c"});
	using _method_4 = das::das_call_member< void (ImGuiIO::*)(const char *),&ImGuiIO::AddInputCharactersUTF8 >;
	addExtern<DAS_CALL_METHOD(_method_4)>(*this,lib,"AddInputCharactersUTF8",SideEffects::worstDefault,"das_call_member< void (ImGuiIO::*)(const char *) , &ImGuiIO::AddInputCharactersUTF8 >::invoke")
		->args({"self","str"});
	using _method_5 = das::das_call_member< void (ImGuiIO::*)(),&ImGuiIO::ClearInputCharacters >;
	addExtern<DAS_CALL_METHOD(_method_5)>(*this,lib,"ClearInputCharacters",SideEffects::worstDefault,"das_call_member< void (ImGuiIO::*)() , &ImGuiIO::ClearInputCharacters >::invoke")
		->args({"self"});
	addCtorAndUsing<ImGuiIO>(*this,lib,"ImGuiIO","ImGuiIO");
	addCtorAndUsing<ImGuiInputTextCallbackData>(*this,lib,"ImGuiInputTextCallbackData","ImGuiInputTextCallbackData");
}
}

