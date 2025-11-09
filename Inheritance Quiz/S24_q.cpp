#include <iostream>
#include <string>
#include "Random.h"

class Creature
{
protected:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_damage{};
	int m_gold{};

public:
	Creature(std::string_view name, char symbol, int health, int damage, int gold)
		: m_name{ name }
		, m_symbol{ symbol }
		, m_health{ health }
		, m_damage{ damage }
		, m_gold{ gold }
	{
	}
	
	// getters
	const std::string& getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth() const { return m_health; }
	int getDamage() const { return m_damage; }
	int getGold() const { return m_gold; }
	
	// helper functions
	void reduceHealth(int damage) { m_health -= damage; }
	bool isDead() const { return m_health <= 0; }
	void addGold(int amount) { m_gold += amount; }
};



class Player : public Creature
{
private:
	uint32_t m_level{1};

public:
	Player(std::string_view name)
		: Creature{ name, '@', 10, 1, 0 }
	{
	}


	void levelUp() {
		++m_level;
		++m_damage;
	}

	uint32_t getLevel() const { return m_level; }
	bool hasWon() const { return m_level >= 20; }
};

class Monster : public Creature
{
public:
	enum Type
	{
		dragon,
		orc,
		slime,
		max_type // 3
	};

private:
	inline static Creature monsterData[]
	{
		Creature { "dragon", 'D', 20, 4, 100 },
		Creature { "orc", 'o', 4, 2, 25 },
		Creature { "slime", 's', 1, 1, 10 }
	};
	
	static_assert(std::size(monsterData) == max_type);

public:
	Monster(Type type)
		: Creature{ monsterData[type] }
	{
	}

	static Monster getRandomMonster()
	{
		int num{ Random::get(0, max_type - 1) };
		return Monster{ static_cast<Type>(num) };
	}
};

void attackMonster(Player& p, Monster& m)
{
	if (p.isDead())
		return;

	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";
	m.reduceHealth(p.getDamage());

	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << ".\n";
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << '\n';
		
		std::cout << "You found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}


void attackPlayer(Player& p, const Monster& m)
{
	if (m.isDead())
		return;

	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";

}

void fight(Player& p)
{
	Monster m{ Monster::getRandomMonster() };
	std::cout << "You encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

	while (!m.isDead() && !p.isDead())
	{
		char choice{};
		std::cout << "(R)un or (F)ight: ";
		std::cin >> choice;

		if (choice == 'F' || choice == 'f')
		{
			attackMonster(p, m);
			attackPlayer(p, m);
		}

		else if (choice == 'R' || choice == 'r')
		{
			int success{ Random::get(0,1) };
			if (success)
			{
				std::cout << "You successfully fled.\n";
				return;
			}

			else
			{
				std::cout << "You failed to flee.\n";
				attackPlayer(p,m);
				continue;
			}
		}
	}
	

}


int main()
{
	std::string name{};
	std::cout << "Please enter your name: ";
	std::cin >> name;

	std::cout << "Welcome, " << name << '\n';

	Player p{ name };
	while (!p.isDead() && !p.hasWon())
		fight(p);

	if (p.isDead())
	{
		std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}

	else
	{
		std::cout << "You won the game with " << p.getGold() << " gold!\n";

	}

	return 0;
}