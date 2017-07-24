
#ifndef _PLAYER_H__
#define _PLAYER_H__

#include "Board.h"
#include "Deck.h"
//#include "Grave.h"
//#include "Ritual.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Board;
class Player {

public:

    string name  = "no name";
    int num= 2; //player1 or player2



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
    void board();
	//subtract HP when hit -> return remaining hp
	int getHit(int AP);

};
#endif

