#pragma once
#include <vector>
#include <string>
#include "card.hpp"
using namespace std;

class Player
{
private:
    string name;
    vector<Card> cards;
    bool inPlay;

public:
    Player(string);
    int stacksize();
    int cardesTaken();
    void setCards(vector<Card> &);
    Card &getFirstCard();
    string getName();
    void addCardsTaken(int);
    bool getInPlay();
    void setInPlay(bool);
}