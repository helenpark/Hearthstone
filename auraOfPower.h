
#ifndef __AURAOFPOWER_H__
#define __AURAOFPOWER_H__
#include <memory>
#include "Ritual.h"
#include "Player.h"

class Board;
class Player;
class Minion;

class AuraOfPower: public Ritual { //concrete card

public:
	AuraOfPower(int p);
	void activate(Player *player=nullptr, Board *board=nullptr, std::shared_ptr<Minion> minion=nullptr);

};
#endif
