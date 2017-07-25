#ifndef _CARD_H__
#define _CARD_H__
#include <vector>
#include <string>
#include <memory>
#include <utility>
class Player;

class Card { // abstract class
	public:
	std::string name;
	int cost;
	std::string type;
	std::string description;
	int owner; //player1 or player2
	Card(std::string name, int cost, std::string type,
    std::string description,  int p);
	std::string getName();
	std::string getDescription();
	std::string getType();
	int getCost();

    void printCard(std::vector<std::string> display);
    virtual void print();
    virtual std::vector<std::string> getAscii();

    friend std::ostream &operator<<(std::ostream &out, const Card &b);
};

#endif

