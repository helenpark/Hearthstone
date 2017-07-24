


#include "Player.h"
//#include "Card.h"
//#include "Ability.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>

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
    int temp = myHand.size();

    if (myHand.empty()|| i<0 || i>=temp) {
        cout << "Can't give away something you don't have, try something else" << endl;
    }
    else {
        myHand.erase(myHand.begin()+i);
        cout << "now you only have " << myHand.size() << " left\n";
    }
}
