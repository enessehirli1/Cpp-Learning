#pragma once
#include <string>

class Potion
{
public:
	enum Type
	{
		Health,
		Strength,
		Poison,
		MAX_POTION_TYPES
	};

private:
	std::string m_name{};
	int m_rarity{};
	int m_affect{};

public:
	Potion(std::string_view name, int rarity,int affect)
		: m_name{ name }
		, m_rarity{ rarity }
		, m_affect{ affect }
	{
	}
	// Getters
	const std::string& getName() const { return m_name; }
	int getRarity() const { return m_rarity; }
	int getAffect() const { return m_affect; }


};