

#ifndef __AIRELEMENTAL_H__
#define __AIRELEMENTAL_H__

#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Minion.h"
using namespace std;

class AirElemental: public Minion { //concrete card

public:
    AirElemental(int p);
};
#endif
