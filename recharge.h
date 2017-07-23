
#ifndef __RECHARGE_H__
#define __RECHARGE_H__

#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Spell.h"
using namespace std;

class Recharge: public Spell { //concrete card

public:
    Recharge(int p);
};
#endif
