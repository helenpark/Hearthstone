
#include "Deck.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <memory>

#include "banish.h"
#include "unsummon.h"
#include "recharge.h"
#include "disenchant.h"
#include "raiseDead.h"
#include "blizzard.h"
#include "giantStrength.h"
#include "magicFatigue.h"
#include "silence.h"
#include "darkRitual.h"
#include "auraOfPower.h"
#include "standstill.h"
#include "airElemental.h"
#include "earthElemental.h"
#include "fireElemental.h"
#include "potionSeller.h"
#include "novicePyromancer.h"
#include "apprenticeSummoner.h"
#include "masterSummoner.h"

using namespace std;
/*
vector<Card*> Deck::shuffle(vector<Card*> cards) {
	random_shuffle(base.begin(), base.end());
}

*/


bool Deck::isEmpty() {
	return base.empty();
}



 shared_ptr<Card> Deck::draw() {
    if (!isEmpty()) {
        shared_ptr<Card> temp = base.back();
        base.pop_back();
        return temp;
    }
    else {
        string msg = "Your deck is empty!";
        throw (msg);
    }
}

void Deck::initDeck(string filename) {
	ifstream input;
	input.open(filename);
	string name;

	while (getline(input,name)) {
		if (name=="Banish")
            base.emplace_back(make_shared<Banish> (owner));

/*		else if(name=="Unsummon")
            base.emplace_back(make_shared<Unsummon> (owner));

        else if(name=="Recharge")
            base.emplace_back(make_shared<Recharge> (owner));

		else if(name=="Disenchant")
            base.emplace_back(make_shared<Disenchant> (owner));

*/		else if(name=="Raise Dead")
            base.emplace_back(make_shared<RaiseDead> (owner));

		else if(name=="Blizzard")
            base.emplace_back(make_shared<Blizzard> (owner));

/*		else if(name=="Giant Strength")
            base.emplace_back(make_shared<GiantStrength> (owner));

		else if(name=="Magic Fatigue")
            base.emplace_back(make_shared<MagicFatigue> (owner));

		else if(name=="Silence")
            base.emplace_back(make_shared<Silence> (owner));

*/		 else if(name=="Dark Ritual")
             base.emplace_back(make_shared<DarkRitual> (owner));

 		else if(name=="Aura of Power")
             base.emplace_back(make_shared<AuraOfPower> (owner));

 		else if(name=="Standstill")
             base.emplace_back(make_shared<Standstill> (owner));

		else if(name=="Air Elemental")
            base.emplace_back(make_shared<AirElemental> (owner));

		else if(name=="Earth Elemental")
            base.emplace_back(make_shared<EarthElemental> (owner));

		else if(name=="Fire Elemental")
            base.emplace_back(make_shared<FireElemental> (owner));

		else if(name=="Potion Seller")
            base.emplace_back(make_shared<PotionSeller> (owner));

		else if(name=="Novice Pyromancer")
            base.emplace_back(make_shared<NovicePyromancer> (owner));

		else if(name=="Apprentice Summoner")
            base.emplace_back(make_shared<ApprenticeSummoner> (owner));

		else if(name=="Master Summoner")
            base.emplace_back(make_shared<MasterSummoner> (owner)); 
	}
}


Deck::Deck() {}

Deck::Deck(int owner):owner{owner}{
    initDeck("default.deck");
}
