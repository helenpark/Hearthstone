
#ifndef __MAGICFATIGUE_H__
#define __MAGICFATIGUE_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Enchantment.h"

class Minion;

class MagicFatigue: public Enchantment, public std::enable_shared_from_this<MagicFatigue> { //concrete card

public:
    MagicFatigue(int p);
    void print() override;
    void enchant(shared_ptr<Minion> minion);
    std::vector<std::string> getAscii() override;
};
#endif
