#include <iostream>

int main()
{
    constexpr int numRows{ 10 };
    constexpr int numCols{ 10 };

    int product[numRows][numCols]{};

    for (size_t rows{ 1 }; rows < numRows; rows++)
    {
        for (size_t cols{ 1 }; cols < numCols; cols++)
        {
            product[rows][cols] = static_cast<int>(rows * cols);
        }
    }

    for (size_t rows{ 1 }; rows < numRows; rows++)
    {
        for (size_t cols{ 1 }; cols < numCols; cols++)
        {
            std::cout << product[rows][cols] << '\t';
        }

        std::cout << '\n';
    }


    return 0;
}


















/*
constexpr int perfectSquare[4] { 0,1,4,9 };

int main()
{
    while (true)
    {
        int num{};
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> num;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        if (num == -1)
        {
            std::cout << "bye";
            break;
        }


        bool isPerfect{ false };
        for (int index{ 0 }; index < std::ssize(perfectSquare); index++)
        {
            if (perfectSquare[index] == num)
            {
                isPerfect = true;
            }

        }

        if (isPerfect)
            std::cout << num << " is perfect square" << '\n';

        else
            std::cout << num << " is NOT a perfect square" << '\n';

    }
}

*/


