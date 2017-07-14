#include <vector>
#include <string>

class Grave {
	
	vector<Card*> graveyard;

public:
	
	// revive top card from the Grave, return card in it's original state
    Card* resurect();

    // return top Minion from Grave
    &Minion topMinion();

    Grave();
    ~Grave();
    
};

std::ostream &operator<<(std::ostream &out, const Grave &g);