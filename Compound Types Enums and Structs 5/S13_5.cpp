#include <iostream>

template <typename T>
struct Triad
{
	T x{};
	T y{};
	T z{};
};

template <typename T>
void print(const Triad<T>& triad)
{
	std::cout << "[" << triad.x << ", " << triad.y << ", " << triad.z << "]\n";
}

int main()
{
	const Triad triad1{ 1,2,3 };
	print(triad1);

	const Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

}











/*
struct Monster
{
	enum Type
	{
		ogre,
		dragon,
		orc,
		giantSpider,
		slime
	};

	Type type{};
	std::string name{};
	int health{};
};


constexpr std::string getMonsterName(const Monster::Type& type)
{
	switch (type)
	{
	case (Monster::ogre):		 return "Ogre";
	case (Monster::dragon):		 return "Dragon";
	case (Monster::orc):		 return "Orc";
	case (Monster::giantSpider): return "Giant Spider";
	case (Monster::slime):		 return "Slime";
	default:					 return "Unknown";
	}
}

void printMonster(const Monster& monster)
{
	std::cout << "This " << getMonsterName(monster.type) <<
				 " is named " << monster.name << " and has " <<
				 monster.health << " health." << '\n';
}


int main()
{
	const Monster monster1{ {Monster::ogre}, "Torg", 145 };
	const Monster monster2{ {Monster::slime}, "Blurp", 23 };
	printMonster(monster1);
	printMonster(monster2);

	return 0;
}
*/
