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
	virtual std::string getName();
	virtual ~Card();
	enum cardType {minion = 0, spell, enchantment, ritual};
	virtual cardType getType();	 

};

std::ostream &operator<<(std::ostream &out, const Card &c);

#endif
