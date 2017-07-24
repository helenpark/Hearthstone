#include "Minion.h"
using namespace std;

Minion::Minion(string name, int cost, string description, int p, int AP, int DP, int ac):
	Card{name,cost,"Minion",description,p} {}

bool attack(Minion *minion) {
   targetHP = target.getHit(AP);
   myHP = getHit(target.AP);
   if (myHP <= 0) {
	// TODO: put card in graveyard, and take off board
   }
   if (targetHP > 0) return false;
   else {
	// TODO: kill card
	return true;
   }	
}

bool attack(Player *player) {
   finalHp = target.getHit(AP);
   if (finalHp > 0) return false;
   else {
	// TODO: Terminate game -> player possesing this card wins!
	return true;
   }
}

int getHit(int ap) {
   DP = DP - ap;
   return DP;

Minion::~Minion(){

}
