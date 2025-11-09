#include <iostream>
#include <array>
#include "Struct.h"
#include "Deck.h"
#include "Player.h"

namespace Settings
{
    constexpr int bust{ 21 };
    constexpr int dealerStopsAt{ 17 };
}

bool dealersTurn(Deck& deck, Player& dealer)
{
    while (dealer.score <= Settings::dealerStopsAt)
    {
        Card card{ deck.dealCard() };
        dealer.score += card.value();
        std::cout << "The dealer flips a card " << card << ". They now have a score " << dealer.score << '\n';
    }

    if (dealer.score > Settings::bust)
    {
        std::cout << "The dealer went bust!.\n";
        return true;
    }

    return false;
}

bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}


bool playersTurn(Deck& deck, Player& player)
{
    while (player.score < Settings::bust && playerWantsHit())
    {
        Card card{ deck.dealCard() };
        player.score += card.value();

        std::cout << "You were dealt " << card << ". You now have score: " << player.score << '\n';
    }

    if (player.score > Settings::bust)
    {
        std::cout << "You went bust!\n";
        return true;
    }

    return false;
}

bool playBlackjack()
{
    Deck deck{};
    deck.shuffle();
    
    Player dealer{ deck.dealCard().value() };

    std::cout << "The dealer is showing: " << dealer.score << '\n';

    Player player{ deck.dealCard().value() + deck.dealCard().value()};

    std::cout << "You have score: " << player.score << '\n';

    if (playersTurn(deck, player))
        return false;

    if (dealersTurn(deck, dealer))
        return true;

    return (player.score > dealer.score);
     

}

int main()
{
    if (playBlackjack())
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}