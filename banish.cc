#include "banish.h"
using namespace std;
string name7 = "Banish";
int  cost7 = 2;
string description7 = "Destroy target minion or ritual";


Banish:: Banish(int p):Spell{name7, cost7,
                description7, p}{}
void Banish::cast(shared_ptr<Board> myBoard,shared_ptr<Card> target, shared_ptr<Board> oppBoard){

}
