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
void Module_dasXBYAK::initFunctions_2() {
	using _method_67 = das::das_call_member< void (Xbyak::RegExp::*)() const,&Xbyak::RegExp::verify >;
	addExtern<DAS_CALL_METHOD(_method_67)>(*this,lib,"verify",SideEffects::worstDefault,"das_call_member< void (Xbyak::RegExp::*)() const , &Xbyak::RegExp::verify >::invoke")
		->args({"self"});
	using _method_68 = das::das_call_member< unsigned char (Xbyak::RegExp::*)() const,&Xbyak::RegExp::getRex >;
	addExtern<DAS_CALL_METHOD(_method_68)>(*this,lib,"getRex",SideEffects::worstDefault,"das_call_member< unsigned char (Xbyak::RegExp::*)() const , &Xbyak::RegExp::getRex >::invoke")
		->args({"self"});
	addCtorAndUsing<Xbyak::CodeArray,unsigned long long,void *,Xbyak::Allocator *>(*this,lib,"CodeArray","Xbyak::CodeArray")
		->args({"maxSize","userPtr","allocator"})
		->arg_init(1,make_smart<ExprConstPtr>())
		->arg_init(2,make_smart<ExprConstPtr>());
	using _method_69 = das::das_call_member< bool (Xbyak::CodeArray::*)(Xbyak::CodeArray::ProtectMode,bool),&Xbyak::CodeArray::setProtectMode >;
	addExtern<DAS_CALL_METHOD(_method_69)>(*this,lib,"setProtectMode",SideEffects::worstDefault,"das_call_member< bool (Xbyak::CodeArray::*)(Xbyak::CodeArray::ProtectMode,bool) , &Xbyak::CodeArray::setProtectMode >::invoke")
		->args({"self","mode","throwException"})
		->arg_init(2,make_smart<ExprConstBool>(true));
	using _method_70 = das::das_call_member< bool (Xbyak::CodeArray::*)(bool),&Xbyak::CodeArray::setProtectModeRE >;
	addExtern<DAS_CALL_METHOD(_method_70)>(*this,lib,"setProtectModeRE",SideEffects::worstDefault,"das_call_member< bool (Xbyak::CodeArray::*)(bool) , &Xbyak::CodeArray::setProtectModeRE >::invoke")
		->args({"self","throwException"})
		->arg_init(1,make_smart<ExprConstBool>(true));
	using _method_71 = das::das_call_member< bool (Xbyak::CodeArray::*)(bool),&Xbyak::CodeArray::setProtectModeRW >;
	addExtern<DAS_CALL_METHOD(_method_71)>(*this,lib,"setProtectModeRW",SideEffects::worstDefault,"das_call_member< bool (Xbyak::CodeArray::*)(bool) , &Xbyak::CodeArray::setProtectModeRW >::invoke")
		->args({"self","throwException"})
		->arg_init(1,make_smart<ExprConstBool>(true));
	using _method_72 = das::das_call_member< void (Xbyak::CodeArray::*)(),&Xbyak::CodeArray::resetSize >;
	addExtern<DAS_CALL_METHOD(_method_72)>(*this,lib,"resetSize",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)() , &Xbyak::CodeArray::resetSize >::invoke")
		->args({"self"});
	using _method_73 = das::das_call_member< void (Xbyak::CodeArray::*)(int),&Xbyak::CodeArray::db >;
	addExtern<DAS_CALL_METHOD(_method_73)>(*this,lib,"db",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(int) , &Xbyak::CodeArray::db >::invoke")
		->args({"self","code"});
	using _method_74 = das::das_call_member< void (Xbyak::CodeArray::*)(const unsigned char *,size_t),&Xbyak::CodeArray::db >;
	addExtern<DAS_CALL_METHOD(_method_74)>(*this,lib,"db",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(const unsigned char *,size_t) , &Xbyak::CodeArray::db >::invoke")
		->args({"self","code","codeSize"});
	using _method_75 = das::das_call_member< void (Xbyak::CodeArray::*)(uint64_t,size_t),&Xbyak::CodeArray::db >;
	addExtern<DAS_CALL_METHOD(_method_75)>(*this,lib,"db",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(uint64_t,size_t) , &Xbyak::CodeArray::db >::invoke")
		->args({"self","code","codeSize"});
	using _method_76 = das::das_call_member< void (Xbyak::CodeArray::*)(unsigned int),&Xbyak::CodeArray::dw >;
	addExtern<DAS_CALL_METHOD(_method_76)>(*this,lib,"dw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(unsigned int) , &Xbyak::CodeArray::dw >::invoke")
		->args({"self","code"});
	using _method_77 = das::das_call_member< void (Xbyak::CodeArray::*)(unsigned int),&Xbyak::CodeArray::dd >;
	addExtern<DAS_CALL_METHOD(_method_77)>(*this,lib,"dd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(unsigned int) , &Xbyak::CodeArray::dd >::invoke")
		->args({"self","code"});
	using _method_78 = das::das_call_member< void (Xbyak::CodeArray::*)(uint64_t),&Xbyak::CodeArray::dq >;
	addExtern<DAS_CALL_METHOD(_method_78)>(*this,lib,"dq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(uint64_t) , &Xbyak::CodeArray::dq >::invoke")
		->args({"self","code"});
	using _method_79 = das::das_call_member< const unsigned char * (Xbyak::CodeArray::*)() const,&Xbyak::CodeArray::getCode >;
	addExtern<DAS_CALL_METHOD(_method_79)>(*this,lib,"getCode",SideEffects::worstDefault,"das_call_member< const unsigned char * (Xbyak::CodeArray::*)() const , &Xbyak::CodeArray::getCode >::invoke")
		->args({"self"});
	using _method_80 = das::das_call_member< const unsigned char * (Xbyak::CodeArray::*)() const,&Xbyak::CodeArray::getCurr >;
	addExtern<DAS_CALL_METHOD(_method_80)>(*this,lib,"getCurr",SideEffects::worstDefault,"das_call_member< const unsigned char * (Xbyak::CodeArray::*)() const , &Xbyak::CodeArray::getCurr >::invoke")
		->args({"self"});
	using _method_81 = das::das_call_member< size_t (Xbyak::CodeArray::*)() const,&Xbyak::CodeArray::getSize >;
	addExtern<DAS_CALL_METHOD(_method_81)>(*this,lib,"getSize",SideEffects::worstDefault,"das_call_member< size_t (Xbyak::CodeArray::*)() const , &Xbyak::CodeArray::getSize >::invoke")
		->args({"self"});
	using _method_82 = das::das_call_member< void (Xbyak::CodeArray::*)(size_t),&Xbyak::CodeArray::setSize >;
	addExtern<DAS_CALL_METHOD(_method_82)>(*this,lib,"setSize",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(size_t) , &Xbyak::CodeArray::setSize >::invoke")
		->args({"self","size"});
	using _method_83 = das::das_call_member< void (Xbyak::CodeArray::*)() const,&Xbyak::CodeArray::dump >;
	addExtern<DAS_CALL_METHOD(_method_83)>(*this,lib,"dump",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)() const , &Xbyak::CodeArray::dump >::invoke")
		->args({"self"});
	using _method_84 = das::das_call_member< void (Xbyak::CodeArray::*)(size_t,uint64_t,size_t),&Xbyak::CodeArray::rewrite >;
	addExtern<DAS_CALL_METHOD(_method_84)>(*this,lib,"rewrite",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(size_t,uint64_t,size_t) , &Xbyak::CodeArray::rewrite >::invoke")
		->args({"self","offset","disp","size"});
	using _method_85 = das::das_call_member< void (Xbyak::CodeArray::*)(size_t,size_t,int,Xbyak::inner::LabelMode),&Xbyak::CodeArray::save >;
	addExtern<DAS_CALL_METHOD(_method_85)>(*this,lib,"save",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeArray::*)(size_t,size_t,int,Xbyak::inner::LabelMode) , &Xbyak::CodeArray::save >::invoke")
		->args({"self","offset","val","size","mode"});
	using _method_86 = das::das_call_member< bool (Xbyak::CodeArray::*)() const,&Xbyak::CodeArray::isAutoGrow >;
	addExtern<DAS_CALL_METHOD(_method_86)>(*this,lib,"isAutoGrow",SideEffects::worstDefault,"das_call_member< bool (Xbyak::CodeArray::*)() const , &Xbyak::CodeArray::isAutoGrow >::invoke")
		->args({"self"});
	using _method_87 = das::das_call_member< bool (Xbyak::CodeArray::*)() const,&Xbyak::CodeArray::isCalledCalcJmpAddress >;
	addExtern<DAS_CALL_METHOD(_method_87)>(*this,lib,"isCalledCalcJmpAddress",SideEffects::worstDefault,"das_call_member< bool (Xbyak::CodeArray::*)() const , &Xbyak::CodeArray::isCalledCalcJmpAddress >::invoke")
		->args({"self"});
	addExtern< bool (*)(const Xbyak::CodeArray &,const void *,size_t,int) , _dasXBYAK_static_3_protect >(*this,lib,"protect",SideEffects::worstDefault,"_dasXBYAK_static_3_protect")
		->args({"self","addr","size","protectMode"});
	addExtern< unsigned char * (*)(const Xbyak::CodeArray &,unsigned char *,size_t) , _dasXBYAK_static_4_getAlignedAddress >(*this,lib,"getAlignedAddress",SideEffects::worstDefault,"_dasXBYAK_static_4_getAlignedAddress")
		->args({"self","addr","alignedSize"})
		->arg_init(2,make_smart<ExprConstUInt64>(0x10));
	addCtorAndUsing<Xbyak::Address,unsigned int,bool,const Xbyak::RegExp &>(*this,lib,"Address","Xbyak::Address")
		->args({"sizeBit","broadcast","e"});
	addCtorAndUsing<Xbyak::Address,unsigned long long>(*this,lib,"Address","Xbyak::Address")
		->args({"disp"});
	addCtorAndUsing<Xbyak::Address,unsigned int,bool,const Xbyak::RegRip &>(*this,lib,"Address","Xbyak::Address")
		->args({"sizeBit","broadcast","addr"});
	using _method_90 = das::das_call_member< Xbyak::RegExp (Xbyak::Address::*)(bool) const,&Xbyak::Address::getRegExp >;
	addExtern<DAS_CALL_METHOD(_method_90),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"getRegExp",SideEffects::worstDefault,"das_call_member< Xbyak::RegExp (Xbyak::Address::*)(bool) const , &Xbyak::Address::getRegExp >::invoke")
		->args({"self","optimize"})
		->arg_init(1,make_smart<ExprConstBool>(true));
	using _method_91 = das::das_call_member< Xbyak::Address::Mode (Xbyak::Address::*)() const,&Xbyak::Address::getMode >;
	addExtern<DAS_CALL_METHOD(_method_91)>(*this,lib,"getMode",SideEffects::worstDefault,"das_call_member< Xbyak::Address::Mode (Xbyak::Address::*)() const , &Xbyak::Address::getMode >::invoke")
		->args({"self"});
	using _method_92 = das::das_call_member< bool (Xbyak::Address::*)() const,&Xbyak::Address::is32bit >;
	addExtern<DAS_CALL_METHOD(_method_92)>(*this,lib,"is32bit",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Address::*)() const , &Xbyak::Address::is32bit >::invoke")
		->args({"self"});
	using _method_93 = das::das_call_member< bool (Xbyak::Address::*)() const,&Xbyak::Address::isOnlyDisp >;
	addExtern<DAS_CALL_METHOD(_method_93)>(*this,lib,"isOnlyDisp",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Address::*)() const , &Xbyak::Address::isOnlyDisp >::invoke")
		->args({"self"});
	using _method_94 = das::das_call_member< size_t (Xbyak::Address::*)() const,&Xbyak::Address::getDisp >;
	addExtern<DAS_CALL_METHOD(_method_94)>(*this,lib,"getDisp",SideEffects::worstDefault,"das_call_member< size_t (Xbyak::Address::*)() const , &Xbyak::Address::getDisp >::invoke")
		->args({"self"});
	using _method_95 = das::das_call_member< unsigned char (Xbyak::Address::*)() const,&Xbyak::Address::getRex >;
	addExtern<DAS_CALL_METHOD(_method_95)>(*this,lib,"getRex",SideEffects::worstDefault,"das_call_member< unsigned char (Xbyak::Address::*)() const , &Xbyak::Address::getRex >::invoke")
		->args({"self"});
	using _method_96 = das::das_call_member< bool (Xbyak::Address::*)() const,&Xbyak::Address::is64bitDisp >;
	addExtern<DAS_CALL_METHOD(_method_96)>(*this,lib,"is64bitDisp",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Address::*)() const , &Xbyak::Address::is64bitDisp >::invoke")
		->args({"self"});
	using _method_97 = das::das_call_member< bool (Xbyak::Address::*)() const,&Xbyak::Address::isBroadcast >;
	addExtern<DAS_CALL_METHOD(_method_97)>(*this,lib,"isBroadcast",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Address::*)() const , &Xbyak::Address::isBroadcast >::invoke")
		->args({"self"});
	using _method_98 = das::das_call_member< const Xbyak::Label * (Xbyak::Address::*)() const,&Xbyak::Address::getLabel >;
	addExtern<DAS_CALL_METHOD(_method_98)>(*this,lib,"getLabel",SideEffects::worstDefault,"das_call_member< const Xbyak::Label * (Xbyak::Address::*)() const , &Xbyak::Address::getLabel >::invoke")
		->args({"self"});
	using _method_99 = das::das_call_member< bool (Xbyak::Address::*)(const Xbyak::Address &) const,&Xbyak::Address::operator== >;
	addExtern<DAS_CALL_METHOD(_method_99)>(*this,lib,"==",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Address::*)(const Xbyak::Address &) const , &Xbyak::Address::operator== >::invoke")
		->args({"self","rhs"});
	using _method_100 = das::das_call_member< bool (Xbyak::Address::*)(const Xbyak::Address &) const,&Xbyak::Address::operator!= >;
	addExtern<DAS_CALL_METHOD(_method_100)>(*this,lib,"!=",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Address::*)(const Xbyak::Address &) const , &Xbyak::Address::operator!= >::invoke")
		->args({"self","rhs"});
	using _method_101 = das::das_call_member< bool (Xbyak::Address::*)() const,&Xbyak::Address::isVsib >;
	addExtern<DAS_CALL_METHOD(_method_101)>(*this,lib,"isVsib",SideEffects::worstDefault,"das_call_member< bool (Xbyak::Address::*)() const , &Xbyak::Address::isVsib >::invoke")
		->args({"self"});
	addCtorAndUsing<Xbyak::AddressFrame,unsigned int,bool>(*this,lib,"AddressFrame","Xbyak::AddressFrame")
		->args({"bit","broadcast"})
		->arg_init(1,make_smart<ExprConstBool>(false));
	using _method_102 = das::das_call_member< Xbyak::Address (Xbyak::AddressFrame::*)(const Xbyak::RegExp &) const,&Xbyak::AddressFrame::operator[] >;
	addExtern<DAS_CALL_METHOD(_method_102),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"[]",SideEffects::worstDefault,"das_call_member< Xbyak::Address (Xbyak::AddressFrame::*)(const Xbyak::RegExp &) const , &Xbyak::AddressFrame::operator[] >::invoke")
		->args({"self","e"});
	using _method_103 = das::das_call_member< Xbyak::Address (Xbyak::AddressFrame::*)(const void *) const,&Xbyak::AddressFrame::operator[] >;
	addExtern<DAS_CALL_METHOD(_method_103),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"[]",SideEffects::worstDefault,"das_call_member< Xbyak::Address (Xbyak::AddressFrame::*)(const void *) const , &Xbyak::AddressFrame::operator[] >::invoke")
		->args({"self","disp"});
	using _method_104 = das::das_call_member< Xbyak::Address (Xbyak::AddressFrame::*)(uint64_t) const,&Xbyak::AddressFrame::operator[] >;
	addExtern<DAS_CALL_METHOD(_method_104),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"[]",SideEffects::worstDefault,"das_call_member< Xbyak::Address (Xbyak::AddressFrame::*)(uint64_t) const , &Xbyak::AddressFrame::operator[] >::invoke")
		->args({"self","disp"});
	using _method_105 = das::das_call_member< Xbyak::Address (Xbyak::AddressFrame::*)(const Xbyak::RegRip &) const,&Xbyak::AddressFrame::operator[] >;
	addExtern<DAS_CALL_METHOD(_method_105),SimNode_ExtFuncCallAndCopyOrMove>(*this,lib,"[]",SideEffects::worstDefault,"das_call_member< Xbyak::Address (Xbyak::AddressFrame::*)(const Xbyak::RegRip &) const , &Xbyak::AddressFrame::operator[] >::invoke")
		->args({"self","addr"});
	addCtorAndUsing<Xbyak::JmpLabel,unsigned long long,int,Xbyak::inner::LabelMode,unsigned long long>(*this,lib,"JmpLabel","Xbyak::JmpLabel")
		->args({"endOfJmp","jmpSize","mode","disp"})
		->arg_init(0,make_smart<ExprConstUInt64>(0x0))
		->arg_init(1,make_smart<ExprConstInt>(0))
		->arg_init(2,make_smart<ExprConstEnumeration>(0,makeType<Xbyak::inner::LabelMode>(lib)))
		->arg_init(3,make_smart<ExprConstUInt64>(0x0));
	addCtorAndUsing<Xbyak::Label>(*this,lib,"Label","Xbyak::Label");
	addCtorAndUsing<Xbyak::Label,const Xbyak::Label &>(*this,lib,"Label","Xbyak::Label")
		->args({"rhs"});
	using _method_106 = das::das_call_member< void (Xbyak::Label::*)(),&Xbyak::Label::clear >;
	addExtern<DAS_CALL_METHOD(_method_106)>(*this,lib,"clear",SideEffects::worstDefault,"das_call_member< void (Xbyak::Label::*)() , &Xbyak::Label::clear >::invoke")
		->args({"self"});
	using _method_107 = das::das_call_member< int (Xbyak::Label::*)() const,&Xbyak::Label::getId >;
	addExtern<DAS_CALL_METHOD(_method_107)>(*this,lib,"getId",SideEffects::worstDefault,"das_call_member< int (Xbyak::Label::*)() const , &Xbyak::Label::getId >::invoke")
		->args({"self"});
	using _method_108 = das::das_call_member< const unsigned char * (Xbyak::Label::*)() const,&Xbyak::Label::getAddress >;
	addExtern<DAS_CALL_METHOD(_method_108)>(*this,lib,"getAddress",SideEffects::worstDefault,"das_call_member< const unsigned char * (Xbyak::Label::*)() const , &Xbyak::Label::getAddress >::invoke")
		->args({"self"});
	addCtorAndUsing<Xbyak::LabelManager>(*this,lib,"LabelManager","Xbyak::LabelManager");
	using _method_109 = das::das_call_member< void (Xbyak::LabelManager::*)(),&Xbyak::LabelManager::reset >;
	addExtern<DAS_CALL_METHOD(_method_109)>(*this,lib,"reset",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)() , &Xbyak::LabelManager::reset >::invoke")
		->args({"self"});
	using _method_110 = das::das_call_member< void (Xbyak::LabelManager::*)(),&Xbyak::LabelManager::enterLocal >;
	addExtern<DAS_CALL_METHOD(_method_110)>(*this,lib,"enterLocal",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)() , &Xbyak::LabelManager::enterLocal >::invoke")
		->args({"self"});
	using _method_111 = das::das_call_member< void (Xbyak::LabelManager::*)(),&Xbyak::LabelManager::leaveLocal >;
	addExtern<DAS_CALL_METHOD(_method_111)>(*this,lib,"leaveLocal",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)() , &Xbyak::LabelManager::leaveLocal >::invoke")
		->args({"self"});
	using _method_112 = das::das_call_member< void (Xbyak::LabelManager::*)(Xbyak::CodeArray *),&Xbyak::LabelManager::set >;
	addExtern<DAS_CALL_METHOD(_method_112)>(*this,lib,"set",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)(Xbyak::CodeArray *) , &Xbyak::LabelManager::set >::invoke")
		->args({"self","base"});
	using _method_113 = das::das_call_member< void (Xbyak::LabelManager::*)(std::basic_string<char>),&Xbyak::LabelManager::defineSlabel >;
	addExtern<DAS_CALL_METHOD(_method_113)>(*this,lib,"defineSlabel",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)(std::basic_string<char>) , &Xbyak::LabelManager::defineSlabel >::invoke")
		->args({"self","label"});
	using _method_114 = das::das_call_member< void (Xbyak::LabelManager::*)(Xbyak::Label &),&Xbyak::LabelManager::defineClabel >;
	addExtern<DAS_CALL_METHOD(_method_114)>(*this,lib,"defineClabel",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)(Xbyak::Label &) , &Xbyak::LabelManager::defineClabel >::invoke")
		->args({"self","label"});
	using _method_115 = das::das_call_member< void (Xbyak::LabelManager::*)(Xbyak::Label &,const Xbyak::Label &),&Xbyak::LabelManager::assign >;
	addExtern<DAS_CALL_METHOD(_method_115)>(*this,lib,"assign",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)(Xbyak::Label &,const Xbyak::Label &) , &Xbyak::LabelManager::assign >::invoke")
		->args({"self","dst","src"});
	using _method_116 = das::das_call_member< bool (Xbyak::LabelManager::*)(size_t *,std::basic_string<char> &) const,&Xbyak::LabelManager::getOffset >;
	addExtern<DAS_CALL_METHOD(_method_116)>(*this,lib,"getOffset",SideEffects::worstDefault,"das_call_member< bool (Xbyak::LabelManager::*)(size_t *,std::basic_string<char> &) const , &Xbyak::LabelManager::getOffset >::invoke")
		->args({"self","offset","label"});
	using _method_117 = das::das_call_member< bool (Xbyak::LabelManager::*)(size_t *,const Xbyak::Label &) const,&Xbyak::LabelManager::getOffset >;
	addExtern<DAS_CALL_METHOD(_method_117)>(*this,lib,"getOffset",SideEffects::worstDefault,"das_call_member< bool (Xbyak::LabelManager::*)(size_t *,const Xbyak::Label &) const , &Xbyak::LabelManager::getOffset >::invoke")
		->args({"self","offset","label"});
	using _method_118 = das::das_call_member< void (Xbyak::LabelManager::*)(const std::basic_string<char> &,const Xbyak::JmpLabel &),&Xbyak::LabelManager::addUndefinedLabel >;
	addExtern<DAS_CALL_METHOD(_method_118)>(*this,lib,"addUndefinedLabel",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)(const std::basic_string<char> &,const Xbyak::JmpLabel &) , &Xbyak::LabelManager::addUndefinedLabel >::invoke")
		->args({"self","label","jmp"});
	using _method_119 = das::das_call_member< void (Xbyak::LabelManager::*)(const Xbyak::Label &,const Xbyak::JmpLabel &),&Xbyak::LabelManager::addUndefinedLabel >;
	addExtern<DAS_CALL_METHOD(_method_119)>(*this,lib,"addUndefinedLabel",SideEffects::worstDefault,"das_call_member< void (Xbyak::LabelManager::*)(const Xbyak::Label &,const Xbyak::JmpLabel &) , &Xbyak::LabelManager::addUndefinedLabel >::invoke")
		->args({"self","label","jmp"});
	using _method_120 = das::das_call_member< bool (Xbyak::LabelManager::*)() const,&Xbyak::LabelManager::hasUndefSlabel >;
	addExtern<DAS_CALL_METHOD(_method_120)>(*this,lib,"hasUndefSlabel",SideEffects::worstDefault,"das_call_member< bool (Xbyak::LabelManager::*)() const , &Xbyak::LabelManager::hasUndefSlabel >::invoke")
		->args({"self"});
	using _method_121 = das::das_call_member< bool (Xbyak::LabelManager::*)() const,&Xbyak::LabelManager::hasUndefClabel >;
	addExtern<DAS_CALL_METHOD(_method_121)>(*this,lib,"hasUndefClabel",SideEffects::worstDefault,"das_call_member< bool (Xbyak::LabelManager::*)() const , &Xbyak::LabelManager::hasUndefClabel >::invoke")
		->args({"self"});
	using _method_122 = das::das_call_member< const unsigned char * (Xbyak::LabelManager::*)() const,&Xbyak::LabelManager::getCode >;
	addExtern<DAS_CALL_METHOD(_method_122)>(*this,lib,"getCode",SideEffects::worstDefault,"das_call_member< const unsigned char * (Xbyak::LabelManager::*)() const , &Xbyak::LabelManager::getCode >::invoke")
		->args({"self"});
	using _method_123 = das::das_call_member< bool (Xbyak::LabelManager::*)() const,&Xbyak::LabelManager::isReady >;
	addExtern<DAS_CALL_METHOD(_method_123)>(*this,lib,"isReady",SideEffects::worstDefault,"das_call_member< bool (Xbyak::LabelManager::*)() const , &Xbyak::LabelManager::isReady >::invoke")
		->args({"self"});
	addExtern< bool (*)(const Xbyak::CodeGenerator &,const Xbyak::Operand &,const Xbyak::Operand &) , _dasXBYAK_static_5_isXMM_XMMorMEM >(*this,lib,"isXMM_XMMorMEM",SideEffects::worstDefault,"_dasXBYAK_static_5_isXMM_XMMorMEM")
		->args({"self","op1","op2"});
	addExtern< bool (*)(const Xbyak::CodeGenerator &,const Xbyak::Operand &,const Xbyak::Operand &) , _dasXBYAK_static_6_isXMMorMMX_MEM >(*this,lib,"isXMMorMMX_MEM",SideEffects::worstDefault,"_dasXBYAK_static_6_isXMMorMMX_MEM")
		->args({"self","op1","op2"});
	addExtern< bool (*)(const Xbyak::CodeGenerator &,const Xbyak::Operand &,const Xbyak::Operand &) , _dasXBYAK_static_7_isXMM_MMXorMEM >(*this,lib,"isXMM_MMXorMEM",SideEffects::worstDefault,"_dasXBYAK_static_7_isXMM_MMXorMEM")
		->args({"self","op1","op2"});
	addExtern< bool (*)(const Xbyak::CodeGenerator &,const Xbyak::Operand &,const Xbyak::Operand &) , _dasXBYAK_static_8_isMMX_XMMorMEM >(*this,lib,"isMMX_XMMorMEM",SideEffects::worstDefault,"_dasXBYAK_static_8_isMMX_XMMorMEM")
		->args({"self","op1","op2"});
	addExtern< bool (*)(const Xbyak::CodeGenerator &,const Xbyak::Operand &,const Xbyak::Operand &) , _dasXBYAK_static_9_isXMM_REG32orMEM >(*this,lib,"isXMM_REG32orMEM",SideEffects::worstDefault,"_dasXBYAK_static_9_isXMM_REG32orMEM")
		->args({"self","op1","op2"});
	addExtern< bool (*)(const Xbyak::CodeGenerator &,const Xbyak::Operand &,const Xbyak::Operand &) , _dasXBYAK_static_10_isREG32_XMMorMEM >(*this,lib,"isREG32_XMMorMEM",SideEffects::worstDefault,"_dasXBYAK_static_10_isREG32_XMMorMEM")
		->args({"self","op1","op2"});
	addExtern< bool (*)(const Xbyak::CodeGenerator &,const Xbyak::Operand &,const Xbyak::Operand &) , _dasXBYAK_static_11_isREG32_REG32orMEM >(*this,lib,"isREG32_REG32orMEM",SideEffects::worstDefault,"_dasXBYAK_static_11_isREG32_REG32orMEM")
		->args({"self","op1","op2"});
	using _method_131 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::rex >;
	addExtern<DAS_CALL_METHOD(_method_131)>(*this,lib,"rex",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::rex >::invoke")
		->args({"self","op1","op2"});
	using _method_132 = das::das_call_member< unsigned int (Xbyak::CodeGenerator::*)(int) const,&Xbyak::CodeGenerator::getPP >;
	addExtern<DAS_CALL_METHOD(_method_132)>(*this,lib,"getPP",SideEffects::worstDefault,"das_call_member< unsigned int (Xbyak::CodeGenerator::*)(int) const , &Xbyak::CodeGenerator::getPP >::invoke")
		->args({"self","type"});
	using _method_133 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Reg &,const Xbyak::Operand *,int,int,bool),&Xbyak::CodeGenerator::vex >;
	addExtern<DAS_CALL_METHOD(_method_133)>(*this,lib,"vex",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Reg &,const Xbyak::Operand *,int,int,bool) , &Xbyak::CodeGenerator::vex >::invoke")
		->args({"self","reg","base","v","type","code","x"})
		->arg_init(6,make_smart<ExprConstBool>(false));
	using _method_134 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,int) const,&Xbyak::CodeGenerator::verifySAE >;
	addExtern<DAS_CALL_METHOD(_method_134)>(*this,lib,"verifySAE",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,int) const , &Xbyak::CodeGenerator::verifySAE >::invoke")
		->args({"self","r","type"});
	using _method_135 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,int) const,&Xbyak::CodeGenerator::verifyER >;
	addExtern<DAS_CALL_METHOD(_method_135)>(*this,lib,"verifyER",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,int) const , &Xbyak::CodeGenerator::verifyER >::invoke")
		->args({"self","r","type"});
	using _method_136 = das::das_call_member< int (Xbyak::CodeGenerator::*)(int,int,int,int),&Xbyak::CodeGenerator::verifyDuplicate >;
	addExtern<DAS_CALL_METHOD(_method_136)>(*this,lib,"verifyDuplicate",SideEffects::worstDefault,"das_call_member< int (Xbyak::CodeGenerator::*)(int,int,int,int) , &Xbyak::CodeGenerator::verifyDuplicate >::invoke")
		->args({"self","a","b","c","err"});
	using _method_137 = das::das_call_member< int (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Reg &,const Xbyak::Operand *,int,int,bool,bool,int,unsigned int,bool),&Xbyak::CodeGenerator::evex >;
	addExtern<DAS_CALL_METHOD(_method_137)>(*this,lib,"evex",SideEffects::worstDefault,"das_call_member< int (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Reg &,const Xbyak::Operand *,int,int,bool,bool,int,unsigned int,bool) , &Xbyak::CodeGenerator::evex >::invoke")
		->args({"self","reg","base","v","type","code","x","b","aaa","VL","Hi16Vidx"})
		->arg_init(6,make_smart<ExprConstBool>(false))
		->arg_init(7,make_smart<ExprConstBool>(false))
		->arg_init(8,make_smart<ExprConstInt>(0))
		->arg_init(9,make_smart<ExprConstUInt>(0x0))
		->arg_init(10,make_smart<ExprConstBool>(false));
	using _method_138 = das::das_call_member< void (Xbyak::CodeGenerator::*)(int,int,int),&Xbyak::CodeGenerator::setModRM >;
	addExtern<DAS_CALL_METHOD(_method_138)>(*this,lib,"setModRM",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(int,int,int) , &Xbyak::CodeGenerator::setModRM >::invoke")
		->args({"self","mod","r1","r2"});
	using _method_139 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::RegExp &,int,int),&Xbyak::CodeGenerator::setSIB >;
	addExtern<DAS_CALL_METHOD(_method_139)>(*this,lib,"setSIB",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::RegExp &,int,int) , &Xbyak::CodeGenerator::setSIB >::invoke")
		->args({"self","e","reg","disp8N"})
		->arg_init(3,make_smart<ExprConstInt>(0));
	using _method_140 = das::das_call_member< bool (Xbyak::CodeGenerator::*)(unsigned int) const,&Xbyak::CodeGenerator::isInDisp16 >;
	addExtern<DAS_CALL_METHOD(_method_140)>(*this,lib,"isInDisp16",SideEffects::worstDefault,"das_call_member< bool (Xbyak::CodeGenerator::*)(unsigned int) const , &Xbyak::CodeGenerator::isInDisp16 >::invoke")
		->args({"self","x"});
	using _method_141 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Reg &,int,int,int),&Xbyak::CodeGenerator::opModR >;
	addExtern<DAS_CALL_METHOD(_method_141)>(*this,lib,"opModR",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Reg &,int,int,int) , &Xbyak::CodeGenerator::opModR >::invoke")
		->args({"self","reg1","reg2","code0","code1","code2"})
		->arg_init(4,make_smart<ExprConstInt>(256))
		->arg_init(5,make_smart<ExprConstInt>(256));
	using _method_142 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg &,int,int,int,int),&Xbyak::CodeGenerator::opModM >;
	addExtern<DAS_CALL_METHOD(_method_142)>(*this,lib,"opModM",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg &,int,int,int,int) , &Xbyak::CodeGenerator::opModM >::invoke")
		->args({"self","addr","reg","code0","code1","code2","immSize"})
		->arg_init(4,make_smart<ExprConstInt>(256))
		->arg_init(5,make_smart<ExprConstInt>(256))
		->arg_init(6,make_smart<ExprConstInt>(0));
	using _method_143 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg &,int,int),&Xbyak::CodeGenerator::opLoadSeg >;
	addExtern<DAS_CALL_METHOD(_method_143)>(*this,lib,"opLoadSeg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg &,int,int) , &Xbyak::CodeGenerator::opLoadSeg >::invoke")
		->args({"self","addr","reg","code0","code1"})
		->arg_init(4,make_smart<ExprConstInt>(256));
	using _method_144 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg &,int,int),&Xbyak::CodeGenerator::opMIB >;
	addExtern<DAS_CALL_METHOD(_method_144)>(*this,lib,"opMIB",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Reg &,int,int) , &Xbyak::CodeGenerator::opMIB >::invoke")
		->args({"self","addr","reg","code0","code1"});
	using _method_145 = das::das_call_member< void (Xbyak::CodeGenerator::*)(unsigned int,Xbyak::CodeGenerator::LabelType,unsigned char,unsigned char,unsigned char),&Xbyak::CodeGenerator::makeJmp >;
	addExtern<DAS_CALL_METHOD(_method_145)>(*this,lib,"makeJmp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(unsigned int,Xbyak::CodeGenerator::LabelType,unsigned char,unsigned char,unsigned char) , &Xbyak::CodeGenerator::makeJmp >::invoke")
		->args({"self","disp","type","shortCode","longCode","longPref"});
	using _method_146 = das::das_call_member< bool (Xbyak::CodeGenerator::*)(Xbyak::CodeGenerator::LabelType) const,&Xbyak::CodeGenerator::isNEAR >;
	addExtern<DAS_CALL_METHOD(_method_146)>(*this,lib,"isNEAR",SideEffects::worstDefault,"das_call_member< bool (Xbyak::CodeGenerator::*)(Xbyak::CodeGenerator::LabelType) const , &Xbyak::CodeGenerator::isNEAR >::invoke")
		->args({"self","type"});
	using _method_147 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const void *,Xbyak::CodeGenerator::LabelType,unsigned char,unsigned char,unsigned char),&Xbyak::CodeGenerator::opJmpAbs >;
	addExtern<DAS_CALL_METHOD(_method_147)>(*this,lib,"opJmpAbs",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const void *,Xbyak::CodeGenerator::LabelType,unsigned char,unsigned char,unsigned char) , &Xbyak::CodeGenerator::opJmpAbs >::invoke")
		->args({"self","addr","type","shortCode","longCode","longPref"});
	using _method_148 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,int,int,int,bool),&Xbyak::CodeGenerator::opAddr >;
	addExtern<DAS_CALL_METHOD(_method_148)>(*this,lib,"opAddr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,int,int,int,bool) , &Xbyak::CodeGenerator::opAddr >::invoke")
		->args({"self","addr","reg","immSize","disp8N","permitVisb"})
		->arg_init(3,make_smart<ExprConstInt>(0))
		->arg_init(4,make_smart<ExprConstInt>(0))
		->arg_init(5,make_smart<ExprConstBool>(false));
	using _method_149 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &,int,int,bool (const Xbyak::Operand &, const Xbyak::Operand &),int,int),&Xbyak::CodeGenerator::opGen >;
	addExtern<DAS_CALL_METHOD(_method_149)>(*this,lib,"opGen",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &,int,int,bool (const Xbyak::Operand &, const Xbyak::Operand &),int,int) , &Xbyak::CodeGenerator::opGen >::invoke")
		->args({"self","reg","op","code","pref","isValid","imm8","preCode"})
		->arg_init(6,make_smart<ExprConstInt>(256))
		->arg_init(7,make_smart<ExprConstInt>(256));
	using _method_150 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int,int,int),&Xbyak::CodeGenerator::opMMX_IMM >;
	addExtern<DAS_CALL_METHOD(_method_150)>(*this,lib,"opMMX_IMM",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int,int,int) , &Xbyak::CodeGenerator::opMMX_IMM >::invoke")
		->args({"self","mmx","imm8","code","ext"});
	using _method_151 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,int,int,int,int),&Xbyak::CodeGenerator::opMMX >;
	addExtern<DAS_CALL_METHOD(_method_151)>(*this,lib,"opMMX",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,int,int,int,int) , &Xbyak::CodeGenerator::opMMX >::invoke")
		->args({"self","mmx","op","code","pref","imm8","preCode"})
		->arg_init(4,make_smart<ExprConstInt>(102))
		->arg_init(5,make_smart<ExprConstInt>(256))
		->arg_init(6,make_smart<ExprConstInt>(256));
	using _method_152 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &,int,int),&Xbyak::CodeGenerator::opMovXMM >;
	addExtern<DAS_CALL_METHOD(_method_152)>(*this,lib,"opMovXMM",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &,int,int) , &Xbyak::CodeGenerator::opMovXMM >::invoke")
		->args({"self","op1","op2","code","pref"});
	using _method_153 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Mmx &,int,int,bool),&Xbyak::CodeGenerator::opExt >;
	addExtern<DAS_CALL_METHOD(_method_153)>(*this,lib,"opExt",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Mmx &,int,int,bool) , &Xbyak::CodeGenerator::opExt >::invoke")
		->args({"self","op","mmx","code","imm","hasMMX2"})
		->arg_init(5,make_smart<ExprConstBool>(false));
	using _method_154 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int,int,int,int,int,bool,int),&Xbyak::CodeGenerator::opR_ModM >;
	addExtern<DAS_CALL_METHOD(_method_154)>(*this,lib,"opR_ModM",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int,int,int,int,int,bool,int) , &Xbyak::CodeGenerator::opR_ModM >::invoke")
		->args({"self","op","bit","ext","code0","code1","code2","disableRex","immSize"})
		->arg_init(5,make_smart<ExprConstInt>(256))
		->arg_init(6,make_smart<ExprConstInt>(256))
		->arg_init(7,make_smart<ExprConstBool>(false))
		->arg_init(8,make_smart<ExprConstInt>(0));
	using _method_155 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int,int),&Xbyak::CodeGenerator::opShift >;
	addExtern<DAS_CALL_METHOD(_method_155)>(*this,lib,"opShift",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int,int) , &Xbyak::CodeGenerator::opShift >::invoke")
		->args({"self","op","imm","ext"});
	using _method_156 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &,int),&Xbyak::CodeGenerator::opShift >;
	addExtern<DAS_CALL_METHOD(_method_156)>(*this,lib,"opShift",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &,int) , &Xbyak::CodeGenerator::opShift >::invoke")
		->args({"self","op","_cl","ext"});
	using _method_157 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &,bool,bool,int,int,int,int),&Xbyak::CodeGenerator::opModRM >;
	addExtern<DAS_CALL_METHOD(_method_157)>(*this,lib,"opModRM",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &,bool,bool,int,int,int,int) , &Xbyak::CodeGenerator::opModRM >::invoke")
		->args({"self","op1","op2","condR","condM","code0","code1","code2","immSize"})
		->arg_init(6,make_smart<ExprConstInt>(256))
		->arg_init(7,make_smart<ExprConstInt>(256))
		->arg_init(8,make_smart<ExprConstInt>(0));
}
}

