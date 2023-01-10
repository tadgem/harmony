#pragma once
#include "Core/ProgramComponent.h"
#include "lua.h"
#include "lualib.h"
namespace harmony
{
    struct LuauBytecode
    {
        char*       Bytecode;
        size_t      BytecodeSize;
        std::string ChunkName;
    };

    class LuaProgramComponent : public ProgramComponent
    {
    public:
        LuaProgramComponent();
        virtual void Init() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Cleanup() override;
        virtual nlohmann::json ToJson() override;
        virtual void FromJson(const nlohmann::json& json) override;

        LuauBytecode    GetBytecode(const std::string& source, const std::string& chunkName);
        int             RunBytecode(lua_State* state, const LuauBytecode& bc, int env = 0);
        
    protected:
        friend class LuaSystem;

        lua_State* p_State;


    };
}