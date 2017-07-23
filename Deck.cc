#include "Deck.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithim>
#include <fstream>

using namespace std;

vector<Card*> Deck::shuffle(vector<Card*> cards) {
	random_shuffle(base.begin(), base.end());
}

shared_ptr<Card> Deck::drawCard() {
	shared_ptr<Card> temp = base.back();
	base.pop_back();
	return temp;
}

bool Deck::isEmpty() {
	return base.empty();
}

void Deck::initDeck(filename) {
	ifstream input;
	input.open(filename);
	string name;

	while (input >> name) {
		// create new instances of cards and shove them into base
		// probably looks like the following
		// base.emplace_back(new Card{name});	
	}
}


