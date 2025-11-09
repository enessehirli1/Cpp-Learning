#include <iostream>
#include "Monster.h"
#include "Random.h"

namespace MonsterGenerator
{
	std::string_view getName(int n)
	{
		switch (n)
		{
		case 0:  return "Bones";
		case 1:  return "Gore";
		case 2:  return "Flesh";
		case 3:  return "Blood";
		case 4:  return "Skull";
		case 5:  return "Death";
		default: return "Unknown";
		}
	}

	std::string_view getRoar(int n)
	{
		switch (n)
		{
		case 0:  return "*RATTLE*";
		case 1:  return "*GROWL*";
		case 2:  return "*SNARL*";
		case 3:  return "*ROAR*";
		case 4:  return "*HOWL*";
		case 5:  return "*SCREAM*";
		default: return "*UNKNOWN ROAR*";
		}
	}

	Monster generate()
	{
		return Monster{ static_cast<Monster::Type>(Random::get(0,Monster::maxMonsterTypes-1)),
			   getName(Random::get(0,5)), getRoar(Random::get(0,5)), Random::get(0,100)};
	}

}


int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}