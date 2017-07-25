#include "magicFatigue.h"
#include "ascii_graphics.h"
#include <vector>

using namespace std;

string name5 = "Magic Fatigue";
int  cost5 = 0;
string description5 = "Enchanted minion's activated ability costs 2 more";


MagicFatigue:: MagicFatigue(int p):Enchantment{name5, cost5,
                description5, p}{}

void MagicFatigue::print() {
    vector<string> display = display_enchantment(name,cost,description);
    printCard(display);
}
