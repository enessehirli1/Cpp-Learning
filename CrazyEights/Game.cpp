#include "Game.h"

Game::Game(std::vector<char>& ranks, std::vector<char>& suits, std::size_t numPlayers)
    : m_deck(ranks, suits), m_currentPlayerIndex {0}
{
    // Desteyi karýþtýr
    m_deck.shuffle();


    // Oyuncularý oluþtur
    for (std::size_t i = 0; i < numPlayers; ++i)
        m_players.emplace_back(m_deck);

    // Baþlangýç için discard pile’a bir kart koy
    m_discardPile.push_back(m_deck.draw());
    m_currentSuit = m_discardPile.back().suit;
}

bool Game::match(Card& card)
{
    // Take the suit and rank
    char suit{ card.suit };
    char rank{ card.rank };

    // If card is 8 then change the suit and push your card
    if (card.rank == '8')
    {
        m_discardPile.push_back(card);
        char newSuit{};
        std::cout << "CRAZY EIGHTS !! Enter your desired suit: ";
        std::cin >> newSuit;

        m_currentSuit = newSuit;
        return true;
    }

    // Same suit 
    if (m_currentSuit == suit)
    {
        std::cout << "Succesfull. Same suit. \n";
        m_discardPile.push_back(card);
        m_currentSuit = suit;
        return true;
    }

    // Same rank
    if (m_discardPile.back().rank == rank)
    {
        std::cout << "Succesfull. Same rank. \n";
        m_discardPile.push_back(card);
        m_currentSuit = suit;
        return true;
    }

    // Safety mechanism
    std::cout << "Unmatched rank or suit.\n";
    m_players[m_currentPlayerIndex].getHand().push_back(card);
    return false;
}

// take the users input
char Game::choice()
{
    char c;
    std::cout << "(P)lay or (D)raw: ";
    std::cin >> c;
    return c;
}

void Game::start()
{
    m_currentSuit = m_discardPile.back().suit;
    m_currentPlayerIndex = 0;

    bool anyoneHasWon{false};

    while (!anyoneHasWon)
    {   
        std::cout << "\nThere is " << m_discardPile.back() << " at the top. Suit is " << m_currentSuit << '\n';
        std::cout << "It is " << m_currentPlayerIndex + 1  << ". players turn\n";
        m_players[m_currentPlayerIndex].showHand();
        char c{ choice() };
        if (c == 'P' || c == 'p')
        {

            Card card{ m_players[m_currentPlayerIndex].playCardInteractive() };
            match(card);
        }

        else if (c == 'D' || c == 'd')
        {
            // Take a card from deck
            m_players[m_currentPlayerIndex].drawCard(m_deck);
            m_players[m_currentPlayerIndex].showHand();
            try
            {
                Card card{ m_players[m_currentPlayerIndex].playCardInteractive() };
                match(card);
            }
            catch (const std::runtime_error& e)
            {
                if (std::string(e.what()) == "NextTurn")
                {
                    // Player drew and chose not to play -> do nothing, let index advance
                }
                else
                {
                    throw;
                }
            }
        }

        for (std::size_t index{ 0 }; index < m_players.size(); index++)
        {
            if (m_players[index].won())
                std::cout << "Congratulations ! Player number #" << index << "has won!!\n";
                anyoneHasWon = true;
        }

        m_currentPlayerIndex = (m_currentPlayerIndex + 1) % 2;
    }


    std::cout << "Game ended\n";
}



