#include <iostream>
#include "random.h"
#include <limits>

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
	if (!std::cin)
	{
		if (std::cin.eof())
		{
			std::exit(0);
		}

		std::cin.clear();
		ignoreLine();

		return true;
	}
	return false;
}

int getRandomNumber(int min, int max)
{
	return Random::get(min, max);
}

bool playHiLo(int guesses, int min, int max)
{
	std::cout << "Let's play a game. I'm thinking of a number between " << min << " and "  << max << ". You have 7 tries to guess what it is." << std::endl;
	int number{ getRandomNumber(min, max) };
	int counter{ 1 };
	bool playAgain{ true };

	while (playAgain)
	{
		if (counter == guesses + 1)
		{
			playAgain = false;
			continue;
		}
		std::cout << "Guess #" << counter << ": ";
		int guess{};
		std::cin >> guess;
		if (clearFailedExtraction())
		{
			std::cout << "Oops, that input is invalid.  Please try again.\n";
			continue;
		}
		ignoreLine();

		if (guess < 1 || guess > 100)
		{
			std::cout << "Please enter a number in specified interval !" << '\n';
			continue;
		}

		if (guess == number)
		{
			std::cout << "Correct! You win!" << '\n';
			return true;
		}
		else if (guess > number)
		{
			std::cout << "Your guess is too high." << '\n';
		}
		else if (guess < number)
		{
			std::cout << "Your guess is too low." << '\n';
		}

		counter++;
	}

	std::cout << "Sorry, you lose. The number was " << number << "." << '\n';
	return false;
	
}

bool playAgain()
{
	char answer{};
	do
	{
		std::cout << "Do you want to play again? (y/n): ";
		std::cin >> answer;
		if (clearFailedExtraction())
		{
			std::cout << "Oops, that input is invalid.  Please try again.\n";
			continue;
		}
		ignoreLine();
	} while (answer != 'y' && answer != 'n');

	if (answer == 'y')
	{
		return true;
	}
	else
	{
		std::cout << "Thank you for playing." << '\n';
		return false;
	}
}


int main()
{
	constexpr int calls{ 7 };
	constexpr int min{ 1 };
	constexpr int max{ 100 };

	do
	{
		playHiLo(calls, min, max);
	} while (playAgain());

	return 0;
}
































/*
#include <iostream>
#include <cassert> // for assert
#include <cmath>

bool isPrime(int x)
{
	if (x <= 1)
		return false;
	else if (x == 2)
		return true;
	else
	{
		int limit{static_cast<int>(std::sqrt(static_cast<double>(x)))};
		for (int i{ 2 }; i <= limit; i++)
		{
			if(x % i == 0)
				return false;
		}
		return true;
	}
	
}


int main()
{

	assert(!isPrime(0)); // terminate program if isPrime(0) is true
	assert(!isPrime(1));
	assert(isPrime(2));  // terminate program if isPrime(2) is false
	assert(isPrime(3));
	assert(!isPrime(4));
	assert(isPrime(5));
	assert(isPrime(7));
	assert(!isPrime(9));
	assert(isPrime(11));
	assert(isPrime(13));
	assert(!isPrime(15));
	assert(!isPrime(16));
	assert(isPrime(17));
	assert(isPrime(19));
	assert(isPrime(97));
	assert(!isPrime(99));
	assert(isPrime(13417));

	std::cout << "Success; ";
	return 0;
}


#include <iostream>

namespace constants
{
	const double gravity{ 9.81 };
}

double getTowerHeight()
{
	double towerHeight{};
	do {
		std::cout << "Enter the height of the tower: ";
		std::cin >> towerHeight;
		if (towerHeight <= 0)
			std::cout << "Height must be a positive number.\n";
	} while (towerHeight <= 0);



	return towerHeight;
}

double calculateHeight(double towerHeight, int time)
{

	double new_height{ towerHeight - (0.5 * constants::gravity * (time * time)) };

	return new_height;
}

void printHeight(double height)
{
	if (height <= 0)
	{
		std::cout << "The object has hit the ground." << '\n';
	}
	else
	{
		std::cout << "The height of the object is: " << height << " meters." << std::endl;
	}
}

int main()
{
	const double towerHeight{ getTowerHeight() };


	for (int i = 0;; ++i)
	{
		double height{ calculateHeight(towerHeight, i) };
		printHeight(height);
		if (height < 0)
		{
			std::cout << "Falling lasted " << i << " seconds." << std::endl;
			break;
		}
	}

	return 0;
}
*/
