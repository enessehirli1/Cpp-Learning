#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits

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

double getDouble()
{
	while (true)
	{
		std::cout << "Enter a double value: ";
		double value{};
		std::cin >> value;

		if (clearFailedExtraction())
		{
			std::cout << "Oops, that input is invalid.  Please try again.\n";
			continue;
		}

		ignoreLine();
		return value;
	}
}

char getOperator()
{
	while (true)
	{
		std::cout << "Enter one of the following: +, -, *, or /: ";
		char operation{};
		std::cin >> operation;

		if (!clearFailedExtraction())
		{
			ignoreLine();
		}

		switch (operation)
		{
			case '+':
			case '-':	
			case '*':
			case '/':
				return operation;
			default:
				std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
	}
}

void printResult(double x, char op, double y)
{
	std::cout << x << ' ' << op << ' ' << y << " = ";

	switch (op)
	{
	case '+':
		std::cout << x + y;
		return;
	case '-':
		std::cout << x - y;
		return;
	case '*':
		std::cout << x * y;
		return;
	case '/':
		if (y == 0.0)
			break;
		std::cout << x / y;
		return;
	default:
		std::cout << "Oops, that input is invalid.  Please try again.\n";
		return;
	}

	std::cout << "???";
}

int main()
{
	double x{ getDouble() };
	char operation{ getOperator() };
	double y{ getDouble() };

	// Handle division by 0
	while (operation == '/' && y == 0.0)
	{
		std::cout << "The denominator cannot be zero.  Try again.\n";
		y = getDouble();
	}

	printResult(x, operation, y);

	return 0;
}