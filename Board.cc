#include "Board.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

shared_ptr<Card> Board::getTarget(int player, int target) {
	// if it affects the ritual card
	if (target == 'r') {
		if (player == 1) {
			return player1Ritual;
		} else {
			return player2Ritual;
		}
	}
	if (target >= 1 && target <= 5) {
		if (player == 1) {
			return player1Minions[target];
		} else {
			return player2Minions[target];
		}
	}
}

void Board::inspect(int i, int player) {}

void Board::placeMinion(shared_ptr<Minion> minionPlay, int player) {
	if (player == 1) {
		if (player1Minions.size() == 5) {
			cout << "Can't play anymore minions" << endl;
			return;
		} else {
			player1Minions.emplace_back(minionplay);
		}
	} else { if (player2Minions.size() == 5) {
			cout << "Can't play anymore minions" << endl;
			return;
		} else {
			player2Minions.emplace_back(minionPlay);
		}
	}
}

void Board::placeRitual(shared_ptr<Ritual> ritualPlay, int player) {
	if (player == 1) {
		player1Ritual = ritualPlay;
	} else {
		player2Ritual = ritualPlay;
	}
}

void Board::playSpell(shared_ptr<Spell> spellPlay) {
	spellPlay->cast(this);
}

void Board::playSpell(shared_ptr<Spell> spellPlay, shared_ptr<Minion> target) {
	spellPlay->cast(this, target);
}

void Board::playSpell(shared_ptr<Spell> spellPlay, shared_ptr<Ritual> target) {
	spellPlay->cast(this, target);
}

void Board::playEnchantment(shared_ptr<Enchantment> enchant, shared_ptr<Minion> minion) {
	minion->addBuff(enchant);
}	

void Board::setDeck(Deck *deck, int player) {
	if (player == 1) {
		player1Deck = deck;
	} else {
		player2Deck = deck;
	}
}

void Board::setGrave(Grave *grave, int player) {
	if (player == 1) {
		player1Grave = grave;
	} else {
		player2Grave = grave;
	}
}

std::ostream &operator<<(std::ostream &out, const Board &b){}
