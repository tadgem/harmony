#pragma once
#include <string>

namespace harmony
{
class String
{
public:
  String(const char* c) : pInternal(c) {}

  size_t length() { return pInternal.length();}

private:
  std::string pInternal;
};
}