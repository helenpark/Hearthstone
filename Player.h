
#include <vector>
#include <string>

class Player {
	
	const Board *board;
	const String name;
	bool firstTurn = true;
	int MP; //magic
	int HP; //health
	vector<Card*> hand; //cards currently in hand
	Deck *playerDeck; 
	Grave *playerGrave; 
	vector<Card*> cardsPlayed; //cards active on the board playing field
	Ritual *ritual;

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
    void initDeck(string filename);

    // Start of the turn
    void turnStart(); 

    // get my board: currently played cards
	vector<Card*> getMyBoard();

	// get enemy currently played cards
	vector<Card*> getEnemyBoard();

	Player(string name, Board *board);
	~Player();
};
