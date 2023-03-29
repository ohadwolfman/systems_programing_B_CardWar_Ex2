#include "player.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

//default constructor
Player::Player(){
    this->playerName="default";
    this->stack=MaxCards;
    this->cards_won=0;
    this->isPlayingNow= true;
    this->win_rate= 0;
}

Player::Player(string playerName):
    playerName(playerName){};

