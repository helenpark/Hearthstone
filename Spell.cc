#include "Spell.h"
#include <vector>
#include "ascii_graphics.h"
using namespace std;

Spell::Spell(string name, int cost,
      string description, int p):Card{name,cost,"Spell",description,p}{}

void Spell::print(){
    vector<string> display = display_spell(name, cost,description);
    printCard(display);
}

