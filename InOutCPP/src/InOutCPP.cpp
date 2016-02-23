//============================================================================
// Name        : InOutCPP.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : January 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define SLEEPING 1
#define WALKING 2
#define BASKETBALL 8

float calCount(string, int, int);

int main() {
	int minutes;
	int weight;
	float calPerMin;
	string activity;
	cout<<"Enter Activity (Cap Lock)\n";
	cin>>activity;
	cout<<"Enter Weight (in pounds)\n";
	cin>>weight;
	cout<<"Enter Time (in minutes)\n";
	cin>>minutes;

	calPerMin = calCount(activity, weight, minutes);
	cout<<calPerMin;
	return 0;
}

float calCount(string activity, int weight, int time){
	float calPerMin = 0;
	if (activity.compare("SLEEPING") == 0){
		calPerMin = (.0175) * SLEEPING * (weight/2.2);
	}
	if (activity.compare("WALKING") == 0){
		calPerMin = (.0175) * WALKING * (weight/2.2);
	}
	if (activity.compare("BASKETBALL") == 0){
		calPerMin = (.0175) * BASKETBALL * (weight/2.2);
	}
	return calPerMin * time;
}
