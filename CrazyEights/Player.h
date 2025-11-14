#pragma once
#include "Card.h"
#include "Deck.h"

class Player 
{
private:
	std::vector<Card> m_hand{};

	Card playCard(std::size_t index)
	{
		if (index >= m_hand.size())
			throw std::out_of_range("Invalid Card Index");

		Card chosenCard{ m_hand[index] };
		m_hand.erase(m_hand.begin() + static_cast<int>(index));

		return chosenCard;
	}

public:
	Player(Deck& d)
	{
		for (std::size_t i{ 0 }; i < 5; i++)
		{
			m_hand.push_back(d.draw());
		}
	}

	std::vector<Card>& getHand()
	{
		return m_hand;
	}

	void drawCard(Deck& d)
	{
		m_hand.push_back(d.draw());
	}

	Card playCardInteractive()
	{
		std::size_t index;
		while (true)
		{
			std::cout << "Enter card index to play (0-" << m_hand.size() - 1 << ")"
			<< " or Next Turn(" << m_hand.size() << ")\n";
			std::cin >> index;

			if (index < m_hand.size()+1)
				break;

			std::cout << "Invalid index! Try again.\n";
		}

		if (index == m_hand.size())
			throw std::runtime_error("NextTurn");

		return playCard(index);
	}

	void showHand()
	{
		std::cout << "Your hand is: ";
		for (const auto& e : m_hand)
			std::cout << e << ' ';
		std::cout << '\n';
	}

	bool won()
	{
		return !m_hand.size();
	}
};