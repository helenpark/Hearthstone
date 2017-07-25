#include "giantStrength.h"
#include <iostream>
#include <vector>
#include "ascii_graphics.h"
using namespace std;

string name4 = "Giant Strength";
int  cost4 = 1;

GiantStrength:: GiantStrength(int p):Enchantment{name4, cost4,
                "", p}{}

void GiantStrength::print(){
    vector<string> display = display_enchantment_attack_defence(name, cost,"","+2","+2");
    printCard(display);
}
