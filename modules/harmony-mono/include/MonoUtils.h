#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include "mono/jit/jit.h"
#include "mono/metadata/assembly.h"
#include "mono/metadata/attrdefs.h"

namespace harmony
{
    namespace MonoUtils
    {
        enum Accessibility : uint8_t
        {
            None = 0,
            Private = (1 << 0),
            Internal = (1 << 1),
            Protected = (1 << 2),
            Public = (1 << 3)
        };

        struct CsTypeInfo
        {
            std::string m_TypeName;
            std::string m_TypeNamespace;
        };

        struct CsInterfaceImplInfo
        {
            std::string m_InterfaceName;
            std::string m_ClassName;
        };

        Accessibility GetFieldAccessibility(MonoClassField* field);

        Accessibility GetPropertyAccessbility(MonoProperty* property);

        MonoAssembly* LoadCSharpAssembly(const std::string& assemblyPath, char* fileData, uint32_t fileSize);

        void FreeCSharpAssembly(const MonoAssembly* assembly);

        MonoClass* GetClassInAssembly(MonoAssembly* assembly, const char* namespaceName, const char* className);
    }
}