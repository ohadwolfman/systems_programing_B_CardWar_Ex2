#pragma once
#include <iostream>
using namespace std;

namespace ariel {
    class Card {
        int card_number;
        string shape;

    public:
        Card(int card_number, string shape);

        Card();//empty constructor

        //~Card();//destructor

        string toString();

        int getCard_number();

        string getShape();

        int compare(Card other);
    };
};