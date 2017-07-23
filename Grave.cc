#include "Grave.h"
#include <vector>
#include <iostream>
#include <iostream>

using namespace std;

Card *Grave::resurect() {
	for (int i = graveyard.size(); i >= 0; i--) {
		if (graveyeard[i].getType() == Card::Minion) {
			return graveyard[i];
		}
	}
	cout << "No minions in the graveyard" << endl;	
}

void Grave::died(Card *minion) {
	graveyard.emplace_back(minion);
}
