#pragma once

#include "Core/Alias.h"
#include "STL/String.h"
namespace harmony {

    struct PipelineHandle {
    public:
        PipelineHandle(String name) : Name(name), Index(s_InstanceCounter) {
            s_InstanceCounter++;
        }

        PipelineHandle() : Index(s_InstanceCounter) {
            s_InstanceCounter++;
        }

        String Name;
        uint32_t Index;

        bool operator==(const PipelineHandle& other) const {
            return other.Name == Name;
        }

        bool operator!=(const PipelineHandle& other) const {
            return other.Name != Name;
        }

        bool operator<(const PipelineHandle& other) const {
            return Index < other.Index;
        }

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineHandle, Name)

    private:
        inline static uint32_t s_InstanceCounter = 0;

        friend class Pipeline;
    };
}