#pragma once
#include <iostream>

using namespace std;
namespace ariel {

    class Player {
    private:
        string playerName;
        int stack;
        bool isPlayingNow;
        int cards_won;
        int win_rate;

    public:
        //prints the amount of cards left. should be 21 but can be less if a draw was played
        int stacksize() { return stack; }

        // prints the amount of cards this player has won.
        int cardsTaken();



        Player(){
            this->playerName="p";
            this->stack=0;
            this->cards_won=0;
            this->isPlayingNow= true;
            this->win_rate=0;
        };

        Player(std::string playerName, int stack, bool isPlayingNow) {
            playerName = playerName;
            stack = stack;
            isPlayingNow = isPlayingNow;
        }
    };
};