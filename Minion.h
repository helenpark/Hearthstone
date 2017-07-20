#ifndef _MINION_
#define _MINION_
#include "Card.h"
#include "Enchantment.h"
#include "Ability.h"
#include <vector>
#include <string>
#include <memory>

class Minion: public Card { //abstract

	int AP; //attack points
	int DP; //defense points
	std::vector<typename std::shared_ptr<typename Enchantment>> buffs; // enchantments applied to minion
	Ability *ability;

public:
	// use minion to attack, return true if minion dies after attack, false if minion lives after attack
	bool attack(Minion *minion);
	// minion attacks the opponent, grab how much the minion can hit for
	int attack();
	// use minions ability
	void use();
	// use minions ability on target minion
	void use(Minion *minion);
	// adds an enchantment on to the minion
	void addBuff(Enchantment *enchant);
	// use the minions	
	virtual ~Minion();

};
#endif
