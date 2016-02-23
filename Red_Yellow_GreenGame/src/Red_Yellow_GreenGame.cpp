//============================================================================
// Name        : Red_Yellow_GreenGame.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : Feb 2015
// Description : Red Yellow Green Game, The color game that uses vectors
				//classes and operator digit spits. Functions using nested
				//for loops and integer comparitors.
//============================================================================

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
using namespace std;

int generateNum();
vector<int> digitSplit(int);

class Comparitor {
private:
	vector<int> randomNum, guess;
	int red, yellow, green;
public:
	Comparitor(vector<int>, vector<int>);
	void compare();
	int getRed();
	int getYellow();
	int getGreen();
	void setColors(int, int, int);
};

Comparitor::Comparitor(vector<int> ranN, vector<int> userN) {
	randomNum = ranN;
	guess = userN;
}
int Comparitor::getGreen() {
	int g = green;
	return g;
}
int Comparitor::getRed() {
	int r = red;
	return r;
}
int Comparitor::getYellow() {
	int y = yellow;
	return y;
}
void Comparitor::setColors(int g, int y, int r) {
	green = g;
	yellow = y;
	red = r;
}

void Comparitor::compare() {
	//check for greens
	for (int i = 0; i < 3; i++) {
		if (randomNum[i] == guess[i]) {
			green++;
			guess[i]=-1;
			randomNum[i]=-2;
		}
	}
//check for yellow

	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){ //super efficiency inspired by Jon
			if (guess[i]==randomNum[j]) yellow ++;
		}
	}
//remainder is red

	red = 3 - (green + yellow);
}
int green, yellow, red;
int main() {
	int numToCheck;
	char cmd;
	int ranNum = generateNum(); //Saves random number
	cout << ranNum << endl;
	while (cmd != 'Q') {
		cout << "Please enter a guess\n";
		cin >> numToCheck;

		while (numToCheck < 100 || numToCheck > 999) {
			cout << "Error: number is too low. Enter New Guess\n";
			cin >> numToCheck;
		}

		vector<int> randomNum = digitSplit(ranNum); //splits random number into digits
		vector<int> guess = digitSplit(numToCheck); //splits guess into digits

		Comparitor attempt(randomNum, guess);
		attempt.setColors(0, 0, 0);
		attempt.compare();
		green = attempt.getGreen();
		red = attempt.getRed();		//
		yellow = attempt.getYellow();
		cout << "Green: " << green;
		cout << "\tYellow: " << yellow;
		cout << "\tRed: " << red << endl;
		if (green == 3) {
			cmd = 'Q';
			cout << "Congratulations! You have guessed the number\n";
		}
	}
	return 0;
}

//Generates random numbers
int generateNum() {
	srand(time(NULL));
	int ranNum = rand() % 900 + 100;
	return ranNum;
}
//Splits using operators
vector<int> digitSplit(int input) {
	vector<int> num;

	while (input > 0) {
		int digit = input % 10; //numbers will be in reverse
		num.push_back(digit);
		input /= 10;
	}
	return num;
}
