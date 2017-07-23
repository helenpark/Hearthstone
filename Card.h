
#ifndef _CARD_H__
#define _CARD_H__
#include <vector>
#include <string>
#include <memory>
#include <utility>
class Player;


class Card { // abstract class

	std::string name;
	int cost;
	std::string type;
	std::string description;
	int owner; //player1 or player2

public:
	Card(std::string name, int cost, std::string type,
    std::string description,  int p);
	std::string getName();  //what's this method for???
	std::string getDescription();
	std::string getType();
	int getCost();

	virtual ~Card()=0;
    friend std::ostream &operator<<(std::ostream &out, const Card &b);
};

#endif


