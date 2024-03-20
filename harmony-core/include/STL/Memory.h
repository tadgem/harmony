#ifndef HARMONY_CORE_STL_MEMORY_H
#define HARMONY_CORE_STL_MEMORY_H
#include <memory>
namespace harmony
{
    template <typename A, typename B>
    inline auto SmartPointerCast(const std::shared_ptr<B>& ptr)
    {
        return std::static_pointer_cast<A>(ptr);
    }


    template<typename T>
    using UPtr = std::unique_ptr<T>;

    template<typename T, typename D>
    using CustomUPtr = std::unique_ptr<T, D>;

    template<typename T, typename ... Args>
    constexpr UPtr<T> CreateUnique(Args &&... args) {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    /// <summary>
    /// Reference counting pointer
    /// Systems owning objects should create a RefCntPtr
    /// </summary>
    /// <typeparam name="T"></typeparam>
    template<typename T>
    using RefCntPtr = std::shared_ptr<T>;

    template<typename T, typename ... Args>
    constexpr RefCntPtr<T> CreateRef(Args &&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    /// <summary>
    /// Weak Pointer to a RefCntPtr
    /// Systems which need access to an object but do not own it+
    /// should be passed a weak reference.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    template<typename T>
    using WeakPtr = std::weak_ptr<T>;

    template<typename T>
    constexpr WeakPtr<T> GetWeakRef(RefCntPtr<T> ref) {
        return std::weak_ptr<T>(ref);
    }

    template<typename Base, typename Derived>
    constexpr RefCntPtr<Derived> GetDerivedRef(RefCntPtr<Base> baseRef) {
        return std::static_pointer_cast<Derived, Base>(baseRef);
    }

    template<typename Base, typename Derived>
    constexpr RefCntPtr<Derived> GetDerivedRef(WeakPtr<Base> baseWeakRef) {
        RefCntPtr<Base> baseRef = baseWeakRef.lock();
        return std::static_pointer_cast<Derived, Base>(baseRef);
    }

}

#endif