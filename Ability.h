#include <vector>
#include <string>

class Ability { 

	string description; //attack points
	int cost; //defense points
	// type of trigger
	enum SubscriptionType { startTurn, endTurn, minionBirth, minionDeath, onPlay}; 

public:
	// activate ability, on optional target
	bool Activate(Target *target); 
	
	virtual ~Ability();

};
