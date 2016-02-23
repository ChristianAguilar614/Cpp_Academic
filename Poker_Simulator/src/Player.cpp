/*
 * Player.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: christian
 */

#include "Player.h"
#include "Hands.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

Player::Player(multimap<int,string> hand) {
	//daHand = Player::recieveHand(Deck.createHand());
	daHand = hand;
	points = 0;
}

void Player::willFold(){
	cout<<"Fold."<<endl;
	daHand.clear();
}
void Player::willReplace(int card1, int card2, int card3, int card4, int card5){}
void Player::willWager(int wager){}

int Player::checkDaHandForPoints(){
	Hands checkHand(daHand);
	if(checkHand.isRoyalFlush()){		//Royal Flush
		cout<<"One Royal Flush"<<endl;
		return checkHand.points;
	}

	else if(checkHand.isStraightFlush()){	//Straight Flush
		cout<<"One Straight Flush"<<endl;
		return checkHand.points;
	}

	else if(checkHand.fourOfAKind()){		//Four of a kind
		cout<<"One Four of a Kind"<<endl;
		return checkHand.points;
	}

	else if(checkHand.fullHouse()){			//Full House
		cout<<"1 Full House"<<endl;
		return checkHand.points;
	}

	else if(checkHand.Flush()){				//Flush
		cout<<"1 Flush"<<endl;
		return checkHand.points;
	}

	else if(checkHand.Straight()){			//Straight
		cout<<"1 Straight"<<endl;
		return checkHand.points;
	}

	else if(checkHand.threeOfAKind()){		//Three of a kind
		cout<<"1 Three of a Kind"<<endl;
		return checkHand.points;
	}

	else if (checkHand.twoPair()){			//Two Pair
		cout<<"2 Pairs"<<endl;
		return checkHand.points;
	}

	else if(checkHand.onePair()){			//One Pair
		cout<<"1 Pair"<<endl;
		return checkHand.points;
	}
	return 0;
}

void Player::setPoints(){
	points = Player::checkDaHandForPoints();
	cout<<"With "<<points<<" points"<<endl; //debug

}

