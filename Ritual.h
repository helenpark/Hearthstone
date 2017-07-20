#ifndef _RITUAL_
#define _RITUAL_
#include "Card.h"
#include "Ability.h"
#include <vector>
#include <string>
#include <memory>

class Ritual: public Card { //abstract

	Ability *ability;
	int charges;

public:
	virtual ~Ritual();

};

#endif
