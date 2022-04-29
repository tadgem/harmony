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
void Module_dasXBYAK::initFunctions_23() {
	using _method_2157 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpxorq >;
	addExtern<DAS_CALL_METHOD(_method_2157)>(*this,lib,"vpxorq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpxorq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2158 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrangepd >;
	addExtern<DAS_CALL_METHOD(_method_2158)>(*this,lib,"vrangepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrangepd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2159 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrangeps >;
	addExtern<DAS_CALL_METHOD(_method_2159)>(*this,lib,"vrangeps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrangeps >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2160 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrangesd >;
	addExtern<DAS_CALL_METHOD(_method_2160)>(*this,lib,"vrangesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrangesd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2161 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrangess >;
	addExtern<DAS_CALL_METHOD(_method_2161)>(*this,lib,"vrangess",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrangess >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2162 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcp14pd >;
	addExtern<DAS_CALL_METHOD(_method_2162)>(*this,lib,"vrcp14pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcp14pd >::invoke")
		->args({"self","x","op"});
	using _method_2163 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcp14ps >;
	addExtern<DAS_CALL_METHOD(_method_2163)>(*this,lib,"vrcp14ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcp14ps >::invoke")
		->args({"self","x","op"});
	using _method_2164 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcp14sd >;
	addExtern<DAS_CALL_METHOD(_method_2164)>(*this,lib,"vrcp14sd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcp14sd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2165 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcp14ss >;
	addExtern<DAS_CALL_METHOD(_method_2165)>(*this,lib,"vrcp14ss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcp14ss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2166 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcp28pd >;
	addExtern<DAS_CALL_METHOD(_method_2166)>(*this,lib,"vrcp28pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcp28pd >::invoke")
		->args({"self","z","op"});
	using _method_2167 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcp28ps >;
	addExtern<DAS_CALL_METHOD(_method_2167)>(*this,lib,"vrcp28ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcp28ps >::invoke")
		->args({"self","z","op"});
	using _method_2168 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcp28sd >;
	addExtern<DAS_CALL_METHOD(_method_2168)>(*this,lib,"vrcp28sd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcp28sd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2169 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcp28ss >;
	addExtern<DAS_CALL_METHOD(_method_2169)>(*this,lib,"vrcp28ss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcp28ss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2170 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcpph >;
	addExtern<DAS_CALL_METHOD(_method_2170)>(*this,lib,"vrcpph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcpph >::invoke")
		->args({"self","x","op"});
	using _method_2171 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrcpsh >;
	addExtern<DAS_CALL_METHOD(_method_2171)>(*this,lib,"vrcpsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrcpsh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2172 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vreducepd >;
	addExtern<DAS_CALL_METHOD(_method_2172)>(*this,lib,"vreducepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vreducepd >::invoke")
		->args({"self","x","op","imm"});
	using _method_2173 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vreduceph >;
	addExtern<DAS_CALL_METHOD(_method_2173)>(*this,lib,"vreduceph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vreduceph >::invoke")
		->args({"self","x","op","imm"});
	using _method_2174 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vreduceps >;
	addExtern<DAS_CALL_METHOD(_method_2174)>(*this,lib,"vreduceps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vreduceps >::invoke")
		->args({"self","x","op","imm"});
	using _method_2175 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vreducesd >;
	addExtern<DAS_CALL_METHOD(_method_2175)>(*this,lib,"vreducesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vreducesd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2176 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vreducesh >;
	addExtern<DAS_CALL_METHOD(_method_2176)>(*this,lib,"vreducesh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vreducesh >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2177 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vreducess >;
	addExtern<DAS_CALL_METHOD(_method_2177)>(*this,lib,"vreducess",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vreducess >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2178 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrndscalepd >;
	addExtern<DAS_CALL_METHOD(_method_2178)>(*this,lib,"vrndscalepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrndscalepd >::invoke")
		->args({"self","x","op","imm"});
	using _method_2179 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrndscaleph >;
	addExtern<DAS_CALL_METHOD(_method_2179)>(*this,lib,"vrndscaleph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrndscaleph >::invoke")
		->args({"self","x","op","imm"});
	using _method_2180 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrndscaleps >;
	addExtern<DAS_CALL_METHOD(_method_2180)>(*this,lib,"vrndscaleps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrndscaleps >::invoke")
		->args({"self","x","op","imm"});
	using _method_2181 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrndscalesd >;
	addExtern<DAS_CALL_METHOD(_method_2181)>(*this,lib,"vrndscalesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrndscalesd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2182 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrndscalesh >;
	addExtern<DAS_CALL_METHOD(_method_2182)>(*this,lib,"vrndscalesh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrndscalesh >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2183 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vrndscaless >;
	addExtern<DAS_CALL_METHOD(_method_2183)>(*this,lib,"vrndscaless",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vrndscaless >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_2184 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrt14pd >;
	addExtern<DAS_CALL_METHOD(_method_2184)>(*this,lib,"vrsqrt14pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrt14pd >::invoke")
		->args({"self","x","op"});
	using _method_2185 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrt14ps >;
	addExtern<DAS_CALL_METHOD(_method_2185)>(*this,lib,"vrsqrt14ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrt14ps >::invoke")
		->args({"self","x","op"});
	using _method_2186 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrt14sd >;
	addExtern<DAS_CALL_METHOD(_method_2186)>(*this,lib,"vrsqrt14sd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrt14sd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2187 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrt14ss >;
	addExtern<DAS_CALL_METHOD(_method_2187)>(*this,lib,"vrsqrt14ss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrt14ss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2188 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrt28pd >;
	addExtern<DAS_CALL_METHOD(_method_2188)>(*this,lib,"vrsqrt28pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrt28pd >::invoke")
		->args({"self","z","op"});
	using _method_2189 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrt28ps >;
	addExtern<DAS_CALL_METHOD(_method_2189)>(*this,lib,"vrsqrt28ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrt28ps >::invoke")
		->args({"self","z","op"});
	using _method_2190 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrt28sd >;
	addExtern<DAS_CALL_METHOD(_method_2190)>(*this,lib,"vrsqrt28sd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrt28sd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2191 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrt28ss >;
	addExtern<DAS_CALL_METHOD(_method_2191)>(*this,lib,"vrsqrt28ss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrt28ss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2192 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrtph >;
	addExtern<DAS_CALL_METHOD(_method_2192)>(*this,lib,"vrsqrtph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrtph >::invoke")
		->args({"self","x","op"});
	using _method_2193 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vrsqrtsh >;
	addExtern<DAS_CALL_METHOD(_method_2193)>(*this,lib,"vrsqrtsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vrsqrtsh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2194 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vscalefpd >;
	addExtern<DAS_CALL_METHOD(_method_2194)>(*this,lib,"vscalefpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vscalefpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2195 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vscalefph >;
	addExtern<DAS_CALL_METHOD(_method_2195)>(*this,lib,"vscalefph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vscalefph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2196 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vscalefps >;
	addExtern<DAS_CALL_METHOD(_method_2196)>(*this,lib,"vscalefps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vscalefps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2197 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vscalefsd >;
	addExtern<DAS_CALL_METHOD(_method_2197)>(*this,lib,"vscalefsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vscalefsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2198 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vscalefsh >;
	addExtern<DAS_CALL_METHOD(_method_2198)>(*this,lib,"vscalefsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vscalefsh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2199 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vscalefss >;
	addExtern<DAS_CALL_METHOD(_method_2199)>(*this,lib,"vscalefss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vscalefss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2200 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vscatterdpd >;
	addExtern<DAS_CALL_METHOD(_method_2200)>(*this,lib,"vscatterdpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vscatterdpd >::invoke")
		->args({"self","addr","x"});
	using _method_2201 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vscatterdps >;
	addExtern<DAS_CALL_METHOD(_method_2201)>(*this,lib,"vscatterdps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vscatterdps >::invoke")
		->args({"self","addr","x"});
	using _method_2202 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vscatterpf0dpd >;
	addExtern<DAS_CALL_METHOD(_method_2202)>(*this,lib,"vscatterpf0dpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vscatterpf0dpd >::invoke")
		->args({"self","addr"});
	using _method_2203 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vscatterpf0dps >;
	addExtern<DAS_CALL_METHOD(_method_2203)>(*this,lib,"vscatterpf0dps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vscatterpf0dps >::invoke")
		->args({"self","addr"});
	using _method_2204 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vscatterpf0qpd >;
	addExtern<DAS_CALL_METHOD(_method_2204)>(*this,lib,"vscatterpf0qpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vscatterpf0qpd >::invoke")
		->args({"self","addr"});
	using _method_2205 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vscatterpf0qps >;
	addExtern<DAS_CALL_METHOD(_method_2205)>(*this,lib,"vscatterpf0qps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vscatterpf0qps >::invoke")
		->args({"self","addr"});
	using _method_2206 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vscatterpf1dpd >;
	addExtern<DAS_CALL_METHOD(_method_2206)>(*this,lib,"vscatterpf1dpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vscatterpf1dpd >::invoke")
		->args({"self","addr"});
	using _method_2207 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vscatterpf1dps >;
	addExtern<DAS_CALL_METHOD(_method_2207)>(*this,lib,"vscatterpf1dps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vscatterpf1dps >::invoke")
		->args({"self","addr"});
	using _method_2208 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vscatterpf1qpd >;
	addExtern<DAS_CALL_METHOD(_method_2208)>(*this,lib,"vscatterpf1qpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vscatterpf1qpd >::invoke")
		->args({"self","addr"});
	using _method_2209 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::vscatterpf1qps >;
	addExtern<DAS_CALL_METHOD(_method_2209)>(*this,lib,"vscatterpf1qps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::vscatterpf1qps >::invoke")
		->args({"self","addr"});
	using _method_2210 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vscatterqpd >;
	addExtern<DAS_CALL_METHOD(_method_2210)>(*this,lib,"vscatterqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vscatterqpd >::invoke")
		->args({"self","addr","x"});
	using _method_2211 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vscatterqps >;
	addExtern<DAS_CALL_METHOD(_method_2211)>(*this,lib,"vscatterqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vscatterqps >::invoke")
		->args({"self","addr","x"});
	using _method_2212 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vshuff32x4 >;
	addExtern<DAS_CALL_METHOD(_method_2212)>(*this,lib,"vshuff32x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vshuff32x4 >::invoke")
		->args({"self","y1","y2","op","imm"});
	using _method_2213 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vshuff64x2 >;
	addExtern<DAS_CALL_METHOD(_method_2213)>(*this,lib,"vshuff64x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vshuff64x2 >::invoke")
		->args({"self","y1","y2","op","imm"});
	using _method_2214 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vshufi32x4 >;
	addExtern<DAS_CALL_METHOD(_method_2214)>(*this,lib,"vshufi32x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vshufi32x4 >::invoke")
		->args({"self","y1","y2","op","imm"});
	using _method_2215 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vshufi64x2 >;
	addExtern<DAS_CALL_METHOD(_method_2215)>(*this,lib,"vshufi64x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vshufi64x2 >::invoke")
		->args({"self","y1","y2","op","imm"});
	using _method_2216 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsqrtph >;
	addExtern<DAS_CALL_METHOD(_method_2216)>(*this,lib,"vsqrtph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsqrtph >::invoke")
		->args({"self","x","op"});
	using _method_2217 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsqrtsh >;
	addExtern<DAS_CALL_METHOD(_method_2217)>(*this,lib,"vsqrtsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsqrtsh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_2218 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsubph >;
	addExtern<DAS_CALL_METHOD(_method_2218)>(*this,lib,"vsubph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsubph >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_2219 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vsubsh >;
	addExtern<DAS_CALL_METHOD(_method_2219)>(*this,lib,"vsubsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vsubsh >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_2220 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vucomish >;
	addExtern<DAS_CALL_METHOD(_method_2220)>(*this,lib,"vucomish",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vucomish >::invoke")
		->args({"self","x","op"});
	using _method_2221 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Reg64 &),&Xbyak::CodeGenerator::kmovq >;
	addExtern<DAS_CALL_METHOD(_method_2221)>(*this,lib,"kmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Reg64 &) , &Xbyak::CodeGenerator::kmovq >::invoke")
		->args({"self","k","r"});
	using _method_2222 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Opmask &),&Xbyak::CodeGenerator::kmovq >;
	addExtern<DAS_CALL_METHOD(_method_2222)>(*this,lib,"kmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg64 &,const Xbyak::Opmask &) , &Xbyak::CodeGenerator::kmovq >::invoke")
		->args({"self","r","k"});
	using _method_2223 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg64 &),&Xbyak::CodeGenerator::vpbroadcastq >;
	addExtern<DAS_CALL_METHOD(_method_2223)>(*this,lib,"vpbroadcastq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Reg64 &) , &Xbyak::CodeGenerator::vpbroadcastq >::invoke")
		->args({"self","x","r"});
	using _method_2224 = das::das_call_member< void (Xbyak::CodeGenerator::*)(size_t,bool),&Xbyak::CodeGenerator::align >;
	addExtern<DAS_CALL_METHOD(_method_2224)>(*this,lib,"align",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(size_t,bool) , &Xbyak::CodeGenerator::align >::invoke")
		->args({"self","x","useMultiByteNop"})
		->arg_init(1,make_smart<ExprConstUInt64>(0x10))
		->arg_init(2,make_smart<ExprConstBool>(true));
}
}

