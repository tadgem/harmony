#pragma once

#include "Core/ProgramComponent.h"
#include "Core/Alias.h"
#include "Assets/Asset.h"
#include "sol.hpp"

namespace harmony
{
	class LuaScriptAsset;
	class LuaProgramComponent : public ProgramComponent
	{
	public:
		LuaProgramComponent();
		virtual void Init() override;
		virtual void Update() override;
		virtual void Render() override;
		virtual void Cleanup() override;
		virtual nlohmann::json ToJson() override;
		virtual void FromJson(const nlohmann::json &json) override;

		Vector<AssetHandle> 			m_LuaProgramScripts;
		Vector<WeakRef<LuaScriptAsset>> m_LuaScriptAssets;

	protected:
		sol::state p_State;
		void RedirectPrintOutput();
		friend class LuaSystem;
	};
} // namespace harmony