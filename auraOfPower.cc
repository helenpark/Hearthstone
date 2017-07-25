#include "auraOfPower.h"
#include "Board.h"
#include "Player.h"
#include "Minion.h"
#include <vector>
#include <memory>
#include <iostream>
#include <string>
using namespace std;

string name1 = "Aura of Power";
int  cost1 = 1;
string description1 = "Whenever a minion enter a play under your control, it gains +1/+1";
int activationCost1 = 1;
int charges1 = 4;

AuraOfPower:: AuraOfPower(int p):Ritual{name1, cost1,
                description1, p, activationCost1, charges1}{}


void  AuraOfPower::activate(Player *player, shared_ptr<Board> board, shared_ptr<Minion> minion){
    if(canActivate()){
        // change the MP and AP values by +1
	// probably need to access a method from minion to gain MP/AP
	// t should be a pointer to minion
	// something like this most likely
	// t->gainMP(1);
	// t->gainHP(1);
	charges -= activationCost;
	minion->DP += 1;
	minion->AP += 1;
    }
}

