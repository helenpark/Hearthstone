#include "Minion.h"
using namespace std;
#include "Player.h"

Minion::Minion(string name, int cost, string description, int p, int AP, int DP, int ac):
	Card{name,cost,"Minion",description,p} {}

bool Minion::attack(Minion *minion) {
   int targetHP = minion->getHit(AP);
   int myHP = getHit(minion->AP);
   if (myHP <= 0) {
	// TODO: put card in graveyard, and take off board
   }
   if (targetHP > 0) return false;
	// TODO: kill card
	return true;
}

bool Minion::attack(Player *player) {
   int finalHp = player->getHit(AP);
   if (finalHp > 0) return false;
	// TODO: Terminate game -> player possesing this card wins!
	return true;
}

int Minion::getHit(int ap) {
   DP = DP - ap;
   return DP;
}

Minion::~Minion(){}
