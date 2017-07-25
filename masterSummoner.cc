

#include <iostream>
#include "masterSummoner.h"
#include <vector>
#include "ascii_graphics.h"
using namespace std;

string name19 = "Master Summoner";
int  cost19 = 3;
string description19 = "Summon up to three 1/1 air elementals";
int AP19 = 2;
int DP19 = 3;
int activationCost19 = 2;

MasterSummoner:: MasterSummoner(int p):Minion{name19, cost19,
                description19, p, AP19,DP19, activationCost19}{}
void MasterSummoner::print() {
    vector<string> display =  display_minion_activated_ability(name,cost,AP,DP,ac,description);
    printCard(display);
}
