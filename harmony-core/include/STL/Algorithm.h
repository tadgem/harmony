#ifndef HARMONY_CORE_STL_ALGORITHM_H
#define HARMONY_CORE_STL_ALGORITHM_H
#include <algorithm>

namespace harmony
{
    template <class _InIt, class _Ty>
    _InIt Find(_InIt _First, const _InIt _Last, const _Ty& _Val) {
        return std::find(_First, _Last, _Val);
    }

    template <class _InIt, class _Pr>
    _InIt FindIf(_InIt _First, const _InIt _Last, _Pr _Pred)
    {
        return std::find_if(_First, _Last, _Pred);
    }

}
#endif