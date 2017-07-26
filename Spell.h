
#ifndef _SPELL_H__
#define _SPELL_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>

using namespace std;
// forward declaration, make sure to #include "Board.h" in the .cc file
class Board;

class Spell: public Card { //abstract

public:

/*
	// cast spell, may or may not have a target
	virtual void cast(Board *board, Card *card);
	// case spell, with no real target, casts in general
	virtual void cast(Board *board);
*/
    Spell(string name, int cost,
      string description, int p);

      void print() override;
      std::vector<std::string> getAscii() override;
      virtual void cast(shared_ptr<Board> myBoard,int p, string t, shared_ptr<Board> oppBoard)=0;
};

#endif
