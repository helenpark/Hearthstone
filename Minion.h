
#ifndef _MINION_H__
#define _MINION_H__
#include "Card.h"
//#include "Enchantment.h"
//#include "Ability.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

// forward declaration, make sure to #include "Minion.h" and "Player.h" in the .cc file
//class Board;
class Player;
class Enchantment;

class Minion: public Card { //abstract

//	std::vector<typename std::shared_ptr<typename Enchantment>> buffs; // enchantments applied to minion
//	Ability *ability;

public:
    int AP; //attack points
	int DP; //defense points
	// use minion to attack, return true if minion dies after attack, false if minion lives after attack
	bool attack(Minion *minion);
	// minion attacks the opponent, grab how much the minion can hit for
	bool attack(Player *player);
	
	// use minions ability (feed in all possible parameters to make life easy)
	// virtual void use(Board *board, Player *player, Minion *minion) = 0;
	// adds an enchantment on to the minion
	// TODO: decide whether to implement in minion.cc (call enchant class) or each individual minion
	//virtual void addBuff(Enchantment *enchant) = 0;
	// gets the ability type
	// TODO: implement ability: decide whether to implement in minion.cc (call enchant class) or each individual minion
	//virtual Ability::AbilityType getType();
	// function extended from abstract parent class: Target. Describes how minion takes damage
	
	int getHit(int ap);

	// use the minions
	
	Minion(string name, int cost,
      string description, int p, int AP, int DP, int ac);
	virtual ~Minion();

};
#endif
