#ifndef _CARD_
#define _CARD_
#include <vector>
#include <string>
#include <memory>

class Card { // abstract class
	
	std::string name;
	int cost;
	std::string description;

public:
	virtual getName();
	virtual ~Card();
	enum cardType {Minion = 0, Spell, Enchantment, Ritual};
	Card::cardType getType();	 

};

std::ostream &operator<<(std::ostream &out, const Card &c);

#endif
