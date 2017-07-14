#include <vector>
#include <string>

class Deck {
	
	vector<Card*> base;

public:
	
	// shuffle deck, randomize order of cards
    vector<Card*>  shuffle(vector<Card*> cards);

    // drawCard from deck, return pointer to card drawn
    Card* drawCard();

    // whether deck contains any cards or not
    bool isEmpty();

    Deck();
    ~Deck();

};

std::ostream &operator<<(std::ostream &out, const Deck &d);