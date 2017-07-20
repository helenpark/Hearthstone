#ifndef _ABILITY_
#define _ABILITY_
#include <vector>
#include <string>
#include <memory>

class Ability  { 
	// for the spells that need a deck and Graveyard, make sure to include them, it should be able to include without having compiler errors
	
	std::string description; //attack points
	int cost; //defense points
	// type of trigger
	enum SubscriptionType { startTurn, endTurn, minionBirth, minionDeath, onPlay}; 

public:
	// activate ability, on optional target
	bool Activate(); 
	
	virtual ~Ability();

};

#endif
