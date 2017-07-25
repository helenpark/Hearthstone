

#ifndef __FIREELEMENTAL_H__
#define __FIREELEMENTAL_H__

#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Minion.h"
using namespace std;

class FireElemental: public Minion { //concrete card

public:
    FireElemental(int p);
};
#endif
