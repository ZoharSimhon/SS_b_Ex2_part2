#pragma once
#include <string>
#include <iostream>
using namespace std;

namespace ariel {}

class Card
{
    private:
        int number;
        string shape;
        int handleAceCase(Card otherCard);

    public:
        Card(int, string);
        int compareTo(Card other);
        string toString();
};