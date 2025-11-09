#pragma once
#include <iostream>
#include <array>
#include <cassert>
#include "Struct.h"
#include <algorithm> // for std::shuffle
#include "Random.h"  // for Random::mt

class Deck
{
private:
	std::array<Card, 52> m_deck{};
	std::size_t m_nextCardIndex{ 0 };

public:
	Deck()
	{
		std::size_t count{ 0 };
		for (auto suit : Card::allSuits)
			for (auto rank : Card::allRanks)
				m_deck[count++] = Card{ rank, suit };
	}

	Card dealCard()
	{
		assert(m_nextCardIndex < static_cast<int>(Card::max_ranks) * static_cast<int>(Card::max_suits));

		return m_deck[m_nextCardIndex++];
	}

	void shuffle()
	{
		std::shuffle(m_deck.begin(), m_deck.end(), Random::mt);
		m_nextCardIndex = 0;
	}
};