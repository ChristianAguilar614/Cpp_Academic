//============================================================================
// Name        : Poker.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : April 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Player.h"
//#include "Hands.h"
#include <string>
#include <vector>
using namespace std;

int main() {
	multimap<int,string> hand1, hand2;
	//make hands for testing here
	hand1.insert(pair<int,string>(5,"spade"));
	hand1.insert(pair<int,string>(5,"heart"));
	hand1.insert(pair<int,string>(7,"spade"));
	hand1.insert(pair<int,string>(9,"spade"));
	hand1.insert(pair<int,string>(14,"spade"));

	hand2.insert(pair<int,string>(7,"diamond"));
	hand2.insert(pair<int,string>(1,"club"));
	hand2.insert(pair<int,string>(5,"diamond"));
	hand2.insert(pair<int,string>(4,"spade"));
	hand2.insert(pair<int,string>(4,"heart"));
	Player player1(hand1);
	Player player2(hand2);

	player1.setPoints();
	cout<<endl;
	player2.setPoints();

	if(player1.points > player2.points){
		cout<<endl<<"Player 1 wins!"<<endl;
	}
	else if(player1.points < player2.points){
		cout<<endl<<"Player 2 wins!"<<endl;
	}
	else cout<<endl<<"Its a tie!";


	return 0;
}
