#include <algorithm> // for std::sort
#include <array>
#include <chrono> // for std::chrono functions
#include <cstddef> // for std::size_t
#include <iostream>
#include <numeric> // for std::iota

const int g_arrayElements{ 10000 };

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::steady_clock;
	using Second = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<Clock> m_beg{ Clock::now() };

public:

	void reset()
	{
		m_beg = Clock::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

int main()
{
	std::array<int, g_arrayElements> array;
	std::iota(array.rbegin(), array.rend(), 1); // fill the array with values 10000 to 1

	Timer t;

	std::ranges::sort(array); // Since C++20
	// If your compiler isn't C++20-capable
	// std::sort(array.begin(), array.end());

	std::cout << "Time taken: " << t.elapsed() << " seconds\n";

	return 0;
}















/*


void doubleNumber(int& i)
{
	i *= 2;
}

int main()
{
	std::array arr{ 2, 4 ,3 ,12, 4, 5, 7 };

	std::for_each(arr.begin(), arr.end(), doubleNumber);

	for (const auto& e : arr)
		std::cout << e << ' ';
}
*/



















/*
int main()
{
	std::array arr{ 13, 90, 99, 5, 40, 80 };
	std::cout << "Before sorting: \n";
	for (const auto& e : arr)
		std::cout << e << " ";

	std::cout << '\n';

	std::sort(std::begin(arr), std::end(arr), std::greater{});

	std::cout << "After sorting: \n";
	for (const auto& e : arr)
		std::cout << e << " ";

	std::cout << '\n';
}
*/

/*
 bool containsNut(std::string_view str)
{
	return str.find("nut") != std::string_view::npos;
}


int main()
{
	std::array words{ "apple", "banana", "walnut", "lemon", "peanut" };

	auto found{ std::find_if(words.begin(), words.end(), containsNut )};
	auto nuts{std::count_if(std::begin(words), std::end(words), containsNut)};
	std::cout << "Counted " << nuts << " nuts\n";

}



*/






/*
int main()
{
	std::array arr{ 13, 90, 99, 5, 40, 80 };
	std::cout << "Array before replacing:\n";
	for (const auto& e : arr)
		std::cout << e << ' ';
	
	std::cout << "\nEnter a value to search for and replace with: ";
	int search{};
	int replace{};
	std::cin >> search >> replace;

	auto found{ std::find(std::begin(arr), std::end(arr), search) };

	if (found == arr.end())
		std::cout << search << " could not be found !\n";

	else
		*found = replace;

	for (const auto& e : arr)
		std::cout << e << ' ';
	

	return 0;
}

*/

/*
* 
* int main()
{
	int arr[]{ 20, 10, 40, 50, 30, 22, 13, 78, 6, 89 };
	std::sort(std::begin(arr), std::end(arr));

	for (int i{ 0 }; i < std::ssize(arr); i++)
	{
		std::cout << arr[i] << ' ';
	}


	return 0;
}


#include <iostream>
#include <iterator>
#include <utility>
#include <algorithm>
#include <vector>
int main()
{
	std::vector<int> arr{ 20, 10, 40, 50, 30, 22, 13, 78, 6, 89 };
	const std::size_t length{ arr.size()};

	for (std::size_t i{ 0 }; i < length - 1; i++)
	{
		bool isSorted{ false };
		for (std::size_t j{ 0 }; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				isSorted = true;
			}
		}

		if (!isSorted)
		{
			std::cout << "Array sorted early\n";
			break;
		}
	}

	for (std::size_t i{ 0 }; i < std::size(arr); i++)
	{
		std::cout << arr[i] << ' ';
	}

}







*/
