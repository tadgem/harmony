#pragma once

#include "Core/Alias.h"
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

        enum InterfaceImplParentType
        {
            TypeDef = 0,
            TypeRef = 1,
            TypeSpec = 2
        };

        struct CsTypeInfo
        {
            String m_TypeName;
            String m_TypeNamespace;
            MonoClass* m_MonoClass;

            bool operator==(const CsTypeInfo& rhs) const;
        };

        struct CsTypeSpecInfo
        {
            String m_Signature;
        };

        struct CsInterfaceImplInfo
        {
            uint32_t m_InterfaceIndex;
            uint32_t m_ClassIndex;
            String m_InterfaceName;
            String m_InterfaceNamespace;
            String m_ClassName;
            String m_ClassNamespace;
            InterfaceImplParentType m_ParentType;
        };

        struct CsMethodImplInfo
        {
            String m_Declaration;
            String m_Body;
            String m_ClassName;
        };

        struct CsTypeRefInfo
        {
            String m_Name;
            String m_Namespace;
            String m_Scope;
        };

        struct CsAssemblyRefInfo
        {
            String m_Name;
            uint32_t    m_Major;
            uint32_t    m_Minor;
        };

        Accessibility GetFieldAccessibility(MonoClassField* field);

        Accessibility GetPropertyAccessbility(MonoProperty* property);

        MonoAssembly* LoadCSharpAssembly(const String& assemblyPath, char* fileData, uint32_t fileSize);

        void FreeCSharpAssembly(const MonoAssembly* assembly);

        MonoClass* GetClassInAssembly(MonoAssembly* assembly, const char* namespaceName, const char* className);

        MonoObject* CreateMonoObject(MonoDomain* appDomain, CsTypeInfo& klass);
    }
}