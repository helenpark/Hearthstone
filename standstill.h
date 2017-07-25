#ifndef __STANDSTILL_H__
#define __STANDSTILL_H__
#include "Ritual.h"
#include "Player.h"
#include <memory>

class Board;
class Player;
class Minion;

class Standstill: public Ritual { //concrete card

public:
	Standstill(int p);
	void activate(Player *player=nullptr, shared_ptr<Board> board=nullptr, 
			std::shared_ptr<Minion> minion=nullptr);

};
#endif
