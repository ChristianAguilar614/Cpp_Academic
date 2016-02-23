/*
 * Player.h
 *
 *  Created on: Apr 27, 2015
 *      Author: christian
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <map>
#include <vector>
#include <string>

using namespace std;
class Player {
private:
	multimap<int,string> daHand;
	multimap<int,string> recieveHand(multimap< int, string >);
	int checkDaHandForPoints();
public:
	Player(multimap<int,string>);
	int points;
	void willFold();
	void willReplace(int, int=0,int=0,int=0,int=0);
	void willWager(int);
	void setPoints();

};

#endif /* PLAYER_H_ */
