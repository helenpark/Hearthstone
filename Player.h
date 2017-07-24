

#ifndef _PLAYER_H__
#define _PLAYER_H__
//#include "Board.h"
#include "Deck.h"
//#include "Grave.h"
//#include "Ritual.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Player {

    string name  = "no name";
    int num= 2; //player1 or player2

    shared_ptr<Deck> myDeck;
   // shared_ptr<Board> myBoard;

    vector<shared_ptr<Card>> myHand; //4 cards
    vector<shared_ptr<Card>> played;
    int HP = 20;  //20 lives
    int MP = 3;   //3 magics

    //board
    //graveyard

public:
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

	// draw from the player's deck
    void drawCard();
    // gain 1 magic
    void gainMagic();
    // discard card
    void discard(int i);
    // display hand, return number of cards currently in hand
    vector<shared_ptr<Card>> getHand();
};
#endif
