#ifndef _MINION_
#define _MINION_
#include "Card.h"
#include "Ability.h"
#include "Enchantment.h"
#include <vector>
#include <string>
#include <memory>

// forward declaration, make sure to #include "Minion.h" and "Player.h" in the .cc file
class Board;
class Player;

class Minion: public Card { //abstract
	
	int AP; //attack points
	int DP; //defense points
	std::vector< std::shared_ptr<Enchantment> > buffs; // enchantments applied to minion
	Ability *ability;

public:
	// use minion to attack, return true if minion dies after attack, false if minion lives after attack
	virtual bool attack(std::shared_ptr<Minion>minion) = 0;
	// minion attacks the opponent, grab how much the minion can hit for
	virtual int attack(Player *player) = 0;
	// use minions ability (feed in all possible parameters to make life easy)
	virtual void use(Board *board, Player *player, std::shared_ptr<Minion> minion) = 0;
	// adds an enchantment on to the minion
	virtual void addBuff(std::shared_ptr<Enchantment> enchant) = 0;
	// gets the ability type
	virtual Ability::AbilityType getAbilityType();
	// use the minions	
	virtual ~Minion();

};
#endif
