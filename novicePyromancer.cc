#include <vector>
#include "ascii_graphics.h"
#include "novicePyromancer.h"
using namespace std;

string name17 = "Novice Pyromancer";
int  cost17 = 1;
string description17 = "Deal 1 damage to target minion";
int AP17 = 0;
int DP17 = 1;
int activationCost17 = 1;

NovicePyromancer:: NovicePyromancer(int p):Minion{name17, cost17,
                description17, p, AP17,DP17, activationCost17}{}

std::vector<std::string>  NovicePyromancer::getAscii(){
    return display_minion_activated_ability(name,cost,AP,DP,ac,description);
}

void NovicePyromancer::print() {
    printCard(getAscii());
}

