
#ifndef __SILENCE_H__
#define __SILENCE_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Enchantment.h"
class Silence: public Enchantment { //concrete card

public:
    Silence(int p);
    void print() override;
    std::vector<std::string> getAscii() override;
};
#endif
