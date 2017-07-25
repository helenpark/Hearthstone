#include "Ability.h"
#include "airElemental.h"
#include "Minion.h"
#include "Board.h"
#include "Player.h"
#include <sstream>
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
	cout << "Fire Elemental ability used on " << minion->getName() << endl;
	minion->DP -= 1;	
}

void Ability::potionSeller(shared_ptr<Board> board) {
	cout << "Potion Seller ability used" << endl;
	int len = board->minionSlots.size();
	for (int i = 0; i < len; i++) {
		board->minionSlots[i]->DP += 1;	
	}
} 

void Ability::novicePyromancer(shared_ptr<Minion> minion) {
	cout << "Novice Pyromancer ability used on " << minion->getName() <<endl;
	minion->DP -= 1;
}

void Ability::masterSummoner(shared_ptr<Board> board) {
	cout << "Master Summoner ability used" << endl;
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

void Ability::apprenticeSummoner(shared_ptr<Board> board) {
	cout << "Aprrentice Summoner ability used" << endl;
	board->minionSlots.emplace_back(make_shared<AirElemental>(1));
}

void Ability::shieldPierce(Player *player, int AP) {
	player->HP -= AP;
}

void Ability::graveKeeper(Player *player, shared_ptr<Board> board){
	cout << "choose a card to pick from the opponents hand to discard" << endl;
	string num;
	stringstream ss;
	cin >> num;
	ss << num;
	int n;
	int size = player->myHand.size();
	while (!ss >> n && n >= 1 && n <= size) {
		cout << "need to pick a card thats actually in there hand" << endl;
		cin >> num;
		ss << num;
	}
	// if its a minion place it into the grave yard and discard
	if (player->myHand[n]->type == "Minion") {
		board->placeGrave(static_pointer_cast<Minion>(player->myHand[n]));
		player->discard(n);
	} else {
		player->discard(n);
	}
}
