#pragma once
#include "Creature.h"
#include "Random.h"

class Monster : public Creature
{
public:
	enum Type
	{
		dragon,
		orc,
		slime,
		MAX_MONSTER_TYPES
	};

private:
	inline static Creature monsterData[]
	{
		Creature{ "Dragon", 'D', 20, 4, 100 },
		Creature{ "Orc", 'o', 4, 2, 25 },
		Creature{ "Slime", 's', 1, 1, 10 }
	};

	static_assert(std::size(monsterData) == MAX_MONSTER_TYPES);

public:
	Monster(Type type)
		: Creature{ monsterData[type] }
	{
	}

	static Monster getRandomMonster()
	{
		return Monster{ static_cast<Type>(Random::get(0, MAX_MONSTER_TYPES - 1)) };
	}

};