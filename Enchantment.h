#ifndef _ENCHANTMENT_H__
#define _ENCHANTMENT_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Card.h"
using namespace std;
class Minion;

class Enchantment: public Card { //abstract

//	Card *minion;

public:
    Enchantment(string name, int cost, string description, int p);
	virtual void enchant(shared_ptr<Minion> minion) =0;
    void print()=0;
    std::vector<std::string> getAscii()=0;
	virtual ~Enchantment();

};

#endif
