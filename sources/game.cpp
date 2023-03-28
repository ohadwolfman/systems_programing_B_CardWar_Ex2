#include "game.hpp"
#include <iostream>

void playTurn(){

}

void Game::printWinner() {
    std::cout<<"you are the winner"<<std::endl;
}

void Game::playAll() {
    std::cout<<"player1:"<<p1.playerName<<"has "<<p1.win_rate<<"wins, and won "<<p1.cards_won<<"cards";


}

void Game::printLastTurn() {
    std::cout<<"the last turn was: "<<std::endl;

}

void Game::printLog() {
    std::cout<<"The game was:"<<std::endl;

}

void Game::printStats() {

}

