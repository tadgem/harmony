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
void Module_dasXBYAK::initFunctions_5() {
	using _method_357 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cmpsb >;
	addExtern<DAS_CALL_METHOD(_method_357)>(*this,lib,"cmpsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cmpsb >::invoke")
		->args({"self"});
	using _method_358 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cmpsd >;
	addExtern<DAS_CALL_METHOD(_method_358)>(*this,lib,"cmpsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cmpsd >::invoke")
		->args({"self"});
	using _method_359 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::cmpsd >;
	addExtern<DAS_CALL_METHOD(_method_359)>(*this,lib,"cmpsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::cmpsd >::invoke")
		->args({"self","xmm","op","imm8"});
	using _method_360 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::cmpss >;
	addExtern<DAS_CALL_METHOD(_method_360)>(*this,lib,"cmpss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::cmpss >::invoke")
		->args({"self","xmm","op","imm8"});
	using _method_361 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cmpsw >;
	addExtern<DAS_CALL_METHOD(_method_361)>(*this,lib,"cmpsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cmpsw >::invoke")
		->args({"self"});
	using _method_362 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpunordpd >;
	addExtern<DAS_CALL_METHOD(_method_362)>(*this,lib,"cmpunordpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpunordpd >::invoke")
		->args({"self","x","op"});
	using _method_363 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpunordps >;
	addExtern<DAS_CALL_METHOD(_method_363)>(*this,lib,"cmpunordps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpunordps >::invoke")
		->args({"self","x","op"});
	using _method_364 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpunordsd >;
	addExtern<DAS_CALL_METHOD(_method_364)>(*this,lib,"cmpunordsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpunordsd >::invoke")
		->args({"self","x","op"});
	using _method_365 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpunordss >;
	addExtern<DAS_CALL_METHOD(_method_365)>(*this,lib,"cmpunordss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpunordss >::invoke")
		->args({"self","x","op"});
	using _method_366 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &),&Xbyak::CodeGenerator::cmpxchg >;
	addExtern<DAS_CALL_METHOD(_method_366)>(*this,lib,"cmpxchg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &) , &Xbyak::CodeGenerator::cmpxchg >::invoke")
		->args({"self","op","reg"});
	using _method_367 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::cmpxchg8b >;
	addExtern<DAS_CALL_METHOD(_method_367)>(*this,lib,"cmpxchg8b",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::cmpxchg8b >::invoke")
		->args({"self","addr"});
	using _method_368 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::comisd >;
	addExtern<DAS_CALL_METHOD(_method_368)>(*this,lib,"comisd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::comisd >::invoke")
		->args({"self","xmm","op"});
	using _method_369 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::comiss >;
	addExtern<DAS_CALL_METHOD(_method_369)>(*this,lib,"comiss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::comiss >::invoke")
		->args({"self","xmm","op"});
	using _method_370 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cpuid >;
	addExtern<DAS_CALL_METHOD(_method_370)>(*this,lib,"cpuid",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cpuid >::invoke")
		->args({"self"});
	using _method_371 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::crc32 >;
	addExtern<DAS_CALL_METHOD(_method_371)>(*this,lib,"crc32",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::crc32 >::invoke")
		->args({"self","reg","op"});
	using _method_372 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtdq2pd >;
	addExtern<DAS_CALL_METHOD(_method_372)>(*this,lib,"cvtdq2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtdq2pd >::invoke")
		->args({"self","xmm","op"});
	using _method_373 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtdq2ps >;
	addExtern<DAS_CALL_METHOD(_method_373)>(*this,lib,"cvtdq2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtdq2ps >::invoke")
		->args({"self","xmm","op"});
	using _method_374 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtpd2dq >;
	addExtern<DAS_CALL_METHOD(_method_374)>(*this,lib,"cvtpd2dq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtpd2dq >::invoke")
		->args({"self","xmm","op"});
	using _method_375 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtpd2pi >;
	addExtern<DAS_CALL_METHOD(_method_375)>(*this,lib,"cvtpd2pi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtpd2pi >::invoke")
		->args({"self","reg","op"});
	using _method_376 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtpd2ps >;
	addExtern<DAS_CALL_METHOD(_method_376)>(*this,lib,"cvtpd2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtpd2ps >::invoke")
		->args({"self","xmm","op"});
	using _method_377 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtpi2pd >;
	addExtern<DAS_CALL_METHOD(_method_377)>(*this,lib,"cvtpi2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtpi2pd >::invoke")
		->args({"self","reg","op"});
	using _method_378 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtpi2ps >;
	addExtern<DAS_CALL_METHOD(_method_378)>(*this,lib,"cvtpi2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtpi2ps >::invoke")
		->args({"self","reg","op"});
	using _method_379 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtps2dq >;
	addExtern<DAS_CALL_METHOD(_method_379)>(*this,lib,"cvtps2dq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtps2dq >::invoke")
		->args({"self","xmm","op"});
	using _method_380 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtps2pd >;
	addExtern<DAS_CALL_METHOD(_method_380)>(*this,lib,"cvtps2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtps2pd >::invoke")
		->args({"self","xmm","op"});
	using _method_381 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtps2pi >;
	addExtern<DAS_CALL_METHOD(_method_381)>(*this,lib,"cvtps2pi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtps2pi >::invoke")
		->args({"self","reg","op"});
	using _method_382 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtsd2si >;
	addExtern<DAS_CALL_METHOD(_method_382)>(*this,lib,"cvtsd2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtsd2si >::invoke")
		->args({"self","reg","op"});
	using _method_383 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtsd2ss >;
	addExtern<DAS_CALL_METHOD(_method_383)>(*this,lib,"cvtsd2ss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtsd2ss >::invoke")
		->args({"self","xmm","op"});
	using _method_384 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtsi2sd >;
	addExtern<DAS_CALL_METHOD(_method_384)>(*this,lib,"cvtsi2sd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtsi2sd >::invoke")
		->args({"self","reg","op"});
	using _method_385 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtsi2ss >;
	addExtern<DAS_CALL_METHOD(_method_385)>(*this,lib,"cvtsi2ss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtsi2ss >::invoke")
		->args({"self","reg","op"});
	using _method_386 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtss2sd >;
	addExtern<DAS_CALL_METHOD(_method_386)>(*this,lib,"cvtss2sd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtss2sd >::invoke")
		->args({"self","xmm","op"});
	using _method_387 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvtss2si >;
	addExtern<DAS_CALL_METHOD(_method_387)>(*this,lib,"cvtss2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvtss2si >::invoke")
		->args({"self","reg","op"});
	using _method_388 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvttpd2dq >;
	addExtern<DAS_CALL_METHOD(_method_388)>(*this,lib,"cvttpd2dq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvttpd2dq >::invoke")
		->args({"self","xmm","op"});
	using _method_389 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvttpd2pi >;
	addExtern<DAS_CALL_METHOD(_method_389)>(*this,lib,"cvttpd2pi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvttpd2pi >::invoke")
		->args({"self","reg","op"});
	using _method_390 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvttps2dq >;
	addExtern<DAS_CALL_METHOD(_method_390)>(*this,lib,"cvttps2dq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvttps2dq >::invoke")
		->args({"self","xmm","op"});
	using _method_391 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvttps2pi >;
	addExtern<DAS_CALL_METHOD(_method_391)>(*this,lib,"cvttps2pi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvttps2pi >::invoke")
		->args({"self","reg","op"});
	using _method_392 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvttsd2si >;
	addExtern<DAS_CALL_METHOD(_method_392)>(*this,lib,"cvttsd2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvttsd2si >::invoke")
		->args({"self","reg","op"});
	using _method_393 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cvttss2si >;
	addExtern<DAS_CALL_METHOD(_method_393)>(*this,lib,"cvttss2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cvttss2si >::invoke")
		->args({"self","reg","op"});
	using _method_394 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cwd >;
	addExtern<DAS_CALL_METHOD(_method_394)>(*this,lib,"cwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cwd >::invoke")
		->args({"self"});
	using _method_395 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cwde >;
	addExtern<DAS_CALL_METHOD(_method_395)>(*this,lib,"cwde",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cwde >::invoke")
		->args({"self"});
	using _method_396 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::dec >;
	addExtern<DAS_CALL_METHOD(_method_396)>(*this,lib,"dec",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::dec >::invoke")
		->args({"self","op"});
	using _method_397 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::div >;
	addExtern<DAS_CALL_METHOD(_method_397)>(*this,lib,"div",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::div >::invoke")
		->args({"self","op"});
	using _method_398 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::divpd >;
	addExtern<DAS_CALL_METHOD(_method_398)>(*this,lib,"divpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::divpd >::invoke")
		->args({"self","xmm","op"});
	using _method_399 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::divps >;
	addExtern<DAS_CALL_METHOD(_method_399)>(*this,lib,"divps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::divps >::invoke")
		->args({"self","xmm","op"});
	using _method_400 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::divsd >;
	addExtern<DAS_CALL_METHOD(_method_400)>(*this,lib,"divsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::divsd >::invoke")
		->args({"self","xmm","op"});
	using _method_401 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::divss >;
	addExtern<DAS_CALL_METHOD(_method_401)>(*this,lib,"divss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::divss >::invoke")
		->args({"self","xmm","op"});
	using _method_402 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int),&Xbyak::CodeGenerator::dppd >;
	addExtern<DAS_CALL_METHOD(_method_402)>(*this,lib,"dppd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::dppd >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_403 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int),&Xbyak::CodeGenerator::dpps >;
	addExtern<DAS_CALL_METHOD(_method_403)>(*this,lib,"dpps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::dpps >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_404 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::emms >;
	addExtern<DAS_CALL_METHOD(_method_404)>(*this,lib,"emms",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::emms >::invoke")
		->args({"self"});
	using _method_405 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::endbr32 >;
	addExtern<DAS_CALL_METHOD(_method_405)>(*this,lib,"endbr32",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::endbr32 >::invoke")
		->args({"self"});
	using _method_406 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::endbr64 >;
	addExtern<DAS_CALL_METHOD(_method_406)>(*this,lib,"endbr64",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::endbr64 >::invoke")
		->args({"self"});
	using _method_407 = das::das_call_member< void (Xbyak::CodeGenerator::*)(unsigned short,unsigned char),&Xbyak::CodeGenerator::enter >;
	addExtern<DAS_CALL_METHOD(_method_407)>(*this,lib,"enter",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(unsigned short,unsigned char) , &Xbyak::CodeGenerator::enter >::invoke")
		->args({"self","x","y"});
	using _method_408 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char),&Xbyak::CodeGenerator::extractps >;
	addExtern<DAS_CALL_METHOD(_method_408)>(*this,lib,"extractps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char) , &Xbyak::CodeGenerator::extractps >::invoke")
		->args({"self","op","xmm","imm"});
	using _method_409 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::f2xm1 >;
	addExtern<DAS_CALL_METHOD(_method_409)>(*this,lib,"f2xm1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::f2xm1 >::invoke")
		->args({"self"});
	using _method_410 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fabs >;
	addExtern<DAS_CALL_METHOD(_method_410)>(*this,lib,"fabs",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fabs >::invoke")
		->args({"self"});
	using _method_411 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fadd >;
	addExtern<DAS_CALL_METHOD(_method_411)>(*this,lib,"fadd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fadd >::invoke")
		->args({"self","addr"});
	using _method_412 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fadd >;
	addExtern<DAS_CALL_METHOD(_method_412)>(*this,lib,"fadd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fadd >::invoke")
		->args({"self","reg1"});
	using _method_413 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fadd >;
	addExtern<DAS_CALL_METHOD(_method_413)>(*this,lib,"fadd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fadd >::invoke")
		->args({"self","reg1","reg2"});
	using _method_414 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::faddp >;
	addExtern<DAS_CALL_METHOD(_method_414)>(*this,lib,"faddp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::faddp >::invoke")
		->args({"self"});
	using _method_415 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::faddp >;
	addExtern<DAS_CALL_METHOD(_method_415)>(*this,lib,"faddp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::faddp >::invoke")
		->args({"self","reg1"});
	using _method_416 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::faddp >;
	addExtern<DAS_CALL_METHOD(_method_416)>(*this,lib,"faddp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::faddp >::invoke")
		->args({"self","reg1","reg2"});
	using _method_417 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fbld >;
	addExtern<DAS_CALL_METHOD(_method_417)>(*this,lib,"fbld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fbld >::invoke")
		->args({"self","addr"});
	using _method_418 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fbstp >;
	addExtern<DAS_CALL_METHOD(_method_418)>(*this,lib,"fbstp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fbstp >::invoke")
		->args({"self","addr"});
	using _method_419 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fchs >;
	addExtern<DAS_CALL_METHOD(_method_419)>(*this,lib,"fchs",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fchs >::invoke")
		->args({"self"});
	using _method_420 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fclex >;
	addExtern<DAS_CALL_METHOD(_method_420)>(*this,lib,"fclex",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fclex >::invoke")
		->args({"self"});
	using _method_421 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovb >;
	addExtern<DAS_CALL_METHOD(_method_421)>(*this,lib,"fcmovb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovb >::invoke")
		->args({"self","reg1"});
	using _method_422 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovb >;
	addExtern<DAS_CALL_METHOD(_method_422)>(*this,lib,"fcmovb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovb >::invoke")
		->args({"self","reg1","reg2"});
	using _method_423 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovbe >;
	addExtern<DAS_CALL_METHOD(_method_423)>(*this,lib,"fcmovbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovbe >::invoke")
		->args({"self","reg1"});
	using _method_424 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovbe >;
	addExtern<DAS_CALL_METHOD(_method_424)>(*this,lib,"fcmovbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovbe >::invoke")
		->args({"self","reg1","reg2"});
	using _method_425 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmove >;
	addExtern<DAS_CALL_METHOD(_method_425)>(*this,lib,"fcmove",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmove >::invoke")
		->args({"self","reg1"});
	using _method_426 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmove >;
	addExtern<DAS_CALL_METHOD(_method_426)>(*this,lib,"fcmove",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmove >::invoke")
		->args({"self","reg1","reg2"});
	using _method_427 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovnb >;
	addExtern<DAS_CALL_METHOD(_method_427)>(*this,lib,"fcmovnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovnb >::invoke")
		->args({"self","reg1"});
	using _method_428 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovnb >;
	addExtern<DAS_CALL_METHOD(_method_428)>(*this,lib,"fcmovnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovnb >::invoke")
		->args({"self","reg1","reg2"});
	using _method_429 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovnbe >;
	addExtern<DAS_CALL_METHOD(_method_429)>(*this,lib,"fcmovnbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovnbe >::invoke")
		->args({"self","reg1"});
	using _method_430 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovnbe >;
	addExtern<DAS_CALL_METHOD(_method_430)>(*this,lib,"fcmovnbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovnbe >::invoke")
		->args({"self","reg1","reg2"});
	using _method_431 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovne >;
	addExtern<DAS_CALL_METHOD(_method_431)>(*this,lib,"fcmovne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovne >::invoke")
		->args({"self","reg1"});
	using _method_432 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovne >;
	addExtern<DAS_CALL_METHOD(_method_432)>(*this,lib,"fcmovne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovne >::invoke")
		->args({"self","reg1","reg2"});
	using _method_433 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovnu >;
	addExtern<DAS_CALL_METHOD(_method_433)>(*this,lib,"fcmovnu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovnu >::invoke")
		->args({"self","reg1"});
	using _method_434 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovnu >;
	addExtern<DAS_CALL_METHOD(_method_434)>(*this,lib,"fcmovnu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovnu >::invoke")
		->args({"self","reg1","reg2"});
	using _method_435 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovu >;
	addExtern<DAS_CALL_METHOD(_method_435)>(*this,lib,"fcmovu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovu >::invoke")
		->args({"self","reg1"});
	using _method_436 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcmovu >;
	addExtern<DAS_CALL_METHOD(_method_436)>(*this,lib,"fcmovu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcmovu >::invoke")
		->args({"self","reg1","reg2"});
	using _method_437 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fcom >;
	addExtern<DAS_CALL_METHOD(_method_437)>(*this,lib,"fcom",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fcom >::invoke")
		->args({"self"});
	using _method_438 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fcom >;
	addExtern<DAS_CALL_METHOD(_method_438)>(*this,lib,"fcom",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fcom >::invoke")
		->args({"self","addr"});
	using _method_439 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcom >;
	addExtern<DAS_CALL_METHOD(_method_439)>(*this,lib,"fcom",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcom >::invoke")
		->args({"self","reg"});
	using _method_440 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcomi >;
	addExtern<DAS_CALL_METHOD(_method_440)>(*this,lib,"fcomi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcomi >::invoke")
		->args({"self","reg1"});
	using _method_441 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcomi >;
	addExtern<DAS_CALL_METHOD(_method_441)>(*this,lib,"fcomi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcomi >::invoke")
		->args({"self","reg1","reg2"});
	using _method_442 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcomip >;
	addExtern<DAS_CALL_METHOD(_method_442)>(*this,lib,"fcomip",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcomip >::invoke")
		->args({"self","reg1"});
	using _method_443 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcomip >;
	addExtern<DAS_CALL_METHOD(_method_443)>(*this,lib,"fcomip",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcomip >::invoke")
		->args({"self","reg1","reg2"});
	using _method_444 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fcomp >;
	addExtern<DAS_CALL_METHOD(_method_444)>(*this,lib,"fcomp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fcomp >::invoke")
		->args({"self"});
	using _method_445 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fcomp >;
	addExtern<DAS_CALL_METHOD(_method_445)>(*this,lib,"fcomp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fcomp >::invoke")
		->args({"self","addr"});
	using _method_446 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fcomp >;
	addExtern<DAS_CALL_METHOD(_method_446)>(*this,lib,"fcomp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fcomp >::invoke")
		->args({"self","reg"});
	using _method_447 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fcompp >;
	addExtern<DAS_CALL_METHOD(_method_447)>(*this,lib,"fcompp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fcompp >::invoke")
		->args({"self"});
	using _method_448 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fcos >;
	addExtern<DAS_CALL_METHOD(_method_448)>(*this,lib,"fcos",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fcos >::invoke")
		->args({"self"});
	using _method_449 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fdecstp >;
	addExtern<DAS_CALL_METHOD(_method_449)>(*this,lib,"fdecstp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fdecstp >::invoke")
		->args({"self"});
	using _method_450 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fdiv >;
	addExtern<DAS_CALL_METHOD(_method_450)>(*this,lib,"fdiv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fdiv >::invoke")
		->args({"self","addr"});
	using _method_451 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fdiv >;
	addExtern<DAS_CALL_METHOD(_method_451)>(*this,lib,"fdiv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fdiv >::invoke")
		->args({"self","reg1"});
	using _method_452 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fdiv >;
	addExtern<DAS_CALL_METHOD(_method_452)>(*this,lib,"fdiv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fdiv >::invoke")
		->args({"self","reg1","reg2"});
	using _method_453 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fdivp >;
	addExtern<DAS_CALL_METHOD(_method_453)>(*this,lib,"fdivp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fdivp >::invoke")
		->args({"self"});
	using _method_454 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fdivp >;
	addExtern<DAS_CALL_METHOD(_method_454)>(*this,lib,"fdivp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fdivp >::invoke")
		->args({"self","reg1"});
	using _method_455 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fdivp >;
	addExtern<DAS_CALL_METHOD(_method_455)>(*this,lib,"fdivp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fdivp >::invoke")
		->args({"self","reg1","reg2"});
	using _method_456 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fdivr >;
	addExtern<DAS_CALL_METHOD(_method_456)>(*this,lib,"fdivr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fdivr >::invoke")
		->args({"self","addr"});
}
}

