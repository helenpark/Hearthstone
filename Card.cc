
#include "Card.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;
class Player;

Card::Card(std::string name, int cost, std::string type,
      std::string description, int p): name{name},
      cost{cost}, type{type}, description{description}, owner{p}{ }


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

void Card::printCard(vector<string> display){
    int len = display.size();
    for (int i=0; i<len; ++i) {
        string line = display[i];
        cout << line << endl;
    }
}
void Card::print(){}


ostream &operator<<(ostream &out, const Card &b){
    out << "This card is: " << b.name << endl;
    out << "Type: " << b.type<<endl;
    out << "Description: " << b.description << endl;
    out << "Cost: " << b.cost<< endl;
    out << endl;
    return out;
}
