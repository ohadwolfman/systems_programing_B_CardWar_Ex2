#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

#include <stdexcept>
#include <iostream>
#define MaxCards 26

using namespace std;
using namespace ariel;

TEST_CASE("Game initialization"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game game(p1, p2));
}

TEST_CASE("Stack and initialization") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    CHECK(p1.stacksize() == MaxCards);
    CHECK(p2.stacksize() == MaxCards);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
}

TEST_CASE("Same Player") {
    Player p1("Eve");
    CHECK_THROWS(Game(p1, p1));
}

TEST_CASE("Closed system - no card disappear") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i=0; i<5; ++i) {
        game.playTurn();
    }
    int totalCards = p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken();
    CHECK(totalCards == 52);
}