#include <iostream>
#include "Program.h"

int main()
{
	harmony::Program app("Harmony Test");
	app.Init();
	app.Run();
	std::cout << "Hello World!\n";
}