#include "daScript/misc/platform.h"

#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include "dasBGFXImgui.h"

using namespace das;

namespace das {

void bgfx_imgui_create ( float fontSize ) {
    imguiCreate(fontSize);
}

void bgfx_imgui_destroy () {
    imguiDestroy();
}

void bgfx_imgui_begin_frame(uint32_t viewId) {
    imguiBeginFrame((bgfx::ViewId) viewId);
}

void bgfx_imgui_end_frame() {
    imguiEndFrame();
}

void bgfx_imgui_push_font(uint32_t fidx, Context * context, LineInfoArg * at ) {
    if ( fidx>=BgfxImguiFont::Enum::Count) context->throw_error_at(*at, "invalid font index");
    imguiPushFont((BgfxImguiFont::Enum)fidx);
}

class Module_BGFXImgui : public Module {
public:
    Module_BGFXImgui();
    virtual ModuleAotType aotRequire ( TextWriter & tw ) const override;
    virtual bool initDependencies() override;
protected:
    bool initialized = false;
    ModuleLibrary lib;
};

Module_BGFXImgui::Module_BGFXImgui() : Module("bgfx_imgui") {
}

bool Module_BGFXImgui::initDependencies() {
    if ( initialized ) return true;
    auto mod_imgui = Module::require("imgui");
    if ( !mod_imgui ) return false;
    if ( !mod_imgui->initDependencies() ) return false;
    initialized = true;
    lib.addModule(this);
    lib.addBuiltInModule();
    lib.addModule(mod_imgui);
    addConstant<uint32_t>(*this, "BGFX_IMGUI_FONT_REGULAR", 0);
    addConstant<uint32_t>(*this, "BGFX_IMGUI_FONT_MONO",    1);
    addExtern<DAS_BIND_FUN(bgfx_imgui_create)>(*this, lib, "bgfx_imgui_create",
        SideEffects::worstDefault, "bgfx_imgui_create")
            ->arg("fontSize");
    addExtern<DAS_BIND_FUN(bgfx_imgui_destroy)>(*this, lib, "bgfx_imgui_destroy",
        SideEffects::worstDefault, "bgfx_imgui_destroy");
    addExtern<DAS_BIND_FUN(bgfx_imgui_begin_frame)>(*this, lib, "bgfx_imgui_begin_frame",
        SideEffects::worstDefault, "bgfx_imgui_begin_frame")
            ->arg("viewId");
    addExtern<DAS_BIND_FUN(bgfx_imgui_end_frame)>(*this, lib, "bgfx_imgui_end_frame",
        SideEffects::worstDefault, "bgfx_imgui_end_frame");
    addExtern<DAS_BIND_FUN(bgfx_imgui_push_font)>(*this, lib, "bgfx_imgui_push_font",
        SideEffects::worstDefault, "bgfx_imgui_push_font")
            ->args({"fontIndex","context","line"});
    return true;
}

ModuleAotType Module_BGFXImgui::aotRequire ( TextWriter & tw ) const {
    tw << "#include \"../modules/dasBGFX/src/dasBGFXImgui.h\"\n";
    return ModuleAotType::cpp;
}

}

REGISTER_MODULE_IN_NAMESPACE(Module_BGFXImgui,das);

