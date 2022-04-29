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
#include "dasXBYAK.struct.impl.inc"
namespace das {
#include "dasXBYAK.enum.class.inc"
#include "dasXBYAK.struct.class.inc"
#include "dasXBYAK.func.aot.inc"
Module_dasXBYAK::Module_dasXBYAK() : Module("xbyak") {
}
bool Module_dasXBYAK::initDependencies() {
	if ( initialized ) return true;
	initialized = true;
	lib.addModule(this);
	lib.addBuiltInModule();
	#include "dasXBYAK.enum.add.inc"
	#include "dasXBYAK.dummy.add.inc"
	#include "dasXBYAK.struct.add.inc"
	#include "dasXBYAK.struct.postadd.inc"
	#include "dasXBYAK.alias.add.inc"
	#include "dasXBYAK.func.reg.inc"
	initMain();
	return true;
}
}
REGISTER_MODULE_IN_NAMESPACE(Module_dasXBYAK,das);

