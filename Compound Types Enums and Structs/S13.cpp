#include <iostream>
#include <string>
#include <string_view>
#include <optional>


enum class MonsterType
{
	orc,
	goblin,
	troll,
	ogre,
	skeleton
};


constexpr std::string_view getMonsterName(MonsterType monster)
{
	using enum MonsterType;
	switch (monster)
	{
	case (orc):      return "orc";
	case (goblin):   return "goblin";
	case (troll):    return "troll";
	case (ogre):     return "ogre";
	case (skeleton): return "skeleton";
	default:				   return "Unknown Monster";
	}
}


constexpr std::optional<MonsterType> getMonsterFromString(std::string_view sv)
{
	using enum MonsterType;
	if (sv == "orc")      return orc;
	if (sv == "goblin")   return goblin;
	if (sv == "troll")    return troll;
	if (sv == "ogre")     return ogre;
	if (sv == "skeleton") return skeleton;
	// If no match found, return std::nullopt
	return std::nullopt;
}

std::ostream& operator<<(std::ostream& out, MonsterType monster)
{
	out << getMonsterName(monster);
	return out;
}

std::istream& operator>>(std::istream& in, MonsterType& monster)
{
	std::string s{};
	in >> s;

	std::optional<MonsterType> match{ getMonsterFromString(s) };
	if (match)
	{
		monster = *match;
		return in;
	}

	in.setstate(std::ios_base::failbit); // Set failbit if no match found
	return in;
}

int main()
{
	using enum MonsterType;
	MonsterType monsterInput{};
	std::cout << "Enter a monster (orc, goblin, troll, ogre, skeleton): ";
	std::cin >> monsterInput;

	if (std::cin)
		std::cout << "You chose: " << getMonsterName(monsterInput) << '\n';
	else
	{
		std::cin.clear(); // reset the input stream to good
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Your pet was not valid\n";
	}

	std::cout << "*******************************" << '\n';
	MonsterType monster_new{ orc };
	std::cout << monster_new << '\n'; // With operator<< overload

	return 0;
}





/*
enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck
};

constexpr std::string_view getAnimalName(Animal animal)
{
	using enum Animal;

	switch (animal)
	{
	case pig:     return "pig";
	case chicken: return "chicken";
	case goat:    return "goat";
	case cat:     return "cat";
	case dog:     return "dog";
	case duck:    return "duck";
	default:      return "Unknown Animal";
	}
}
void printNumberOfLegs(Animal animal)
{
	using enum Animal;

	switch (animal)
	{
	case pig:
	case goat:
	case cat:
	case dog:
		std::cout << "A " << getAnimalName(animal) << " has 4 legs" << '\n';
		return; // Exit after printing for pig

	case chicken:
	case duck:
		std::cout << "A " << getAnimalName(animal) << " has 2 legs" << '\n';
		return;


	default:
		std::cout << "Unknown Animal\n";
		return;
	}

}

int main()
{
	printNumberOfLegs(Animal::cat);
	printNumberOfLegs(Animal::chicken);


	return 0;
}


*/


