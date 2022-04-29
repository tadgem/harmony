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
void Module_dasXBYAK::initFunctions_15() {
	using _method_1357 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vmovsd >;
	addExtern<DAS_CALL_METHOD(_method_1357)>(*this,lib,"vmovsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vmovsd >::invoke")
		->args({"self","x","addr"});
	using _method_1358 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovsd >;
	addExtern<DAS_CALL_METHOD(_method_1358)>(*this,lib,"vmovsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovsd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1359 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovshdup >;
	addExtern<DAS_CALL_METHOD(_method_1359)>(*this,lib,"vmovshdup",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovshdup >::invoke")
		->args({"self","xm","op"});
	using _method_1360 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovsldup >;
	addExtern<DAS_CALL_METHOD(_method_1360)>(*this,lib,"vmovsldup",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovsldup >::invoke")
		->args({"self","xm","op"});
	using _method_1361 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovss >;
	addExtern<DAS_CALL_METHOD(_method_1361)>(*this,lib,"vmovss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovss >::invoke")
		->args({"self","addr","x"});
	using _method_1362 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vmovss >;
	addExtern<DAS_CALL_METHOD(_method_1362)>(*this,lib,"vmovss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vmovss >::invoke")
		->args({"self","x","addr"});
	using _method_1363 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovss >;
	addExtern<DAS_CALL_METHOD(_method_1363)>(*this,lib,"vmovss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1364 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovupd >;
	addExtern<DAS_CALL_METHOD(_method_1364)>(*this,lib,"vmovupd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovupd >::invoke")
		->args({"self","addr","xmm"});
	using _method_1365 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovupd >;
	addExtern<DAS_CALL_METHOD(_method_1365)>(*this,lib,"vmovupd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovupd >::invoke")
		->args({"self","xm","op"});
	using _method_1366 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vmovups >;
	addExtern<DAS_CALL_METHOD(_method_1366)>(*this,lib,"vmovups",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vmovups >::invoke")
		->args({"self","addr","xmm"});
	using _method_1367 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmovups >;
	addExtern<DAS_CALL_METHOD(_method_1367)>(*this,lib,"vmovups",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmovups >::invoke")
		->args({"self","xm","op"});
	using _method_1368 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vmpsadbw >;
	addExtern<DAS_CALL_METHOD(_method_1368)>(*this,lib,"vmpsadbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vmpsadbw >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1369 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmulpd >;
	addExtern<DAS_CALL_METHOD(_method_1369)>(*this,lib,"vmulpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmulpd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1370 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmulps >;
	addExtern<DAS_CALL_METHOD(_method_1370)>(*this,lib,"vmulps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmulps >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1371 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmulsd >;
	addExtern<DAS_CALL_METHOD(_method_1371)>(*this,lib,"vmulsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmulsd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1372 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vmulss >;
	addExtern<DAS_CALL_METHOD(_method_1372)>(*this,lib,"vmulss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vmulss >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1373 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vorpd >;
	addExtern<DAS_CALL_METHOD(_method_1373)>(*this,lib,"vorpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vorpd >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1374 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vorps >;
	addExtern<DAS_CALL_METHOD(_method_1374)>(*this,lib,"vorps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vorps >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1375 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpabsb >;
	addExtern<DAS_CALL_METHOD(_method_1375)>(*this,lib,"vpabsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpabsb >::invoke")
		->args({"self","xm","op"});
	using _method_1376 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpabsd >;
	addExtern<DAS_CALL_METHOD(_method_1376)>(*this,lib,"vpabsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpabsd >::invoke")
		->args({"self","xm","op"});
	using _method_1377 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpabsw >;
	addExtern<DAS_CALL_METHOD(_method_1377)>(*this,lib,"vpabsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpabsw >::invoke")
		->args({"self","xm","op"});
	using _method_1378 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpackssdw >;
	addExtern<DAS_CALL_METHOD(_method_1378)>(*this,lib,"vpackssdw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpackssdw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1379 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpacksswb >;
	addExtern<DAS_CALL_METHOD(_method_1379)>(*this,lib,"vpacksswb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpacksswb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1380 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpackusdw >;
	addExtern<DAS_CALL_METHOD(_method_1380)>(*this,lib,"vpackusdw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpackusdw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1381 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpackuswb >;
	addExtern<DAS_CALL_METHOD(_method_1381)>(*this,lib,"vpackuswb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpackuswb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1382 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpaddb >;
	addExtern<DAS_CALL_METHOD(_method_1382)>(*this,lib,"vpaddb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpaddb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1383 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpaddd >;
	addExtern<DAS_CALL_METHOD(_method_1383)>(*this,lib,"vpaddd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpaddd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1384 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpaddq >;
	addExtern<DAS_CALL_METHOD(_method_1384)>(*this,lib,"vpaddq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpaddq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1385 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpaddsb >;
	addExtern<DAS_CALL_METHOD(_method_1385)>(*this,lib,"vpaddsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpaddsb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1386 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpaddsw >;
	addExtern<DAS_CALL_METHOD(_method_1386)>(*this,lib,"vpaddsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpaddsw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1387 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpaddusb >;
	addExtern<DAS_CALL_METHOD(_method_1387)>(*this,lib,"vpaddusb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpaddusb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1388 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpaddusw >;
	addExtern<DAS_CALL_METHOD(_method_1388)>(*this,lib,"vpaddusw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpaddusw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1389 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpaddw >;
	addExtern<DAS_CALL_METHOD(_method_1389)>(*this,lib,"vpaddw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpaddw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1390 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpalignr >;
	addExtern<DAS_CALL_METHOD(_method_1390)>(*this,lib,"vpalignr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpalignr >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1391 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpand >;
	addExtern<DAS_CALL_METHOD(_method_1391)>(*this,lib,"vpand",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpand >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1392 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpandn >;
	addExtern<DAS_CALL_METHOD(_method_1392)>(*this,lib,"vpandn",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpandn >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1393 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpavgb >;
	addExtern<DAS_CALL_METHOD(_method_1393)>(*this,lib,"vpavgb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpavgb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1394 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpavgw >;
	addExtern<DAS_CALL_METHOD(_method_1394)>(*this,lib,"vpavgw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpavgw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1395 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpblendd >;
	addExtern<DAS_CALL_METHOD(_method_1395)>(*this,lib,"vpblendd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpblendd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1396 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpblendvb >;
	addExtern<DAS_CALL_METHOD(_method_1396)>(*this,lib,"vpblendvb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpblendvb >::invoke")
		->args({"self","x1","x2","op","x4"});
	using _method_1397 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpblendw >;
	addExtern<DAS_CALL_METHOD(_method_1397)>(*this,lib,"vpblendw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpblendw >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1398 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpbroadcastb >;
	addExtern<DAS_CALL_METHOD(_method_1398)>(*this,lib,"vpbroadcastb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpbroadcastb >::invoke")
		->args({"self","x","op"});
	using _method_1399 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpbroadcastd >;
	addExtern<DAS_CALL_METHOD(_method_1399)>(*this,lib,"vpbroadcastd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpbroadcastd >::invoke")
		->args({"self","x","op"});
	using _method_1400 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpbroadcastq >;
	addExtern<DAS_CALL_METHOD(_method_1400)>(*this,lib,"vpbroadcastq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpbroadcastq >::invoke")
		->args({"self","x","op"});
	using _method_1401 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpbroadcastw >;
	addExtern<DAS_CALL_METHOD(_method_1401)>(*this,lib,"vpbroadcastw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpbroadcastw >::invoke")
		->args({"self","x","op"});
	using _method_1402 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpclmulqdq >;
	addExtern<DAS_CALL_METHOD(_method_1402)>(*this,lib,"vpclmulqdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpclmulqdq >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1403 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpeqb >;
	addExtern<DAS_CALL_METHOD(_method_1403)>(*this,lib,"vpcmpeqb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpeqb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1404 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpeqd >;
	addExtern<DAS_CALL_METHOD(_method_1404)>(*this,lib,"vpcmpeqd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpeqd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1405 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpeqq >;
	addExtern<DAS_CALL_METHOD(_method_1405)>(*this,lib,"vpcmpeqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpeqq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1406 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpeqw >;
	addExtern<DAS_CALL_METHOD(_method_1406)>(*this,lib,"vpcmpeqw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpeqw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1407 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpestri >;
	addExtern<DAS_CALL_METHOD(_method_1407)>(*this,lib,"vpcmpestri",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpestri >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1408 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpestrm >;
	addExtern<DAS_CALL_METHOD(_method_1408)>(*this,lib,"vpcmpestrm",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpestrm >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1409 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpgtb >;
	addExtern<DAS_CALL_METHOD(_method_1409)>(*this,lib,"vpcmpgtb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpgtb >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1410 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpgtd >;
	addExtern<DAS_CALL_METHOD(_method_1410)>(*this,lib,"vpcmpgtd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpgtd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1411 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpgtq >;
	addExtern<DAS_CALL_METHOD(_method_1411)>(*this,lib,"vpcmpgtq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpgtq >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1412 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpcmpgtw >;
	addExtern<DAS_CALL_METHOD(_method_1412)>(*this,lib,"vpcmpgtw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpcmpgtw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1413 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpistri >;
	addExtern<DAS_CALL_METHOD(_method_1413)>(*this,lib,"vpcmpistri",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpistri >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1414 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpcmpistrm >;
	addExtern<DAS_CALL_METHOD(_method_1414)>(*this,lib,"vpcmpistrm",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpcmpistrm >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1415 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,Xbyak::PreferredEncoding),&Xbyak::CodeGenerator::vpdpbusd >;
	addExtern<DAS_CALL_METHOD(_method_1415)>(*this,lib,"vpdpbusd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,Xbyak::PreferredEncoding) , &Xbyak::CodeGenerator::vpdpbusd >::invoke")
		->args({"self","x1","x2","op","encoding"})
		->arg_init(4,make_smart<ExprConstEnumeration>(0,makeType<Xbyak::PreferredEncoding>(lib)));
	using _method_1416 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,Xbyak::PreferredEncoding),&Xbyak::CodeGenerator::vpdpbusds >;
	addExtern<DAS_CALL_METHOD(_method_1416)>(*this,lib,"vpdpbusds",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,Xbyak::PreferredEncoding) , &Xbyak::CodeGenerator::vpdpbusds >::invoke")
		->args({"self","x1","x2","op","encoding"})
		->arg_init(4,make_smart<ExprConstEnumeration>(0,makeType<Xbyak::PreferredEncoding>(lib)));
	using _method_1417 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,Xbyak::PreferredEncoding),&Xbyak::CodeGenerator::vpdpwssd >;
	addExtern<DAS_CALL_METHOD(_method_1417)>(*this,lib,"vpdpwssd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,Xbyak::PreferredEncoding) , &Xbyak::CodeGenerator::vpdpwssd >::invoke")
		->args({"self","x1","x2","op","encoding"})
		->arg_init(4,make_smart<ExprConstEnumeration>(0,makeType<Xbyak::PreferredEncoding>(lib)));
	using _method_1418 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,Xbyak::PreferredEncoding),&Xbyak::CodeGenerator::vpdpwssds >;
	addExtern<DAS_CALL_METHOD(_method_1418)>(*this,lib,"vpdpwssds",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,Xbyak::PreferredEncoding) , &Xbyak::CodeGenerator::vpdpwssds >::invoke")
		->args({"self","x1","x2","op","encoding"})
		->arg_init(4,make_smart<ExprConstEnumeration>(0,makeType<Xbyak::PreferredEncoding>(lib)));
	using _method_1419 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vperm2f128 >;
	addExtern<DAS_CALL_METHOD(_method_1419)>(*this,lib,"vperm2f128",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vperm2f128 >::invoke")
		->args({"self","y1","y2","op","imm"});
	using _method_1420 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vperm2i128 >;
	addExtern<DAS_CALL_METHOD(_method_1420)>(*this,lib,"vperm2i128",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vperm2i128 >::invoke")
		->args({"self","y1","y2","op","imm"});
	using _method_1421 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermd >;
	addExtern<DAS_CALL_METHOD(_method_1421)>(*this,lib,"vpermd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermd >::invoke")
		->args({"self","y1","y2","op"});
	using _method_1422 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermilpd >;
	addExtern<DAS_CALL_METHOD(_method_1422)>(*this,lib,"vpermilpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermilpd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1423 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpermilpd >;
	addExtern<DAS_CALL_METHOD(_method_1423)>(*this,lib,"vpermilpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpermilpd >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1424 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermilps >;
	addExtern<DAS_CALL_METHOD(_method_1424)>(*this,lib,"vpermilps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermilps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1425 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpermilps >;
	addExtern<DAS_CALL_METHOD(_method_1425)>(*this,lib,"vpermilps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpermilps >::invoke")
		->args({"self","xm","op","imm"});
	using _method_1426 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpermpd >;
	addExtern<DAS_CALL_METHOD(_method_1426)>(*this,lib,"vpermpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpermpd >::invoke")
		->args({"self","y","op","imm"});
	using _method_1427 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermpd >;
	addExtern<DAS_CALL_METHOD(_method_1427)>(*this,lib,"vpermpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermpd >::invoke")
		->args({"self","y1","y2","op"});
	using _method_1428 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermps >;
	addExtern<DAS_CALL_METHOD(_method_1428)>(*this,lib,"vpermps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermps >::invoke")
		->args({"self","y1","y2","op"});
	using _method_1429 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpermq >;
	addExtern<DAS_CALL_METHOD(_method_1429)>(*this,lib,"vpermq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpermq >::invoke")
		->args({"self","y","op","imm"});
	using _method_1430 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpermq >;
	addExtern<DAS_CALL_METHOD(_method_1430)>(*this,lib,"vpermq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Ymm &,const Xbyak::Ymm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpermq >::invoke")
		->args({"self","y1","y2","op"});
	using _method_1431 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char),&Xbyak::CodeGenerator::vpextrb >;
	addExtern<DAS_CALL_METHOD(_method_1431)>(*this,lib,"vpextrb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char) , &Xbyak::CodeGenerator::vpextrb >::invoke")
		->args({"self","op","x","imm"});
	using _method_1432 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char),&Xbyak::CodeGenerator::vpextrd >;
	addExtern<DAS_CALL_METHOD(_method_1432)>(*this,lib,"vpextrd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char) , &Xbyak::CodeGenerator::vpextrd >::invoke")
		->args({"self","op","x","imm"});
	using _method_1433 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char),&Xbyak::CodeGenerator::vpextrq >;
	addExtern<DAS_CALL_METHOD(_method_1433)>(*this,lib,"vpextrq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char) , &Xbyak::CodeGenerator::vpextrq >::invoke")
		->args({"self","op","x","imm"});
	using _method_1434 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char),&Xbyak::CodeGenerator::vpextrw >;
	addExtern<DAS_CALL_METHOD(_method_1434)>(*this,lib,"vpextrw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Xmm &,unsigned char) , &Xbyak::CodeGenerator::vpextrw >::invoke")
		->args({"self","op","x","imm"});
	using _method_1435 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpgatherdd >;
	addExtern<DAS_CALL_METHOD(_method_1435)>(*this,lib,"vpgatherdd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpgatherdd >::invoke")
		->args({"self","x1","addr","x2"});
	using _method_1436 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpgatherdq >;
	addExtern<DAS_CALL_METHOD(_method_1436)>(*this,lib,"vpgatherdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpgatherdq >::invoke")
		->args({"self","x1","addr","x2"});
	using _method_1437 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpgatherqd >;
	addExtern<DAS_CALL_METHOD(_method_1437)>(*this,lib,"vpgatherqd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpgatherqd >::invoke")
		->args({"self","x1","addr","x2"});
	using _method_1438 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpgatherqq >;
	addExtern<DAS_CALL_METHOD(_method_1438)>(*this,lib,"vpgatherqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Address &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpgatherqq >::invoke")
		->args({"self","x1","addr","x2"});
	using _method_1439 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vphaddd >;
	addExtern<DAS_CALL_METHOD(_method_1439)>(*this,lib,"vphaddd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vphaddd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1440 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vphaddsw >;
	addExtern<DAS_CALL_METHOD(_method_1440)>(*this,lib,"vphaddsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vphaddsw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1441 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vphaddw >;
	addExtern<DAS_CALL_METHOD(_method_1441)>(*this,lib,"vphaddw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vphaddw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1442 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vphminposuw >;
	addExtern<DAS_CALL_METHOD(_method_1442)>(*this,lib,"vphminposuw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vphminposuw >::invoke")
		->args({"self","xm","op"});
	using _method_1443 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vphsubd >;
	addExtern<DAS_CALL_METHOD(_method_1443)>(*this,lib,"vphsubd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vphsubd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1444 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vphsubsw >;
	addExtern<DAS_CALL_METHOD(_method_1444)>(*this,lib,"vphsubsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vphsubsw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1445 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vphsubw >;
	addExtern<DAS_CALL_METHOD(_method_1445)>(*this,lib,"vphsubw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vphsubw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1446 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpinsrb >;
	addExtern<DAS_CALL_METHOD(_method_1446)>(*this,lib,"vpinsrb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpinsrb >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1447 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpinsrd >;
	addExtern<DAS_CALL_METHOD(_method_1447)>(*this,lib,"vpinsrd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpinsrd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1448 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpinsrq >;
	addExtern<DAS_CALL_METHOD(_method_1448)>(*this,lib,"vpinsrq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpinsrq >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1449 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vpinsrw >;
	addExtern<DAS_CALL_METHOD(_method_1449)>(*this,lib,"vpinsrw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vpinsrw >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1450 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaddubsw >;
	addExtern<DAS_CALL_METHOD(_method_1450)>(*this,lib,"vpmaddubsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaddubsw >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1451 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaddwd >;
	addExtern<DAS_CALL_METHOD(_method_1451)>(*this,lib,"vpmaddwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaddwd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1452 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmaskmovd >;
	addExtern<DAS_CALL_METHOD(_method_1452)>(*this,lib,"vpmaskmovd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmaskmovd >::invoke")
		->args({"self","addr","x1","x2"});
	using _method_1453 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vpmaskmovd >;
	addExtern<DAS_CALL_METHOD(_method_1453)>(*this,lib,"vpmaskmovd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vpmaskmovd >::invoke")
		->args({"self","x1","x2","addr"});
	using _method_1454 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &,const Xbyak::Xmm &),&Xbyak::CodeGenerator::vpmaskmovq >;
	addExtern<DAS_CALL_METHOD(_method_1454)>(*this,lib,"vpmaskmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &,const Xbyak::Xmm &,const Xbyak::Xmm &) , &Xbyak::CodeGenerator::vpmaskmovq >::invoke")
		->args({"self","addr","x1","x2"});
	using _method_1455 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Address &),&Xbyak::CodeGenerator::vpmaskmovq >;
	addExtern<DAS_CALL_METHOD(_method_1455)>(*this,lib,"vpmaskmovq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Address &) , &Xbyak::CodeGenerator::vpmaskmovq >::invoke")
		->args({"self","x1","x2","addr"});
	using _method_1456 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vpmaxsb >;
	addExtern<DAS_CALL_METHOD(_method_1456)>(*this,lib,"vpmaxsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vpmaxsb >::invoke")
		->args({"self","x1","x2","op"});
}
}

