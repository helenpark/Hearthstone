
#include <iostream>
#include "standstill.h"
using namespace std;

string name3 = "Standstill";
int  cost3 = 3;
string description3 = "Whenever a minion enters play, destroy it";
int activationCost3 = 2;
int charges3 = 4;


Standstill:: Standstill(int p):Ritual{name3, cost3,
                description3, p, activationCost3, charges3}{}

/*
Standstill::void useAbility(Target *t=nullptr){
    if(canActivate()){
         // need to see implementation of minion
        charges -= activationCost;
    }
}
*/
