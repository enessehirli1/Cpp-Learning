#pragma once
#include "Card.h"
#include "Deck.h"
#include "Player.h"

class Game
{
private:
	Deck m_deck;
	std::vector<Player> m_players;
	std::vector<Card> m_discardPile;
	std::size_t m_currentPlayerIndex{};
	char m_currentSuit;

public:
	Game(std::vector<char>& ranks, std::vector<char>& suits, std::size_t numPlayers);
	void start();
	bool match(Card& card);
	char choice();
};