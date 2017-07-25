#include "airElemental.h"
#include <iostream>
#include "ascii_graphics.h"
#include <vector>

using namespace std;

string name13 = "Air Elemental";
int  cost13 = 0;
string description13 = "";
int AP13 = 1;
int DP13 = 1;


AirElemental:: AirElemental(int p):Minion{name13, cost13,
                description13, p, AP13,DP13,0}{}

void AirElemental::print() {
    vector<string> display = display_minion_no_ability(name,cost,AP,DP);
    printCard(display);

}
