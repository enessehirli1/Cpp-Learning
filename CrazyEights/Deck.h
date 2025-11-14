#pragma once
#include <iostream>
#include "Deck.h"
#include <algorithm>
#include <random>

class Deck
{
private:
	std::vector<Card> m_deck{};

public:
	Deck(std::vector<char>& ranks, std::vector<char>& suits)
	{
		std::vector<Card> preDeck{};
		for (const auto& s : suits)
			for (const auto& r : ranks)
			{
				Card card{ r, s };
				preDeck.push_back(card);
			}
		m_deck = preDeck;
	}

	friend std::ostream& operator<<(std::ostream& out, const Deck& d)
	{
		for (std::size_t i{ 0 }; i < d.m_deck.size(); i++)
		{
			if (d.m_deck[i].rank == '0')
			{
				out << "10" << d.m_deck[i].suit << ' ';
			}
			else
			{
				out << d.m_deck[i] << ' ';
			}

			if (i == 12 || i == 25 || i == 38)
				out << '\n';
		}
		return out;
	}


	void shuffle()
	{
		static std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
		std::shuffle(m_deck.begin(), m_deck.end(), rng);
	}

	Card draw()
	{
		if (m_deck.empty())
		{
			throw std::runtime_error("Deck is empty!");
		}
		Card card{ m_deck.back() };
		m_deck.pop_back();
		return card;
	}
};
