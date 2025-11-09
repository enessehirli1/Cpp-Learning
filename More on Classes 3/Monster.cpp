#include "Monster.h"
#include <iostream>

Monster::Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
	: m_type{ type }
	, m_name{ name }
	, m_roar{ roar }
	, m_hitPoints{ hitPoints } {}

std::string_view Monster::getTypeString() const
{
	switch (m_type)
	{
	case Dragon:   return "Dragon";
	case Goblin:   return "Goblin";
	case Ogre:     return "Ogre";
	case Orc:      return "Orc";
	case Skeleton: return "Skeleton";
	case Troll:    return "Troll";
	case Vampire:  return "Vampire";
	case Zombie:   return "Zombie";
	default:       return "Unknown Monster Type";
	}
}

void Monster::print() const
{
	std::cout << m_name << " the " << getTypeString();
	if (m_hitPoints <= 0)
		std::cout << " is dead.\n";
	else
		std::cout << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
}