#ifndef _SOULHARVEST_
#define _SOULHARVEST_
#include "Ritual.h"
#include "Player.h"
#include <memory>

class Board;
class Player;
class Minion;

class SoulHarvest : public Ritual {

public:
	SoulHarvest(int p);
	void activate(Player *player=nullptr, shared_ptr<Board> board=nullptr, std::shared_ptr<Minion> minion=nullptr);

};
#endif

