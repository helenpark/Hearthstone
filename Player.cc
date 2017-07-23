#include "Player.h"
#include "Card.h"
#include "Ability.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

Player::Player(int num, int oppNum,  string name, Board &board): number(num), oppNumber(oppNum), name(name), board(board), MP(3), HP(20)
{
	// game starts, add 4 cards to the player's hand
	for (int i = 0; i < 4; i++) {
		hand.emplace_back(playerDeck->drawCard());
	}					  
}

void Player::placeCard(int i) {
	// if its a minion
	if (hand[i]->getType() == Card::minion) {
		board.placeMinion(static_pointer_cast<Minion>(hand[i]), number);
		MinionsPlayed.emplace_back(static_pointer_cast<Minion>(hand[i]));
		minionPlayed(static_pointer_cast<Minion>(hand[i]));
		hand.erase(hand.begin() + (i - 1));
	}
	// if its a ritual type
	if (hand[i]->getType() == Card::ritual) {
		board.placeRitual(static_pointer_cast<Ritual>(hand[i]), number);
		ritualPlayed = static_pointer_cast<Ritual>(hand[i]);
		hand.erase(hand.begin() + (i - 1));
	}
	// if its a Spell
	if (hand[i]->getType() == Card::spell) {
		board.playSpell(static_pointer_cast<Spell>(hand[i]));
		hand.erase(hand.begin() + (i - 1));
	}
}

void Player::placeCard(int i, int p, int t) {
	shared_ptr<Card> target = board.getTarget(p, t);

	// if its a spell
	if (hand[i]->getType() == Card::spell) {
		board.playSpell(static_pointer_cast<Spell>(hand[i]), target);
		hand.erase(hand.begin() + (i - 1));
	}
	// if its an enchantment card
	if (hand[i]->getType() == Card::enchantment) {
		
		board.playEnchantment(static_pointer_cast<Enchantment>(hand[i]), target);
		hand.erase(hand.begin() + (i - 1));
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
	hand.erase(hand.begin() + (i - 1));
}

void Player::attack(int i, int j) {
	// for invalid entries
	shared_ptr<Card> temp = board.getTarget(oppNumber, j);
	// to check whether its actually attacking a minion or not
	if (temp->getType() != Card::minion) {
			cout << "Minions can only attack minions" << endl;
			return;
	}
	shared_ptr<Minion> target = static_pointer_cast<Minion>(temp);
	// if the minion died, trigger the ritual ability if present
	if (MinionsPlayed[i]->attack(target)) {
		opponent->minionDied();
	}
}

void Player::attack(int i) {
	MinionsPlayed[i]->attack(opponent);	
}

void Player::use(int i, int p, int t) {
	shared_ptr<Card> temp = board.getTarget(p, t);
	if (temp->getType() != Card::minion) {
		cout << "You can only use abilites from minions" << endl;
		return;
	}
	shared_ptr<Minion> target = static_pointer_cast<Minion>(temp);
	// execute the function from minion that would use the ability
	MinionsPlayed[i]->use(&board, opponent, target);
}

void Player::use(int i) {
	MinionsPlayed[i]->use(&board, this, static_pointer_cast<Minion>(MinionsPlayed[i]));
}

void Player::inspect(int i) {
	board.inspect(i, number);
}

void Player::displayHand() {};

void Player::initDeck(string filename) {
	playerDeck->initDeck(filename);	
}

void Player::turnStart() {
	MP++;
	if (hand.size() != 5 || !playerDeck->isEmpty()) {
		hand.emplace_back(playerDeck->drawCard());	
	}	
	if (ritualPlayed->getName() == "Dark Ritual") {
		ritualPlayed->activate(this);
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

void Player::takeDmg(int dmg) {
	HP -= dmg;
}

void Player::useMP(int mp) {
	MP -= mp;
}

void Player::minionDied() {
	for (int i = 0; i < MinionsPlayed.size(); i++) {
		if (MinionsPlayed[i]->getAbilityType() == Ability::minionDeath) {
			MinionsPlayed[i]->use(&board, opponent, static_pointer_cast<Minion>(MinionsPlayed[i]));
		}
	}
	if (ritualPlayed->getName() == "Soul Harvest") {
		ritualPlayed->activate(this);
	
	}
}


void Player::turnEnd() {
	// only case is Potion Seller
	for (int i = 0; i < MinionsPlayed.size(); i++) {
		if (MinionsPlayed[i]->getAbilityType() == Ability::endTurn) {
			MinionsPlayed[i]->use(&board, this, static_pointer_cast<Minion>(MinionsPlayed[i]));
		}
	} 
}

void Player::minionPlayed(shared_ptr<Minion> target){
	// only case is Fire Elemental
	for (int i = 0; i < MinionsPlayed.size(); i++) {
		if (MinionsPlayed[i]->getAbilityType() == Ability::minionBirth) {
			MinionsPlayed[i]->use(&board, opponent, target);
		}
	} 
	if (ritualPlayed->getName() == "Aura of Power") {
		ritualPlayed->activate(target);
	}
	if (ritualPlayed->getName() == "Standstill") {
		ritualPlayed->activate(target);
	}
}
