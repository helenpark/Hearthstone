#include "Board.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Card *Board::getTarget(int player, int target) {
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

void Board::placeMinion(Minion *minion, int player) {
	if (player == 1) {
		if (player1Minions.size() == 5) {
			cout << "Can't play anymore minions" << endl;
			return;
		} else {
			player1Minions.emplace_back(minion);
		}
	} else {
		if (player2Minions.size() == 5) {
			cout << "Can't play anymore minions" << endl;
			return;
		} else {
			player2Minions.emplace_back(minion);
		}
	}
}

void Board::placeRitual(Ritual *ritual, int player) {
	if (player == 1) {
		player1Ritual = ritual;
	} else {
		player2Ritual = ritual;
	}
}

void Board::playSpell(Spell *spell) {
	spell.cast();
}

void Board::playSpell(Spell *spell, Card *target) {
	spell.cast(target);
}

void Board::playEnchantment(Enchantment *enchant, Minion *minion) {
	minion.addBuff(enchant);
}	

std::ostream &operator<<(std::ostream &out, const Board &b){}
