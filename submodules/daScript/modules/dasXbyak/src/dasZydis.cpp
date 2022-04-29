#include "daScript/misc/platform.h"

#include "daScript/daScript.h"
#include "daScript/ast/ast_typefactory_bind.h"

#include "dasZydis.h"

using namespace das;

#include <Zydis/Zydis.h>
#include <Zydis/Status.h>
#include <Zycore/Format.h>
#include <Zycore/LibC.h>

#include <stdio.h>
#include <inttypes.h>
namespace das {

void das_decode ( void * _data, uint64_t length ) {
    uint8_t * data = (uint8_t *) _data;
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);
    ZydisFormatter formatter;
    ZydisFormatterInit(&formatter, ZYDIS_FORMATTER_STYLE_INTEL);
    ZyanU64 runtime_address = intptr_t(data);
    ZyanUSize offset = 0;
    ZydisDecodedInstruction instruction;
    while (ZYAN_SUCCESS(ZydisDecoderDecodeBuffer(&decoder, data + offset, length - offset, &instruction))) {
        printf("%016" PRIX64 "  ", runtime_address);
        char buffer[256];
        ZydisFormatterFormatInstruction(&formatter, &instruction, buffer, sizeof(buffer), runtime_address);
        puts(buffer);
        offset += instruction.length;
        runtime_address += instruction.length;
    }
    fflush(stdout);
}

ZydisFormatterFunc default_print_address_absolute;
TTable<uint64_t,char *> zydis_address_table;
Context * zydis_disasm_context = nullptr;

static ZyanStatus ZydisFormatterPrintAddressAbsolute(const ZydisFormatter* formatter,
    ZydisFormatterBuffer* buffer, ZydisFormatterContext* context) {
    ZyanU64 address;
    ZYAN_CHECK(ZydisCalcAbsoluteAddress(context->instruction, context->operand,
        context->runtime_address, &address));

    auto pname = TTable<uint64_t,char *>::safe_index(&zydis_address_table,address,zydis_disasm_context);
    if ( pname ) {
        ZYAN_CHECK(ZydisFormatterBufferAppend(buffer, ZYDIS_TOKEN_SYMBOL));
        ZyanString* string;
        ZYAN_CHECK(ZydisFormatterBufferGetString(buffer, &string));
        return ZyanStringAppendFormat(string, "%s", *pname);
    } else {
        return default_print_address_absolute(formatter, buffer, context);
    }
}

void das_decode_ex ( void * _data, uint64_t length, const TTable<uint64_t,char *> & addr_table,
        const TBlock<void,uint64_t,const char *> & blk, Context * context, LineInfoArg * at ) {
    memcpy(&zydis_address_table, &addr_table, sizeof(Table));
    zydis_disasm_context = context;
    uint8_t * data = (uint8_t *) _data;
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64);
    ZydisFormatter formatter;
    ZydisFormatterInit(&formatter, ZYDIS_FORMATTER_STYLE_INTEL);
    default_print_address_absolute = (ZydisFormatterFunc)&ZydisFormatterPrintAddressAbsolute;
    ZydisFormatterSetHook(&formatter, ZYDIS_FORMATTER_FUNC_PRINT_ADDRESS_ABS,
        (const void**)&default_print_address_absolute);
    ZyanU64 runtime_address = intptr_t(data);
    ZyanUSize offset = 0;
    ZydisDecodedInstruction instruction;
    while (ZYAN_SUCCESS(ZydisDecoderDecodeBuffer(&decoder, data + offset, length - offset, &instruction))) {
        char buffer[256];
        ZydisFormatterFormatInstruction(&formatter, &instruction, buffer, sizeof(buffer), runtime_address);
        das_invoke<void>::invoke<uint64_t,const char *>(context, at, blk, runtime_address, buffer);
        offset += instruction.length;
        runtime_address += instruction.length;
    }
    fflush(stdout);
}

Module_Zydis::Module_Zydis() : Module("zydis") {
    ModuleLibrary lib;
    lib.addModule(this);
    lib.addBuiltInModule();
    addExtern<DAS_BIND_FUN(das_decode)>(*this, lib, "disassemble",
        SideEffects::worstDefault, "das_decode")
	        ->args({"data","label"});
    addExtern<DAS_BIND_FUN(das_decode_ex)>(*this, lib, "disassemble",
        SideEffects::worstDefault, "das_decode_ex")
	        ->args({"data","label","address_book","block","context","line"});
}

ModuleAotType Module_Zydis::aotRequire ( TextWriter & tw ) const  {
    tw << "#include \"../modules/dasXbyak/src/dasZydis.h\"\n";
    return ModuleAotType::cpp;
}

}

REGISTER_MODULE_IN_NAMESPACE(Module_Zydis,das);

