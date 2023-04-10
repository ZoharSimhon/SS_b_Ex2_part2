#include "player.hpp"

Player::Player(string name)
{
    this->name = name;
    this->inPlay = false;
    this->cardsTaken = 0;
}

Card &Player::getFirstCard()
{
    this->inPlay = false;
    Card &lastCard = cards.back();
    cards.pop_back();
    return lastCard;
}

bool Player::getInPlay()
{
    return inPlay;
}

void Player::setInPlay(bool inPlay)
{
    this->inPlay = inPlay;
}

void Player::setCards(vector<Card> &cards)
{
    this->cards = cards;
}

string Player::getName()
{
    return this->name;
}

void Player::addCardsTaken(int number)
{
    this->cardsTaken += number;
}

int Player::cardesTaken()
{
    return this->cardsTaken;
}

int Player::stacksize()
{
    return this->cards.size();
}
