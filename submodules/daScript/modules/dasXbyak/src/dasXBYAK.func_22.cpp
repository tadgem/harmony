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
void Module_dasXBYAK::initFunctions_22() {
	using _method_2057 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermi2w >;
	addExtern<DAS_CALL_METHOD(_method_2057)>(*this,lib,"vpermi2w",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermi2w >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2058 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermt2b >;
	addExtern<DAS_CALL_METHOD(_method_2058)>(*this,lib,"vpermt2b",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermt2b >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2059 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermt2d >;
	addExtern<DAS_CALL_METHOD(_method_2059)>(*this,lib,"vpermt2d",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermt2d >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2060 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermt2pd >;
	addExtern<DAS_CALL_METHOD(_method_2060)>(*this,lib,"vpermt2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermt2pd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2061 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermt2ps >;
	addExtern<DAS_CALL_METHOD(_method_2061)>(*this,lib,"vpermt2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermt2ps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2062 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermt2q >;
	addExtern<DAS_CALL_METHOD(_method_2062)>(*this,lib,"vpermt2q",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermt2q >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2063 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermt2w >;
	addExtern<DAS_CALL_METHOD(_method_2063)>(*this,lib,"vpermt2w",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermt2w >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2064 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermw >;
	addExtern<DAS_CALL_METHOD(_method_2064)>(*this,lib,"vpermw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2065 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpexpandb >;
	addExtern<DAS_CALL_METHOD(_method_2065)>(*this,lib,"vpexpandb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpexpandb >::invoke")
		->args({"self","x","op"});
	using _method_2066 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpexpandd >;
	addExtern<DAS_CALL_METHOD(_method_2066)>(*this,lib,"vpexpandd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpexpandd >::invoke")
		->args({"self","x","op"});
	using _method_2067 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpexpandq >;
	addExtern<DAS_CALL_METHOD(_method_2067)>(*this,lib,"vpexpandq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpexpandq >::invoke")
		->args({"self","x","op"});
	using _method_2068 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpexpandw >;
	addExtern<DAS_CALL_METHOD(_method_2068)>(*this,lib,"vpexpandw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpexpandw >::invoke")
		->args({"self","x","op"});
	using _method_2069 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vpgatherdd >;
	addExtern<DAS_CALL_METHOD(_method_2069)>(*this,lib,"vpgatherdd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vpgatherdd >::invoke")
		->args({"self","x","addr"});
	using _method_2070 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vpgatherdq >;
	addExtern<DAS_CALL_METHOD(_method_2070)>(*this,lib,"vpgatherdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vpgatherdq >::invoke")
		->args({"self","x","addr"});
	using _method_2071 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vpgatherqd >;
	addExtern<DAS_CALL_METHOD(_method_2071)>(*this,lib,"vpgatherqd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vpgatherqd >::invoke")
		->args({"self","x","addr"});
	using _method_2072 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vpgatherqq >;
	addExtern<DAS_CALL_METHOD(_method_2072)>(*this,lib,"vpgatherqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vpgatherqq >::invoke")
		->args({"self","x","addr"});
	using _method_2073 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vplzcntd >;
	addExtern<DAS_CALL_METHOD(_method_2073)>(*this,lib,"vplzcntd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vplzcntd >::invoke")
		->args({"self","x","op"});
	using _method_2074 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vplzcntq >;
	addExtern<DAS_CALL_METHOD(_method_2074)>(*this,lib,"vplzcntq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vplzcntq >::invoke")
		->args({"self","x","op"});
	using _method_2075 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmadd52huq >;
	addExtern<DAS_CALL_METHOD(_method_2075)>(*this,lib,"vpmadd52huq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmadd52huq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2076 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmadd52luq >;
	addExtern<DAS_CALL_METHOD(_method_2076)>(*this,lib,"vpmadd52luq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmadd52luq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2077 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaxsq >;
	addExtern<DAS_CALL_METHOD(_method_2077)>(*this,lib,"vpmaxsq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaxsq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2078 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaxuq >;
	addExtern<DAS_CALL_METHOD(_method_2078)>(*this,lib,"vpmaxuq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaxuq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2079 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpminsq >;
	addExtern<DAS_CALL_METHOD(_method_2079)>(*this,lib,"vpminsq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpminsq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2080 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpminuq >;
	addExtern<DAS_CALL_METHOD(_method_2080)>(*this,lib,"vpminuq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpminuq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2081 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovb2m >;
	addExtern<DAS_CALL_METHOD(_method_2081)>(*this,lib,"vpmovb2m",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovb2m >::invoke")
		->args({"self","k","x"});
	using _method_2082 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovd2m >;
	addExtern<DAS_CALL_METHOD(_method_2082)>(*this,lib,"vpmovd2m",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovd2m >::invoke")
		->args({"self","k","x"});
	using _method_2083 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovdb >;
	addExtern<DAS_CALL_METHOD(_method_2083)>(*this,lib,"vpmovdb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovdb >::invoke")
		->args({"self","op","x"});
	using _method_2084 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovdw >;
	addExtern<DAS_CALL_METHOD(_method_2084)>(*this,lib,"vpmovdw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovdw >::invoke")
		->args({"self","op","x"});
	using _method_2085 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::vpmovm2b >;
	addExtern<DAS_CALL_METHOD(_method_2085)>(*this,lib,"vpmovm2b",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::vpmovm2b >::invoke")
		->args({"self","x","k"});
	using _method_2086 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::vpmovm2d >;
	addExtern<DAS_CALL_METHOD(_method_2086)>(*this,lib,"vpmovm2d",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::vpmovm2d >::invoke")
		->args({"self","x","k"});
	using _method_2087 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::vpmovm2q >;
	addExtern<DAS_CALL_METHOD(_method_2087)>(*this,lib,"vpmovm2q",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::vpmovm2q >::invoke")
		->args({"self","x","k"});
	using _method_2088 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::vpmovm2w >;
	addExtern<DAS_CALL_METHOD(_method_2088)>(*this,lib,"vpmovm2w",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::vpmovm2w >::invoke")
		->args({"self","x","k"});
	using _method_2089 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovq2m >;
	addExtern<DAS_CALL_METHOD(_method_2089)>(*this,lib,"vpmovq2m",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovq2m >::invoke")
		->args({"self","k","x"});
	using _method_2090 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovqb >;
	addExtern<DAS_CALL_METHOD(_method_2090)>(*this,lib,"vpmovqb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovqb >::invoke")
		->args({"self","op","x"});
	using _method_2091 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovqd >;
	addExtern<DAS_CALL_METHOD(_method_2091)>(*this,lib,"vpmovqd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovqd >::invoke")
		->args({"self","op","x"});
	using _method_2092 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovqw >;
	addExtern<DAS_CALL_METHOD(_method_2092)>(*this,lib,"vpmovqw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovqw >::invoke")
		->args({"self","op","x"});
	using _method_2093 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovsdb >;
	addExtern<DAS_CALL_METHOD(_method_2093)>(*this,lib,"vpmovsdb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovsdb >::invoke")
		->args({"self","op","x"});
	using _method_2094 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovsdw >;
	addExtern<DAS_CALL_METHOD(_method_2094)>(*this,lib,"vpmovsdw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovsdw >::invoke")
		->args({"self","op","x"});
	using _method_2095 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovsqb >;
	addExtern<DAS_CALL_METHOD(_method_2095)>(*this,lib,"vpmovsqb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovsqb >::invoke")
		->args({"self","op","x"});
	using _method_2096 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovsqd >;
	addExtern<DAS_CALL_METHOD(_method_2096)>(*this,lib,"vpmovsqd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovsqd >::invoke")
		->args({"self","op","x"});
	using _method_2097 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovsqw >;
	addExtern<DAS_CALL_METHOD(_method_2097)>(*this,lib,"vpmovsqw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovsqw >::invoke")
		->args({"self","op","x"});
	using _method_2098 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovswb >;
	addExtern<DAS_CALL_METHOD(_method_2098)>(*this,lib,"vpmovswb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovswb >::invoke")
		->args({"self","op","x"});
	using _method_2099 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovusdb >;
	addExtern<DAS_CALL_METHOD(_method_2099)>(*this,lib,"vpmovusdb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovusdb >::invoke")
		->args({"self","op","x"});
	using _method_2100 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovusdw >;
	addExtern<DAS_CALL_METHOD(_method_2100)>(*this,lib,"vpmovusdw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovusdw >::invoke")
		->args({"self","op","x"});
	using _method_2101 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovusqb >;
	addExtern<DAS_CALL_METHOD(_method_2101)>(*this,lib,"vpmovusqb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovusqb >::invoke")
		->args({"self","op","x"});
	using _method_2102 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovusqd >;
	addExtern<DAS_CALL_METHOD(_method_2102)>(*this,lib,"vpmovusqd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovusqd >::invoke")
		->args({"self","op","x"});
	using _method_2103 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovusqw >;
	addExtern<DAS_CALL_METHOD(_method_2103)>(*this,lib,"vpmovusqw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovusqw >::invoke")
		->args({"self","op","x"});
	using _method_2104 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovuswb >;
	addExtern<DAS_CALL_METHOD(_method_2104)>(*this,lib,"vpmovuswb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovuswb >::invoke")
		->args({"self","op","x"});
	using _method_2105 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovw2m >;
	addExtern<DAS_CALL_METHOD(_method_2105)>(*this,lib,"vpmovw2m",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovw2m >::invoke")
		->args({"self","k","x"});
	using _method_2106 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmovwb >;
	addExtern<DAS_CALL_METHOD(_method_2106)>(*this,lib,"vpmovwb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmovwb >::invoke")
		->args({"self","op","x"});
	using _method_2107 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmullq >;
	addExtern<DAS_CALL_METHOD(_method_2107)>(*this,lib,"vpmullq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmullq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2108 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmultishiftqb >;
	addExtern<DAS_CALL_METHOD(_method_2108)>(*this,lib,"vpmultishiftqb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmultishiftqb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2109 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpopcntb >;
	addExtern<DAS_CALL_METHOD(_method_2109)>(*this,lib,"vpopcntb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpopcntb >::invoke")
		->args({"self","x","op"});
	using _method_2110 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpopcntd >;
	addExtern<DAS_CALL_METHOD(_method_2110)>(*this,lib,"vpopcntd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpopcntd >::invoke")
		->args({"self","x","op"});
	using _method_2111 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpopcntq >;
	addExtern<DAS_CALL_METHOD(_method_2111)>(*this,lib,"vpopcntq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpopcntq >::invoke")
		->args({"self","x","op"});
	using _method_2112 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpopcntw >;
	addExtern<DAS_CALL_METHOD(_method_2112)>(*this,lib,"vpopcntw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpopcntw >::invoke")
		->args({"self","x","op"});
	using _method_2113 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpord >;
	addExtern<DAS_CALL_METHOD(_method_2113)>(*this,lib,"vpord",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpord >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2114 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vporq >;
	addExtern<DAS_CALL_METHOD(_method_2114)>(*this,lib,"vporq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vporq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2115 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vprold >;
	addExtern<DAS_CALL_METHOD(_method_2115)>(*this,lib,"vprold",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vprold >::invoke")
		->args({"self","x","op","imm"});
	using _method_2116 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vprolq >;
	addExtern<DAS_CALL_METHOD(_method_2116)>(*this,lib,"vprolq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vprolq >::invoke")
		->args({"self","x","op","imm"});
	using _method_2117 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vprolvd >;
	addExtern<DAS_CALL_METHOD(_method_2117)>(*this,lib,"vprolvd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vprolvd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2118 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vprolvq >;
	addExtern<DAS_CALL_METHOD(_method_2118)>(*this,lib,"vprolvq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vprolvq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2119 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vprord >;
	addExtern<DAS_CALL_METHOD(_method_2119)>(*this,lib,"vprord",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vprord >::invoke")
		->args({"self","x","op","imm"});
	using _method_2120 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vprorq >;
	addExtern<DAS_CALL_METHOD(_method_2120)>(*this,lib,"vprorq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vprorq >::invoke")
		->args({"self","x","op","imm"});
	using _method_2121 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vprorvd >;
	addExtern<DAS_CALL_METHOD(_method_2121)>(*this,lib,"vprorvd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vprorvd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2122 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vprorvq >;
	addExtern<DAS_CALL_METHOD(_method_2122)>(*this,lib,"vprorvq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vprorvq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2123 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpscatterdd >;
	addExtern<DAS_CALL_METHOD(_method_2123)>(*this,lib,"vpscatterdd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpscatterdd >::invoke")
		->args({"self","addr","x"});
	using _method_2124 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpscatterdq >;
	addExtern<DAS_CALL_METHOD(_method_2124)>(*this,lib,"vpscatterdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpscatterdq >::invoke")
		->args({"self","addr","x"});
	using _method_2125 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpscatterqd >;
	addExtern<DAS_CALL_METHOD(_method_2125)>(*this,lib,"vpscatterqd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpscatterqd >::invoke")
		->args({"self","addr","x"});
	using _method_2126 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpscatterqq >;
	addExtern<DAS_CALL_METHOD(_method_2126)>(*this,lib,"vpscatterqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpscatterqq >::invoke")
		->args({"self","addr","x"});
	using _method_2127 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshldd >;
	addExtern<DAS_CALL_METHOD(_method_2127)>(*this,lib,"vpshldd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshldd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2128 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshldq >;
	addExtern<DAS_CALL_METHOD(_method_2128)>(*this,lib,"vpshldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshldq >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2129 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpshldvd >;
	addExtern<DAS_CALL_METHOD(_method_2129)>(*this,lib,"vpshldvd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpshldvd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2130 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpshldvq >;
	addExtern<DAS_CALL_METHOD(_method_2130)>(*this,lib,"vpshldvq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpshldvq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2131 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpshldvw >;
	addExtern<DAS_CALL_METHOD(_method_2131)>(*this,lib,"vpshldvw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpshldvw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2132 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshldw >;
	addExtern<DAS_CALL_METHOD(_method_2132)>(*this,lib,"vpshldw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshldw >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2133 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshrdd >;
	addExtern<DAS_CALL_METHOD(_method_2133)>(*this,lib,"vpshrdd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshrdd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2134 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshrdq >;
	addExtern<DAS_CALL_METHOD(_method_2134)>(*this,lib,"vpshrdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshrdq >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2135 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpshrdvd >;
	addExtern<DAS_CALL_METHOD(_method_2135)>(*this,lib,"vpshrdvd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpshrdvd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2136 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpshrdvq >;
	addExtern<DAS_CALL_METHOD(_method_2136)>(*this,lib,"vpshrdvq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpshrdvq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2137 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpshrdvw >;
	addExtern<DAS_CALL_METHOD(_method_2137)>(*this,lib,"vpshrdvw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpshrdvw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2138 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpshrdw >;
	addExtern<DAS_CALL_METHOD(_method_2138)>(*this,lib,"vpshrdw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpshrdw >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2139 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpshufbitqmb >;
	addExtern<DAS_CALL_METHOD(_method_2139)>(*this,lib,"vpshufbitqmb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpshufbitqmb >::invoke")
		->args({"self","k","x","op"});
	using _method_2140 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsllvw >;
	addExtern<DAS_CALL_METHOD(_method_2140)>(*this,lib,"vpsllvw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsllvw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2141 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpsraq >;
	addExtern<DAS_CALL_METHOD(_method_2141)>(*this,lib,"vpsraq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpsraq >::invoke")
		->args({"self","x","op","imm"});
	using _method_2142 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsraq >;
	addExtern<DAS_CALL_METHOD(_method_2142)>(*this,lib,"vpsraq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsraq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2143 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsravq >;
	addExtern<DAS_CALL_METHOD(_method_2143)>(*this,lib,"vpsravq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsravq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2144 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsravw >;
	addExtern<DAS_CALL_METHOD(_method_2144)>(*this,lib,"vpsravw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsravw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2145 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpsrlvw >;
	addExtern<DAS_CALL_METHOD(_method_2145)>(*this,lib,"vpsrlvw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpsrlvw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2146 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpternlogd >;
	addExtern<DAS_CALL_METHOD(_method_2146)>(*this,lib,"vpternlogd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpternlogd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2147 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpternlogq >;
	addExtern<DAS_CALL_METHOD(_method_2147)>(*this,lib,"vpternlogq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpternlogq >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2148 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptestmb >;
	addExtern<DAS_CALL_METHOD(_method_2148)>(*this,lib,"vptestmb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptestmb >::invoke")
		->args({"self","k","x","op"});
	using _method_2149 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptestmd >;
	addExtern<DAS_CALL_METHOD(_method_2149)>(*this,lib,"vptestmd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptestmd >::invoke")
		->args({"self","k","x","op"});
	using _method_2150 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptestmq >;
	addExtern<DAS_CALL_METHOD(_method_2150)>(*this,lib,"vptestmq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptestmq >::invoke")
		->args({"self","k","x","op"});
	using _method_2151 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptestmw >;
	addExtern<DAS_CALL_METHOD(_method_2151)>(*this,lib,"vptestmw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptestmw >::invoke")
		->args({"self","k","x","op"});
	using _method_2152 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptestnmb >;
	addExtern<DAS_CALL_METHOD(_method_2152)>(*this,lib,"vptestnmb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptestnmb >::invoke")
		->args({"self","k","x","op"});
	using _method_2153 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptestnmd >;
	addExtern<DAS_CALL_METHOD(_method_2153)>(*this,lib,"vptestnmd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptestnmd >::invoke")
		->args({"self","k","x","op"});
	using _method_2154 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptestnmq >;
	addExtern<DAS_CALL_METHOD(_method_2154)>(*this,lib,"vptestnmq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptestnmq >::invoke")
		->args({"self","k","x","op"});
	using _method_2155 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vptestnmw >;
	addExtern<DAS_CALL_METHOD(_method_2155)>(*this,lib,"vptestnmw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vptestnmw >::invoke")
		->args({"self","k","x","op"});
	using _method_2156 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpxord >;
	addExtern<DAS_CALL_METHOD(_method_2156)>(*this,lib,"vpxord",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpxord >::invoke")
		->args({"self","x1","x2","op"});
}
}

