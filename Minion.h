
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

class Minion: public Card { //abstract

	int AP; //attack points
	int DP; //defense points
//	std::vector<typename std::shared_ptr<typename Enchantment>> buffs; // enchantments applied to minion
//	Ability *ability;

public:
/*	// use minion to attack, return true if minion dies after attack, false if minion lives after attack
	virtual bool attack(Minion *minion) = 0;
	// minion attacks the opponent, grab how much the minion can hit for
	virtual int attack(Player *player) = 0;
	// use minions ability (feed in all possible parameters to make life easy)
	virtual void use(Board *board, player *player, Minion *minion) = 0;
	// adds an enchantment on to the minion
	virtual void addBuff(Enchantment *enchant) = 0;
	// gets the ability type
	virtual Ability::AbilityType getType();
	// use the minions
	*/
	Minion(string name, int cost,
      string description, int p, int AP, int DP, int ac);
	virtual ~Minion();

};
#endif
