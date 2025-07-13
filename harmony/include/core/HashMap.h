#pragma once

#include <unordered_map>

namespace harmony
{
template<typename _KeyType, typename _ValueType>
class THashMap
{
public:

  _ValueType&   get(const _KeyType& key) {
    return pInternal.at(key);
  }
  void          set(const _KeyType& key, const _ValueType& v) {
    pInternal[key] = v;
  }
  void    emplace(const _KeyType& key, const _ValueType& v) {
    pInternal.emplace(key, v);
  }
  void    remove(const _KeyType& key)   {
    pInternal.erase(key);
  }

  size_t  size()  {return pInternal.size();}

  auto    begin() {return pInternal.begin();    }
  auto    end()   {return pInternal.end();      }

private:
  std::unordered_map<_KeyType, _ValueType> pInternal;
};
}