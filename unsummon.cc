#include "unsummon.h"
using namespace std;

string name8 = "Unsummon";
int  cost8 = 1;
string description8 = "Put target inion on the bottom of its owner's deck";


Unsummon:: Unsummon(int p):Spell{name8, cost8,
                description8, p}{}

void Unsummon::cast(shared_ptr<Board> myBoard,int p,string t, shared_ptr<Board> oppBoard){

}
