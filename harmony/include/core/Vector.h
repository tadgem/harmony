#pragma once
#include <vector>

namespace harmony
{
  template<typename _Type>
  class TVector
  {
  public:

    _Type&  get(size_t index) {return pInternal.at(index);}
    void    set(size_t index, const _Type& v) { pInternal[index] = v; }
    void    push(const _Type& v) { pInternal.push_back(v); }
    void    pop()   {return pInternal.pop_back(); }
    _Type&  last()  {return pInternal.back();     }
    _Type&  front() {return pInternal.front();    }
    auto    begin() {return pInternal.begin();    }
    auto    end()   {return pInternal.end();      }

  private:
    std::vector<_Type> pInternal;
  };
}