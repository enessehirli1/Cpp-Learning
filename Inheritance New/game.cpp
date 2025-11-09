#include <iostream>
#include <string>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

void attackMonster(Monster& m, Player& p)
{
	m.reduceHealth(p.getDamage());
	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << "!\n";
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << ".\n";
		p.addGold(m.getGold());
		std::cout << "You found " << m.getGold() << " gold on the " << m.getName() << ".\n";

 	}
}

void attackPlayer(Player& p, Monster& m)
{
	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

void fightMonster(Player& p, Monster& m)
{
	while (!m.isDead() || !p.isDead())
	{
		char choice;
		std::cout << "(R)un or (F)ight: ";
		std::cin >> choice;
		if (choice == 'r' || choice == 'R')
		{
			int success{ Random::get(0, 1) };
			if (success)
			{
				std::cout << "You successfully fled!\n";
				return;
			}
			else
			{
				std::cout << "You failed to run away!\n";
				attackPlayer(p, m);
				if (p.isDead())
				{
					std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
					std::cout << "Too bad you can’t take it with you!";
					return;
				}
			}
		}

		else if (choice == 'f' || choice == 'F')
		{
			attackMonster(m, p);
			if (m.isDead())
			{
				return;
			}
			attackPlayer(p, m);
			if (p.isDead())
			{
				std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
				std::cout << "Too bad you can’t take it with you!";
				return;
			}
		}
		else
		{
			std::cout << "Invalid choice. Please choose again.\n";
		}
	}
}


