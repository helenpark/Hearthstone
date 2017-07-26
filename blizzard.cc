

#include "blizzard.h"
#include "Board.h"
using namespace std;

string name12 = "Blizzard";
int  cost12 = 3;
string description12 = "Deal 2 damage to all minions";


Blizzard:: Blizzard(int p):Spell{name12, cost12,
                description12, p}{}

void Blizzard::cast(shared_ptr<Board> myBoard,int p,string t, shared_ptr<Board> oppBoard){
    int n = myBoard->minionSlots.size();
    for (int i=0; i<n; i++) {
        myBoard->minionSlots[i]->getHit(2);
    }

    n = oppBoard->minionSlots.size();
    for (int i=0; i<n; i++) {
        oppBoard->minionSlots[i]->getHit(2);
    }
    cout << "called blizzard" << endl ;
}
