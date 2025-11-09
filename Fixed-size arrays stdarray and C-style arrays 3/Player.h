#pragma once
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include "Random.h"
#include "Potion.h"

class Player
{
private:
	std::string m_name{};
	std::vector<Potion::Type> m_potions {};
	int m_gold{};

public:
	Player(std::string name, std::vector<Potion::Type> potions, int gold = Random::get(80, 120))
		: m_name{name}
		, m_potions{potions}
		, m_gold{gold} {}

	int getGold() const { return m_gold; }
	std::string_view getName() const { return m_name; }
	std::vector<Potion::Type> getPotions() const { return m_potions; }

	void purchase(int num) 
	{ 
		m_potions.push_back(Potion::potions[static_cast<std::size_t>(num)]);
		m_gold -= Potion::cost[static_cast<std::size_t>(num)];
	}
};