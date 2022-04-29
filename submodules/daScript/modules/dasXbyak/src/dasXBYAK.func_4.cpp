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
void Module_dasXBYAK::initFunctions_4() {
	using _method_257 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &),&Xbyak::CodeGenerator::bextr >;
	addExtern<DAS_CALL_METHOD(_method_257)>(*this,lib,"bextr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &) , &Xbyak::CodeGenerator::bextr >::invoke")
		->args({"self","r1","op","r2"});
	using _method_258 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int),&Xbyak::CodeGenerator::blendpd >;
	addExtern<DAS_CALL_METHOD(_method_258)>(*this,lib,"blendpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::blendpd >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_259 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int),&Xbyak::CodeGenerator::blendps >;
	addExtern<DAS_CALL_METHOD(_method_259)>(*this,lib,"blendps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::blendps >::invoke")
		->args({"self","xmm","op","imm"});
	using _method_260 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::blendvpd >;
	addExtern<DAS_CALL_METHOD(_method_260)>(*this,lib,"blendvpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::blendvpd >::invoke")
		->args({"self","xmm","op"});
	using _method_261 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::blendvps >;
	addExtern<DAS_CALL_METHOD(_method_261)>(*this,lib,"blendvps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::blendvps >::invoke")
		->args({"self","xmm","op"});
	using _method_262 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::blsi >;
	addExtern<DAS_CALL_METHOD(_method_262)>(*this,lib,"blsi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::blsi >::invoke")
		->args({"self","r","op"});
	using _method_263 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::blsmsk >;
	addExtern<DAS_CALL_METHOD(_method_263)>(*this,lib,"blsmsk",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::blsmsk >::invoke")
		->args({"self","r","op"});
	using _method_264 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::blsr >;
	addExtern<DAS_CALL_METHOD(_method_264)>(*this,lib,"blsr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::blsr >::invoke")
		->args({"self","r","op"});
	using _method_265 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::bnd >;
	addExtern<DAS_CALL_METHOD(_method_265)>(*this,lib,"bnd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::bnd >::invoke")
		->args({"self"});
	using _method_266 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::bndcl >;
	addExtern<DAS_CALL_METHOD(_method_266)>(*this,lib,"bndcl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::bndcl >::invoke")
		->args({"self","bnd","op"});
	using _method_267 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::bndcn >;
	addExtern<DAS_CALL_METHOD(_method_267)>(*this,lib,"bndcn",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::bndcn >::invoke")
		->args({"self","bnd","op"});
	using _method_268 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::bndcu >;
	addExtern<DAS_CALL_METHOD(_method_268)>(*this,lib,"bndcu",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::bndcu >::invoke")
		->args({"self","bnd","op"});
	using _method_269 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Address &),&Xbyak::CodeGenerator::bndldx >;
	addExtern<DAS_CALL_METHOD(_method_269)>(*this,lib,"bndldx",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Address &) , &Xbyak::CodeGenerator::bndldx >::invoke")
		->args({"self","bnd","addr"});
	using _method_270 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Address &),&Xbyak::CodeGenerator::bndmk >;
	addExtern<DAS_CALL_METHOD(_method_270)>(*this,lib,"bndmk",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Address &) , &Xbyak::CodeGenerator::bndmk >::invoke")
		->args({"self","bnd","addr"});
	using _method_271 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::BoundsReg &),&Xbyak::CodeGenerator::bndmov >;
	addExtern<DAS_CALL_METHOD(_method_271)>(*this,lib,"bndmov",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::BoundsReg &) , &Xbyak::CodeGenerator::bndmov >::invoke")
		->args({"self","addr","bnd"});
	using _method_272 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::bndmov >;
	addExtern<DAS_CALL_METHOD(_method_272)>(*this,lib,"bndmov",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::BoundsReg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::bndmov >::invoke")
		->args({"self","bnd","op"});
	using _method_273 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::BoundsReg &),&Xbyak::CodeGenerator::bndstx >;
	addExtern<DAS_CALL_METHOD(_method_273)>(*this,lib,"bndstx",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::BoundsReg &) , &Xbyak::CodeGenerator::bndstx >::invoke")
		->args({"self","addr","bnd"});
	using _method_274 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::bsf >;
	addExtern<DAS_CALL_METHOD(_method_274)>(*this,lib,"bsf",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::bsf >::invoke")
		->args({"self","reg","op"});
	using _method_275 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::bsr >;
	addExtern<DAS_CALL_METHOD(_method_275)>(*this,lib,"bsr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::bsr >::invoke")
		->args({"self","reg","op"});
	using _method_276 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &),&Xbyak::CodeGenerator::bswap >;
	addExtern<DAS_CALL_METHOD(_method_276)>(*this,lib,"bswap",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &) , &Xbyak::CodeGenerator::bswap >::invoke")
		->args({"self","reg"});
	using _method_277 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &),&Xbyak::CodeGenerator::bt >;
	addExtern<DAS_CALL_METHOD(_method_277)>(*this,lib,"bt",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &) , &Xbyak::CodeGenerator::bt >::invoke")
		->args({"self","op","reg"});
	using _method_278 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::bt >;
	addExtern<DAS_CALL_METHOD(_method_278)>(*this,lib,"bt",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::bt >::invoke")
		->args({"self","op","imm"});
	using _method_279 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &),&Xbyak::CodeGenerator::btc >;
	addExtern<DAS_CALL_METHOD(_method_279)>(*this,lib,"btc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &) , &Xbyak::CodeGenerator::btc >::invoke")
		->args({"self","op","reg"});
	using _method_280 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::btc >;
	addExtern<DAS_CALL_METHOD(_method_280)>(*this,lib,"btc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::btc >::invoke")
		->args({"self","op","imm"});
	using _method_281 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &),&Xbyak::CodeGenerator::btr >;
	addExtern<DAS_CALL_METHOD(_method_281)>(*this,lib,"btr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &) , &Xbyak::CodeGenerator::btr >::invoke")
		->args({"self","op","reg"});
	using _method_282 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::btr >;
	addExtern<DAS_CALL_METHOD(_method_282)>(*this,lib,"btr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::btr >::invoke")
		->args({"self","op","imm"});
	using _method_283 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &),&Xbyak::CodeGenerator::bts >;
	addExtern<DAS_CALL_METHOD(_method_283)>(*this,lib,"bts",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg &) , &Xbyak::CodeGenerator::bts >::invoke")
		->args({"self","op","reg"});
	using _method_284 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::bts >;
	addExtern<DAS_CALL_METHOD(_method_284)>(*this,lib,"bts",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::bts >::invoke")
		->args({"self","op","imm"});
	using _method_285 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &),&Xbyak::CodeGenerator::bzhi >;
	addExtern<DAS_CALL_METHOD(_method_285)>(*this,lib,"bzhi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,const Xbyak::Reg32e &) , &Xbyak::CodeGenerator::bzhi >::invoke")
		->args({"self","r1","op","r2"});
	using _method_286 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cbw >;
	addExtern<DAS_CALL_METHOD(_method_286)>(*this,lib,"cbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cbw >::invoke")
		->args({"self"});
	using _method_287 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cdq >;
	addExtern<DAS_CALL_METHOD(_method_287)>(*this,lib,"cdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cdq >::invoke")
		->args({"self"});
	using _method_288 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::clc >;
	addExtern<DAS_CALL_METHOD(_method_288)>(*this,lib,"clc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::clc >::invoke")
		->args({"self"});
	using _method_289 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cld >;
	addExtern<DAS_CALL_METHOD(_method_289)>(*this,lib,"cld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cld >::invoke")
		->args({"self"});
	using _method_290 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::clflush >;
	addExtern<DAS_CALL_METHOD(_method_290)>(*this,lib,"clflush",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::clflush >::invoke")
		->args({"self","addr"});
	using _method_291 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::clflushopt >;
	addExtern<DAS_CALL_METHOD(_method_291)>(*this,lib,"clflushopt",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::clflushopt >::invoke")
		->args({"self","addr"});
	using _method_292 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cli >;
	addExtern<DAS_CALL_METHOD(_method_292)>(*this,lib,"cli",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cli >::invoke")
		->args({"self"});
	using _method_293 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::clzero >;
	addExtern<DAS_CALL_METHOD(_method_293)>(*this,lib,"clzero",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::clzero >::invoke")
		->args({"self"});
	using _method_294 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::cmc >;
	addExtern<DAS_CALL_METHOD(_method_294)>(*this,lib,"cmc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::cmc >::invoke")
		->args({"self"});
	using _method_295 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmova >;
	addExtern<DAS_CALL_METHOD(_method_295)>(*this,lib,"cmova",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmova >::invoke")
		->args({"self","reg","op"});
	using _method_296 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovae >;
	addExtern<DAS_CALL_METHOD(_method_296)>(*this,lib,"cmovae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovae >::invoke")
		->args({"self","reg","op"});
	using _method_297 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovb >;
	addExtern<DAS_CALL_METHOD(_method_297)>(*this,lib,"cmovb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovb >::invoke")
		->args({"self","reg","op"});
	using _method_298 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovbe >;
	addExtern<DAS_CALL_METHOD(_method_298)>(*this,lib,"cmovbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovbe >::invoke")
		->args({"self","reg","op"});
	using _method_299 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovc >;
	addExtern<DAS_CALL_METHOD(_method_299)>(*this,lib,"cmovc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovc >::invoke")
		->args({"self","reg","op"});
	using _method_300 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmove >;
	addExtern<DAS_CALL_METHOD(_method_300)>(*this,lib,"cmove",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmove >::invoke")
		->args({"self","reg","op"});
	using _method_301 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovg >;
	addExtern<DAS_CALL_METHOD(_method_301)>(*this,lib,"cmovg",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovg >::invoke")
		->args({"self","reg","op"});
	using _method_302 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovge >;
	addExtern<DAS_CALL_METHOD(_method_302)>(*this,lib,"cmovge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovge >::invoke")
		->args({"self","reg","op"});
	using _method_303 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovl >;
	addExtern<DAS_CALL_METHOD(_method_303)>(*this,lib,"cmovl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovl >::invoke")
		->args({"self","reg","op"});
	using _method_304 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovle >;
	addExtern<DAS_CALL_METHOD(_method_304)>(*this,lib,"cmovle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovle >::invoke")
		->args({"self","reg","op"});
	using _method_305 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovna >;
	addExtern<DAS_CALL_METHOD(_method_305)>(*this,lib,"cmovna",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovna >::invoke")
		->args({"self","reg","op"});
	using _method_306 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnae >;
	addExtern<DAS_CALL_METHOD(_method_306)>(*this,lib,"cmovnae",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnae >::invoke")
		->args({"self","reg","op"});
	using _method_307 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnb >;
	addExtern<DAS_CALL_METHOD(_method_307)>(*this,lib,"cmovnb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnb >::invoke")
		->args({"self","reg","op"});
	using _method_308 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnbe >;
	addExtern<DAS_CALL_METHOD(_method_308)>(*this,lib,"cmovnbe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnbe >::invoke")
		->args({"self","reg","op"});
	using _method_309 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnc >;
	addExtern<DAS_CALL_METHOD(_method_309)>(*this,lib,"cmovnc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnc >::invoke")
		->args({"self","reg","op"});
	using _method_310 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovne >;
	addExtern<DAS_CALL_METHOD(_method_310)>(*this,lib,"cmovne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovne >::invoke")
		->args({"self","reg","op"});
	using _method_311 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovng >;
	addExtern<DAS_CALL_METHOD(_method_311)>(*this,lib,"cmovng",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovng >::invoke")
		->args({"self","reg","op"});
	using _method_312 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnge >;
	addExtern<DAS_CALL_METHOD(_method_312)>(*this,lib,"cmovnge",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnge >::invoke")
		->args({"self","reg","op"});
	using _method_313 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnl >;
	addExtern<DAS_CALL_METHOD(_method_313)>(*this,lib,"cmovnl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnl >::invoke")
		->args({"self","reg","op"});
	using _method_314 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnle >;
	addExtern<DAS_CALL_METHOD(_method_314)>(*this,lib,"cmovnle",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnle >::invoke")
		->args({"self","reg","op"});
	using _method_315 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovno >;
	addExtern<DAS_CALL_METHOD(_method_315)>(*this,lib,"cmovno",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovno >::invoke")
		->args({"self","reg","op"});
	using _method_316 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnp >;
	addExtern<DAS_CALL_METHOD(_method_316)>(*this,lib,"cmovnp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnp >::invoke")
		->args({"self","reg","op"});
	using _method_317 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovns >;
	addExtern<DAS_CALL_METHOD(_method_317)>(*this,lib,"cmovns",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovns >::invoke")
		->args({"self","reg","op"});
	using _method_318 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovnz >;
	addExtern<DAS_CALL_METHOD(_method_318)>(*this,lib,"cmovnz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovnz >::invoke")
		->args({"self","reg","op"});
	using _method_319 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovo >;
	addExtern<DAS_CALL_METHOD(_method_319)>(*this,lib,"cmovo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovo >::invoke")
		->args({"self","reg","op"});
	using _method_320 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovp >;
	addExtern<DAS_CALL_METHOD(_method_320)>(*this,lib,"cmovp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovp >::invoke")
		->args({"self","reg","op"});
	using _method_321 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovpe >;
	addExtern<DAS_CALL_METHOD(_method_321)>(*this,lib,"cmovpe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovpe >::invoke")
		->args({"self","reg","op"});
	using _method_322 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovpo >;
	addExtern<DAS_CALL_METHOD(_method_322)>(*this,lib,"cmovpo",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovpo >::invoke")
		->args({"self","reg","op"});
	using _method_323 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovs >;
	addExtern<DAS_CALL_METHOD(_method_323)>(*this,lib,"cmovs",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovs >::invoke")
		->args({"self","reg","op"});
	using _method_324 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmovz >;
	addExtern<DAS_CALL_METHOD(_method_324)>(*this,lib,"cmovz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmovz >::invoke")
		->args({"self","reg","op"});
	using _method_325 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned int),&Xbyak::CodeGenerator::cmp >;
	addExtern<DAS_CALL_METHOD(_method_325)>(*this,lib,"cmp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,unsigned int) , &Xbyak::CodeGenerator::cmp >::invoke")
		->args({"self","op","imm"});
	using _method_326 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmp >;
	addExtern<DAS_CALL_METHOD(_method_326)>(*this,lib,"cmp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmp >::invoke")
		->args({"self","op1","op2"});
	using _method_327 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpeqpd >;
	addExtern<DAS_CALL_METHOD(_method_327)>(*this,lib,"cmpeqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpeqpd >::invoke")
		->args({"self","x","op"});
	using _method_328 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpeqps >;
	addExtern<DAS_CALL_METHOD(_method_328)>(*this,lib,"cmpeqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpeqps >::invoke")
		->args({"self","x","op"});
	using _method_329 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpeqsd >;
	addExtern<DAS_CALL_METHOD(_method_329)>(*this,lib,"cmpeqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpeqsd >::invoke")
		->args({"self","x","op"});
	using _method_330 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpeqss >;
	addExtern<DAS_CALL_METHOD(_method_330)>(*this,lib,"cmpeqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpeqss >::invoke")
		->args({"self","x","op"});
	using _method_331 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmplepd >;
	addExtern<DAS_CALL_METHOD(_method_331)>(*this,lib,"cmplepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmplepd >::invoke")
		->args({"self","x","op"});
	using _method_332 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpleps >;
	addExtern<DAS_CALL_METHOD(_method_332)>(*this,lib,"cmpleps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpleps >::invoke")
		->args({"self","x","op"});
	using _method_333 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmplesd >;
	addExtern<DAS_CALL_METHOD(_method_333)>(*this,lib,"cmplesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmplesd >::invoke")
		->args({"self","x","op"});
	using _method_334 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpless >;
	addExtern<DAS_CALL_METHOD(_method_334)>(*this,lib,"cmpless",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpless >::invoke")
		->args({"self","x","op"});
	using _method_335 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpltpd >;
	addExtern<DAS_CALL_METHOD(_method_335)>(*this,lib,"cmpltpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpltpd >::invoke")
		->args({"self","x","op"});
	using _method_336 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpltps >;
	addExtern<DAS_CALL_METHOD(_method_336)>(*this,lib,"cmpltps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpltps >::invoke")
		->args({"self","x","op"});
	using _method_337 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpltsd >;
	addExtern<DAS_CALL_METHOD(_method_337)>(*this,lib,"cmpltsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpltsd >::invoke")
		->args({"self","x","op"});
	using _method_338 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpltss >;
	addExtern<DAS_CALL_METHOD(_method_338)>(*this,lib,"cmpltss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpltss >::invoke")
		->args({"self","x","op"});
	using _method_339 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpneqpd >;
	addExtern<DAS_CALL_METHOD(_method_339)>(*this,lib,"cmpneqpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpneqpd >::invoke")
		->args({"self","x","op"});
	using _method_340 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpneqps >;
	addExtern<DAS_CALL_METHOD(_method_340)>(*this,lib,"cmpneqps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpneqps >::invoke")
		->args({"self","x","op"});
	using _method_341 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpneqsd >;
	addExtern<DAS_CALL_METHOD(_method_341)>(*this,lib,"cmpneqsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpneqsd >::invoke")
		->args({"self","x","op"});
	using _method_342 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpneqss >;
	addExtern<DAS_CALL_METHOD(_method_342)>(*this,lib,"cmpneqss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpneqss >::invoke")
		->args({"self","x","op"});
	using _method_343 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpnlepd >;
	addExtern<DAS_CALL_METHOD(_method_343)>(*this,lib,"cmpnlepd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpnlepd >::invoke")
		->args({"self","x","op"});
	using _method_344 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpnleps >;
	addExtern<DAS_CALL_METHOD(_method_344)>(*this,lib,"cmpnleps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpnleps >::invoke")
		->args({"self","x","op"});
	using _method_345 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpnlesd >;
	addExtern<DAS_CALL_METHOD(_method_345)>(*this,lib,"cmpnlesd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpnlesd >::invoke")
		->args({"self","x","op"});
	using _method_346 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpnless >;
	addExtern<DAS_CALL_METHOD(_method_346)>(*this,lib,"cmpnless",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpnless >::invoke")
		->args({"self","x","op"});
	using _method_347 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpnltpd >;
	addExtern<DAS_CALL_METHOD(_method_347)>(*this,lib,"cmpnltpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpnltpd >::invoke")
		->args({"self","x","op"});
	using _method_348 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpnltps >;
	addExtern<DAS_CALL_METHOD(_method_348)>(*this,lib,"cmpnltps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpnltps >::invoke")
		->args({"self","x","op"});
	using _method_349 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpnltsd >;
	addExtern<DAS_CALL_METHOD(_method_349)>(*this,lib,"cmpnltsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpnltsd >::invoke")
		->args({"self","x","op"});
	using _method_350 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpnltss >;
	addExtern<DAS_CALL_METHOD(_method_350)>(*this,lib,"cmpnltss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpnltss >::invoke")
		->args({"self","x","op"});
	using _method_351 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpordpd >;
	addExtern<DAS_CALL_METHOD(_method_351)>(*this,lib,"cmpordpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpordpd >::invoke")
		->args({"self","x","op"});
	using _method_352 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpordps >;
	addExtern<DAS_CALL_METHOD(_method_352)>(*this,lib,"cmpordps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpordps >::invoke")
		->args({"self","x","op"});
	using _method_353 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpordsd >;
	addExtern<DAS_CALL_METHOD(_method_353)>(*this,lib,"cmpordsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpordsd >::invoke")
		->args({"self","x","op"});
	using _method_354 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::cmpordss >;
	addExtern<DAS_CALL_METHOD(_method_354)>(*this,lib,"cmpordss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::cmpordss >::invoke")
		->args({"self","x","op"});
	using _method_355 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::cmppd >;
	addExtern<DAS_CALL_METHOD(_method_355)>(*this,lib,"cmppd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::cmppd >::invoke")
		->args({"self","xmm","op","imm8"});
	using _method_356 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::cmpps >;
	addExtern<DAS_CALL_METHOD(_method_356)>(*this,lib,"cmpps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::cmpps >::invoke")
		->args({"self","xmm","op","imm8"});
}
}

