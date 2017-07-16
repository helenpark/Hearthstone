#include <iostream>
#include <string>
#include <fstream>
#include "Board.h"
#include "Player.h"
using namespace std;

int main(int argc, char *argv[]) {	
	string cmd;
	Board board;	
	// flags to indicate whether the player brought there own deck
	bool deck1 = false;
	bool deck2 = false;
	bool testing = false;
	bool init = false;
	ifstream initFile;
	
	// get the names of the players
	cout << "Name of player 1: ";
	cin >> cmd;
	Player player1{cmd, board};
	cout << endl;

	cout << "Name of player 2: ";
	cin >> cmd;
	Player player2{cmd, board};
	
	// executing the arguements provided to main	
	for (int i = 0; i < argc; i++) {
		// when player 1 has a deck, the next element should be the filename of the deck
		if (argv[i] == "-deck1") {
			player1.initDeck(argv[i+1]);
			deck1 = true;
		}
		// when player 2 has a deck, same situation as -deck1
		if (argv[i] == "-deck2") {
			player2.initDeck(argv[i+1]);
			deck2 = true;
		}
		// when -init arguement is present
		if (argv[i] == "init") {
			initFile.open(argv[i+1]);
			init = true;
		}
		// if the testing argument is present
		if (argv[i] == "-testing") {
			testing = true;
		}
		
	}

	// When the -deck1 or -deck2 arguement is not present,
	// use the default decks
	if (!deck1) {
		player1.initDeck("default.deck");
	}
	if (!deck2) {
		player2.initDeck("default.deck");
	}

	// recieve commands until the end of the game;
	while (cin >> cmd) {
		
	}
}
