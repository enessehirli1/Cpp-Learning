#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <iterator>

namespace Animal
{
	enum Type
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		maxAnimals
	};

	struct Data
	{
		std::string_view name{};
		int numLegs{};
		std::string_view sound{};
	};

	constexpr std::array data
	{
		Data{ "chicken",    2, "cluck" },
		Data{ "dog",        4, "woof" },
		Data{ "cat",        4, "meow" },
		Data{ "elephant",   4, "pawoo" },
		Data{ "duck",       2, "quack" },
		Data{ "snake",      0, "hissss" },
	};
	static_assert(std::size(data) == maxAnimals);


	constexpr std::array types{chicken, dog, cat, elephant, duck, snake};
	static_assert(std::size(types) == maxAnimals);
}

constexpr std::string_view getAnimalName(Animal::Type animal)
{
	return Animal::data[static_cast<Animal::Type>(animal)].name;
}

std::ostream& operator<<(std::ostream& out, Animal::Type animal)
{
	return out << getAnimalName(animal);
}

std::istream& operator>>(std::istream& in, Animal::Type& animal)
{
	std::string input{};
	std::getline(in >> std::ws, input);

	for (std::size_t index{ 0 }; index < Animal::data.size(); index++)
	{
		if (input == Animal::data[index].name)
		{
			animal = static_cast<Animal::Type>(index);
			return in;
		}
	}

	in.setstate(std::ios_base::failbit);
	return in;
}

void printAnimalData(Animal::Type type)
{
	const Animal::Data& animal{ Animal::data[type]};
	std::cout << "A " << animal.name << " has " << animal.numLegs << " legs and says " << animal.sound << '\n';
}


int main()
{
	Animal::Type input{};
	std::cout << "Enter animal name: ";
	std::cin >> input;

	if (!std::cin)
	{
		std::cin.clear();
		std::cout << "Invalid";
		input = Animal::maxAnimals;
	}
	else
		printAnimalData(input);
	
	std::cout << "\nHere is the data for the rest of the animals:\n";
	for (auto a : Animal::types)
	{
		if (a != input)
			printAnimalData(a);
	}

	return 0;
}




















/*
#include <array>
#include <iostream>
#include <string>
#include <string_view>
#include <iterator>

namespace Animal
{
	enum Type
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		max_animal
	};

	struct Data
	{
		std::string_view name{};
		int numLegs{};
		std::string_view sound{};
	};

	constexpr std::array types{chicken, dog, cat, elephant, duck, snake};
	static_assert(std::size(types) == max_animal);

	constexpr std::array data
	{
		Data{ "chicken",		2, "cluck"},
		Data{ "dog",        4, "woof" },
		Data{ "cat",        4, "meow" },
		Data{ "elephant",   4, "pawoo" },
		Data{ "duck",       2, "quack" },
		Data{ "snake",      0, "hissss" },
	};
	static_assert(std::size(data) == max_animal);

};

constexpr std::string_view getAnimalName(Animal::Type animal)
{
	return Animal::data[static_cast<std::size_t>(animal)].name;
}

std::ostream& operator<<(std::ostream& out, Animal::Type animal)
{
	return out << getAnimalName(animal);
}

std::istream& operator>>(std::istream& in, Animal::Type& animal)
{
	std::string input{};
	std::getline(in >> std::ws, input);

	for (std::size_t index{ 0 }; index < Animal::data.size(); index++)
	{
		if (input == Animal::data[index].name)
		{
			animal = static_cast<Animal::Type>(index);
			return in;
		}

	}

	in.setstate(std::ios_base::failbit);

	return in;
}

void printAnimalData(Animal::Type type)
{
	const Animal::Data& animal{ Animal::data[type] };
	std::cout << "A " << animal.name << " has " << animal.numLegs << " legs and says " << animal.sound << '\n';
}

int main()
{
	Animal::Type animal{};
	std::cout << "Enter an animal: ";
	std::cin >> animal;
	if (!std::cin)
	{
		std::cin.clear();
		std::cout << "That animal couldn't be found.\n";
		animal = Animal::max_animal; // set to invalid option so we don't match below
	}
	else
		printAnimalData(animal);

	std::cout << "\nHere is the data for the rest of the animals:\n";
	for (const auto& e : Animal::types)
	{
		if (e != animal)
		{
			printAnimalData(e);
		}
	}

}

*/
















/*

#include <array>
#include <iostream>

struct Item
{
	std::string_view name{};
	int gold{};
};

template<typename T, std::size_t N>
constexpr void printArr(const std::array<T, N>& arr)
{
	for (const auto& item : arr)
	{
		std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
	}
}

int main()
{
	constexpr std::array<Item, 4> items
	{
		{
			{"Sword", 5},
			{"Dagger",  3},
			{"Club", 2},
			{"Spear", 7},
		}
	};


	printArr(items);

	return 0;
}














struct Student
{
	int id{};
	std::string_view name{};
};

constexpr std::array students{ Student{0, "Alex"}, Student{ 1, "Joe" }, Student{ 2, "Bob" } };

const Student* findStudentById(int id)
{
	for (const auto& student : students)
	{
		if (student.id == id)
			return &student;
	}

	return nullptr;
}

int main()
{
	constexpr std::string_view nobody{ "nobody" };
	const Student* s1{ findStudentById(1) };
	std::cout << "You found " << (s1 ? s1->name : nobody) << '\n';

	const Student* s2{findStudentById(3)};
	std::cout << "You found " << (s2 ? s2->name : nobody) << '\n';

}

*/
