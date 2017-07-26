#ifndef __RITUAL_H__
#define __RITUAL_H__
#include <vector>
#include <string>
#include <memory>
#include "Card.h"
using namespace std;

class Board;
class Player;
class Minion;

class Ritual: public Card { //abstract

public:
	//Ability *ability;
	int activationCost;
	int charges;
	Ritual(string name, int cost, string description, int p,
	int activationCost, int charges);

	bool canActivate();
	// uses the ritual ability
	void print() override;
	std::vector<std::string> getAscii() override;
	virtual void activate(Player *player=nullptr, std::shared_ptr<Board> board=nullptr, std::shared_ptr<Minion> minion=nullptr) = 0;

};
#endif
