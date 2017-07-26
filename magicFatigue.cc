#include "magicFatigue.h"
#include "ascii_graphics.h"
#include <vector>
#include "Minion.h"

using namespace std;

string name5 = "Magic Fatigue";
int  cost5 = 0;
string description5 = "Enchanted minion's activated ability costs 2 more";


MagicFatigue:: MagicFatigue(int p):Enchantment{name5, cost5,
                description5, p}{}


std::vector<std::string>  MagicFatigue::getAscii(){
    return display_enchantment(name,cost,description);
}

void MagicFatigue::enchant(shared_ptr<Minion> minion) {
	minion->ability->cost = minion->ability->cost + 2;
	minion->enchants.push_back(shared_from_this());
}

void MagicFatigue::print() {
    printCard(getAscii());
}
