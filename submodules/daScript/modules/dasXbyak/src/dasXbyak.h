// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#pragma once
namespace das {
class Module_dasXBYAK : public Module {
public:
	Module_dasXBYAK();
protected:
virtual bool initDependencies() override;
	void initMain ();
	virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
	#include "dasXBYAK.func.decl.inc"
public:
	ModuleLibrary lib;
	bool initialized = false;
};
}

