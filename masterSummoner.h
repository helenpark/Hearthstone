

#ifndef __MASTERSUMMONER_H__
#define __MASTERSUMMONER_H__

#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Minion.h"
using namespace std;

class MasterSummoner: public Minion { //concrete card

public:
    MasterSummoner(int p);
    void print() override;
};
#endif
