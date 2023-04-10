#include "card.hpp"

Card::Card(int number, string shape)
{
    this->number = number;
    this->shape = shape;
}

int Card::handleAceCase(Card otherCard)
{
    if (this->number == 2)
    {
        return 1;
    }
    else if (otherCard.number == 2)
    {
        return -1;
    }
    else if (this->number == 1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int Card::compareTo(Card other)
{
    if (this->number == other.number)
    {
        return 0;
    }
    else if (this->number == 1 || other.number == 1)
    {
        handleAceCase(other);
    }
    else if (this->number < other.number)
    {
        return -1;
    }
    
    return 1;
}

string Card::toString()
{
    string numberAsString = "";
    switch (this->number)
    {
    case 11:
        numberAsString = "Jack";
        break;
    case 12:
        numberAsString = "Queen";
        break;
    case 13:
        numberAsString = "King";
        break;
    case 1:
        numberAsString = "Ace";
        break;
    default:
        numberAsString = to_string(this->number);
        break;
    }
    return numberAsString + " of " + this->shape;
}
