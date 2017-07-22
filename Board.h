#ifndef _BOARD__
#define _BOARD_
#include "Minion.h"
#include "Ritual.h"
#include "Spell.h"
#include <vector>
#include <string>
#include <memory>

class Board {
	Minion *deadMinion; //top of the graveyard
	Ritual *ritual;  // Ritual Pointer (that is on the board)
 	std::vector <std::shared_ptr<typename Minion>> onBoard; // a std::vector of maximum size of five that keeps track of the minions on the board 
	std::vector <std::shared_ptr<typename Minion>> player1Minions // player 1's cards
	Ritual *player1Ritual; // player 1's ritual
	Deck *player1Deck;
	Grave *player1Grave;
	std::vector <std::shared_ptr<typename Minion>> player2Minions // player 2's minions
	Ritual *player2Ritual; // player 2's ritual
	Deck *player2Deck;
	Grave *player2Grave;

public:
	Card* getTarget(int player, int target); // retrieves the given card needed
	// inspects the card from the current active player
	void inspect(int i, int player);
	// places the minion on the active player's board
	void placeMinion(Minion *minion, int player);
	// places the ritual card on the active player's board
	void placeRitual(Ritual *ritual, int player);
	// plays the spell card with no specific target
	void playSpell(Spell *spell);
	// plays the spell card with a specific target
	void playSpell(Spell *spell, Card *target);
	// places the enchantment on the targeted minion
	void playEnchantment(Enchantment *enchant, Minion *minion);
	// sets the deck for whichever player
	void setDeck(Deck *deck, int player);
	// sets the Grave for whichever player
	void setGrave(Grave *grave, int player); 
	// activates any ability that triggers when a minion enters play
	void minionPlayed(Minion *minion);
};

std::ostream &operator<<(std::ostream &out, const Board &b);

#endif
