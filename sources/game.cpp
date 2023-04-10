#include "game.hpp"
Game::Game(Player &player1, Player &player2) : player1(player1), player2(player2)
{
    this->draws = 0;
    this->player1wins = 0;
    this->player2wins = 0;
    buildPacketCards();
}

void Game::buildPacketCards()
{
    vector<Card> cards;
    string shapes[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 13; j++)
        {
            Card card(i, shapes[j]);
            cards.push_back(card);
        }
    }
    splitPacketCards(&cards);
}

void Game::splitPacketCards(vector<Card> &cards)
{
    vector<Card> player1cards;
    vector<Card> player2cards;
    srand(time(NULL));
    for (size_t i = 52; i > 0; i--)
    {
        int index = rand() % i;
        if (i % 2 == 0)
        {
            player1cards.push_back(cards.at((size_t)index));
        }
        else
        {
            player2cards.push_back(cards.at((size_t)index));
        }
        cards.erase((size_t)index);
    }
    this->player1.setCards(player1cards);
    this->player2.setCards(player2cards);
}

void Game::playTurn()
{
    checkValidPlayers();
    Card card1 = this->player1.getFirstCard();
    Card card2 = this->player2.getFirstCard();
    bool isEmpty = false;
    int winner = card1.compareTo(card2);
    int counter = 1;
    string log = player1.getName() + " played " + card1.toString();
    log += " " + player2.getName() + " played " + card2.toString() + ".";
    while (winner == 0 || !isEmpty)
    {
        this->draws++;
        log += " Draw. ";
        for (size_t i = 0; i < 2; i++)
        {
            if (0 < this->player1.stacksize())
            {
                card1 = this->player1.getFirstCard();
                card2 = this->player2.getFirstCard();
            }
            else
            {
                isEmpty = true;
                break;
            }
        }
        if (!isEmpty)
        {
            log += player1.getName() + " played " + card1.toString();
            log += " " + player2.getName() + " played " + card2.toString() + ".";
            winner = card1.compareTo(card2);
            counter++;
        }
    }
    int cardsTaken = (counter * 2 - 1) * 2;
    if (winner == 1)
    {
        log += player1.getName() + " wins.";
        player1.addCardsTaken(cardsTaken);
        this->player1wins++;
    }
    else if (winner == -1)
    {
        log += player2.getName() + " wins.";
        player2.addCardsTaken(cardsTaken);
        this->player2wins++;
    }
    else
    {
        player1.addCardsTaken(cardsTaken / 2);
        player2.addCardsTaken(cardsTaken / 2);
        this->draws++;
    }
    this->logs.push_back(log);
}

void Game::playAll()
{
    while (0 < this->player1.stacksize())
    {
        playTurn();
    }
}

void Game::printWiner()
{
    int player1cards = this->player1.cardesTaken();
    int player2cards = this->player2.cardesTaken();
    if (player1cards < player2cards)
    {
        cout << this->player1.getName() + " wins" << endl;
    }
    else if (player2cards < player1cards)
    {
        cout << this->player2.getName() + " wins" << endl;
    }
    else
    {
        cout << "There is a tie" << endl;
    }
}

void Game::printLastTurn()
{
    cout << logs.back() << endl;
}

void Game::printLog()
{
    for (size_t i = 0; i < this->logs.size(); i++)
    {
        cout << logs.at(i) << endl;
    }
}

void Game::printStats()
{
    //
    double player1winRate = ((double)player1wins / this->logs.size()) * 100;
    cout << player1.getName() + ": Winning rate: " + to_string(player1winRate);
    cout << ", Cards won: " + to_string(player1.cardesTaken()) << endl;
    //
    double player2winRate = ((double)player2wins / this->logs.size()) * 100;
    cout << player2.getName() + ": Winning rate: " + to_string(player2winRate);
    cout << ", Cards won: " + to_string(player2.cardesTaken()) << endl;
    //
    double drawRate = ((double)draws / this->logs.size()) * 100;
    cout << "Game: Draw rate: " + to_string(drawRate);
    cout << ", Draw amount: " + to_string(draws) << endl;
}

void Game::checkValidPlayers()
{
    if (this->player1.getInPlay())
    {
        throw invalid_argument("Player one is already playing");
    }
    this->player1.setInPlay(true);
    if (this->player2.getInPlay())
    {
        throw invalid_argument("Player two is already playing");
    }
}