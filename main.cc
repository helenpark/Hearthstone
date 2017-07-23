#include <iostream>
#include <string>
#include <fstream>
//#include "Board.h"
#include "Player.h"
#include "Card.h"
#include "Banish.h"
#include "Deck.h"

using namespace std;

int main(int argc, char *argv[]) {
    // TODO: delete, this is testing purposes

    cout << "GAME START: \n"
    string cmd;


    Player p1, p2;
    bool init = false;
    bool testing = false;
    int turn = 1; //keep track of whose turn is it, turn{1,2}



	// executing the arguments provided to main
	for (int i = 1; i < argc; i++) {
   //     cout << "arg[" <<i << "]: " << argv[i]<< endl;
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
            init = true;
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

        cin >> cmd;
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

        if (cmd=="end"){

            cout << "current turn: "<< turn << endl;
            //end of turn effects
            if (turn==1) {

            }
            else{

            }
            //start of turn effects
            if (turn==1){
                p1.gainMagic();
                p1.drawCard();
                //triggered start of turn abilities
            }
            else{
                p2.gainMagic();
                p2.drawCard();
            }
            turn==1?turn=2:turn=1;
            cout << "new turn: "<< turn << endl;
        }
        if (cmd=="quit"){
            done = true;
            cout << "quit called" << endl;
        }
        if (testing) {
            if (cmd=="draw"){
                turn==1?p1.drawCard():p2.drawCard();
                cout << "draw called" << endl;
            }
            if (cmd=="discard"){
                int i;
                cin >> i;
                turn==1?p1.discard(i):p2.discard(i);
                cout << "discard called" << endl;
            }
        }

        if (cmd=="attack"){
             cout << "attack called" << endl;
        }
        if (cmd=="play"){
            cout << "play called" << endl;
        }

        if (cmd=="use"){
            cout << "use called" << endl;
        }


        if (cmd=="inspect"){
            cout << "inspect called" << endl;
        }

        if (cmd=="hand"){
            cout << "hand called" << endl;
        }

        if (cmd=="board"){
            cout << "board called" << endl;
        }

	}
}
