#include <iostream>

void swap(int* const a, int* const b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	std::cout << "Enter a First Value: ";
	int num{};
	std::cin >> num;

	std::cout << "Enter a Second Value: ";
	int num2{};
	std::cin >> num2;

	std::cout << "Before Swap: " << num << " " << num2 << std::endl;
	swap(&num, &num2);
	std::cout << "After Swap: " << num << " " << num2 << std::endl;


	return 0;
}