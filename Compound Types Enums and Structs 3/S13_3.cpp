#include <iostream>

struct Paw
{
	int claws{};
};

struct Animal
{
	std::string name{};
	Paw paw{};
};

int main()
{
	Animal puma{ "Puma", {4} };
	Animal* ptr{ &puma };

	std::cout << (ptr->paw).claws;

	return 0;
}




/*


struct Point
{
	double x{};
	double y{};
};

struct Triangle
{
	Point* a{};
	Point* b{};
	Point* c{};
};

int main()
{
	Point a{ 1, 2 };
	Point b{ 4, 12 };
	Point c{ 13, 7 };

	Triangle tr{&a, &b, &c};
	Triangle* ptr{ &tr };

	std::cout << ptr -> b -> y;


	return 0;
}
*/
