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
void Module_dasXBYAK::initFunctions_16() {
	using _method_1457 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaxsd >;
	addExtern<DAS_CALL_METHOD(_method_1457)>(*this,lib,"vpmaxsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaxsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1458 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaxsw >;
	addExtern<DAS_CALL_METHOD(_method_1458)>(*this,lib,"vpmaxsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaxsw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1459 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaxub >;
	addExtern<DAS_CALL_METHOD(_method_1459)>(*this,lib,"vpmaxub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaxub >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1460 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaxud >;
	addExtern<DAS_CALL_METHOD(_method_1460)>(*this,lib,"vpmaxud",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaxud >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1461 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaxuw >;
	addExtern<DAS_CALL_METHOD(_method_1461)>(*this,lib,"vpmaxuw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaxuw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1462 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpminsb >;
	addExtern<DAS_CALL_METHOD(_method_1462)>(*this,lib,"vpminsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpminsb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1463 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpminsd >;
	addExtern<DAS_CALL_METHOD(_method_1463)>(*this,lib,"vpminsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpminsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1464 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpminsw >;
	addExtern<DAS_CALL_METHOD(_method_1464)>(*this,lib,"vpminsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpminsw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1465 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpminub >;
	addExtern<DAS_CALL_METHOD(_method_1465)>(*this,lib,"vpminub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpminub >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1466 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpminud >;
	addExtern<DAS_CALL_METHOD(_method_1466)>(*this,lib,"vpminud",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpminud >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1467 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpminuw >;
	addExtern<DAS_CALL_METHOD(_method_1467)>(*this,lib,"vpminuw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpminuw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1468 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovmskb >;
	addExtern<DAS_CALL_METHOD(_method_1468)>(*this,lib,"vpmovmskb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovmskb >::invoke")
		->args({"self","r","x"});
	using _method_1469 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovsxbd >;
	addExtern<DAS_CALL_METHOD(_method_1469)>(*this,lib,"vpmovsxbd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovsxbd >::invoke")
		->args({"self","xm","op"});
	using _method_1470 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovsxbq >;
	addExtern<DAS_CALL_METHOD(_method_1470)>(*this,lib,"vpmovsxbq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovsxbq >::invoke")
		->args({"self","xm","op"});
	using _method_1471 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovsxbw >;
	addExtern<DAS_CALL_METHOD(_method_1471)>(*this,lib,"vpmovsxbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovsxbw >::invoke")
		->args({"self","xm","op"});
	using _method_1472 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovsxdq >;
	addExtern<DAS_CALL_METHOD(_method_1472)>(*this,lib,"vpmovsxdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovsxdq >::invoke")
		->args({"self","xm","op"});
	using _method_1473 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovsxwd >;
	addExtern<DAS_CALL_METHOD(_method_1473)>(*this,lib,"vpmovsxwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovsxwd >::invoke")
		->args({"self","xm","op"});
	using _method_1474 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovsxwq >;
	addExtern<DAS_CALL_METHOD(_method_1474)>(*this,lib,"vpmovsxwq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovsxwq >::invoke")
		->args({"self","xm","op"});
	using _method_1475 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovzxbd >;
	addExtern<DAS_CALL_METHOD(_method_1475)>(*this,lib,"vpmovzxbd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovzxbd >::invoke")
		->args({"self","xm","op"});
	using _method_1476 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovzxbq >;
	addExtern<DAS_CALL_METHOD(_method_1476)>(*this,lib,"vpmovzxbq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovzxbq >::invoke")
		->args({"self","xm","op"});
	using _method_1477 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovzxbw >;
	addExtern<DAS_CALL_METHOD(_method_1477)>(*this,lib,"vpmovzxbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovzxbw >::invoke")
		->args({"self","xm","op"});
	using _method_1478 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovzxdq >;
	addExtern<DAS_CALL_METHOD(_method_1478)>(*this,lib,"vpmovzxdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovzxdq >::invoke")
		->args({"self","xm","op"});
	using _method_1479 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovzxwd >;
	addExtern<DAS_CALL_METHOD(_method_1479)>(*this,lib,"vpmovzxwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovzxwd >::invoke")
		->args({"self","xm","op"});
	using _method_1480 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmovzxwq >;
	addExtern<DAS_CALL_METHOD(_method_1480)>(*this,lib,"vpmovzxwq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmovzxwq >::invoke")
		->args({"self","xm","op"});
	using _method_1481 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmuldq >;
	addExtern<DAS_CALL_METHOD(_method_1481)>(*this,lib,"vpmuldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmuldq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1482 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmulhrsw >;
	addExtern<DAS_CALL_METHOD(_method_1482)>(*this,lib,"vpmulhrsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmulhrsw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1483 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmulhuw >;
	addExtern<DAS_CALL_METHOD(_method_1483)>(*this,lib,"vpmulhuw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmulhuw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1484 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmulhw >;
	addExtern<DAS_CALL_METHOD(_method_1484)>(*this,lib,"vpmulhw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmulhw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1485 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmulld >;
	addExtern<DAS_CALL_METHOD(_method_1485)>(*this,lib,"vpmulld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmulld >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1486 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmullw >;
	addExtern<DAS_CALL_METHOD(_method_1486)>(*this,lib,"vpmullw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmullw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1487 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmuludq >;
	addExtern<DAS_CALL_METHOD(_method_1487)>(*this,lib,"vpmuludq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmuludq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1488 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpor >;
	addExtern<DAS_CALL_METHOD(_method_1488)>(*this,lib,"vpor",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpor >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1489 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsadbw >;
	addExtern<DAS_CALL_METHOD(_method_1489)>(*this,lib,"vpsadbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsadbw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1490 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpshufb >;
	addExtern<DAS_CALL_METHOD(_method_1490)>(*this,lib,"vpshufb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpshufb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1491 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshufd >;
	addExtern<DAS_CALL_METHOD(_method_1491)>(*this,lib,"vpshufd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshufd >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1492 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshufhw >;
	addExtern<DAS_CALL_METHOD(_method_1492)>(*this,lib,"vpshufhw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshufhw >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1493 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshuflw >;
	addExtern<DAS_CALL_METHOD(_method_1493)>(*this,lib,"vpshuflw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshuflw >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1494 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsignb >;
	addExtern<DAS_CALL_METHOD(_method_1494)>(*this,lib,"vpsignb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsignb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1495 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsignd >;
	addExtern<DAS_CALL_METHOD(_method_1495)>(*this,lib,"vpsignd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsignd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1496 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsignw >;
	addExtern<DAS_CALL_METHOD(_method_1496)>(*this,lib,"vpsignw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsignw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1497 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpslld >;
	addExtern<DAS_CALL_METHOD(_method_1497)>(*this,lib,"vpslld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpslld >::invoke")
		->args({"self","x","op","imm"});
	using _method_1498 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpslld >;
	addExtern<DAS_CALL_METHOD(_method_1498)>(*this,lib,"vpslld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpslld >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1499 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpslldq >;
	addExtern<DAS_CALL_METHOD(_method_1499)>(*this,lib,"vpslldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpslldq >::invoke")
		->args({"self","x","op","imm"});
	using _method_1500 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsllq >;
	addExtern<DAS_CALL_METHOD(_method_1500)>(*this,lib,"vpsllq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsllq >::invoke")
		->args({"self","x","op","imm"});
	using _method_1501 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsllq >;
	addExtern<DAS_CALL_METHOD(_method_1501)>(*this,lib,"vpsllq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsllq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1502 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsllvd >;
	addExtern<DAS_CALL_METHOD(_method_1502)>(*this,lib,"vpsllvd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsllvd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1503 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsllvq >;
	addExtern<DAS_CALL_METHOD(_method_1503)>(*this,lib,"vpsllvq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsllvq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1504 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsllw >;
	addExtern<DAS_CALL_METHOD(_method_1504)>(*this,lib,"vpsllw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsllw >::invoke")
		->args({"self","x","op","imm"});
	using _method_1505 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsllw >;
	addExtern<DAS_CALL_METHOD(_method_1505)>(*this,lib,"vpsllw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsllw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1506 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsrad >;
	addExtern<DAS_CALL_METHOD(_method_1506)>(*this,lib,"vpsrad",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsrad >::invoke")
		->args({"self","x","op","imm"});
	using _method_1507 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsrad >;
	addExtern<DAS_CALL_METHOD(_method_1507)>(*this,lib,"vpsrad",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsrad >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1508 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsravd >;
	addExtern<DAS_CALL_METHOD(_method_1508)>(*this,lib,"vpsravd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsravd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1509 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsraw >;
	addExtern<DAS_CALL_METHOD(_method_1509)>(*this,lib,"vpsraw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsraw >::invoke")
		->args({"self","x","op","imm"});
	using _method_1510 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsraw >;
	addExtern<DAS_CALL_METHOD(_method_1510)>(*this,lib,"vpsraw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsraw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1511 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsrld >;
	addExtern<DAS_CALL_METHOD(_method_1511)>(*this,lib,"vpsrld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsrld >::invoke")
		->args({"self","x","op","imm"});
	using _method_1512 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsrld >;
	addExtern<DAS_CALL_METHOD(_method_1512)>(*this,lib,"vpsrld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsrld >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1513 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsrldq >;
	addExtern<DAS_CALL_METHOD(_method_1513)>(*this,lib,"vpsrldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsrldq >::invoke")
		->args({"self","x","op","imm"});
	using _method_1514 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsrlq >;
	addExtern<DAS_CALL_METHOD(_method_1514)>(*this,lib,"vpsrlq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsrlq >::invoke")
		->args({"self","x","op","imm"});
	using _method_1515 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsrlq >;
	addExtern<DAS_CALL_METHOD(_method_1515)>(*this,lib,"vpsrlq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsrlq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1516 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsrlvd >;
	addExtern<DAS_CALL_METHOD(_method_1516)>(*this,lib,"vpsrlvd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsrlvd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1517 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsrlvq >;
	addExtern<DAS_CALL_METHOD(_method_1517)>(*this,lib,"vpsrlvq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsrlvq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1518 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsrlw >;
	addExtern<DAS_CALL_METHOD(_method_1518)>(*this,lib,"vpsrlw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsrlw >::invoke")
		->args({"self","x","op","imm"});
	using _method_1519 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsrlw >;
	addExtern<DAS_CALL_METHOD(_method_1519)>(*this,lib,"vpsrlw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsrlw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1520 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsubb >;
	addExtern<DAS_CALL_METHOD(_method_1520)>(*this,lib,"vpsubb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsubb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1521 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsubd >;
	addExtern<DAS_CALL_METHOD(_method_1521)>(*this,lib,"vpsubd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsubd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1522 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsubq >;
	addExtern<DAS_CALL_METHOD(_method_1522)>(*this,lib,"vpsubq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsubq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1523 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsubsb >;
	addExtern<DAS_CALL_METHOD(_method_1523)>(*this,lib,"vpsubsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsubsb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1524 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsubsw >;
	addExtern<DAS_CALL_METHOD(_method_1524)>(*this,lib,"vpsubsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsubsw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1525 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsubusb >;
	addExtern<DAS_CALL_METHOD(_method_1525)>(*this,lib,"vpsubusb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsubusb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1526 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsubusw >;
	addExtern<DAS_CALL_METHOD(_method_1526)>(*this,lib,"vpsubusw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsubusw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1527 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsubw >;
	addExtern<DAS_CALL_METHOD(_method_1527)>(*this,lib,"vpsubw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsubw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1528 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptest >;
	addExtern<DAS_CALL_METHOD(_method_1528)>(*this,lib,"vptest",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptest >::invoke")
		->args({"self","xm","op"});
	using _method_1529 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpunpckhbw >;
	addExtern<DAS_CALL_METHOD(_method_1529)>(*this,lib,"vpunpckhbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpunpckhbw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1530 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpunpckhdq >;
	addExtern<DAS_CALL_METHOD(_method_1530)>(*this,lib,"vpunpckhdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpunpckhdq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1531 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpunpckhqdq >;
	addExtern<DAS_CALL_METHOD(_method_1531)>(*this,lib,"vpunpckhqdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpunpckhqdq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1532 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpunpckhwd >;
	addExtern<DAS_CALL_METHOD(_method_1532)>(*this,lib,"vpunpckhwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpunpckhwd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1533 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpunpcklbw >;
	addExtern<DAS_CALL_METHOD(_method_1533)>(*this,lib,"vpunpcklbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpunpcklbw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1534 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpunpckldq >;
	addExtern<DAS_CALL_METHOD(_method_1534)>(*this,lib,"vpunpckldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpunpckldq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1535 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpunpcklqdq >;
	addExtern<DAS_CALL_METHOD(_method_1535)>(*this,lib,"vpunpcklqdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpunpcklqdq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1536 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpunpcklwd >;
	addExtern<DAS_CALL_METHOD(_method_1536)>(*this,lib,"vpunpcklwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpunpcklwd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1537 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpxor >;
	addExtern<DAS_CALL_METHOD(_method_1537)>(*this,lib,"vpxor",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpxor >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1538 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcpps >;
	addExtern<DAS_CALL_METHOD(_method_1538)>(*this,lib,"vrcpps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcpps >::invoke")
		->args({"self","xm","op"});
	using _method_1539 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcpss >;
	addExtern<DAS_CALL_METHOD(_method_1539)>(*this,lib,"vrcpss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcpss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1540 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vroundpd >;
	addExtern<DAS_CALL_METHOD(_method_1540)>(*this,lib,"vroundpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vroundpd >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1541 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vroundps >;
	addExtern<DAS_CALL_METHOD(_method_1541)>(*this,lib,"vroundps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vroundps >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1542 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vroundsd >;
	addExtern<DAS_CALL_METHOD(_method_1542)>(*this,lib,"vroundsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vroundsd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1543 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vroundss >;
	addExtern<DAS_CALL_METHOD(_method_1543)>(*this,lib,"vroundss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vroundss >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1544 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrtps >;
	addExtern<DAS_CALL_METHOD(_method_1544)>(*this,lib,"vrsqrtps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrtps >::invoke")
		->args({"self","xm","op"});
	using _method_1545 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrtss >;
	addExtern<DAS_CALL_METHOD(_method_1545)>(*this,lib,"vrsqrtss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrtss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1546 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vshufpd >;
	addExtern<DAS_CALL_METHOD(_method_1546)>(*this,lib,"vshufpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vshufpd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1547 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vshufps >;
	addExtern<DAS_CALL_METHOD(_method_1547)>(*this,lib,"vshufps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vshufps >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1548 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsqrtpd >;
	addExtern<DAS_CALL_METHOD(_method_1548)>(*this,lib,"vsqrtpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsqrtpd >::invoke")
		->args({"self","xm","op"});
	using _method_1549 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsqrtps >;
	addExtern<DAS_CALL_METHOD(_method_1549)>(*this,lib,"vsqrtps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsqrtps >::invoke")
		->args({"self","xm","op"});
	using _method_1550 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsqrtsd >;
	addExtern<DAS_CALL_METHOD(_method_1550)>(*this,lib,"vsqrtsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsqrtsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1551 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsqrtss >;
	addExtern<DAS_CALL_METHOD(_method_1551)>(*this,lib,"vsqrtss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsqrtss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1552 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vstmxcsr >;
	addExtern<DAS_CALL_METHOD(_method_1552)>(*this,lib,"vstmxcsr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vstmxcsr >::invoke")
		->args({"self","addr"});
	using _method_1553 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsubpd >;
	addExtern<DAS_CALL_METHOD(_method_1553)>(*this,lib,"vsubpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsubpd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1554 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsubps >;
	addExtern<DAS_CALL_METHOD(_method_1554)>(*this,lib,"vsubps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsubps >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1555 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsubsd >;
	addExtern<DAS_CALL_METHOD(_method_1555)>(*this,lib,"vsubsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsubsd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1556 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsubss >;
	addExtern<DAS_CALL_METHOD(_method_1556)>(*this,lib,"vsubss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsubss >::invoke")
		->args({"self","xmm","op1","op2"});
}
}

