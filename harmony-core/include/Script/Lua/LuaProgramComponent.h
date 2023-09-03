#pragma once

#include "Core/ProgramComponent.h"
#include "Core/Alias.h"
#include "Assets/Asset.h"
#include "sol.hpp"

namespace harmony
{
	class AssetManager;
	class LuaScriptAsset;
	class LuaProgramComponent : public ProgramComponent
	{
	public:
		LuaProgramComponent(AssetManager& am);
		virtual void Init() override;
		virtual void Update() override;
		virtual void Render() override;
		virtual void Cleanup() override;
		virtual nlohmann::json ToJson() override;
		virtual void FromJson(const nlohmann::json &json) override;

	protected:
		AssetManager&					p_AssetManager;
		sol::state						p_State;
		Vector<AssetHandle> 			p_LuaProgramScripts;
		Vector<WeakRef<LuaScriptAsset>> p_LuaScriptAssets;
		
		void RedirectPrintOutput();
		
		friend class LuaSystem;
	};
}