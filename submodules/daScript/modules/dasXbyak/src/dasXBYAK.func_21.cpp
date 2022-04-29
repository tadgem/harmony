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
void Module_dasXBYAK::initFunctions_21() {
	using _method_1957 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherdpd >;
	addExtern<DAS_CALL_METHOD(_method_1957)>(*this,lib,"vgatherdpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherdpd >::invoke")
		->args({"self","x","addr"});
	using _method_1958 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherdps >;
	addExtern<DAS_CALL_METHOD(_method_1958)>(*this,lib,"vgatherdps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherdps >::invoke")
		->args({"self","x","addr"});
	using _method_1959 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherpf0dpd >;
	addExtern<DAS_CALL_METHOD(_method_1959)>(*this,lib,"vgatherpf0dpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherpf0dpd >::invoke")
		->args({"self","addr"});
	using _method_1960 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherpf0dps >;
	addExtern<DAS_CALL_METHOD(_method_1960)>(*this,lib,"vgatherpf0dps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherpf0dps >::invoke")
		->args({"self","addr"});
	using _method_1961 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherpf0qpd >;
	addExtern<DAS_CALL_METHOD(_method_1961)>(*this,lib,"vgatherpf0qpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherpf0qpd >::invoke")
		->args({"self","addr"});
	using _method_1962 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherpf0qps >;
	addExtern<DAS_CALL_METHOD(_method_1962)>(*this,lib,"vgatherpf0qps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherpf0qps >::invoke")
		->args({"self","addr"});
	using _method_1963 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherpf1dpd >;
	addExtern<DAS_CALL_METHOD(_method_1963)>(*this,lib,"vgatherpf1dpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherpf1dpd >::invoke")
		->args({"self","addr"});
	using _method_1964 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherpf1dps >;
	addExtern<DAS_CALL_METHOD(_method_1964)>(*this,lib,"vgatherpf1dps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherpf1dps >::invoke")
		->args({"self","addr"});
	using _method_1965 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherpf1qpd >;
	addExtern<DAS_CALL_METHOD(_method_1965)>(*this,lib,"vgatherpf1qpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherpf1qpd >::invoke")
		->args({"self","addr"});
	using _method_1966 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherpf1qps >;
	addExtern<DAS_CALL_METHOD(_method_1966)>(*this,lib,"vgatherpf1qps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherpf1qps >::invoke")
		->args({"self","addr"});
	using _method_1967 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherqpd >;
	addExtern<DAS_CALL_METHOD(_method_1967)>(*this,lib,"vgatherqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherqpd >::invoke")
		->args({"self","x","addr"});
	using _method_1968 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vgatherqps >;
	addExtern<DAS_CALL_METHOD(_method_1968)>(*this,lib,"vgatherqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vgatherqps >::invoke")
		->args({"self","x","addr"});
	using _method_1969 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vgetexppd >;
	addExtern<DAS_CALL_METHOD(_method_1969)>(*this,lib,"vgetexppd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vgetexppd >::invoke")
		->args({"self","x","op"});
	using _method_1970 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vgetexpph >;
	addExtern<DAS_CALL_METHOD(_method_1970)>(*this,lib,"vgetexpph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vgetexpph >::invoke")
		->args({"self","x","op"});
	using _method_1971 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vgetexpps >;
	addExtern<DAS_CALL_METHOD(_method_1971)>(*this,lib,"vgetexpps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vgetexpps >::invoke")
		->args({"self","x","op"});
	using _method_1972 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vgetexpsd >;
	addExtern<DAS_CALL_METHOD(_method_1972)>(*this,lib,"vgetexpsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vgetexpsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1973 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vgetexpsh >;
	addExtern<DAS_CALL_METHOD(_method_1973)>(*this,lib,"vgetexpsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vgetexpsh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1974 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vgetexpss >;
	addExtern<DAS_CALL_METHOD(_method_1974)>(*this,lib,"vgetexpss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vgetexpss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1975 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vgetmantpd >;
	addExtern<DAS_CALL_METHOD(_method_1975)>(*this,lib,"vgetmantpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vgetmantpd >::invoke")
		->args({"self","x","op","imm"});
	using _method_1976 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vgetmantph >;
	addExtern<DAS_CALL_METHOD(_method_1976)>(*this,lib,"vgetmantph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vgetmantph >::invoke")
		->args({"self","x","op","imm"});
	using _method_1977 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vgetmantps >;
	addExtern<DAS_CALL_METHOD(_method_1977)>(*this,lib,"vgetmantps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vgetmantps >::invoke")
		->args({"self","x","op","imm"});
	using _method_1978 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vgetmantsd >;
	addExtern<DAS_CALL_METHOD(_method_1978)>(*this,lib,"vgetmantsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vgetmantsd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1979 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vgetmantsh >;
	addExtern<DAS_CALL_METHOD(_method_1979)>(*this,lib,"vgetmantsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vgetmantsh >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1980 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vgetmantss >;
	addExtern<DAS_CALL_METHOD(_method_1980)>(*this,lib,"vgetmantss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vgetmantss >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1981 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vinsertf32x4 >;
	addExtern<DAS_CALL_METHOD(_method_1981)>(*this,lib,"vinsertf32x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vinsertf32x4 >::invoke")
		->args({"self","r1","r2","op","imm"});
	using _method_1982 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vinsertf32x8 >;
	addExtern<DAS_CALL_METHOD(_method_1982)>(*this,lib,"vinsertf32x8",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vinsertf32x8 >::invoke")
		->args({"self","r1","r2","op","imm"});
	using _method_1983 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vinsertf64x2 >;
	addExtern<DAS_CALL_METHOD(_method_1983)>(*this,lib,"vinsertf64x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vinsertf64x2 >::invoke")
		->args({"self","r1","r2","op","imm"});
	using _method_1984 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vinsertf64x4 >;
	addExtern<DAS_CALL_METHOD(_method_1984)>(*this,lib,"vinsertf64x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vinsertf64x4 >::invoke")
		->args({"self","r1","r2","op","imm"});
	using _method_1985 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vinserti32x4 >;
	addExtern<DAS_CALL_METHOD(_method_1985)>(*this,lib,"vinserti32x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vinserti32x4 >::invoke")
		->args({"self","r1","r2","op","imm"});
	using _method_1986 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vinserti32x8 >;
	addExtern<DAS_CALL_METHOD(_method_1986)>(*this,lib,"vinserti32x8",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vinserti32x8 >::invoke")
		->args({"self","r1","r2","op","imm"});
	using _method_1987 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vinserti64x2 >;
	addExtern<DAS_CALL_METHOD(_method_1987)>(*this,lib,"vinserti64x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vinserti64x2 >::invoke")
		->args({"self","r1","r2","op","imm"});
	using _method_1988 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vinserti64x4 >;
	addExtern<DAS_CALL_METHOD(_method_1988)>(*this,lib,"vinserti64x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vinserti64x4 >::invoke")
		->args({"self","r1","r2","op","imm"});
	using _method_1989 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmaxph >;
	addExtern<DAS_CALL_METHOD(_method_1989)>(*this,lib,"vmaxph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmaxph >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1990 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmaxsh >;
	addExtern<DAS_CALL_METHOD(_method_1990)>(*this,lib,"vmaxsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmaxsh >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1991 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vminph >;
	addExtern<DAS_CALL_METHOD(_method_1991)>(*this,lib,"vminph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vminph >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1992 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vminsh >;
	addExtern<DAS_CALL_METHOD(_method_1992)>(*this,lib,"vminsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vminsh >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1993 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovdqa32 >;
	addExtern<DAS_CALL_METHOD(_method_1993)>(*this,lib,"vmovdqa32",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovdqa32 >::invoke")
		->args({"self","addr","x"});
	using _method_1994 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovdqa32 >;
	addExtern<DAS_CALL_METHOD(_method_1994)>(*this,lib,"vmovdqa32",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovdqa32 >::invoke")
		->args({"self","x","op"});
	using _method_1995 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovdqa64 >;
	addExtern<DAS_CALL_METHOD(_method_1995)>(*this,lib,"vmovdqa64",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovdqa64 >::invoke")
		->args({"self","addr","x"});
	using _method_1996 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovdqa64 >;
	addExtern<DAS_CALL_METHOD(_method_1996)>(*this,lib,"vmovdqa64",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovdqa64 >::invoke")
		->args({"self","x","op"});
	using _method_1997 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovdqu16 >;
	addExtern<DAS_CALL_METHOD(_method_1997)>(*this,lib,"vmovdqu16",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovdqu16 >::invoke")
		->args({"self","addr","x"});
	using _method_1998 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovdqu16 >;
	addExtern<DAS_CALL_METHOD(_method_1998)>(*this,lib,"vmovdqu16",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovdqu16 >::invoke")
		->args({"self","x","op"});
	using _method_1999 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovdqu32 >;
	addExtern<DAS_CALL_METHOD(_method_1999)>(*this,lib,"vmovdqu32",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovdqu32 >::invoke")
		->args({"self","addr","x"});
	using _method_2000 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovdqu32 >;
	addExtern<DAS_CALL_METHOD(_method_2000)>(*this,lib,"vmovdqu32",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovdqu32 >::invoke")
		->args({"self","x","op"});
	using _method_2001 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovdqu64 >;
	addExtern<DAS_CALL_METHOD(_method_2001)>(*this,lib,"vmovdqu64",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovdqu64 >::invoke")
		->args({"self","addr","x"});
	using _method_2002 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovdqu64 >;
	addExtern<DAS_CALL_METHOD(_method_2002)>(*this,lib,"vmovdqu64",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovdqu64 >::invoke")
		->args({"self","x","op"});
	using _method_2003 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovdqu8 >;
	addExtern<DAS_CALL_METHOD(_method_2003)>(*this,lib,"vmovdqu8",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovdqu8 >::invoke")
		->args({"self","addr","x"});
	using _method_2004 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovdqu8 >;
	addExtern<DAS_CALL_METHOD(_method_2004)>(*this,lib,"vmovdqu8",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovdqu8 >::invoke")
		->args({"self","x","op"});
	using _method_2005 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovsh >;
	addExtern<DAS_CALL_METHOD(_method_2005)>(*this,lib,"vmovsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovsh >::invoke")
		->args({"self","addr","x"});
	using _method_2006 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vmovsh >;
	addExtern<DAS_CALL_METHOD(_method_2006)>(*this,lib,"vmovsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vmovsh >::invoke")
		->args({"self","x","addr"});
	using _method_2007 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovsh >;
	addExtern<DAS_CALL_METHOD(_method_2007)>(*this,lib,"vmovsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovsh >::invoke")
		->args({"self","x1","x2","x3"});
	using _method_2008 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovw >;
	addExtern<DAS_CALL_METHOD(_method_2008)>(*this,lib,"vmovw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovw >::invoke")
		->args({"self","addr","x"});
	using _method_2009 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovw >;
	addExtern<DAS_CALL_METHOD(_method_2009)>(*this,lib,"vmovw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovw >::invoke")
		->args({"self","r","x"});
	using _method_2010 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovw >;
	addExtern<DAS_CALL_METHOD(_method_2010)>(*this,lib,"vmovw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovw >::invoke")
		->args({"self","x","op"});
	using _method_2011 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmulph >;
	addExtern<DAS_CALL_METHOD(_method_2011)>(*this,lib,"vmulph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmulph >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_2012 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmulsh >;
	addExtern<DAS_CALL_METHOD(_method_2012)>(*this,lib,"vmulsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmulsh >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_2013 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vp2intersectd >;
	addExtern<DAS_CALL_METHOD(_method_2013)>(*this,lib,"vp2intersectd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vp2intersectd >::invoke")
		->args({"self","k","x","op"});
	using _method_2014 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vp2intersectq >;
	addExtern<DAS_CALL_METHOD(_method_2014)>(*this,lib,"vp2intersectq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vp2intersectq >::invoke")
		->args({"self","k","x","op"});
	using _method_2015 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vp4dpwssd >;
	addExtern<DAS_CALL_METHOD(_method_2015)>(*this,lib,"vp4dpwssd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vp4dpwssd >::invoke")
		->args({"self","z1","z2","addr"});
	using _method_2016 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vp4dpwssds >;
	addExtern<DAS_CALL_METHOD(_method_2016)>(*this,lib,"vp4dpwssds",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Zmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vp4dpwssds >::invoke")
		->args({"self","z1","z2","addr"});
	using _method_2017 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpabsq >;
	addExtern<DAS_CALL_METHOD(_method_2017)>(*this,lib,"vpabsq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpabsq >::invoke")
		->args({"self","x","op"});
	using _method_2018 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpandd >;
	addExtern<DAS_CALL_METHOD(_method_2018)>(*this,lib,"vpandd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpandd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2019 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpandnd >;
	addExtern<DAS_CALL_METHOD(_method_2019)>(*this,lib,"vpandnd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpandnd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2020 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpandnq >;
	addExtern<DAS_CALL_METHOD(_method_2020)>(*this,lib,"vpandnq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpandnq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2021 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpandq >;
	addExtern<DAS_CALL_METHOD(_method_2021)>(*this,lib,"vpandq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpandq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2022 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpblendmb >;
	addExtern<DAS_CALL_METHOD(_method_2022)>(*this,lib,"vpblendmb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpblendmb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2023 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpblendmd >;
	addExtern<DAS_CALL_METHOD(_method_2023)>(*this,lib,"vpblendmd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpblendmd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2024 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpblendmq >;
	addExtern<DAS_CALL_METHOD(_method_2024)>(*this,lib,"vpblendmq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpblendmq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2025 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpblendmw >;
	addExtern<DAS_CALL_METHOD(_method_2025)>(*this,lib,"vpblendmw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpblendmw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2026 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::vpbroadcastb >;
	addExtern<DAS_CALL_METHOD(_method_2026)>(*this,lib,"vpbroadcastb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::vpbroadcastb >::invoke")
		->args({"self","x","r"});
	using _method_2027 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg32 &),&Xbyak::CodeGenerator::vpbroadcastd >;
	addExtern<DAS_CALL_METHOD(_method_2027)>(*this,lib,"vpbroadcastd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg32 &) , &Xbyak::CodeGenerator::vpbroadcastd >::invoke")
		->args({"self","x","r"});
	using _method_2028 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::vpbroadcastmb2q >;
	addExtern<DAS_CALL_METHOD(_method_2028)>(*this,lib,"vpbroadcastmb2q",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::vpbroadcastmb2q >::invoke")
		->args({"self","x","k"});
	using _method_2029 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::vpbroadcastmw2d >;
	addExtern<DAS_CALL_METHOD(_method_2029)>(*this,lib,"vpbroadcastmw2d",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::vpbroadcastmw2d >::invoke")
		->args({"self","x","k"});
	using _method_2030 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg16 &),&Xbyak::CodeGenerator::vpbroadcastw >;
	addExtern<DAS_CALL_METHOD(_method_2030)>(*this,lib,"vpbroadcastw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg16 &) , &Xbyak::CodeGenerator::vpbroadcastw >::invoke")
		->args({"self","x","r"});
	using _method_2031 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpb >;
	addExtern<DAS_CALL_METHOD(_method_2031)>(*this,lib,"vpcmpb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpb >::invoke")
		->args({"self","k","x","op","imm"});
	using _method_2032 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpd >;
	addExtern<DAS_CALL_METHOD(_method_2032)>(*this,lib,"vpcmpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpd >::invoke")
		->args({"self","k","x","op","imm"});
	using _method_2033 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpeqb >;
	addExtern<DAS_CALL_METHOD(_method_2033)>(*this,lib,"vpcmpeqb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpeqb >::invoke")
		->args({"self","k","x","op"});
	using _method_2034 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpeqd >;
	addExtern<DAS_CALL_METHOD(_method_2034)>(*this,lib,"vpcmpeqd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpeqd >::invoke")
		->args({"self","k","x","op"});
	using _method_2035 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpeqq >;
	addExtern<DAS_CALL_METHOD(_method_2035)>(*this,lib,"vpcmpeqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpeqq >::invoke")
		->args({"self","k","x","op"});
	using _method_2036 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpeqw >;
	addExtern<DAS_CALL_METHOD(_method_2036)>(*this,lib,"vpcmpeqw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpeqw >::invoke")
		->args({"self","k","x","op"});
	using _method_2037 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpgtb >;
	addExtern<DAS_CALL_METHOD(_method_2037)>(*this,lib,"vpcmpgtb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpgtb >::invoke")
		->args({"self","k","x","op"});
	using _method_2038 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpgtd >;
	addExtern<DAS_CALL_METHOD(_method_2038)>(*this,lib,"vpcmpgtd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpgtd >::invoke")
		->args({"self","k","x","op"});
	using _method_2039 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpgtq >;
	addExtern<DAS_CALL_METHOD(_method_2039)>(*this,lib,"vpcmpgtq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpgtq >::invoke")
		->args({"self","k","x","op"});
	using _method_2040 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpgtw >;
	addExtern<DAS_CALL_METHOD(_method_2040)>(*this,lib,"vpcmpgtw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpgtw >::invoke")
		->args({"self","k","x","op"});
	using _method_2041 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpq >;
	addExtern<DAS_CALL_METHOD(_method_2041)>(*this,lib,"vpcmpq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpq >::invoke")
		->args({"self","k","x","op","imm"});
	using _method_2042 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpub >;
	addExtern<DAS_CALL_METHOD(_method_2042)>(*this,lib,"vpcmpub",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpub >::invoke")
		->args({"self","k","x","op","imm"});
	using _method_2043 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpud >;
	addExtern<DAS_CALL_METHOD(_method_2043)>(*this,lib,"vpcmpud",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpud >::invoke")
		->args({"self","k","x","op","imm"});
	using _method_2044 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpuq >;
	addExtern<DAS_CALL_METHOD(_method_2044)>(*this,lib,"vpcmpuq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpuq >::invoke")
		->args({"self","k","x","op","imm"});
	using _method_2045 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpuw >;
	addExtern<DAS_CALL_METHOD(_method_2045)>(*this,lib,"vpcmpuw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpuw >::invoke")
		->args({"self","k","x","op","imm"});
	using _method_2046 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpw >;
	addExtern<DAS_CALL_METHOD(_method_2046)>(*this,lib,"vpcmpw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpw >::invoke")
		->args({"self","k","x","op","imm"});
	using _method_2047 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpcompressd >;
	addExtern<DAS_CALL_METHOD(_method_2047)>(*this,lib,"vpcompressd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpcompressd >::invoke")
		->args({"self","op","x"});
	using _method_2048 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpcompressq >;
	addExtern<DAS_CALL_METHOD(_method_2048)>(*this,lib,"vpcompressq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpcompressq >::invoke")
		->args({"self","op","x"});
	using _method_2049 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpconflictd >;
	addExtern<DAS_CALL_METHOD(_method_2049)>(*this,lib,"vpconflictd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpconflictd >::invoke")
		->args({"self","x","op"});
	using _method_2050 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpconflictq >;
	addExtern<DAS_CALL_METHOD(_method_2050)>(*this,lib,"vpconflictq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpconflictq >::invoke")
		->args({"self","x","op"});
	using _method_2051 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermb >;
	addExtern<DAS_CALL_METHOD(_method_2051)>(*this,lib,"vpermb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2052 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermi2b >;
	addExtern<DAS_CALL_METHOD(_method_2052)>(*this,lib,"vpermi2b",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermi2b >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2053 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermi2d >;
	addExtern<DAS_CALL_METHOD(_method_2053)>(*this,lib,"vpermi2d",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermi2d >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2054 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermi2pd >;
	addExtern<DAS_CALL_METHOD(_method_2054)>(*this,lib,"vpermi2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermi2pd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2055 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermi2ps >;
	addExtern<DAS_CALL_METHOD(_method_2055)>(*this,lib,"vpermi2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermi2ps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2056 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermi2q >;
	addExtern<DAS_CALL_METHOD(_method_2056)>(*this,lib,"vpermi2q",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermi2q >::invoke")
		->args({"self","x1","x2","op"});
}
}

