#include <array>
#include <iostream>
#include <functional>
#include "Potion.h"
#include "Player.h"

void shop()
{
    std::cout << "\nHere is our selection for today:\n";
    for (std::size_t index{ 0 }; index < std::size(Potion::name); index++)
    {
        std::cout << index << ") " << Potion::name[index] << " costs " << Potion::cost[index] << '\n';
    }
}

void printInfo(const Player& player)
{
    std::cout << "Hello " << player.getName() << ", you have " << player.getGold() << " gold.\n";
}

void printInventory(int hCtr, int mCtr, int sCtr, int iCtr)
{
    std::cout << "\nYour inventory contains: \n";
    if (hCtr)
        std::cout << hCtr << "x potion of healing\n";

    if (mCtr)
        std::cout << mCtr << "x potion of mana\n";

    if (sCtr)
        std::cout << sCtr << "x potion of speed\n";

    if (iCtr)
        std::cout << iCtr << "x potion of invisibility\n";
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int charNumToInt(char c)
{
    return c - '0';
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";

    // get name for player class
    std::string name{};
    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, name);

    // create a empty std::vector for potions
    // This will be uploaded with users entries
    std::vector<Potion::Type> potions{};

    Player p1{ name, potions};
    printInfo(p1);
    while (true)
    {
        shop();
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        char choice{};
        std::cin >> choice;

        if (choice == 'q')
            break;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is an invalid input.  Try again: ";
            continue;
        }

        // If there is extraneous input, treat as failure case
        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cout << "I didn't understand what you said.  Try again: ";
            ignoreLine(); // ignore any extraneous input
            continue;
        }

        int val{ charNumToInt(choice) };
        if (val >= 0 && val <= 4)
        {
            if (Potion::cost[static_cast<std::size_t>(val)] <= p1.getGold())
            {
                p1.purchase(val);
                std::cout << "You purchased a potion of " << Potion::name[static_cast<std::size_t>(val)]
                          << ". You have " << p1.getGold() << " gold left.\n";
            }
            
            else
            {
                std::cout << "You cannot afford that. \n";
                continue;
            }
        }
        else
        {
            std::cout << "That is an invalid input.  Try again: ";
            continue;
        }

    }

    int hCtr{ 0 };
    int mCtr{ 0 };
    int sCtr{ 0 };
    int iCtr{ 0 };

    for (const auto& e : p1.getPotions())
    {
        if (e == 0) // healing potion
            hCtr += 1;

        else if (e == 1) // mana potion
            mCtr += 1;

        else if (e == 2) // speed potion
            sCtr += 1;

        else if (e == 3) // invisibility potion
            iCtr += 1;
    }

    printInventory(hCtr, mCtr, sCtr, iCtr);
    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
}







/*
template <typename T, std::size_t Row, std::size_t Col>
using ArrayFlat2d = std::array<T, Row* Col>;

int main()
{
    // Define a one-dimensional std::array of int (with 3 rows and 4 columns)
    ArrayFlat2d<int, 3, 4> arr{
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12 };

    // Define a two-dimensional span into our one-dimensional array
    // We must pass std::mdspan a pointer to the sequence of elements
    // which we can do via the data() member function of std::array or std::vector
    std::mdspan mdView{ arr.data(), 3, 4 };

    // print array dimensions
    // std::mdspan calls these extents
    std::size_t rows{ mdView.extents().extent(0) };
    std::size_t cols{ mdView.extents().extent(1) };
    std::cout << "Rows: " << rows << '\n';
    std::cout << "Cols: " << cols << '\n';

    // print array in 1d
    // The data_handle() member gives us a pointer to the sequence of elements
    // which we can then index
    for (std::size_t i = 0; i < mdView.size(); ++i)
        std::cout << mdView.data_handle()[i] << ' ';
    std::cout << '\n';

    // print array in 2d
    // We use multidimensional [] to access elements
    for (std::size_t row = 0; row < rows; ++row)
    {
        for (std::size_t col = 0; col < cols; ++col)
            std::cout << mdView[row, col] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';

    return 0;
}



template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

template <typename T , std::size_t Row, std::size_t Col>
constexpr int lengthRow(const Array2d<T, Row, Col>&)
{
    return Row;
}

template <typename T, std::size_t Row, std::size_t Col>
constexpr int lengthCol(const Array2d<T, Row, Col>&)
{
    return Col;
}


template<typename T, std::size_t Row, std::size_t Col>
void printArray(Array2d<T, Row, Col>& arr)
{
    for (const auto& arow : arr)
    {
        for (const auto& e : arow)
        {
            std::cout << e << " ";
        }

        std::cout << '\n';
    }
}


int main()
{
    Array2d<int, 3, 4> arr {{
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }} };

    printArray(arr);

    std::cout << "Rows: " << lengthRow(arr) << '\n';
    std::cout << "Cols: " << lengthCol(arr) << '\n';

}

*/



















