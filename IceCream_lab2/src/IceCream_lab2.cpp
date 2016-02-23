//============================================================================
// Name        : IceCream_lab2.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : Feb 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void printCone(int, int, int);
float getPrice(int);
void charConeSave(int, int);

char scoop1, scoop2, scoop3, scoop4, scoop5;
#define MAXSCOOPS 5;

int main() {
	char cmd;
	int cones;
	int numScoops;
	int counter;
	float price;

	cout<<"1 Scoop -> $2.00\n2 Scoops -> $3.00\nEach after 2 Scoops -> $.75\n\n";
	while (cmd != 'y' || cmd != 'Y'){
		//Number of cones
		cout<<"Enter number of cones you want, fool ";
		cin>>cones;
		counter = cones;

		//Number of scoops
		cout<<"How many scoops do you want for your first cone? ";
		cin>>numScoops;
		counter--;
		charConeSave(numScoops, cones);
		price = getPrice(numScoops);
		if (counter != 0) {
			cout<<"How many scoops do you want on your next cone? ";
			cin>>numScoops;
			charConeSave(numScoops, cones);
			price = price + getPrice(numScoops);
		}

		//Program Quit
		cout<<"Is that all, sir or mam? [Y]es or [N]o ";
		cin>>cmd;
		if (cmd != 'Y' || cmd != 'y'){
			cout<<"Is that all, sir or mam? [Y]es or [N]o ";
			cin>>cmd;
		}else {
			cout<<"Thank You! Your price is: "<<price;
		}
	}
	return 0;
}

float getPrice(int numScoops){
	float total;
	switch (numScoops) {
	case 1:
		total = 2.00;
		break;
	case 2:
		total = 3.00;
		break;
	case 3:
		total = 3.00 + .75;
		break;
	case 4:
		total = 3.00 + (.75 * 2);
		break;
	case 5:
		total = 3.00 + (.75 * 3);
		break;
	}
	return total;
}
void printCone(int scoop){
	int temp = 0;
	while(temp <= scoop){
		switch(temp){
		case 1:
			cout<<"\n ("<<scoop1<<")\n";
			break;
		case 2:
			cout<<" ("<<scoop2<<")\n";
			break;
		case 3:
			cout<<" ("<<scoop3<<")\n";
			break;
		case 4:
			cout<<" ("<<scoop4<<")\n";
			break;
		case 5:
			cout<<" ("<<scoop5<<")\n";
			break;
		}
		temp++;
	}
	cout<<" \\ / \n";
	cout<<"  |  \n";
	cout<<"Here is your Ice Cream :)\n ";
}

void charConeSave(int numScoops, int cones){
	int temp = cones;
	int tempScoops = numScoops;
	while (numScoops > 0){
	cout<<"Let me know your preferred ACII flavor for cone "<<(temp-cones)+1;
	switch (numScoops){
	case 1:
		cin>>scoop1;
		break;
	case 2:
		cin>>scoop2;
		break;
	case 3:
		cin>>scoop3;
		break;
	case 4:
		cin>>scoop4;
		break;
	case 5:
		cin>>scoop5;
		break;
	}
	numScoops--;
	}
	printCone(tempScoops);
}
