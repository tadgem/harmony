#pragma once

#include "Assets/Asset.h"
#include <utility>

namespace harmony::GraphScript
{
	class GraphScriptAsset
	{
	public:
		explicit GraphScriptAsset(nlohmann::json graphScriptJson)
				: m_JSON(std::move(graphScriptJson))
		{
		};

		const nlohmann::json m_JSON;
	};
}; // namespace harmony::GraphScript