// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

#include "daScript/misc/platform.h"
#include "daScript/ast/ast.h"
#include "daScript/ast/ast_interop.h"
#include "daScript/ast/ast_handle.h"
#include "daScript/ast/ast_typefactory_bind.h"
#include "daScript/simulate/bind_enum.h"
#include "dasXBYAK.h"
#include "need_dasXBYAK.h"
namespace das {
#include "dasXBYAK.func.aot.decl.inc"
void Module_dasXBYAK::initFunctions_20() {
	using _method_1857 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtps2uqq >;
	addExtern<DAS_CALL_METHOD(_method_1857)>(*this,lib,"vcvtps2uqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtps2uqq >::invoke")
		->args({"self","x","op"});
	using _method_1858 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtqq2pd >;
	addExtern<DAS_CALL_METHOD(_method_1858)>(*this,lib,"vcvtqq2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtqq2pd >::invoke")
		->args({"self","x","op"});
	using _method_1859 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtqq2ph >;
	addExtern<DAS_CALL_METHOD(_method_1859)>(*this,lib,"vcvtqq2ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtqq2ph >::invoke")
		->args({"self","x","op"});
	using _method_1860 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtqq2ps >;
	addExtern<DAS_CALL_METHOD(_method_1860)>(*this,lib,"vcvtqq2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtqq2ps >::invoke")
		->args({"self","x","op"});
	using _method_1861 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtsd2sh >;
	addExtern<DAS_CALL_METHOD(_method_1861)>(*this,lib,"vcvtsd2sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtsd2sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1862 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtsd2usi >;
	addExtern<DAS_CALL_METHOD(_method_1862)>(*this,lib,"vcvtsd2usi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtsd2usi >::invoke")
		->args({"self","r","op"});
	using _method_1863 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtsh2sd >;
	addExtern<DAS_CALL_METHOD(_method_1863)>(*this,lib,"vcvtsh2sd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtsh2sd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1864 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtsh2si >;
	addExtern<DAS_CALL_METHOD(_method_1864)>(*this,lib,"vcvtsh2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtsh2si >::invoke")
		->args({"self","r","op"});
	using _method_1865 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtsh2ss >;
	addExtern<DAS_CALL_METHOD(_method_1865)>(*this,lib,"vcvtsh2ss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtsh2ss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1866 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtsh2usi >;
	addExtern<DAS_CALL_METHOD(_method_1866)>(*this,lib,"vcvtsh2usi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtsh2usi >::invoke")
		->args({"self","r","op"});
	using _method_1867 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtsi2sh >;
	addExtern<DAS_CALL_METHOD(_method_1867)>(*this,lib,"vcvtsi2sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtsi2sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1868 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtss2sh >;
	addExtern<DAS_CALL_METHOD(_method_1868)>(*this,lib,"vcvtss2sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtss2sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1869 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtss2usi >;
	addExtern<DAS_CALL_METHOD(_method_1869)>(*this,lib,"vcvtss2usi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtss2usi >::invoke")
		->args({"self","r","op"});
	using _method_1870 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttpd2qq >;
	addExtern<DAS_CALL_METHOD(_method_1870)>(*this,lib,"vcvttpd2qq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttpd2qq >::invoke")
		->args({"self","x","op"});
	using _method_1871 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttpd2udq >;
	addExtern<DAS_CALL_METHOD(_method_1871)>(*this,lib,"vcvttpd2udq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttpd2udq >::invoke")
		->args({"self","x","op"});
	using _method_1872 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttpd2uqq >;
	addExtern<DAS_CALL_METHOD(_method_1872)>(*this,lib,"vcvttpd2uqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttpd2uqq >::invoke")
		->args({"self","x","op"});
	using _method_1873 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttph2dq >;
	addExtern<DAS_CALL_METHOD(_method_1873)>(*this,lib,"vcvttph2dq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttph2dq >::invoke")
		->args({"self","x","op"});
	using _method_1874 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttph2qq >;
	addExtern<DAS_CALL_METHOD(_method_1874)>(*this,lib,"vcvttph2qq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttph2qq >::invoke")
		->args({"self","x","op"});
	using _method_1875 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttph2udq >;
	addExtern<DAS_CALL_METHOD(_method_1875)>(*this,lib,"vcvttph2udq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttph2udq >::invoke")
		->args({"self","x","op"});
	using _method_1876 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttph2uqq >;
	addExtern<DAS_CALL_METHOD(_method_1876)>(*this,lib,"vcvttph2uqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttph2uqq >::invoke")
		->args({"self","x","op"});
	using _method_1877 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttph2uw >;
	addExtern<DAS_CALL_METHOD(_method_1877)>(*this,lib,"vcvttph2uw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttph2uw >::invoke")
		->args({"self","x","op"});
	using _method_1878 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttph2w >;
	addExtern<DAS_CALL_METHOD(_method_1878)>(*this,lib,"vcvttph2w",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttph2w >::invoke")
		->args({"self","x","op"});
	using _method_1879 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttps2qq >;
	addExtern<DAS_CALL_METHOD(_method_1879)>(*this,lib,"vcvttps2qq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttps2qq >::invoke")
		->args({"self","x","op"});
	using _method_1880 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttps2udq >;
	addExtern<DAS_CALL_METHOD(_method_1880)>(*this,lib,"vcvttps2udq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttps2udq >::invoke")
		->args({"self","x","op"});
	using _method_1881 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttps2uqq >;
	addExtern<DAS_CALL_METHOD(_method_1881)>(*this,lib,"vcvttps2uqq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttps2uqq >::invoke")
		->args({"self","x","op"});
	using _method_1882 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttsd2usi >;
	addExtern<DAS_CALL_METHOD(_method_1882)>(*this,lib,"vcvttsd2usi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttsd2usi >::invoke")
		->args({"self","r","op"});
	using _method_1883 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttsh2si >;
	addExtern<DAS_CALL_METHOD(_method_1883)>(*this,lib,"vcvttsh2si",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttsh2si >::invoke")
		->args({"self","r","op"});
	using _method_1884 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttsh2usi >;
	addExtern<DAS_CALL_METHOD(_method_1884)>(*this,lib,"vcvttsh2usi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttsh2usi >::invoke")
		->args({"self","r","op"});
	using _method_1885 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvttss2usi >;
	addExtern<DAS_CALL_METHOD(_method_1885)>(*this,lib,"vcvttss2usi",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvttss2usi >::invoke")
		->args({"self","r","op"});
	using _method_1886 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtudq2pd >;
	addExtern<DAS_CALL_METHOD(_method_1886)>(*this,lib,"vcvtudq2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtudq2pd >::invoke")
		->args({"self","x","op"});
	using _method_1887 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtudq2ph >;
	addExtern<DAS_CALL_METHOD(_method_1887)>(*this,lib,"vcvtudq2ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtudq2ph >::invoke")
		->args({"self","x","op"});
	using _method_1888 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtudq2ps >;
	addExtern<DAS_CALL_METHOD(_method_1888)>(*this,lib,"vcvtudq2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtudq2ps >::invoke")
		->args({"self","x","op"});
	using _method_1889 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtuqq2pd >;
	addExtern<DAS_CALL_METHOD(_method_1889)>(*this,lib,"vcvtuqq2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtuqq2pd >::invoke")
		->args({"self","x","op"});
	using _method_1890 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtuqq2ph >;
	addExtern<DAS_CALL_METHOD(_method_1890)>(*this,lib,"vcvtuqq2ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtuqq2ph >::invoke")
		->args({"self","x","op"});
	using _method_1891 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtuqq2ps >;
	addExtern<DAS_CALL_METHOD(_method_1891)>(*this,lib,"vcvtuqq2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtuqq2ps >::invoke")
		->args({"self","x","op"});
	using _method_1892 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtusi2sd >;
	addExtern<DAS_CALL_METHOD(_method_1892)>(*this,lib,"vcvtusi2sd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtusi2sd >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1893 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtusi2sh >;
	addExtern<DAS_CALL_METHOD(_method_1893)>(*this,lib,"vcvtusi2sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtusi2sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1894 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtusi2ss >;
	addExtern<DAS_CALL_METHOD(_method_1894)>(*this,lib,"vcvtusi2ss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtusi2ss >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1895 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtuw2ph >;
	addExtern<DAS_CALL_METHOD(_method_1895)>(*this,lib,"vcvtuw2ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtuw2ph >::invoke")
		->args({"self","x","op"});
	using _method_1896 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vcvtw2ph >;
	addExtern<DAS_CALL_METHOD(_method_1896)>(*this,lib,"vcvtw2ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vcvtw2ph >::invoke")
		->args({"self","x","op"});
	using _method_1897 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vdbpsadbw >;
	addExtern<DAS_CALL_METHOD(_method_1897)>(*this,lib,"vdbpsadbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vdbpsadbw >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1898 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vdivph >;
	addExtern<DAS_CALL_METHOD(_method_1898)>(*this,lib,"vdivph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vdivph >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1899 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vdivsh >;
	addExtern<DAS_CALL_METHOD(_method_1899)>(*this,lib,"vdivsh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vdivsh >::invoke")
		->args({"self","xmm","op1","op2"});
	using _method_1900 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vdpbf16ps >;
	addExtern<DAS_CALL_METHOD(_method_1900)>(*this,lib,"vdpbf16ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vdpbf16ps >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1901 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vexp2pd >;
	addExtern<DAS_CALL_METHOD(_method_1901)>(*this,lib,"vexp2pd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vexp2pd >::invoke")
		->args({"self","z","op"});
	using _method_1902 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vexp2ps >;
	addExtern<DAS_CALL_METHOD(_method_1902)>(*this,lib,"vexp2ps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Zmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vexp2ps >::invoke")
		->args({"self","z","op"});
	using _method_1903 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vexpandpd >;
	addExtern<DAS_CALL_METHOD(_method_1903)>(*this,lib,"vexpandpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vexpandpd >::invoke")
		->args({"self","x","op"});
	using _method_1904 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vexpandps >;
	addExtern<DAS_CALL_METHOD(_method_1904)>(*this,lib,"vexpandps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vexpandps >::invoke")
		->args({"self","x","op"});
	using _method_1905 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Ymm &,unsigned char),&Xbyak::CodeGenerator::vextractf32x4 >;
	addExtern<DAS_CALL_METHOD(_method_1905)>(*this,lib,"vextractf32x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Ymm &,unsigned char) , &Xbyak::CodeGenerator::vextractf32x4 >::invoke")
		->args({"self","op","r","imm"});
	using _method_1906 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Zmm &,unsigned char),&Xbyak::CodeGenerator::vextractf32x8 >;
	addExtern<DAS_CALL_METHOD(_method_1906)>(*this,lib,"vextractf32x8",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Zmm &,unsigned char) , &Xbyak::CodeGenerator::vextractf32x8 >::invoke")
		->args({"self","op","r","imm"});
	using _method_1907 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Ymm &,unsigned char),&Xbyak::CodeGenerator::vextractf64x2 >;
	addExtern<DAS_CALL_METHOD(_method_1907)>(*this,lib,"vextractf64x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Ymm &,unsigned char) , &Xbyak::CodeGenerator::vextractf64x2 >::invoke")
		->args({"self","op","r","imm"});
	using _method_1908 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Zmm &,unsigned char),&Xbyak::CodeGenerator::vextractf64x4 >;
	addExtern<DAS_CALL_METHOD(_method_1908)>(*this,lib,"vextractf64x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Zmm &,unsigned char) , &Xbyak::CodeGenerator::vextractf64x4 >::invoke")
		->args({"self","op","r","imm"});
	using _method_1909 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Ymm &,unsigned char),&Xbyak::CodeGenerator::vextracti32x4 >;
	addExtern<DAS_CALL_METHOD(_method_1909)>(*this,lib,"vextracti32x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Ymm &,unsigned char) , &Xbyak::CodeGenerator::vextracti32x4 >::invoke")
		->args({"self","op","r","imm"});
	using _method_1910 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Zmm &,unsigned char),&Xbyak::CodeGenerator::vextracti32x8 >;
	addExtern<DAS_CALL_METHOD(_method_1910)>(*this,lib,"vextracti32x8",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Zmm &,unsigned char) , &Xbyak::CodeGenerator::vextracti32x8 >::invoke")
		->args({"self","op","r","imm"});
	using _method_1911 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Ymm &,unsigned char),&Xbyak::CodeGenerator::vextracti64x2 >;
	addExtern<DAS_CALL_METHOD(_method_1911)>(*this,lib,"vextracti64x2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Ymm &,unsigned char) , &Xbyak::CodeGenerator::vextracti64x2 >::invoke")
		->args({"self","op","r","imm"});
	using _method_1912 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Zmm &,unsigned char),&Xbyak::CodeGenerator::vextracti64x4 >;
	addExtern<DAS_CALL_METHOD(_method_1912)>(*this,lib,"vextracti64x4",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Zmm &,unsigned char) , &Xbyak::CodeGenerator::vextracti64x4 >::invoke")
		->args({"self","op","r","imm"});
	using _method_1913 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfcmaddcph >;
	addExtern<DAS_CALL_METHOD(_method_1913)>(*this,lib,"vfcmaddcph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfcmaddcph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1914 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfcmulcph >;
	addExtern<DAS_CALL_METHOD(_method_1914)>(*this,lib,"vfcmulcph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfcmulcph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1915 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfixupimmpd >;
	addExtern<DAS_CALL_METHOD(_method_1915)>(*this,lib,"vfixupimmpd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfixupimmpd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1916 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfixupimmps >;
	addExtern<DAS_CALL_METHOD(_method_1916)>(*this,lib,"vfixupimmps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfixupimmps >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1917 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfixupimmsd >;
	addExtern<DAS_CALL_METHOD(_method_1917)>(*this,lib,"vfixupimmsd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfixupimmsd >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1918 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfixupimmss >;
	addExtern<DAS_CALL_METHOD(_method_1918)>(*this,lib,"vfixupimmss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfixupimmss >::invoke")
		->args({"self","x1","x2","op","imm"});
	using _method_1919 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmadd132ph >;
	addExtern<DAS_CALL_METHOD(_method_1919)>(*this,lib,"vfmadd132ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmadd132ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1920 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmadd132sh >;
	addExtern<DAS_CALL_METHOD(_method_1920)>(*this,lib,"vfmadd132sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmadd132sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1921 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmadd213ph >;
	addExtern<DAS_CALL_METHOD(_method_1921)>(*this,lib,"vfmadd213ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmadd213ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1922 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmadd213sh >;
	addExtern<DAS_CALL_METHOD(_method_1922)>(*this,lib,"vfmadd213sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmadd213sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1923 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmadd231ph >;
	addExtern<DAS_CALL_METHOD(_method_1923)>(*this,lib,"vfmadd231ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmadd231ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1924 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmadd231sh >;
	addExtern<DAS_CALL_METHOD(_method_1924)>(*this,lib,"vfmadd231sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmadd231sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1925 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmaddcph >;
	addExtern<DAS_CALL_METHOD(_method_1925)>(*this,lib,"vfmaddcph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmaddcph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1926 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmaddsub132ph >;
	addExtern<DAS_CALL_METHOD(_method_1926)>(*this,lib,"vfmaddsub132ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmaddsub132ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1927 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmaddsub213ph >;
	addExtern<DAS_CALL_METHOD(_method_1927)>(*this,lib,"vfmaddsub213ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmaddsub213ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1928 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmaddsub231ph >;
	addExtern<DAS_CALL_METHOD(_method_1928)>(*this,lib,"vfmaddsub231ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmaddsub231ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1929 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsub132ph >;
	addExtern<DAS_CALL_METHOD(_method_1929)>(*this,lib,"vfmsub132ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsub132ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1930 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsub132sh >;
	addExtern<DAS_CALL_METHOD(_method_1930)>(*this,lib,"vfmsub132sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsub132sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1931 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsub213ph >;
	addExtern<DAS_CALL_METHOD(_method_1931)>(*this,lib,"vfmsub213ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsub213ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1932 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsub213sh >;
	addExtern<DAS_CALL_METHOD(_method_1932)>(*this,lib,"vfmsub213sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsub213sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1933 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsub231ph >;
	addExtern<DAS_CALL_METHOD(_method_1933)>(*this,lib,"vfmsub231ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsub231ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1934 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsub231sh >;
	addExtern<DAS_CALL_METHOD(_method_1934)>(*this,lib,"vfmsub231sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsub231sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1935 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsubadd132ph >;
	addExtern<DAS_CALL_METHOD(_method_1935)>(*this,lib,"vfmsubadd132ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsubadd132ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1936 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsubadd213ph >;
	addExtern<DAS_CALL_METHOD(_method_1936)>(*this,lib,"vfmsubadd213ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsubadd213ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1937 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmsubadd231ph >;
	addExtern<DAS_CALL_METHOD(_method_1937)>(*this,lib,"vfmsubadd231ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmsubadd231ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1938 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfmulcph >;
	addExtern<DAS_CALL_METHOD(_method_1938)>(*this,lib,"vfmulcph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfmulcph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1939 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmadd132ph >;
	addExtern<DAS_CALL_METHOD(_method_1939)>(*this,lib,"vfnmadd132ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmadd132ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1940 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmadd132sh >;
	addExtern<DAS_CALL_METHOD(_method_1940)>(*this,lib,"vfnmadd132sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmadd132sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1941 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmadd213ph >;
	addExtern<DAS_CALL_METHOD(_method_1941)>(*this,lib,"vfnmadd213ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmadd213ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1942 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmadd213sh >;
	addExtern<DAS_CALL_METHOD(_method_1942)>(*this,lib,"vfnmadd213sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmadd213sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1943 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmadd231ph >;
	addExtern<DAS_CALL_METHOD(_method_1943)>(*this,lib,"vfnmadd231ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmadd231ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1944 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmadd231sh >;
	addExtern<DAS_CALL_METHOD(_method_1944)>(*this,lib,"vfnmadd231sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmadd231sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1945 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmsub132ph >;
	addExtern<DAS_CALL_METHOD(_method_1945)>(*this,lib,"vfnmsub132ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmsub132ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1946 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmsub132sh >;
	addExtern<DAS_CALL_METHOD(_method_1946)>(*this,lib,"vfnmsub132sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmsub132sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1947 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmsub213ph >;
	addExtern<DAS_CALL_METHOD(_method_1947)>(*this,lib,"vfnmsub213ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmsub213ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1948 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmsub213sh >;
	addExtern<DAS_CALL_METHOD(_method_1948)>(*this,lib,"vfnmsub213sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmsub213sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1949 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmsub231ph >;
	addExtern<DAS_CALL_METHOD(_method_1949)>(*this,lib,"vfnmsub231ph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmsub231ph >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1950 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::vfnmsub231sh >;
	addExtern<DAS_CALL_METHOD(_method_1950)>(*this,lib,"vfnmsub231sh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::vfnmsub231sh >::invoke")
		->args({"self","x1","x2","op"});
	using _method_1951 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfpclasspd >;
	addExtern<DAS_CALL_METHOD(_method_1951)>(*this,lib,"vfpclasspd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfpclasspd >::invoke")
		->args({"self","k","op","imm"});
	using _method_1952 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfpclassph >;
	addExtern<DAS_CALL_METHOD(_method_1952)>(*this,lib,"vfpclassph",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfpclassph >::invoke")
		->args({"self","k","op","imm"});
	using _method_1953 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfpclassps >;
	addExtern<DAS_CALL_METHOD(_method_1953)>(*this,lib,"vfpclassps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfpclassps >::invoke")
		->args({"self","k","op","imm"});
	using _method_1954 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfpclasssd >;
	addExtern<DAS_CALL_METHOD(_method_1954)>(*this,lib,"vfpclasssd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfpclasssd >::invoke")
		->args({"self","k","op","imm"});
	using _method_1955 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfpclasssh >;
	addExtern<DAS_CALL_METHOD(_method_1955)>(*this,lib,"vfpclasssh",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfpclasssh >::invoke")
		->args({"self","k","op","imm"});
	using _method_1956 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::vfpclassss >;
	addExtern<DAS_CALL_METHOD(_method_1956)>(*this,lib,"vfpclassss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Opmask &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::vfpclassss >::invoke")
		->args({"self","k","op","imm"});
}
}

