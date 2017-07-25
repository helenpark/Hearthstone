#include "darkRitual.h"
#include "Minion.h"
#include "Board.h"
#include "Player.h"
#include <memory>
#include <iostream>
#include <string>
using namespace std;

string name2 = "Dark Ritual";
int  cost2 = 0;
string description2 = "At the start of your turn, gain 1 magic";
int activationCost2 = 1;
int charges2 = 5;


DarkRitual:: DarkRitual(int p):Ritual{name2, cost2,
                description2, p, activationCost2, charges2}{}



void DarkRitual::activate(Player *player, Board *board, shared_ptr<Minion> minion){
    if(canActivate()){
    }
}

