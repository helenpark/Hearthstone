#include <vector>
#include "ascii_graphics.h"
#include "potionSeller.h"
using namespace std;

string name16 = "Potion Seller";
int  cost16 = 2;
string description16 = "At the end of your turn, all your minions gain +0/+1.";
int AP16 = 1;
int DP16 = 3;


PotionSeller:: PotionSeller(int p):Minion{name16, cost16,
                description16, p, AP16,DP16,0}{}


std::vector<std::string>  PotionSeller::getAscii(){
    return display_minion_triggered_ability(name,cost,AP,DP,description);
}

void PotionSeller::print() {
    printCard(getAscii());
}
