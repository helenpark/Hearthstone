

#ifndef _DECK_H__
#define _DECK_H__
#include "Card.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;
class Deck {
    int owner;
    string filename;
	std::vector<std::shared_ptr<Card>> base;

public:
   Deck(int owner);
   Deck(int owner,string filename);


	// shuffle deck, randomize order of cards
    void shuffle();

 /*   //readd
    void readd();
*/
    // whether deck contains any cards or not
    bool isEmpty();

    // initializes the deck at the beginning of the game form the file name
    void initDeck(std::string filename);

    shared_ptr<Card> draw();

    friend std::ostream &operator<<(std::ostream &out, const Deck &d);
};

#endif
