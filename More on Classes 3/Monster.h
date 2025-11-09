#pragma once
#include <string>

class Monster
{
public:
	enum Type
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		maxMonsterTypes
	};

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

public:
	Monster(Type type, std::string_view name, std::string_view roar, int hitPoints);

	std::string_view getTypeString() const;

	void print() const;
};