#include <random>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "game.hpp"

using namespace std;
using namespace ariel;

Game::Game() :
        p1(Player("Alice")),
        p2(Player("Bob")),
        winner("There is no winner yet"),
        draws(0),
        deck(new vector<Card>()),
        stats() {
    shuffleNewDeck(*deck);
    dealCards(p1, p2);
    cout << deck->size() << " cards in deck" << endl;
}

Game::Game(Player& p1, Player& p2) :
        p1(p1),
        p2(p2),
        winner("There is no winner yet"),
        draws(0),
        deck(new vector<Card>()),
        stats() {
    shuffleNewDeck(*deck);
    dealCards(p1, p2);
}

// Initialize deck of cards, shuffle it, and deal to players
void Game::shuffleNewDeck(vector<Card>& deck) {
    deck.clear(); // Clear the deck vector before initializing
    for (int i = 1; i <= 13; i++) {
        deck.push_back(Card(i, "Heart"));
        deck.push_back(Card(i, "Diamonds"));
        deck.push_back(Card(i, "Clubs"));
        deck.push_back(Card(i, "Spades"));
    }

    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);
}

void Game::dealCards(Player& _p1, Player& _p2)
{
    if (deck->size() != 52) {
        throw runtime_error("Invalid deck size. The deck must contain 52 cards.");
    }

    for (size_t i = 0; i < 26; ++i) {
        _p1.insertCardToStack(deck->at(i));
    }
    for (size_t i = 26; i < 52; ++i) {
        _p2.insertCardToStack(deck->at(i));
    }
    deck->clear();
}


void Game::playTurn() {
    if (&p1 == &p2 || p1.getPlayerName()==p2.getPlayerName()) {
        throw invalid_argument("same player");
    }
    if(this->p1.stacksize()==0){
        return;
    }
    Card a = p1.draw_A_Card();
    Card b = p2.draw_A_Card();
    string turnData = p1.getPlayerName() + ": " + a.toString() + ", " + p2.getPlayerName() + ": " + b.toString();
    int turn = a.compare(b);
    if (turn == 1) {
        p1.wonTheTurn(2);
        turnData += ", " + p1.getPlayerName() + " earned 2 cards\n";
        cout << turnData;
    }
    else if (turn == -1) {
        p2.wonTheTurn(2);
        turnData += ", " + p2.getPlayerName() + " earned 2 cards\n";
        cout << turnData;
    }
    else {
        breakTie();
    }
}
void Game::printWiner() {
    cout<<Game::winner<<endl;
}

void Game::playAll() {
    while (draws < 26) {
        ++draws;
        playTurn();
    }
    cout << p1.getPlayerName() << " has " << p1.getWinnings() << " wins, and won " << p1.cardesTaken() << " cards\n";
    cout << p2.getPlayerName() << " has " << p2.getWinnings() << " wins, and won " << p2.cardesTaken() << " cards\n";
}

void Game::printLastTurn() {
    cout<<"the last turn was: "<<std::endl;
}

void Game::printLog() {
    cout<<"Printing log:"<<std::endl;
}

void Game::printStats() {
    cout << p1.getPlayerName() << " has " << p1.getWinnings() << " wins, and won " << p1.cardesTaken() << " cards\n";
    cout << p2.getPlayerName() << " has " << p2.getWinnings() << " wins, and won " << p2.cardesTaken() << " cards\n";
}
void Game::breakTie() {
    int amount = 2;
    Card a = p1.draw_A_Card();
    Card b = p2.draw_A_Card();
    a = p1.draw_A_Card();
    b = p2.draw_A_Card();
    draws += 2;
    string turnData = p1.getPlayerName() + ": " + a.toString() + ", " + p2.getPlayerName() + ": " + b.toString();
    if (a.compare(b) == 1) {
        amount += 4;
        p1.wonTheTurn(amount);
        cout << turnData << ", " + p1.getPlayerName() + " earned " << amount << " cards\n";
    }
    else if (a.compare(b) == -1) {
        amount += 4;
        p2.wonTheTurn(amount);
    }
    else {
        amount += 4;
        breakTie();
    }
}

