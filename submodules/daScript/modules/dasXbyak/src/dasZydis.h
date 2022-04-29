#pragma once

namespace das {

class Module_Zydis : public Module {
public:
    Module_Zydis();
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
};

}
