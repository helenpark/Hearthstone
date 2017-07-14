
#include <vector>
#include <string>

class Player {
	
	Board board;
	String name;
	int MP; //magic
	int HP; //health
	vector<Card*> hand; //cards currently in hand
	Deck *playerDeck; 
	Grave *playerGrave; 
	vector<Card*> cardsPlayed; //cards active on the board playing field

public:
    
    // place card on the playing field 
    void placeCard(Card *card);
    
    // discard card, removing from hand and placing into player grave
    void discardCard(Card *card);

    // trigger attack method of the selected card on target 
    void attack(Card *card, Target *target);

    // use minion's ability on the target (target does not need to be specified)
    void use(Minion *minion, Target *target);

    // get my board: currently played cards
	vector<Card*> getMyBoard();

	// get enemy currently played cards
	vector<Card*> getEnemyBoard();

	Player();
	~Player();
};