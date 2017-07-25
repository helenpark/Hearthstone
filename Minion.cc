#include "Minion.h"
using namespace std;
#include "Player.h"

Minion::Minion(string name, int cost, string description, int p, int AP, int DP, int ac):
	Card{name,cost,"Minion",description,p}, AP{AP}, DP{DP},ac{ac}, original(true) {

}

vector<shared_ptr<Minion>> Minion::attack(shared_ptr<Minion> minion) {
   int targetHP = minion->getHit(AP);
   int myHP = getHit(minion->AP);
   vector<shared_ptr<Minion>> died;

   if (myHP <= 0) {
	died.push_back(shared_from_this());
   } else {
   	died.push_back(nullptr);
   }

   if (targetHP < 0) {
	died.push_back(minion);
   } else {
   	died.push_back(nullptr);
   }

   return died;
}

int Minion::attack(Player *player) {
   int finalHp = player->getHit(AP);
   return finalHp;
}

void Minion::die() {

}

int Minion::getHit(int ap) {
   //cout << "I am " << name << ". Orignally I have: "<< DP << " lives.\n";
   DP = DP - ap;
   //cout << "Now I have " << DP <<endl;
   return DP;
}

Minion::~Minion(){}
