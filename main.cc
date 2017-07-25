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
#ifndef _PLAYER_H__
#define _PLAYER_H__

#include "Board.h"
#include "Deck.h"
//#include "Grave.h"
//#include "Ritual.h"
#include "Minion.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Player {

public:

    string name  = "no name";
    int num= 2; //player1 or player2
    Player *opponent;



    shared_ptr<Deck> myDeck = make_shared<Deck>(num);
    shared_ptr<Board> myBoard = make_shared<Board>(num);

    vector<shared_ptr<Card>> myHand; //5 cards
    vector<shared_ptr<Card>> played;
    int HP = 20;  //20 lives
    int MP = 3;   //3 magics

    Player();
	Player(std::string name, int n);

	//copy ctor
    Player (const Player &other);
    //move ctor
    Player (Player &&other);
    //copy assignment operator
    Player &operator=(const Player &other);
    //move assignment operator
    Player &operator=(Player &&other);
	 //dtor
	~Player();

	// returns true if ith card is on hand
	bool hasCard(int i);

	// draw from the player's deck
    void drawCard();
    // gain 1 magic
    void gainMagic();
    // discard card on Hand
    void discard(int i);
    // orders minion i to attack the opposing player
    void attack (int i);
    // overloaded attack orders minion i to attack opponent's minion j
    void attack(int i, int j);

    // play the ith card in the player's hand
    void play(int i);
    // overloaded play, plays the ith card on card t owned by player p
    void play (int i, int p, int t);

    //use ith minion owned by the player
    void use(int i);
    //inspect ith minion owned
    void inspect(int i);
    //display the hand
    void hand ();
    //display the board
    void board(int i);
    //subtract HP when hit -> return remaining hp
    int getHit(int AP);

    // function for turnStart triggers
    void turnStart();
    // function for turnEnd triggers
    void turnEnd();
    // function for minionPlayed
    void minionPlayed(std::shared_ptr<Minion> minion);
    // function for miniondied
    void minionDied();
    // the status of the player as of right now
    void status();
};
#endif


	//t.initDeck("default.deck",p1);

	//standard input loop
	bool done = false;
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
				cout << "8" << endl;
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
        }

        else if (cmd=="use") {

            int i;
            iss >> i;
            turn==1?p1.use(i):p2.use(i);
            cout << "use called" << endl << endl;
            
            
            p1.myBoard->checkDead();
			p2.myBoard->checkDead();
        }


        else if (cmd=="inspect"){
            int i;
            iss >> i;
            turn==1?p1.inspect(i):p2.inspect(i);
            cout << "inspect called" << endl << endl;
        }

        else if (cmd=="hand") {
            turn==1?p1.hand():p2.hand();
            cout << "hand called" << endl << endl;
        }

        else if (cmd=="board"){
            p1.board(1);
            cout << endl;
            print (CENTRE_GRAPHIC);
            cout << endl;
            p2.board(2);
            cout << "board called" << endl << endl;
        }
	}
}
;
