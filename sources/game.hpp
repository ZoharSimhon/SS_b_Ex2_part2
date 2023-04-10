#pragma once
#include "player.hpp"

class Game
{
private:
    Player &player1, &player2;
    vector<string> logs;
    int player1wins;
    int player2wins;
    int draws;
    void splitPacketCards(vector<Card>& cards);
    void buildPacketCards();
    void checkValidPlayers();

public:
    Game(Player &, Player &);
    void playTurn();
    void playAll();
    void printWiner();
    void printLastTurn();
    void printLog();
    void printStats();
}