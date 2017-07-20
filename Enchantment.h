#ifndef _ENCHANTMENT_
#define _ENCHANTMENT_
#include "Card.h"
#include <vector>
#include <string>
#include <memory>

class Enchantment: public Card { //abstract

	Card *minion;

public:

	virtual ~Enchantment();

};

#endif
