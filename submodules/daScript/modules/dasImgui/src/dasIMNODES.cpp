// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasIMNODES.h"
#include "need_dasIMNODES.h"
#include "dasIMNODES.struct.impl.inc"
namespace das {
#include "dasIMNODES.enum.class.inc"
#include "dasIMNODES.struct.class.inc"
#include "dasIMNODES.func.aot.inc"
Module_dasIMNODES::Module_dasIMNODES() : Module("imnodes") {
}
bool Module_dasIMNODES::initDependencies() {
	if ( initialized ) return true;
	auto mod_imgui = Module::require("imgui");
	if ( !mod_imgui ) return false;
	if ( !mod_imgui->initDependencies() ) return false;
	initialized = true;
	lib.addModule(this);
	lib.addBuiltInModule();
	lib.addModule(mod_imgui);
	initAotAlias();
	#include "dasIMNODES.const.inc"
	#include "dasIMNODES.enum.add.inc"
	#include "dasIMNODES.dummy.add.inc"
	#include "dasIMNODES.struct.add.inc"
	#include "dasIMNODES.struct.postadd.inc"
	#include "dasIMNODES.alias.add.inc"
	#include "dasIMNODES.func.reg.inc"
	initMain();
	return true;
}
}
REGISTER_MODULE_IN_NAMESPACE(Module_dasIMNODES,das);

