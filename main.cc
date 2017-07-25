#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "banish.h"
#include "Deck.h"

#include "earthElemental.h"
#include "fireElemental.h"
#include "darkRitual.h"
#include "auraOfPower.h"
#include "standstill.h"

using namespace std;

int main(int argc, char *argv[]) {
	string cmd;
	string input;

	Player p1, p2;
	vector<Player *> players;
	players.push_back(&p1);
	players.push_back(&p2);
	bool testing = false;
	int turn = 1;
	Player *curPlayer = &p1; // alternative, notation to above line of code (Helen)
	Player *otherPlayer = &p2;
	vector<shared_ptr<Card>> hand;

	// executing the arguments provided to main
	for (int i = 1; i < argc; i++) {
		// cout << "arg[" <<i << "]: " << argv[i]<< endl;
		string arg = argv[i];

		// when player 1 has a deck, the next element should be the filename of the deck
		if (arg == "-deck1") {

			++i;/*
			       player1.initDeck(argv[i]);
			       deck1 = true;*/
		}
		// when player 2 has a deck, same situation as -deck1
		if (arg == "-deck2") {

			++i;/*
			       player2.initDeck(argv[i]);
			       deck2 = true; */
		}
		// when -init arguement is present
		if (arg == "-init") {
			ifstream initFile;
			// init = true;
			++i;
			// cout<<"Filename is: " << argv[i]<<endl;

			initFile.open(argv[i]);
			string in;
			if (initFile.is_open()){

				initFile >> in;
				p1 = Player{in,1};

				initFile >> in;
				p2 = Player{in,2};

				while(!initFile.eof()){
					initFile >> in;
					if (in=="play") {
						int n;
						initFile >> n;
						//play card n
						// cout << "play card n: " << n << endl;
					}
				}
			}
		}

		// if the testing argument is present
		if (arg == "-testing") {
			testing = true;
		}

	}
	cout << endl;


	//Deck t = Deck();
	//t.initDeck("default.deck",p1);

	//standard input loop
	bool done = false;
	while (!done){

		getline(cin, input);
		istringstream iss(input);
	    string cmd;
    	iss >> cmd;
		if (cin.eof()) break;

		if  (cmd=="help") {
			cout<<"Commands: help-- Display this message.\n";
			cout<<"\t end -- End the current player's turn.\n";
			cout<<"\t quit -- End the game.\n";
			cout<<"\t attack minion other-minion -- Orders"<<
				" minion to attack the opponent\n";
			cout<<"\t attack minion -- Orders minion to attack the opponent.\n";
			cout<<"\t play card [target-player target-card]"<<
				" -- Play card, optionally targeting target-card owned by target-player\n";
			cout<<"\t use minion [target-player target-card] -- Use minion's special ability,"
				<< " optionally targeting target-card owned by target-player.\n";
			cout<<"\t inspect minion -- View a minion's card and all enchantments on that minion.\n";
			cout<<"\t hand -- Describe all cards in your hand.\n";
			cout<<"\t board -- Describe all cards on the board.\n";
		}

		else if (cmd=="end"){
			{

			cout << "current turn: "<< turn << endl;
			// TODO:end of turn effects

			//start of turn effects

			curPlayer->gainMagic();
			curPlayer->drawCard();
			//triggered start of turn abilities
			}
		otherPlayer = players[turn];
		turn==1?turn=2:turn=1;
		curPlayer = players[turn];
		cout << "new turn: "<< turn << endl;
		}

        else if (cmd=="quit"){
            done = true;
            cout << "quit called" << endl;
        }
        else if (cmd=="draw") {
            if (testing){
                turn==1?p1.drawCard():p2.drawCard();
                cout << "draw called" << endl;
            }
        }
        else if (cmd=="discard"){
            if (testing){
                int i;
                cin >> i;
                turn==1?p1.discard(i):p2.discard(i);
                cout << "discard called" << endl;
            }
        }

        else if (cmd=="attack"){
        	 int i, j;
        	 iss >> i;
        	 cout << "1" << endl;
             // invalid input
             cout << "#minions played = " << curPlayer->myBoard->minionSlots.size() << endl;
			 shared_ptr<Minion> myMinion = curPlayer->myBoard->minionSlots[i-1];
			 cout << "3" << endl;
			 if (iss >> j) { // case: attack another minion
			 cout << "attacking minion... " << endl;
				cout << "4" << endl;
				shared_ptr<Minion> oppMinion = otherPlayer->myBoard->minionSlots[j-1];
			
				// minions that die in this attack (note: max 2 minions)
				vector<shared_ptr<Minion>> deadMinions = myMinion->attack(oppMinion);
			
				if (deadMinions[0] != nullptr) {
					cout << "5" << endl;
					cout << "My minion - " << myMinion->name << "has died" << endl; 
					p1.myBoard->placeGrave(myMinion);
					p1.myBoard->minionSlots.erase(p1.myBoard->minionSlots.begin() + i-1);
				}
				if (deadMinions[1] != nullptr) {
					cout << "6" << endl;
					cout << "Their minion - " << oppMinion->name << "has died" << endl; 
					p2.myBoard->placeGrave(oppMinion);
					p2.myBoard->minionSlots.erase(p2.myBoard->minionSlots.begin() + j-1);
				}
				cout << "7" << endl;
			 } else { // case: attack the other player directly
				cout << "8" << endl;
				cout << "attacking player... " << endl;
				int otherHP = myMinion->attack(otherPlayer);
				cout << "the other player has " << otherHP << "left!" << endl; 
		 
			 }
			 cout << "9" << endl;
			 cout << "attack called" << endl;

			
        }
		else if (cmd=="play"){
            int i;
            cin >> i;
            turn==1?p1.play(i):p2.play(i);
            cout << "play called" << endl;
            // still need to implement the second option of play with i p t
             // int i,p,t;
        }

        else if (cmd=="use") {

            int i;
            cin >> i;
            turn==1?p1.use(i):p2.use(i);
            cout << "use called" << endl;
        }


        else if (cmd=="inspect"){
            int i;
            cin >> i;
            turn==1?p1.inspect(i):p2.inspect(i);
            cout << "inspect called" << endl;
        }

        else if (cmd=="hand"){
            turn==1?p1.hand():p2.hand();
            cout << "hand called" << endl;
        }

        else if (cmd=="board"){
            p1.board();
            p2.board();
            cout << "board called" << endl;
        }
        else if (cmd=="t") { //testing cmd for board methods (Jenn)

         Board *t = new Board(1);
          /*   shared_ptr<Minion> m = make_shared<EarthElemental>(1);
            shared_ptr<Minion> b = make_shared<FireElemental>(1);
              t->placeGrave(m);

            t->placeGrave(b);
            t->resurrect();
            t->resurrect();
            t->placeGrave(m);

            t->placeMinion(m);
            t->placeMinion(m);
            t->placeMinion(b);
            t->placeMinion(m);
            t->placeMinion(b);
            t->placeMinion(m);
            try {
                t->resurrect();
            }
            catch (string msg) {
                cout << msg <<endl;
            } */
            
            // TODO: uncomment -> this code currently does not compile.
            // shared_ptr<Card> r1 = make_shared<DarkRitual>(1);
//             shared_ptr<Ritual> r2 = make_shared<AuraOfPower>(1);
//             shared_ptr<Ritual> r3 = make_shared<Standstill>(1);
//             t->placeRitual(r1);
//             t->placeRitual(r2);
//             t->placeRitual(r3);
        }
	}
}
	
