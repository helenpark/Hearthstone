#include "Player.h"
#include "Card.h"
//#include "Ability.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <memory>

#include "banish.h"

using namespace std;

bool testing = true;

Player::Player(string name,int n): name{name}, num{n} {

    myDeck = make_shared<Deck> (num);
}

Player::Player() {
    num = 2;
    name = "Boss";
    myDeck = make_shared<Deck> (2);
}

//copy ctor
Player::Player (const Player &other): name{other.name},num{other.num}{
    //myDeck = make_shared<Deck> ();
    cout << "copy ctor called" << endl;
}

//move ctor
Player::Player (Player &&other): name{other.name},num{other.num}{
    cout << "move ctor called" << endl;

}

//copy assignment operator
Player& Player::operator=(const Player &other){
    cout << "copy assign called" << endl;

        name = other.name;
        num = other.num;
        return *this;
}

    //move assignment operator
Player& Player::operator=(Player &&other){
        //delete my own....
cout << "move assign called" << endl;

        //other. = nullptr
        name = other.name;
        num = other.num;
        return *this;
    }

     //dtor
Player::~Player(){}

bool Player::hasCard(int i){
    int temp = myHand.size();

    return !(myHand.empty()|| i-1<0 || i-1>=temp);
}

void Player::drawCard(){
     if (myHand.size()!=5){
         try {
            myHand.emplace_back(myDeck->draw());
            int len = myHand.size();
            cout << "This is hand:" << len << " "<< endl;
            (myHand[len-1])->print();
         } catch(string s) {
             cout << s << endl;
         }
     }
     else {
        cout <<"Your hand is full! You already have 5 cards!"<< endl;
     }

}

void Player::gainMagic(){
    ++MP;
    cout<< "Player " <<name<< " num: " <<num<< " has magic: " << MP<<endl;
}

void Player::discard(int i){
	// nice error messages
	if (i > 5 || i < 1) {
		cout << "You need to pick a number between 1 and 5" << endl;
	}
    if (!hasCard(i)) {
        cout << "Can't give away something you don't have, try something else" << endl;
    }
    else {
        myHand.erase(myHand.begin() + i - 1);
        cout << "now you only have " << myHand.size() << " left\n";
    }
}

// orders minion i to attack the opposing player
void attack (int i){}
// overloaded attack orders minion i to attack opponent's minion j
void attack(int i, int j){}


void Player::play(int i) {

    if (hasCard(i)) {
        string type = myHand[i-1]->getType();
        cout << "my type is: " << type << endl;
        if (type=="Ritual") {
            shared_ptr<Card> t = myHand[i-1];
            myBoard->placeRitual(t);
        }
        else if(type=="Minion") {
            shared_ptr<Card> t = myHand[i-1];
            myBoard->placeMinion(t);
	    minionPlayed(static_pointer_cast<Minion>(myHand[i-1]));
        }
        else if (type=="Spell") {
                // use spell
        }
        discard(i);
    }
    else {
        cout << "You don't have this card!" << endl;
    }
}

//subtract HP when hit -> return remaining hp
int Player::getHit(int AP) {
	HP = HP - AP;
	return HP;
}

// overloaded play, plays the ith card on card t owned by player p
void Player::play (int i, int p, int t) {}

//use ith minion owned by the player
void Player::use(int i){
}
//inspect ith minion owned
void Player::inspect(int i){

}
//display the hand
void Player::hand (){
     for(vector<int>::size_type i = 0; i != myHand.size(); i++) {
         (myHand[i]->print());
    }
}
//display the board
void Player::board(){

}

void Player::turnEnd() {
	cout << "called" << endl;
	int len = myBoard->minionSlots.size();
	for (int i = 0; i < len; i++) {
		if (myBoard->minionSlots[i]->getName() == "Potion Seller"
		    && myBoard->minionSlots[i]->original) {
			myBoard->minionSlots[i]->ability->potionSeller(myBoard);
		}
	}
}

void Player::turnStart() {
	if (myBoard->myRitual) {
		if (myBoard->myRitual->getName() == "Dark Ritual") {
			myBoard->myRitual->activate(this);
		}
	}
}

void Player::minionPlayed(shared_ptr<Minion> minion) {
	if (myBoard->myRitual) {
		if (myBoard->myRitual->getName() == "Aura of Power") {
			myBoard->myRitual->activate(nullptr, nullptr, minion);
		}
		if (myBoard->myRitual->getName() == "Standstill") {
			myBoard->myRitual->activate(nullptr, myBoard, minion);	
		}
	}
	if (opponent->myBoard->myRitual) {
		if (opponent->myBoard->myRitual->getName() == "Standstill") {
			opponent->myBoard->myRitual->activate(nullptr, opponent->myBoard, minion);
		}
	}
	int len = myBoard->minionSlots.size();	
	for (int i = 0; i < len; i++) {
		if (myBoard->minionSlots[i]->getName() == "Fire Elemental"
		    && myBoard->minionSlots[i]->original) {
			myBoard->minionSlots[i]->ability->fireElemental(minion);
		}
	}
}

void Player::minionDied() {
	int len = myBoard->minionSlots.size();
	for (int i = 0; i < len; i++) {
		if (!myBoard->minionSlots[i]->original) {
		}
	}
	 if (myBoard->myRitual->getName() == "") {}
}

void Player::status() {
	cout << "Player : " << name << endl;
	cout << "HP : " << HP << endl;
	cout << "MP : " << MP << endl;
	int len = myBoard->minionSlots.size();
	cout << "Minios played :" << endl;
	for (int i = 0; i < len; i++) {
		cout << "Name : " << myBoard->minionSlots[i]->getName() << endl;
		cout << "DP : " << myBoard->minionSlots[i]->DP << endl;
		cout << "HP : " << myBoard->minionSlots[i]->AP << endl;
	}
	cout << endl;
	if (myBoard->myRitual) {
		cout << "Ritual Played : " << myBoard->myRitual->getName() << endl;
	}
	cout << endl;
}
