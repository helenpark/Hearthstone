#include "Board.h"
#include <memory>

#include "airElemental.h"
#include "earthElemental.h"
#include "fireElemental.h"
#include "potionSeller.h"
#include "novicePyromancer.h"
#include "apprenticeSummoner.h"
#include "masterSummoner.h"

Board::Board(int owner):owner{owner} {}

shared_ptr<Card> Board::resurrect(){

    if (!grave.empty()){
        string name = grave.back();
        grave.pop_back();
        cout << "you resurrected one minion: \n";
        shared_ptr <Card> newMinion = nullptr;
        if(name=="Air Elemental")
           newMinion = make_shared<AirElemental>(owner);

        else if(name=="Earth Elemental")
            newMinion = make_shared<EarthElemental> (owner);

        else if(name=="Fire Elemental")
            newMinion = make_shared<FireElemental> (owner);

        else if(name=="Potion Seller")
            newMinion = make_shared<PotionSeller> (owner);

        else if(name=="Novice Pyromancer")
            newMinion = make_shared<NovicePyromancer> (owner);

        else if(name=="Apprentice Summoner")
            newMinion = make_shared<ApprenticeSummoner> (owner);

        else if(name=="Master Summoner")
            newMinion = make_shared<MasterSummoner> (owner);

       // cout << *newMinion;
        newMinion->print();
        int temp = grave.size();
        cout << "The size of the graveyard is: " << temp << endl<<endl;
        return newMinion;

    }
    else {
        string msg = "No minion to be resurrect.";
        throw msg;
    }
}


void Board::placeMinion(shared_ptr<Card> m) {
    int i = minionSlots.size();
    if (i<5) {
        minionSlots.emplace_back(static_pointer_cast<Minion>(m));
        int temp = minionSlots.size();
     //   cout << *minionSlots[temp-1];
        minionSlots[temp-1]->print();
        cout << "The size of the minionSlots is: " << temp <<endl;
    }
    else if(i==5){
        cout << "You already have 5 minions on board!" << endl;
    }
}

//place a ritual on the board
void Board::placeRitual(shared_ptr<Card> r){
    cout << "was here, place ritual" << endl;
    myRitual.reset();
    myRitual = static_pointer_cast<Ritual>(r);
    cout << "Assigned" << endl;
    cout <<"My current ritual is: " << endl;
    //cout <<"My current ritual is: " << *myRitual;
    myRitual->print();
}

//place a died minion in the grave
void Board::placeGrave(shared_ptr<Minion> m){
    string name = m->getName();

    cout << "placed: " << name << " in the graveyard \n";
    grave.emplace_back(name);
    int temp = grave.size();

    cout << "The size of the graveyard is: " << temp << endl<<endl;
}
