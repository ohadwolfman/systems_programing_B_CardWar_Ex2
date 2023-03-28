#pragma once

#include <iostream>
#include <stack>
#include "player.hpp"


using namespace ariel;
class Game{
private:
    ariel::Player p1, p2;
    std::string winner;
    std::stack<ariel::Player, ariel::> stack;

public:
    void playAll(); //plays the game until the endif
    void printLastTurn(); // print the last turn stats
    void printWinner(); // prints the name of the winning player
    void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats(); // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

};