#include "Spell.h"
#include <vector>
#include "ascii_graphics.h"
using namespace std;

Spell::Spell(string name, int cost,
      string description, int p):Card{name,cost,"Spell",description,p}{}

std::vector<std::string> Spell::getAscii() {
    return display_spell(name, cost,description);
}

void Spell::print(){
    printCard(getAscii());
}



