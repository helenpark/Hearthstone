#include "Player.h"
#include "Card.h"
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

void Player::placeCard(int i) {
	// if its a minion
	if (hand[i].getType() == Card::Minion) {
		board.placeMinion(hand[i]);
	}
	// if its a ritual type
	if (hand[i].getType() == Card::Ritual) {
		board.placeRitual(hand[i]);
	}
	// if its a Spell
	if (hand[i].getType() == Card::Spell) {
		board.playSpell(hand[i]);
	}
}

void Player::placeCard(int i, int p, int t) {
	Card *target = getTarget(int p, int t);

	// if its a spell
	if (hand[i].getType() == Card::Spell) {
		board.playSpell(hand[i], target);
	}
	// if its an enchantment card
	if (hand[i].getType() == Card::Enchantment) {
		board.playEnchantment(hand[i], target);
	}
}

void Player::drawCard() {
	if (hand.size() == 5 || Deck.isEmpty()) {
		return;
	}	
	hand.emplace_back(Deck.draw());	
}

void Player::discardCard(int i) {
	if (hand.empty()) {
		return;
	}
	hand.erase(i);
}



