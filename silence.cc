#include <iostream>
#include "silence.h"
#include <vector>
#include "ascii_graphics.h"
using namespace std;

string name6 = "Silence";
int  cost6 = 1;
string description6 = "Enchanted minion cannot use abilities";


Silence:: Silence(int p):Enchantment{name6, cost6,
                description6, p}{}


std::vector<std::string>  Silence::getAscii(){
    return display_enchantment(name,cost,description);
}

void Silence::print() {
    printCard(getAscii());
}
