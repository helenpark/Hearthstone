
#include "disenchant.h"
using namespace std;

string name10 = "Disenchant";
int  cost10 = 1;
string description10 = "Destroy the top enchantment on target minion";


Disenchant:: Disenchant(int p):Spell{name10, cost10,
                description10, p}{}
void Disenchant::cast(shared_ptr<Board> myBoard,int p,string t, shared_ptr<Board> oppBoard){

}
