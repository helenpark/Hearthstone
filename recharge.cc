#include "Board.h"
#include "Card.h"
#include "recharge.h"
using namespace std;

string name9 = "Recharge";
int  cost9 = 1;
string description9 = "Your ritual gains 3 charges";


Recharge:: Recharge(int p):Spell{name9, cost9,
                description9, p}{}

void Recharge::cast(shared_ptr<Board> myBoard,shared_ptr<Card> target, shared_ptr<Board> oppBoard){
    if (!myBoard->myRitual){
        string msg = "You do not have a Ritual to recharge!";
        throw msg;
    }
    else {
        myBoard->gainCharge(3);
    }
}
