#include "magicFatigue.h"
using namespace std;

string name5 = "Magic Fatigue";
int  cost5 = 0;
string description5 = "Enchanted minion's activated ability costs 2 more";


MagicFatigue:: MagicFatigue(int p):Enchantment{name5, cost5,
                description5, p}{}
