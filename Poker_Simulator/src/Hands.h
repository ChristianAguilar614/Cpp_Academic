/*
 * Hands.h
 *
 *  Created on: Apr 27, 2015
 *      Author: christian
 */

#ifndef HANDS_H_
#define HANDS_H_
#include <map>
#include <string>

using namespace std;
class Hands {
private:
	multimap<int,string> playerHand;
	//int points;
public:
	int points;
	Hands(multimap<int,string>);
	bool isRoyalFlush();
	bool isStraightFlush();
	bool fourOfAKind();
	bool fullHouse();
	bool Flush();
	bool Straight();
	bool threeOfAKind();
	bool twoPair();
	bool onePair();
	int highCard(); // possibly be ignored for the sake of time
};

#endif /* HANDS_H_ */
