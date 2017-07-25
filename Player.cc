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
    //myDeck = make_shared<Deck> ();
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
            cout << *myHand[len-1];
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

    if (!hasCard(i)) {
        cout << "Can't give away something you don't have, try something else" << endl;
    }
    else {
        myHand.erase(myHand.begin()+i-1);
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
void play (int i, int p, int t);

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

/*
    for(vector<int>::size_type i = 0; i != myHand.size(); i++) {

         cout << *(myHand[i]);
    }
*/
}
//display the board
void Player::board(){

}


