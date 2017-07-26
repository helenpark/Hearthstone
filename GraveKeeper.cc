#include "GraveKeeper.h"
#include "ascii_graphics.h"
using namespace std;

GraveKeeper::GraveKeeper(int p): Minion{"Grave Keeper", 2, "When this minion dies, the owner of this minion chooses one card from the opponent's hand and sends it to the Grave", p, 3, 2, 0} {}

std::vector<std::string> GraveKeeper::getAscii(){
	return display_minion_triggered_ability(name, cost, AP, DP, description);
}

void GraveKeeper::print() {
	printCard(getAscii());
}
