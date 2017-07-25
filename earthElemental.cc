
#include "earthElemental.h"
using namespace std;
#include "ascii_graphics.h"
#include <vector>

string name14 = "Earth Elemental";
int  cost14 = 3;
string description14 = "";
int AP14 = 4;
int DP14 = 4;


EarthElemental:: EarthElemental(int p):Minion{name14, cost14,
                description14, p, AP14,DP14,0}{}

void EarthElemental::print() {
    vector<string> display = display_minion_no_ability(name,cost,AP,DP);
    printCard(display);

}
