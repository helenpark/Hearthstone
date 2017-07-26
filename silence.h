
#ifndef __SILENCE_H__
#define __SILENCE_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Enchantment.h"

class Minion;

class Silence: public Enchantment, public std::enable_shared_from_this<Silence> { //concrete card

public:
    Silence(int p);
    void print() override;
    std::vector<std::string> getAscii() override;
    void enchant(shared_ptr<Minion> minion);
};
#endif
