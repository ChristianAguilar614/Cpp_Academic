/*
 * Hands.cpp
 *
 *  Created on: Apr 27, 2015
 *      Author: christian
 */

#include "Hands.h"
#include <map>
#include <string>
#include <vector>
using namespace std;
Hands::Hands(multimap<int, string> hand) {
	playerHand = hand;
	points = 0;
}

bool Hands::isRoyalFlush() {
	int counter = 0;
	vector<string> suites;
	multimap<int, string>::iterator it;

	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		if ((*it).first < 10) { //checks if face cards
			return false; //break?
		}
		suites.push_back((*it).second); //pulls out suites and saves into vector
	}
	counter = 0;
	for (int i = 1; i < 5; i++) {
		if (suites[i].compare(suites[i - 1]) == 0) //verifies that they are suite
			counter++;
	}

	if (counter == 4) {
		points = 10;
		return true;
	}
	return false;
}
bool Hands::isStraightFlush() {
	int counter = 0;
	vector<string> suites; //temporary storage of string suites
	multimap<int, string>::iterator it;
	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		if ((*it).first > 10) { //quits loop as soon as face cards appears
			return false;
		}
		suites.push_back((*it).second); //pulls out suites and saves into vector
	}
	counter = 0;
	for (int i = 1; i < 5; i++) { //checks for same suites, makes a count of them
		if (suites[i].compare(suites[i - 1]) == 0)
			counter++;
	}

	if (counter == 4) {
		points = 9;
		return true;
	}
	return false;
}
bool Hands::fourOfAKind() {
	int counter = 0;
	vector<int> ranks; //temporary storage of string suites
	multimap<int, string>::iterator it;
	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		ranks.push_back((*it).first); //pulls out suites and saves into vector
	}

	for (int i = 1; i < 5; i++) {
		if (ranks[i] == ranks[i - 1]) {
			counter++;
		}else if (counter == 3) { //four of a kind
			points = 8;
			return true;
		}else counter = 0;
	}
	return false;
}
bool Hands::fullHouse() {
	int type1 = 0;
	int type2 = 0;
	vector<int> ranks; //temporary storage of string suites
	multimap<int, string>::iterator it;
	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		ranks.push_back((*it).first); //pulls out suites and saves into vector
	}

	if (ranks[0] == ranks[1]) { //full house has to have pairs on ends
		if(ranks[3] == ranks[4]){
			type1 = 2;
			type2 = 2;
		}
	}
	if (ranks[2] == ranks[1]) //+1 for lower half
		type1++;
	if (ranks[2] == ranks[3]) //+1 for upper half
		type2++;

	//checks for a 3/2 hand of some sort
	if (type1 == 3 && type2 == 2) {
		points = 7;
		return true;
	} else if (type1 == 2 && type2 == 3) {
		points = 7;
		return true;
	}
	return false;
}
bool Hands::Flush() {
	int counter = 0;
	vector<string> suites; //temporary storage of string suites
	multimap<int, string>::iterator it;
	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		suites.push_back((*it).second); //pulls out suites and saves into vector
	}

	for (int i = 1; i < 5; i++) {
		if (suites[i].compare(suites[i - 1]) == 0) {
			counter++;
		}
	}

	if (counter == 4) {
		points = 6;
		return true;
	}
	return false;
}
bool Hands::Straight() {
	int counter = 0;
	vector<int> ranks; //temporary storage of string suites
	multimap<int, string>::iterator it;
	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		ranks.push_back((*it).first); //pulls out ranks and saves into vector
	}

	for (int i = 1; i < 5; i++) {
		if ((ranks[i] - ranks[i - 1]) == 1) {
			counter++;
		} else
			return false;
	}
	if (counter == 4) {
		points = 5;
		return true;
	}
	return false;
}
bool Hands::threeOfAKind() {
	int counter = 0;
	vector<int> ranks; //temporary storage of string suites
	multimap<int, string>::iterator it;
	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		ranks.push_back((*it).first); //pulls out suites and saves into vector
	}

	for (int i = 1; i < 5; i++) {
		if (ranks[i] == ranks[i - 1]) {
			counter++;
		}
	}
	if (counter == 2) {
		points = 4;
		return true;
	}
	return false;
}
bool Hands::twoPair() {
	int pair1 = 0;
	int pair2 = 0;
	vector<int> ranks; //temporary storage of string suites
	multimap<int, string>::iterator it;
	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		ranks.push_back((*it).first); //pulls out suites and saves into vector
	}

	for (int i = 1; i < 5; i++) {
		if (ranks[i] == ranks[i - 1]) {
			pair1++;
			break;
		}
	}
	for (int i = 2; i < 5; i++) {
		if (ranks[i] == ranks[i - 1]) {
			pair2++;
			break;
		}
	}
	if (pair1 == pair2) {
		points = 3;
		return true;
	}
	return false;
}
bool Hands::onePair(){
	int counter = 0;
	vector<int> ranks; //temporary storage of string suites
	multimap<int, string>::iterator it;
	for (it = playerHand.begin(); it != playerHand.end(); it++) {
		ranks.push_back((*it).first); //pulls out suites and saves into vector
	}

	for (int i = 1; i < 5; i++) {
		if (ranks[i] == ranks[i - 1]) {
			counter++;
			break;
		}
	}

	if(counter == 1){
		points = 2;
		return true;
	}
	return false;
}
