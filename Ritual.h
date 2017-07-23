#ifndef _RITUAL_
#define _RITUAL_
#include "Card.h"
#include "Ability.h"
#include "Minion.h"
#include <vector>
#include <string>
#include <memory>

// forward declaration, make sure to #include "Board.h" and #include "Player.h" in the .cc files
class Player;
class Board;

class Ritual: public Card { //abstract

	Ability *ability;
	int charges;

public:
	virtual void activate(std::shared_ptr<Minion> minion);
	virtual void activate(Player *player);
	virtual ~Ritual();

};

#endif
