

#ifndef __POTIONSELLER_H__
#define __POTIONSELLER_H__

#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Minion.h"
using namespace std;

class PotionSeller: public Minion { //concrete card

public:
    PotionSeller(int p);
    void print() override;
    std::vector<std::string> getAscii() override;
};
#endif
