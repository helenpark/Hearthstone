
#include "Card.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
class Player;

Card::Card(std::string name, int cost, std::string type,
      std::string description, int p): name{name},
      cost{cost}, type{type}, description{description}, owner{p}{

      }
Card::~Card(){
   // delete Owner;
}

string Card::getName(){
    return name;
}

string Card::getDescription() {
    return description;
}
string Card::getType(){
    return type;
}
int Card::getCost(){
    return cost;
}

ostream &operator<<(ostream &out, const Card &b){
    out << "This card is: " << b.name << endl;
    out << "Type: " << b.type<<endl;
    out << "Description: " << b.description << endl;
    out << "Cost: " << b.cost<< endl;
    out << endl;
    return out;
}
