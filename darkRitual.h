
#ifndef __DARKRITUAL_H__
#define __DARKRITUAL_H__

#include "Ritual.h"
#include "Player.h"
#include <memory>

class Player;
class Board;
class Minion;

class DarkRitual: public Ritual { //concrete card

public:
	DarkRitual(int p);
	void activate(Player *player=nullptr, Board *board=nullptr, 
		      std::shared_ptr<Minion> minion=nullptr);

};
#endif
