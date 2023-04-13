#include <iostream>
#include "card.hpp"

using namespace ariel;
using namespace std;

// Constructor
Card::Card (int card_number, string shape):
    card_number(card_number), shape(shape) {};

string Card::toString() {
    if (this->card_number<11 && this->card_number!=1){
        return this->getCardNumber() + " of " + this->getShape();
    }
    else if (this->card_number == 1) {
        return "Ace of " + this->shape;
    }
    else if (this->card_number == 11) {
        return "Prince of " + this->shape;
    }
    else if (this->card_number == 12) {
        return "Queen of " + this->shape;
    }
    else{       // (this->card_number == 13)
        return "King of " + this->shape;
    }
}

int Card::compare(Card other){
    if (this->card_number ==1 && other.card_number == 2){ // Ace wins all except 2
        return -1;
    }
    if (this->card_number == 2 && other.card_number == 1){ // Ace wins all except 2
        return 1;
    }
    else if(this->card_number > other.card_number){
        return 1;
    }
    else if(this->card_number < other.card_number){
        return -1;
    }
    else{
        return 0;
    }
}

int Card::getCardNumber(){
    return this->card_number;
}

string Card::getShape() {
    return this->shape;
}
