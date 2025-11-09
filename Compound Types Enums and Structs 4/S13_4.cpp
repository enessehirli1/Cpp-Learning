#include <iostream>
#include <type_traits>
#include <utility>
#include "pair.h"

void foo();

int main()
{
	Pair<double> p2{ 3.4, 5.6 };
	std::cout << max(p2) << " is larger\n";

	foo();

	return 0;
}

/*
template <typename T, typename U>
struct Pair
{
	T first{};
	U second{};
};

template <typename T, typename U>
constexpr std::common_type_t<T, U> max(Pair<T, U> p) // std::common_type_t veri kaybını önledi
{
	return (p.first < p.second ? p.second : p.first);
}


int main()
{
	Pair<int, int> p1{ 1,3 };
	std::cout << max(p1) << '\n';

	Pair<double, double> p2{ 27.54, 11.32 };
	std::cout << max(p2) << '\n';

	Pair<double, int> p3{ 17.23, 9 };
	std::cout << max(p3) << '\n';

	Pair<int, double> p4{ 8, 2.45 };
	std::cout << max(p4) << '\n';


	return 0;
}



template <typename T, typename U>
void print(std::pair<T, U> p)
{
	std::cout << "[" << p.first << ", " << p.second << "]";
}


int main()
{
	std::pair<int, double> p1{ 1, 2.3 }; // a pair holding an int and a double
	std::pair<double, int> p2{ 4.5, 6 }; // a pair holding a double and an int
	std::pair<int, int> p3{ 7, 8 };      // a pair holding two ints

	print(p2);

	return 0;
}
*/
