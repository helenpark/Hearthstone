#ifndef _GRAVEKEEPER_
#define _GRAVEKEEPER_
#include "Card.h"
#include "Minion.h"
#include <vector>
#include <string>
#include <memory>

class GraveKeeper: public Minion {

public:
	GraveKeeper(int p);
	void print() override;
	std::vector<std::string> getAscii() override;
};
#endif
