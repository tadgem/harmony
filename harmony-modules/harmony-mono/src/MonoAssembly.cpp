#include "MonoAssembly.h"
#include "MonoUtils.h"

harmony::MonoAssemblyAsset::MonoAssemblyAsset(std::vector<uint8_t> assemblyBinary, const String& assemblyPath) :
	Asset(),
	p_AssemblyBinary(assemblyBinary), 
	m_AssemblyPath(assemblyPath),
	p_MonoAssembly(MonoUtils::LoadCSharpAssembly(m_AssemblyPath, (char*)p_AssemblyBinary.data(), p_AssemblyBinary.size()))
{
    CollectAssemblyData();
}

harmony::MonoAssemblyAsset::~MonoAssemblyAsset()
{
	MonoUtils::FreeCSharpAssembly(p_MonoAssembly);
}

void harmony::MonoAssemblyAsset::CollectAssemblyData()
{
    MonoImage* image = mono_assembly_get_image((MonoAssembly*) p_MonoAssembly);

    const MonoTableInfo* typeDefinitionsTable = mono_image_get_table_info(image, MONO_TABLE_TYPEDEF);
    const MonoTableInfo* interfaceImplTable = mono_image_get_table_info(image, MONO_TABLE_INTERFACEIMPL);
    const MonoTableInfo* typeSpecTable = mono_image_get_table_info(image, MONO_TABLE_TYPESPEC);
    const MonoTableInfo* methodImplTable = mono_image_get_table_info(image, MONO_TABLE_METHODIMPL);
    const MonoTableInfo* typeRefTable = mono_image_get_table_info(image, MONO_TABLE_TYPEREF);
    const MonoTableInfo* assemblyRefTable = mono_image_get_table_info(image, MONO_TABLE_ASSEMBLYREF);

    int32_t numTypes = mono_table_info_get_rows(typeDefinitionsTable);
    int32_t numInterfaces = mono_table_info_get_rows(interfaceImplTable);
    int32_t numTypeSpecs = mono_table_info_get_rows(typeSpecTable);
    int32_t numMethodImpls = mono_table_info_get_rows(methodImplTable);
    int32_t numTypeRefs = mono_table_info_get_rows(typeRefTable);
    int32_t numRefs = mono_table_info_get_rows(assemblyRefTable);


    for (int32_t i = 0; i < numTypes; i++)
    {
        uint32_t cols[MONO_TYPEDEF_SIZE];
        mono_metadata_decode_row(typeDefinitionsTable, i, cols, MONO_TYPEDEF_SIZE);

        String nameSpace = String(mono_metadata_string_heap(image, cols[MONO_TYPEDEF_NAMESPACE]));
        String name = String(mono_metadata_string_heap(image, cols[MONO_TYPEDEF_NAME]));

        MonoUtils::CsTypeInfo typeInfo{
                name,
                nameSpace
        };

        m_TypeInfos.emplace_back(typeInfo);
    }

    for (int32_t i = 0; i < numInterfaces; i++)
    {
        uint32_t cols[MONO_INTERFACEIMPL_SIZE];
        mono_metadata_decode_row(interfaceImplTable, i, cols, MONO_INTERFACEIMPL_SIZE);

        uint32_t interface = cols[MONO_INTERFACEIMPL_INTERFACE];
        uint32_t klass =  cols[MONO_INTERFACEIMPL_CLASS];
        MonoUtils::CsInterfaceImplInfo interfaceImplInfo{
                interface,
                klass
        };

        m_InterfaceImplInfos.emplace_back(interfaceImplInfo);
    }

    for (int32_t i = 0; i < numMethodImpls; i++)
    {
        uint32_t cols[MONO_METHODIMPL_SIZE];
        mono_metadata_decode_row(typeSpecTable, i, cols, MONO_METHODIMPL_SIZE);

        String declaration = String(mono_metadata_string_heap(image, cols[MONO_METHODIMPL_DECLARATION]));
        String body = String(mono_metadata_string_heap(image, cols[MONO_METHODIMPL_BODY]));
        String klass = String(mono_metadata_string_heap(image, cols[MONO_METHODIMPL_CLASS]));

        MonoUtils::CsMethodImplInfo methodInfo {declaration, body, klass};
        m_MethodImplInfos.push_back(methodInfo);

    }

    for (int32_t i = 0; i < numTypeRefs; i++)
    {
        uint32_t cols[MONO_TYPEREF_SIZE];
        mono_metadata_decode_row(typeRefTable, i, cols, MONO_TYPEREF_SIZE);

        String name = String(mono_metadata_string_heap(image, cols[MONO_TYPEREF_NAME]));
        String nameSpace = String(mono_metadata_string_heap(image, cols[MONO_TYPEREF_NAMESPACE]));
        String scope = String(mono_metadata_string_heap(image, cols[MONO_TYPEREF_SCOPE]));

        MonoUtils::CsTypeRefInfo methodInfo {name, nameSpace, scope};
        m_TypeRefInfos.push_back(methodInfo);
    }

    for (int32_t i = 0; i < numRefs; i++)
    {
        uint32_t cols[MONO_ASSEMBLYREF_SIZE];
        mono_metadata_decode_row(assemblyRefTable, i, cols, MONO_ASSEMBLYREF_SIZE);
        String name = String(mono_metadata_string_heap(image, cols[MONO_ASSEMBLYREF_NAME]));

        uint32_t majorVersion = cols[MONO_ASSEMBLYREF_MAJOR_VERSION];
        uint32_t minorVersion = cols[MONO_ASSEMBLYREF_MINOR_VERSION];

        MonoUtils::CsAssemblyRefInfo assemblyRefInfo {name, majorVersion, minorVersion};
        m_AssemblyRefInfos.push_back(assemblyRefInfo);
    }
}
