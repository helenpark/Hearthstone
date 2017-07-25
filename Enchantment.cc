#include "Enchantment.h"

using namespace std;


Enchantment::Enchantment(string name, int cost, string description,
                         int p):Card{name,cost,"Enchantment",description,p}{}


Enchantment::~Enchantment(){
   // delete minion;
}
