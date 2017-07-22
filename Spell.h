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

	// cast spell, may or may not have a target
	virtual void cast(Board *board, Card *card); 
	// case spell, with no real target, casts in general
	virtual void cast(Board *board);

	virtual ~Spell();
};

#endif
