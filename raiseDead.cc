#include "Board.h"
#include "raiseDead.h"
using namespace std;

string name11 = "Raise Dead";
int  cost11 = 1;
string description11 = "Resurrect the top minion in your graveyard";


RaiseDead:: RaiseDead(int p):Spell{name11, cost11,
                description11, p}{}

void RaiseDead::cast(shared_ptr<Board> myBoard,int p,string t, shared_ptr<Board> oppBoard){
    myBoard->resurrect();
}

