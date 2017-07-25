#include "recharge.h"
#include <iostream>

using namespace std;

string name9 = "Recharge";
int  cost9 = 1;
string description9 = "Your ritual gains 3 charges";


Recharge:: Recharge(int p):Spell{name9, cost9,

                description9, p}{}
