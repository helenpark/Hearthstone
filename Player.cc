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
            //int len = myHand.size();
            //cout << "This is hand:" << len << " "<< endl;
            //(myHand[len-1])->print();
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
    	if (useMagic(myHand[i-1]->getCost())) {
			string type = myHand[i-1]->getType();
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
		} else {
			cout << "Not enough magic to play this card!" << endl;
		}
    }
    else {
        cout << "You don't have this card!" << endl;
    }
}

// overloaded play, plays the ith card on card t owned by player p
void Player::play (int i, int p, int t) {
	 if (hasCard(i)) {
		 // check if you can afford to play
		 if (useMagic(myHand[i]->cost)) {

			// TODO: implement this!









		 } else {
			cout << "Not enough magic to play this card!" << endl;
		 }
	 } else {
	 	 cout << "You don't have this card!" << endl;
	 }
}


//subtract HP when hit -> return remaining hp
int Player::getHit(int AP) {
	HP = HP - AP;
	return HP;
}



//use ith minion owned by the player
void Player::use(int i){
	int len = myBoard->minionSlots.size();
	if (len == 0) {
		cout << "You have no minions in play right now" << endl;
	}
	if (i < 1 || i > len) {
		cout << "need to pick a number between 1 and " << len << endl;
	}
	if (myBoard->minionSlots[i-1]->ability->name == "Apprentice Summoner") {
		if (myBoard->minionSlots.size() ==  5) {
			cout << "Can't summon any more Air Elementals to the board" << endl;
			return;
		}
		myBoard->minionSlots[i-1]->ability->apprenticeSummoner(myBoard);
	}
	else if (myBoard->minionSlots[i-1]->ability->name == "Master Summoner") {
		if (myBoard->minionSlots.size() == 5) {
			cout <<  "Can't summon any more Air Elementals to the board" << endl;
			return;
		}
		myBoard->minionSlots[i-1]->ability->masterSummoner(myBoard);
	} else if (myBoard->minionSlots[i-1]->ability->name == "Shield Pierce") {
		myBoard->minionSlots[i-1]->ability->shieldPierce(opponent, myBoard->minionSlots[i]->AP);
	} else {
		cout << "This minion can't use this type of ability" << endl;
	}
}

//use ith minions ability on whichever target
void Player::use(int i, Player *p, int t) {
	cout << "4 "; 
	int len = myBoard->minionSlots.size();
	if (len == 0) {
		cout << "You have no minions in play right now" << endl;
	}
	cout << "5 "; 
	if (i < 1 || i > len) {
		cout << "6 "; 
		cout << "need to pick a number between 1 and " << len << endl;
	} else if (myBoard->minionSlots[i-1]->ability->name == "Novice Pyromancer") {
		if (t == -1) { // target ritual
			cout << "Novice Pyromancer ability only applies to a minion!" << endl;
		} else { // target minion
			myBoard->minionSlots[i-1]->ability->fireElemental(p->myBoard->minionSlots[t-1]); 
		}
	} else {
		cout << "This minion can't use this type of ability" << endl;
	}
	
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
vector<string> display_Ritual_Player_Grave(shared_ptr<Card> rp, vector<string> p1,
                                           shared_ptr<Board> b) {
    vector<string> display;
    vector<string> r,g;
    if (rp) {
        r = rp->getAscii();
    }else {
        r = CARD_TEMPLATE_BORDER;
    }

    if (b->grave.empty()) {
        g = CARD_TEMPLATE_BORDER;
    }
    else {
        g = b->top()->getAscii();
    }
    for (int i=0; i<11; i++) {
        string line;
        line += r[i];
        line += CARD_TEMPLATE_BORDER[i];
        line += p1[i];
        line += CARD_TEMPLATE_BORDER[i];
        line += g[i];
        display.emplace_back(line);
    }
    return display;
}

vector<string> displayRow (vector<shared_ptr<Minion>> msg) {
    int i = 0;
    int j = msg.size();

        vector<string> display;
        vector <vector<string>> displayHand;
        int len = 11;

        while (i<j) {
            displayHand.emplace_back(msg[i]->getAscii());
            ++i;
        }
        while (i!=5) {
             displayHand.emplace_back(CARD_TEMPLATE_BORDER);
             ++i;
        }

        for (int m=0; m<len; m++) {
            string line;
            for (int b=0; b<5; b++) {
                line += displayHand[b][m];
            }
            display.emplace_back(line);
        }

    return display;
}

vector<string> displayRow (vector<shared_ptr<Card>> msg) {
    int i = 0;
    int j = msg.size();

        vector<string> display;
        vector <vector<string>> displayHand;
        int len = 11;

        while (i<j) {
            displayHand.emplace_back(msg[i]->getAscii());
            ++i;
        }
        while (i!=5) {
             displayHand.emplace_back(CARD_TEMPLATE_BORDER);
             ++i;
        }

        for (int m=0; m<len; m++) {
            string line;
            for (int b=0; b<5; b++) {
                line += displayHand[b][m];
            }
            display.emplace_back(line);
        }

    return display;
}
//display the hand
void Player::hand (){
    int j = myHand.size();
    if (j!=0) {
        vector<string> display = displayRow(myHand);
        print(display);
    } else {
        cout << "You don't have any cards on your hand.\n";
    }
}
//display the board
void Player::board(int i){
    if (i==1){ //display player1's board
        vector<string> p = display_player_card(num,name,HP,MP);
        //display grave
        print(display_Ritual_Player_Grave(myBoard->myRitual,p,myBoard));
        //display minions
        print(displayRow(myBoard->minionSlots));

    }
    else if (i==2){ //display player2's board
         //display minions
        print(displayRow(myBoard->minionSlots));
        vector<string> p = display_player_card(num,name,HP,MP);
        //display grave
        print(display_Ritual_Player_Grave(myBoard->myRitual,p,myBoard));
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
	cout << "ML : " << ML << endl;
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

bool Player::useMagic(int cost) {
	if (ML >= cost) {
		ML = ML - cost;
		cout << "new ML = " << ML << endl;
		return true;
	} else {
		return false;
	}
}




