

#ifndef __EARTHELEMENTAL_H__
#define __EARTHELEMENTAL_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Minion.h"
using namespace std;

class EarthElemental: public Minion { //concrete card

public:
    EarthElemental(int p);
};

#endif
