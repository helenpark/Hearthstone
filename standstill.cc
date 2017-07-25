
#include "Board.h"
#include "standstill.h"
using namespace std;

string name3 = "Standstill";
int  cost3 = 3;
string description3 = "Whenever a minion enters play, destroy it";
int activationCost3 = 2;
int charges3 = 4;


Standstill:: Standstill(int p):Ritual{name3, cost3,
                description3, p, activationCost3, charges3}{}


void Standstill::activate(Player *player, Board *board, shared_ptr<Minion> minion){

}
/*
void Standstill::activate(Player *player, Board *board, shared_ptr<Minion> minion){
    if(canActivate()){
        // this one is tricky since it probably need access to the board
	// and the position of the minion that is played on the board
	// so that it can be removed
	// assuming t is a pointer to minion and board is given, then
	// board->destroy(t);
	// or
	// board->destroy(opponentPlayerNumber, positionOfMinion);
        charges -= activationCost;
	int len = board->minionSlots.size();
	for (int i = 0; i < len; i++) {
		if (minion == board->minionSlots[i]) {
			board->placeGrave(minionSlots[i]);
			board->minionSlots.erase(minionSlots.begin() + i - 1);
		}
	}
    }
}
*/
