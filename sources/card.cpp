#include <iostream>
#include "card.hpp"
using namespace ariel;
using namespace std;

void Card::setNumber(int number){
    cout<<"number set to: "<<number<<endl;
}

void Card::setShape(string shape){
    cout<<"shape set to: "<<shape<<endl;
}

string Card::toString(){
    return this->getShape();
}

int Card::compare(Card other){
    if(this->card_number > other.card_number){
        return 1;}
    else if(this->card_number < other.card_number){
        return -1;}
    else{
        return 0;}
}