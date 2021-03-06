
#include "ascii_graphics.h"
#include <vector>
#include "fireElemental.h"
using namespace std;

string name15 = "Fire Elemental";
int  cost15 = 0;
string description15 = "Whenever an opponent's minion enters play, deal 1 damage to it.";
int AP15 = 2;
int DP15 = 2;

FireElemental:: FireElemental(int p):Minion{name15, cost15,
                description15, p, AP15,DP15,0}{}


std::vector<std::string>  FireElemental::getAscii(){
    return display_minion_triggered_ability(name,cost,AP,DP,description);
}

void FireElemental::print() {
    printCard(getAscii());
}

