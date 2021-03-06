#include "apprenticeSummoner.h"
#include <vector>
#include "ascii_graphics.h"
using namespace std;

string name18 = "Apprentice Summoner";
int  cost18 = 1;
string description18 = "Summon a 1/1 air elemental";
int AP18 = 1;
int DP18 = 1;
int activationCost18 = 1;

ApprenticeSummoner:: ApprenticeSummoner(int p):Minion{name18, cost18,
                description18, p, AP18,DP18, activationCost18}{}

std::vector<std::string>  ApprenticeSummoner::getAscii(){
    return display_minion_activated_ability(name,cost,AP,DP,ac,description);
}

void ApprenticeSummoner::print() {

    printCard(getAscii());
}
