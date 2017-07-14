#include <vector>
#include <string>

class Card { // abstract class
	
	string name;
	int cost;
	string description;
	Player *Owner;

public:

	virtual ~Expr();

};

std::ostream &operator<<(std::ostream &out, const Card &c);