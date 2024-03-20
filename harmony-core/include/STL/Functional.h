#ifndef HARMONY_CORE_STL_FUNCTIONAL_H
#define HARMONY_CORE_STL_FUNCTIONAL_H

#include <functional>
namespace harmony
{
	template<typename T>
	using Lambda = std::function<T>;

	using Procedure = std::function<void()>;
}
#endif