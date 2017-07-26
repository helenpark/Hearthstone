#ifndef __DISENCHANT_H__
#define __DISENCHANT_H__

#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Spell.h"
using namespace std;

class Disenchant: public Spell { //concrete card

public:
    Disenchant(int p);
    void cast(shared_ptr<Board> myBoard,int p,string t, shared_ptr<Board> oppBoard) override;
};
#endif

