#ifndef _GIANTSTRENGTH_H__
#define _GIANTSTRENGTH_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Enchantment.h"
using namespace std;

class GiantStrength: public Enchantment { //concrete card

public:
    GiantStrength(int p);
    void print() override;
    std::vector<std::string> getAscii() override;
};
#endif
