

#ifndef __BLIZZARD_H__
#define __BLIZZARD_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
#include "Spell.h"
using namespace std;

class Blizzard: public Spell { //concrete card

public:
    Blizzard(int p);
    void cast(shared_ptr<Board> myBoard,shared_ptr<Card> target=nullptr, shared_ptr<Board> oppBoard=nullptr) override;
};
#endif
