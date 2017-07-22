#include "Player.h"
#include "Card.h"
#include "Ability.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Player::Player(int num, int oppNum,  string name, Board &board): number(num), oppNumber(oppNum), name(name), board(board), MP(3), HP(20)
{
	// game starts, add 4 cards to the player's hand
	for (int i = 0; i < 4; i++) {
		hand.emplace_back(Deck.drawCard());
	}					  
}

Card *Player::placeCard(int i) {
	shared_ptr<Card> temp = hand[i];
	// if its a minion
	if (hand[i].getType() == Card::Minion) {
		board.placeMinion(hand[i], number);
		MinionsPlayed.emplace_back(hand[i]);
		hand.erase(i);
		minionPlayed(temp);		
		return temp;
	}
	// if its a ritual type
	if (hand[i].getType() == Card::Ritual) {
		board.placeRitual(hand[i], number);
		ritualPlayed = hand[i];
		hand.erase(i);
		return temp;
	}
	// if its a Spell
	if (hand[i].getType() == Card::Spell) {
		board.playSpell(hand[i]);
		hand.erase(i);
		return temp;
	}
}

void Player::placeCard(int i, int p, int t) {
	Card *target = board.getTarget(p, t);

	// if its a spell
	if (hand[i].getType() == Card::Spell) {
		board.playSpell(hand[i], target);
		hand.erase(i);
	}
	// if its an enchantment card
	if (hand[i].getType() == Card::Enchantment) {
		board.playEnchantment(hand[i], target);
		hand.erase(i);
	}
}

void Player::drawCard() {
	if (hand.size() == 5 || playerDeck->isEmpty()) {
		cout << "Can't draw cards from an empty deck, try something else" << endl;
		return;
	}	
	hand.emplace_back(playerDeck->drawCard());	
}

void Player::discardCard(int i) {
	if (hand.empty()) {
		cout << "Can't give away something you don't have, try something else" << endl;
		return;
	}
	const int temp = i;
	hand.erase(temp);
}

void Player::attack(int i, int j) {
	Card *target = board.getTarget(oppNum, j);
	
	// if the minion died, trigger the ritual ability if present
	if (MinionsPlayed[i]->attack(target)) {
		opponent.minionDied();
	}
}

void Player::attack(int i) {
	MinionsPlayed[i]->attack(opponent);	
}

void Player::use(int i, int p, int t) {
	Card *target = Board.getTarget(p, t);
	// execute the function from minion that would use the ability
	MinionsPlayed[i]->use(target);
}

void Player::use(int i) {
	MinionsPlayed[i]->use(&board);
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
	turnStart();
				
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

void Player::takeDmg(int dmg) {
	HP -= dmg;
}

void Player::useMP(int mp) {
	MP -= mp;
}

void Player::minionDied() {
	for (int i = 0; i < MinionsPlayed.size(); i++) {
		if (MinionsPlayed[i].getType() == Ability::MinionDeath) {
			MinionsPlayed[i].use(board, opponent, MinionsPlayed[i]);
		}
	}
	if (ritual.getName() == "Soul Harvest") {
		ritual.activate(this);
	
	}
}

void Player::turnStart() {
	if (ritual.getName() == "Dark Ritual") {
		ritual.activate(this);
	}
}

void Player::turnEnd() {
	// only case is Potion Seller
	for (int i = 0; i < MinionsPlayed.size(); i++) {
		if (MinionsPlayed[i].getType() == Ability::turnEnd()) {
			MinionsPlayed[i].use(board, this, MinionsPlayed[i]);
		}
	} 
}

void Player::minionPlayed(Minion *target){
	// only case is Fire Elemental
	for (int i = 0; i < MinionsPlayed(); i++) {
		if (MinionsPlayed[i].getType() == Ability::minionBirth) {
			MinionsPlayed[i].use(board, opponent, target);
		}
	} 
	if (ritual.getName() == "Aura of Power") {
		ritual.activate(target, this);
	}
	if (ritual.getName() == "Standstill") {
		ritual.activate(target, opponent);
	}
}

