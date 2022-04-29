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
void Module_dasXBYAK::initFunctions_17() {
	using _method_1557 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vtestpd >;
	addExtern<DAS_CALL_METHOD(_method_1557)>(*this,lib,"vtestpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vtestpd >::invoke")
		->args({"self","xm","op"});
	using _method_1558 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vtestps >;
	addExtern<DAS_CALL_METHOD(_method_1558)>(*this,lib,"vtestps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vtestps >::invoke")
		->args({"self","xm","op"});
	using _method_1559 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vucomisd >;
	addExtern<DAS_CALL_METHOD(_method_1559)>(*this,lib,"vucomisd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vucomisd >::invoke")
		->args({"self","xm","op"});
	using _method_1560 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vucomiss >;
	addExtern<DAS_CALL_METHOD(_method_1560)>(*this,lib,"vucomiss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vucomiss >::invoke")
		->args({"self","xm","op"});
	using _method_1561 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vunpckhpd >;
	addExtern<DAS_CALL_METHOD(_method_1561)>(*this,lib,"vunpckhpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vunpckhpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1562 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vunpckhps >;
	addExtern<DAS_CALL_METHOD(_method_1562)>(*this,lib,"vunpckhps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vunpckhps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1563 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vunpcklpd >;
	addExtern<DAS_CALL_METHOD(_method_1563)>(*this,lib,"vunpcklpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vunpcklpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1564 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vunpcklps >;
	addExtern<DAS_CALL_METHOD(_method_1564)>(*this,lib,"vunpcklps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vunpcklps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1565 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vxorpd >;
	addExtern<DAS_CALL_METHOD(_method_1565)>(*this,lib,"vxorpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vxorpd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1566 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vxorps >;
	addExtern<DAS_CALL_METHOD(_method_1566)>(*this,lib,"vxorps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vxorps >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1567 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::vzeroall >;
	addExtern<DAS_CALL_METHOD(_method_1567)>(*this,lib,"vzeroall",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::vzeroall >::invoke")
		->args({"self"});
	using _method_1568 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::vzeroupper >;
	addExtern<DAS_CALL_METHOD(_method_1568)>(*this,lib,"vzeroupper",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::vzeroupper >::invoke")
		->args({"self"});
	using _method_1569 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::wait >;
	addExtern<DAS_CALL_METHOD(_method_1569)>(*this,lib,"wait",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::wait >::invoke")
		->args({"self"});
	using _method_1570 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::wbinvd >;
	addExtern<DAS_CALL_METHOD(_method_1570)>(*this,lib,"wbinvd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::wbinvd >::invoke")
		->args({"self"});
	using _method_1571 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::wrmsr >;
	addExtern<DAS_CALL_METHOD(_method_1571)>(*this,lib,"wrmsr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::wrmsr >::invoke")
		->args({"self"});
	using _method_1572 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &),&Xbyak::CodeGenerator::xadd >;
	addExtern<DAS_CALL_METHOD(_method_1572)>(*this,lib,"xadd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &) , &Xbyak::CodeGenerator::xadd >::invoke")
		->args({"self","op","reg"});
	using _method_1573 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::xgetbv >;
	addExtern<DAS_CALL_METHOD(_method_1573)>(*this,lib,"xgetbv",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::xgetbv >::invoke")
		->args({"self"});
	using _method_1574 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::xlatb >;
	addExtern<DAS_CALL_METHOD(_method_1574)>(*this,lib,"xlatb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::xlatb >::invoke")
		->args({"self"});
	using _method_1575 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned int),&Xbyak::CodeGenerator::xor_ >;
	addExtern<DAS_CALL_METHOD(_method_1575)>(*this,lib,"xor_",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned int) , &Xbyak::CodeGenerator::xor_ >::invoke")
		->args({"self","op","imm"});
	using _method_1576 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::xor_ >;
	addExtern<DAS_CALL_METHOD(_method_1576)>(*this,lib,"xor_",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::xor_ >::invoke")
		->args({"self","op1","op2"});
	using _method_1577 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::xorpd >;
	addExtern<DAS_CALL_METHOD(_method_1577)>(*this,lib,"xorpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::xorpd >::invoke")
		->args({"self","xmm","op"});
	using _method_1578 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::xorps >;
	addExtern<DAS_CALL_METHOD(_method_1578)>(*this,lib,"xorps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::xorps >::invoke")
		->args({"self","xmm","op"});
	using _method_1579 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>),&Xbyak::CodeGenerator::jecxz >;
	addExtern<DAS_CALL_METHOD(_method_1579)>(*this,lib,"jecxz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>) , &Xbyak::CodeGenerator::jecxz >::invoke")
		->args({"self","label"});
	using _method_1580 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &),&Xbyak::CodeGenerator::jecxz >;
	addExtern<DAS_CALL_METHOD(_method_1580)>(*this,lib,"jecxz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &) , &Xbyak::CodeGenerator::jecxz >::invoke")
		->args({"self","label"});
	using _method_1581 = das::das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>),&Xbyak::CodeGenerator::jrcxz >;
	addExtern<DAS_CALL_METHOD(_method_1581)>(*this,lib,"jrcxz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(std::basic_string<char>) , &Xbyak::CodeGenerator::jrcxz >::invoke")
		->args({"self","label"});
	using _method_1582 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &),&Xbyak::CodeGenerator::jrcxz >;
	addExtern<DAS_CALL_METHOD(_method_1582)>(*this,lib,"jrcxz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Label &) , &Xbyak::CodeGenerator::jrcxz >::invoke")
		->args({"self","label"});
	using _method_1583 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cdqe >;
	addExtern<DAS_CALL_METHOD(_method_1583)>(*this,lib,"cdqe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cdqe >::invoke")
		->args({"self"});
	using _method_1584 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cqo >;
	addExtern<DAS_CALL_METHOD(_method_1584)>(*this,lib,"cqo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cqo >::invoke")
		->args({"self"});
	using _method_1585 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cmpsq >;
	addExtern<DAS_CALL_METHOD(_method_1585)>(*this,lib,"cmpsq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cmpsq >::invoke")
		->args({"self"});
	using _method_1586 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::popfq >;
	addExtern<DAS_CALL_METHOD(_method_1586)>(*this,lib,"popfq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::popfq >::invoke")
		->args({"self"});
	using _method_1587 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::pushfq >;
	addExtern<DAS_CALL_METHOD(_method_1587)>(*this,lib,"pushfq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::pushfq >::invoke")
		->args({"self"});
	using _method_1588 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::lodsq >;
	addExtern<DAS_CALL_METHOD(_method_1588)>(*this,lib,"lodsq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::lodsq >::invoke")
		->args({"self"});
	using _method_1589 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::movsq >;
	addExtern<DAS_CALL_METHOD(_method_1589)>(*this,lib,"movsq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::movsq >::invoke")
		->args({"self"});
	using _method_1590 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::scasq >;
	addExtern<DAS_CALL_METHOD(_method_1590)>(*this,lib,"scasq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::scasq >::invoke")
		->args({"self"});
	using _method_1591 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::stosq >;
	addExtern<DAS_CALL_METHOD(_method_1591)>(*this,lib,"stosq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::stosq >::invoke")
		->args({"self"});
	using _method_1592 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::syscall >;
	addExtern<DAS_CALL_METHOD(_method_1592)>(*this,lib,"syscall",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::syscall >::invoke")
		->args({"self"});
	using _method_1593 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::sysret >;
	addExtern<DAS_CALL_METHOD(_method_1593)>(*this,lib,"sysret",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::sysret >::invoke")
		->args({"self"});
	using _method_1594 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::cmpxchg16b >;
	addExtern<DAS_CALL_METHOD(_method_1594)>(*this,lib,"cmpxchg16b",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::cmpxchg16b >::invoke")
		->args({"self","addr"});
	using _method_1595 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::fxrstor64 >;
	addExtern<DAS_CALL_METHOD(_method_1595)>(*this,lib,"fxrstor64",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::fxrstor64 >::invoke")
		->args({"self","addr"});
	using _method_1596 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Mmx &),&Xbyak::CodeGenerator::movq >;
	addExtern<DAS_CALL_METHOD(_method_1596)>(*this,lib,"movq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Mmx &) , &Xbyak::CodeGenerator::movq >::invoke")
		->args({"self","reg","mmx"});
	using _method_1597 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Reg64 &),&Xbyak::CodeGenerator::movq >;
	addExtern<DAS_CALL_METHOD(_method_1597)>(*this,lib,"movq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Reg64 &) , &Xbyak::CodeGenerator::movq >::invoke")
		->args({"self","mmx","reg"});
	using _method_1598 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &),&Xbyak::CodeGenerator::movsxd >;
	addExtern<DAS_CALL_METHOD(_method_1598)>(*this,lib,"movsxd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::movsxd >::invoke")
		->args({"self","reg","op"});
	using _method_1599 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char),&Xbyak::CodeGenerator::pextrq >;
	addExtern<DAS_CALL_METHOD(_method_1599)>(*this,lib,"pextrq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char) , &Xbyak::CodeGenerator::pextrq >::invoke")
		->args({"self","op","xmm","imm"});
	using _method_1600 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::pinsrq >;
	addExtern<DAS_CALL_METHOD(_method_1600)>(*this,lib,"pinsrq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::pinsrq >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_1601 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtss2si >;
	addExtern<DAS_CALL_METHOD(_method_1601)>(*this,lib,"vcvtss2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtss2si >::invoke")
		->args({"self","r","op"});
	using _method_1602 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttss2si >;
	addExtern<DAS_CALL_METHOD(_method_1602)>(*this,lib,"vcvttss2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttss2si >::invoke")
		->args({"self","r","op"});
	using _method_1603 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtsd2si >;
	addExtern<DAS_CALL_METHOD(_method_1603)>(*this,lib,"vcvtsd2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtsd2si >::invoke")
		->args({"self","r","op"});
	using _method_1604 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttsd2si >;
	addExtern<DAS_CALL_METHOD(_method_1604)>(*this,lib,"vcvttsd2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttsd2si >::invoke")
		->args({"self","r","op"});
	using _method_1605 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg64 &),&Xbyak::CodeGenerator::vmovq >;
	addExtern<DAS_CALL_METHOD(_method_1605)>(*this,lib,"vmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg64 &) , &Xbyak::CodeGenerator::vmovq >::invoke")
		->args({"self","x","r"});
	using _method_1606 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovq >;
	addExtern<DAS_CALL_METHOD(_method_1606)>(*this,lib,"vmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovq >::invoke")
		->args({"self","r","x"});
	using _method_1607 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::ldtilecfg >;
	addExtern<DAS_CALL_METHOD(_method_1607)>(*this,lib,"ldtilecfg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::ldtilecfg >::invoke")
		->args({"self","addr"});
	using _method_1608 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::sttilecfg >;
	addExtern<DAS_CALL_METHOD(_method_1608)>(*this,lib,"sttilecfg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::sttilecfg >::invoke")
		->args({"self","addr"});
	using _method_1609 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::tileloadd >;
	addExtern<DAS_CALL_METHOD(_method_1609)>(*this,lib,"tileloadd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::tileloadd >::invoke")
		->args({"self","tm","addr"});
	using _method_1610 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::tileloaddt1 >;
	addExtern<DAS_CALL_METHOD(_method_1610)>(*this,lib,"tileloaddt1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::tileloaddt1 >::invoke")
		->args({"self","tm","addr"});
	using _method_1611 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::tilerelease >;
	addExtern<DAS_CALL_METHOD(_method_1611)>(*this,lib,"tilerelease",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::tilerelease >::invoke")
		->args({"self"});
	using _method_1612 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Tmm &),&Xbyak::CodeGenerator::tilestored >;
	addExtern<DAS_CALL_METHOD(_method_1612)>(*this,lib,"tilestored",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Tmm &) , &Xbyak::CodeGenerator::tilestored >::invoke")
		->args({"self","addr","tm"});
	using _method_1613 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &),&Xbyak::CodeGenerator::tilezero >;
	addExtern<DAS_CALL_METHOD(_method_1613)>(*this,lib,"tilezero",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &) , &Xbyak::CodeGenerator::tilezero >::invoke")
		->args({"self","Tmm"});
	using _method_1614 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &),&Xbyak::CodeGenerator::tdpbssd >;
	addExtern<DAS_CALL_METHOD(_method_1614)>(*this,lib,"tdpbssd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &) , &Xbyak::CodeGenerator::tdpbssd >::invoke")
		->args({"self","x1","x2","x3"});
	using _method_1615 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &),&Xbyak::CodeGenerator::tdpbsud >;
	addExtern<DAS_CALL_METHOD(_method_1615)>(*this,lib,"tdpbsud",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &) , &Xbyak::CodeGenerator::tdpbsud >::invoke")
		->args({"self","x1","x2","x3"});
	using _method_1616 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &),&Xbyak::CodeGenerator::tdpbusd >;
	addExtern<DAS_CALL_METHOD(_method_1616)>(*this,lib,"tdpbusd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &) , &Xbyak::CodeGenerator::tdpbusd >::invoke")
		->args({"self","x1","x2","x3"});
	using _method_1617 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &),&Xbyak::CodeGenerator::tdpbuud >;
	addExtern<DAS_CALL_METHOD(_method_1617)>(*this,lib,"tdpbuud",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &) , &Xbyak::CodeGenerator::tdpbuud >::invoke")
		->args({"self","x1","x2","x3"});
	using _method_1618 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &),&Xbyak::CodeGenerator::tdpbf16ps >;
	addExtern<DAS_CALL_METHOD(_method_1618)>(*this,lib,"tdpbf16ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Tmm &,const Xbyak::Tmm &,const Xbyak::Tmm &) , &Xbyak::CodeGenerator::tdpbf16ps >::invoke")
		->args({"self","x1","x2","x3"});
	using _method_1619 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kaddb >;
	addExtern<DAS_CALL_METHOD(_method_1619)>(*this,lib,"kaddb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kaddb >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1620 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kaddd >;
	addExtern<DAS_CALL_METHOD(_method_1620)>(*this,lib,"kaddd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kaddd >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1621 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kaddq >;
	addExtern<DAS_CALL_METHOD(_method_1621)>(*this,lib,"kaddq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kaddq >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1622 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kaddw >;
	addExtern<DAS_CALL_METHOD(_method_1622)>(*this,lib,"kaddw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kaddw >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1623 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kandb >;
	addExtern<DAS_CALL_METHOD(_method_1623)>(*this,lib,"kandb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kandb >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1624 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kandd >;
	addExtern<DAS_CALL_METHOD(_method_1624)>(*this,lib,"kandd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kandd >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1625 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kandnb >;
	addExtern<DAS_CALL_METHOD(_method_1625)>(*this,lib,"kandnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kandnb >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1626 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kandnd >;
	addExtern<DAS_CALL_METHOD(_method_1626)>(*this,lib,"kandnd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kandnd >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1627 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kandnq >;
	addExtern<DAS_CALL_METHOD(_method_1627)>(*this,lib,"kandnq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kandnq >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1628 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kandnw >;
	addExtern<DAS_CALL_METHOD(_method_1628)>(*this,lib,"kandnw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kandnw >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1629 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kandq >;
	addExtern<DAS_CALL_METHOD(_method_1629)>(*this,lib,"kandq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kandq >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1630 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kandw >;
	addExtern<DAS_CALL_METHOD(_method_1630)>(*this,lib,"kandw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kandw >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1631 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kmovb >;
	addExtern<DAS_CALL_METHOD(_method_1631)>(*this,lib,"kmovb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kmovb >::invoke")
		->args({"self","addr","k"});
	using _method_1632 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &),&Xbyak::CodeGenerator::kmovb >;
	addExtern<DAS_CALL_METHOD(_method_1632)>(*this,lib,"kmovb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::kmovb >::invoke")
		->args({"self","k","op"});
	using _method_1633 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Reg32 &),&Xbyak::CodeGenerator::kmovb >;
	addExtern<DAS_CALL_METHOD(_method_1633)>(*this,lib,"kmovb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Reg32 &) , &Xbyak::CodeGenerator::kmovb >::invoke")
		->args({"self","k","r"});
	using _method_1634 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32 &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kmovb >;
	addExtern<DAS_CALL_METHOD(_method_1634)>(*this,lib,"kmovb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32 &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kmovb >::invoke")
		->args({"self","r","k"});
	using _method_1635 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kmovd >;
	addExtern<DAS_CALL_METHOD(_method_1635)>(*this,lib,"kmovd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kmovd >::invoke")
		->args({"self","addr","k"});
	using _method_1636 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &),&Xbyak::CodeGenerator::kmovd >;
	addExtern<DAS_CALL_METHOD(_method_1636)>(*this,lib,"kmovd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::kmovd >::invoke")
		->args({"self","k","op"});
	using _method_1637 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Reg32 &),&Xbyak::CodeGenerator::kmovd >;
	addExtern<DAS_CALL_METHOD(_method_1637)>(*this,lib,"kmovd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Reg32 &) , &Xbyak::CodeGenerator::kmovd >::invoke")
		->args({"self","k","r"});
	using _method_1638 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32 &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kmovd >;
	addExtern<DAS_CALL_METHOD(_method_1638)>(*this,lib,"kmovd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32 &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kmovd >::invoke")
		->args({"self","r","k"});
	using _method_1639 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kmovq >;
	addExtern<DAS_CALL_METHOD(_method_1639)>(*this,lib,"kmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kmovq >::invoke")
		->args({"self","addr","k"});
	using _method_1640 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &),&Xbyak::CodeGenerator::kmovq >;
	addExtern<DAS_CALL_METHOD(_method_1640)>(*this,lib,"kmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::kmovq >::invoke")
		->args({"self","k","op"});
	using _method_1641 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kmovw >;
	addExtern<DAS_CALL_METHOD(_method_1641)>(*this,lib,"kmovw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kmovw >::invoke")
		->args({"self","addr","k"});
	using _method_1642 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &),&Xbyak::CodeGenerator::kmovw >;
	addExtern<DAS_CALL_METHOD(_method_1642)>(*this,lib,"kmovw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::kmovw >::invoke")
		->args({"self","k","op"});
	using _method_1643 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Reg32 &),&Xbyak::CodeGenerator::kmovw >;
	addExtern<DAS_CALL_METHOD(_method_1643)>(*this,lib,"kmovw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Reg32 &) , &Xbyak::CodeGenerator::kmovw >::invoke")
		->args({"self","k","r"});
	using _method_1644 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32 &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kmovw >;
	addExtern<DAS_CALL_METHOD(_method_1644)>(*this,lib,"kmovw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32 &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kmovw >::invoke")
		->args({"self","r","k"});
	using _method_1645 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::knotb >;
	addExtern<DAS_CALL_METHOD(_method_1645)>(*this,lib,"knotb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::knotb >::invoke")
		->args({"self","r1","r2"});
	using _method_1646 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::knotd >;
	addExtern<DAS_CALL_METHOD(_method_1646)>(*this,lib,"knotd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::knotd >::invoke")
		->args({"self","r1","r2"});
	using _method_1647 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::knotq >;
	addExtern<DAS_CALL_METHOD(_method_1647)>(*this,lib,"knotq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::knotq >::invoke")
		->args({"self","r1","r2"});
	using _method_1648 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::knotw >;
	addExtern<DAS_CALL_METHOD(_method_1648)>(*this,lib,"knotw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::knotw >::invoke")
		->args({"self","r1","r2"});
	using _method_1649 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::korb >;
	addExtern<DAS_CALL_METHOD(_method_1649)>(*this,lib,"korb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::korb >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1650 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kord >;
	addExtern<DAS_CALL_METHOD(_method_1650)>(*this,lib,"kord",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kord >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1651 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::korq >;
	addExtern<DAS_CALL_METHOD(_method_1651)>(*this,lib,"korq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::korq >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1652 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kortestb >;
	addExtern<DAS_CALL_METHOD(_method_1652)>(*this,lib,"kortestb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kortestb >::invoke")
		->args({"self","r1","r2"});
	using _method_1653 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kortestd >;
	addExtern<DAS_CALL_METHOD(_method_1653)>(*this,lib,"kortestd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kortestd >::invoke")
		->args({"self","r1","r2"});
	using _method_1654 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kortestq >;
	addExtern<DAS_CALL_METHOD(_method_1654)>(*this,lib,"kortestq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kortestq >::invoke")
		->args({"self","r1","r2"});
	using _method_1655 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kortestw >;
	addExtern<DAS_CALL_METHOD(_method_1655)>(*this,lib,"kortestw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kortestw >::invoke")
		->args({"self","r1","r2"});
	using _method_1656 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::korw >;
	addExtern<DAS_CALL_METHOD(_method_1656)>(*this,lib,"korw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::korw >::invoke")
		->args({"self","r1","r2","r3"});
}
}

