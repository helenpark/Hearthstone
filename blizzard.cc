

#include "blizzard.h"
using namespace std;

string name12 = "Blizzard";
int  cost12 = 3;
string description12 = "Deal 2 damage to all minions";


Blizzard:: Blizzard(int p):Spell{name12, cost12,
                description12, p}{}
