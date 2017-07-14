#include <vector>
#include <string>

class Spell: public Card { //abstract
	
public:

	// cast spell, may or may not have a target
	virtual void cast(Target *target); 

	virtual ~Spel();
};
