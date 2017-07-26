#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "banish.h"
#include "Deck.h"
#include "ascii_graphics.h"
#include "print.h"

#include "earthElemental.h"
#include "fireElemental.h"
#include "darkRitual.h"
#include "auraOfPower.h"
#include "standstill.h"

using namespace std;




int main(int argc, char *argv[]) {
	string cmd;
	string input;

	// filler because turn is set to either 1 or 2, which would seg fault hard since there is only 0 and 1
	Player filler, p1, p2;
	vector<Player *> players;
	players.push_back(&filler);
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
	// setting the opponents
	p1.opponent = &p2;
	p2.opponent = &p1;

	//Deck t = Deck();

	//t.initDeck("default.deck",p1);

	//standard input loop
	bool done = false;
	
	// ************** START OF GAME *****************
	
	if (!testing) {
		for (int i=0; i <4; i++) {
			p1.drawCard();
			p2.drawCard();
		}
	}
	
	
	// display magic remaining to be used
	cout << "Magic:";
	for (int i=0; i < curPlayer->ML; i++) {
		cout << " o";
	}
	for (int i=0; i < (curPlayer->MP - curPlayer->ML); i++) {
		cout << " .";
	}
	cout << endl;
	
	while (!done){
		
		// ************** START OF TURN *****************
		
		// RITUALS
		//curPlayer->myBoard->myRitual->activate() -> TODO NEED STANLEY TO INTEGRATE HERE
		
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
		
		curPlayer->turnEnd();
		curPlayer->status();
		otherPlayer = players[turn];
		turn==1?turn=2:turn=1;
		curPlayer = players[turn];
		curPlayer->turnStart();
		
		// draw a card and gain a magic point
		if (!testing) {
			curPlayer->drawCard();
			curPlayer->MP = curPlayer->MP + 1;
			curPlayer->ML = curPlayer->MP;
		}
		
		// display magic remaining to be used
		cout << "Magic:";
		for (int i=0; i < curPlayer->ML; i++) {
			cout << " o";
		}
		for (int i=0; i < (curPlayer->MP - curPlayer->ML); i++) {
			cout << " .";
		}
		cout << endl;
		
		cout << "new turn: "<< turn << endl;
		}

        else if (cmd=="quit"){
            done = true;
        }

        else if (cmd=="draw") {
            if (testing){
                turn==1?p1.drawCard():p2.drawCard();
            }
        }

        else if (cmd=="discard"){
            if (testing){
                int i;
                if (iss >> i) {
                    turn==1?p1.discard(i):p2.discard(i);
                    cout << "discard called" << endl << endl;
                } else {
                    cout << "Needs to be a number between 1 and 5" << endl;
                }
            }

        }

        else if (cmd=="attack"){
        	 int i, j;
        	 iss >> i;
             
			 shared_ptr<Minion> myMinion = curPlayer->myBoard->minionSlots[i-1];
			 if (iss >> j) { // case: attack another minion
			 cout << "attacking minion... " << endl;
				//cout << "4" << endl;
				shared_ptr<Minion> oppMinion = otherPlayer->myBoard->minionSlots[j-1];				
				myMinion->attack(oppMinion);
				
				p1.myBoard->checkDead();
				p2.myBoard->checkDead();

			 } else { // case: attack the other player directly
				cout << "attacking player... " << endl;
				int otherHP = myMinion->attack(otherPlayer);
				cout << "the other player has " << otherHP << " HP left!" << endl;
				if (otherHP <= 0) {
					curPlayer->winGame();
					return 0;
				}
			 }

        }
	else if (cmd=="play"){
            int i, p, t;
	    string temp;
	    // check if the second command is actually and int
            if (iss >> i) {
	    	// if this doesnt go through, it means its only attacking the player, if it does go through its attacking a target
                if (iss >> p) {
                    iss >> temp;
                    if (temp == "r") {
                        turn==1 ? p1.play(i, p, 'r') : p2.play(i, p, 'r');
                    }
                    else if (stringstream(temp) >> t) {
                        turn==1 ? p1.play(i, p, t) : p2.play(i, p, t);
                    } else {
                        turn==1?p1.play(i):p2.play(i);
                    }
                } else {
                    turn==1?p1.play(i):p2.play(i);
                }
            }

            // still need to implement the second option of play with i p t
             // int i,p,t;
             
             
            p1.myBoard->checkDead();
			p2.myBoard->checkDead();
			
			// display magic remaining to be used
			cout << "Magic Remaining:";
			for (int i=0; i < curPlayer->ML; i++) {
				cout << " o";
			}
			for (int i=0; i < (curPlayer->MP - curPlayer->ML); i++) {
				cout << " .";
			}
			cout << endl;
        }

        else if (cmd=="use") {
	    int i, p, t;
	    string temp;
	    // check if the second command is actually and int
            if (iss >> i) {
	    	// if this doesnt go through, it means its only attacking the player, if it does go through its attacking a target
                if (iss >> p) {
                    iss >> temp;
                    if (temp == "r") {
			int r = 'r';
                        turn==1 ? p1.use(i, p, r) : p2.use(i, p, r);
                    }
                    else if (stringstream(temp) >> t) {
                        turn==1 ? p1.use(i, p, t) : p2.use(i, p, t);
                    } else {
                        turn==1?p1.use(i):p2.use(i);
                    }
                } else {
                    turn==1?p1.use(i):p2.use(i);
                }
            }

            iss >> i;
            turn==1?p1.use(i):p2.use(i);            
            
            p1.myBoard->checkDead();
			p2.myBoard->checkDead();
			
			// display magic remaining to be used
			cout << "Magic Remaining:";
			for (int i=0; i < curPlayer->ML; i++) {
				cout << " o";
			}
			for (int i=0; i < (curPlayer->MP - curPlayer->ML); i++) {
				cout << " .";
			}
			cout << endl;
			
        }


        else if (cmd=="inspect"){
            int i;
            iss >> i;
            turn==1?p1.inspect(i):p2.inspect(i);
        }

        else if (cmd=="hand") {
            turn==1?p1.hand():p2.hand();
        }

        else if (cmd=="board"){
            p1.board(1);
            cout << endl;
            print (CENTRE_GRAPHIC);
            cout << endl;
            p2.board(2);
        }
	}
}
;
