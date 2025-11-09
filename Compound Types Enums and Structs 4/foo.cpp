#include "pair.h"
#include <iostream>

void foo()
{
	Pair<int> p1{ 3, 5 };
	std::cout << max(p1) << " is larger\n";
}