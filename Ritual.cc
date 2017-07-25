#include "Ritual.h"
using namespace std;
Ritual::Ritual(string name, int cost,
      string description, int p,
      int activationCost, int charges):Card{name,cost,"Ritual",description,p},
       activationCost{activationCost}, charges{charges}{}

bool Ritual::canActivate(){
    return (charges - activationCost) > 0;
}

Ritual::~Ritual(){
   // delete ability;
}
