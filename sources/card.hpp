#pragma once

#include <iostream>
using namespace std;

namespace ariel {
    class Card {
        int card_number; // 1 (Ace) to 13 (King)
        string shape; // Hearts, Diamonds, Clubs, Spades

    public:
        Card (int card_number, string shape);
        string toString();
        int compare(Card other); //return 1 if the first number is higher, -1 if the other number is higher, 0 otherwise
        int getCardNumber();
        string getShape();
    };
}