

#ifndef __NOVICEPYROMANCER_H__
#define __NOVICEPYRONMANCER_H__

#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Minion.h"
using namespace std;

class NovicePyromancer: public Minion { //concrete card

public:
    NovicePyromancer(int p);
    void print() override;
    std::vector<std::string> getAscii() override;
};
#endif
