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
void Module_dasXBYAK::initFunctions_11() {
	using _method_957 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::roundpd >;
	addExtern<DAS_CALL_METHOD(_method_957)>(*this,lib,"roundpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::roundpd >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_958 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::roundps >;
	addExtern<DAS_CALL_METHOD(_method_958)>(*this,lib,"roundps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::roundps >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_959 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int),&Xbyak::CodeGenerator::roundsd >;
	addExtern<DAS_CALL_METHOD(_method_959)>(*this,lib,"roundsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::roundsd >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_960 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int),&Xbyak::CodeGenerator::roundss >;
	addExtern<DAS_CALL_METHOD(_method_960)>(*this,lib,"roundss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::roundss >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_961 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::rsqrtps >;
	addExtern<DAS_CALL_METHOD(_method_961)>(*this,lib,"rsqrtps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::rsqrtps >::invoke")
		->args({"self","xmm","op"});
	using _method_962 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::rsqrtss >;
	addExtern<DAS_CALL_METHOD(_method_962)>(*this,lib,"rsqrtss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::rsqrtss >::invoke")
		->args({"self","xmm","op"});
	using _method_963 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::sahf >;
	addExtern<DAS_CALL_METHOD(_method_963)>(*this,lib,"sahf",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::sahf >::invoke")
		->args({"self"});
	using _method_964 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::sal >;
	addExtern<DAS_CALL_METHOD(_method_964)>(*this,lib,"sal",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::sal >::invoke")
		->args({"self","op","_cl"});
	using _method_965 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int),&Xbyak::CodeGenerator::sal >;
	addExtern<DAS_CALL_METHOD(_method_965)>(*this,lib,"sal",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::sal >::invoke")
		->args({"self","op","imm"});
	using _method_966 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::sar >;
	addExtern<DAS_CALL_METHOD(_method_966)>(*this,lib,"sar",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::sar >::invoke")
		->args({"self","op","_cl"});
	using _method_967 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int),&Xbyak::CodeGenerator::sar >;
	addExtern<DAS_CALL_METHOD(_method_967)>(*this,lib,"sar",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::sar >::invoke")
		->args({"self","op","imm"});
	using _method_968 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &),&Xbyak::CodeGenerator::sarx >;
	addExtern<DAS_CALL_METHOD(_method_968)>(*this,lib,"sarx",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &) , &Xbyak::CodeGenerator::sarx >::invoke")
		->args({"self","r1","op","r2"});
	using _method_969 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned int),&Xbyak::CodeGenerator::sbb >;
	addExtern<DAS_CALL_METHOD(_method_969)>(*this,lib,"sbb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned int) , &Xbyak::CodeGenerator::sbb >::invoke")
		->args({"self","op","imm"});
	using _method_970 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sbb >;
	addExtern<DAS_CALL_METHOD(_method_970)>(*this,lib,"sbb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sbb >::invoke")
		->args({"self","op1","op2"});
	using _method_971 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::scasb >;
	addExtern<DAS_CALL_METHOD(_method_971)>(*this,lib,"scasb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::scasb >::invoke")
		->args({"self"});
	using _method_972 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::scasd >;
	addExtern<DAS_CALL_METHOD(_method_972)>(*this,lib,"scasd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::scasd >::invoke")
		->args({"self"});
	using _method_973 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::scasw >;
	addExtern<DAS_CALL_METHOD(_method_973)>(*this,lib,"scasw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::scasw >::invoke")
		->args({"self"});
	using _method_974 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::seta >;
	addExtern<DAS_CALL_METHOD(_method_974)>(*this,lib,"seta",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::seta >::invoke")
		->args({"self","op"});
	using _method_975 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setae >;
	addExtern<DAS_CALL_METHOD(_method_975)>(*this,lib,"setae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setae >::invoke")
		->args({"self","op"});
	using _method_976 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setb >;
	addExtern<DAS_CALL_METHOD(_method_976)>(*this,lib,"setb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setb >::invoke")
		->args({"self","op"});
	using _method_977 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setbe >;
	addExtern<DAS_CALL_METHOD(_method_977)>(*this,lib,"setbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setbe >::invoke")
		->args({"self","op"});
	using _method_978 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setc >;
	addExtern<DAS_CALL_METHOD(_method_978)>(*this,lib,"setc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setc >::invoke")
		->args({"self","op"});
	using _method_979 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::sete >;
	addExtern<DAS_CALL_METHOD(_method_979)>(*this,lib,"sete",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::sete >::invoke")
		->args({"self","op"});
	using _method_980 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setg >;
	addExtern<DAS_CALL_METHOD(_method_980)>(*this,lib,"setg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setg >::invoke")
		->args({"self","op"});
	using _method_981 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setge >;
	addExtern<DAS_CALL_METHOD(_method_981)>(*this,lib,"setge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setge >::invoke")
		->args({"self","op"});
	using _method_982 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setl >;
	addExtern<DAS_CALL_METHOD(_method_982)>(*this,lib,"setl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setl >::invoke")
		->args({"self","op"});
	using _method_983 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setle >;
	addExtern<DAS_CALL_METHOD(_method_983)>(*this,lib,"setle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setle >::invoke")
		->args({"self","op"});
	using _method_984 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setna >;
	addExtern<DAS_CALL_METHOD(_method_984)>(*this,lib,"setna",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setna >::invoke")
		->args({"self","op"});
	using _method_985 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnae >;
	addExtern<DAS_CALL_METHOD(_method_985)>(*this,lib,"setnae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnae >::invoke")
		->args({"self","op"});
	using _method_986 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnb >;
	addExtern<DAS_CALL_METHOD(_method_986)>(*this,lib,"setnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnb >::invoke")
		->args({"self","op"});
	using _method_987 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnbe >;
	addExtern<DAS_CALL_METHOD(_method_987)>(*this,lib,"setnbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnbe >::invoke")
		->args({"self","op"});
	using _method_988 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnc >;
	addExtern<DAS_CALL_METHOD(_method_988)>(*this,lib,"setnc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnc >::invoke")
		->args({"self","op"});
	using _method_989 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setne >;
	addExtern<DAS_CALL_METHOD(_method_989)>(*this,lib,"setne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setne >::invoke")
		->args({"self","op"});
	using _method_990 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setng >;
	addExtern<DAS_CALL_METHOD(_method_990)>(*this,lib,"setng",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setng >::invoke")
		->args({"self","op"});
	using _method_991 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnge >;
	addExtern<DAS_CALL_METHOD(_method_991)>(*this,lib,"setnge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnge >::invoke")
		->args({"self","op"});
	using _method_992 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnl >;
	addExtern<DAS_CALL_METHOD(_method_992)>(*this,lib,"setnl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnl >::invoke")
		->args({"self","op"});
	using _method_993 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnle >;
	addExtern<DAS_CALL_METHOD(_method_993)>(*this,lib,"setnle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnle >::invoke")
		->args({"self","op"});
	using _method_994 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setno >;
	addExtern<DAS_CALL_METHOD(_method_994)>(*this,lib,"setno",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setno >::invoke")
		->args({"self","op"});
	using _method_995 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnp >;
	addExtern<DAS_CALL_METHOD(_method_995)>(*this,lib,"setnp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnp >::invoke")
		->args({"self","op"});
	using _method_996 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setns >;
	addExtern<DAS_CALL_METHOD(_method_996)>(*this,lib,"setns",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setns >::invoke")
		->args({"self","op"});
	using _method_997 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setnz >;
	addExtern<DAS_CALL_METHOD(_method_997)>(*this,lib,"setnz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setnz >::invoke")
		->args({"self","op"});
	using _method_998 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::seto >;
	addExtern<DAS_CALL_METHOD(_method_998)>(*this,lib,"seto",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::seto >::invoke")
		->args({"self","op"});
	using _method_999 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setp >;
	addExtern<DAS_CALL_METHOD(_method_999)>(*this,lib,"setp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setp >::invoke")
		->args({"self","op"});
	using _method_1000 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setpe >;
	addExtern<DAS_CALL_METHOD(_method_1000)>(*this,lib,"setpe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setpe >::invoke")
		->args({"self","op"});
	using _method_1001 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setpo >;
	addExtern<DAS_CALL_METHOD(_method_1001)>(*this,lib,"setpo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setpo >::invoke")
		->args({"self","op"});
	using _method_1002 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::sets >;
	addExtern<DAS_CALL_METHOD(_method_1002)>(*this,lib,"sets",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::sets >::invoke")
		->args({"self","op"});
	using _method_1003 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &),&Xbyak::CodeGenerator::setz >;
	addExtern<DAS_CALL_METHOD(_method_1003)>(*this,lib,"setz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &) , &Xbyak::CodeGenerator::setz >::invoke")
		->args({"self","op"});
	using _method_1004 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::sfence >;
	addExtern<DAS_CALL_METHOD(_method_1004)>(*this,lib,"sfence",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::sfence >::invoke")
		->args({"self"});
	using _method_1005 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sha1msg1 >;
	addExtern<DAS_CALL_METHOD(_method_1005)>(*this,lib,"sha1msg1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sha1msg1 >::invoke")
		->args({"self","xmm","op"});
	using _method_1006 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sha1msg2 >;
	addExtern<DAS_CALL_METHOD(_method_1006)>(*this,lib,"sha1msg2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sha1msg2 >::invoke")
		->args({"self","xmm","op"});
	using _method_1007 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sha1nexte >;
	addExtern<DAS_CALL_METHOD(_method_1007)>(*this,lib,"sha1nexte",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sha1nexte >::invoke")
		->args({"self","xmm","op"});
	using _method_1008 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::sha1rnds4 >;
	addExtern<DAS_CALL_METHOD(_method_1008)>(*this,lib,"sha1rnds4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::sha1rnds4 >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_1009 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sha256msg1 >;
	addExtern<DAS_CALL_METHOD(_method_1009)>(*this,lib,"sha256msg1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sha256msg1 >::invoke")
		->args({"self","xmm","op"});
	using _method_1010 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sha256msg2 >;
	addExtern<DAS_CALL_METHOD(_method_1010)>(*this,lib,"sha256msg2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sha256msg2 >::invoke")
		->args({"self","xmm","op"});
	using _method_1011 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sha256rnds2 >;
	addExtern<DAS_CALL_METHOD(_method_1011)>(*this,lib,"sha256rnds2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sha256rnds2 >::invoke")
		->args({"self","xmm","op"});
	using _method_1012 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::shl >;
	addExtern<DAS_CALL_METHOD(_method_1012)>(*this,lib,"shl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::shl >::invoke")
		->args({"self","op","_cl"});
	using _method_1013 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int),&Xbyak::CodeGenerator::shl >;
	addExtern<DAS_CALL_METHOD(_method_1013)>(*this,lib,"shl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::shl >::invoke")
		->args({"self","op","imm"});
	using _method_1014 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::shld >;
	addExtern<DAS_CALL_METHOD(_method_1014)>(*this,lib,"shld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::shld >::invoke")
		->args({"self","op","reg","_cl"});
	using _method_1015 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &,unsigned char),&Xbyak::CodeGenerator::shld >;
	addExtern<DAS_CALL_METHOD(_method_1015)>(*this,lib,"shld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &,unsigned char) , &Xbyak::CodeGenerator::shld >::invoke")
		->args({"self","op","reg","imm"});
	using _method_1016 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &),&Xbyak::CodeGenerator::shlx >;
	addExtern<DAS_CALL_METHOD(_method_1016)>(*this,lib,"shlx",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &) , &Xbyak::CodeGenerator::shlx >::invoke")
		->args({"self","r1","op","r2"});
	using _method_1017 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::shr >;
	addExtern<DAS_CALL_METHOD(_method_1017)>(*this,lib,"shr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::shr >::invoke")
		->args({"self","op","_cl"});
	using _method_1018 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int),&Xbyak::CodeGenerator::shr >;
	addExtern<DAS_CALL_METHOD(_method_1018)>(*this,lib,"shr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::shr >::invoke")
		->args({"self","op","imm"});
	using _method_1019 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::shrd >;
	addExtern<DAS_CALL_METHOD(_method_1019)>(*this,lib,"shrd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::shrd >::invoke")
		->args({"self","op","reg","_cl"});
	using _method_1020 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &,unsigned char),&Xbyak::CodeGenerator::shrd >;
	addExtern<DAS_CALL_METHOD(_method_1020)>(*this,lib,"shrd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &,unsigned char) , &Xbyak::CodeGenerator::shrd >::invoke")
		->args({"self","op","reg","imm"});
	using _method_1021 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &),&Xbyak::CodeGenerator::shrx >;
	addExtern<DAS_CALL_METHOD(_method_1021)>(*this,lib,"shrx",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &) , &Xbyak::CodeGenerator::shrx >::invoke")
		->args({"self","r1","op","r2"});
	using _method_1022 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::shufpd >;
	addExtern<DAS_CALL_METHOD(_method_1022)>(*this,lib,"shufpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::shufpd >::invoke")
		->args({"self","xmm","op","imm8"});
	using _method_1023 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::shufps >;
	addExtern<DAS_CALL_METHOD(_method_1023)>(*this,lib,"shufps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::shufps >::invoke")
		->args({"self","xmm","op","imm8"});
	using _method_1024 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sqrtpd >;
	addExtern<DAS_CALL_METHOD(_method_1024)>(*this,lib,"sqrtpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sqrtpd >::invoke")
		->args({"self","xmm","op"});
	using _method_1025 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sqrtps >;
	addExtern<DAS_CALL_METHOD(_method_1025)>(*this,lib,"sqrtps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sqrtps >::invoke")
		->args({"self","xmm","op"});
	using _method_1026 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sqrtsd >;
	addExtern<DAS_CALL_METHOD(_method_1026)>(*this,lib,"sqrtsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sqrtsd >::invoke")
		->args({"self","xmm","op"});
	using _method_1027 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sqrtss >;
	addExtern<DAS_CALL_METHOD(_method_1027)>(*this,lib,"sqrtss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sqrtss >::invoke")
		->args({"self","xmm","op"});
	using _method_1028 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::stac >;
	addExtern<DAS_CALL_METHOD(_method_1028)>(*this,lib,"stac",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::stac >::invoke")
		->args({"self"});
	using _method_1029 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::stc >;
	addExtern<DAS_CALL_METHOD(_method_1029)>(*this,lib,"stc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::stc >::invoke")
		->args({"self"});
	using _method_1030 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::std >;
	addExtern<DAS_CALL_METHOD(_method_1030)>(*this,lib,"std",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::std >::invoke")
		->args({"self"});
	using _method_1031 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::sti >;
	addExtern<DAS_CALL_METHOD(_method_1031)>(*this,lib,"sti",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::sti >::invoke")
		->args({"self"});
	using _method_1032 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::stmxcsr >;
	addExtern<DAS_CALL_METHOD(_method_1032)>(*this,lib,"stmxcsr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::stmxcsr >::invoke")
		->args({"self","addr"});
	using _method_1033 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::stosb >;
	addExtern<DAS_CALL_METHOD(_method_1033)>(*this,lib,"stosb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::stosb >::invoke")
		->args({"self"});
	using _method_1034 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::stosd >;
	addExtern<DAS_CALL_METHOD(_method_1034)>(*this,lib,"stosd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::stosd >::invoke")
		->args({"self"});
	using _method_1035 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::stosw >;
	addExtern<DAS_CALL_METHOD(_method_1035)>(*this,lib,"stosw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::stosw >::invoke")
		->args({"self"});
	using _method_1036 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned int),&Xbyak::CodeGenerator::sub >;
	addExtern<DAS_CALL_METHOD(_method_1036)>(*this,lib,"sub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned int) , &Xbyak::CodeGenerator::sub >::invoke")
		->args({"self","op","imm"});
	using _method_1037 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::sub >;
	addExtern<DAS_CALL_METHOD(_method_1037)>(*this,lib,"sub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::sub >::invoke")
		->args({"self","op1","op2"});
	using _method_1038 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::subpd >;
	addExtern<DAS_CALL_METHOD(_method_1038)>(*this,lib,"subpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::subpd >::invoke")
		->args({"self","xmm","op"});
	using _method_1039 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::subps >;
	addExtern<DAS_CALL_METHOD(_method_1039)>(*this,lib,"subps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::subps >::invoke")
		->args({"self","xmm","op"});
	using _method_1040 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::subsd >;
	addExtern<DAS_CALL_METHOD(_method_1040)>(*this,lib,"subsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::subsd >::invoke")
		->args({"self","xmm","op"});
	using _method_1041 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::subss >;
	addExtern<DAS_CALL_METHOD(_method_1041)>(*this,lib,"subss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::subss >::invoke")
		->args({"self","xmm","op"});
	using _method_1042 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::sysenter >;
	addExtern<DAS_CALL_METHOD(_method_1042)>(*this,lib,"sysenter",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::sysenter >::invoke")
		->args({"self"});
	using _method_1043 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::sysexit >;
	addExtern<DAS_CALL_METHOD(_method_1043)>(*this,lib,"sysexit",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::sysexit >::invoke")
		->args({"self"});
	using _method_1044 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::tzcnt >;
	addExtern<DAS_CALL_METHOD(_method_1044)>(*this,lib,"tzcnt",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::tzcnt >::invoke")
		->args({"self","reg","op"});
	using _method_1045 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::ucomisd >;
	addExtern<DAS_CALL_METHOD(_method_1045)>(*this,lib,"ucomisd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::ucomisd >::invoke")
		->args({"self","xmm","op"});
	using _method_1046 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::ucomiss >;
	addExtern<DAS_CALL_METHOD(_method_1046)>(*this,lib,"ucomiss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::ucomiss >::invoke")
		->args({"self","xmm","op"});
	using _method_1047 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::ud2 >;
	addExtern<DAS_CALL_METHOD(_method_1047)>(*this,lib,"ud2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::ud2 >::invoke")
		->args({"self"});
	using _method_1048 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::unpckhpd >;
	addExtern<DAS_CALL_METHOD(_method_1048)>(*this,lib,"unpckhpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::unpckhpd >::invoke")
		->args({"self","xmm","op"});
	using _method_1049 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::unpckhps >;
	addExtern<DAS_CALL_METHOD(_method_1049)>(*this,lib,"unpckhps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::unpckhps >::invoke")
		->args({"self","xmm","op"});
	using _method_1050 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::unpcklpd >;
	addExtern<DAS_CALL_METHOD(_method_1050)>(*this,lib,"unpcklpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::unpcklpd >::invoke")
		->args({"self","xmm","op"});
	using _method_1051 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::unpcklps >;
	addExtern<DAS_CALL_METHOD(_method_1051)>(*this,lib,"unpcklps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::unpcklps >::invoke")
		->args({"self","xmm","op"});
	using _method_1052 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaddpd >;
	addExtern<DAS_CALL_METHOD(_method_1052)>(*this,lib,"vaddpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaddpd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1053 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaddps >;
	addExtern<DAS_CALL_METHOD(_method_1053)>(*this,lib,"vaddps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaddps >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1054 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaddsd >;
	addExtern<DAS_CALL_METHOD(_method_1054)>(*this,lib,"vaddsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaddsd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1055 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaddss >;
	addExtern<DAS_CALL_METHOD(_method_1055)>(*this,lib,"vaddss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaddss >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1056 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vaddsubpd >;
	addExtern<DAS_CALL_METHOD(_method_1056)>(*this,lib,"vaddsubpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vaddsubpd >::invoke")
		->args({"self","xmm","op1","op2"});
}
}

