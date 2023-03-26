#pragma once
#include <iostream>

#ifndef UNTITLED_PLAYER_HPP
#define UNTITLED_PLAYER_HPP
class Player{
private:
    std::string playerName;
    int stack;


public:
    //prints the amount of cards left. should be 21 but can be less if a draw was played
    int stacksize() { return stack; }
    // prints the amount of cards this player has won.
    int cardesTaken();

};
#endif //UNTITLED_PLAYER_HPP
