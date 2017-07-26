#ifndef _GIANTSTRENGTH_H__
#define _GIANTSTRENGTH_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Enchantment.h"
using namespace std;

class Minion;

class GiantStrength: public std::enable_shared_from_this<GiantStrength>, public Enchantment { //concrete card

public:
    GiantStrength(int p);
    void print() override;
    void enchant(shared_ptr<Minion> minion);
    std::vector<std::string> getAscii() override;
};
#endif
