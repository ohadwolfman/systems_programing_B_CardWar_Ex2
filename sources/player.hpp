#pragma once

#include <iostream>
#define MaxCards 26

using namespace std;
namespace ariel {

    class Player {
    private:
        string playerName;
        int stack;
        bool isPlayingNow;
        int cards_won;
        double win_rate;

    public:
        Player(); //default constructor
        Player(string playerName); //constructor

        int stacksize() { return stack; } //prints the amount of cards left
        int cardesTaken() { return cards_won; } // prints the amount of cards this player has won.
        string getPlayerName() const{ return this->playerName; }
        int getIsPlayingNow() const{ return this->isPlayingNow; }
        int getWin_rate() const{ return this->win_rate; }
    };
}