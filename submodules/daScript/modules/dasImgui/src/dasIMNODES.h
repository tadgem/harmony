// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#pragma once
#include "cb_dasIMGUI.h"
#include "cb_dasIMNODES.h"
#include "need_dasIMGUI.h"
namespace das {
class Module_dasIMNODES : public Module {
public:
	Module_dasIMNODES();
protected:
virtual bool initDependencies() override;
	void initMain ();
	void initAotAlias ();
	virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
	#include "dasIMNODES.func.decl.inc"
public:
	ModuleLibrary lib;
	bool initialized = false;
};
}

