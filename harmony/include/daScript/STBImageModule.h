#pragma once
#include "daScript/misc/platform.h"

#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_typefactory_bind.h"

namespace das {
    class Module_dasStbImage : public das::Module {
    public:
        Module_dasStbImage();

        virtual bool initDependencies() override;
        virtual das::ModuleAotType aotRequire(das::TextWriter& tw) const override {
            tw << "#include \"../modules/dasStbImage/src/dasStbImage.h\"\n";
            return das::ModuleAotType::cpp;
        }
    };
}