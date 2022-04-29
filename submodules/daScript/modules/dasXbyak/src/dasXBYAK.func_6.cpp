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
void Module_dasXBYAK::initFunctions_6() {
	using _method_457 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fdivr >;
	addExtern<DAS_CALL_METHOD(_method_457)>(*this,lib,"fdivr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fdivr >::invoke")
		->args({"self","reg1"});
	using _method_458 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fdivr >;
	addExtern<DAS_CALL_METHOD(_method_458)>(*this,lib,"fdivr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fdivr >::invoke")
		->args({"self","reg1","reg2"});
	using _method_459 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fdivrp >;
	addExtern<DAS_CALL_METHOD(_method_459)>(*this,lib,"fdivrp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fdivrp >::invoke")
		->args({"self"});
	using _method_460 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fdivrp >;
	addExtern<DAS_CALL_METHOD(_method_460)>(*this,lib,"fdivrp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fdivrp >::invoke")
		->args({"self","reg1"});
	using _method_461 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fdivrp >;
	addExtern<DAS_CALL_METHOD(_method_461)>(*this,lib,"fdivrp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fdivrp >::invoke")
		->args({"self","reg1","reg2"});
	using _method_462 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::ffree >;
	addExtern<DAS_CALL_METHOD(_method_462)>(*this,lib,"ffree",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::ffree >::invoke")
		->args({"self","reg"});
	using _method_463 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fiadd >;
	addExtern<DAS_CALL_METHOD(_method_463)>(*this,lib,"fiadd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fiadd >::invoke")
		->args({"self","addr"});
	using _method_464 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::ficom >;
	addExtern<DAS_CALL_METHOD(_method_464)>(*this,lib,"ficom",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::ficom >::invoke")
		->args({"self","addr"});
	using _method_465 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::ficomp >;
	addExtern<DAS_CALL_METHOD(_method_465)>(*this,lib,"ficomp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::ficomp >::invoke")
		->args({"self","addr"});
	using _method_466 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fidiv >;
	addExtern<DAS_CALL_METHOD(_method_466)>(*this,lib,"fidiv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fidiv >::invoke")
		->args({"self","addr"});
	using _method_467 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fidivr >;
	addExtern<DAS_CALL_METHOD(_method_467)>(*this,lib,"fidivr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fidivr >::invoke")
		->args({"self","addr"});
	using _method_468 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fild >;
	addExtern<DAS_CALL_METHOD(_method_468)>(*this,lib,"fild",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fild >::invoke")
		->args({"self","addr"});
	using _method_469 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fimul >;
	addExtern<DAS_CALL_METHOD(_method_469)>(*this,lib,"fimul",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fimul >::invoke")
		->args({"self","addr"});
	using _method_470 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fincstp >;
	addExtern<DAS_CALL_METHOD(_method_470)>(*this,lib,"fincstp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fincstp >::invoke")
		->args({"self"});
	using _method_471 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::finit >;
	addExtern<DAS_CALL_METHOD(_method_471)>(*this,lib,"finit",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::finit >::invoke")
		->args({"self"});
	using _method_472 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fist >;
	addExtern<DAS_CALL_METHOD(_method_472)>(*this,lib,"fist",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fist >::invoke")
		->args({"self","addr"});
	using _method_473 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fistp >;
	addExtern<DAS_CALL_METHOD(_method_473)>(*this,lib,"fistp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fistp >::invoke")
		->args({"self","addr"});
	using _method_474 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fisttp >;
	addExtern<DAS_CALL_METHOD(_method_474)>(*this,lib,"fisttp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fisttp >::invoke")
		->args({"self","addr"});
	using _method_475 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fisub >;
	addExtern<DAS_CALL_METHOD(_method_475)>(*this,lib,"fisub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fisub >::invoke")
		->args({"self","addr"});
	using _method_476 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fisubr >;
	addExtern<DAS_CALL_METHOD(_method_476)>(*this,lib,"fisubr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fisubr >::invoke")
		->args({"self","addr"});
	using _method_477 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fld >;
	addExtern<DAS_CALL_METHOD(_method_477)>(*this,lib,"fld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fld >::invoke")
		->args({"self","addr"});
	using _method_478 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fld >;
	addExtern<DAS_CALL_METHOD(_method_478)>(*this,lib,"fld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fld >::invoke")
		->args({"self","reg"});
	using _method_479 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fld1 >;
	addExtern<DAS_CALL_METHOD(_method_479)>(*this,lib,"fld1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fld1 >::invoke")
		->args({"self"});
	using _method_480 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fldcw >;
	addExtern<DAS_CALL_METHOD(_method_480)>(*this,lib,"fldcw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fldcw >::invoke")
		->args({"self","addr"});
	using _method_481 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fldenv >;
	addExtern<DAS_CALL_METHOD(_method_481)>(*this,lib,"fldenv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fldenv >::invoke")
		->args({"self","addr"});
	using _method_482 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fldl2e >;
	addExtern<DAS_CALL_METHOD(_method_482)>(*this,lib,"fldl2e",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fldl2e >::invoke")
		->args({"self"});
	using _method_483 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fldl2t >;
	addExtern<DAS_CALL_METHOD(_method_483)>(*this,lib,"fldl2t",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fldl2t >::invoke")
		->args({"self"});
	using _method_484 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fldlg2 >;
	addExtern<DAS_CALL_METHOD(_method_484)>(*this,lib,"fldlg2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fldlg2 >::invoke")
		->args({"self"});
	using _method_485 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fldln2 >;
	addExtern<DAS_CALL_METHOD(_method_485)>(*this,lib,"fldln2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fldln2 >::invoke")
		->args({"self"});
	using _method_486 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fldpi >;
	addExtern<DAS_CALL_METHOD(_method_486)>(*this,lib,"fldpi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fldpi >::invoke")
		->args({"self"});
	using _method_487 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fldz >;
	addExtern<DAS_CALL_METHOD(_method_487)>(*this,lib,"fldz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fldz >::invoke")
		->args({"self"});
	using _method_488 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fmul >;
	addExtern<DAS_CALL_METHOD(_method_488)>(*this,lib,"fmul",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fmul >::invoke")
		->args({"self","addr"});
	using _method_489 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fmul >;
	addExtern<DAS_CALL_METHOD(_method_489)>(*this,lib,"fmul",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fmul >::invoke")
		->args({"self","reg1"});
	using _method_490 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fmul >;
	addExtern<DAS_CALL_METHOD(_method_490)>(*this,lib,"fmul",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fmul >::invoke")
		->args({"self","reg1","reg2"});
	using _method_491 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fmulp >;
	addExtern<DAS_CALL_METHOD(_method_491)>(*this,lib,"fmulp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fmulp >::invoke")
		->args({"self"});
	using _method_492 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fmulp >;
	addExtern<DAS_CALL_METHOD(_method_492)>(*this,lib,"fmulp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fmulp >::invoke")
		->args({"self","reg1"});
	using _method_493 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fmulp >;
	addExtern<DAS_CALL_METHOD(_method_493)>(*this,lib,"fmulp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fmulp >::invoke")
		->args({"self","reg1","reg2"});
	using _method_494 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fnclex >;
	addExtern<DAS_CALL_METHOD(_method_494)>(*this,lib,"fnclex",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fnclex >::invoke")
		->args({"self"});
	using _method_495 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fninit >;
	addExtern<DAS_CALL_METHOD(_method_495)>(*this,lib,"fninit",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fninit >::invoke")
		->args({"self"});
	using _method_496 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fnop >;
	addExtern<DAS_CALL_METHOD(_method_496)>(*this,lib,"fnop",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fnop >::invoke")
		->args({"self"});
	using _method_497 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fnsave >;
	addExtern<DAS_CALL_METHOD(_method_497)>(*this,lib,"fnsave",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fnsave >::invoke")
		->args({"self","addr"});
	using _method_498 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fnstcw >;
	addExtern<DAS_CALL_METHOD(_method_498)>(*this,lib,"fnstcw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fnstcw >::invoke")
		->args({"self","addr"});
	using _method_499 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fnstenv >;
	addExtern<DAS_CALL_METHOD(_method_499)>(*this,lib,"fnstenv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fnstenv >::invoke")
		->args({"self","addr"});
	using _method_500 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fnstsw >;
	addExtern<DAS_CALL_METHOD(_method_500)>(*this,lib,"fnstsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fnstsw >::invoke")
		->args({"self","addr"});
	using _method_501 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg16 &),&Xbyak::CodeGenerator::fnstsw >;
	addExtern<DAS_CALL_METHOD(_method_501)>(*this,lib,"fnstsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg16 &) , &Xbyak::CodeGenerator::fnstsw >::invoke")
		->args({"self","r"});
	using _method_502 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fpatan >;
	addExtern<DAS_CALL_METHOD(_method_502)>(*this,lib,"fpatan",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fpatan >::invoke")
		->args({"self"});
	using _method_503 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fprem >;
	addExtern<DAS_CALL_METHOD(_method_503)>(*this,lib,"fprem",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fprem >::invoke")
		->args({"self"});
	using _method_504 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fprem1 >;
	addExtern<DAS_CALL_METHOD(_method_504)>(*this,lib,"fprem1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fprem1 >::invoke")
		->args({"self"});
	using _method_505 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fptan >;
	addExtern<DAS_CALL_METHOD(_method_505)>(*this,lib,"fptan",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fptan >::invoke")
		->args({"self"});
	using _method_506 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::frndint >;
	addExtern<DAS_CALL_METHOD(_method_506)>(*this,lib,"frndint",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::frndint >::invoke")
		->args({"self"});
	using _method_507 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::frstor >;
	addExtern<DAS_CALL_METHOD(_method_507)>(*this,lib,"frstor",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::frstor >::invoke")
		->args({"self","addr"});
	using _method_508 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fsave >;
	addExtern<DAS_CALL_METHOD(_method_508)>(*this,lib,"fsave",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fsave >::invoke")
		->args({"self","addr"});
	using _method_509 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fscale >;
	addExtern<DAS_CALL_METHOD(_method_509)>(*this,lib,"fscale",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fscale >::invoke")
		->args({"self"});
	using _method_510 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fsin >;
	addExtern<DAS_CALL_METHOD(_method_510)>(*this,lib,"fsin",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fsin >::invoke")
		->args({"self"});
	using _method_511 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fsincos >;
	addExtern<DAS_CALL_METHOD(_method_511)>(*this,lib,"fsincos",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fsincos >::invoke")
		->args({"self"});
	using _method_512 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fsqrt >;
	addExtern<DAS_CALL_METHOD(_method_512)>(*this,lib,"fsqrt",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fsqrt >::invoke")
		->args({"self"});
	using _method_513 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fst >;
	addExtern<DAS_CALL_METHOD(_method_513)>(*this,lib,"fst",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fst >::invoke")
		->args({"self","addr"});
	using _method_514 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fst >;
	addExtern<DAS_CALL_METHOD(_method_514)>(*this,lib,"fst",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fst >::invoke")
		->args({"self","reg"});
	using _method_515 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fstcw >;
	addExtern<DAS_CALL_METHOD(_method_515)>(*this,lib,"fstcw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fstcw >::invoke")
		->args({"self","addr"});
	using _method_516 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fstenv >;
	addExtern<DAS_CALL_METHOD(_method_516)>(*this,lib,"fstenv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fstenv >::invoke")
		->args({"self","addr"});
	using _method_517 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fstp >;
	addExtern<DAS_CALL_METHOD(_method_517)>(*this,lib,"fstp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fstp >::invoke")
		->args({"self","addr"});
	using _method_518 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fstp >;
	addExtern<DAS_CALL_METHOD(_method_518)>(*this,lib,"fstp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fstp >::invoke")
		->args({"self","reg"});
	using _method_519 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fstsw >;
	addExtern<DAS_CALL_METHOD(_method_519)>(*this,lib,"fstsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fstsw >::invoke")
		->args({"self","addr"});
	using _method_520 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg16 &),&Xbyak::CodeGenerator::fstsw >;
	addExtern<DAS_CALL_METHOD(_method_520)>(*this,lib,"fstsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg16 &) , &Xbyak::CodeGenerator::fstsw >::invoke")
		->args({"self","r"});
	using _method_521 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fsub >;
	addExtern<DAS_CALL_METHOD(_method_521)>(*this,lib,"fsub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fsub >::invoke")
		->args({"self","addr"});
	using _method_522 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fsub >;
	addExtern<DAS_CALL_METHOD(_method_522)>(*this,lib,"fsub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fsub >::invoke")
		->args({"self","reg1"});
	using _method_523 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fsub >;
	addExtern<DAS_CALL_METHOD(_method_523)>(*this,lib,"fsub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fsub >::invoke")
		->args({"self","reg1","reg2"});
	using _method_524 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fsubp >;
	addExtern<DAS_CALL_METHOD(_method_524)>(*this,lib,"fsubp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fsubp >::invoke")
		->args({"self"});
	using _method_525 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fsubp >;
	addExtern<DAS_CALL_METHOD(_method_525)>(*this,lib,"fsubp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fsubp >::invoke")
		->args({"self","reg1"});
	using _method_526 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fsubp >;
	addExtern<DAS_CALL_METHOD(_method_526)>(*this,lib,"fsubp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fsubp >::invoke")
		->args({"self","reg1","reg2"});
	using _method_527 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fsubr >;
	addExtern<DAS_CALL_METHOD(_method_527)>(*this,lib,"fsubr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fsubr >::invoke")
		->args({"self","addr"});
	using _method_528 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fsubr >;
	addExtern<DAS_CALL_METHOD(_method_528)>(*this,lib,"fsubr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fsubr >::invoke")
		->args({"self","reg1"});
	using _method_529 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fsubr >;
	addExtern<DAS_CALL_METHOD(_method_529)>(*this,lib,"fsubr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fsubr >::invoke")
		->args({"self","reg1","reg2"});
	using _method_530 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fsubrp >;
	addExtern<DAS_CALL_METHOD(_method_530)>(*this,lib,"fsubrp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fsubrp >::invoke")
		->args({"self"});
	using _method_531 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fsubrp >;
	addExtern<DAS_CALL_METHOD(_method_531)>(*this,lib,"fsubrp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fsubrp >::invoke")
		->args({"self","reg1"});
	using _method_532 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fsubrp >;
	addExtern<DAS_CALL_METHOD(_method_532)>(*this,lib,"fsubrp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fsubrp >::invoke")
		->args({"self","reg1","reg2"});
	using _method_533 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::ftst >;
	addExtern<DAS_CALL_METHOD(_method_533)>(*this,lib,"ftst",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::ftst >::invoke")
		->args({"self"});
	using _method_534 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fucom >;
	addExtern<DAS_CALL_METHOD(_method_534)>(*this,lib,"fucom",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fucom >::invoke")
		->args({"self"});
	using _method_535 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fucom >;
	addExtern<DAS_CALL_METHOD(_method_535)>(*this,lib,"fucom",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fucom >::invoke")
		->args({"self","reg"});
	using _method_536 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fucomi >;
	addExtern<DAS_CALL_METHOD(_method_536)>(*this,lib,"fucomi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fucomi >::invoke")
		->args({"self","reg1"});
	using _method_537 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fucomi >;
	addExtern<DAS_CALL_METHOD(_method_537)>(*this,lib,"fucomi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fucomi >::invoke")
		->args({"self","reg1","reg2"});
	using _method_538 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fucomip >;
	addExtern<DAS_CALL_METHOD(_method_538)>(*this,lib,"fucomip",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fucomip >::invoke")
		->args({"self","reg1"});
	using _method_539 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &),&Xbyak::CodeGenerator::fucomip >;
	addExtern<DAS_CALL_METHOD(_method_539)>(*this,lib,"fucomip",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &,const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fucomip >::invoke")
		->args({"self","reg1","reg2"});
	using _method_540 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fucomp >;
	addExtern<DAS_CALL_METHOD(_method_540)>(*this,lib,"fucomp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fucomp >::invoke")
		->args({"self"});
	using _method_541 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fucomp >;
	addExtern<DAS_CALL_METHOD(_method_541)>(*this,lib,"fucomp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fucomp >::invoke")
		->args({"self","reg"});
	using _method_542 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fucompp >;
	addExtern<DAS_CALL_METHOD(_method_542)>(*this,lib,"fucompp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fucompp >::invoke")
		->args({"self"});
	using _method_543 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fwait >;
	addExtern<DAS_CALL_METHOD(_method_543)>(*this,lib,"fwait",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fwait >::invoke")
		->args({"self"});
	using _method_544 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fxam >;
	addExtern<DAS_CALL_METHOD(_method_544)>(*this,lib,"fxam",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fxam >::invoke")
		->args({"self"});
	using _method_545 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fxch >;
	addExtern<DAS_CALL_METHOD(_method_545)>(*this,lib,"fxch",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fxch >::invoke")
		->args({"self"});
	using _method_546 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &),&Xbyak::CodeGenerator::fxch >;
	addExtern<DAS_CALL_METHOD(_method_546)>(*this,lib,"fxch",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Fpu &) , &Xbyak::CodeGenerator::fxch >::invoke")
		->args({"self","reg"});
	using _method_547 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fxrstor >;
	addExtern<DAS_CALL_METHOD(_method_547)>(*this,lib,"fxrstor",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fxrstor >::invoke")
		->args({"self","addr"});
	using _method_548 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fxtract >;
	addExtern<DAS_CALL_METHOD(_method_548)>(*this,lib,"fxtract",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fxtract >::invoke")
		->args({"self"});
	using _method_549 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fyl2x >;
	addExtern<DAS_CALL_METHOD(_method_549)>(*this,lib,"fyl2x",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fyl2x >::invoke")
		->args({"self"});
	using _method_550 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::fyl2xp1 >;
	addExtern<DAS_CALL_METHOD(_method_550)>(*this,lib,"fyl2xp1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::fyl2xp1 >::invoke")
		->args({"self"});
	using _method_551 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int),&Xbyak::CodeGenerator::gf2p8affineinvqb >;
	addExtern<DAS_CALL_METHOD(_method_551)>(*this,lib,"gf2p8affineinvqb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::gf2p8affineinvqb >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_552 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int),&Xbyak::CodeGenerator::gf2p8affineqb >;
	addExtern<DAS_CALL_METHOD(_method_552)>(*this,lib,"gf2p8affineqb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::gf2p8affineqb >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_553 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::gf2p8mulb >;
	addExtern<DAS_CALL_METHOD(_method_553)>(*this,lib,"gf2p8mulb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::gf2p8mulb >::invoke")
		->args({"self","xmm","op"});
	using _method_554 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::haddpd >;
	addExtern<DAS_CALL_METHOD(_method_554)>(*this,lib,"haddpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::haddpd >::invoke")
		->args({"self","xmm","op"});
	using _method_555 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::haddps >;
	addExtern<DAS_CALL_METHOD(_method_555)>(*this,lib,"haddps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::haddps >::invoke")
		->args({"self","xmm","op"});
	using _method_556 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::hsubpd >;
	addExtern<DAS_CALL_METHOD(_method_556)>(*this,lib,"hsubpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::hsubpd >::invoke")
		->args({"self","xmm","op"});
}
}

