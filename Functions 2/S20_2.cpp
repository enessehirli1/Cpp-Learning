#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <vector>
#include "Random.h"	
#include <iterator>
#include <cassert>

int binarySearch(const int* array, int target, int min, int max)
{
	assert(array);
	while (min <= max)
	{
		int midpoint{ (min + max) / 2 };
		if (target == array[midpoint])
		{
			return midpoint;
		}

		else if (target > array[midpoint])
		{
			min = midpoint + 1;
		}

		else if (target < array[midpoint])
		{
			max = midpoint - 1;
		}
			
	}

	return -1;
}

int main()
{
	constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	// We're going to test a bunch of values to see if the algorithm returns the result we expect

	// Here are the test values
	constexpr int testValues[]{ 0, 3, 12, 13, 22, 26, 43, 44, 48, 49 };

	// And here are the results that we expect for those test values
	int expectedResult[]{ -1, 0, 3, -1, -1, 8, -1, 13, 14, -1 };

	// Make sure we have the same number of test values and expected results
	static_assert(std::size(testValues) == std::size(expectedResult));

	int numTestValues{ std::size(testValues) };
	// Loop through all of the test values
	for (int count{ 0 }; count < numTestValues; ++count)
	{
		// See if our test value is in the array
		int index{ binarySearch(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
		// If it matches our expected value, then great!
		if (index == expectedResult[count])
			std::cout << "test value " << testValues[count] << " passed!\n";
		else // otherwise, our binarySearch() function must be broken
			std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
	}

	return 0;
}






















/*
void prepareNumbers(std::vector<int>& vec)
{
	int numToStart{}; // Starting number
	std::cout << "Start where? ";
	std::cin >> numToStart;

	int numToGenerate{}; // Number of values generated from the point of starting number
	std::cout << "How many? ";
	std::cin >> numToGenerate;

	int multiplier{ Random::get(2,4) }; // multiplier for squared values

	for (int i{ numToStart }; i < numToStart + numToGenerate; i++)
	{
		vec.push_back(i * i * multiplier);
	}

	std::cout << "I generated " <<  numToGenerate << " square numbers. " <<
				 "Do you know what each number is after multiplying it by " << multiplier << " ?\n";
}

bool checkVector(std::vector<int>& vec, int guess)
{
	bool found{ false };
	for (size_t index{ 0 }; index < std::size(vec); index++)
	{
		if (vec[index] == guess)
		{
			vec.erase(vec.begin() + static_cast<int>(index)); // pops the guessed element
			found = true;
			break;
		}
	}
	return found;
}



void play(std::vector<int>& vec)
{
	while (true)
	{
		int guess{};
		std::cin >> guess;
		if (checkVector(vec, guess))
		{
			if (std::ssize(vec) == 0)
			{
				std::cout << "Nice! You found all numbers, good job!";
				break;
			}

			std::cout << "Nice! " << vec.size() << " numbers left.\n";
		}

		else
		{
			auto closest{ std::min_element(vec.begin(), vec.end(),
						  [guess](const auto& a,const auto& b) {return (a > guess && (b <= guess || a < b)); }) };
						  std::cout << guess << " is wrong! Try " << *closest << " next time.";
			break;
		}

	}
}


int main()
{
	std::vector<int> vec{};
	prepareNumbers(vec);
	play(vec);


	return 0;
}
*/















/*
struct Student
{
	std::string_view name{};
	int points{};
};

struct Season
{
	std::string_view name{};
	double averageTemperature{};
};


int main()
{
	std::array<Season, 4> seasons
	{
		{
			{"Spring", 285.0},
			{"Summer", 296.0},
			{"Fall", 288.0},
			{"Winter", 263.0}
		}
	};

	std::sort(seasons.begin(), seasons.end(), [=](const auto& s1, const auto& s2)
											  {return s1.averageTemperature < s2.averageTemperature; });

	for (const auto& season : seasons)
	{
		std::cout << season.name << '\n';
	}

	return 0;
}









int main()
{
	constexpr std::array<std::string_view, 4> words{"apple" "banana", "walnut", "cherry"};

	auto found{ std::find_if(words.begin(), words.end(), [](std::string_view str) -> bool
														   {return str.find("nut") != std::string_view::npos;}) };

	if (found == words.end())
	{
		std::cout << "No nuts\n";
	}
	else
		std::cout << "Nuts found: " << *found;


	return 0;
}



*/

