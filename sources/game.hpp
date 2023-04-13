#pragma once

#include <iostream>
#include <vector>
#include "player.hpp"
#include "card.hpp"
using namespace std;
using namespace ariel;

class Game{
private:
    ariel::Player p1, p2;
    string winner;
    int draws;
    vector<Card> deck;
    vector<string> stats;

public:
    Game();
    Game(Player &p1, Player &p2);

    void shuffleNewDeck(vector<Card>& deck);
    void dealCards(vector<Card>& deck, Player& _p1, Player& _p2);
    void playTurn();
    void playAll(); //plays the game until the endif
    void printLastTurn(); // print the last turn stats
    void printWiner(); // prints the name of the winning player
    void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
    void printStats(); // for each player prints basic statistics: win rate, cards won.
                        // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws)
    void brakeTie(); // In case of a tie, both players place a card face down, and open a new card. The winner takes the six cards.
};