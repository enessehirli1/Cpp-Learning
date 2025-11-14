#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"


int main()
{
    std::vector<char> ranks{ 'A','2','3','4','5','6','7','8','9','0','J','Q','K' };
    std::vector<char> suits{ 'H','D','C','S' };

    Game game(ranks, suits, 2); // 2 oyuncu

	game.start();
    return 0;
}
