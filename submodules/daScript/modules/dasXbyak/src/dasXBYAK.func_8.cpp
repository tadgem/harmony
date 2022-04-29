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
void Module_dasXBYAK::initFunctions_8() {
	using _method_657 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jns >;
	addExtern<DAS_CALL_METHOD(_method_657)>(*this,lib,"jns",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jns >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_658 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnz >;
	addExtern<DAS_CALL_METHOD(_method_658)>(*this,lib,"jnz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnz >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_659 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnz >;
	addExtern<DAS_CALL_METHOD(_method_659)>(*this,lib,"jnz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnz >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_660 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jnz >;
	addExtern<DAS_CALL_METHOD(_method_660)>(*this,lib,"jnz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jnz >::invoke")
		->args({"self","addr"});
	using _method_661 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jnz >;
	addExtern<DAS_CALL_METHOD(_method_661)>(*this,lib,"jnz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jnz >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_662 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jo >;
	addExtern<DAS_CALL_METHOD(_method_662)>(*this,lib,"jo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jo >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_663 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jo >;
	addExtern<DAS_CALL_METHOD(_method_663)>(*this,lib,"jo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jo >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_664 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jo >;
	addExtern<DAS_CALL_METHOD(_method_664)>(*this,lib,"jo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jo >::invoke")
		->args({"self","addr"});
	using _method_665 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jo >;
	addExtern<DAS_CALL_METHOD(_method_665)>(*this,lib,"jo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jo >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_666 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jp >;
	addExtern<DAS_CALL_METHOD(_method_666)>(*this,lib,"jp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jp >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_667 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jp >;
	addExtern<DAS_CALL_METHOD(_method_667)>(*this,lib,"jp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jp >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_668 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jp >;
	addExtern<DAS_CALL_METHOD(_method_668)>(*this,lib,"jp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jp >::invoke")
		->args({"self","addr"});
	using _method_669 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jp >;
	addExtern<DAS_CALL_METHOD(_method_669)>(*this,lib,"jp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jp >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_670 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jpe >;
	addExtern<DAS_CALL_METHOD(_method_670)>(*this,lib,"jpe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jpe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_671 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jpe >;
	addExtern<DAS_CALL_METHOD(_method_671)>(*this,lib,"jpe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jpe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_672 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jpe >;
	addExtern<DAS_CALL_METHOD(_method_672)>(*this,lib,"jpe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jpe >::invoke")
		->args({"self","addr"});
	using _method_673 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jpe >;
	addExtern<DAS_CALL_METHOD(_method_673)>(*this,lib,"jpe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jpe >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_674 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jpo >;
	addExtern<DAS_CALL_METHOD(_method_674)>(*this,lib,"jpo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jpo >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_675 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jpo >;
	addExtern<DAS_CALL_METHOD(_method_675)>(*this,lib,"jpo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jpo >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_676 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jpo >;
	addExtern<DAS_CALL_METHOD(_method_676)>(*this,lib,"jpo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jpo >::invoke")
		->args({"self","addr"});
	using _method_677 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jpo >;
	addExtern<DAS_CALL_METHOD(_method_677)>(*this,lib,"jpo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jpo >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_678 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::js >;
	addExtern<DAS_CALL_METHOD(_method_678)>(*this,lib,"js",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::js >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_679 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::js >;
	addExtern<DAS_CALL_METHOD(_method_679)>(*this,lib,"js",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::js >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_680 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::js >;
	addExtern<DAS_CALL_METHOD(_method_680)>(*this,lib,"js",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::js >::invoke")
		->args({"self","addr"});
	using _method_681 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::js >;
	addExtern<DAS_CALL_METHOD(_method_681)>(*this,lib,"js",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::js >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_682 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jz >;
	addExtern<DAS_CALL_METHOD(_method_682)>(*this,lib,"jz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jz >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_683 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jz >;
	addExtern<DAS_CALL_METHOD(_method_683)>(*this,lib,"jz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jz >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_684 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *),&Xbyak::CodeGenerator::jz >;
	addExtern<DAS_CALL_METHOD(_method_684)>(*this,lib,"jz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *) , &Xbyak::CodeGenerator::jz >::invoke")
		->args({"self","addr"});
	using _method_685 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType),&Xbyak::CodeGenerator::jz >;
	addExtern<DAS_CALL_METHOD(_method_685)>(*this,lib,"jz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>,Xbyak::CodeGenerator::LabelType) , &Xbyak::CodeGenerator::jz >::invoke")
		->args({"self","label","type"})
		->arg_init(2,make_smart<ExprConstEnumeration>(2,makeType<Xbyak::CodeGenerator::LabelType>(lib)));
	using _method_686 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::lahf >;
	addExtern<DAS_CALL_METHOD(_method_686)>(*this,lib,"lahf",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::lahf >::invoke")
		->args({"self"});
	using _method_687 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::lddqu >;
	addExtern<DAS_CALL_METHOD(_method_687)>(*this,lib,"lddqu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::lddqu >::invoke")
		->args({"self","xmm","addr"});
	using _method_688 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::ldmxcsr >;
	addExtern<DAS_CALL_METHOD(_method_688)>(*this,lib,"ldmxcsr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::ldmxcsr >::invoke")
		->args({"self","addr"});
	using _method_689 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &),&Xbyak::CodeGenerator::lea >;
	addExtern<DAS_CALL_METHOD(_method_689)>(*this,lib,"lea",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &) , &Xbyak::CodeGenerator::lea >::invoke")
		->args({"self","reg","addr"});
	using _method_690 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::leave >;
	addExtern<DAS_CALL_METHOD(_method_690)>(*this,lib,"leave",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::leave >::invoke")
		->args({"self"});
	using _method_691 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::lfence >;
	addExtern<DAS_CALL_METHOD(_method_691)>(*this,lib,"lfence",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::lfence >::invoke")
		->args({"self"});
	using _method_692 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &),&Xbyak::CodeGenerator::lfs >;
	addExtern<DAS_CALL_METHOD(_method_692)>(*this,lib,"lfs",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &) , &Xbyak::CodeGenerator::lfs >::invoke")
		->args({"self","reg","addr"});
	using _method_693 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &),&Xbyak::CodeGenerator::lgs >;
	addExtern<DAS_CALL_METHOD(_method_693)>(*this,lib,"lgs",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &) , &Xbyak::CodeGenerator::lgs >::invoke")
		->args({"self","reg","addr"});
	using _method_694 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::lock >;
	addExtern<DAS_CALL_METHOD(_method_694)>(*this,lib,"lock",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::lock >::invoke")
		->args({"self"});
	using _method_695 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::lodsb >;
	addExtern<DAS_CALL_METHOD(_method_695)>(*this,lib,"lodsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::lodsb >::invoke")
		->args({"self"});
	using _method_696 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::lodsd >;
	addExtern<DAS_CALL_METHOD(_method_696)>(*this,lib,"lodsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::lodsd >::invoke")
		->args({"self"});
	using _method_697 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::lodsw >;
	addExtern<DAS_CALL_METHOD(_method_697)>(*this,lib,"lodsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::lodsw >::invoke")
		->args({"self"});
	using _method_698 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &),&Xbyak::CodeGenerator::loop >;
	addExtern<DAS_CALL_METHOD(_method_698)>(*this,lib,"loop",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &) , &Xbyak::CodeGenerator::loop >::invoke")
		->args({"self","label"});
	using _method_699 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *),&Xbyak::CodeGenerator::loop >;
	addExtern<DAS_CALL_METHOD(_method_699)>(*this,lib,"loop",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *) , &Xbyak::CodeGenerator::loop >::invoke")
		->args({"self","label"});
	using _method_700 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>),&Xbyak::CodeGenerator::loop >;
	addExtern<DAS_CALL_METHOD(_method_700)>(*this,lib,"loop",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>) , &Xbyak::CodeGenerator::loop >::invoke")
		->args({"self","label"});
	using _method_701 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &),&Xbyak::CodeGenerator::loope >;
	addExtern<DAS_CALL_METHOD(_method_701)>(*this,lib,"loope",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &) , &Xbyak::CodeGenerator::loope >::invoke")
		->args({"self","label"});
	using _method_702 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *),&Xbyak::CodeGenerator::loope >;
	addExtern<DAS_CALL_METHOD(_method_702)>(*this,lib,"loope",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *) , &Xbyak::CodeGenerator::loope >::invoke")
		->args({"self","label"});
	using _method_703 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>),&Xbyak::CodeGenerator::loope >;
	addExtern<DAS_CALL_METHOD(_method_703)>(*this,lib,"loope",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>) , &Xbyak::CodeGenerator::loope >::invoke")
		->args({"self","label"});
	using _method_704 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &),&Xbyak::CodeGenerator::loopne >;
	addExtern<DAS_CALL_METHOD(_method_704)>(*this,lib,"loopne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &) , &Xbyak::CodeGenerator::loopne >::invoke")
		->args({"self","label"});
	using _method_705 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const char *),&Xbyak::CodeGenerator::loopne >;
	addExtern<DAS_CALL_METHOD(_method_705)>(*this,lib,"loopne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const char *) , &Xbyak::CodeGenerator::loopne >::invoke")
		->args({"self","label"});
	using _method_706 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>),&Xbyak::CodeGenerator::loopne >;
	addExtern<DAS_CALL_METHOD(_method_706)>(*this,lib,"loopne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>) , &Xbyak::CodeGenerator::loopne >::invoke")
		->args({"self","label"});
	using _method_707 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &),&Xbyak::CodeGenerator::lss >;
	addExtern<DAS_CALL_METHOD(_method_707)>(*this,lib,"lss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &) , &Xbyak::CodeGenerator::lss >::invoke")
		->args({"self","reg","addr"});
	using _method_708 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::lzcnt >;
	addExtern<DAS_CALL_METHOD(_method_708)>(*this,lib,"lzcnt",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::lzcnt >::invoke")
		->args({"self","reg","op"});
	using _method_709 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::maskmovdqu >;
	addExtern<DAS_CALL_METHOD(_method_709)>(*this,lib,"maskmovdqu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::maskmovdqu >::invoke")
		->args({"self","reg1","reg2"});
	using _method_710 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Mmx &),&Xbyak::CodeGenerator::maskmovq >;
	addExtern<DAS_CALL_METHOD(_method_710)>(*this,lib,"maskmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Mmx &) , &Xbyak::CodeGenerator::maskmovq >::invoke")
		->args({"self","reg1","reg2"});
	using _method_711 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::maxpd >;
	addExtern<DAS_CALL_METHOD(_method_711)>(*this,lib,"maxpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::maxpd >::invoke")
		->args({"self","xmm","op"});
	using _method_712 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::maxps >;
	addExtern<DAS_CALL_METHOD(_method_712)>(*this,lib,"maxps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::maxps >::invoke")
		->args({"self","xmm","op"});
	using _method_713 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::maxsd >;
	addExtern<DAS_CALL_METHOD(_method_713)>(*this,lib,"maxsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::maxsd >::invoke")
		->args({"self","xmm","op"});
	using _method_714 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::maxss >;
	addExtern<DAS_CALL_METHOD(_method_714)>(*this,lib,"maxss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::maxss >::invoke")
		->args({"self","xmm","op"});
	using _method_715 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::mfence >;
	addExtern<DAS_CALL_METHOD(_method_715)>(*this,lib,"mfence",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::mfence >::invoke")
		->args({"self"});
	using _method_716 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::minpd >;
	addExtern<DAS_CALL_METHOD(_method_716)>(*this,lib,"minpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::minpd >::invoke")
		->args({"self","xmm","op"});
	using _method_717 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::minps >;
	addExtern<DAS_CALL_METHOD(_method_717)>(*this,lib,"minps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::minps >::invoke")
		->args({"self","xmm","op"});
	using _method_718 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::minsd >;
	addExtern<DAS_CALL_METHOD(_method_718)>(*this,lib,"minsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::minsd >::invoke")
		->args({"self","xmm","op"});
	using _method_719 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::minss >;
	addExtern<DAS_CALL_METHOD(_method_719)>(*this,lib,"minss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::minss >::invoke")
		->args({"self","xmm","op"});
	using _method_720 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::monitor >;
	addExtern<DAS_CALL_METHOD(_method_720)>(*this,lib,"monitor",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::monitor >::invoke")
		->args({"self"});
	using _method_721 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::monitorx >;
	addExtern<DAS_CALL_METHOD(_method_721)>(*this,lib,"monitorx",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::monitorx >::invoke")
		->args({"self"});
	using _method_722 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movapd >;
	addExtern<DAS_CALL_METHOD(_method_722)>(*this,lib,"movapd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movapd >::invoke")
		->args({"self","addr","xmm"});
	using _method_723 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movapd >;
	addExtern<DAS_CALL_METHOD(_method_723)>(*this,lib,"movapd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movapd >::invoke")
		->args({"self","xmm","op"});
	using _method_724 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movaps >;
	addExtern<DAS_CALL_METHOD(_method_724)>(*this,lib,"movaps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movaps >::invoke")
		->args({"self","addr","xmm"});
	using _method_725 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movaps >;
	addExtern<DAS_CALL_METHOD(_method_725)>(*this,lib,"movaps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movaps >::invoke")
		->args({"self","xmm","op"});
	using _method_726 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg &),&Xbyak::CodeGenerator::movbe >;
	addExtern<DAS_CALL_METHOD(_method_726)>(*this,lib,"movbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg &) , &Xbyak::CodeGenerator::movbe >::invoke")
		->args({"self","addr","reg"});
	using _method_727 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &),&Xbyak::CodeGenerator::movbe >;
	addExtern<DAS_CALL_METHOD(_method_727)>(*this,lib,"movbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Address &) , &Xbyak::CodeGenerator::movbe >::invoke")
		->args({"self","reg","addr"});
	using _method_728 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Mmx &),&Xbyak::CodeGenerator::movd >;
	addExtern<DAS_CALL_METHOD(_method_728)>(*this,lib,"movd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Mmx &) , &Xbyak::CodeGenerator::movd >::invoke")
		->args({"self","addr","mmx"});
	using _method_729 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Address &),&Xbyak::CodeGenerator::movd >;
	addExtern<DAS_CALL_METHOD(_method_729)>(*this,lib,"movd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Address &) , &Xbyak::CodeGenerator::movd >::invoke")
		->args({"self","mmx","addr"});
	using _method_730 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Reg32 &),&Xbyak::CodeGenerator::movd >;
	addExtern<DAS_CALL_METHOD(_method_730)>(*this,lib,"movd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Reg32 &) , &Xbyak::CodeGenerator::movd >::invoke")
		->args({"self","mmx","reg"});
	using _method_731 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32 &,const Xbyak::Mmx &),&Xbyak::CodeGenerator::movd >;
	addExtern<DAS_CALL_METHOD(_method_731)>(*this,lib,"movd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32 &,const Xbyak::Mmx &) , &Xbyak::CodeGenerator::movd >::invoke")
		->args({"self","reg","mmx"});
	using _method_732 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movddup >;
	addExtern<DAS_CALL_METHOD(_method_732)>(*this,lib,"movddup",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movddup >::invoke")
		->args({"self","xmm","op"});
	using _method_733 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movdq2q >;
	addExtern<DAS_CALL_METHOD(_method_733)>(*this,lib,"movdq2q",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movdq2q >::invoke")
		->args({"self","mmx","xmm"});
	using _method_734 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movdqa >;
	addExtern<DAS_CALL_METHOD(_method_734)>(*this,lib,"movdqa",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movdqa >::invoke")
		->args({"self","addr","xmm"});
	using _method_735 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movdqa >;
	addExtern<DAS_CALL_METHOD(_method_735)>(*this,lib,"movdqa",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movdqa >::invoke")
		->args({"self","xmm","op"});
	using _method_736 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movdqu >;
	addExtern<DAS_CALL_METHOD(_method_736)>(*this,lib,"movdqu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movdqu >::invoke")
		->args({"self","addr","xmm"});
	using _method_737 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movdqu >;
	addExtern<DAS_CALL_METHOD(_method_737)>(*this,lib,"movdqu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movdqu >::invoke")
		->args({"self","xmm","op"});
	using _method_738 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movhlps >;
	addExtern<DAS_CALL_METHOD(_method_738)>(*this,lib,"movhlps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movhlps >::invoke")
		->args({"self","reg1","reg2"});
	using _method_739 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movhpd >;
	addExtern<DAS_CALL_METHOD(_method_739)>(*this,lib,"movhpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movhpd >::invoke")
		->args({"self","op1","op2"});
	using _method_740 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movhps >;
	addExtern<DAS_CALL_METHOD(_method_740)>(*this,lib,"movhps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movhps >::invoke")
		->args({"self","op1","op2"});
	using _method_741 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movlhps >;
	addExtern<DAS_CALL_METHOD(_method_741)>(*this,lib,"movlhps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movlhps >::invoke")
		->args({"self","reg1","reg2"});
	using _method_742 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movlpd >;
	addExtern<DAS_CALL_METHOD(_method_742)>(*this,lib,"movlpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movlpd >::invoke")
		->args({"self","op1","op2"});
	using _method_743 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movlps >;
	addExtern<DAS_CALL_METHOD(_method_743)>(*this,lib,"movlps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movlps >::invoke")
		->args({"self","op1","op2"});
	using _method_744 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movmskpd >;
	addExtern<DAS_CALL_METHOD(_method_744)>(*this,lib,"movmskpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movmskpd >::invoke")
		->args({"self","reg","xmm"});
	using _method_745 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movmskps >;
	addExtern<DAS_CALL_METHOD(_method_745)>(*this,lib,"movmskps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movmskps >::invoke")
		->args({"self","reg","xmm"});
	using _method_746 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movntdq >;
	addExtern<DAS_CALL_METHOD(_method_746)>(*this,lib,"movntdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movntdq >::invoke")
		->args({"self","addr","reg"});
	using _method_747 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::movntdqa >;
	addExtern<DAS_CALL_METHOD(_method_747)>(*this,lib,"movntdqa",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::movntdqa >::invoke")
		->args({"self","xmm","addr"});
	using _method_748 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg32e &),&Xbyak::CodeGenerator::movnti >;
	addExtern<DAS_CALL_METHOD(_method_748)>(*this,lib,"movnti",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg32e &) , &Xbyak::CodeGenerator::movnti >::invoke")
		->args({"self","addr","reg"});
	using _method_749 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movntpd >;
	addExtern<DAS_CALL_METHOD(_method_749)>(*this,lib,"movntpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movntpd >::invoke")
		->args({"self","addr","reg"});
	using _method_750 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::movntps >;
	addExtern<DAS_CALL_METHOD(_method_750)>(*this,lib,"movntps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::movntps >::invoke")
		->args({"self","addr","xmm"});
	using _method_751 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Mmx &),&Xbyak::CodeGenerator::movntq >;
	addExtern<DAS_CALL_METHOD(_method_751)>(*this,lib,"movntq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Mmx &) , &Xbyak::CodeGenerator::movntq >::invoke")
		->args({"self","addr","mmx"});
	using _method_752 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Mmx &),&Xbyak::CodeGenerator::movq >;
	addExtern<DAS_CALL_METHOD(_method_752)>(*this,lib,"movq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Mmx &) , &Xbyak::CodeGenerator::movq >::invoke")
		->args({"self","addr","mmx"});
	using _method_753 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movq >;
	addExtern<DAS_CALL_METHOD(_method_753)>(*this,lib,"movq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movq >::invoke")
		->args({"self","mmx","op"});
	using _method_754 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Mmx &),&Xbyak::CodeGenerator::movq2dq >;
	addExtern<DAS_CALL_METHOD(_method_754)>(*this,lib,"movq2dq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Mmx &) , &Xbyak::CodeGenerator::movq2dq >::invoke")
		->args({"self","xmm","mmx"});
	using _method_755 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::movsb >;
	addExtern<DAS_CALL_METHOD(_method_755)>(*this,lib,"movsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::movsb >::invoke")
		->args({"self"});
	using _method_756 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::movsd >;
	addExtern<DAS_CALL_METHOD(_method_756)>(*this,lib,"movsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::movsd >::invoke")
		->args({"self"});
}
}

