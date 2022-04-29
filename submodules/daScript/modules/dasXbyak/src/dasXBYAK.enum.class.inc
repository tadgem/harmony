// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

class Enumeration_Xbyak_inner_LabelMode : public das::Enumeration {
public:
	Enumeration_Xbyak_inner_LabelMode() : das::Enumeration("LabelMode") {
		external = true;
		cppName = "Xbyak::inner::LabelMode";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("LasIs", "LasIs", int64_t(Xbyak::inner::LabelMode::LasIs), das::LineInfo());
		addIEx("Labs", "Labs", int64_t(Xbyak::inner::LabelMode::Labs), das::LineInfo());
		addIEx("LaddTop", "LaddTop", int64_t(Xbyak::inner::LabelMode::LaddTop), das::LineInfo());
	}
};

class Enumeration_Xbyak_Operand_Kind : public das::Enumeration {
public:
	Enumeration_Xbyak_Operand_Kind() : das::Enumeration("Kind") {
		external = true;
		cppName = "Xbyak::Operand::Kind";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("NONE", "NONE", int64_t(Xbyak::Operand::Kind::NONE), das::LineInfo());
		addIEx("MEM", "MEM", int64_t(Xbyak::Operand::Kind::MEM), das::LineInfo());
		addIEx("REG", "REG", int64_t(Xbyak::Operand::Kind::REG), das::LineInfo());
		addIEx("MMX", "MMX", int64_t(Xbyak::Operand::Kind::MMX), das::LineInfo());
		addIEx("FPU", "FPU", int64_t(Xbyak::Operand::Kind::FPU), das::LineInfo());
		addIEx("XMM", "XMM", int64_t(Xbyak::Operand::Kind::XMM), das::LineInfo());
		addIEx("YMM", "YMM", int64_t(Xbyak::Operand::Kind::YMM), das::LineInfo());
		addIEx("ZMM", "ZMM", int64_t(Xbyak::Operand::Kind::ZMM), das::LineInfo());
		addIEx("OPMASK", "OPMASK", int64_t(Xbyak::Operand::Kind::OPMASK), das::LineInfo());
		addIEx("BNDREG", "BNDREG", int64_t(Xbyak::Operand::Kind::BNDREG), das::LineInfo());
		addIEx("TMM", "TMM", int64_t(Xbyak::Operand::Kind::TMM), das::LineInfo());
	}
};

class Enumeration_Xbyak_Operand_Code : public das::Enumeration {
public:
	Enumeration_Xbyak_Operand_Code() : das::Enumeration("Code") {
		external = true;
		cppName = "Xbyak::Operand::Code";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("RAX", "RAX", int64_t(Xbyak::Operand::Code::RAX), das::LineInfo());
		addIEx("RCX", "RCX", int64_t(Xbyak::Operand::Code::RCX), das::LineInfo());
		addIEx("RDX", "RDX", int64_t(Xbyak::Operand::Code::RDX), das::LineInfo());
		addIEx("RBX", "RBX", int64_t(Xbyak::Operand::Code::RBX), das::LineInfo());
		addIEx("RSP", "RSP", int64_t(Xbyak::Operand::Code::RSP), das::LineInfo());
		addIEx("RBP", "RBP", int64_t(Xbyak::Operand::Code::RBP), das::LineInfo());
		addIEx("RSI", "RSI", int64_t(Xbyak::Operand::Code::RSI), das::LineInfo());
		addIEx("RDI", "RDI", int64_t(Xbyak::Operand::Code::RDI), das::LineInfo());
		addIEx("R8", "R8", int64_t(Xbyak::Operand::Code::R8), das::LineInfo());
		addIEx("R9", "R9", int64_t(Xbyak::Operand::Code::R9), das::LineInfo());
		addIEx("R10", "R10", int64_t(Xbyak::Operand::Code::R10), das::LineInfo());
		addIEx("R11", "R11", int64_t(Xbyak::Operand::Code::R11), das::LineInfo());
		addIEx("R12", "R12", int64_t(Xbyak::Operand::Code::R12), das::LineInfo());
		addIEx("R13", "R13", int64_t(Xbyak::Operand::Code::R13), das::LineInfo());
		addIEx("R14", "R14", int64_t(Xbyak::Operand::Code::R14), das::LineInfo());
		addIEx("R15", "R15", int64_t(Xbyak::Operand::Code::R15), das::LineInfo());
		addIEx("R8D", "R8D", int64_t(Xbyak::Operand::Code::R8D), das::LineInfo());
		addIEx("R9D", "R9D", int64_t(Xbyak::Operand::Code::R9D), das::LineInfo());
		addIEx("R10D", "R10D", int64_t(Xbyak::Operand::Code::R10D), das::LineInfo());
		addIEx("R11D", "R11D", int64_t(Xbyak::Operand::Code::R11D), das::LineInfo());
		addIEx("R12D", "R12D", int64_t(Xbyak::Operand::Code::R12D), das::LineInfo());
		addIEx("R13D", "R13D", int64_t(Xbyak::Operand::Code::R13D), das::LineInfo());
		addIEx("R14D", "R14D", int64_t(Xbyak::Operand::Code::R14D), das::LineInfo());
		addIEx("R15D", "R15D", int64_t(Xbyak::Operand::Code::R15D), das::LineInfo());
		addIEx("R8W", "R8W", int64_t(Xbyak::Operand::Code::R8W), das::LineInfo());
		addIEx("R9W", "R9W", int64_t(Xbyak::Operand::Code::R9W), das::LineInfo());
		addIEx("R10W", "R10W", int64_t(Xbyak::Operand::Code::R10W), das::LineInfo());
		addIEx("R11W", "R11W", int64_t(Xbyak::Operand::Code::R11W), das::LineInfo());
		addIEx("R12W", "R12W", int64_t(Xbyak::Operand::Code::R12W), das::LineInfo());
		addIEx("R13W", "R13W", int64_t(Xbyak::Operand::Code::R13W), das::LineInfo());
		addIEx("R14W", "R14W", int64_t(Xbyak::Operand::Code::R14W), das::LineInfo());
		addIEx("R15W", "R15W", int64_t(Xbyak::Operand::Code::R15W), das::LineInfo());
		addIEx("R8B", "R8B", int64_t(Xbyak::Operand::Code::R8B), das::LineInfo());
		addIEx("R9B", "R9B", int64_t(Xbyak::Operand::Code::R9B), das::LineInfo());
		addIEx("R10B", "R10B", int64_t(Xbyak::Operand::Code::R10B), das::LineInfo());
		addIEx("R11B", "R11B", int64_t(Xbyak::Operand::Code::R11B), das::LineInfo());
		addIEx("R12B", "R12B", int64_t(Xbyak::Operand::Code::R12B), das::LineInfo());
		addIEx("R13B", "R13B", int64_t(Xbyak::Operand::Code::R13B), das::LineInfo());
		addIEx("R14B", "R14B", int64_t(Xbyak::Operand::Code::R14B), das::LineInfo());
		addIEx("R15B", "R15B", int64_t(Xbyak::Operand::Code::R15B), das::LineInfo());
		addIEx("SPL", "SPL", int64_t(Xbyak::Operand::Code::SPL), das::LineInfo());
		addIEx("BPL", "BPL", int64_t(Xbyak::Operand::Code::BPL), das::LineInfo());
		addIEx("SIL", "SIL", int64_t(Xbyak::Operand::Code::SIL), das::LineInfo());
		addIEx("DIL", "DIL", int64_t(Xbyak::Operand::Code::DIL), das::LineInfo());
		addIEx("EAX", "EAX", int64_t(Xbyak::Operand::Code::EAX), das::LineInfo());
		addIEx("ECX", "ECX", int64_t(Xbyak::Operand::Code::ECX), das::LineInfo());
		addIEx("EDX", "EDX", int64_t(Xbyak::Operand::Code::EDX), das::LineInfo());
		addIEx("EBX", "EBX", int64_t(Xbyak::Operand::Code::EBX), das::LineInfo());
		addIEx("ESP", "ESP", int64_t(Xbyak::Operand::Code::ESP), das::LineInfo());
		addIEx("EBP", "EBP", int64_t(Xbyak::Operand::Code::EBP), das::LineInfo());
		addIEx("ESI", "ESI", int64_t(Xbyak::Operand::Code::ESI), das::LineInfo());
		addIEx("EDI", "EDI", int64_t(Xbyak::Operand::Code::EDI), das::LineInfo());
		addIEx("AX", "AX", int64_t(Xbyak::Operand::Code::AX), das::LineInfo());
		addIEx("CX", "CX", int64_t(Xbyak::Operand::Code::CX), das::LineInfo());
		addIEx("DX", "DX", int64_t(Xbyak::Operand::Code::DX), das::LineInfo());
		addIEx("BX", "BX", int64_t(Xbyak::Operand::Code::BX), das::LineInfo());
		addIEx("SP", "SP", int64_t(Xbyak::Operand::Code::SP), das::LineInfo());
		addIEx("BP", "BP", int64_t(Xbyak::Operand::Code::BP), das::LineInfo());
		addIEx("SI", "SI", int64_t(Xbyak::Operand::Code::SI), das::LineInfo());
		addIEx("DI", "DI", int64_t(Xbyak::Operand::Code::DI), das::LineInfo());
		addIEx("AL", "AL", int64_t(Xbyak::Operand::Code::AL), das::LineInfo());
		addIEx("CL", "CL", int64_t(Xbyak::Operand::Code::CL), das::LineInfo());
		addIEx("DL", "DL", int64_t(Xbyak::Operand::Code::DL), das::LineInfo());
		addIEx("BL", "BL", int64_t(Xbyak::Operand::Code::BL), das::LineInfo());
		addIEx("AH", "AH", int64_t(Xbyak::Operand::Code::AH), das::LineInfo());
		addIEx("CH", "CH", int64_t(Xbyak::Operand::Code::CH), das::LineInfo());
		addIEx("DH", "DH", int64_t(Xbyak::Operand::Code::DH), das::LineInfo());
		addIEx("BH", "BH", int64_t(Xbyak::Operand::Code::BH), das::LineInfo());
	}
};

class Enumeration_Xbyak_CodeArray_ProtectMode : public das::Enumeration {
public:
	Enumeration_Xbyak_CodeArray_ProtectMode() : das::Enumeration("ProtectMode") {
		external = true;
		cppName = "Xbyak::CodeArray::ProtectMode";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("PROTECT_RW", "PROTECT_RW", int64_t(Xbyak::CodeArray::ProtectMode::PROTECT_RW), das::LineInfo());
		addIEx("PROTECT_RWE", "PROTECT_RWE", int64_t(Xbyak::CodeArray::ProtectMode::PROTECT_RWE), das::LineInfo());
		addIEx("PROTECT_RE", "PROTECT_RE", int64_t(Xbyak::CodeArray::ProtectMode::PROTECT_RE), das::LineInfo());
	}
};

class Enumeration_Xbyak_Address_Mode : public das::Enumeration {
public:
	Enumeration_Xbyak_Address_Mode() : das::Enumeration("Mode") {
		external = true;
		cppName = "Xbyak::Address::Mode";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("M_ModRM", "M_ModRM", int64_t(Xbyak::Address::Mode::M_ModRM), das::LineInfo());
		addIEx("M_64bitDisp", "M_64bitDisp", int64_t(Xbyak::Address::Mode::M_64bitDisp), das::LineInfo());
		addIEx("M_rip", "M_rip", int64_t(Xbyak::Address::Mode::M_rip), das::LineInfo());
		addIEx("M_ripAddr", "M_ripAddr", int64_t(Xbyak::Address::Mode::M_ripAddr), das::LineInfo());
	}
};

class Enumeration_Xbyak_PreferredEncoding : public das::Enumeration {
public:
	Enumeration_Xbyak_PreferredEncoding() : das::Enumeration("PreferredEncoding") {
		external = true;
		cppName = "Xbyak::PreferredEncoding";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("DefaultEncoding", "DefaultEncoding", int64_t(Xbyak::PreferredEncoding::DefaultEncoding), das::LineInfo());
		addIEx("VexEncoding", "VexEncoding", int64_t(Xbyak::PreferredEncoding::VexEncoding), das::LineInfo());
		addIEx("EvexEncoding", "EvexEncoding", int64_t(Xbyak::PreferredEncoding::EvexEncoding), das::LineInfo());
	}
};

class Enumeration_Xbyak_CodeGenerator_LabelType : public das::Enumeration {
public:
	Enumeration_Xbyak_CodeGenerator_LabelType() : das::Enumeration("LabelType") {
		external = true;
		cppName = "Xbyak::CodeGenerator::LabelType";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("T_SHORT", "T_SHORT", int64_t(Xbyak::CodeGenerator::LabelType::T_SHORT), das::LineInfo());
		addIEx("T_NEAR", "T_NEAR", int64_t(Xbyak::CodeGenerator::LabelType::T_NEAR), das::LineInfo());
		addIEx("T_AUTO", "T_AUTO", int64_t(Xbyak::CodeGenerator::LabelType::T_AUTO), das::LineInfo());
	}
};

class Enumeration_Xbyak_CodeGenerator_AVXtype : public das::Enumeration {
public:
	Enumeration_Xbyak_CodeGenerator_AVXtype() : das::Enumeration("AVXtype") {
		external = true;
		cppName = "Xbyak::CodeGenerator::AVXtype";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("T_N1", "T_N1", int64_t(Xbyak::CodeGenerator::AVXtype::T_N1), das::LineInfo());
		addIEx("T_N2", "T_N2", int64_t(Xbyak::CodeGenerator::AVXtype::T_N2), das::LineInfo());
		addIEx("T_N4", "T_N4", int64_t(Xbyak::CodeGenerator::AVXtype::T_N4), das::LineInfo());
		addIEx("T_N8", "T_N8", int64_t(Xbyak::CodeGenerator::AVXtype::T_N8), das::LineInfo());
		addIEx("T_N16", "T_N16", int64_t(Xbyak::CodeGenerator::AVXtype::T_N16), das::LineInfo());
		addIEx("T_N32", "T_N32", int64_t(Xbyak::CodeGenerator::AVXtype::T_N32), das::LineInfo());
		addIEx("T_NX_MASK", "T_NX_MASK", int64_t(Xbyak::CodeGenerator::AVXtype::T_NX_MASK), das::LineInfo());
		addIEx("T_N_VL", "T_N_VL", int64_t(Xbyak::CodeGenerator::AVXtype::T_N_VL), das::LineInfo());
		addIEx("T_DUP", "T_DUP", int64_t(Xbyak::CodeGenerator::AVXtype::T_DUP), das::LineInfo());
		addIEx("T_66", "T_66", int64_t(Xbyak::CodeGenerator::AVXtype::T_66), das::LineInfo());
		addIEx("T_F3", "T_F3", int64_t(Xbyak::CodeGenerator::AVXtype::T_F3), das::LineInfo());
		addIEx("T_F2", "T_F2", int64_t(Xbyak::CodeGenerator::AVXtype::T_F2), das::LineInfo());
		addIEx("T_ER_R", "T_ER_R", int64_t(Xbyak::CodeGenerator::AVXtype::T_ER_R), das::LineInfo());
		addIEx("T_0F", "T_0F", int64_t(Xbyak::CodeGenerator::AVXtype::T_0F), das::LineInfo());
		addIEx("T_0F38", "T_0F38", int64_t(Xbyak::CodeGenerator::AVXtype::T_0F38), das::LineInfo());
		addIEx("T_0F3A", "T_0F3A", int64_t(Xbyak::CodeGenerator::AVXtype::T_0F3A), das::LineInfo());
		addIEx("T_L0", "T_L0", int64_t(Xbyak::CodeGenerator::AVXtype::T_L0), das::LineInfo());
		addIEx("T_L1", "T_L1", int64_t(Xbyak::CodeGenerator::AVXtype::T_L1), das::LineInfo());
		addIEx("T_W0", "T_W0", int64_t(Xbyak::CodeGenerator::AVXtype::T_W0), das::LineInfo());
		addIEx("T_W1", "T_W1", int64_t(Xbyak::CodeGenerator::AVXtype::T_W1), das::LineInfo());
		addIEx("T_EW0", "T_EW0", int64_t(Xbyak::CodeGenerator::AVXtype::T_EW0), das::LineInfo());
		addIEx("T_EW1", "T_EW1", int64_t(Xbyak::CodeGenerator::AVXtype::T_EW1), das::LineInfo());
		addIEx("T_YMM", "T_YMM", int64_t(Xbyak::CodeGenerator::AVXtype::T_YMM), das::LineInfo());
		addIEx("T_EVEX", "T_EVEX", int64_t(Xbyak::CodeGenerator::AVXtype::T_EVEX), das::LineInfo());
		addIEx("T_ER_X", "T_ER_X", int64_t(Xbyak::CodeGenerator::AVXtype::T_ER_X), das::LineInfo());
		addIEx("T_ER_Y", "T_ER_Y", int64_t(Xbyak::CodeGenerator::AVXtype::T_ER_Y), das::LineInfo());
		addIEx("T_ER_Z", "T_ER_Z", int64_t(Xbyak::CodeGenerator::AVXtype::T_ER_Z), das::LineInfo());
		addIEx("T_SAE_X", "T_SAE_X", int64_t(Xbyak::CodeGenerator::AVXtype::T_SAE_X), das::LineInfo());
		addIEx("T_SAE_Y", "T_SAE_Y", int64_t(Xbyak::CodeGenerator::AVXtype::T_SAE_Y), das::LineInfo());
		addIEx("T_SAE_Z", "T_SAE_Z", int64_t(Xbyak::CodeGenerator::AVXtype::T_SAE_Z), das::LineInfo());
		addIEx("T_MUST_EVEX", "T_MUST_EVEX", int64_t(Xbyak::CodeGenerator::AVXtype::T_MUST_EVEX), das::LineInfo());
		addIEx("T_B32", "T_B32", int64_t(Xbyak::CodeGenerator::AVXtype::T_B32), das::LineInfo());
		addIEx("T_B64", "T_B64", int64_t(Xbyak::CodeGenerator::AVXtype::T_B64), das::LineInfo());
		addIEx("T_B16", "T_B16", int64_t(Xbyak::CodeGenerator::AVXtype::T_B16), das::LineInfo());
		addIEx("T_M_K", "T_M_K", int64_t(Xbyak::CodeGenerator::AVXtype::T_M_K), das::LineInfo());
		addIEx("T_VSIB", "T_VSIB", int64_t(Xbyak::CodeGenerator::AVXtype::T_VSIB), das::LineInfo());
		addIEx("T_MEM_EVEX", "T_MEM_EVEX", int64_t(Xbyak::CodeGenerator::AVXtype::T_MEM_EVEX), das::LineInfo());
		addIEx("T_FP16", "T_FP16", int64_t(Xbyak::CodeGenerator::AVXtype::T_FP16), das::LineInfo());
		addIEx("T_MAP5", "T_MAP5", int64_t(Xbyak::CodeGenerator::AVXtype::T_MAP5), das::LineInfo());
		addIEx("T_MAP6", "T_MAP6", int64_t(Xbyak::CodeGenerator::AVXtype::T_MAP6), das::LineInfo());
		addIEx("T_XXX", "T_XXX", int64_t(Xbyak::CodeGenerator::AVXtype::T_XXX), das::LineInfo());
	}
};

