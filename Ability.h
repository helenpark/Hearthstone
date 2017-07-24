#ifndef _ABILITY_
#define _ABILITY_
#include <vector>
#include <memory>
#include <string>

class Minion;
class Board;

class Ability {
public:
	std::string description;
	std::string name;
	int cost;
	// deal 1 dmg when the minion enters play
	void fireElemental(std::shared_ptr<Minion> minion);
	// all minions on your side gain +0/+1 when turn ends
	void potionSeller(Board *board);
	// deal 1 dmg to target minion
	void novicePyromancer(std::shared_ptr<Minion> minion);
	// Summon air elemental to the board
	void apprenticeSummoner(Board *boad);
	// Summon 3 air elemental to the board
	void masterSummoner(Board *board);
	// ctor for ability
	Ability(std::string name, int cost);
};

#endif
