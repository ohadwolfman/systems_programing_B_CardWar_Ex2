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

TEST_CASE("Check all the functions are compiling") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printWiner());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("Same Player") {
    Player p1("Eve");
    CHECK_THROWS(Game(p1, p1));
}

TEST_CASE("Player with no name") {
    CHECK_THROWS_AS(Player(nullptr), invalid_argument);
    CHECK_THROWS_AS(Player(""), invalid_argument);
}

TEST_CASE("Closed system - no card disappear") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    for (int i=0; i<5; ++i) {
        game.playTurn();
    }
    int totalCards = p1.stacksize() + p2.stacksize() + p1.cardesTaken() + p2.cardesTaken();
    CHECK(totalCards == (2*MaxCards));
}

TEST_CASE("Check amounts Before the game") {
    Player p1("Alice");
    Player p2("Bob");

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.stacksize() != 0);
    CHECK(p2.stacksize() != 0);
}

TEST_CASE("There is a Winner after PlayAll") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    CHECK(p1.stacksize() == MaxCards);
    CHECK(p2.stacksize() == MaxCards);

    CHECK(p1.cardesTaken() != p2.cardesTaken());

    //The winning player should have more than 0 cards taken
    if (p1.cardesTaken() > p2.cardesTaken()) {
        CHECK(p1.cardesTaken() > 0);
        CHECK(p2.cardesTaken() == 0);
    } else {
        CHECK(p2.cardesTaken() > 0);
        CHECK(p1.cardesTaken() == 0);
    }
}

TEST_CASE("cards decreasing together") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);

    game.playTurn();
    CHECK(p1.stacksize() == p2.stacksize());
    CHECK(p1.stacksize() < MaxCards);
    CHECK(p2.stacksize() < MaxCards);
}

TEST_CASE("playTurn after the end of the game") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
}