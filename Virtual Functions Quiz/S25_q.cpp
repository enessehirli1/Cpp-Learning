#include <iostream>
#include <vector>
#include "Shape.h"
#include "Point.h"

int getLargestRadius(const std::vector<std::unique_ptr<Shape>>& vec)
{
	int largest{ 0 };
	for (const auto& e : vec)
	{
		if (auto c = dynamic_cast<Circle*>(e.get()))
			largest = std::max(largest, c->getRadius());
	}

	return largest;
}


int main()
{
    
	std::vector<std::unique_ptr<Shape>> v;
	v.reserve(3);
	v.push_back(std::make_unique<Circle>(Point{ 1,2 }, 7));
	v.push_back(std::make_unique<Triangle>(Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }));
	v.push_back(std::make_unique<Circle>(Point{ 7, 8 }, 3));

	// print each shape in vector v on its own line here
	for (const auto& e : v)
	{
		std::cout << *e << '\n';
	}

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function


	return 0;
}