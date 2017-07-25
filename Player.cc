#include "Player.h"
#include "Card.h"
//#include "Ability.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <memory>
#include "ascii_graphics.h"
#include "print.h"

#include "banish.h"

using namespace std;

bool testing = true;

/*
void print(vector<string> display) {
    int a = display.size();
    for (int i=0; i<a; ++i) {
        string line = display[i];
        cout << line << endl;
    }
}
*/

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
        cout << "now you only have " << myHand.size() << " cards left\n";
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
        shared_ptr<Card> t = myHand[i-1];
        if (type=="Ritual") {
            myBoard->placeRitual(t);
            discard(i);
        }
        else if(type=="Minion") {
            myBoard->placeMinion(t);
            minionPlayed(static_pointer_cast<Minion>(myHand[i-1]));
            discard(i);
        }
        else if (type=="Spell") {
            try {
                (static_pointer_cast<Spell>(myHand[i-1]))->cast(myBoard,nullptr,opponent->myBoard);
                 discard(i);
            }
            catch (string msg) {
                cout << msg << endl;
            }
        }

    }
    else {
        cout << "You don't have this card!" << endl;
    }
}

// overloaded play, plays the ith card on card t owned by player p
void Player::play (int i, int p, int t) {}


//subtract HP when hit -> return remaining hp
int Player::getHit(int AP) {
	HP = HP - AP;
	return HP;
}



//use ith minion owned by the player
void Player::use(int i){
}
//inspect ith minion owned
void Player::inspect(int i){
    int numOfMinions = myBoard->minionSlots.size();
    if (i<1 || i>numOfMinions) {
        cout << "You don't have this minion.\n";
    }
    else {
        myBoard->minionSlots[i-1]->print();
    }
}
//display the hand
void Player::hand (){
     for(vector<int>::size_type i = 0; i != myHand.size(); i++) {
         (myHand[i]->print());
    }
}
//display the board
void Player::board(int i){
    if (i==1){ //display player1's board
        cout << "Ritual: " <<endl;
        if (myBoard->myRitual) {
            myBoard->myRitual->print();
        }
        cout << "___________________" << endl;
        vector<string> display = display_player_card(num,name,HP,MP);
        print(display);

        cout << "Graveyard: " << endl;
        if (!myBoard->grave.empty()) {
            myBoard->top()->print();
        }
        cout << "___________________" << endl;
        cout << "Minion Slots" << endl;
        int numOfMinions = myBoard->minionSlots.size();
        for (int i=0; i<numOfMinions; ++i) {
            myBoard->minionSlots[i]->print();
        }

    }
    else if (i==2){ //display player2's board

        cout << "Minion Slots" << endl;
        int numOfMinions = myBoard->minionSlots.size();
        for (int i=0; i<numOfMinions; ++i) {
            myBoard->minionSlots[i]->print();
        }
          cout << "___________________" << endl;
         cout << "Ritual: " <<endl;
        if (myBoard->myRitual) {
            myBoard->myRitual->print();
        }
        cout << "___________________" << endl;
        vector<string> display = display_player_card(num,name,HP,MP);
        print(display);
        cout << "Graveyard: " << endl;
        if (!myBoard->grave.empty()) {
            myBoard->top()->print();
        }


    }
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
			myBoard->myRitual->activate(nullptr, opponent->myBoard, minion);
		}
	}
	if (opponent->myBoard->myRitual) {
		if (opponent->myBoard->myRitual->getName() == "Standstill") {
			opponent->myBoard->myRitual->activate(nullptr, opponent->myBoard, minion);
			opponent->myBoard->myRitual->activate(nullptr, myBoard, minion);
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

void Player::winGame() {
	cout << " ********** GAME OVER ********** " << endl;
	cout << "  WINNER: "<< name << endl;
}




