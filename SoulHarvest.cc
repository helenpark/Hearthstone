#include "Board.h"
#include "SoulHarvest.h"
using namespace std;

SoulHarvest::SoulHarvest(int p):Ritual{"Soul Harvest", 3, "Whenever a minion dies, the player that owns this ritual gains 2 HP", p, 2, 4}{}

void SoulHarvest::activate(Player *player, shared_ptr<Board> board, shared_ptr<Minion> minion) {
	player->HP += 2;
}
