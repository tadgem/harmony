// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasBGFX.h"
#include "need_dasBGFX.h"
#include "dasBGFX.struct.impl.inc"
namespace das {
#include "dasBGFX.enum.class.inc"
#include "dasBGFX.struct.class.inc"
Module_dasBGFX::Module_dasBGFX() : Module("bgfx") {
}
bool Module_dasBGFX::initDependencies() {
	if ( initialized ) return true;
	initialized = true;
	lib.addModule(this);
	lib.addBuiltInModule();
	#include "dasBGFX.const.inc"
	#include "dasBGFX.enum.add.inc"
	#include "dasBGFX.dummy.add.inc"
	#include "dasBGFX.struct.add.inc"
	#include "dasBGFX.struct.postadd.inc"
	#include "dasBGFX.alias.add.inc"
	#include "dasBGFX.func.reg.inc"
	initMain();
	return true;
}
}
REGISTER_MODULE_IN_NAMESPACE(Module_dasBGFX,das);

