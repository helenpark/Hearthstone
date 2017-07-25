
#ifndef __MAGICFATIGUE_H__
#define __MAGICFATIGUE_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Enchantment.h"
class MagicFatigue: public Enchantment { //concrete card

public:
    MagicFatigue(int p);
    void print() override;
    std::vector<std::string> getAscii() override;
};
#endif
