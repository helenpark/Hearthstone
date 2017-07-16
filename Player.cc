#include "Player.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Player::Player(string name, Board board*): name(name), board(board), MP(3), HP(20)
{
	// game starts, add 4 cards to the player's hand
	for (int i = 0; i < 4; i++) {
		hand.emplace_back(Deck.back());
		Deck.pop_back();
	}					  
}
void Player::placeCard(Card *card) {
	
}	
