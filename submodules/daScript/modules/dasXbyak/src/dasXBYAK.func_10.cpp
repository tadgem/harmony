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
void Module_dasXBYAK::initFunctions_10() {
	using _method_857 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pminud >;
	addExtern<DAS_CALL_METHOD(_method_857)>(*this,lib,"pminud",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pminud >::invoke")
		->args({"self","xmm","op"});
	using _method_858 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pminuw >;
	addExtern<DAS_CALL_METHOD(_method_858)>(*this,lib,"pminuw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pminuw >::invoke")
		->args({"self","xmm","op"});
	using _method_859 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Mmx &),&Xbyak::CodeGenerator::pmovmskb >;
	addExtern<DAS_CALL_METHOD(_method_859)>(*this,lib,"pmovmskb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Mmx &) , &Xbyak::CodeGenerator::pmovmskb >::invoke")
		->args({"self","reg","mmx"});
	using _method_860 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovsxbd >;
	addExtern<DAS_CALL_METHOD(_method_860)>(*this,lib,"pmovsxbd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovsxbd >::invoke")
		->args({"self","xmm","op"});
	using _method_861 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovsxbq >;
	addExtern<DAS_CALL_METHOD(_method_861)>(*this,lib,"pmovsxbq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovsxbq >::invoke")
		->args({"self","xmm","op"});
	using _method_862 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovsxbw >;
	addExtern<DAS_CALL_METHOD(_method_862)>(*this,lib,"pmovsxbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovsxbw >::invoke")
		->args({"self","xmm","op"});
	using _method_863 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovsxdq >;
	addExtern<DAS_CALL_METHOD(_method_863)>(*this,lib,"pmovsxdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovsxdq >::invoke")
		->args({"self","xmm","op"});
	using _method_864 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovsxwd >;
	addExtern<DAS_CALL_METHOD(_method_864)>(*this,lib,"pmovsxwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovsxwd >::invoke")
		->args({"self","xmm","op"});
	using _method_865 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovsxwq >;
	addExtern<DAS_CALL_METHOD(_method_865)>(*this,lib,"pmovsxwq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovsxwq >::invoke")
		->args({"self","xmm","op"});
	using _method_866 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovzxbd >;
	addExtern<DAS_CALL_METHOD(_method_866)>(*this,lib,"pmovzxbd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovzxbd >::invoke")
		->args({"self","xmm","op"});
	using _method_867 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovzxbq >;
	addExtern<DAS_CALL_METHOD(_method_867)>(*this,lib,"pmovzxbq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovzxbq >::invoke")
		->args({"self","xmm","op"});
	using _method_868 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovzxbw >;
	addExtern<DAS_CALL_METHOD(_method_868)>(*this,lib,"pmovzxbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovzxbw >::invoke")
		->args({"self","xmm","op"});
	using _method_869 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovzxdq >;
	addExtern<DAS_CALL_METHOD(_method_869)>(*this,lib,"pmovzxdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovzxdq >::invoke")
		->args({"self","xmm","op"});
	using _method_870 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovzxwd >;
	addExtern<DAS_CALL_METHOD(_method_870)>(*this,lib,"pmovzxwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovzxwd >::invoke")
		->args({"self","xmm","op"});
	using _method_871 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmovzxwq >;
	addExtern<DAS_CALL_METHOD(_method_871)>(*this,lib,"pmovzxwq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmovzxwq >::invoke")
		->args({"self","xmm","op"});
	using _method_872 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmuldq >;
	addExtern<DAS_CALL_METHOD(_method_872)>(*this,lib,"pmuldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmuldq >::invoke")
		->args({"self","xmm","op"});
	using _method_873 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmulhrsw >;
	addExtern<DAS_CALL_METHOD(_method_873)>(*this,lib,"pmulhrsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmulhrsw >::invoke")
		->args({"self","mmx","op"});
	using _method_874 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmulhuw >;
	addExtern<DAS_CALL_METHOD(_method_874)>(*this,lib,"pmulhuw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmulhuw >::invoke")
		->args({"self","mmx","op"});
	using _method_875 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmulhw >;
	addExtern<DAS_CALL_METHOD(_method_875)>(*this,lib,"pmulhw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmulhw >::invoke")
		->args({"self","mmx","op"});
	using _method_876 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmulld >;
	addExtern<DAS_CALL_METHOD(_method_876)>(*this,lib,"pmulld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmulld >::invoke")
		->args({"self","xmm","op"});
	using _method_877 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmullw >;
	addExtern<DAS_CALL_METHOD(_method_877)>(*this,lib,"pmullw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmullw >::invoke")
		->args({"self","mmx","op"});
	using _method_878 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pmuludq >;
	addExtern<DAS_CALL_METHOD(_method_878)>(*this,lib,"pmuludq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pmuludq >::invoke")
		->args({"self","mmx","op"});
	using _method_879 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &),&Xbyak::CodeGenerator::popcnt >;
	addExtern<DAS_CALL_METHOD(_method_879)>(*this,lib,"popcnt",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::popcnt >::invoke")
		->args({"self","reg","op"});
	using _method_880 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::popf >;
	addExtern<DAS_CALL_METHOD(_method_880)>(*this,lib,"popf",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::popf >::invoke")
		->args({"self"});
	using _method_881 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::por >;
	addExtern<DAS_CALL_METHOD(_method_881)>(*this,lib,"por",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::por >::invoke")
		->args({"self","mmx","op"});
	using _method_882 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::prefetchnta >;
	addExtern<DAS_CALL_METHOD(_method_882)>(*this,lib,"prefetchnta",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::prefetchnta >::invoke")
		->args({"self","addr"});
	using _method_883 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::prefetcht0 >;
	addExtern<DAS_CALL_METHOD(_method_883)>(*this,lib,"prefetcht0",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::prefetcht0 >::invoke")
		->args({"self","addr"});
	using _method_884 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::prefetcht1 >;
	addExtern<DAS_CALL_METHOD(_method_884)>(*this,lib,"prefetcht1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::prefetcht1 >::invoke")
		->args({"self","addr"});
	using _method_885 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::prefetcht2 >;
	addExtern<DAS_CALL_METHOD(_method_885)>(*this,lib,"prefetcht2",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::prefetcht2 >::invoke")
		->args({"self","addr"});
	using _method_886 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::prefetchw >;
	addExtern<DAS_CALL_METHOD(_method_886)>(*this,lib,"prefetchw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::prefetchw >::invoke")
		->args({"self","addr"});
	using _method_887 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &),&Xbyak::CodeGenerator::prefetchwt1 >;
	addExtern<DAS_CALL_METHOD(_method_887)>(*this,lib,"prefetchwt1",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Address &) , &Xbyak::CodeGenerator::prefetchwt1 >::invoke")
		->args({"self","addr"});
	using _method_888 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psadbw >;
	addExtern<DAS_CALL_METHOD(_method_888)>(*this,lib,"psadbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psadbw >::invoke")
		->args({"self","mmx","op"});
	using _method_889 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pshufb >;
	addExtern<DAS_CALL_METHOD(_method_889)>(*this,lib,"pshufb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pshufb >::invoke")
		->args({"self","mmx","op"});
	using _method_890 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::pshufd >;
	addExtern<DAS_CALL_METHOD(_method_890)>(*this,lib,"pshufd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::pshufd >::invoke")
		->args({"self","mmx","op","imm8"});
	using _method_891 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::pshufhw >;
	addExtern<DAS_CALL_METHOD(_method_891)>(*this,lib,"pshufhw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::pshufhw >::invoke")
		->args({"self","mmx","op","imm8"});
	using _method_892 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::pshuflw >;
	addExtern<DAS_CALL_METHOD(_method_892)>(*this,lib,"pshuflw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::pshuflw >::invoke")
		->args({"self","mmx","op","imm8"});
	using _method_893 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::pshufw >;
	addExtern<DAS_CALL_METHOD(_method_893)>(*this,lib,"pshufw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::pshufw >::invoke")
		->args({"self","mmx","op","imm8"});
	using _method_894 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psignb >;
	addExtern<DAS_CALL_METHOD(_method_894)>(*this,lib,"psignb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psignb >::invoke")
		->args({"self","mmx","op"});
	using _method_895 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psignd >;
	addExtern<DAS_CALL_METHOD(_method_895)>(*this,lib,"psignd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psignd >::invoke")
		->args({"self","mmx","op"});
	using _method_896 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psignw >;
	addExtern<DAS_CALL_METHOD(_method_896)>(*this,lib,"psignw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psignw >::invoke")
		->args({"self","mmx","op"});
	using _method_897 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pslld >;
	addExtern<DAS_CALL_METHOD(_method_897)>(*this,lib,"pslld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pslld >::invoke")
		->args({"self","mmx","op"});
	using _method_898 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int),&Xbyak::CodeGenerator::pslld >;
	addExtern<DAS_CALL_METHOD(_method_898)>(*this,lib,"pslld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int) , &Xbyak::CodeGenerator::pslld >::invoke")
		->args({"self","mmx","imm8"});
	using _method_899 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,int),&Xbyak::CodeGenerator::pslldq >;
	addExtern<DAS_CALL_METHOD(_method_899)>(*this,lib,"pslldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,int) , &Xbyak::CodeGenerator::pslldq >::invoke")
		->args({"self","xmm","imm8"});
	using _method_900 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psllq >;
	addExtern<DAS_CALL_METHOD(_method_900)>(*this,lib,"psllq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psllq >::invoke")
		->args({"self","mmx","op"});
	using _method_901 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int),&Xbyak::CodeGenerator::psllq >;
	addExtern<DAS_CALL_METHOD(_method_901)>(*this,lib,"psllq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int) , &Xbyak::CodeGenerator::psllq >::invoke")
		->args({"self","mmx","imm8"});
	using _method_902 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psllw >;
	addExtern<DAS_CALL_METHOD(_method_902)>(*this,lib,"psllw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psllw >::invoke")
		->args({"self","mmx","op"});
	using _method_903 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int),&Xbyak::CodeGenerator::psllw >;
	addExtern<DAS_CALL_METHOD(_method_903)>(*this,lib,"psllw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int) , &Xbyak::CodeGenerator::psllw >::invoke")
		->args({"self","mmx","imm8"});
	using _method_904 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psrad >;
	addExtern<DAS_CALL_METHOD(_method_904)>(*this,lib,"psrad",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psrad >::invoke")
		->args({"self","mmx","op"});
	using _method_905 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int),&Xbyak::CodeGenerator::psrad >;
	addExtern<DAS_CALL_METHOD(_method_905)>(*this,lib,"psrad",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int) , &Xbyak::CodeGenerator::psrad >::invoke")
		->args({"self","mmx","imm8"});
	using _method_906 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psraw >;
	addExtern<DAS_CALL_METHOD(_method_906)>(*this,lib,"psraw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psraw >::invoke")
		->args({"self","mmx","op"});
	using _method_907 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int),&Xbyak::CodeGenerator::psraw >;
	addExtern<DAS_CALL_METHOD(_method_907)>(*this,lib,"psraw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int) , &Xbyak::CodeGenerator::psraw >::invoke")
		->args({"self","mmx","imm8"});
	using _method_908 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psrld >;
	addExtern<DAS_CALL_METHOD(_method_908)>(*this,lib,"psrld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psrld >::invoke")
		->args({"self","mmx","op"});
	using _method_909 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int),&Xbyak::CodeGenerator::psrld >;
	addExtern<DAS_CALL_METHOD(_method_909)>(*this,lib,"psrld",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int) , &Xbyak::CodeGenerator::psrld >::invoke")
		->args({"self","mmx","imm8"});
	using _method_910 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,int),&Xbyak::CodeGenerator::psrldq >;
	addExtern<DAS_CALL_METHOD(_method_910)>(*this,lib,"psrldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,int) , &Xbyak::CodeGenerator::psrldq >::invoke")
		->args({"self","xmm","imm8"});
	using _method_911 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psrlq >;
	addExtern<DAS_CALL_METHOD(_method_911)>(*this,lib,"psrlq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psrlq >::invoke")
		->args({"self","mmx","op"});
	using _method_912 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int),&Xbyak::CodeGenerator::psrlq >;
	addExtern<DAS_CALL_METHOD(_method_912)>(*this,lib,"psrlq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int) , &Xbyak::CodeGenerator::psrlq >::invoke")
		->args({"self","mmx","imm8"});
	using _method_913 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psrlw >;
	addExtern<DAS_CALL_METHOD(_method_913)>(*this,lib,"psrlw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psrlw >::invoke")
		->args({"self","mmx","op"});
	using _method_914 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int),&Xbyak::CodeGenerator::psrlw >;
	addExtern<DAS_CALL_METHOD(_method_914)>(*this,lib,"psrlw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,int) , &Xbyak::CodeGenerator::psrlw >::invoke")
		->args({"self","mmx","imm8"});
	using _method_915 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psubb >;
	addExtern<DAS_CALL_METHOD(_method_915)>(*this,lib,"psubb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psubb >::invoke")
		->args({"self","mmx","op"});
	using _method_916 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psubd >;
	addExtern<DAS_CALL_METHOD(_method_916)>(*this,lib,"psubd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psubd >::invoke")
		->args({"self","mmx","op"});
	using _method_917 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psubq >;
	addExtern<DAS_CALL_METHOD(_method_917)>(*this,lib,"psubq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psubq >::invoke")
		->args({"self","mmx","op"});
	using _method_918 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psubsb >;
	addExtern<DAS_CALL_METHOD(_method_918)>(*this,lib,"psubsb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psubsb >::invoke")
		->args({"self","mmx","op"});
	using _method_919 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psubsw >;
	addExtern<DAS_CALL_METHOD(_method_919)>(*this,lib,"psubsw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psubsw >::invoke")
		->args({"self","mmx","op"});
	using _method_920 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psubusb >;
	addExtern<DAS_CALL_METHOD(_method_920)>(*this,lib,"psubusb",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psubusb >::invoke")
		->args({"self","mmx","op"});
	using _method_921 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psubusw >;
	addExtern<DAS_CALL_METHOD(_method_921)>(*this,lib,"psubusw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psubusw >::invoke")
		->args({"self","mmx","op"});
	using _method_922 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::psubw >;
	addExtern<DAS_CALL_METHOD(_method_922)>(*this,lib,"psubw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::psubw >::invoke")
		->args({"self","mmx","op"});
	using _method_923 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::ptest >;
	addExtern<DAS_CALL_METHOD(_method_923)>(*this,lib,"ptest",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::ptest >::invoke")
		->args({"self","xmm","op"});
	using _method_924 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::punpckhbw >;
	addExtern<DAS_CALL_METHOD(_method_924)>(*this,lib,"punpckhbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::punpckhbw >::invoke")
		->args({"self","mmx","op"});
	using _method_925 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::punpckhdq >;
	addExtern<DAS_CALL_METHOD(_method_925)>(*this,lib,"punpckhdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::punpckhdq >::invoke")
		->args({"self","mmx","op"});
	using _method_926 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::punpckhqdq >;
	addExtern<DAS_CALL_METHOD(_method_926)>(*this,lib,"punpckhqdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::punpckhqdq >::invoke")
		->args({"self","xmm","op"});
	using _method_927 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::punpckhwd >;
	addExtern<DAS_CALL_METHOD(_method_927)>(*this,lib,"punpckhwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::punpckhwd >::invoke")
		->args({"self","mmx","op"});
	using _method_928 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::punpcklbw >;
	addExtern<DAS_CALL_METHOD(_method_928)>(*this,lib,"punpcklbw",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::punpcklbw >::invoke")
		->args({"self","mmx","op"});
	using _method_929 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::punpckldq >;
	addExtern<DAS_CALL_METHOD(_method_929)>(*this,lib,"punpckldq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::punpckldq >::invoke")
		->args({"self","mmx","op"});
	using _method_930 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::punpcklqdq >;
	addExtern<DAS_CALL_METHOD(_method_930)>(*this,lib,"punpcklqdq",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::punpcklqdq >::invoke")
		->args({"self","xmm","op"});
	using _method_931 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::punpcklwd >;
	addExtern<DAS_CALL_METHOD(_method_931)>(*this,lib,"punpcklwd",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::punpcklwd >::invoke")
		->args({"self","mmx","op"});
	using _method_932 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::pushf >;
	addExtern<DAS_CALL_METHOD(_method_932)>(*this,lib,"pushf",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::pushf >::invoke")
		->args({"self"});
	using _method_933 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &),&Xbyak::CodeGenerator::pxor >;
	addExtern<DAS_CALL_METHOD(_method_933)>(*this,lib,"pxor",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Mmx &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::pxor >::invoke")
		->args({"self","mmx","op"});
	using _method_934 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::rcl >;
	addExtern<DAS_CALL_METHOD(_method_934)>(*this,lib,"rcl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::rcl >::invoke")
		->args({"self","op","_cl"});
	using _method_935 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int),&Xbyak::CodeGenerator::rcl >;
	addExtern<DAS_CALL_METHOD(_method_935)>(*this,lib,"rcl",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::rcl >::invoke")
		->args({"self","op","imm"});
	using _method_936 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::rcpps >;
	addExtern<DAS_CALL_METHOD(_method_936)>(*this,lib,"rcpps",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::rcpps >::invoke")
		->args({"self","xmm","op"});
	using _method_937 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &),&Xbyak::CodeGenerator::rcpss >;
	addExtern<DAS_CALL_METHOD(_method_937)>(*this,lib,"rcpss",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Xmm &,const Xbyak::Operand &) , &Xbyak::CodeGenerator::rcpss >::invoke")
		->args({"self","xmm","op"});
	using _method_938 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::rcr >;
	addExtern<DAS_CALL_METHOD(_method_938)>(*this,lib,"rcr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::rcr >::invoke")
		->args({"self","op","_cl"});
	using _method_939 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int),&Xbyak::CodeGenerator::rcr >;
	addExtern<DAS_CALL_METHOD(_method_939)>(*this,lib,"rcr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::rcr >::invoke")
		->args({"self","op","imm"});
	using _method_940 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::rdmsr >;
	addExtern<DAS_CALL_METHOD(_method_940)>(*this,lib,"rdmsr",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::rdmsr >::invoke")
		->args({"self"});
	using _method_941 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::rdpmc >;
	addExtern<DAS_CALL_METHOD(_method_941)>(*this,lib,"rdpmc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::rdpmc >::invoke")
		->args({"self"});
	using _method_942 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &),&Xbyak::CodeGenerator::rdrand >;
	addExtern<DAS_CALL_METHOD(_method_942)>(*this,lib,"rdrand",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &) , &Xbyak::CodeGenerator::rdrand >::invoke")
		->args({"self","r"});
	using _method_943 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &),&Xbyak::CodeGenerator::rdseed >;
	addExtern<DAS_CALL_METHOD(_method_943)>(*this,lib,"rdseed",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg &) , &Xbyak::CodeGenerator::rdseed >::invoke")
		->args({"self","r"});
	using _method_944 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::rdtsc >;
	addExtern<DAS_CALL_METHOD(_method_944)>(*this,lib,"rdtsc",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::rdtsc >::invoke")
		->args({"self"});
	using _method_945 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::rdtscp >;
	addExtern<DAS_CALL_METHOD(_method_945)>(*this,lib,"rdtscp",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::rdtscp >::invoke")
		->args({"self"});
	using _method_946 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::rep >;
	addExtern<DAS_CALL_METHOD(_method_946)>(*this,lib,"rep",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::rep >::invoke")
		->args({"self"});
	using _method_947 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::repe >;
	addExtern<DAS_CALL_METHOD(_method_947)>(*this,lib,"repe",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::repe >::invoke")
		->args({"self"});
	using _method_948 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::repne >;
	addExtern<DAS_CALL_METHOD(_method_948)>(*this,lib,"repne",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::repne >::invoke")
		->args({"self"});
	using _method_949 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::repnz >;
	addExtern<DAS_CALL_METHOD(_method_949)>(*this,lib,"repnz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::repnz >::invoke")
		->args({"self"});
	using _method_950 = das::das_call_member< void (Xbyak::CodeGenerator::*)(),&Xbyak::CodeGenerator::repz >;
	addExtern<DAS_CALL_METHOD(_method_950)>(*this,lib,"repz",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)() , &Xbyak::CodeGenerator::repz >::invoke")
		->args({"self"});
	using _method_951 = das::das_call_member< void (Xbyak::CodeGenerator::*)(int),&Xbyak::CodeGenerator::ret >;
	addExtern<DAS_CALL_METHOD(_method_951)>(*this,lib,"ret",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(int) , &Xbyak::CodeGenerator::ret >::invoke")
		->args({"self","imm"})
		->arg_init(1,make_smart<ExprConstInt>(0));
	using _method_952 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::rol >;
	addExtern<DAS_CALL_METHOD(_method_952)>(*this,lib,"rol",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::rol >::invoke")
		->args({"self","op","_cl"});
	using _method_953 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int),&Xbyak::CodeGenerator::rol >;
	addExtern<DAS_CALL_METHOD(_method_953)>(*this,lib,"rol",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::rol >::invoke")
		->args({"self","op","imm"});
	using _method_954 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &),&Xbyak::CodeGenerator::ror >;
	addExtern<DAS_CALL_METHOD(_method_954)>(*this,lib,"ror",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,const Xbyak::Reg8 &) , &Xbyak::CodeGenerator::ror >::invoke")
		->args({"self","op","_cl"});
	using _method_955 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int),&Xbyak::CodeGenerator::ror >;
	addExtern<DAS_CALL_METHOD(_method_955)>(*this,lib,"ror",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Operand &,int) , &Xbyak::CodeGenerator::ror >::invoke")
		->args({"self","op","imm"});
	using _method_956 = das::das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,unsigned char),&Xbyak::CodeGenerator::rorx >;
	addExtern<DAS_CALL_METHOD(_method_956)>(*this,lib,"rorx",SideEffects::worstDefault,"das_call_member< void (Xbyak::CodeGenerator::*)(const Xbyak::Reg32e &,const Xbyak::Operand &,unsigned char) , &Xbyak::CodeGenerator::rorx >::invoke")
		->args({"self","r","op","imm"});
}
}

