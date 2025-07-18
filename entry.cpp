#include <iostream>
#include "stl/Vector.h"
#include "stl/HashMap.h"
#include "stl/String.h"
#include "stl/Memory.h"

using namespace harmony;

struct something
{
  HashMap<String, int> Names;
};

int main(int argc, char *argv[])
{
  Vector<int> ints {};
  HashMap<int, float> floats {};
  HashMap<String, int> namesAndAges{};
  String s = "Hello";

  Unique<something> uptr = MakeUnique<something>();

  ints.push(2);
  ints.push(2);
  ints.set(0, 1);

  floats.emplace(1, 0.0f);
  floats.emplace(5, 2.0f);
  floats.emplace(10,4.0f);

  namesAndAges.emplace("john", 20);
  namesAndAges.emplace("joe", 30);
  namesAndAges.emplace("jordan", 40);

  for(auto i : ints)
  {
    std::cout << i << "\n";
  }

  for(auto[key, value] : floats)
  {
    std::cout << key << " : " << value << "\n";
  }

  for(auto& [key, value] : namesAndAges)
  {
    std::cout << key.c_str() << " : " << value << "\n";
  }

  std::cout << "Hello world\n";
}