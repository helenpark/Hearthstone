#include "Player.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Player::Player(int num, int oppNum,  string name, Board &board): number(num), oppNumber(oppNum, name(name), board(board), MP(3), HP(20)
{
	// game starts, add 4 cards to the player's hand
	for (int i = 0; i < 4; i++) {
		hand.emplace_back(Deck.drawCard());
	}					  
}

void Player::placeCard(int i) {
	// if its a minion
	if (hand[i].getType() == Card::Minion) {
		board.placeMinion(hand[i], number);
		MinionsPlayed.emplace_back(hand[i]);
	}
	// if its a ritual type
	if (hand[i].getType() == Card::Ritual) {
		board.placeRitual(hand[i], number);
		ritualPlayed = hand[i];
	}
	// if its a Spell
	if (hand[i].getType() == Card::Spell) {
		board.playSpell(hand[i]);
	}
}

void Player::placeCard(int i, int p, int t) {
	Card *target = board.getTarget(p, t);

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
	if (hand.size() == 5 || playerDeck->isEmpty()) {
		return;
	}	
	hand.emplace_back(playerDeck->drawCard());	
}

void Player::discardCard(int i) {
	if (hand.empty()) {
		return;
	}
	const int temp = i;
	hand.erase(temp);
}

void Player::attack(int i, int j) {
	Card *target = board.getTarget(oppNum, j);
	
	MinionsPlayed[i]->attack(target);
}

void Player::attack(int i) {
	// grab the amount of attack it does
	int AP = MinionsPlayed[i]->attack(opponent);
	// inflict that amount on to the opponent;
	opponent.inflictDmg(AP);
	
}

void Player::use(int i, int p, int t) {
	Card *target = Board.getTarget(p, t);

	// execute the function from minion that would use the ability
	MinionsPlayed[i]->use(target);
	
}

void Player::use(int i) {
	MinionsPlayed[i]->use();
}

void Player::inspect(int i) {
	board.inspect(i, number);
}

void Player::displayHand() {};

void Player::initDeck(string filename) {
	playerDeck.initDeck(filename);	
}

void Player::turnStart() {
	MP++;

	if (hand.size() != 5 || !playerDeck->isEmpty()) {
		drawCard();	
	}			
}

bool Player::isDead() {
	if (HP == 0) {
		return true;
	}
	return false;
}

void Player::setOpponent(Player *opp) {
	opponent = opp; 
}
