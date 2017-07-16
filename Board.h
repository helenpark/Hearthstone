
#include <vector>
#include <string>

class Board {
	
	Player *player1;
	Player *player2;

	Minion *deadMinion; //top of the graveyard)
	Ritual *ritual;  // Ritual Pointer (that is on the board)
 	vector <minion*> onBoard; // a vector of maximum size of five that keeps track of the minions on the board 
	vector <minion*> player1Minions // player 1's cards
	Ritaul *player1Ritual; // player 1's ritual
	vector <minion*> player2Minions // player 2's minions
	Ritual *player2Ritual; // player 2's ritual

public:
	void gameStart(); // asks for the player's names, shuffles the decks
	bool gameEnded(); // checks if someone won or lost
	Card getTarget(int p, int t); // retrieves the given card needed
};

std::ostream &operator<<(std::ostream &out, const Board &b);
