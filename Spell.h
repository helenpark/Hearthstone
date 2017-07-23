#ifndef _SPELL_
#define _SPELL_
#include "Card.h"
#include <vector>
#include <string>
#include <memory>

// forward declaration, make sure to #include "Board.h" in the .cc file
class Board;

class Spell: public Card { //abstract
	
public:

	// cast spell on ritual
	virtual void cast(Board *board, std::shared_ptr<Card> target);
	// case spell, with no real target, casts in general
	virtual void cast(Board *board);

	virtual ~Spell();
};

#endif
