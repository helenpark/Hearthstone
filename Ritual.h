#ifndef __RITUAL_H__
#define __RITUAL_H__
#include <vector>
#include <string>
#include "Card.h"
using namespace std;
class Ritual: public Card { //abstract

	//Ability *ability;
	int activationCost;
	int charges;

public:
    Ritual(string name, int cost, string description, int p,
      int activationCost, int charges);


    bool canActivate();
  //  virtual void useAbility(Target *t=nullptr)=0;
    void print() override;
	virtual ~Ritual();

};
#endif
