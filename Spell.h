#ifndef _SPELL_
#define _SPELL_
#include "Card.h"
#include <vector>
#include <string>
#include <memory>

class Spell: public Card { //abstract
	
public:

	// cast spell, may or may not have a target
	virtual void cast(Card *card); 
	// case spell, with no real target, casts in general
	virtual oid cast();

	virtual ~Spell();
};

#endif
