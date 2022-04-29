#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasXBYAK.h"
#include "need_dasXBYAK.h"
#include "aot_dasXBYAK.h"

namespace das {

    void das_L_str ( Xbyak::CodeGenerator & self, const char * label ) {
        self.L(label);
    }

    void das_L_lab ( Xbyak::CodeGenerator & self, Xbyak::Label & label ) {
        self.L(label);
    }

    Xbyak::Label * das_L ( Xbyak::CodeGenerator & self ) {
        auto label = new Xbyak::Label();
        self.L(*label);
        return label;
    }

    Xbyak::Address das_op_at_reg ( const Xbyak::AddressFrame & frame, const Xbyak::Reg & reg ) {
        return frame[reg];
    }

    Xbyak::RegExp das_op_mul_uint ( const Xbyak::Reg & reg, uint32_t value ) {
        return reg * value;
    }

    Xbyak::RegExp das_op_add_reg ( const Xbyak::Reg & reg, const Xbyak::Reg & value ) {
        return reg + value;
    }

    Xbyak::RegExp das_op_add_int ( const Xbyak::Reg & reg, int32_t value ) {
        return reg + value;
    }

    Xbyak::RegExp das_op_add_uint ( const Xbyak::Reg & reg, uint32_t value ) {
        return reg + value;
    }

    Xbyak::RegExp das_op_sub_int ( const Xbyak::Reg & reg, int32_t value ) {
        return reg - value;
    }

    Xbyak::RegExp das_op_sub_uint ( const Xbyak::Reg & reg, uint32_t value ) {
        return reg - value;
    }

    float4 das_invoke_code ( const Xbyak::CodeGenerator & code, vec4f anything, void * cmres, Context * context ) {
        vec4f * arguments = cast<vec4f *>::to(anything);
        auto fun = code.getCode<JitFunction>();
        return fun ( context, arguments, cmres );
    }

    bool das_is_jit_function ( const Func func ) {
        auto simfn = func.PTR;
        if ( !simfn ) return false;
        return simfn->code && simfn->code->rtti_node_isJit();
    }

    bool das_remove_jit ( const Func func ) {
        auto simfn = func.PTR;
        if ( !simfn ) return false;
        if ( simfn->code && simfn->code->rtti_node_isJit() ) {
            auto jitNode = static_cast<SimNode_Jit *>(simfn->code);
            simfn->code = jitNode->saved_code;
            simfn->aot = jitNode->saved_aot;
            simfn->aotFunction = jitNode->saved_aot_function;
            simfn->jit = false;
            return true;
        } else {
            return false;
        }
    }

    bool das_instrument_jit ( const Xbyak::CodeGenerator & code, const Func func, Context * context ) {
        auto simfn = func.PTR;
        if ( !simfn ) return false;
        if ( simfn->code && simfn->code->rtti_node_isJit() ) {
            auto jitNode = static_cast<SimNode_Jit *>(simfn->code);
            jitNode->func = code.getCode<JitFunction>();
        } else {
            auto gen = code.getCode<JitFunction>();
            auto node = context->code->makeNode<SimNode_Jit>(LineInfo(), gen);
            node->saved_code = simfn->code;
            node->saved_aot = simfn->aot;
            node->saved_aot_function = simfn->aotFunction;
            simfn->code = node;
            simfn->aot = false;
            simfn->aotFunction = nullptr;
            simfn->jit = true;
        }
        return true;
    }

    void * das_get_code_ptr ( const Xbyak::CodeGenerator & code ) {
        return (void *) code.getCode();
    }

    uint64_t das_get_curr_ptr ( const Xbyak::CodeGenerator & code ) {
        return (uint64_t) code.getCurr();
    }

    vec4f JIT_call_or_fastcall ( SimFunction * fn, vec4f * args, Context * context ) {
        return context->callOrFastcall(fn, args, nullptr);
    }

    uint64_t das_get_JIT_call_or_fastcall ( ) {
        return (uint64_t) &JIT_call_or_fastcall;
    }

    void JIT_exception ( const char * text, Context * context ) {
        context->throw_error(text);
    }

    uint64_t das_get_JIT_exception ( ) {
        return (uint64_t) &JIT_exception;
    }

    uint64_t das_get_SimFunction_by_MNH ( uint64_t MNH, Context * context ) {
        return (uint64_t) context->fnByMangledName(MNH);
    }

    uint64_t das_get_const_string_offset ( const char * text, Context * context, LineInfoArg * at ) {
        if ( !text ) context->throw_error_at(*at, "missing text");
        auto ptext = context->constStringHeap->allocateString(text);
        return (uint64_t) ptext;
    }

	void Module_dasXBYAK::initMain () {
        #ifdef XBYAK32
            addConstant<bool>(*this,"xbyak32",true);
            addConstant<bool>(*this,"xbyak64",false);
            addConstant<bool>(*this,"xbyak64win",false);
        #elif defined(XBYAK64_WIN)
            addConstant<bool>(*this,"xbyak32",false);
            addConstant<bool>(*this,"xbyak64",false);
            addConstant<bool>(*this,"xbyak64win",true);
        #else
            addConstant<bool>(*this,"xbyak32",false);
            addConstant<bool>(*this,"xbyak64",true);
            addConstant<bool>(*this,"xbyak64win",false);
        #endif
        // remainder of xbyak
        addExtern<DAS_BIND_FUN(das_L_str)>(*this, lib, "L",
            SideEffects::worstDefault, "das_L_str")
                ->args({"self","label"});
        addExtern<DAS_BIND_FUN(das_L_lab)>(*this, lib, "L",
            SideEffects::worstDefault, "das_L_lab")
                ->args({"self","label"});
        addExtern<DAS_BIND_FUN(das_L)>(*this, lib, "L",
            SideEffects::worstDefault, "das_L")
                ->args({"self"});
        addExtern<DAS_BIND_FUN(das_op_at_reg),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "[]",
            SideEffects::worstDefault, "das_op_at_reg")
                ->args({"AddrFrame","address"});
        addExtern<DAS_BIND_FUN(das_op_mul_uint),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "*",
            SideEffects::worstDefault, "das_op_mul_uint")
                ->args({"Operand","constant"});
        addExtern<DAS_BIND_FUN(das_op_add_reg),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "+",
            SideEffects::worstDefault, "das_op_add_reg")
                ->args({"Operand","constant"});
        addExtern<DAS_BIND_FUN(das_op_add_int),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "+",
            SideEffects::worstDefault, "das_op_add_int")
                ->args({"Operand","constant"});
        addExtern<DAS_BIND_FUN(das_op_add_uint),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "+",
            SideEffects::worstDefault, "das_op_add_uint")
                ->args({"Operand","constant"});
        addExtern<DAS_BIND_FUN(das_op_sub_int),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "-",
            SideEffects::worstDefault, "das_op_sub_int")
                ->args({"Operand","constant"});
        addExtern<DAS_BIND_FUN(das_op_sub_uint),SimNode_ExtFuncCallAndCopyOrMove>(*this, lib, "-",
            SideEffects::worstDefault, "das_op_sub_uint")
                ->args({"Operand","constant"});
        // codogen and instruments
        addExtern<DAS_BIND_FUN(das_get_code_ptr)>(*this, lib, "get_code",
            SideEffects::worstDefault, "das_get_code_ptr");
        addExtern<DAS_BIND_FUN(das_get_curr_ptr)>(*this, lib, "get_current_address",
            SideEffects::worstDefault, "das_get_curr_ptr");
        addExtern<DAS_BIND_FUN(das_invoke_code)>(*this, lib, "invoke_code",
            SideEffects::worstDefault, "das_invoke_code")
                ->args({"code","arguments","cmres","context"})->unsafeOperation = true;
        addExtern<DAS_BIND_FUN(das_instrument_jit)>(*this, lib, "instrument_jit",
            SideEffects::worstDefault, "das_instrument_jit")
                ->args({"code","function","context"})->unsafeOperation = true;
        addExtern<DAS_BIND_FUN(das_remove_jit)>(*this, lib, "remove_jit",
            SideEffects::worstDefault, "das_remove_jit")
                ->args({"function"})->unsafeOperation = true;
        addExtern<DAS_BIND_FUN(das_is_jit_function)>(*this, lib, "is_jit_function",
            SideEffects::worstDefault, "das_is_jit_function")
                ->args({"function"});
        // JIT helpers
        addExtern<DAS_BIND_FUN(das_get_SimFunction_by_MNH)>(*this, lib, "get_function_address",
            SideEffects::none, "das_get_SimFunction_by_MNH")
                ->args({"MNH","at"});
        addExtern<DAS_BIND_FUN(das_get_const_string_offset)>(*this, lib, "jit_generate_const_string",
            SideEffects::none, "das_get_const_string_offset")
                ->args({"text","context","at"});
        // JIT table
        addExtern<DAS_BIND_FUN(das_get_JIT_call_or_fastcall)>(*this, lib, "JIT_call_or_fastcall",
            SideEffects::none, "das_get_JIT_call_or_fastcall");
        addExtern<DAS_BIND_FUN(das_get_JIT_exception)>(*this, lib, "JIT_exception",
            SideEffects::none, "das_get_JIT_exception");
        // fixup RET
        auto fnRet = findUniqueFunction("ret");
        fnRet->arguments[1]->init = make_smart<ExprConstInt>(0);
    }

	ModuleAotType Module_dasXBYAK::aotRequire ( TextWriter & tw ) const {
        tw << "#include \"../modules/dasXbyak/src/aot_dasXBYAK.h\"\n";
        tw << "#include \"daScript/simulate/bind_enum.h\"\n";
        tw << "#include \"../modules/dasXbyak/src/dasXBYAK.enum.decl.cast.inc\"\n";
        return ModuleAotType::cpp;
    }
}
