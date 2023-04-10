#pragma once
#include <string>
using namespace std;

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
}