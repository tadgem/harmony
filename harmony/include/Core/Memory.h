#pragma once

#include <memory>
#include <functional>
#include "json.hpp"


namespace harmony {

	template <typename T>
	static size_t GetTypeHash()
	{
		return typeid(T).hash_code();
	}

	/// <summary>
	/// Reference counting pointer
	/// Systems owning objects should create a Ref
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	/// <summary>
	/// Weak Pointer to a Ref
	/// Systems which need access to an object but do not own it
	/// should be passed a weak reference.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<typename T>
	using WeakRef = std::weak_ptr<T>;
	template<typename T>
	constexpr WeakRef<T> GetWeakRef(Ref<T> ref)
	{
		return std::weak_ptr<T>(ref);
	}

	template<typename Base, typename Derived>
	constexpr Ref<Derived> GetDerivedRef(Ref<Base> baseRef)
	{
		return std::static_pointer_cast<Derived, Base>(baseRef);
	}

	template<typename Base, typename Derived>
	constexpr Ref<Derived> GetDerivedRef(WeakRef<Base> baseWeakRef)
	{
		Ref<Base> baseRef = baseWeakRef.lock();
		return std::static_pointer_cast<Derived, Base>(baseRef);
	}


	template<typename T>
	using WeakRefCallback = std::function<void(Ref<T>)>;
	template<typename T>
	bool Scope(WeakRef<T> wr, WeakRefCallback<T> callback)
	{
		if (wr.expired()) return false;

		if (Ref<T> ref = wr.lock())
		{
			callback(ref);
		}
		return true;
	}

};

namespace nlohmann {
	template <typename T>
	struct adl_serializer<harmony::WeakRef<T>> {
		static void to_json(json& j, const harmony::WeakRef<T>& opt) {
			if (opt.expired()) {
				j = nullptr;
			}
			else {
				j = *opt.lock();
			}
		}

		static void from_json(const json& j, harmony::WeakRef<T>& opt) {
			if (opt.expired()) {
				return;
			}
			else {
				harmony::Ref<T> o = opt.lock();
				*o.get() = j;
			}
		}
	};
}
