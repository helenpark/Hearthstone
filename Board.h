#ifndef _BOARD_
#define _BOARD_
#include "Minion.h"
#include "Ritual.h"
#include "Spell.h"
#include "Deck.h"
#include "Grave.h"
#include "Card.h"
#include <vector>
#include <string>
#include <memory>

class Board {
	std::vector < std::shared_ptr<Minion> > player1Minions; // player 1's cards
	std::shared_ptr<Ritual> player1Ritual; // player 1's ritual
	Deck *player1Deck;
	Grave *player1Grave;
	std::vector <std::shared_ptr<Minion>> player2Minions; // player 2's minions
	std::shared_ptr<Ritual> player2Ritual; // player 2's ritual
	Deck *player2Deck;
	Grave *player2Grave;

public:
	std::shared_ptr<Card> getTarget(int player, int target); // retrieves the given card needed
	// inspects the card from the current active player
	void inspect(int i, int player);
	// places the minion on the active player's board
	void placeMinion(std::shared_ptr<Minion> minionPlay, int player);
	// places the ritual card on the active player's board
	void placeRitual(std::shared_ptr<Ritual> ritualPlay, int player);
	// plays the spell on whichever target
	void playSpell(std::shared_ptr<Spell> spellPlay, std::shared_ptr<Card> target);
	// plays the spell card with no specific target
	void playSpell(std::shared_ptr<Spell> spellPlay);
	// plays the spell card with on a minion
	void playEnchantment(std::shared_ptr<Enchantment> enchant, std::shared_ptr<Card> target);
	// sets the deck for whichever player
	void setDeck(Deck *deck, int player);
	// sets the Grave for whichever player
	void setGrave(Grave *grave, int player); 
	// activates any ability that triggers when a minion enters play
	void minionPlayed(std::shared_ptr<Minion> minionPlay);
};

std::ostream &operator<<(std::ostream &out, const Board &b);

#endif
