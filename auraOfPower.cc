#include "auraOfPower.h"
using namespace std;

string name1 = "Aura of Power";
int  cost1 = 1;
string description1 = "Whenever a minion enter a play under your control, it gains +1/+1";
int activationCost1 = 1;
int charges1 = 4;

AuraOfPower:: AuraOfPower(int p):Ritual{name1, cost1,
                description1, p, activationCost1, charges1}{


 //   ability = new Ability();
//    ability.subscriptionType::minionBirth; // ????


}

/*
AuraOfPower::void useAbility(Target *t=nullptr){
    if(canActivate()){
         // need to see implementation of minion
        charges -= activationCost;
    }
}
*/
