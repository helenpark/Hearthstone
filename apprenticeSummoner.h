

#ifndef __APPRENTICESUMMONER_H__
#define __APPRENTICESUMMONER_H__

#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Minion.h"
using namespace std;

class ApprenticeSummoner: public Minion { //concrete card

public:
    ApprenticeSummoner(int p);
};
#endif
