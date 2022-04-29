// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

template <> struct cast_arg<imnodes::IO::EmulateThreeButtonMouse> {
	static __forceinline const imnodes::IO::EmulateThreeButtonMouse & to ( Context & ctx, SimNode * node ) {
		vec4f res = node->eval(ctx);
		return * cast<imnodes::IO::EmulateThreeButtonMouse *>::to(res);
	}
};
template <> struct cast_arg<imnodes::IO::LinkDetachWithModifierClick> {
	static __forceinline const imnodes::IO::LinkDetachWithModifierClick & to ( Context & ctx, SimNode * node ) {
		vec4f res = node->eval(ctx);
		return * cast<imnodes::IO::LinkDetachWithModifierClick *>::to(res);
	}
};
template <> struct cast_arg<imnodes::IO> {
	static __forceinline const imnodes::IO & to ( Context & ctx, SimNode * node ) {
		vec4f res = node->eval(ctx);
		return * cast<imnodes::IO *>::to(res);
	}
};
template <> struct cast_arg<imnodes::Style> {
	static __forceinline const imnodes::Style & to ( Context & ctx, SimNode * node ) {
		vec4f res = node->eval(ctx);
		return * cast<imnodes::Style *>::to(res);
	}
};
