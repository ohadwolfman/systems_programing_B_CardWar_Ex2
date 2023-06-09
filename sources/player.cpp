#include "player.hpp"
#include "card.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

// Constructor
Player::Player(const string& playerName)
        : playerName(playerName), stack(*new vector<Card>()), cards_won(0), winnings(0), PlayingNow(true) {
    if (this->playerName.empty()) {
        throw runtime_error("Please insert a name for the player");
    }
}

// Getters
string Player::getPlayerName() { return this->playerName;}
int Player::stacksize() { return stack.size(); } // returns the amount of cards left
int Player::cardesTaken() { return cards_won; } // returns the amount of cards this player has won in this game.
int Player::getWinnings() { return this->winnings; } // returns the amount of winnings the player won
bool Player::isPlayingNow() { return PlayingNow; }

// Updating data during the game functions
void Player::wonTheTurn(int amount){
    this->cards_won += amount;
}

void Player::wonTheGame(){
    ++this->cards_won;
}

Card Player::draw_A_Card() {
    if (stack.empty()) {
        throw runtime_error("Player's stack is empty. Cannot draw a card.");
    }

    Card headCard = stack.back();
    stack.pop_back();
    return headCard;
}


void Player::insertCardToStack(Card newCard){
    this->stack.push_back(newCard);
}

