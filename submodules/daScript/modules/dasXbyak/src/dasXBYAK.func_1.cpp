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
void Module_dasXBYAK::initFunctions_1() {
	addExtern< const char * (*)(int) , Xbyak::ConvertErrorToString >(*this,lib,"ConvertErrorToString",SideEffects::worstDefault,"Xbyak::ConvertErrorToString")
		->args({"err"});
	addExtern< int & (*)() , Xbyak::local::GetErrorRef , SimNode_ExtFuncCallRef>(*this,lib,"GetErrorRef",SideEffects::worstDefault,"Xbyak::local::GetErrorRef");
	addExtern< void (*)(int) , Xbyak::local::SetError >(*this,lib,"SetError",SideEffects::worstDefault,"Xbyak::local::SetError")
		->args({"err"});
	addExtern< void (*)() , Xbyak::ClearError >(*this,lib,"ClearError",SideEffects::worstDefault,"Xbyak::ClearError");
	addExtern< int (*)() , Xbyak::GetError >(*this,lib,"GetError",SideEffects::worstDefault,"Xbyak::GetError");
	addExtern< void * (*)(size_t,size_t) , Xbyak::AlignedMalloc >(*this,lib,"AlignedMalloc",SideEffects::worstDefault,"Xbyak::AlignedMalloc")
		->args({"size","alignment"});
	addExtern< void (*)(void *) , Xbyak::AlignedFree >(*this,lib,"AlignedFree",SideEffects::worstDefault,"Xbyak::AlignedFree")
		->args({"p"});
	addExtern< bool (*)(unsigned int) , Xbyak::inner::IsInDisp8 >(*this,lib,"IsInDisp8",SideEffects::worstDefault,"Xbyak::inner::IsInDisp8")
		->args({"x"});
	addExtern< bool (*)(uint64_t) , Xbyak::inner::IsInInt32 >(*this,lib,"IsInInt32",SideEffects::worstDefault,"Xbyak::inner::IsInInt32")
		->args({"x"});
	addExtern< unsigned int (*)(uint64_t) , Xbyak::inner::VerifyInInt32 >(*this,lib,"VerifyInInt32",SideEffects::worstDefault,"Xbyak::inner::VerifyInInt32")
		->args({"x"});
	addExtern< unsigned char * (*)(Xbyak::Allocator &,size_t) , _dasXBYAK_virtual_0_alloc >(*this,lib,"alloc",SideEffects::worstDefault,"_dasXBYAK_virtual_0_alloc")
		->args({"self","size"});
	addExtern< void (*)(Xbyak::Allocator &,unsigned char *) , _dasXBYAK_virtual_1_free >(*this,lib,"free",SideEffects::worstDefault,"_dasXBYAK_virtual_1_free")
		->args({"self","p"});
	addExtern< bool (*)(const Xbyak::Allocator &) , _dasXBYAK_virtual_2_useProtect >(*this,lib,"useProtect",SideEffects::worstDefault,"_dasXBYAK_virtual_2_useProtect")
		->args({"self"});
	addCtorAndUsing<Xbyak::Operand>(*this,lib,"Operand","Xbyak::Operand");
	addCtorAndUsing<Xbyak::Operand,int,Xbyak::Operand::Kind,int,bool>(*this,lib,"Operand","Xbyak::Operand")
		->args({"idx","kind","bit","ext8bit"})
		->arg_init(3,make_smart<ExprConstBool>(false));
	using _method_4 = das::das_call_member< Xbyak::Operand::Kind (Xbyak::Operand::*)() const,&Xbyak::Operand::getKind >;
	addExtern<DAS_CALL_METHOD(_method_4)>(*this,lib,"getKind",SideEffects::worstDefault,"das_call_member< Xbyak::Operand::Kind (Xbyak::Operand::*)() const , &Xbyak::Operand::getKind >::invoke")
		->args({"self"});
	using _method_5 = das::das_call_member< int (Xbyak::Operand::*)() const,&Xbyak::Operand::getIdx >;
	addExtern<DAS_CALL_METHOD(_method_5)>(*this,lib,"getIdx",SideEffects::worstDefault,"das_call_member< int (Xbyak::Operand::*)() const , &Xbyak::Operand::getIdx >::invoke")
		->args({"self"});
	using _method_6 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isNone >;
	addExtern<DAS_CALL_METHOD(_method_6)>(*this,lib,"isNone",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isNone >::invoke")
		->args({"self"});
	using _method_7 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isMMX >;
	addExtern<DAS_CALL_METHOD(_method_7)>(*this,lib,"isMMX",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isMMX >::invoke")
		->args({"self"});
	using _method_8 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isXMM >;
	addExtern<DAS_CALL_METHOD(_method_8)>(*this,lib,"isXMM",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isXMM >::invoke")
		->args({"self"});
	using _method_9 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isYMM >;
	addExtern<DAS_CALL_METHOD(_method_9)>(*this,lib,"isYMM",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isYMM >::invoke")
		->args({"self"});
	using _method_10 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isZMM >;
	addExtern<DAS_CALL_METHOD(_method_10)>(*this,lib,"isZMM",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isZMM >::invoke")
		->args({"self"});
	using _method_11 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isTMM >;
	addExtern<DAS_CALL_METHOD(_method_11)>(*this,lib,"isTMM",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isTMM >::invoke")
		->args({"self"});
	using _method_12 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isXMEM >;
	addExtern<DAS_CALL_METHOD(_method_12)>(*this,lib,"isXMEM",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isXMEM >::invoke")
		->args({"self"});
	using _method_13 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isYMEM >;
	addExtern<DAS_CALL_METHOD(_method_13)>(*this,lib,"isYMEM",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isYMEM >::invoke")
		->args({"self"});
	using _method_14 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isZMEM >;
	addExtern<DAS_CALL_METHOD(_method_14)>(*this,lib,"isZMEM",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isZMEM >::invoke")
		->args({"self"});
	using _method_15 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isOPMASK >;
	addExtern<DAS_CALL_METHOD(_method_15)>(*this,lib,"isOPMASK",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isOPMASK >::invoke")
		->args({"self"});
	using _method_16 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isBNDREG >;
	addExtern<DAS_CALL_METHOD(_method_16)>(*this,lib,"isBNDREG",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isBNDREG >::invoke")
		->args({"self"});
	using _method_17 = das::das_call_member< bool (Xbyak::Operand::*)(int) const,&Xbyak::Operand::isREG >;
	addExtern<DAS_CALL_METHOD(_method_17)>(*this,lib,"isREG",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)(int) const , &Xbyak::Operand::isREG >::invoke")
		->args({"self","bit"})
		->arg_init(1,make_smart<ExprConstInt>(0));
	using _method_18 = das::das_call_member< bool (Xbyak::Operand::*)(int) const,&Xbyak::Operand::isMEM >;
	addExtern<DAS_CALL_METHOD(_method_18)>(*this,lib,"isMEM",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)(int) const , &Xbyak::Operand::isMEM >::invoke")
		->args({"self","bit"})
		->arg_init(1,make_smart<ExprConstInt>(0));
	using _method_19 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isFPU >;
	addExtern<DAS_CALL_METHOD(_method_19)>(*this,lib,"isFPU",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isFPU >::invoke")
		->args({"self"});
	using _method_20 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isExt8bit >;
	addExtern<DAS_CALL_METHOD(_method_20)>(*this,lib,"isExt8bit",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isExt8bit >::invoke")
		->args({"self"});
	using _method_21 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isExtIdx >;
	addExtern<DAS_CALL_METHOD(_method_21)>(*this,lib,"isExtIdx",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isExtIdx >::invoke")
		->args({"self"});
	using _method_22 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isExtIdx2 >;
	addExtern<DAS_CALL_METHOD(_method_22)>(*this,lib,"isExtIdx2",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isExtIdx2 >::invoke")
		->args({"self"});
	using _method_23 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::hasEvex >;
	addExtern<DAS_CALL_METHOD(_method_23)>(*this,lib,"hasEvex",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::hasEvex >::invoke")
		->args({"self"});
	using _method_24 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::hasRex >;
	addExtern<DAS_CALL_METHOD(_method_24)>(*this,lib,"hasRex",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::hasRex >::invoke")
		->args({"self"});
	using _method_25 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::hasZero >;
	addExtern<DAS_CALL_METHOD(_method_25)>(*this,lib,"hasZero",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::hasZero >::invoke")
		->args({"self"});
	using _method_26 = das::das_call_member< int (Xbyak::Operand::*)() const,&Xbyak::Operand::getOpmaskIdx >;
	addExtern<DAS_CALL_METHOD(_method_26)>(*this,lib,"getOpmaskIdx",SideEffects::worstDefault,"das_call_member< int (Xbyak::Operand::*)() const , &Xbyak::Operand::getOpmaskIdx >::invoke")
		->args({"self"});
	using _method_27 = das::das_call_member< int (Xbyak::Operand::*)() const,&Xbyak::Operand::getRounding >;
	addExtern<DAS_CALL_METHOD(_method_27)>(*this,lib,"getRounding",SideEffects::worstDefault,"das_call_member< int (Xbyak::Operand::*)() const , &Xbyak::Operand::getRounding >::invoke")
		->args({"self"});
	using _method_28 = das::das_call_member< void (Xbyak::Operand::*)(Xbyak::Operand::Kind),&Xbyak::Operand::setKind >;
	addExtern<DAS_CALL_METHOD(_method_28)>(*this,lib,"setKind",SideEffects::worstDefault,"das_call_member< void (Xbyak::Operand::*)(Xbyak::Operand::Kind) , &Xbyak::Operand::setKind >::invoke")
		->args({"self","kind"});
	using _method_29 = das::das_call_member< void (Xbyak::Operand::*)(int),&Xbyak::Operand::setBit >;
	addExtern<DAS_CALL_METHOD(_method_29)>(*this,lib,"setBit",SideEffects::worstDefault,"das_call_member< void (Xbyak::Operand::*)(int) , &Xbyak::Operand::setBit >::invoke")
		->args({"self","bit"});
	using _method_30 = das::das_call_member< void (Xbyak::Operand::*)(int,bool),&Xbyak::Operand::setOpmaskIdx >;
	addExtern<DAS_CALL_METHOD(_method_30)>(*this,lib,"setOpmaskIdx",SideEffects::worstDefault,"das_call_member< void (Xbyak::Operand::*)(int,bool) , &Xbyak::Operand::setOpmaskIdx >::invoke")
		->args({"self","idx",""})
		->arg_init(2,make_smart<ExprConstBool>(true));
	using _method_31 = das::das_call_member< void (Xbyak::Operand::*)(int),&Xbyak::Operand::setRounding >;
	addExtern<DAS_CALL_METHOD(_method_31)>(*this,lib,"setRounding",SideEffects::worstDefault,"das_call_member< void (Xbyak::Operand::*)(int) , &Xbyak::Operand::setRounding >::invoke")
		->args({"self","idx"});
	using _method_32 = das::das_call_member< void (Xbyak::Operand::*)(),&Xbyak::Operand::setZero >;
	addExtern<DAS_CALL_METHOD(_method_32)>(*this,lib,"setZero",SideEffects::worstDefault,"das_call_member< void (Xbyak::Operand::*)() , &Xbyak::Operand::setZero >::invoke")
		->args({"self"});
	using _method_33 = das::das_call_member< bool (Xbyak::Operand::*)() const,&Xbyak::Operand::isHigh8bit >;
	addExtern<DAS_CALL_METHOD(_method_33)>(*this,lib,"isHigh8bit",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)() const , &Xbyak::Operand::isHigh8bit >::invoke")
		->args({"self"});
	using _method_34 = das::das_call_member< bool (Xbyak::Operand::*)(int,unsigned int) const,&Xbyak::Operand::is >;
	addExtern<DAS_CALL_METHOD(_method_34)>(*this,lib,"is",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)(int,unsigned int) const , &Xbyak::Operand::is >::invoke")
		->args({"self","kind","bit"})
		->arg_init(2,make_smart<ExprConstUInt>(0x0));
	using _method_35 = das::das_call_member< bool (Xbyak::Operand::*)(unsigned int) const,&Xbyak::Operand::isBit >;
	addExtern<DAS_CALL_METHOD(_method_35)>(*this,lib,"isBit",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)(unsigned int) const , &Xbyak::Operand::isBit >::invoke")
		->args({"self","bit"});
	using _method_36 = das::das_call_member< unsigned int (Xbyak::Operand::*)() const,&Xbyak::Operand::getBit >;
	addExtern<DAS_CALL_METHOD(_method_36)>(*this,lib,"getBit",SideEffects::worstDefault,"das_call_member< unsigned int (Xbyak::Operand::*)() const , &Xbyak::Operand::getBit >::invoke")
		->args({"self"});
	using _method_37 = das::das_call_member< const char * (Xbyak::Operand::*)() const,&Xbyak::Operand::toString >;
	addExtern<DAS_CALL_METHOD(_method_37)>(*this,lib,"toString",SideEffects::worstDefault,"das_call_member< const char * (Xbyak::Operand::*)() const , &Xbyak::Operand::toString >::invoke")
		->args({"self"});
	using _method_38 = das::das_call_member< bool (Xbyak::Operand::*)(const Xbyak::Operand &) const,&Xbyak::Operand::isEqualIfNotInherited >;
	addExtern<DAS_CALL_METHOD(_method_38)>(*this,lib,"isEqualIfNotInherited",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)(const Xbyak::Operand &) const , &Xbyak::Operand::isEqualIfNotInherited >::invoke")
		->args({"self","rhs"});
	using _method_39 = das::das_call_member< bool (Xbyak::Operand::*)(const Xbyak::Operand &) const,&Xbyak::Operand::operator== >;
	addExtern<DAS_CALL_METHOD(_method_39)>(*this,lib,"==",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)(const Xbyak::Operand &) const , &Xbyak::Operand::operator== >::invoke")
		->args({"self","rhs"});
	using _method_40 = das::das_call_member< bool (Xbyak::Operand::*)(const Xbyak::Operand &) const,&Xbyak::Operand::operator!= >;
	addExtern<DAS_CALL_METHOD(_method_40)>(*this,lib,"!=",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Operand::*)(const Xbyak::Operand &) const , &Xbyak::Operand::operator!= >::invoke")
		->args({"self","rhs"});
	using _method_41 = das::das_call_member< const Xbyak::Address & (Xbyak::Operand::*)() const,&Xbyak::Operand::getAddress >;
	addExtern<DAS_CALL_METHOD(_method_41), SimNode_ExtFuncCallRef>(*this,lib,"getAddress",SideEffects::worstDefault,"das_call_member< const Xbyak::Address & (Xbyak::Operand::*)() const , &Xbyak::Operand::getAddress >::invoke")
		->args({"self"});
	using _method_42 = das::das_call_member< const Xbyak::Reg & (Xbyak::Operand::*)() const,&Xbyak::Operand::getReg >;
	addExtern<DAS_CALL_METHOD(_method_42), SimNode_ExtFuncCallRef>(*this,lib,"getReg",SideEffects::worstDefault,"das_call_member< const Xbyak::Reg & (Xbyak::Operand::*)() const , &Xbyak::Operand::getReg >::invoke")
		->args({"self"});
	addCtorAndUsing<Xbyak::Reg>(*this,lib,"Reg","Xbyak::Reg");
	addCtorAndUsing<Xbyak::Reg,int,Xbyak::Operand::Kind,int,bool>(*this,lib,"Reg","Xbyak::Reg")
		->args({"idx","kind","bit","ext8bit"})
		->arg_init(2,make_smart<ExprConstInt>(0))
		->arg_init(3,make_smart<ExprConstBool>(false));
	using _method_43 = das::das_call_member< Xbyak::Reg (Xbyak::Reg::*)(int) const,&Xbyak::Reg::changeBit >;
	addExtern<DAS_CALL_METHOD(_method_43),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"changeBit",SideEffects::worstDefault,"das_call_member< Xbyak::Reg (Xbyak::Reg::*)(int) const , &Xbyak::Reg::changeBit >::invoke")
		->args({"self","bit"});
	using _method_44 = das::das_call_member< unsigned char (Xbyak::Reg::*)() const,&Xbyak::Reg::getRexW >;
	addExtern<DAS_CALL_METHOD(_method_44)>(*this,lib,"getRexW",SideEffects::worstDefault,"das_call_member< unsigned char (Xbyak::Reg::*)() const , &Xbyak::Reg::getRexW >::invoke")
		->args({"self"});
	using _method_45 = das::das_call_member< unsigned char (Xbyak::Reg::*)() const,&Xbyak::Reg::getRexR >;
	addExtern<DAS_CALL_METHOD(_method_45)>(*this,lib,"getRexR",SideEffects::worstDefault,"das_call_member< unsigned char (Xbyak::Reg::*)() const , &Xbyak::Reg::getRexR >::invoke")
		->args({"self"});
	using _method_46 = das::das_call_member< unsigned char (Xbyak::Reg::*)() const,&Xbyak::Reg::getRexX >;
	addExtern<DAS_CALL_METHOD(_method_46)>(*this,lib,"getRexX",SideEffects::worstDefault,"das_call_member< unsigned char (Xbyak::Reg::*)() const , &Xbyak::Reg::getRexX >::invoke")
		->args({"self"});
	using _method_47 = das::das_call_member< unsigned char (Xbyak::Reg::*)() const,&Xbyak::Reg::getRexB >;
	addExtern<DAS_CALL_METHOD(_method_47)>(*this,lib,"getRexB",SideEffects::worstDefault,"das_call_member< unsigned char (Xbyak::Reg::*)() const , &Xbyak::Reg::getRexB >::invoke")
		->args({"self"});
	using _method_48 = das::das_call_member< unsigned char (Xbyak::Reg::*)(const Xbyak::Reg &) const,&Xbyak::Reg::getRex >;
	addExtern<DAS_CALL_METHOD(_method_48)>(*this,lib,"getRex",SideEffects::worstDefault,"das_call_member< unsigned char (Xbyak::Reg::*)(const Xbyak::Reg &) const , &Xbyak::Reg::getRex >::invoke")
		->args({"self","base"});
	using _method_49 = das::das_call_member< Xbyak::Reg8 (Xbyak::Reg::*)() const,&Xbyak::Reg::cvt8 >;
	addExtern<DAS_CALL_METHOD(_method_49),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"cvt8",SideEffects::worstDefault,"das_call_member< Xbyak::Reg8 (Xbyak::Reg::*)() const , &Xbyak::Reg::cvt8 >::invoke")
		->args({"self"});
	using _method_50 = das::das_call_member< Xbyak::Reg16 (Xbyak::Reg::*)() const,&Xbyak::Reg::cvt16 >;
	addExtern<DAS_CALL_METHOD(_method_50),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"cvt16",SideEffects::worstDefault,"das_call_member< Xbyak::Reg16 (Xbyak::Reg::*)() const , &Xbyak::Reg::cvt16 >::invoke")
		->args({"self"});
	using _method_51 = das::das_call_member< Xbyak::Reg32 (Xbyak::Reg::*)() const,&Xbyak::Reg::cvt32 >;
	addExtern<DAS_CALL_METHOD(_method_51),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"cvt32",SideEffects::worstDefault,"das_call_member< Xbyak::Reg32 (Xbyak::Reg::*)() const , &Xbyak::Reg::cvt32 >::invoke")
		->args({"self"});
	using _method_52 = das::das_call_member< Xbyak::Reg64 (Xbyak::Reg::*)() const,&Xbyak::Reg::cvt64 >;
	addExtern<DAS_CALL_METHOD(_method_52),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"cvt64",SideEffects::worstDefault,"das_call_member< Xbyak::Reg64 (Xbyak::Reg::*)() const , &Xbyak::Reg::cvt64 >::invoke")
		->args({"self"});
	addCtorAndUsing<Xbyak::Reg8,int,bool>(*this,lib,"Reg8","Xbyak::Reg8")
		->args({"idx","ext8bit"})
		->arg_init(0,make_smart<ExprConstInt>(0))
		->arg_init(1,make_smart<ExprConstBool>(false));
	addCtorAndUsing<Xbyak::Reg16,int>(*this,lib,"Reg16","Xbyak::Reg16")
		->args({"idx"})
		->arg_init(0,make_smart<ExprConstInt>(0));
	addCtorAndUsing<Xbyak::Mmx,int,Xbyak::Operand::Kind,int>(*this,lib,"Mmx","Xbyak::Mmx")
		->args({"idx","kind","bit"})
		->arg_init(0,make_smart<ExprConstInt>(0))
		->arg_init(1,make_smart<ExprConstEnumeration>(4,makeType<Xbyak::Operand::Kind>(lib)))
		->arg_init(2,make_smart<ExprConstInt>(64));
	addCtorAndUsing<Xbyak::EvexModifierRounding,int>(*this,lib,"EvexModifierRounding","Xbyak::EvexModifierRounding")
		->args({"rounding"});
	addCtorAndUsing<Xbyak::EvexModifierZero>(*this,lib,"EvexModifierZero","Xbyak::EvexModifierZero");
	addCtorAndUsing<Xbyak::Xmm,int,Xbyak::Operand::Kind,int>(*this,lib,"Xmm","Xbyak::Xmm")
		->args({"idx","kind","bit"})
		->arg_init(0,make_smart<ExprConstInt>(0))
		->arg_init(1,make_smart<ExprConstEnumeration>(16,makeType<Xbyak::Operand::Kind>(lib)))
		->arg_init(2,make_smart<ExprConstInt>(128));
	addCtorAndUsing<Xbyak::Xmm,Xbyak::Operand::Kind,int>(*this,lib,"Xmm","Xbyak::Xmm")
		->args({"kind","idx"});
	using _method_53 = das::das_call_member< Xbyak::Xmm (Xbyak::Xmm::*)(const Xbyak::EvexModifierRounding &) const,&Xbyak::Xmm::operator| >;
	addExtern<DAS_CALL_METHOD(_method_53),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"|",SideEffects::worstDefault,"das_call_member< Xbyak::Xmm (Xbyak::Xmm::*)(const Xbyak::EvexModifierRounding &) const , &Xbyak::Xmm::operator| >::invoke")
		->args({"self","emr"});
	using _method_54 = das::das_call_member< Xbyak::Xmm (Xbyak::Xmm::*)(int) const,&Xbyak::Xmm::copyAndSetIdx >;
	addExtern<DAS_CALL_METHOD(_method_54),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"copyAndSetIdx",SideEffects::worstDefault,"das_call_member< Xbyak::Xmm (Xbyak::Xmm::*)(int) const , &Xbyak::Xmm::copyAndSetIdx >::invoke")
		->args({"self","idx"});
	using _method_55 = das::das_call_member< Xbyak::Xmm (Xbyak::Xmm::*)(Xbyak::Operand::Kind) const,&Xbyak::Xmm::copyAndSetKind >;
	addExtern<DAS_CALL_METHOD(_method_55),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"copyAndSetKind",SideEffects::worstDefault,"das_call_member< Xbyak::Xmm (Xbyak::Xmm::*)(Xbyak::Operand::Kind) const , &Xbyak::Xmm::copyAndSetKind >::invoke")
		->args({"self","kind"});
	addCtorAndUsing<Xbyak::Ymm,int,Xbyak::Operand::Kind,int>(*this,lib,"Ymm","Xbyak::Ymm")
		->args({"idx","kind","bit"})
		->arg_init(0,make_smart<ExprConstInt>(0))
		->arg_init(1,make_smart<ExprConstEnumeration>(32,makeType<Xbyak::Operand::Kind>(lib)))
		->arg_init(2,make_smart<ExprConstInt>(256));
	using _method_56 = das::das_call_member< Xbyak::Ymm (Xbyak::Ymm::*)(const Xbyak::EvexModifierRounding &) const,&Xbyak::Ymm::operator| >;
	addExtern<DAS_CALL_METHOD(_method_56),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"|",SideEffects::worstDefault,"das_call_member< Xbyak::Ymm (Xbyak::Ymm::*)(const Xbyak::EvexModifierRounding &) const , &Xbyak::Ymm::operator| >::invoke")
		->args({"self","emr"});
	addCtorAndUsing<Xbyak::Zmm,int>(*this,lib,"Zmm","Xbyak::Zmm")
		->args({"idx"})
		->arg_init(0,make_smart<ExprConstInt>(0));
	using _method_57 = das::das_call_member< Xbyak::Zmm (Xbyak::Zmm::*)(const Xbyak::EvexModifierRounding &) const,&Xbyak::Zmm::operator| >;
	addExtern<DAS_CALL_METHOD(_method_57),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"|",SideEffects::worstDefault,"das_call_member< Xbyak::Zmm (Xbyak::Zmm::*)(const Xbyak::EvexModifierRounding &) const , &Xbyak::Zmm::operator| >::invoke")
		->args({"self","emr"});
	addCtorAndUsing<Xbyak::Tmm,int,Xbyak::Operand::Kind,int>(*this,lib,"Tmm","Xbyak::Tmm")
		->args({"idx","kind","bit"})
		->arg_init(0,make_smart<ExprConstInt>(0))
		->arg_init(1,make_smart<ExprConstEnumeration>(512,makeType<Xbyak::Operand::Kind>(lib)))
		->arg_init(2,make_smart<ExprConstInt>(8192));
	addCtorAndUsing<Xbyak::Opmask,int>(*this,lib,"Opmask","Xbyak::Opmask")
		->args({"idx"})
		->arg_init(0,make_smart<ExprConstInt>(0));
	addCtorAndUsing<Xbyak::BoundsReg,int>(*this,lib,"BoundsReg","Xbyak::BoundsReg")
		->args({"idx"})
		->arg_init(0,make_smart<ExprConstInt>(0));
	addCtorAndUsing<Xbyak::Fpu,int>(*this,lib,"Fpu","Xbyak::Fpu")
		->args({"idx"})
		->arg_init(0,make_smart<ExprConstInt>(0));
	addCtorAndUsing<Xbyak::Reg32e,int,int>(*this,lib,"Reg32e","Xbyak::Reg32e")
		->args({"idx","bit"});
	addCtorAndUsing<Xbyak::Reg32,int>(*this,lib,"Reg32","Xbyak::Reg32")
		->args({"idx"})
		->arg_init(0,make_smart<ExprConstInt>(0));
	addCtorAndUsing<Xbyak::Reg64,int>(*this,lib,"Reg64","Xbyak::Reg64")
		->args({"idx"})
		->arg_init(0,make_smart<ExprConstInt>(0));
	addCtorAndUsing<Xbyak::RegRip,long long,const Xbyak::Label *,bool>(*this,lib,"RegRip","Xbyak::RegRip")
		->args({"disp","label","isAddr"})
		->arg_init(0,make_smart<ExprConstInt64>(0))
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_init(2,make_smart<ExprConstBool>(false));
	addCtorAndUsing<Xbyak::Segment,int>(*this,lib,"Segment","Xbyak::Segment")
		->args({"idx"});
	using _method_58 = das::das_call_member< int (Xbyak::Segment::*)() const,&Xbyak::Segment::getIdx >;
	addExtern<DAS_CALL_METHOD(_method_58)>(*this,lib,"getIdx",SideEffects::worstDefault,"das_call_member< int (Xbyak::Segment::*)() const , &Xbyak::Segment::getIdx >::invoke")
		->args({"self"});
	using _method_59 = das::das_call_member< const char * (Xbyak::Segment::*)() const,&Xbyak::Segment::toString >;
	addExtern<DAS_CALL_METHOD(_method_59)>(*this,lib,"toString",SideEffects::worstDefault,"das_call_member< const char * (Xbyak::Segment::*)() const , &Xbyak::Segment::toString >::invoke")
		->args({"self"});
	addCtorAndUsing<Xbyak::RegExp,unsigned long long>(*this,lib,"RegExp","Xbyak::RegExp")
		->args({"disp"})
		->arg_init(0,make_smart<ExprConstUInt64>(0x0));
	addCtorAndUsing<Xbyak::RegExp,const Xbyak::Reg &,int>(*this,lib,"RegExp","Xbyak::RegExp")
		->args({"r","scale"})
		->arg_init(1,make_smart<ExprConstInt>(1));
	using _method_60 = das::das_call_member< bool (Xbyak::RegExp::*)(int) const,&Xbyak::RegExp::isVsib >;
	addExtern<DAS_CALL_METHOD(_method_60)>(*this,lib,"isVsib",SideEffects::worstDefault,"das_call_member< bool (Xbyak::RegExp::*)(int) const , &Xbyak::RegExp::isVsib >::invoke")
		->args({"self","bit"})
		->arg_init(1,make_smart<ExprConstInt>(896));
	using _method_61 = das::das_call_member< Xbyak::RegExp (Xbyak::RegExp::*)() const,&Xbyak::RegExp::optimize >;
	addExtern<DAS_CALL_METHOD(_method_61),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"optimize",SideEffects::worstDefault,"das_call_member< Xbyak::RegExp (Xbyak::RegExp::*)() const , &Xbyak::RegExp::optimize >::invoke")
		->args({"self"});
	using _method_62 = das::das_call_member< bool (Xbyak::RegExp::*)(const Xbyak::RegExp &) const,&Xbyak::RegExp::operator== >;
	addExtern<DAS_CALL_METHOD(_method_62)>(*this,lib,"==",SideEffects::worstDefault,"das_call_member< bool (Xbyak::RegExp::*)(const Xbyak::RegExp &) const , &Xbyak::RegExp::operator== >::invoke")
		->args({"self","rhs"});
	using _method_63 = das::das_call_member< const Xbyak::Reg & (Xbyak::RegExp::*)() const,&Xbyak::RegExp::getBase >;
	addExtern<DAS_CALL_METHOD(_method_63), SimNode_ExtFuncCallRef>(*this,lib,"getBase",SideEffects::worstDefault,"das_call_member< const Xbyak::Reg & (Xbyak::RegExp::*)() const , &Xbyak::RegExp::getBase >::invoke")
		->args({"self"});
	using _method_64 = das::das_call_member< const Xbyak::Reg & (Xbyak::RegExp::*)() const,&Xbyak::RegExp::getIndex >;
	addExtern<DAS_CALL_METHOD(_method_64), SimNode_ExtFuncCallRef>(*this,lib,"getIndex",SideEffects::worstDefault,"das_call_member< const Xbyak::Reg & (Xbyak::RegExp::*)() const , &Xbyak::RegExp::getIndex >::invoke")
		->args({"self"});
	using _method_65 = das::das_call_member< int (Xbyak::RegExp::*)() const,&Xbyak::RegExp::getScale >;
	addExtern<DAS_CALL_METHOD(_method_65)>(*this,lib,"getScale",SideEffects::worstDefault,"das_call_member< int (Xbyak::RegExp::*)() const , &Xbyak::RegExp::getScale >::invoke")
		->args({"self"});
	using _method_66 = das::das_call_member< size_t (Xbyak::RegExp::*)() const,&Xbyak::RegExp::getDisp >;
	addExtern<DAS_CALL_METHOD(_method_66)>(*this,lib,"getDisp",SideEffects::worstDefault,"das_call_member< size_t (Xbyak::RegExp::*)() const , &Xbyak::RegExp::getDisp >::invoke")
		->args({"self"});
}
}

