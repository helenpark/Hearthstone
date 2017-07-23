#ifndef _ABILITY_
#define _ABILITY_
#include <vector>
#include <string>
#include <memory>

class Board;
class Player;

class Ability  { 
	// for the spells that need a deck and Graveyard, make sure to include them, it should be able to include without having compiler errors
	
	std::string description; //attack points
	int cost; //defense points
public:
	virtual ~Ability();
	// type of trigger
	enum AbilityType { startTurn, endTurn, minionBirth, minionDeath, onPlay}; 


};

#endif
