
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

class Player : public std::enable_shared_from_this<Minion> {

public:

    string name  = "no name";
    int num= 2; //player1 or player2
    Player *opponent;


    shared_ptr<Deck> myDeck = make_shared<Deck>(num);
    shared_ptr<Board> myBoard = make_shared<Board>(num);

    vector<shared_ptr<Card>> myHand; //5 cards
    vector<shared_ptr<Card>> played;
    int HP = 20;  //20 lives
    int MP = 3;   //2 magics
    int ML = MP;   //magic left


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
    void play (int i, int p, string t);

    //use ith minion owned by the player
    void use(int i);
    //use ith minions ability on whichever target
    void use(int i, Player *p, int t);

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
    // win Game -> output game won messages
    void winGame();
    // use magic (when playing minion or other cards)
    bool useMagic(int cost);
};
#endif

