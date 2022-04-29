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
void Module_dasXBYAK::initFunctions_7() {
	using _method_557 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::hsubps >;
	addExtern<DAS_CALL_METHOD(_method_557)>(*this,lib,"hsubps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::hsubps >::invoke")
		->args({"self","xmm","op"});
	using _method_558 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::idiv >;
	addExtern<DAS_CALL_METHOD(_method_558)>(*this,lib,"idiv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::idiv >::invoke")
		->args({"self","op"});
	using _method_559 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::imul >;
	addExtern<DAS_CALL_METHOD(_method_559)>(*this,lib,"imul",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::imul >::invoke")
		->args({"self","op"});
	using _method_560 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Reg &),&Xbyak::CodeGenerator::in_ >;
	addExtern<DAS_CALL_METHOD(_method_560)>(*this,lib,"in_",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Reg &) , &Xbyak::CodeGenerator::in_ >::invoke")
		->args({"self","a","d"});
	using _method_561 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,unsigned char),&Xbyak::CodeGenerator::in_ >;
	addExtern<DAS_CALL_METHOD(_method_561)>(*this,lib,"in_",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,unsigned char) , &Xbyak::CodeGenerator::in_ >::invoke")
		->args({"self","a","v"});
	using _method_562 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::inc >;
	addExtern<DAS_CALL_METHOD(_method_562)>(*this,lib,"inc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::inc >::invoke")
		->args({"self","op"});
	using _method_563 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::insertps >;
	addExtern<DAS_CALL_METHOD(_method_563)>(*this,lib,"insertps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::insertps >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_564 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::int3 >;
	addExtern<DAS_CALL_METHOD(_method_564)>(*this,lib,"int3",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::int3 >::invoke")
		->args({"self"});
	using _method_565 = das::das_call_member< void (Xbyak::CodeGenerator::*)(unsigned char),&Xbyak::CodeGenerator::int_ >;
	addExtern<DAS_CALL_METHOD(_method_565)>(*this,lib,"int_",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(unsigned char) , &Xbyak::CodeGenerator::int_ >::invoke")
		->args({"self","x"});
	using _method_566 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::ja >;
	addExtern<DAS_CALL_METHOD(_method_566)>(*this,lib,"ja",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::ja >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_567 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::ja >;
	addExtern<DAS_CALL_METHOD(_method_567)>(*this,lib,"ja",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::ja >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_568 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::ja >;
	addExtern<DAS_CALL_METHOD(_method_568)>(*this,lib,"ja",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::ja >::invoke")
		->args({"self","addr"});
	using _method_569 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::ja >;
	addExtern<DAS_CALL_METHOD(_method_569)>(*this,lib,"ja",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::ja >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_570 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jae >;
	addExtern<DAS_CALL_METHOD(_method_570)>(*this,lib,"jae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jae >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_571 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jae >;
	addExtern<DAS_CALL_METHOD(_method_571)>(*this,lib,"jae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jae >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_572 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jae >;
	addExtern<DAS_CALL_METHOD(_method_572)>(*this,lib,"jae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jae >::invoke")
		->args({"self","addr"});
	using _method_573 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jae >;
	addExtern<DAS_CALL_METHOD(_method_573)>(*this,lib,"jae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jae >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_574 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jb >;
	addExtern<DAS_CALL_METHOD(_method_574)>(*this,lib,"jb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jb >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_575 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jb >;
	addExtern<DAS_CALL_METHOD(_method_575)>(*this,lib,"jb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jb >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_576 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jb >;
	addExtern<DAS_CALL_METHOD(_method_576)>(*this,lib,"jb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jb >::invoke")
		->args({"self","addr"});
	using _method_577 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jb >;
	addExtern<DAS_CALL_METHOD(_method_577)>(*this,lib,"jb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jb >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_578 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jbe >;
	addExtern<DAS_CALL_METHOD(_method_578)>(*this,lib,"jbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jbe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_579 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jbe >;
	addExtern<DAS_CALL_METHOD(_method_579)>(*this,lib,"jbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jbe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_580 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jbe >;
	addExtern<DAS_CALL_METHOD(_method_580)>(*this,lib,"jbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jbe >::invoke")
		->args({"self","addr"});
	using _method_581 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jbe >;
	addExtern<DAS_CALL_METHOD(_method_581)>(*this,lib,"jbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jbe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_582 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jc >;
	addExtern<DAS_CALL_METHOD(_method_582)>(*this,lib,"jc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jc >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_583 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jc >;
	addExtern<DAS_CALL_METHOD(_method_583)>(*this,lib,"jc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jc >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_584 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jc >;
	addExtern<DAS_CALL_METHOD(_method_584)>(*this,lib,"jc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jc >::invoke")
		->args({"self","addr"});
	using _method_585 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jc >;
	addExtern<DAS_CALL_METHOD(_method_585)>(*this,lib,"jc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jc >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_586 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::je >;
	addExtern<DAS_CALL_METHOD(_method_586)>(*this,lib,"je",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::je >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_587 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::je >;
	addExtern<DAS_CALL_METHOD(_method_587)>(*this,lib,"je",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::je >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_588 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::je >;
	addExtern<DAS_CALL_METHOD(_method_588)>(*this,lib,"je",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::je >::invoke")
		->args({"self","addr"});
	using _method_589 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::je >;
	addExtern<DAS_CALL_METHOD(_method_589)>(*this,lib,"je",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::je >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_590 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jg >;
	addExtern<DAS_CALL_METHOD(_method_590)>(*this,lib,"jg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jg >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_591 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jg >;
	addExtern<DAS_CALL_METHOD(_method_591)>(*this,lib,"jg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jg >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_592 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jg >;
	addExtern<DAS_CALL_METHOD(_method_592)>(*this,lib,"jg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jg >::invoke")
		->args({"self","addr"});
	using _method_593 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jg >;
	addExtern<DAS_CALL_METHOD(_method_593)>(*this,lib,"jg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jg >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_594 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jge >;
	addExtern<DAS_CALL_METHOD(_method_594)>(*this,lib,"jge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jge >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_595 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jge >;
	addExtern<DAS_CALL_METHOD(_method_595)>(*this,lib,"jge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jge >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_596 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jge >;
	addExtern<DAS_CALL_METHOD(_method_596)>(*this,lib,"jge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jge >::invoke")
		->args({"self","addr"});
	using _method_597 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jge >;
	addExtern<DAS_CALL_METHOD(_method_597)>(*this,lib,"jge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jge >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_598 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jl >;
	addExtern<DAS_CALL_METHOD(_method_598)>(*this,lib,"jl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jl >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_599 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jl >;
	addExtern<DAS_CALL_METHOD(_method_599)>(*this,lib,"jl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jl >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_600 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jl >;
	addExtern<DAS_CALL_METHOD(_method_600)>(*this,lib,"jl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jl >::invoke")
		->args({"self","addr"});
	using _method_601 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jl >;
	addExtern<DAS_CALL_METHOD(_method_601)>(*this,lib,"jl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jl >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_602 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jle >;
	addExtern<DAS_CALL_METHOD(_method_602)>(*this,lib,"jle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jle >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_603 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jle >;
	addExtern<DAS_CALL_METHOD(_method_603)>(*this,lib,"jle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jle >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_604 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jle >;
	addExtern<DAS_CALL_METHOD(_method_604)>(*this,lib,"jle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jle >::invoke")
		->args({"self","addr"});
	using _method_605 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jle >;
	addExtern<DAS_CALL_METHOD(_method_605)>(*this,lib,"jle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jle >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_606 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jna >;
	addExtern<DAS_CALL_METHOD(_method_606)>(*this,lib,"jna",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jna >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_607 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jna >;
	addExtern<DAS_CALL_METHOD(_method_607)>(*this,lib,"jna",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jna >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_608 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jna >;
	addExtern<DAS_CALL_METHOD(_method_608)>(*this,lib,"jna",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jna >::invoke")
		->args({"self","addr"});
	using _method_609 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jna >;
	addExtern<DAS_CALL_METHOD(_method_609)>(*this,lib,"jna",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jna >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_610 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnae >;
	addExtern<DAS_CALL_METHOD(_method_610)>(*this,lib,"jnae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnae >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_611 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnae >;
	addExtern<DAS_CALL_METHOD(_method_611)>(*this,lib,"jnae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnae >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_612 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnae >;
	addExtern<DAS_CALL_METHOD(_method_612)>(*this,lib,"jnae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnae >::invoke")
		->args({"self","addr"});
	using _method_613 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnae >;
	addExtern<DAS_CALL_METHOD(_method_613)>(*this,lib,"jnae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnae >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_614 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnb >;
	addExtern<DAS_CALL_METHOD(_method_614)>(*this,lib,"jnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnb >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_615 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnb >;
	addExtern<DAS_CALL_METHOD(_method_615)>(*this,lib,"jnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnb >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_616 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnb >;
	addExtern<DAS_CALL_METHOD(_method_616)>(*this,lib,"jnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnb >::invoke")
		->args({"self","addr"});
	using _method_617 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnb >;
	addExtern<DAS_CALL_METHOD(_method_617)>(*this,lib,"jnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnb >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_618 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnbe >;
	addExtern<DAS_CALL_METHOD(_method_618)>(*this,lib,"jnbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnbe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_619 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnbe >;
	addExtern<DAS_CALL_METHOD(_method_619)>(*this,lib,"jnbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnbe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_620 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnbe >;
	addExtern<DAS_CALL_METHOD(_method_620)>(*this,lib,"jnbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnbe >::invoke")
		->args({"self","addr"});
	using _method_621 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnbe >;
	addExtern<DAS_CALL_METHOD(_method_621)>(*this,lib,"jnbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnbe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_622 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnc >;
	addExtern<DAS_CALL_METHOD(_method_622)>(*this,lib,"jnc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnc >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_623 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnc >;
	addExtern<DAS_CALL_METHOD(_method_623)>(*this,lib,"jnc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnc >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_624 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnc >;
	addExtern<DAS_CALL_METHOD(_method_624)>(*this,lib,"jnc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnc >::invoke")
		->args({"self","addr"});
	using _method_625 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnc >;
	addExtern<DAS_CALL_METHOD(_method_625)>(*this,lib,"jnc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnc >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_626 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jne >;
	addExtern<DAS_CALL_METHOD(_method_626)>(*this,lib,"jne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jne >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_627 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jne >;
	addExtern<DAS_CALL_METHOD(_method_627)>(*this,lib,"jne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jne >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_628 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jne >;
	addExtern<DAS_CALL_METHOD(_method_628)>(*this,lib,"jne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jne >::invoke")
		->args({"self","addr"});
	using _method_629 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jne >;
	addExtern<DAS_CALL_METHOD(_method_629)>(*this,lib,"jne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jne >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_630 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jng >;
	addExtern<DAS_CALL_METHOD(_method_630)>(*this,lib,"jng",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jng >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_631 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jng >;
	addExtern<DAS_CALL_METHOD(_method_631)>(*this,lib,"jng",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jng >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_632 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jng >;
	addExtern<DAS_CALL_METHOD(_method_632)>(*this,lib,"jng",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jng >::invoke")
		->args({"self","addr"});
	using _method_633 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jng >;
	addExtern<DAS_CALL_METHOD(_method_633)>(*this,lib,"jng",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jng >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_634 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnge >;
	addExtern<DAS_CALL_METHOD(_method_634)>(*this,lib,"jnge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnge >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_635 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnge >;
	addExtern<DAS_CALL_METHOD(_method_635)>(*this,lib,"jnge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnge >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_636 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnge >;
	addExtern<DAS_CALL_METHOD(_method_636)>(*this,lib,"jnge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnge >::invoke")
		->args({"self","addr"});
	using _method_637 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnge >;
	addExtern<DAS_CALL_METHOD(_method_637)>(*this,lib,"jnge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnge >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_638 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnl >;
	addExtern<DAS_CALL_METHOD(_method_638)>(*this,lib,"jnl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnl >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_639 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnl >;
	addExtern<DAS_CALL_METHOD(_method_639)>(*this,lib,"jnl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnl >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_640 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnl >;
	addExtern<DAS_CALL_METHOD(_method_640)>(*this,lib,"jnl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnl >::invoke")
		->args({"self","addr"});
	using _method_641 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnl >;
	addExtern<DAS_CALL_METHOD(_method_641)>(*this,lib,"jnl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnl >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_642 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnle >;
	addExtern<DAS_CALL_METHOD(_method_642)>(*this,lib,"jnle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnle >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_643 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnle >;
	addExtern<DAS_CALL_METHOD(_method_643)>(*this,lib,"jnle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnle >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_644 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnle >;
	addExtern<DAS_CALL_METHOD(_method_644)>(*this,lib,"jnle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnle >::invoke")
		->args({"self","addr"});
	using _method_645 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnle >;
	addExtern<DAS_CALL_METHOD(_method_645)>(*this,lib,"jnle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnle >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_646 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jno >;
	addExtern<DAS_CALL_METHOD(_method_646)>(*this,lib,"jno",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jno >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_647 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jno >;
	addExtern<DAS_CALL_METHOD(_method_647)>(*this,lib,"jno",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jno >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_648 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jno >;
	addExtern<DAS_CALL_METHOD(_method_648)>(*this,lib,"jno",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jno >::invoke")
		->args({"self","addr"});
	using _method_649 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jno >;
	addExtern<DAS_CALL_METHOD(_method_649)>(*this,lib,"jno",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jno >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_650 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnp >;
	addExtern<DAS_CALL_METHOD(_method_650)>(*this,lib,"jnp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnp >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_651 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnp >;
	addExtern<DAS_CALL_METHOD(_method_651)>(*this,lib,"jnp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnp >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_652 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnp >;
	addExtern<DAS_CALL_METHOD(_method_652)>(*this,lib,"jnp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnp >::invoke")
		->args({"self","addr"});
	using _method_653 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnp >;
	addExtern<DAS_CALL_METHOD(_method_653)>(*this,lib,"jnp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnp >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_654 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jns >;
	addExtern<DAS_CALL_METHOD(_method_654)>(*this,lib,"jns",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jns >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_655 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jns >;
	addExtern<DAS_CALL_METHOD(_method_655)>(*this,lib,"jns",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jns >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_656 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jns >;
	addExtern<DAS_CALL_METHOD(_method_656)>(*this,lib,"jns",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jns >::invoke")
		->args({"self","addr"});
}
}

