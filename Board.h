
#include <vector>
#include <string>

class Board {
	
	Player *player1;
	Player *player2;

	Minion *deadMionion; //top of the graveyard)
	Ritual *ritual;  // Ritual Pointer (that is on the board)
 	vector <minion*> onBoard; // a vector of maximum size of five that keeps track of the minions on the board

};

std::ostream &operator<<(std::ostream &out, const Board &b);