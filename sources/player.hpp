#pragma once

#include <string>
#include <vector>
#include "card.hpp"

#define MaxCards 26

using namespace std;
namespace ariel {

    class Player {
    private:
        string playerName;
        vector <Card> stack;
        int cards_won;
        double winnings;
        bool PlayingNow;

    public:
        Player(string playerName); //constructor
        string getPlayerName();
        int stacksize(); // returns the amount of cards left
        int cardesTaken(); // returns the amount of cards this player has won in this game.
        int getWinnings(); // returns the amount of winnings the player won
        bool isPlayingNow();
        void wonTheTurn(int amount);
        void wonTheGame();
        Card draw_A_Card();
        void insertCardToStack(Card c);
    };
}