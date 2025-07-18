#pragma once

#include <functional>
namespace harmony
{
	template<typename T>
	using Lambda = std::function<T>;

	using Procedure = std::function<void()>;
}