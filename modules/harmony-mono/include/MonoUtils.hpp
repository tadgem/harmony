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

        Accessibility GetFieldAccessibility(MonoClassField* field)
        {
            uint8_t accessibility = Accessibility::None;
            uint32_t accessFlag = mono_field_get_flags(field) & MONO_FIELD_ATTR_FIELD_ACCESS_MASK;

            switch (accessFlag)
            {
            case MONO_FIELD_ATTR_PRIVATE:
            {
                accessibility = Accessibility::Private;
                break;
            }
            case MONO_FIELD_ATTR_FAM_AND_ASSEM:
            {
                accessibility |= Accessibility::Protected;
                accessibility |= Accessibility::Internal;
                break;
            }
            case MONO_FIELD_ATTR_ASSEMBLY:
            {
                accessibility = Accessibility::Internal;
                break;
            }
            case MONO_FIELD_ATTR_FAMILY:
            {
                accessibility = Accessibility::Protected;
                break;
            }
            case MONO_FIELD_ATTR_FAM_OR_ASSEM:
            {
                accessibility |= Accessibility::Private;
                accessibility |= Accessibility::Protected;
                break;
            }
            case MONO_FIELD_ATTR_PUBLIC:
            {
                accessibility = Accessibility::Public;
                break;
            }

            }
            return (Accessibility)accessibility;
        }

        Accessibility GetPropertyAccessbility(MonoProperty* property)
        {
            uint8_t accessibility = (uint8_t)Accessibility::None;

            // Get a reference to the property's getter method
            MonoMethod* propertyGetter = mono_property_get_get_method(property);
            if (propertyGetter != nullptr)
            {
                // Extract the access flags from the getters flags
                uint32_t accessFlag = mono_method_get_flags(propertyGetter, nullptr) & MONO_METHOD_ATTR_ACCESS_MASK;

                switch (accessFlag)
                {
                case MONO_FIELD_ATTR_PRIVATE:
                {
                    accessibility = (uint8_t)Accessibility::Private;
                    break;
                }
                case MONO_FIELD_ATTR_FAM_AND_ASSEM:
                {
                    accessibility |= (uint8_t)Accessibility::Protected;
                    accessibility |= (uint8_t)Accessibility::Internal;
                    break;
                }
                case MONO_FIELD_ATTR_ASSEMBLY:
                {
                    accessibility = (uint8_t)Accessibility::Internal;
                    break;
                }
                case MONO_FIELD_ATTR_FAMILY:
                {
                    accessibility = (uint8_t)Accessibility::Protected;
                    break;
                }
                case MONO_FIELD_ATTR_FAM_OR_ASSEM:
                {
                    accessibility |= (uint8_t)Accessibility::Private;
                    accessibility |= (uint8_t)Accessibility::Protected;
                    break;
                }
                case MONO_FIELD_ATTR_PUBLIC:
                {
                    accessibility = (uint8_t)Accessibility::Public;
                    break;
                }
                }
            }

            // Get a reference to the property's setter method
            MonoMethod* propertySetter = mono_property_get_set_method(property);
            if (propertySetter != nullptr)
            {
                // Extract the access flags from the setters flags
                uint32_t accessFlag = mono_method_get_flags(propertySetter, nullptr) & MONO_METHOD_ATTR_ACCESS_MASK;
                if (accessFlag != MONO_FIELD_ATTR_PUBLIC)
                    accessibility = (uint8_t)Accessibility::Private;
            }
            else
            {
                accessibility = (uint8_t)Accessibility::Private;
            }

            return (Accessibility)accessibility;
        }

        MonoAssembly* LoadCSharpAssembly(const std::string& assemblyPath, char* fileData, uint32_t fileSize)
        {
            MonoImageOpenStatus status;
            MonoImage* image = mono_image_open_from_data_full(fileData, fileSize, 1, &status, 0);

            if (status != MONO_IMAGE_OK)
            {
                const char* errorMessage = mono_image_strerror(status);
                std::cerr << "Failed to create MonoAssembly for assembly : " << errorMessage << std::endl;
                return nullptr;
            }

            MonoAssembly* assembly = mono_assembly_load_from_full(image, assemblyPath.c_str(), &status, 0);
            mono_image_close(image);

            // Don't forget to free the file data
            delete[] fileData;

            return assembly;
        }

        MonoClass* GetClassInAssembly(MonoAssembly* assembly, const char* namespaceName, const char* className)
        {
            MonoImage* image = mono_assembly_get_image(assembly);
            MonoClass* klass = mono_class_from_name(image, namespaceName, className);

            if (klass == nullptr)
            {
                // Log error here
                return nullptr;
            }

            return klass;
        }
    }
}