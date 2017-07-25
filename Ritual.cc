#include "Ritual.h"
#include <vector>
#include "ascii_graphics.h"
using namespace std;
Ritual::Ritual(string name, int cost,
      string description, int p,
      int activationCost, int charges):Card{name,cost,"Ritual",description,p},
       activationCost{activationCost}, charges{charges}{}

bool Ritual::canActivate(){
    return (charges - activationCost) > 0;
}

std::vector<std::string> Ritual::getAscii() {
    return display_ritual(name,cost,activationCost,description,charges);
}


void Ritual::print() {
     printCard(getAscii());
}
