// this file is generated via daScript automatic C++ binder
// all user modifications will be lost after this file is re-generated

class Enumeration_bgfx_fatal : public das::Enumeration {
public:
	Enumeration_bgfx_fatal() : das::Enumeration("bgfx_fatal") {
		external = true;
		cppName = "bgfx_fatal";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("DEBUG_CHECK", "BGFX_FATAL_DEBUG_CHECK", int64_t(bgfx_fatal::BGFX_FATAL_DEBUG_CHECK), das::LineInfo());
		addIEx("INVALID_SHADER", "BGFX_FATAL_INVALID_SHADER", int64_t(bgfx_fatal::BGFX_FATAL_INVALID_SHADER), das::LineInfo());
		addIEx("UNABLE_TO_INITIALIZE", "BGFX_FATAL_UNABLE_TO_INITIALIZE", int64_t(bgfx_fatal::BGFX_FATAL_UNABLE_TO_INITIALIZE), das::LineInfo());
		addIEx("UNABLE_TO_CREATE_TEXTURE", "BGFX_FATAL_UNABLE_TO_CREATE_TEXTURE", int64_t(bgfx_fatal::BGFX_FATAL_UNABLE_TO_CREATE_TEXTURE), das::LineInfo());
		addIEx("DEVICE_LOST", "BGFX_FATAL_DEVICE_LOST", int64_t(bgfx_fatal::BGFX_FATAL_DEVICE_LOST), das::LineInfo());
		addIEx("COUNT", "BGFX_FATAL_COUNT", int64_t(bgfx_fatal::BGFX_FATAL_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_renderer_type : public das::Enumeration {
public:
	Enumeration_bgfx_renderer_type() : das::Enumeration("bgfx_renderer_type") {
		external = true;
		cppName = "bgfx_renderer_type";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("NOOP", "BGFX_RENDERER_TYPE_NOOP", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_NOOP), das::LineInfo());
		addIEx("AGC", "BGFX_RENDERER_TYPE_AGC", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_AGC), das::LineInfo());
		addIEx("DIRECT3D9", "BGFX_RENDERER_TYPE_DIRECT3D9", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_DIRECT3D9), das::LineInfo());
		addIEx("DIRECT3D11", "BGFX_RENDERER_TYPE_DIRECT3D11", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_DIRECT3D11), das::LineInfo());
		addIEx("DIRECT3D12", "BGFX_RENDERER_TYPE_DIRECT3D12", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_DIRECT3D12), das::LineInfo());
		addIEx("GNM", "BGFX_RENDERER_TYPE_GNM", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_GNM), das::LineInfo());
		addIEx("METAL", "BGFX_RENDERER_TYPE_METAL", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_METAL), das::LineInfo());
		addIEx("NVN", "BGFX_RENDERER_TYPE_NVN", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_NVN), das::LineInfo());
		addIEx("OPENGLES", "BGFX_RENDERER_TYPE_OPENGLES", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_OPENGLES), das::LineInfo());
		addIEx("OPENGL", "BGFX_RENDERER_TYPE_OPENGL", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_OPENGL), das::LineInfo());
		addIEx("VULKAN", "BGFX_RENDERER_TYPE_VULKAN", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_VULKAN), das::LineInfo());
		addIEx("WEBGPU", "BGFX_RENDERER_TYPE_WEBGPU", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_WEBGPU), das::LineInfo());
		addIEx("COUNT", "BGFX_RENDERER_TYPE_COUNT", int64_t(bgfx_renderer_type::BGFX_RENDERER_TYPE_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_access : public das::Enumeration {
public:
	Enumeration_bgfx_access() : das::Enumeration("bgfx_access") {
		external = true;
		cppName = "bgfx_access";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("READ", "BGFX_ACCESS_READ", int64_t(bgfx_access::BGFX_ACCESS_READ), das::LineInfo());
		addIEx("WRITE", "BGFX_ACCESS_WRITE", int64_t(bgfx_access::BGFX_ACCESS_WRITE), das::LineInfo());
		addIEx("READWRITE", "BGFX_ACCESS_READWRITE", int64_t(bgfx_access::BGFX_ACCESS_READWRITE), das::LineInfo());
		addIEx("COUNT", "BGFX_ACCESS_COUNT", int64_t(bgfx_access::BGFX_ACCESS_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_attrib : public das::Enumeration {
public:
	Enumeration_bgfx_attrib() : das::Enumeration("bgfx_attrib") {
		external = true;
		cppName = "bgfx_attrib";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("POSITION", "BGFX_ATTRIB_POSITION", int64_t(bgfx_attrib::BGFX_ATTRIB_POSITION), das::LineInfo());
		addIEx("NORMAL", "BGFX_ATTRIB_NORMAL", int64_t(bgfx_attrib::BGFX_ATTRIB_NORMAL), das::LineInfo());
		addIEx("TANGENT", "BGFX_ATTRIB_TANGENT", int64_t(bgfx_attrib::BGFX_ATTRIB_TANGENT), das::LineInfo());
		addIEx("BITANGENT", "BGFX_ATTRIB_BITANGENT", int64_t(bgfx_attrib::BGFX_ATTRIB_BITANGENT), das::LineInfo());
		addIEx("COLOR0", "BGFX_ATTRIB_COLOR0", int64_t(bgfx_attrib::BGFX_ATTRIB_COLOR0), das::LineInfo());
		addIEx("COLOR1", "BGFX_ATTRIB_COLOR1", int64_t(bgfx_attrib::BGFX_ATTRIB_COLOR1), das::LineInfo());
		addIEx("COLOR2", "BGFX_ATTRIB_COLOR2", int64_t(bgfx_attrib::BGFX_ATTRIB_COLOR2), das::LineInfo());
		addIEx("COLOR3", "BGFX_ATTRIB_COLOR3", int64_t(bgfx_attrib::BGFX_ATTRIB_COLOR3), das::LineInfo());
		addIEx("INDICES", "BGFX_ATTRIB_INDICES", int64_t(bgfx_attrib::BGFX_ATTRIB_INDICES), das::LineInfo());
		addIEx("WEIGHT", "BGFX_ATTRIB_WEIGHT", int64_t(bgfx_attrib::BGFX_ATTRIB_WEIGHT), das::LineInfo());
		addIEx("TEXCOORD0", "BGFX_ATTRIB_TEXCOORD0", int64_t(bgfx_attrib::BGFX_ATTRIB_TEXCOORD0), das::LineInfo());
		addIEx("TEXCOORD1", "BGFX_ATTRIB_TEXCOORD1", int64_t(bgfx_attrib::BGFX_ATTRIB_TEXCOORD1), das::LineInfo());
		addIEx("TEXCOORD2", "BGFX_ATTRIB_TEXCOORD2", int64_t(bgfx_attrib::BGFX_ATTRIB_TEXCOORD2), das::LineInfo());
		addIEx("TEXCOORD3", "BGFX_ATTRIB_TEXCOORD3", int64_t(bgfx_attrib::BGFX_ATTRIB_TEXCOORD3), das::LineInfo());
		addIEx("TEXCOORD4", "BGFX_ATTRIB_TEXCOORD4", int64_t(bgfx_attrib::BGFX_ATTRIB_TEXCOORD4), das::LineInfo());
		addIEx("TEXCOORD5", "BGFX_ATTRIB_TEXCOORD5", int64_t(bgfx_attrib::BGFX_ATTRIB_TEXCOORD5), das::LineInfo());
		addIEx("TEXCOORD6", "BGFX_ATTRIB_TEXCOORD6", int64_t(bgfx_attrib::BGFX_ATTRIB_TEXCOORD6), das::LineInfo());
		addIEx("TEXCOORD7", "BGFX_ATTRIB_TEXCOORD7", int64_t(bgfx_attrib::BGFX_ATTRIB_TEXCOORD7), das::LineInfo());
		addIEx("COUNT", "BGFX_ATTRIB_COUNT", int64_t(bgfx_attrib::BGFX_ATTRIB_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_attrib_type : public das::Enumeration {
public:
	Enumeration_bgfx_attrib_type() : das::Enumeration("bgfx_attrib_type") {
		external = true;
		cppName = "bgfx_attrib_type";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("UINT8", "BGFX_ATTRIB_TYPE_UINT8", int64_t(bgfx_attrib_type::BGFX_ATTRIB_TYPE_UINT8), das::LineInfo());
		addIEx("UINT10", "BGFX_ATTRIB_TYPE_UINT10", int64_t(bgfx_attrib_type::BGFX_ATTRIB_TYPE_UINT10), das::LineInfo());
		addIEx("INT16", "BGFX_ATTRIB_TYPE_INT16", int64_t(bgfx_attrib_type::BGFX_ATTRIB_TYPE_INT16), das::LineInfo());
		addIEx("HALF", "BGFX_ATTRIB_TYPE_HALF", int64_t(bgfx_attrib_type::BGFX_ATTRIB_TYPE_HALF), das::LineInfo());
		addIEx("FLOAT", "BGFX_ATTRIB_TYPE_FLOAT", int64_t(bgfx_attrib_type::BGFX_ATTRIB_TYPE_FLOAT), das::LineInfo());
		addIEx("COUNT", "BGFX_ATTRIB_TYPE_COUNT", int64_t(bgfx_attrib_type::BGFX_ATTRIB_TYPE_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_texture_format : public das::Enumeration {
public:
	Enumeration_bgfx_texture_format() : das::Enumeration("bgfx_texture_format") {
		external = true;
		cppName = "bgfx_texture_format";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("BC1", "BGFX_TEXTURE_FORMAT_BC1", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_BC1), das::LineInfo());
		addIEx("BC2", "BGFX_TEXTURE_FORMAT_BC2", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_BC2), das::LineInfo());
		addIEx("BC3", "BGFX_TEXTURE_FORMAT_BC3", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_BC3), das::LineInfo());
		addIEx("BC4", "BGFX_TEXTURE_FORMAT_BC4", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_BC4), das::LineInfo());
		addIEx("BC5", "BGFX_TEXTURE_FORMAT_BC5", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_BC5), das::LineInfo());
		addIEx("BC6H", "BGFX_TEXTURE_FORMAT_BC6H", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_BC6H), das::LineInfo());
		addIEx("BC7", "BGFX_TEXTURE_FORMAT_BC7", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_BC7), das::LineInfo());
		addIEx("ETC1", "BGFX_TEXTURE_FORMAT_ETC1", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ETC1), das::LineInfo());
		addIEx("ETC2", "BGFX_TEXTURE_FORMAT_ETC2", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ETC2), das::LineInfo());
		addIEx("ETC2A", "BGFX_TEXTURE_FORMAT_ETC2A", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ETC2A), das::LineInfo());
		addIEx("ETC2A1", "BGFX_TEXTURE_FORMAT_ETC2A1", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ETC2A1), das::LineInfo());
		addIEx("PTC12", "BGFX_TEXTURE_FORMAT_PTC12", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_PTC12), das::LineInfo());
		addIEx("PTC14", "BGFX_TEXTURE_FORMAT_PTC14", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_PTC14), das::LineInfo());
		addIEx("PTC12A", "BGFX_TEXTURE_FORMAT_PTC12A", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_PTC12A), das::LineInfo());
		addIEx("PTC14A", "BGFX_TEXTURE_FORMAT_PTC14A", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_PTC14A), das::LineInfo());
		addIEx("PTC22", "BGFX_TEXTURE_FORMAT_PTC22", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_PTC22), das::LineInfo());
		addIEx("PTC24", "BGFX_TEXTURE_FORMAT_PTC24", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_PTC24), das::LineInfo());
		addIEx("ATC", "BGFX_TEXTURE_FORMAT_ATC", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ATC), das::LineInfo());
		addIEx("ATCE", "BGFX_TEXTURE_FORMAT_ATCE", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ATCE), das::LineInfo());
		addIEx("ATCI", "BGFX_TEXTURE_FORMAT_ATCI", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ATCI), das::LineInfo());
		addIEx("ASTC4X4", "BGFX_TEXTURE_FORMAT_ASTC4X4", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ASTC4X4), das::LineInfo());
		addIEx("ASTC5X5", "BGFX_TEXTURE_FORMAT_ASTC5X5", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ASTC5X5), das::LineInfo());
		addIEx("ASTC6X6", "BGFX_TEXTURE_FORMAT_ASTC6X6", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ASTC6X6), das::LineInfo());
		addIEx("ASTC8X5", "BGFX_TEXTURE_FORMAT_ASTC8X5", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ASTC8X5), das::LineInfo());
		addIEx("ASTC8X6", "BGFX_TEXTURE_FORMAT_ASTC8X6", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ASTC8X6), das::LineInfo());
		addIEx("ASTC10X5", "BGFX_TEXTURE_FORMAT_ASTC10X5", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_ASTC10X5), das::LineInfo());
		addIEx("UNKNOWN", "BGFX_TEXTURE_FORMAT_UNKNOWN", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_UNKNOWN), das::LineInfo());
		addIEx("R1", "BGFX_TEXTURE_FORMAT_R1", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R1), das::LineInfo());
		addIEx("A8", "BGFX_TEXTURE_FORMAT_A8", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_A8), das::LineInfo());
		addIEx("R8", "BGFX_TEXTURE_FORMAT_R8", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R8), das::LineInfo());
		addIEx("R8I", "BGFX_TEXTURE_FORMAT_R8I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R8I), das::LineInfo());
		addIEx("R8U", "BGFX_TEXTURE_FORMAT_R8U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R8U), das::LineInfo());
		addIEx("R8S", "BGFX_TEXTURE_FORMAT_R8S", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R8S), das::LineInfo());
		addIEx("R16", "BGFX_TEXTURE_FORMAT_R16", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R16), das::LineInfo());
		addIEx("R16I", "BGFX_TEXTURE_FORMAT_R16I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R16I), das::LineInfo());
		addIEx("R16U", "BGFX_TEXTURE_FORMAT_R16U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R16U), das::LineInfo());
		addIEx("R16F", "BGFX_TEXTURE_FORMAT_R16F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R16F), das::LineInfo());
		addIEx("R16S", "BGFX_TEXTURE_FORMAT_R16S", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R16S), das::LineInfo());
		addIEx("R32I", "BGFX_TEXTURE_FORMAT_R32I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R32I), das::LineInfo());
		addIEx("R32U", "BGFX_TEXTURE_FORMAT_R32U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R32U), das::LineInfo());
		addIEx("R32F", "BGFX_TEXTURE_FORMAT_R32F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R32F), das::LineInfo());
		addIEx("RG8", "BGFX_TEXTURE_FORMAT_RG8", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG8), das::LineInfo());
		addIEx("RG8I", "BGFX_TEXTURE_FORMAT_RG8I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG8I), das::LineInfo());
		addIEx("RG8U", "BGFX_TEXTURE_FORMAT_RG8U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG8U), das::LineInfo());
		addIEx("RG8S", "BGFX_TEXTURE_FORMAT_RG8S", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG8S), das::LineInfo());
		addIEx("RG16", "BGFX_TEXTURE_FORMAT_RG16", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG16), das::LineInfo());
		addIEx("RG16I", "BGFX_TEXTURE_FORMAT_RG16I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG16I), das::LineInfo());
		addIEx("RG16U", "BGFX_TEXTURE_FORMAT_RG16U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG16U), das::LineInfo());
		addIEx("RG16F", "BGFX_TEXTURE_FORMAT_RG16F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG16F), das::LineInfo());
		addIEx("RG16S", "BGFX_TEXTURE_FORMAT_RG16S", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG16S), das::LineInfo());
		addIEx("RG32I", "BGFX_TEXTURE_FORMAT_RG32I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG32I), das::LineInfo());
		addIEx("RG32U", "BGFX_TEXTURE_FORMAT_RG32U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG32U), das::LineInfo());
		addIEx("RG32F", "BGFX_TEXTURE_FORMAT_RG32F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG32F), das::LineInfo());
		addIEx("RGB8", "BGFX_TEXTURE_FORMAT_RGB8", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGB8), das::LineInfo());
		addIEx("RGB8I", "BGFX_TEXTURE_FORMAT_RGB8I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGB8I), das::LineInfo());
		addIEx("RGB8U", "BGFX_TEXTURE_FORMAT_RGB8U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGB8U), das::LineInfo());
		addIEx("RGB8S", "BGFX_TEXTURE_FORMAT_RGB8S", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGB8S), das::LineInfo());
		addIEx("RGB9E5F", "BGFX_TEXTURE_FORMAT_RGB9E5F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGB9E5F), das::LineInfo());
		addIEx("BGRA8", "BGFX_TEXTURE_FORMAT_BGRA8", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_BGRA8), das::LineInfo());
		addIEx("RGBA8", "BGFX_TEXTURE_FORMAT_RGBA8", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA8), das::LineInfo());
		addIEx("RGBA8I", "BGFX_TEXTURE_FORMAT_RGBA8I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA8I), das::LineInfo());
		addIEx("RGBA8U", "BGFX_TEXTURE_FORMAT_RGBA8U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA8U), das::LineInfo());
		addIEx("RGBA8S", "BGFX_TEXTURE_FORMAT_RGBA8S", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA8S), das::LineInfo());
		addIEx("RGBA16", "BGFX_TEXTURE_FORMAT_RGBA16", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA16), das::LineInfo());
		addIEx("RGBA16I", "BGFX_TEXTURE_FORMAT_RGBA16I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA16I), das::LineInfo());
		addIEx("RGBA16U", "BGFX_TEXTURE_FORMAT_RGBA16U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA16U), das::LineInfo());
		addIEx("RGBA16F", "BGFX_TEXTURE_FORMAT_RGBA16F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA16F), das::LineInfo());
		addIEx("RGBA16S", "BGFX_TEXTURE_FORMAT_RGBA16S", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA16S), das::LineInfo());
		addIEx("RGBA32I", "BGFX_TEXTURE_FORMAT_RGBA32I", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA32I), das::LineInfo());
		addIEx("RGBA32U", "BGFX_TEXTURE_FORMAT_RGBA32U", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA32U), das::LineInfo());
		addIEx("RGBA32F", "BGFX_TEXTURE_FORMAT_RGBA32F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA32F), das::LineInfo());
		addIEx("R5G6B5", "BGFX_TEXTURE_FORMAT_R5G6B5", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_R5G6B5), das::LineInfo());
		addIEx("RGBA4", "BGFX_TEXTURE_FORMAT_RGBA4", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGBA4), das::LineInfo());
		addIEx("RGB5A1", "BGFX_TEXTURE_FORMAT_RGB5A1", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGB5A1), das::LineInfo());
		addIEx("RGB10A2", "BGFX_TEXTURE_FORMAT_RGB10A2", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RGB10A2), das::LineInfo());
		addIEx("RG11B10F", "BGFX_TEXTURE_FORMAT_RG11B10F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_RG11B10F), das::LineInfo());
		addIEx("UNKNOWNDEPTH", "BGFX_TEXTURE_FORMAT_UNKNOWNDEPTH", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_UNKNOWNDEPTH), das::LineInfo());
		addIEx("D16", "BGFX_TEXTURE_FORMAT_D16", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_D16), das::LineInfo());
		addIEx("D24", "BGFX_TEXTURE_FORMAT_D24", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_D24), das::LineInfo());
		addIEx("D24S8", "BGFX_TEXTURE_FORMAT_D24S8", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_D24S8), das::LineInfo());
		addIEx("D32", "BGFX_TEXTURE_FORMAT_D32", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_D32), das::LineInfo());
		addIEx("D16F", "BGFX_TEXTURE_FORMAT_D16F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_D16F), das::LineInfo());
		addIEx("D24F", "BGFX_TEXTURE_FORMAT_D24F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_D24F), das::LineInfo());
		addIEx("D32F", "BGFX_TEXTURE_FORMAT_D32F", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_D32F), das::LineInfo());
		addIEx("D0S8", "BGFX_TEXTURE_FORMAT_D0S8", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_D0S8), das::LineInfo());
		addIEx("COUNT", "BGFX_TEXTURE_FORMAT_COUNT", int64_t(bgfx_texture_format::BGFX_TEXTURE_FORMAT_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_uniform_type : public das::Enumeration {
public:
	Enumeration_bgfx_uniform_type() : das::Enumeration("bgfx_uniform_type") {
		external = true;
		cppName = "bgfx_uniform_type";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("SAMPLER", "BGFX_UNIFORM_TYPE_SAMPLER", int64_t(bgfx_uniform_type::BGFX_UNIFORM_TYPE_SAMPLER), das::LineInfo());
		addIEx("END", "BGFX_UNIFORM_TYPE_END", int64_t(bgfx_uniform_type::BGFX_UNIFORM_TYPE_END), das::LineInfo());
		addIEx("VEC4", "BGFX_UNIFORM_TYPE_VEC4", int64_t(bgfx_uniform_type::BGFX_UNIFORM_TYPE_VEC4), das::LineInfo());
		addIEx("MAT3", "BGFX_UNIFORM_TYPE_MAT3", int64_t(bgfx_uniform_type::BGFX_UNIFORM_TYPE_MAT3), das::LineInfo());
		addIEx("MAT4", "BGFX_UNIFORM_TYPE_MAT4", int64_t(bgfx_uniform_type::BGFX_UNIFORM_TYPE_MAT4), das::LineInfo());
		addIEx("COUNT", "BGFX_UNIFORM_TYPE_COUNT", int64_t(bgfx_uniform_type::BGFX_UNIFORM_TYPE_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_backbuffer_ratio : public das::Enumeration {
public:
	Enumeration_bgfx_backbuffer_ratio() : das::Enumeration("bgfx_backbuffer_ratio") {
		external = true;
		cppName = "bgfx_backbuffer_ratio";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("EQUAL", "BGFX_BACKBUFFER_RATIO_EQUAL", int64_t(bgfx_backbuffer_ratio::BGFX_BACKBUFFER_RATIO_EQUAL), das::LineInfo());
		addIEx("HALF", "BGFX_BACKBUFFER_RATIO_HALF", int64_t(bgfx_backbuffer_ratio::BGFX_BACKBUFFER_RATIO_HALF), das::LineInfo());
		addIEx("QUARTER", "BGFX_BACKBUFFER_RATIO_QUARTER", int64_t(bgfx_backbuffer_ratio::BGFX_BACKBUFFER_RATIO_QUARTER), das::LineInfo());
		addIEx("EIGHTH", "BGFX_BACKBUFFER_RATIO_EIGHTH", int64_t(bgfx_backbuffer_ratio::BGFX_BACKBUFFER_RATIO_EIGHTH), das::LineInfo());
		addIEx("SIXTEENTH", "BGFX_BACKBUFFER_RATIO_SIXTEENTH", int64_t(bgfx_backbuffer_ratio::BGFX_BACKBUFFER_RATIO_SIXTEENTH), das::LineInfo());
		addIEx("DOUBLE", "BGFX_BACKBUFFER_RATIO_DOUBLE", int64_t(bgfx_backbuffer_ratio::BGFX_BACKBUFFER_RATIO_DOUBLE), das::LineInfo());
		addIEx("COUNT", "BGFX_BACKBUFFER_RATIO_COUNT", int64_t(bgfx_backbuffer_ratio::BGFX_BACKBUFFER_RATIO_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_occlusion_query_result : public das::Enumeration {
public:
	Enumeration_bgfx_occlusion_query_result() : das::Enumeration("bgfx_occlusion_query_result") {
		external = true;
		cppName = "bgfx_occlusion_query_result";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("INVISIBLE", "BGFX_OCCLUSION_QUERY_RESULT_INVISIBLE", int64_t(bgfx_occlusion_query_result::BGFX_OCCLUSION_QUERY_RESULT_INVISIBLE), das::LineInfo());
		addIEx("VISIBLE", "BGFX_OCCLUSION_QUERY_RESULT_VISIBLE", int64_t(bgfx_occlusion_query_result::BGFX_OCCLUSION_QUERY_RESULT_VISIBLE), das::LineInfo());
		addIEx("NORESULT", "BGFX_OCCLUSION_QUERY_RESULT_NORESULT", int64_t(bgfx_occlusion_query_result::BGFX_OCCLUSION_QUERY_RESULT_NORESULT), das::LineInfo());
		addIEx("COUNT", "BGFX_OCCLUSION_QUERY_RESULT_COUNT", int64_t(bgfx_occlusion_query_result::BGFX_OCCLUSION_QUERY_RESULT_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_topology : public das::Enumeration {
public:
	Enumeration_bgfx_topology() : das::Enumeration("bgfx_topology") {
		external = true;
		cppName = "bgfx_topology";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("TRI_LIST", "BGFX_TOPOLOGY_TRI_LIST", int64_t(bgfx_topology::BGFX_TOPOLOGY_TRI_LIST), das::LineInfo());
		addIEx("TRI_STRIP", "BGFX_TOPOLOGY_TRI_STRIP", int64_t(bgfx_topology::BGFX_TOPOLOGY_TRI_STRIP), das::LineInfo());
		addIEx("LINE_LIST", "BGFX_TOPOLOGY_LINE_LIST", int64_t(bgfx_topology::BGFX_TOPOLOGY_LINE_LIST), das::LineInfo());
		addIEx("LINE_STRIP", "BGFX_TOPOLOGY_LINE_STRIP", int64_t(bgfx_topology::BGFX_TOPOLOGY_LINE_STRIP), das::LineInfo());
		addIEx("POINT_LIST", "BGFX_TOPOLOGY_POINT_LIST", int64_t(bgfx_topology::BGFX_TOPOLOGY_POINT_LIST), das::LineInfo());
		addIEx("COUNT", "BGFX_TOPOLOGY_COUNT", int64_t(bgfx_topology::BGFX_TOPOLOGY_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_topology_convert : public das::Enumeration {
public:
	Enumeration_bgfx_topology_convert() : das::Enumeration("bgfx_topology_convert") {
		external = true;
		cppName = "bgfx_topology_convert";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("TRI_LIST_FLIP_WINDING", "BGFX_TOPOLOGY_CONVERT_TRI_LIST_FLIP_WINDING", int64_t(bgfx_topology_convert::BGFX_TOPOLOGY_CONVERT_TRI_LIST_FLIP_WINDING), das::LineInfo());
		addIEx("TRI_STRIP_FLIP_WINDING", "BGFX_TOPOLOGY_CONVERT_TRI_STRIP_FLIP_WINDING", int64_t(bgfx_topology_convert::BGFX_TOPOLOGY_CONVERT_TRI_STRIP_FLIP_WINDING), das::LineInfo());
		addIEx("TRI_LIST_TO_LINE_LIST", "BGFX_TOPOLOGY_CONVERT_TRI_LIST_TO_LINE_LIST", int64_t(bgfx_topology_convert::BGFX_TOPOLOGY_CONVERT_TRI_LIST_TO_LINE_LIST), das::LineInfo());
		addIEx("TRI_STRIP_TO_TRI_LIST", "BGFX_TOPOLOGY_CONVERT_TRI_STRIP_TO_TRI_LIST", int64_t(bgfx_topology_convert::BGFX_TOPOLOGY_CONVERT_TRI_STRIP_TO_TRI_LIST), das::LineInfo());
		addIEx("LINE_STRIP_TO_LINE_LIST", "BGFX_TOPOLOGY_CONVERT_LINE_STRIP_TO_LINE_LIST", int64_t(bgfx_topology_convert::BGFX_TOPOLOGY_CONVERT_LINE_STRIP_TO_LINE_LIST), das::LineInfo());
		addIEx("COUNT", "BGFX_TOPOLOGY_CONVERT_COUNT", int64_t(bgfx_topology_convert::BGFX_TOPOLOGY_CONVERT_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_topology_sort : public das::Enumeration {
public:
	Enumeration_bgfx_topology_sort() : das::Enumeration("bgfx_topology_sort") {
		external = true;
		cppName = "bgfx_topology_sort";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("DIRECTION_FRONT_TO_BACK_MIN", "BGFX_TOPOLOGY_SORT_DIRECTION_FRONT_TO_BACK_MIN", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DIRECTION_FRONT_TO_BACK_MIN), das::LineInfo());
		addIEx("DIRECTION_FRONT_TO_BACK_AVG", "BGFX_TOPOLOGY_SORT_DIRECTION_FRONT_TO_BACK_AVG", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DIRECTION_FRONT_TO_BACK_AVG), das::LineInfo());
		addIEx("DIRECTION_FRONT_TO_BACK_MAX", "BGFX_TOPOLOGY_SORT_DIRECTION_FRONT_TO_BACK_MAX", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DIRECTION_FRONT_TO_BACK_MAX), das::LineInfo());
		addIEx("DIRECTION_BACK_TO_FRONT_MIN", "BGFX_TOPOLOGY_SORT_DIRECTION_BACK_TO_FRONT_MIN", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DIRECTION_BACK_TO_FRONT_MIN), das::LineInfo());
		addIEx("DIRECTION_BACK_TO_FRONT_AVG", "BGFX_TOPOLOGY_SORT_DIRECTION_BACK_TO_FRONT_AVG", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DIRECTION_BACK_TO_FRONT_AVG), das::LineInfo());
		addIEx("DIRECTION_BACK_TO_FRONT_MAX", "BGFX_TOPOLOGY_SORT_DIRECTION_BACK_TO_FRONT_MAX", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DIRECTION_BACK_TO_FRONT_MAX), das::LineInfo());
		addIEx("DISTANCE_FRONT_TO_BACK_MIN", "BGFX_TOPOLOGY_SORT_DISTANCE_FRONT_TO_BACK_MIN", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DISTANCE_FRONT_TO_BACK_MIN), das::LineInfo());
		addIEx("DISTANCE_FRONT_TO_BACK_AVG", "BGFX_TOPOLOGY_SORT_DISTANCE_FRONT_TO_BACK_AVG", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DISTANCE_FRONT_TO_BACK_AVG), das::LineInfo());
		addIEx("DISTANCE_FRONT_TO_BACK_MAX", "BGFX_TOPOLOGY_SORT_DISTANCE_FRONT_TO_BACK_MAX", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DISTANCE_FRONT_TO_BACK_MAX), das::LineInfo());
		addIEx("DISTANCE_BACK_TO_FRONT_MIN", "BGFX_TOPOLOGY_SORT_DISTANCE_BACK_TO_FRONT_MIN", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DISTANCE_BACK_TO_FRONT_MIN), das::LineInfo());
		addIEx("DISTANCE_BACK_TO_FRONT_AVG", "BGFX_TOPOLOGY_SORT_DISTANCE_BACK_TO_FRONT_AVG", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DISTANCE_BACK_TO_FRONT_AVG), das::LineInfo());
		addIEx("DISTANCE_BACK_TO_FRONT_MAX", "BGFX_TOPOLOGY_SORT_DISTANCE_BACK_TO_FRONT_MAX", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_DISTANCE_BACK_TO_FRONT_MAX), das::LineInfo());
		addIEx("COUNT", "BGFX_TOPOLOGY_SORT_COUNT", int64_t(bgfx_topology_sort::BGFX_TOPOLOGY_SORT_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_view_mode : public das::Enumeration {
public:
	Enumeration_bgfx_view_mode() : das::Enumeration("bgfx_view_mode") {
		external = true;
		cppName = "bgfx_view_mode";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("DEFAULT", "BGFX_VIEW_MODE_DEFAULT", int64_t(bgfx_view_mode::BGFX_VIEW_MODE_DEFAULT), das::LineInfo());
		addIEx("SEQUENTIAL", "BGFX_VIEW_MODE_SEQUENTIAL", int64_t(bgfx_view_mode::BGFX_VIEW_MODE_SEQUENTIAL), das::LineInfo());
		addIEx("DEPTH_ASCENDING", "BGFX_VIEW_MODE_DEPTH_ASCENDING", int64_t(bgfx_view_mode::BGFX_VIEW_MODE_DEPTH_ASCENDING), das::LineInfo());
		addIEx("DEPTH_DESCENDING", "BGFX_VIEW_MODE_DEPTH_DESCENDING", int64_t(bgfx_view_mode::BGFX_VIEW_MODE_DEPTH_DESCENDING), das::LineInfo());
		addIEx("COUNT", "BGFX_VIEW_MODE_COUNT", int64_t(bgfx_view_mode::BGFX_VIEW_MODE_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_render_frame : public das::Enumeration {
public:
	Enumeration_bgfx_render_frame() : das::Enumeration("bgfx_render_frame") {
		external = true;
		cppName = "bgfx_render_frame";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("NO_CONTEXT", "BGFX_RENDER_FRAME_NO_CONTEXT", int64_t(bgfx_render_frame::BGFX_RENDER_FRAME_NO_CONTEXT), das::LineInfo());
		addIEx("RENDER", "BGFX_RENDER_FRAME_RENDER", int64_t(bgfx_render_frame::BGFX_RENDER_FRAME_RENDER), das::LineInfo());
		addIEx("TIMEOUT", "BGFX_RENDER_FRAME_TIMEOUT", int64_t(bgfx_render_frame::BGFX_RENDER_FRAME_TIMEOUT), das::LineInfo());
		addIEx("EXITING", "BGFX_RENDER_FRAME_EXITING", int64_t(bgfx_render_frame::BGFX_RENDER_FRAME_EXITING), das::LineInfo());
		addIEx("COUNT", "BGFX_RENDER_FRAME_COUNT", int64_t(bgfx_render_frame::BGFX_RENDER_FRAME_COUNT), das::LineInfo());
	}
};

class Enumeration_bgfx_function_id : public das::Enumeration {
public:
	Enumeration_bgfx_function_id() : das::Enumeration("bgfx_function_id") {
		external = true;
		cppName = "bgfx_function_id";
		baseType = (das::Type) das::ToBasicType<int>::type;
		addIEx("ATTACHMENT_INIT", "BGFX_FUNCTION_ID_ATTACHMENT_INIT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ATTACHMENT_INIT), das::LineInfo());
		addIEx("VERTEX_LAYOUT_BEGIN", "BGFX_FUNCTION_ID_VERTEX_LAYOUT_BEGIN", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_LAYOUT_BEGIN), das::LineInfo());
		addIEx("VERTEX_LAYOUT_ADD", "BGFX_FUNCTION_ID_VERTEX_LAYOUT_ADD", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_LAYOUT_ADD), das::LineInfo());
		addIEx("VERTEX_LAYOUT_DECODE", "BGFX_FUNCTION_ID_VERTEX_LAYOUT_DECODE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_LAYOUT_DECODE), das::LineInfo());
		addIEx("VERTEX_LAYOUT_HAS", "BGFX_FUNCTION_ID_VERTEX_LAYOUT_HAS", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_LAYOUT_HAS), das::LineInfo());
		addIEx("VERTEX_LAYOUT_SKIP", "BGFX_FUNCTION_ID_VERTEX_LAYOUT_SKIP", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_LAYOUT_SKIP), das::LineInfo());
		addIEx("VERTEX_LAYOUT_END", "BGFX_FUNCTION_ID_VERTEX_LAYOUT_END", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_LAYOUT_END), das::LineInfo());
		addIEx("VERTEX_PACK", "BGFX_FUNCTION_ID_VERTEX_PACK", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_PACK), das::LineInfo());
		addIEx("VERTEX_UNPACK", "BGFX_FUNCTION_ID_VERTEX_UNPACK", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_UNPACK), das::LineInfo());
		addIEx("VERTEX_CONVERT", "BGFX_FUNCTION_ID_VERTEX_CONVERT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_VERTEX_CONVERT), das::LineInfo());
		addIEx("WELD_VERTICES", "BGFX_FUNCTION_ID_WELD_VERTICES", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_WELD_VERTICES), das::LineInfo());
		addIEx("TOPOLOGY_CONVERT", "BGFX_FUNCTION_ID_TOPOLOGY_CONVERT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_TOPOLOGY_CONVERT), das::LineInfo());
		addIEx("TOPOLOGY_SORT_TRI_LIST", "BGFX_FUNCTION_ID_TOPOLOGY_SORT_TRI_LIST", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_TOPOLOGY_SORT_TRI_LIST), das::LineInfo());
		addIEx("GET_SUPPORTED_RENDERERS", "BGFX_FUNCTION_ID_GET_SUPPORTED_RENDERERS", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_SUPPORTED_RENDERERS), das::LineInfo());
		addIEx("GET_RENDERER_NAME", "BGFX_FUNCTION_ID_GET_RENDERER_NAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_RENDERER_NAME), das::LineInfo());
		addIEx("INIT_CTOR", "BGFX_FUNCTION_ID_INIT_CTOR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_INIT_CTOR), das::LineInfo());
		addIEx("INIT", "BGFX_FUNCTION_ID_INIT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_INIT), das::LineInfo());
		addIEx("SHUTDOWN", "BGFX_FUNCTION_ID_SHUTDOWN", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SHUTDOWN), das::LineInfo());
		addIEx("RESET", "BGFX_FUNCTION_ID_RESET", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_RESET), das::LineInfo());
		addIEx("FRAME", "BGFX_FUNCTION_ID_FRAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_FRAME), das::LineInfo());
		addIEx("GET_RENDERER_TYPE", "BGFX_FUNCTION_ID_GET_RENDERER_TYPE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_RENDERER_TYPE), das::LineInfo());
		addIEx("GET_CAPS", "BGFX_FUNCTION_ID_GET_CAPS", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_CAPS), das::LineInfo());
		addIEx("GET_STATS", "BGFX_FUNCTION_ID_GET_STATS", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_STATS), das::LineInfo());
		addIEx("ALLOC", "BGFX_FUNCTION_ID_ALLOC", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ALLOC), das::LineInfo());
		addIEx("COPY", "BGFX_FUNCTION_ID_COPY", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_COPY), das::LineInfo());
		addIEx("MAKE_REF", "BGFX_FUNCTION_ID_MAKE_REF", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_MAKE_REF), das::LineInfo());
		addIEx("MAKE_REF_RELEASE", "BGFX_FUNCTION_ID_MAKE_REF_RELEASE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_MAKE_REF_RELEASE), das::LineInfo());
		addIEx("SET_DEBUG", "BGFX_FUNCTION_ID_SET_DEBUG", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_DEBUG), das::LineInfo());
		addIEx("DBG_TEXT_CLEAR", "BGFX_FUNCTION_ID_DBG_TEXT_CLEAR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DBG_TEXT_CLEAR), das::LineInfo());
		addIEx("DBG_TEXT_PRINTF", "BGFX_FUNCTION_ID_DBG_TEXT_PRINTF", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DBG_TEXT_PRINTF), das::LineInfo());
		addIEx("DBG_TEXT_VPRINTF", "BGFX_FUNCTION_ID_DBG_TEXT_VPRINTF", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DBG_TEXT_VPRINTF), das::LineInfo());
		addIEx("DBG_TEXT_IMAGE", "BGFX_FUNCTION_ID_DBG_TEXT_IMAGE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DBG_TEXT_IMAGE), das::LineInfo());
		addIEx("CREATE_INDEX_BUFFER", "BGFX_FUNCTION_ID_CREATE_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_INDEX_BUFFER), das::LineInfo());
		addIEx("SET_INDEX_BUFFER_NAME", "BGFX_FUNCTION_ID_SET_INDEX_BUFFER_NAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_INDEX_BUFFER_NAME), das::LineInfo());
		addIEx("DESTROY_INDEX_BUFFER", "BGFX_FUNCTION_ID_DESTROY_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_INDEX_BUFFER), das::LineInfo());
		addIEx("CREATE_VERTEX_LAYOUT", "BGFX_FUNCTION_ID_CREATE_VERTEX_LAYOUT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_VERTEX_LAYOUT), das::LineInfo());
		addIEx("DESTROY_VERTEX_LAYOUT", "BGFX_FUNCTION_ID_DESTROY_VERTEX_LAYOUT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_VERTEX_LAYOUT), das::LineInfo());
		addIEx("CREATE_VERTEX_BUFFER", "BGFX_FUNCTION_ID_CREATE_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_VERTEX_BUFFER), das::LineInfo());
		addIEx("SET_VERTEX_BUFFER_NAME", "BGFX_FUNCTION_ID_SET_VERTEX_BUFFER_NAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VERTEX_BUFFER_NAME), das::LineInfo());
		addIEx("DESTROY_VERTEX_BUFFER", "BGFX_FUNCTION_ID_DESTROY_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_VERTEX_BUFFER), das::LineInfo());
		addIEx("CREATE_DYNAMIC_INDEX_BUFFER", "BGFX_FUNCTION_ID_CREATE_DYNAMIC_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_DYNAMIC_INDEX_BUFFER), das::LineInfo());
		addIEx("CREATE_DYNAMIC_INDEX_BUFFER_MEM", "BGFX_FUNCTION_ID_CREATE_DYNAMIC_INDEX_BUFFER_MEM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_DYNAMIC_INDEX_BUFFER_MEM), das::LineInfo());
		addIEx("UPDATE_DYNAMIC_INDEX_BUFFER", "BGFX_FUNCTION_ID_UPDATE_DYNAMIC_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_UPDATE_DYNAMIC_INDEX_BUFFER), das::LineInfo());
		addIEx("DESTROY_DYNAMIC_INDEX_BUFFER", "BGFX_FUNCTION_ID_DESTROY_DYNAMIC_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_DYNAMIC_INDEX_BUFFER), das::LineInfo());
		addIEx("CREATE_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_CREATE_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("CREATE_DYNAMIC_VERTEX_BUFFER_MEM", "BGFX_FUNCTION_ID_CREATE_DYNAMIC_VERTEX_BUFFER_MEM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_DYNAMIC_VERTEX_BUFFER_MEM), das::LineInfo());
		addIEx("UPDATE_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_UPDATE_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_UPDATE_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("DESTROY_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_DESTROY_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("GET_AVAIL_TRANSIENT_INDEX_BUFFER", "BGFX_FUNCTION_ID_GET_AVAIL_TRANSIENT_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_AVAIL_TRANSIENT_INDEX_BUFFER), das::LineInfo());
		addIEx("GET_AVAIL_TRANSIENT_VERTEX_BUFFER", "BGFX_FUNCTION_ID_GET_AVAIL_TRANSIENT_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_AVAIL_TRANSIENT_VERTEX_BUFFER), das::LineInfo());
		addIEx("GET_AVAIL_INSTANCE_DATA_BUFFER", "BGFX_FUNCTION_ID_GET_AVAIL_INSTANCE_DATA_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_AVAIL_INSTANCE_DATA_BUFFER), das::LineInfo());
		addIEx("ALLOC_TRANSIENT_INDEX_BUFFER", "BGFX_FUNCTION_ID_ALLOC_TRANSIENT_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ALLOC_TRANSIENT_INDEX_BUFFER), das::LineInfo());
		addIEx("ALLOC_TRANSIENT_VERTEX_BUFFER", "BGFX_FUNCTION_ID_ALLOC_TRANSIENT_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ALLOC_TRANSIENT_VERTEX_BUFFER), das::LineInfo());
		addIEx("ALLOC_TRANSIENT_BUFFERS", "BGFX_FUNCTION_ID_ALLOC_TRANSIENT_BUFFERS", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ALLOC_TRANSIENT_BUFFERS), das::LineInfo());
		addIEx("ALLOC_INSTANCE_DATA_BUFFER", "BGFX_FUNCTION_ID_ALLOC_INSTANCE_DATA_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ALLOC_INSTANCE_DATA_BUFFER), das::LineInfo());
		addIEx("CREATE_INDIRECT_BUFFER", "BGFX_FUNCTION_ID_CREATE_INDIRECT_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_INDIRECT_BUFFER), das::LineInfo());
		addIEx("DESTROY_INDIRECT_BUFFER", "BGFX_FUNCTION_ID_DESTROY_INDIRECT_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_INDIRECT_BUFFER), das::LineInfo());
		addIEx("CREATE_SHADER", "BGFX_FUNCTION_ID_CREATE_SHADER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_SHADER), das::LineInfo());
		addIEx("GET_SHADER_UNIFORMS", "BGFX_FUNCTION_ID_GET_SHADER_UNIFORMS", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_SHADER_UNIFORMS), das::LineInfo());
		addIEx("SET_SHADER_NAME", "BGFX_FUNCTION_ID_SET_SHADER_NAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_SHADER_NAME), das::LineInfo());
		addIEx("DESTROY_SHADER", "BGFX_FUNCTION_ID_DESTROY_SHADER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_SHADER), das::LineInfo());
		addIEx("CREATE_PROGRAM", "BGFX_FUNCTION_ID_CREATE_PROGRAM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_PROGRAM), das::LineInfo());
		addIEx("CREATE_COMPUTE_PROGRAM", "BGFX_FUNCTION_ID_CREATE_COMPUTE_PROGRAM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_COMPUTE_PROGRAM), das::LineInfo());
		addIEx("DESTROY_PROGRAM", "BGFX_FUNCTION_ID_DESTROY_PROGRAM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_PROGRAM), das::LineInfo());
		addIEx("IS_TEXTURE_VALID", "BGFX_FUNCTION_ID_IS_TEXTURE_VALID", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_IS_TEXTURE_VALID), das::LineInfo());
		addIEx("IS_FRAME_BUFFER_VALID", "BGFX_FUNCTION_ID_IS_FRAME_BUFFER_VALID", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_IS_FRAME_BUFFER_VALID), das::LineInfo());
		addIEx("CALC_TEXTURE_SIZE", "BGFX_FUNCTION_ID_CALC_TEXTURE_SIZE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CALC_TEXTURE_SIZE), das::LineInfo());
		addIEx("CREATE_TEXTURE", "BGFX_FUNCTION_ID_CREATE_TEXTURE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_TEXTURE), das::LineInfo());
		addIEx("CREATE_TEXTURE_2D", "BGFX_FUNCTION_ID_CREATE_TEXTURE_2D", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_TEXTURE_2D), das::LineInfo());
		addIEx("CREATE_TEXTURE_2D_SCALED", "BGFX_FUNCTION_ID_CREATE_TEXTURE_2D_SCALED", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_TEXTURE_2D_SCALED), das::LineInfo());
		addIEx("CREATE_TEXTURE_3D", "BGFX_FUNCTION_ID_CREATE_TEXTURE_3D", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_TEXTURE_3D), das::LineInfo());
		addIEx("CREATE_TEXTURE_CUBE", "BGFX_FUNCTION_ID_CREATE_TEXTURE_CUBE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_TEXTURE_CUBE), das::LineInfo());
		addIEx("UPDATE_TEXTURE_2D", "BGFX_FUNCTION_ID_UPDATE_TEXTURE_2D", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_UPDATE_TEXTURE_2D), das::LineInfo());
		addIEx("UPDATE_TEXTURE_3D", "BGFX_FUNCTION_ID_UPDATE_TEXTURE_3D", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_UPDATE_TEXTURE_3D), das::LineInfo());
		addIEx("UPDATE_TEXTURE_CUBE", "BGFX_FUNCTION_ID_UPDATE_TEXTURE_CUBE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_UPDATE_TEXTURE_CUBE), das::LineInfo());
		addIEx("READ_TEXTURE", "BGFX_FUNCTION_ID_READ_TEXTURE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_READ_TEXTURE), das::LineInfo());
		addIEx("SET_TEXTURE_NAME", "BGFX_FUNCTION_ID_SET_TEXTURE_NAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_TEXTURE_NAME), das::LineInfo());
		addIEx("GET_DIRECT_ACCESS_PTR", "BGFX_FUNCTION_ID_GET_DIRECT_ACCESS_PTR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_DIRECT_ACCESS_PTR), das::LineInfo());
		addIEx("DESTROY_TEXTURE", "BGFX_FUNCTION_ID_DESTROY_TEXTURE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_TEXTURE), das::LineInfo());
		addIEx("CREATE_FRAME_BUFFER", "BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER), das::LineInfo());
		addIEx("CREATE_FRAME_BUFFER_SCALED", "BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER_SCALED", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER_SCALED), das::LineInfo());
		addIEx("CREATE_FRAME_BUFFER_FROM_HANDLES", "BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER_FROM_HANDLES", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER_FROM_HANDLES), das::LineInfo());
		addIEx("CREATE_FRAME_BUFFER_FROM_ATTACHMENT", "BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER_FROM_ATTACHMENT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER_FROM_ATTACHMENT), das::LineInfo());
		addIEx("CREATE_FRAME_BUFFER_FROM_NWH", "BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER_FROM_NWH", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_FRAME_BUFFER_FROM_NWH), das::LineInfo());
		addIEx("SET_FRAME_BUFFER_NAME", "BGFX_FUNCTION_ID_SET_FRAME_BUFFER_NAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_FRAME_BUFFER_NAME), das::LineInfo());
		addIEx("GET_TEXTURE", "BGFX_FUNCTION_ID_GET_TEXTURE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_TEXTURE), das::LineInfo());
		addIEx("DESTROY_FRAME_BUFFER", "BGFX_FUNCTION_ID_DESTROY_FRAME_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_FRAME_BUFFER), das::LineInfo());
		addIEx("CREATE_UNIFORM", "BGFX_FUNCTION_ID_CREATE_UNIFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_UNIFORM), das::LineInfo());
		addIEx("GET_UNIFORM_INFO", "BGFX_FUNCTION_ID_GET_UNIFORM_INFO", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_UNIFORM_INFO), das::LineInfo());
		addIEx("DESTROY_UNIFORM", "BGFX_FUNCTION_ID_DESTROY_UNIFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_UNIFORM), das::LineInfo());
		addIEx("CREATE_OCCLUSION_QUERY", "BGFX_FUNCTION_ID_CREATE_OCCLUSION_QUERY", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_CREATE_OCCLUSION_QUERY), das::LineInfo());
		addIEx("GET_RESULT", "BGFX_FUNCTION_ID_GET_RESULT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_RESULT), das::LineInfo());
		addIEx("DESTROY_OCCLUSION_QUERY", "BGFX_FUNCTION_ID_DESTROY_OCCLUSION_QUERY", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DESTROY_OCCLUSION_QUERY), das::LineInfo());
		addIEx("SET_PALETTE_COLOR", "BGFX_FUNCTION_ID_SET_PALETTE_COLOR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_PALETTE_COLOR), das::LineInfo());
		addIEx("SET_PALETTE_COLOR_RGBA8", "BGFX_FUNCTION_ID_SET_PALETTE_COLOR_RGBA8", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_PALETTE_COLOR_RGBA8), das::LineInfo());
		addIEx("SET_VIEW_NAME", "BGFX_FUNCTION_ID_SET_VIEW_NAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_NAME), das::LineInfo());
		addIEx("SET_VIEW_RECT", "BGFX_FUNCTION_ID_SET_VIEW_RECT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_RECT), das::LineInfo());
		addIEx("SET_VIEW_RECT_RATIO", "BGFX_FUNCTION_ID_SET_VIEW_RECT_RATIO", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_RECT_RATIO), das::LineInfo());
		addIEx("SET_VIEW_SCISSOR", "BGFX_FUNCTION_ID_SET_VIEW_SCISSOR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_SCISSOR), das::LineInfo());
		addIEx("SET_VIEW_CLEAR", "BGFX_FUNCTION_ID_SET_VIEW_CLEAR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_CLEAR), das::LineInfo());
		addIEx("SET_VIEW_CLEAR_MRT", "BGFX_FUNCTION_ID_SET_VIEW_CLEAR_MRT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_CLEAR_MRT), das::LineInfo());
		addIEx("SET_VIEW_MODE", "BGFX_FUNCTION_ID_SET_VIEW_MODE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_MODE), das::LineInfo());
		addIEx("SET_VIEW_FRAME_BUFFER", "BGFX_FUNCTION_ID_SET_VIEW_FRAME_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_FRAME_BUFFER), das::LineInfo());
		addIEx("SET_VIEW_TRANSFORM", "BGFX_FUNCTION_ID_SET_VIEW_TRANSFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_TRANSFORM), das::LineInfo());
		addIEx("SET_VIEW_ORDER", "BGFX_FUNCTION_ID_SET_VIEW_ORDER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VIEW_ORDER), das::LineInfo());
		addIEx("RESET_VIEW", "BGFX_FUNCTION_ID_RESET_VIEW", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_RESET_VIEW), das::LineInfo());
		addIEx("ENCODER_BEGIN", "BGFX_FUNCTION_ID_ENCODER_BEGIN", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_BEGIN), das::LineInfo());
		addIEx("ENCODER_END", "BGFX_FUNCTION_ID_ENCODER_END", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_END), das::LineInfo());
		addIEx("ENCODER_SET_MARKER", "BGFX_FUNCTION_ID_ENCODER_SET_MARKER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_MARKER), das::LineInfo());
		addIEx("ENCODER_SET_STATE", "BGFX_FUNCTION_ID_ENCODER_SET_STATE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_STATE), das::LineInfo());
		addIEx("ENCODER_SET_CONDITION", "BGFX_FUNCTION_ID_ENCODER_SET_CONDITION", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_CONDITION), das::LineInfo());
		addIEx("ENCODER_SET_STENCIL", "BGFX_FUNCTION_ID_ENCODER_SET_STENCIL", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_STENCIL), das::LineInfo());
		addIEx("ENCODER_SET_SCISSOR", "BGFX_FUNCTION_ID_ENCODER_SET_SCISSOR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_SCISSOR), das::LineInfo());
		addIEx("ENCODER_SET_SCISSOR_CACHED", "BGFX_FUNCTION_ID_ENCODER_SET_SCISSOR_CACHED", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_SCISSOR_CACHED), das::LineInfo());
		addIEx("ENCODER_SET_TRANSFORM", "BGFX_FUNCTION_ID_ENCODER_SET_TRANSFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_TRANSFORM), das::LineInfo());
		addIEx("ENCODER_SET_TRANSFORM_CACHED", "BGFX_FUNCTION_ID_ENCODER_SET_TRANSFORM_CACHED", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_TRANSFORM_CACHED), das::LineInfo());
		addIEx("ENCODER_ALLOC_TRANSFORM", "BGFX_FUNCTION_ID_ENCODER_ALLOC_TRANSFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_ALLOC_TRANSFORM), das::LineInfo());
		addIEx("ENCODER_SET_UNIFORM", "BGFX_FUNCTION_ID_ENCODER_SET_UNIFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_UNIFORM), das::LineInfo());
		addIEx("ENCODER_SET_INDEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_INDEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_DYNAMIC_INDEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_DYNAMIC_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_DYNAMIC_INDEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_TRANSIENT_INDEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_TRANSIENT_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_TRANSIENT_INDEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_VERTEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_VERTEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_VERTEX_BUFFER_WITH_LAYOUT", "BGFX_FUNCTION_ID_ENCODER_SET_VERTEX_BUFFER_WITH_LAYOUT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_VERTEX_BUFFER_WITH_LAYOUT), das::LineInfo());
		addIEx("ENCODER_SET_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_DYNAMIC_VERTEX_BUFFER_WITH_LAYOUT", "BGFX_FUNCTION_ID_ENCODER_SET_DYNAMIC_VERTEX_BUFFER_WITH_LAYOUT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_DYNAMIC_VERTEX_BUFFER_WITH_LAYOUT), das::LineInfo());
		addIEx("ENCODER_SET_TRANSIENT_VERTEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_TRANSIENT_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_TRANSIENT_VERTEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_TRANSIENT_VERTEX_BUFFER_WITH_LAYOUT", "BGFX_FUNCTION_ID_ENCODER_SET_TRANSIENT_VERTEX_BUFFER_WITH_LAYOUT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_TRANSIENT_VERTEX_BUFFER_WITH_LAYOUT), das::LineInfo());
		addIEx("ENCODER_SET_VERTEX_COUNT", "BGFX_FUNCTION_ID_ENCODER_SET_VERTEX_COUNT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_VERTEX_COUNT), das::LineInfo());
		addIEx("ENCODER_SET_INSTANCE_DATA_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_INSTANCE_DATA_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_INSTANCE_DATA_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_INSTANCE_DATA_FROM_VERTEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_INSTANCE_DATA_FROM_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_INSTANCE_DATA_FROM_VERTEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_INSTANCE_DATA_FROM_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_INSTANCE_DATA_FROM_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_INSTANCE_DATA_FROM_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_INSTANCE_COUNT", "BGFX_FUNCTION_ID_ENCODER_SET_INSTANCE_COUNT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_INSTANCE_COUNT), das::LineInfo());
		addIEx("ENCODER_SET_TEXTURE", "BGFX_FUNCTION_ID_ENCODER_SET_TEXTURE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_TEXTURE), das::LineInfo());
		addIEx("ENCODER_TOUCH", "BGFX_FUNCTION_ID_ENCODER_TOUCH", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_TOUCH), das::LineInfo());
		addIEx("ENCODER_SUBMIT", "BGFX_FUNCTION_ID_ENCODER_SUBMIT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SUBMIT), das::LineInfo());
		addIEx("ENCODER_SUBMIT_OCCLUSION_QUERY", "BGFX_FUNCTION_ID_ENCODER_SUBMIT_OCCLUSION_QUERY", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SUBMIT_OCCLUSION_QUERY), das::LineInfo());
		addIEx("ENCODER_SUBMIT_INDIRECT", "BGFX_FUNCTION_ID_ENCODER_SUBMIT_INDIRECT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SUBMIT_INDIRECT), das::LineInfo());
		addIEx("ENCODER_SET_COMPUTE_INDEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_INDEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_COMPUTE_VERTEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_VERTEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_COMPUTE_DYNAMIC_INDEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_DYNAMIC_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_DYNAMIC_INDEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_COMPUTE_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_COMPUTE_INDIRECT_BUFFER", "BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_INDIRECT_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_COMPUTE_INDIRECT_BUFFER), das::LineInfo());
		addIEx("ENCODER_SET_IMAGE", "BGFX_FUNCTION_ID_ENCODER_SET_IMAGE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_SET_IMAGE), das::LineInfo());
		addIEx("ENCODER_DISPATCH", "BGFX_FUNCTION_ID_ENCODER_DISPATCH", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_DISPATCH), das::LineInfo());
		addIEx("ENCODER_DISPATCH_INDIRECT", "BGFX_FUNCTION_ID_ENCODER_DISPATCH_INDIRECT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_DISPATCH_INDIRECT), das::LineInfo());
		addIEx("ENCODER_DISCARD", "BGFX_FUNCTION_ID_ENCODER_DISCARD", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_DISCARD), das::LineInfo());
		addIEx("ENCODER_BLIT", "BGFX_FUNCTION_ID_ENCODER_BLIT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ENCODER_BLIT), das::LineInfo());
		addIEx("REQUEST_SCREEN_SHOT", "BGFX_FUNCTION_ID_REQUEST_SCREEN_SHOT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_REQUEST_SCREEN_SHOT), das::LineInfo());
		addIEx("RENDER_FRAME", "BGFX_FUNCTION_ID_RENDER_FRAME", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_RENDER_FRAME), das::LineInfo());
		addIEx("SET_PLATFORM_DATA", "BGFX_FUNCTION_ID_SET_PLATFORM_DATA", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_PLATFORM_DATA), das::LineInfo());
		addIEx("GET_INTERNAL_DATA", "BGFX_FUNCTION_ID_GET_INTERNAL_DATA", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_GET_INTERNAL_DATA), das::LineInfo());
		addIEx("OVERRIDE_INTERNAL_TEXTURE_PTR", "BGFX_FUNCTION_ID_OVERRIDE_INTERNAL_TEXTURE_PTR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_OVERRIDE_INTERNAL_TEXTURE_PTR), das::LineInfo());
		addIEx("OVERRIDE_INTERNAL_TEXTURE", "BGFX_FUNCTION_ID_OVERRIDE_INTERNAL_TEXTURE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_OVERRIDE_INTERNAL_TEXTURE), das::LineInfo());
		addIEx("SET_MARKER", "BGFX_FUNCTION_ID_SET_MARKER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_MARKER), das::LineInfo());
		addIEx("SET_STATE", "BGFX_FUNCTION_ID_SET_STATE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_STATE), das::LineInfo());
		addIEx("SET_CONDITION", "BGFX_FUNCTION_ID_SET_CONDITION", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_CONDITION), das::LineInfo());
		addIEx("SET_STENCIL", "BGFX_FUNCTION_ID_SET_STENCIL", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_STENCIL), das::LineInfo());
		addIEx("SET_SCISSOR", "BGFX_FUNCTION_ID_SET_SCISSOR", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_SCISSOR), das::LineInfo());
		addIEx("SET_SCISSOR_CACHED", "BGFX_FUNCTION_ID_SET_SCISSOR_CACHED", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_SCISSOR_CACHED), das::LineInfo());
		addIEx("SET_TRANSFORM", "BGFX_FUNCTION_ID_SET_TRANSFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_TRANSFORM), das::LineInfo());
		addIEx("SET_TRANSFORM_CACHED", "BGFX_FUNCTION_ID_SET_TRANSFORM_CACHED", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_TRANSFORM_CACHED), das::LineInfo());
		addIEx("ALLOC_TRANSFORM", "BGFX_FUNCTION_ID_ALLOC_TRANSFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_ALLOC_TRANSFORM), das::LineInfo());
		addIEx("SET_UNIFORM", "BGFX_FUNCTION_ID_SET_UNIFORM", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_UNIFORM), das::LineInfo());
		addIEx("SET_INDEX_BUFFER", "BGFX_FUNCTION_ID_SET_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_INDEX_BUFFER), das::LineInfo());
		addIEx("SET_DYNAMIC_INDEX_BUFFER", "BGFX_FUNCTION_ID_SET_DYNAMIC_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_DYNAMIC_INDEX_BUFFER), das::LineInfo());
		addIEx("SET_TRANSIENT_INDEX_BUFFER", "BGFX_FUNCTION_ID_SET_TRANSIENT_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_TRANSIENT_INDEX_BUFFER), das::LineInfo());
		addIEx("SET_VERTEX_BUFFER", "BGFX_FUNCTION_ID_SET_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VERTEX_BUFFER), das::LineInfo());
		addIEx("SET_VERTEX_BUFFER_WITH_LAYOUT", "BGFX_FUNCTION_ID_SET_VERTEX_BUFFER_WITH_LAYOUT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VERTEX_BUFFER_WITH_LAYOUT), das::LineInfo());
		addIEx("SET_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_SET_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("SET_DYNAMIC_VERTEX_BUFFER_WITH_LAYOUT", "BGFX_FUNCTION_ID_SET_DYNAMIC_VERTEX_BUFFER_WITH_LAYOUT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_DYNAMIC_VERTEX_BUFFER_WITH_LAYOUT), das::LineInfo());
		addIEx("SET_TRANSIENT_VERTEX_BUFFER", "BGFX_FUNCTION_ID_SET_TRANSIENT_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_TRANSIENT_VERTEX_BUFFER), das::LineInfo());
		addIEx("SET_TRANSIENT_VERTEX_BUFFER_WITH_LAYOUT", "BGFX_FUNCTION_ID_SET_TRANSIENT_VERTEX_BUFFER_WITH_LAYOUT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_TRANSIENT_VERTEX_BUFFER_WITH_LAYOUT), das::LineInfo());
		addIEx("SET_VERTEX_COUNT", "BGFX_FUNCTION_ID_SET_VERTEX_COUNT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_VERTEX_COUNT), das::LineInfo());
		addIEx("SET_INSTANCE_DATA_BUFFER", "BGFX_FUNCTION_ID_SET_INSTANCE_DATA_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_INSTANCE_DATA_BUFFER), das::LineInfo());
		addIEx("SET_INSTANCE_DATA_FROM_VERTEX_BUFFER", "BGFX_FUNCTION_ID_SET_INSTANCE_DATA_FROM_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_INSTANCE_DATA_FROM_VERTEX_BUFFER), das::LineInfo());
		addIEx("SET_INSTANCE_DATA_FROM_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_SET_INSTANCE_DATA_FROM_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_INSTANCE_DATA_FROM_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("SET_INSTANCE_COUNT", "BGFX_FUNCTION_ID_SET_INSTANCE_COUNT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_INSTANCE_COUNT), das::LineInfo());
		addIEx("SET_TEXTURE", "BGFX_FUNCTION_ID_SET_TEXTURE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_TEXTURE), das::LineInfo());
		addIEx("TOUCH", "BGFX_FUNCTION_ID_TOUCH", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_TOUCH), das::LineInfo());
		addIEx("SUBMIT", "BGFX_FUNCTION_ID_SUBMIT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SUBMIT), das::LineInfo());
		addIEx("SUBMIT_OCCLUSION_QUERY", "BGFX_FUNCTION_ID_SUBMIT_OCCLUSION_QUERY", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SUBMIT_OCCLUSION_QUERY), das::LineInfo());
		addIEx("SUBMIT_INDIRECT", "BGFX_FUNCTION_ID_SUBMIT_INDIRECT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SUBMIT_INDIRECT), das::LineInfo());
		addIEx("SET_COMPUTE_INDEX_BUFFER", "BGFX_FUNCTION_ID_SET_COMPUTE_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_COMPUTE_INDEX_BUFFER), das::LineInfo());
		addIEx("SET_COMPUTE_VERTEX_BUFFER", "BGFX_FUNCTION_ID_SET_COMPUTE_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_COMPUTE_VERTEX_BUFFER), das::LineInfo());
		addIEx("SET_COMPUTE_DYNAMIC_INDEX_BUFFER", "BGFX_FUNCTION_ID_SET_COMPUTE_DYNAMIC_INDEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_COMPUTE_DYNAMIC_INDEX_BUFFER), das::LineInfo());
		addIEx("SET_COMPUTE_DYNAMIC_VERTEX_BUFFER", "BGFX_FUNCTION_ID_SET_COMPUTE_DYNAMIC_VERTEX_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_COMPUTE_DYNAMIC_VERTEX_BUFFER), das::LineInfo());
		addIEx("SET_COMPUTE_INDIRECT_BUFFER", "BGFX_FUNCTION_ID_SET_COMPUTE_INDIRECT_BUFFER", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_COMPUTE_INDIRECT_BUFFER), das::LineInfo());
		addIEx("SET_IMAGE", "BGFX_FUNCTION_ID_SET_IMAGE", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_SET_IMAGE), das::LineInfo());
		addIEx("DISPATCH", "BGFX_FUNCTION_ID_DISPATCH", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DISPATCH), das::LineInfo());
		addIEx("DISPATCH_INDIRECT", "BGFX_FUNCTION_ID_DISPATCH_INDIRECT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DISPATCH_INDIRECT), das::LineInfo());
		addIEx("DISCARD", "BGFX_FUNCTION_ID_DISCARD", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_DISCARD), das::LineInfo());
		addIEx("BLIT", "BGFX_FUNCTION_ID_BLIT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_BLIT), das::LineInfo());
		addIEx("COUNT", "BGFX_FUNCTION_ID_COUNT", int64_t(bgfx_function_id::BGFX_FUNCTION_ID_COUNT), das::LineInfo());
	}
};

