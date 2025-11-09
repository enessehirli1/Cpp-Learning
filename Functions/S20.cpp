#include <iostream>
#include <functional>
#include <optional>
#include <sstream> // for std::stringstream


int recFactorial(std::size_t count)
{
	static std::vector fac{ 1, 1 };

	if (count < std::size(fac))
		return fac[count];

	fac.push_back(count * recFactorial(count - 1));
	return fac[count];
}


int fibonacci(std::size_t count)
{
	static std::vector fib{ 0, 1 };

	if (count < std::size(fib))
		return fib[count];

	fib.push_back(fibonacci(count - 1) + fibonacci(count - 2));
	return fib[count];
}

int sumDigit(int num)
{
	if (num < 10)
		return num;

	return sumDigit(num / 10 ) + num % 10;
}


void printBinary(int x)
{
	// Termination case
	if (x == 0)
		return;

	// Recurse to the next bit
	printBinary(x / 2);

	// Print out the remainders (in reverse order)
	std::cout << x % 2;
}


int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		// On some operating systems, argv[0] can end up as an empty string instead of the program's name.
		// We'll conditionalize our response on whether argv[0] is empty or not.
		if (argv[0])
			std::cout << "Usage: " << argv[0] << " <number>" << '\n';
		else
			std::cout << "Usage: <program name> <number>" << '\n';

		return 1;
	}

	std::stringstream convert{ argv[1] }; // set up a stringstream variable named convert, initialized with the input from argv[1]

	int myint{};
	if (!(convert >> myint)) // do the conversion
		myint = 0; // if conversion fails, set myint to a default value

	std::cout << "Got integer: " << myint << '\n';

	return 0;
}




/*
using ArithmeticFunction = std::function<int(int, int)>;

int getValue()
{
	while (true)
	{
		int value{};
		std::cout << "Please enter a value: ";
		std::cin >> value;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid Input\n";
			continue;
		}
		return value;
	}
}

char getOp()
{
	while (true)
	{
		char op{};
		std::cout << "Please select a operation  ('+', '-', '*', '/'): ";
		std::cin >> op;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid Input\n";
			continue;
		}

		else if (op == '+' || op == '-' || op == '*' || op == '/')
		{
			return op;
		}

		else
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid Input\n";
			continue;
		}
	}
}

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int mulitply(int x, int y) { return x * y; }
int divide(int x, int y) { return (y != 0) ? (x / y) : 0; }


std::optional<ArithmeticFunction> getArithmeticFunction(char op)
{
	switch (op)
	{
	case '+': return add;
	case '-': return subtract;
	case '*': return mulitply;
	case '/': return divide;
	default:  return {};
	}
}


int main()
{
	int first{ getValue() };
	int second{getValue()};

	std::cout << "First int: " << first << '\n';
	std::cout << "Second int: " << second << '\n';

	char op{ getOp() };
	ArithmeticFunction func{ *getArithmeticFunction(op) };
	std::cout << first << " " << op << " " << second << " = " << func(first, second);

	return 0;
}

















bool ascending(int x, int y)
{
	return x > y;
}

bool descending(int x, int y)
{
	return x < y;
}

bool evensFirst(int x, int y)
{
	if ((x % 2 == 0) && !(y % 2 == 0))
		return false ;

	if (!(x % 2 == 0) && (y % 2 == 0))
		return true;

	ascending(x, y);
}

void printArray(int* array, int size)
{
	if (!array)
		return;

	for (int index{ 0 }; index < size; index++)
	{
		std::cout << array[index] << ' ';
	}
	std::cout << '\n';
}

using cmprFunc = bool(*)(int, int);
void selectionSort(int* array, int size, cmprFunc func = ascending)
{
	if (!array || !func)
		return;

	for (int startIndex{ 0 }; startIndex < (size - 1) ; startIndex++)
	{
		int bestIndex{startIndex};
		for (int currentIndex{ startIndex + 1 }; currentIndex < size; currentIndex++)
		{
			if (func(array[bestIndex], array[currentIndex]))
			{
				bestIndex = currentIndex;
			}	
		}
		std::swap(array[startIndex], array[bestIndex]);
	}
}

int main()
{
	int array[9]{ 3, 7, 9, 5, 6, 1, 8, 2, 4 };
	printArray(array, 9);

	selectionSort(array, 9, descending);
	printArray(array, 9);

	selectionSort(array, 9);
	printArray(array, 9);

	selectionSort(array, 9, evensFirst);
	printArray(array, 9);

	return 0;
}
*/
