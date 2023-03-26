#pragma once
#include <iostream>

#ifndef UNTITLED_GAME_HPP
#define UNTITLED_GAME_HPP

class Game{
private:
    std::string winner;

public:
    void printLastTurn(); // print the last turn stats
    void playAll(); //playes the game untill the endif
    void printWiner(); // prints the name of the winning player
    void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats(); // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )

};

#endif //UNTITLED_GAME_HPP
