#ifndef _GRAVE_
#define _GRAVE_
#include "Card.h"
#include <vector>
#include <string>
#include <memory>

class Grave {
	
	std::vector<std::shared_ptr<Card>> graveyard;

public:
	
    // revive top card from the Grave, return card in it's original state
    Card* resurect();

    // when the minion dies, place it on the top of the graveyard
    void died(Card *minion);

    Grave();
    ~Grave();
    
};

std::ostream &operator<<(std::ostream &out, const Grave &g);

#endif
