
#ifndef __BOARD_H__
#define __BOARD_H__

#include "Player.h"
#include "Minion.h"
#include "Ritual.h"
#include "Card.h"
#include "Ability.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <memory>
using namespace std;

class Board {
    public:
        int owner = 1;
        vector<shared_ptr<Minion>> minionSlots;
        vector<string> grave;
        shared_ptr<Ritual> myRitual = nullptr;


        Board();
        Board(int owner);
        //resurrect the top minion in graveyard
        shared_ptr<Card> resurrect();
        //place a minion on the board
        void placeMinion(shared_ptr<Card> m);
        //place a ritual on the board
        void placeRitual(shared_ptr<Card> r);
        //place a died minion in the grave
        void placeGrave(shared_ptr<Minion> m);
        //ritual on the board gain i charges
        void gainCharge(int i);
        //return top minion
        shared_ptr<Card> top();
        // checks for any dead minions; removes from board and places in graveyeard
        void checkDead();
};

#endif
