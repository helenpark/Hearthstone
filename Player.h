#ifndef _PLAYER_
#define _PLAYER_
#include "Board.h"
#include "Deck.h"
#include "Grave.h"
#include <vector>
#include <string>
#include <memory>

class Player {
	
	Board &board;
	const std::string name;
	const int number;
	const int oppNumber;
	Player *opponent;
	bool firstTurn = true;
	int MP; //magic
	int HP; //health
	std::vector<std::shared_ptr<Card>> hand; //cards currently in hand
	Deck *playerDeck; 
	Grave *playerGrave; 
	std::vector<std::shared_ptr<Card>> MinionsPlayed; //cards active on the board playing field
	// ritual played for this player
	std::shared_ptr<Ritual> ritualPlayed;

public:
    
    // place card on the playing field 
    void placeCard(int i);

    // place a card with a targeted ability
    void placeCard(int i, int p, int t);

    // draw from the player's deck
    void drawCard();
    
    // discard card, removing from hand and placing into player grave
    void discardCard(int i);

    // trigger attack method of the selected card on target 
    void attack(int i, int j);

    // trigger attack method on the opponent
    void attack(int i);

    // use minion's ability on the target (target does not need to be specified)
    void use(int i, int p, int t);

    // use minion's ability with no specified target
    void use(int i);

    // inspect the player's minion
    void inspect(int i);

    // displays the player's hand
    void displayHand();

    // intialize the player's deck
    void initDeck(std::string filename);

    // Start of the turn
    void turnStart(); 

    // checks if the player's HP is 0
    bool isDead();

    // sets the opponent of the player
    void setOpponent(Player *opp);

    // get my board: currently played cards
	std::vector<Card*> getMyBoard();

	// get enemy currently played cards
	std::vector<Card*> getEnemyBoard();

	Player(int num, int oppNum,  std::string name, Board &board);
	~Player();
};
#endif
