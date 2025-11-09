#include <iostream>
#include <limits>
#include <string>

struct Fraction
{
	int numerator{};
	int denominator{1};
};

void clearInputBuffer()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Fraction getFraction()
{
	Fraction temp{};
	
	while (true)
	{
		std::cout << "Enter a value for the numerator: ";
		std::cin >> temp.numerator;

		if (!std::cin)
		{
			std::cout << "Invalid input for numerator. Please enter an integer.\n";
			std::cin.clear(); // Clear the error state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		}
		else
		{
			clearInputBuffer();
			break; // Valid input received
		}
	}
	

	while (true)
	{
		std::cout << "Enter a value for the denominator: ";
		std::cin >> temp.denominator;
		if (!std::cin)
		{
			std::cout << "Invalid input for denominator. Please enter an integer.\n";
			std::cin.clear(); // Clear the error state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
		}
		else if (temp.denominator == 0)
			std::cout << "Denominator cannot be 0 !" << '\n';
		else
		{
			clearInputBuffer();
			break; // Valid input received;
		}
			
	}
	

	return temp;
}

Fraction multiplyFraction(const Fraction& fr1, const Fraction& fr2)
{
	return { fr1.numerator * fr2.numerator, fr1.denominator * fr2.denominator };
}

void printFraction(const Fraction& fr)
{
	std::cout << "\nYour fractions multiplied together: " << fr.numerator << "/" << fr.denominator << '\n';
}
int main()
{
	Fraction fr1{ getFraction() };
	std::cout << '\n';
	Fraction fr2{ getFraction() };
	Fraction result{ multiplyFraction(fr1, fr2) };
	printFraction(result);
	return 0;
}


/*
struct Advertising
{
	int adsShown{};
	double clickThroughRatePercentage{};
	double averageEarningsPerClick{};
};

void clearInputBuffer()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int getValidInteger(const std::string_view prompt, int min_value = 0)
{
	int value;
	while (true)
	{
		std::cout << prompt;
		std::cin >> value;
		if (std::cin)
		{
			if (value >= min_value)
			{
				clearInputBuffer();
				return value;

			}
			else
			{
				std::cout << "Value must be at least " << min_value << ". Please try again.\n";
			}
		}
		else
		{
			std::cout << "Invalid input. Please enter a valid integer.\n";
			std::cin.clear();
			clearInputBuffer();
		}
	}
}

double getValidDouble(const std::string_view prompt, int min_value = 0, double max_value = std::numeric_limits<double>::max())
{
	double value;
	while (true)
	{
		std::cout << prompt;
		std::cin >> value;
		if (std::cin)
		{
			if (value >= min_value && value <= max_value)
			{
				clearInputBuffer();
				return value;
			}
			else
			{
				std::cout << "Value must be between 0 and " << max_value << std::endl;

			}
		}
		else
		{
			std::cout << "Invalid input. Please enter a valid decimal number.\n";
			std::cin.clear();
			clearInputBuffer();
		}
	}
}

Advertising getAdvertising()
{
	Advertising temp{ };
	temp.adsShown = getValidInteger("Enter the number of ads shown: ", 0);
	temp.clickThroughRatePercentage = getValidDouble("Enter the click-through rate percentage (0-1): ", 0, 1);
	temp.averageEarningsPerClick = getValidDouble("Enter the average earnings per click: ", 0);

	return temp;
}

void printAdvertising(const Advertising& ad)
{
	std::cout << "\nAdvertising Statistics\n";
	std::cout << "Ads Shown: " << ad.adsShown << "\n";
	std::cout << "Click-Through Rate Percentage: " << ad.clickThroughRatePercentage << "\n";
	std::cout << "Average Earnings Per Click: " << ad.averageEarningsPerClick << "\n\n";

	std::cout << "Total Earnings: " << (ad.adsShown * ad.clickThroughRatePercentage * ad.averageEarningsPerClick) << "\n";

}

int main()
{
	Advertising ad{ getAdvertising() };
	printAdvertising(ad);

	return 0;
}








std::ostream& operator<<(std::ostream& out, const Employee& e)
{
	out << "ID: " << e.id << ", Age: " << e.age << ", Wage: " << e.wage;
	return out;
}
*/