#include "player.hpp"

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

