#include <vector>
#include <string>

class Ritual: public Card { //abstract

	Ability *ability;
	int charges;

public:
	virtual ~Ritual();

};
