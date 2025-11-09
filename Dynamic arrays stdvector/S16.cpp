#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <cassert>
#include <ranges>

namespace Animals
{
	enum breeds
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,

		numBreeds
	};

	const std::vector<int> legs{ 2, 4, 4, 4, 2 ,0};
}

int main()
{
	assert(Animals::numBreeds == std::ssize(Animals::legs) && "Number of Animal Breeds and Length of legs must be same");

	std::cout << "A snake has " << Animals::legs[Animals::snake] << " legs\n";
}


/*
void game(int number)
{
	static const std::vector primes{ 3,5,7,11,13,17,19 };
	static const std::vector<std::string_view> name{"fizz","buzz","pop","bang","jazz","pow","boom"};


	for (int counter{1}; counter <= number; counter++)
	{
		bool printed{ false };

		for (size_t i{ 0 }; i < primes.size(); i++)
		{
			if (counter % primes[i] == 0)
			{
				std::cout << name[i];
				printed = true;
			}
		}

		if (!printed)
		{
			std::cout << counter;
		}

		std::cout << '\n';
	}
}

int main()
{
	game(150);
	return 0;
}
*/
