#include <vector>
#include <string>

class Minion: public Card { //abstract

	int AP; //attack points
	int DP; //defense points
	vector<Enchantment*> buffs; // enchantments applied to minion
	Ability *ability;

public:
	// use minion to attack, return true if minion dies after attack, false if minion lives after attack
	bool attack(Target *target); 
	
	virtual ~Minion();

};
