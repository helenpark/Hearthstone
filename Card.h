#include <vector>
#include <string>

class Card { // abstract class
	
	string name;
	int cost;
	string description;
	Player *Owner;

public:

	virtual ~Expr();
	enum cardType {Minion = 0, Spell, Enchantment, Ritual}
	cardType getType();	 

};

std::ostream &operator<<(std::ostream &out, const Card &c);
