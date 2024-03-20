#pragma once

#include "Core/Alias.h"

namespace harmony {

    class Memory {
    private:
        inline static uint64_t s_HarmonyAllocated = 0;
        inline static uint64_t s_HarmonyFreed = 0;
    public:
        inline static void AddAllocatedMemory(size_t allocated) {
            s_HarmonyAllocated += allocated;
        }

        inline static void AddFreedMemory(size_t freed) {
            s_HarmonyFreed += freed;
        }

        inline static uint64_t GetAllocatedMemory() {
            return s_HarmonyAllocated;
        }

        inline static uint64_t GetFreedMemory() {
            return s_HarmonyFreed;
        }
    };

#if defined(__APPLE__) || defined(__unix__) || defined(__unix)

    static String ParseUnixTypeName(const String& typeName)
    {
        bool    parseNs = false;
        int     nameSize = -1;
        Vector<String>    separatedNames      = Vector<String>();
        Vector<char>           numericAccumulator  = Vector<char>();
        Vector<char>           typeNameAccumulator = Vector<char>();

        for(int i = 0; i < typeName.size(); i++)
        {
            char c = typeName[i];
            if(nameSize < 0)
            {
                if(!parseNs && c == 'N')
                {
                    parseNs = true;
                    continue;
                }

                if(isdigit(c))
                {
                    numericAccumulator.emplace_back(c);
                    continue;
                }

                if(c == 'E' && i == (typeName.size() - 1))
                {
                    continue;
                }

                String finalSizeString = String(numericAccumulator.begin(), numericAccumulator.end());
                nameSize = stoi(finalSizeString);
                numericAccumulator.clear();
                if(nameSize > 0)
                {
                    typeNameAccumulator.emplace_back(c);
                    continue;
                }
            }

            if(typeNameAccumulator.size() < nameSize)
            {
                typeNameAccumulator.emplace_back(c);
                continue;
            }
            else
            {
                String name = String(typeNameAccumulator.begin(), typeNameAccumulator.end());
                separatedNames.emplace_back(name);
                typeNameAccumulator.clear();
                nameSize = -1;
                parseNs = false;
                numericAccumulator.emplace_back(c);
                continue;
            }

        }
        String finalTypeName = String();

        for(int i = 0; i < separatedNames.size(); i++)
        {
            finalTypeName += separatedNames[i];
            if(i != (separatedNames.size() - 1))
            {
                finalTypeName += "::";
            }
        }

        return finalTypeName;
    }
#endif


};

namespace nlohmann {
    template<typename T>
    struct adl_serializer<harmony::WeakPtr < T>> {
    static void to_json(json &j, const harmony::WeakPtr <T> &opt) {
        if (opt.expired()) {
            j = nullptr;
        } else {
            j = *opt.lock();
        }
    }

    static void from_json(const json &j, harmony::WeakPtr <T> &opt) {
        if (opt.expired()) {
            return;
        } else {
            harmony::RefCntPtr<T> o = opt.lock();
            *o.get() = j;
        }
    }
};

template<typename T>
struct adl_serializer<harmony::RefCntPtr<T>> {
    static void to_json(json &j, const harmony::RefCntPtr<T> &opt) {
        j = *opt;
    }

    static void from_json(const json &j, harmony::RefCntPtr<T> &opt) {
        *opt.get() = j;
    }
};

}
