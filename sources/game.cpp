#include <random>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "game.hpp"


using namespace std;
using namespace ariel;

Game::Game():
    p1(Player("Alice")),
    p2(Player("Bob")),
    winner("There is no winner yet"),
    draws(0),
    stats (){}

Game::Game(Player &p1, Player &p2):
        p1(p1),
        p2(p2),
        winner("There is no winner yet"),
        draws(0),
        stats ()
        {
            if(&p1 == &p2) {
                throw invalid_argument("same player");
            }
            if (p1.isPlayingNow() || p2.isPlayingNow())
                throw runtime_error("Wait until both of the players will finish their games");
        }

void Game::shuffleNewDeck(vector<Card>& deck){
    for(int i=1; i<=13 ;i++){
        deck.push_back(Card(i,"Heart"));
        deck.push_back(Card(i,"Diamonds"));
        deck.push_back(Card(i,"Clubs"));
        deck.push_back(Card(i,"Spades"));
    }

    //random_shuffle(deck.begin(), deck.end()); //https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    for (size_t i = 0; i < 26; i++) {
        p1.insertCardToStack(deck[i*2]);
        p2.insertCardToStack(deck[i*2 + 1]);
    }
}

void Game::playTurn(){
    Card a = p1.draw_A_Card();
    Card b = p2.draw_A_Card();
    string turnData = p1.getPlayerName() + " played " + a.toString() + " " + p2.getPlayerName() + " played " + b.toString();
    int turn = a.compare(b);
    if(turn == 1){
        p1.wonTheTurn(2);
        turnData += ", " + p1.getPlayerName() + " earned 2 cards";
        cout<< turnData;
    }
    else if(turn == -1){
        p2.wonTheTurn(2);
        turnData += ", " + p2.getPlayerName() + " earned 2 cards";
        cout<< turnData;
    }
    else{
        Game::brakeTie();
    }
}

void Game::printWiner() {
    cout<<Game::winner<<endl;
}

void Game::playAll() {
    while(draws<26){
        playTurn();
        ++draws;
    }
    cout<<p1.getPlayerName()<<" has "<<p1.getWinnings()<<" wins, and won "<<p1.cardesTaken()<<" cards\n";
    cout<<p2.getPlayerName()<<" has "<<p2.getWinnings()<<" wins, and won "<<p2.cardesTaken()<<" cards\n";
}

void Game::printLastTurn() {
    cout<<"the last turn was: "<<std::endl;
}

void Game::printLog() {
    cout<<"Printing log:"<<std::endl;
}

void Game::printStats() {
    cout<<p1.getPlayerName()<<" has "<<p1.getWinnings()<<" wins, and won "<<p1.cardesTaken()<<" cards\n";
    cout<<p2.getPlayerName()<<" has "<<p2.getWinnings()<<" wins, and won "<<p2.cardesTaken()<<" cards\n";
}

void Game::brakeTie(){
    int amount = 2;
    Card a = p1.draw_A_Card();
    Card b = p2.draw_A_Card();
    a = p1.draw_A_Card();
    b = p2.draw_A_Card();
    draws+=2;
    string turnData = p1.getPlayerName() + " played " + a.toString() + " " + p2.getPlayerName() + " played " + b.toString();
    if(a.compare(b) == 1){
        amount += 4;
        p1.wonTheTurn(amount);
        cout<< turnData<< ", " + p1.getPlayerName() + " earned " << amount << " cards";
    }
    else if(a.compare(b) == -1){
        amount += 4;
        p2.wonTheTurn(amount);
    }
    else{
        amount += 4;
        brakeTie();
    }
}

