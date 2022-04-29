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
void Module_dasXBYAK::initFunctions_18() {
	using _method_1657 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char),&Xbyak::CodeGenerator::kshiftlb >;
	addExtern<DAS_CALL_METHOD(_method_1657)>(*this,lib,"kshiftlb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char) , &Xbyak::CodeGenerator::kshiftlb >::invoke")
		->args({"self","r1","r2","imm"});
	using _method_1658 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char),&Xbyak::CodeGenerator::kshiftld >;
	addExtern<DAS_CALL_METHOD(_method_1658)>(*this,lib,"kshiftld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char) , &Xbyak::CodeGenerator::kshiftld >::invoke")
		->args({"self","r1","r2","imm"});
	using _method_1659 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char),&Xbyak::CodeGenerator::kshiftlq >;
	addExtern<DAS_CALL_METHOD(_method_1659)>(*this,lib,"kshiftlq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char) , &Xbyak::CodeGenerator::kshiftlq >::invoke")
		->args({"self","r1","r2","imm"});
	using _method_1660 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char),&Xbyak::CodeGenerator::kshiftlw >;
	addExtern<DAS_CALL_METHOD(_method_1660)>(*this,lib,"kshiftlw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char) , &Xbyak::CodeGenerator::kshiftlw >::invoke")
		->args({"self","r1","r2","imm"});
	using _method_1661 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char),&Xbyak::CodeGenerator::kshiftrb >;
	addExtern<DAS_CALL_METHOD(_method_1661)>(*this,lib,"kshiftrb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char) , &Xbyak::CodeGenerator::kshiftrb >::invoke")
		->args({"self","r1","r2","imm"});
	using _method_1662 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char),&Xbyak::CodeGenerator::kshiftrd >;
	addExtern<DAS_CALL_METHOD(_method_1662)>(*this,lib,"kshiftrd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char) , &Xbyak::CodeGenerator::kshiftrd >::invoke")
		->args({"self","r1","r2","imm"});
	using _method_1663 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char),&Xbyak::CodeGenerator::kshiftrq >;
	addExtern<DAS_CALL_METHOD(_method_1663)>(*this,lib,"kshiftrq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char) , &Xbyak::CodeGenerator::kshiftrq >::invoke")
		->args({"self","r1","r2","imm"});
	using _method_1664 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char),&Xbyak::CodeGenerator::kshiftrw >;
	addExtern<DAS_CALL_METHOD(_method_1664)>(*this,lib,"kshiftrw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,unsigned char) , &Xbyak::CodeGenerator::kshiftrw >::invoke")
		->args({"self","r1","r2","imm"});
	using _method_1665 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::ktestb >;
	addExtern<DAS_CALL_METHOD(_method_1665)>(*this,lib,"ktestb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::ktestb >::invoke")
		->args({"self","r1","r2"});
	using _method_1666 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::ktestd >;
	addExtern<DAS_CALL_METHOD(_method_1666)>(*this,lib,"ktestd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::ktestd >::invoke")
		->args({"self","r1","r2"});
	using _method_1667 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::ktestq >;
	addExtern<DAS_CALL_METHOD(_method_1667)>(*this,lib,"ktestq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::ktestq >::invoke")
		->args({"self","r1","r2"});
	using _method_1668 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::ktestw >;
	addExtern<DAS_CALL_METHOD(_method_1668)>(*this,lib,"ktestw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::ktestw >::invoke")
		->args({"self","r1","r2"});
	using _method_1669 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kunpckbw >;
	addExtern<DAS_CALL_METHOD(_method_1669)>(*this,lib,"kunpckbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kunpckbw >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1670 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kunpckdq >;
	addExtern<DAS_CALL_METHOD(_method_1670)>(*this,lib,"kunpckdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kunpckdq >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1671 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kunpckwd >;
	addExtern<DAS_CALL_METHOD(_method_1671)>(*this,lib,"kunpckwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kunpckwd >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1672 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kxnorb >;
	addExtern<DAS_CALL_METHOD(_method_1672)>(*this,lib,"kxnorb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kxnorb >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1673 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kxnord >;
	addExtern<DAS_CALL_METHOD(_method_1673)>(*this,lib,"kxnord",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kxnord >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1674 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kxnorq >;
	addExtern<DAS_CALL_METHOD(_method_1674)>(*this,lib,"kxnorq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kxnorq >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1675 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kxnorw >;
	addExtern<DAS_CALL_METHOD(_method_1675)>(*this,lib,"kxnorw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kxnorw >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1676 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kxorb >;
	addExtern<DAS_CALL_METHOD(_method_1676)>(*this,lib,"kxorb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kxorb >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1677 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kxord >;
	addExtern<DAS_CALL_METHOD(_method_1677)>(*this,lib,"kxord",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kxord >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1678 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kxorq >;
	addExtern<DAS_CALL_METHOD(_method_1678)>(*this,lib,"kxorq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kxorq >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1679 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kxorw >;
	addExtern<DAS_CALL_METHOD(_method_1679)>(*this,lib,"kxorw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Opmask &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kxorw >::invoke")
		->args({"self","r1","r2","r3"});
	using _method_1680 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::v4fmaddps >;
	addExtern<DAS_CALL_METHOD(_method_1680)>(*this,lib,"v4fmaddps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::v4fmaddps >::invoke")
		->args({"self","z1","z2","addr"});
	using _method_1681 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::v4fmaddss >;
	addExtern<DAS_CALL_METHOD(_method_1681)>(*this,lib,"v4fmaddss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::v4fmaddss >::invoke")
		->args({"self","x1","x2","addr"});
	using _method_1682 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::v4fnmaddps >;
	addExtern<DAS_CALL_METHOD(_method_1682)>(*this,lib,"v4fnmaddps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::v4fnmaddps >::invoke")
		->args({"self","z1","z2","addr"});
	using _method_1683 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::v4fnmaddss >;
	addExtern<DAS_CALL_METHOD(_method_1683)>(*this,lib,"v4fnmaddss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::v4fnmaddss >::invoke")
		->args({"self","x1","x2","addr"});
	using _method_1684 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaddph >;
	addExtern<DAS_CALL_METHOD(_method_1684)>(*this,lib,"vaddph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaddph >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1685 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaddsh >;
	addExtern<DAS_CALL_METHOD(_method_1685)>(*this,lib,"vaddsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaddsh >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1686 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::valignd >;
	addExtern<DAS_CALL_METHOD(_method_1686)>(*this,lib,"valignd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::valignd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1687 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::valignq >;
	addExtern<DAS_CALL_METHOD(_method_1687)>(*this,lib,"valignq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::valignq >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1688 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vblendmpd >;
	addExtern<DAS_CALL_METHOD(_method_1688)>(*this,lib,"vblendmpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vblendmpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1689 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vblendmps >;
	addExtern<DAS_CALL_METHOD(_method_1689)>(*this,lib,"vblendmps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vblendmps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1690 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vbroadcastf32x2 >;
	addExtern<DAS_CALL_METHOD(_method_1690)>(*this,lib,"vbroadcastf32x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vbroadcastf32x2 >::invoke")
		->args({"self","y","op"});
	using _method_1691 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vbroadcastf32x4 >;
	addExtern<DAS_CALL_METHOD(_method_1691)>(*this,lib,"vbroadcastf32x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vbroadcastf32x4 >::invoke")
		->args({"self","y","addr"});
	using _method_1692 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vbroadcastf32x8 >;
	addExtern<DAS_CALL_METHOD(_method_1692)>(*this,lib,"vbroadcastf32x8",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vbroadcastf32x8 >::invoke")
		->args({"self","y","addr"});
	using _method_1693 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vbroadcastf64x2 >;
	addExtern<DAS_CALL_METHOD(_method_1693)>(*this,lib,"vbroadcastf64x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vbroadcastf64x2 >::invoke")
		->args({"self","y","addr"});
	using _method_1694 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vbroadcastf64x4 >;
	addExtern<DAS_CALL_METHOD(_method_1694)>(*this,lib,"vbroadcastf64x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vbroadcastf64x4 >::invoke")
		->args({"self","y","addr"});
	using _method_1695 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vbroadcasti32x2 >;
	addExtern<DAS_CALL_METHOD(_method_1695)>(*this,lib,"vbroadcasti32x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vbroadcasti32x2 >::invoke")
		->args({"self","x","op"});
	using _method_1696 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vbroadcasti32x4 >;
	addExtern<DAS_CALL_METHOD(_method_1696)>(*this,lib,"vbroadcasti32x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vbroadcasti32x4 >::invoke")
		->args({"self","y","op"});
	using _method_1697 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vbroadcasti32x8 >;
	addExtern<DAS_CALL_METHOD(_method_1697)>(*this,lib,"vbroadcasti32x8",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vbroadcasti32x8 >::invoke")
		->args({"self","z","op"});
	using _method_1698 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vbroadcasti64x2 >;
	addExtern<DAS_CALL_METHOD(_method_1698)>(*this,lib,"vbroadcasti64x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vbroadcasti64x2 >::invoke")
		->args({"self","y","op"});
	using _method_1699 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vbroadcasti64x4 >;
	addExtern<DAS_CALL_METHOD(_method_1699)>(*this,lib,"vbroadcasti64x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vbroadcasti64x4 >::invoke")
		->args({"self","z","op"});
	using _method_1700 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_ospd >;
	addExtern<DAS_CALL_METHOD(_method_1700)>(*this,lib,"vcmpeq_ospd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_ospd >::invoke")
		->args({"self","k","x","op"});
	using _method_1701 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_osps >;
	addExtern<DAS_CALL_METHOD(_method_1701)>(*this,lib,"vcmpeq_osps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_osps >::invoke")
		->args({"self","k","x","op"});
	using _method_1702 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_ossd >;
	addExtern<DAS_CALL_METHOD(_method_1702)>(*this,lib,"vcmpeq_ossd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_ossd >::invoke")
		->args({"self","k","x","op"});
	using _method_1703 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_osss >;
	addExtern<DAS_CALL_METHOD(_method_1703)>(*this,lib,"vcmpeq_osss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_osss >::invoke")
		->args({"self","k","x","op"});
	using _method_1704 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uqpd >;
	addExtern<DAS_CALL_METHOD(_method_1704)>(*this,lib,"vcmpeq_uqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uqpd >::invoke")
		->args({"self","k","x","op"});
	using _method_1705 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uqps >;
	addExtern<DAS_CALL_METHOD(_method_1705)>(*this,lib,"vcmpeq_uqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uqps >::invoke")
		->args({"self","k","x","op"});
	using _method_1706 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uqsd >;
	addExtern<DAS_CALL_METHOD(_method_1706)>(*this,lib,"vcmpeq_uqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uqsd >::invoke")
		->args({"self","k","x","op"});
	using _method_1707 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uqss >;
	addExtern<DAS_CALL_METHOD(_method_1707)>(*this,lib,"vcmpeq_uqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uqss >::invoke")
		->args({"self","k","x","op"});
	using _method_1708 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_uspd >;
	addExtern<DAS_CALL_METHOD(_method_1708)>(*this,lib,"vcmpeq_uspd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_uspd >::invoke")
		->args({"self","k","x","op"});
	using _method_1709 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_usps >;
	addExtern<DAS_CALL_METHOD(_method_1709)>(*this,lib,"vcmpeq_usps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_usps >::invoke")
		->args({"self","k","x","op"});
	using _method_1710 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_ussd >;
	addExtern<DAS_CALL_METHOD(_method_1710)>(*this,lib,"vcmpeq_ussd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_ussd >::invoke")
		->args({"self","k","x","op"});
	using _method_1711 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeq_usss >;
	addExtern<DAS_CALL_METHOD(_method_1711)>(*this,lib,"vcmpeq_usss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeq_usss >::invoke")
		->args({"self","k","x","op"});
	using _method_1712 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeqpd >;
	addExtern<DAS_CALL_METHOD(_method_1712)>(*this,lib,"vcmpeqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeqpd >::invoke")
		->args({"self","k","x","op"});
	using _method_1713 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeqps >;
	addExtern<DAS_CALL_METHOD(_method_1713)>(*this,lib,"vcmpeqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeqps >::invoke")
		->args({"self","k","x","op"});
	using _method_1714 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeqsd >;
	addExtern<DAS_CALL_METHOD(_method_1714)>(*this,lib,"vcmpeqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeqsd >::invoke")
		->args({"self","k","x","op"});
	using _method_1715 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpeqss >;
	addExtern<DAS_CALL_METHOD(_method_1715)>(*this,lib,"vcmpeqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpeqss >::invoke")
		->args({"self","k","x","op"});
	using _method_1716 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalse_ospd >;
	addExtern<DAS_CALL_METHOD(_method_1716)>(*this,lib,"vcmpfalse_ospd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalse_ospd >::invoke")
		->args({"self","k","x","op"});
	using _method_1717 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalse_osps >;
	addExtern<DAS_CALL_METHOD(_method_1717)>(*this,lib,"vcmpfalse_osps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalse_osps >::invoke")
		->args({"self","k","x","op"});
	using _method_1718 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalse_ossd >;
	addExtern<DAS_CALL_METHOD(_method_1718)>(*this,lib,"vcmpfalse_ossd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalse_ossd >::invoke")
		->args({"self","k","x","op"});
	using _method_1719 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalse_osss >;
	addExtern<DAS_CALL_METHOD(_method_1719)>(*this,lib,"vcmpfalse_osss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalse_osss >::invoke")
		->args({"self","k","x","op"});
	using _method_1720 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalsepd >;
	addExtern<DAS_CALL_METHOD(_method_1720)>(*this,lib,"vcmpfalsepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalsepd >::invoke")
		->args({"self","k","x","op"});
	using _method_1721 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalseps >;
	addExtern<DAS_CALL_METHOD(_method_1721)>(*this,lib,"vcmpfalseps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalseps >::invoke")
		->args({"self","k","x","op"});
	using _method_1722 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalsesd >;
	addExtern<DAS_CALL_METHOD(_method_1722)>(*this,lib,"vcmpfalsesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalsesd >::invoke")
		->args({"self","k","x","op"});
	using _method_1723 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpfalsess >;
	addExtern<DAS_CALL_METHOD(_method_1723)>(*this,lib,"vcmpfalsess",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpfalsess >::invoke")
		->args({"self","k","x","op"});
	using _method_1724 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpge_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1724)>(*this,lib,"vcmpge_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpge_oqpd >::invoke")
		->args({"self","k","x","op"});
	using _method_1725 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpge_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1725)>(*this,lib,"vcmpge_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpge_oqps >::invoke")
		->args({"self","k","x","op"});
	using _method_1726 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpge_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1726)>(*this,lib,"vcmpge_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpge_oqsd >::invoke")
		->args({"self","k","x","op"});
	using _method_1727 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpge_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1727)>(*this,lib,"vcmpge_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpge_oqss >::invoke")
		->args({"self","k","x","op"});
	using _method_1728 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgepd >;
	addExtern<DAS_CALL_METHOD(_method_1728)>(*this,lib,"vcmpgepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgepd >::invoke")
		->args({"self","k","x","op"});
	using _method_1729 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgeps >;
	addExtern<DAS_CALL_METHOD(_method_1729)>(*this,lib,"vcmpgeps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgeps >::invoke")
		->args({"self","k","x","op"});
	using _method_1730 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgesd >;
	addExtern<DAS_CALL_METHOD(_method_1730)>(*this,lib,"vcmpgesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgesd >::invoke")
		->args({"self","k","x","op"});
	using _method_1731 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgess >;
	addExtern<DAS_CALL_METHOD(_method_1731)>(*this,lib,"vcmpgess",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgess >::invoke")
		->args({"self","k","x","op"});
	using _method_1732 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgt_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1732)>(*this,lib,"vcmpgt_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgt_oqpd >::invoke")
		->args({"self","k","x","op"});
	using _method_1733 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgt_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1733)>(*this,lib,"vcmpgt_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgt_oqps >::invoke")
		->args({"self","k","x","op"});
	using _method_1734 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgt_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1734)>(*this,lib,"vcmpgt_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgt_oqsd >::invoke")
		->args({"self","k","x","op"});
	using _method_1735 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgt_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1735)>(*this,lib,"vcmpgt_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgt_oqss >::invoke")
		->args({"self","k","x","op"});
	using _method_1736 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgtpd >;
	addExtern<DAS_CALL_METHOD(_method_1736)>(*this,lib,"vcmpgtpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgtpd >::invoke")
		->args({"self","k","x","op"});
	using _method_1737 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgtps >;
	addExtern<DAS_CALL_METHOD(_method_1737)>(*this,lib,"vcmpgtps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgtps >::invoke")
		->args({"self","k","x","op"});
	using _method_1738 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgtsd >;
	addExtern<DAS_CALL_METHOD(_method_1738)>(*this,lib,"vcmpgtsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgtsd >::invoke")
		->args({"self","k","x","op"});
	using _method_1739 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpgtss >;
	addExtern<DAS_CALL_METHOD(_method_1739)>(*this,lib,"vcmpgtss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpgtss >::invoke")
		->args({"self","k","x","op"});
	using _method_1740 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmple_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1740)>(*this,lib,"vcmple_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmple_oqpd >::invoke")
		->args({"self","k","x","op"});
	using _method_1741 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmple_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1741)>(*this,lib,"vcmple_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmple_oqps >::invoke")
		->args({"self","k","x","op"});
	using _method_1742 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmple_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1742)>(*this,lib,"vcmple_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmple_oqsd >::invoke")
		->args({"self","k","x","op"});
	using _method_1743 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmple_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1743)>(*this,lib,"vcmple_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmple_oqss >::invoke")
		->args({"self","k","x","op"});
	using _method_1744 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplepd >;
	addExtern<DAS_CALL_METHOD(_method_1744)>(*this,lib,"vcmplepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplepd >::invoke")
		->args({"self","k","x","op"});
	using _method_1745 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpleps >;
	addExtern<DAS_CALL_METHOD(_method_1745)>(*this,lib,"vcmpleps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpleps >::invoke")
		->args({"self","k","x","op"});
	using _method_1746 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplesd >;
	addExtern<DAS_CALL_METHOD(_method_1746)>(*this,lib,"vcmplesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplesd >::invoke")
		->args({"self","k","x","op"});
	using _method_1747 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpless >;
	addExtern<DAS_CALL_METHOD(_method_1747)>(*this,lib,"vcmpless",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpless >::invoke")
		->args({"self","k","x","op"});
	using _method_1748 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplt_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1748)>(*this,lib,"vcmplt_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplt_oqpd >::invoke")
		->args({"self","k","x","op"});
	using _method_1749 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplt_oqps >;
	addExtern<DAS_CALL_METHOD(_method_1749)>(*this,lib,"vcmplt_oqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplt_oqps >::invoke")
		->args({"self","k","x","op"});
	using _method_1750 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplt_oqsd >;
	addExtern<DAS_CALL_METHOD(_method_1750)>(*this,lib,"vcmplt_oqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplt_oqsd >::invoke")
		->args({"self","k","x","op"});
	using _method_1751 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmplt_oqss >;
	addExtern<DAS_CALL_METHOD(_method_1751)>(*this,lib,"vcmplt_oqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmplt_oqss >::invoke")
		->args({"self","k","x","op"});
	using _method_1752 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpltpd >;
	addExtern<DAS_CALL_METHOD(_method_1752)>(*this,lib,"vcmpltpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpltpd >::invoke")
		->args({"self","k","x","op"});
	using _method_1753 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpltps >;
	addExtern<DAS_CALL_METHOD(_method_1753)>(*this,lib,"vcmpltps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpltps >::invoke")
		->args({"self","k","x","op"});
	using _method_1754 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpltsd >;
	addExtern<DAS_CALL_METHOD(_method_1754)>(*this,lib,"vcmpltsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpltsd >::invoke")
		->args({"self","k","x","op"});
	using _method_1755 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpltss >;
	addExtern<DAS_CALL_METHOD(_method_1755)>(*this,lib,"vcmpltss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpltss >::invoke")
		->args({"self","k","x","op"});
	using _method_1756 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcmpneq_oqpd >;
	addExtern<DAS_CALL_METHOD(_method_1756)>(*this,lib,"vcmpneq_oqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcmpneq_oqpd >::invoke")
		->args({"self","k","x","op"});
}
}

