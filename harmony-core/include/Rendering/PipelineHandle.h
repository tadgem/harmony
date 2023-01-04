#pragma once
#include <string>
#include "ThirdParty/json.hpp"

struct PipelineHandle
{
public:
    PipelineHandle(std::string name) : Name(name), Index(s_InstanceCounter)
    {
        s_InstanceCounter++;
    }
    PipelineHandle() : Index(s_InstanceCounter)
    {
        s_InstanceCounter++;
    }
    std::string Name;
    uint32_t Index;

    bool operator==(const PipelineHandle& other) const { return other.Name == Name; }
    bool operator!=(const PipelineHandle& other) const { return other.Name != Name; }
    bool operator< (const PipelineHandle& other) const { return Index < other.Index; }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(PipelineHandle, Name)
private:
    inline static uint32_t s_InstanceCounter = 0;
    friend class Pipeline;
};