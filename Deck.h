#ifndef _DECK_
#define _DECK_
#include "Card.h"
#include <vector>
#include <string>
#include <memory>

class Deck {
	
	std::vector<std::shared_ptr<Card>> base;

public:
	
	// shuffle deck, randomize order of cards
    std::vector<std::shared_ptr<Card>>  shuffle();

    // drawCard from deck, return pointer to card drawn
    std::shared_ptr<Card> drawCard();

    // whether deck contains any cards or not
    bool isEmpty();

    // intializes the deck at the beginning of the game form the file name
    void initDeck(std::string filename);

    Deck();
    ~Deck();

};

std::ostream &operator<<(std::ostream &out, const Deck &d);

#endif
