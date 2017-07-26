#include "giantStrength.h"
#include <vector>
#include "ascii_graphics.h"
#include "Minion.h"
using namespace std;

string name4 = "Giant Strength";
int  cost4 = 1;

GiantStrength:: GiantStrength(int p):Enchantment{name4, cost4,
                "", p}{}


std::vector<std::string>  GiantStrength::getAscii(){
    return display_enchantment_attack_defence(name, cost,"","+2","+2");
}

void GiantStrength::enchant(shared_ptr<Minion> minion) {
	minion->AP = minion->AP + 2;
	minion->DP = minion->DP + 2;
	minion->enchants.push_back(shared_from_this());
}

void GiantStrength::print() {
    printCard(getAscii());
}

