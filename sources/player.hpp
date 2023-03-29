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
        string getPlayerName() { return this->playerName; }
        int getIsPlayingNow() { return this->isPlayingNow; }
        double getWin_rate() { return this->win_rate; }
    };
}