// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasXBYAK.h"
#include "need_dasXBYAK.h"
namespace das {
#include "dasXBYAK.func.aot.decl.inc"
void Module_dasXBYAK::initFunctions_12() {
	using _method_1057 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaddsubps >;
	addExtern<DAS_CALL_METHOD(_method_1057)>(*this,lib,"vaddsubps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaddsubps >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1058 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaesdec >;
	addExtern<DAS_CALL_METHOD(_method_1058)>(*this,lib,"vaesdec",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaesdec >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1059 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaesdeclast >;
	addExtern<DAS_CALL_METHOD(_method_1059)>(*this,lib,"vaesdeclast",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaesdeclast >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1060 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaesenc >;
	addExtern<DAS_CALL_METHOD(_method_1060)>(*this,lib,"vaesenc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaesenc >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1061 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaesenclast >;
	addExtern<DAS_CALL_METHOD(_method_1061)>(*this,lib,"vaesenclast",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaesenclast >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1062 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaesimc >;
	addExtern<DAS_CALL_METHOD(_method_1062)>(*this,lib,"vaesimc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaesimc >::invoke")
		->args({"self","xm","op"});
	using _method_1063 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vaeskeygenassist >;
	addExtern<DAS_CALL_METHOD(_method_1063)>(*this,lib,"vaeskeygenassist",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vaeskeygenassist >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1064 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vandnpd >;
	addExtern<DAS_CALL_METHOD(_method_1064)>(*this,lib,"vandnpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vandnpd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1065 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vandnps >;
	addExtern<DAS_CALL_METHOD(_method_1065)>(*this,lib,"vandnps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vandnps >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1066 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vandpd >;
	addExtern<DAS_CALL_METHOD(_method_1066)>(*this,lib,"vandpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vandpd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1067 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vandps >;
	addExtern<DAS_CALL_METHOD(_method_1067)>(*this,lib,"vandps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vandps >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1068 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vblendpd >;
	addExtern<DAS_CALL_METHOD(_method_1068)>(*this,lib,"vblendpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vblendpd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1069 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vblendps >;
	addExtern<DAS_CALL_METHOD(_method_1069)>(*this,lib,"vblendps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vblendps >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1070 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vblendvpd >;
	addExtern<DAS_CALL_METHOD(_method_1070)>(*this,lib,"vblendvpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vblendvpd >::invoke")
		->args({"self","x1","x2","op","x4"});
	using _method_1071 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vblendvps >;
	addExtern<DAS_CALL_METHOD(_method_1071)>(*this,lib,"vblendvps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vblendvps >::invoke")
		->args({"self","x1","x2","op","x4"});
	using _method_1072 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vbroadcastf128 >;
	addExtern<DAS_CALL_METHOD(_method_1072)>(*this,lib,"vbroadcastf128",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vbroadcastf128 >::invoke")
		->args({"self","y","addr"});
	using _method_1073 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vbroadcasti128 >;
	addExtern<DAS_CALL_METHOD(_method_1073)>(*this,lib,"vbroadcasti128",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vbroadcasti128 >::invoke")
		->args({"self","y","addr"});
	using _method_1074 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vbroadcastsd >;
	addExtern<DAS_CALL_METHOD(_method_1074)>(*this,lib,"vbroadcastsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vbroadcastsd >::invoke")
		->args({"self","y","op"});
	using _method_1075 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vbroadcastss >;
	addExtern<DAS_CALL_METHOD(_method_1075)>(*this,lib,"vbroadcastss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vbroadcastss >::invoke")
		->args({"self","x","op"});
	using _method_1076 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_ospd >;
	addExtern<DAS_CALL_METHOD(_method_1076)>(*this,lib,"vcmpeq_ospd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_ospd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1077 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_osps >;
	addExtern<DAS_CALL_METHOD(_method_1077)>(*this,lib,"vcmpeq_osps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_osps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1078 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_ossd >;
	addExtern<DAS_CALL_METHOD(_method_1078)>(*this,lib,"vcmpeq_ossd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_ossd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1079 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_osss >;
	addExtern<DAS_CALL_METHOD(_method_1079)>(*this,lib,"vcmpeq_osss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_osss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1080 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uqpd >;
	addExtern<DAS_CALL_METHOD(_method_1080)>(*this,lib,"vcmpeq_uqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1081 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uqps >;
	addExtern<DAS_CALL_METHOD(_method_1081)>(*this,lib,"vcmpeq_uqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1082 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uqsd >;
	addExtern<DAS_CALL_METHOD(_method_1082)>(*this,lib,"vcmpeq_uqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1083 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uqss >;
	addExtern<DAS_CALL_METHOD(_method_1083)>(*this,lib,"vcmpeq_uqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1084 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uspd >;
	addExtern<DAS_CALL_METHOD(_method_1084)>(*this,lib,"vcmpeq_uspd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uspd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1085 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_usps >;
	addExtern<DAS_CALL_METHOD(_method_1085)>(*this,lib,"vcmpeq_usps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_usps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1086 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_ussd >;
	addExtern<DAS_CALL_METHOD(_method_1086)>(*this,lib,"vcmpeq_ussd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_ussd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1087 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_usss >;
	addExtern<DAS_CALL_METHOD(_method_1087)>(*this,lib,"vcmpeq_usss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_usss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1088 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeqpd >;
	addExtern<DAS_CALL_METHOD(_method_1088)>(*this,lib,"vcmpeqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1089 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeqps >;
	addExtern<DAS_CALL_METHOD(_method_1089)>(*this,lib,"vcmpeqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1090 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeqsd >;
	addExtern<DAS_CALL_METHOD(_method_1090)>(*this,lib,"vcmpeqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1091 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeqss >;
	addExtern<DAS_CALL_METHOD(_method_1091)>(*this,lib,"vcmpeqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1092 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalse_ospd >;
	addExtern<DAS_CALL_METHOD(_method_1092)>(*this,lib,"vcmpfalse_ospd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalse_ospd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1093 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalse_osps >;
	addExtern<DAS_CALL_METHOD(_method_1093)>(*this,lib,"vcmpfalse_osps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalse_osps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1094 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalse_ossd >;
	addExtern<DAS_CALL_METHOD(_method_1094)>(*this,lib,"vcmpfalse_ossd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalse_ossd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1095 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalse_osss >;
	addExtern<DAS_CALL_METHOD(_method_1095)>(*this,lib,"vcmpfalse_osss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalse_osss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1096 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalsepd >;
	addExtern<DAS_CALL_METHOD(_method_1096)>(*this,lib,"vcmpfalsepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalsepd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1097 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalseps >;
	addExtern<DAS_CALL_METHOD(_method_1097)>(*this,lib,"vcmpfalseps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalseps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1098 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalsesd >;
	addExtern<DAS_CALL_METHOD(_method_1098)>(*this,lib,"vcmpfalsesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalsesd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1099 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalsess >;
	addExtern<DAS_CALL_METHOD(_method_1099)>(*this,lib,"vcmpfalsess",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalsess >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1100 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpge_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1100)>(*this,lib,"vcmpge_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpge_oqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1101 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpge_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1101)>(*this,lib,"vcmpge_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpge_oqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1102 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpge_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1102)>(*this,lib,"vcmpge_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpge_oqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1103 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpge_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1103)>(*this,lib,"vcmpge_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpge_oqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1104 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgepd >;
	addExtern<DAS_CALL_METHOD(_method_1104)>(*this,lib,"vcmpgepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgepd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1105 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgeps >;
	addExtern<DAS_CALL_METHOD(_method_1105)>(*this,lib,"vcmpgeps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgeps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1106 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgesd >;
	addExtern<DAS_CALL_METHOD(_method_1106)>(*this,lib,"vcmpgesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgesd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1107 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgess >;
	addExtern<DAS_CALL_METHOD(_method_1107)>(*this,lib,"vcmpgess",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgess >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1108 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgt_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1108)>(*this,lib,"vcmpgt_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgt_oqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1109 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgt_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1109)>(*this,lib,"vcmpgt_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgt_oqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1110 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgt_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1110)>(*this,lib,"vcmpgt_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgt_oqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1111 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgt_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1111)>(*this,lib,"vcmpgt_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgt_oqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1112 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgtpd >;
	addExtern<DAS_CALL_METHOD(_method_1112)>(*this,lib,"vcmpgtpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgtpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1113 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgtps >;
	addExtern<DAS_CALL_METHOD(_method_1113)>(*this,lib,"vcmpgtps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgtps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1114 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgtsd >;
	addExtern<DAS_CALL_METHOD(_method_1114)>(*this,lib,"vcmpgtsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgtsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1115 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgtss >;
	addExtern<DAS_CALL_METHOD(_method_1115)>(*this,lib,"vcmpgtss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgtss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1116 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmple_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1116)>(*this,lib,"vcmple_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmple_oqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1117 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmple_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1117)>(*this,lib,"vcmple_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmple_oqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1118 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmple_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1118)>(*this,lib,"vcmple_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmple_oqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1119 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmple_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1119)>(*this,lib,"vcmple_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmple_oqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1120 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplepd >;
	addExtern<DAS_CALL_METHOD(_method_1120)>(*this,lib,"vcmplepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplepd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1121 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpleps >;
	addExtern<DAS_CALL_METHOD(_method_1121)>(*this,lib,"vcmpleps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpleps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1122 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplesd >;
	addExtern<DAS_CALL_METHOD(_method_1122)>(*this,lib,"vcmplesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplesd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1123 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpless >;
	addExtern<DAS_CALL_METHOD(_method_1123)>(*this,lib,"vcmpless",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpless >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1124 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplt_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1124)>(*this,lib,"vcmplt_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplt_oqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1125 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplt_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1125)>(*this,lib,"vcmplt_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplt_oqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1126 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplt_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1126)>(*this,lib,"vcmplt_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplt_oqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1127 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplt_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1127)>(*this,lib,"vcmplt_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplt_oqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1128 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpltpd >;
	addExtern<DAS_CALL_METHOD(_method_1128)>(*this,lib,"vcmpltpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpltpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1129 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpltps >;
	addExtern<DAS_CALL_METHOD(_method_1129)>(*this,lib,"vcmpltps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpltps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1130 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpltsd >;
	addExtern<DAS_CALL_METHOD(_method_1130)>(*this,lib,"vcmpltsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpltsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1131 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpltss >;
	addExtern<DAS_CALL_METHOD(_method_1131)>(*this,lib,"vcmpltss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpltss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1132 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1132)>(*this,lib,"vcmpneq_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_oqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1133 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1133)>(*this,lib,"vcmpneq_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_oqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1134 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1134)>(*this,lib,"vcmpneq_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_oqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1135 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1135)>(*this,lib,"vcmpneq_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_oqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1136 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_ospd >;
	addExtern<DAS_CALL_METHOD(_method_1136)>(*this,lib,"vcmpneq_ospd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_ospd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1137 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_osps >;
	addExtern<DAS_CALL_METHOD(_method_1137)>(*this,lib,"vcmpneq_osps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_osps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1138 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_ossd >;
	addExtern<DAS_CALL_METHOD(_method_1138)>(*this,lib,"vcmpneq_ossd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_ossd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1139 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_osss >;
	addExtern<DAS_CALL_METHOD(_method_1139)>(*this,lib,"vcmpneq_osss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_osss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1140 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_uspd >;
	addExtern<DAS_CALL_METHOD(_method_1140)>(*this,lib,"vcmpneq_uspd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_uspd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1141 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_usps >;
	addExtern<DAS_CALL_METHOD(_method_1141)>(*this,lib,"vcmpneq_usps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_usps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1142 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_ussd >;
	addExtern<DAS_CALL_METHOD(_method_1142)>(*this,lib,"vcmpneq_ussd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_ussd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1143 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_usss >;
	addExtern<DAS_CALL_METHOD(_method_1143)>(*this,lib,"vcmpneq_usss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_usss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1144 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneqpd >;
	addExtern<DAS_CALL_METHOD(_method_1144)>(*this,lib,"vcmpneqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1145 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneqps >;
	addExtern<DAS_CALL_METHOD(_method_1145)>(*this,lib,"vcmpneqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1146 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneqsd >;
	addExtern<DAS_CALL_METHOD(_method_1146)>(*this,lib,"vcmpneqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1147 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneqss >;
	addExtern<DAS_CALL_METHOD(_method_1147)>(*this,lib,"vcmpneqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1148 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpnge_uqpd >;
	addExtern<DAS_CALL_METHOD(_method_1148)>(*this,lib,"vcmpnge_uqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpnge_uqpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1149 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpnge_uqps >;
	addExtern<DAS_CALL_METHOD(_method_1149)>(*this,lib,"vcmpnge_uqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpnge_uqps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1150 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpnge_uqsd >;
	addExtern<DAS_CALL_METHOD(_method_1150)>(*this,lib,"vcmpnge_uqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpnge_uqsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1151 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpnge_uqss >;
	addExtern<DAS_CALL_METHOD(_method_1151)>(*this,lib,"vcmpnge_uqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpnge_uqss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1152 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpngepd >;
	addExtern<DAS_CALL_METHOD(_method_1152)>(*this,lib,"vcmpngepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpngepd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1153 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpngeps >;
	addExtern<DAS_CALL_METHOD(_method_1153)>(*this,lib,"vcmpngeps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpngeps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1154 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpngesd >;
	addExtern<DAS_CALL_METHOD(_method_1154)>(*this,lib,"vcmpngesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpngesd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1155 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpngess >;
	addExtern<DAS_CALL_METHOD(_method_1155)>(*this,lib,"vcmpngess",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpngess >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1156 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpngt_uqpd >;
	addExtern<DAS_CALL_METHOD(_method_1156)>(*this,lib,"vcmpngt_uqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpngt_uqpd >::invoke")
		->args({"self","x1","x2","op"});
}
}

