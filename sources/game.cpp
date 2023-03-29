#include "game.hpp"
#include <iostream>
#include "player.hpp"
using namespace std;

Game::Game(){
    this->p1= Player("Alice");
    this->p2= Player("Bob");
    this->winner= "There is no winner yet";
}

Game::Game(Player p1, Player p2){
    this->winner="There is no winner yet";
}

void Game::playTurn(){
    cout<<"Play turn"<<std::endl;
}

void Game::printWiner() {
    cout<<"you are the winner"<<std::endl;
}

void Game::playAll() {
    cout<<"player1: "<<p1.getPlayerName()<<" has "<<p1.getWin_rate()<<" wins, and won "<<p1.cardesTaken()<<" cards\n";
    cout<<"player2: "<<p2.getPlayerName()<<" has "<<p2.getWin_rate()<<" wins, and won "<<p2.cardesTaken()<<" cards\n";
}

void Game::printLastTurn() {
    cout<<"the last turn was: "<<std::endl;
}

void Game::printLog() {
    cout<<"Printing log:"<<std::endl;
}

void Game::printStats() {
    cout<<"Printing stats:"<<std::endl;
}

