// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

unsigned char * _dasXBYAK_virtual_0_alloc(Xbyak::Allocator & self,size_t size) {
	return self.alloc(size);
}

void _dasXBYAK_virtual_1_free(Xbyak::Allocator & self,unsigned char * p) {
	self.free(p);
}

bool _dasXBYAK_virtual_2_useProtect(const Xbyak::Allocator & self) {
	return self.useProtect();
}

bool _dasXBYAK_static_3_protect(const Xbyak::CodeArray &,const void * addr,size_t size,int protectMode) {
	return Xbyak::CodeArray::protect(addr,size,protectMode);
}

unsigned char * _dasXBYAK_static_4_getAlignedAddress(const Xbyak::CodeArray &,unsigned char * addr,size_t alignedSize) {
	return Xbyak::CodeArray::getAlignedAddress(addr,alignedSize);
}

bool _dasXBYAK_static_5_isXMM_XMMorMEM(const Xbyak::CodeGenerator &,const Xbyak::Operand & op1,const Xbyak::Operand & op2) {
	return Xbyak::CodeGenerator::isXMM_XMMorMEM(op1,op2);
}

bool _dasXBYAK_static_6_isXMMorMMX_MEM(const Xbyak::CodeGenerator &,const Xbyak::Operand & op1,const Xbyak::Operand & op2) {
	return Xbyak::CodeGenerator::isXMMorMMX_MEM(op1,op2);
}

bool _dasXBYAK_static_7_isXMM_MMXorMEM(const Xbyak::CodeGenerator &,const Xbyak::Operand & op1,const Xbyak::Operand & op2) {
	return Xbyak::CodeGenerator::isXMM_MMXorMEM(op1,op2);
}

bool _dasXBYAK_static_8_isMMX_XMMorMEM(const Xbyak::CodeGenerator &,const Xbyak::Operand & op1,const Xbyak::Operand & op2) {
	return Xbyak::CodeGenerator::isMMX_XMMorMEM(op1,op2);
}

bool _dasXBYAK_static_9_isXMM_REG32orMEM(const Xbyak::CodeGenerator &,const Xbyak::Operand & op1,const Xbyak::Operand & op2) {
	return Xbyak::CodeGenerator::isXMM_REG32orMEM(op1,op2);
}

bool _dasXBYAK_static_10_isREG32_XMMorMEM(const Xbyak::CodeGenerator &,const Xbyak::Operand & op1,const Xbyak::Operand & op2) {
	return Xbyak::CodeGenerator::isREG32_XMMorMEM(op1,op2);
}

bool _dasXBYAK_static_11_isREG32_REG32orMEM(const Xbyak::CodeGenerator &,const Xbyak::Operand & op1,const Xbyak::Operand & op2) {
	return Xbyak::CodeGenerator::isREG32_REG32orMEM(op1,op2);
}

