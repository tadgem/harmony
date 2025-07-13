#pragma once
#include <string>

namespace harmony
{
class String
{
public:
  String(const char* c) : pInternal(c) {}

  size_t length() { return pInternal.length();}

  [[nodiscard]] const char* c_str() const { return pInternal.c_str();}

  bool operator==(const String &other) const
  {
    return pInternal == other.pInternal;
  }

private:
  std::string pInternal;

  friend struct std::hash<String>;
};
}
template <>
struct std::hash<harmony::String>
{
  std::size_t operator()(const harmony::String& k) const
  {
    using std::size_t;
    using std::hash;
    using std::string;

    // Compute individual hash values for first,
    // second and third and combine them using XOR
    // and bit shifting:

    return hash<string>()(k.pInternal);
  }
};