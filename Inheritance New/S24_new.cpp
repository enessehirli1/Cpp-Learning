#include <iostream>
#include <string>
#include <string_view>
#include "Creature.h"
#include "Player.h"
#include "Monster.h"

void fightMonster(Player& p, Monster& m);
void attackPlayer(Player& p, Monster& m);
void attackMonster(Monster& m, Player& p);




int main()
{
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;

	Player p{ name };

	while (!p.hasWon())
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ")!\n";
		fightMonster(p, m);
	}

	std::cout << "Congratulations! You have reached level 20 and won the game!\n";

	return 0;
}
