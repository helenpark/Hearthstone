

#ifndef __RAISEDEAD_H__
#define __RAISEDEAD_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Spell.h"
using namespace std;

class RaiseDead: public Spell { //concrete card

public:
    RaiseDead(int p);
     void cast(shared_ptr<Board> myBoard,int p,string t, shared_ptr<Board> oppBoard) override;
};

#endif
