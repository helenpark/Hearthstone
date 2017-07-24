#include "Ability.h"
#include "airElemental.h"
#include "Minion.h"
#include "Board.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Ability::Ability(string name, int cost): name(name), cost(cost) {
	if (name == "Fire Elemental") {
		description = "Whenever an opponent's minion enters play, deal 1 damage to it.";
	} 
	else if (name == "Potion Seller") {
		description = "At the end of your turn, all your minions gain +0/+1";
	}
	else if (name == "Novice Pyromancer") {
		description = "Deal 1 damage to target minion";
	}
	else if (name == "Apprentice Summoner") {
		description = "Summon a 1/1 air elemental";
	}
	else if (name == "Master Summoner") {
		description = "Summon up to three 1/1 air elementals";
	}
}

void Ability::fireElemental(shared_ptr<Minion> minion) {
	minion->DP -= 1;	
}

void Ability::potionSeller(Board *board) {
	int len = board->minionSlots.size();
	for (int i = 0; i < len; i++) {
		board->minionSlots[i]->DP += 1;	
	}
} 

void Ability::novicePyromancer(shared_ptr<Minion> minion) {
	minion->DP -= 1;
}

void Ability::masterSummoner(Board *board) {
	int i;
	int summon = 5 - board->minionSlots.size();
	if (summon > 3) {
		for (i = 0; i < 3; i++) {
			board->minionSlots.emplace_back(make_shared<AirElemental>(1));
		}
	} else {
		for (i = 0; i < summon; i++) {
			board->minionSlots.emplace_back(make_shared<AirElemental>(1));
		}
	}
}

void Ability::apprenticeSummoner(Board *board) {
	board->minionSlots.emplace_back(make_shared<AirElemental>(1));
}