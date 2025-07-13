#include <iostream>
#include "core/Vector.h"
#include "core/HashMap.h"
#include "core/String.h"

using namespace harmony;

int main(int argc, char *argv[])
{
  TVector<int> ints {};
  THashMap<int, float> floats {};
  THashMap<String, int> nameAndAges{};
  String s = "Hello";
  ints.push(2);
  ints.push(2);
  ints.set(0, 1);

  floats.emplace(1, 0.0f);
  floats.emplace(5, 2.0f);
  floats.emplace(10,4.0f);

  nameAndAges.emplace("john", 20);
  for(auto i : ints)
  {
    std::cout << i << "\n";
  }

  for(auto[key, value] : floats)
  {
    std::cout << key << " : " << value << "\n";
  }

  std::cout << "Hello world\n";
}