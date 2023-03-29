#pragma once

#include <iostream>
using namespace std;

namespace ariel {
    class Card {
        int card_number;
        string shape;

    public:
        Card (int card_number, string shape){
            this->card_number = card_number;
            this->shape =  shape;
        }

        int getCard_number() { return this->card_number; }
        string getShape() { return this->shape; }

        void setNumber(int number);
        void setShape(string shape);
        string toString();
        int compare(Card other); //return 1 if the first number is higher, -1 if the other number is higher, 0 otherwise
    };
};