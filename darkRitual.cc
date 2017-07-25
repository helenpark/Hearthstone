
#include "darkRitual.h"
using namespace std;

string name2 = "Dark Ritual";
int  cost2 = 0;
string description2 = "At the start of your turn, gain 1 magic";
int activationCost2 = 1;
int charges2 = 5;


DarkRitual:: DarkRitual(int p):Ritual{name2, cost2,
                description2, p, activationCost2, charges2}{}



DarkRitual::void useAbility(Target *t=nullptr){
    if(canActivate()){
	// t should be a pointer to a player, so that it gains MP
        t->gainMP();
        charges -= activationCost;
    }
}

