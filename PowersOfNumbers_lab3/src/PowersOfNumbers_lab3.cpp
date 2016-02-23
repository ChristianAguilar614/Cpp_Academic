//============================================================================
// Name        : PowersOfNumbers_lab3.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : Feb 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int Powers(int, int = 2);
double Powers(double, int = 2);
float Powers(float, int = 2);
long double Powers(long double, int = 2);

int main() {
		float num;
		int power;
		int count = 1;
		while (count < 5) {
		cout<<"What number would you like to work with? ";
		cin>>num;

		cout<<"What power would you like to raise it to? ";
		cin>>power;
		switch(count){
		case 1:
			cout<<endl<<Powers((double)num, power)<<endl; break;
		case 2:
			cout<<endl<<Powers(num, power)<<endl; break;
		case 3:
			cout<<endl<<Powers((int)num, power)<<endl; break;
		case 4:
			cout<<endl<<Powers((long double)num, power)<<endl;
			cout<<"Whats your last number? ";
			cin>>num;
			cout<<endl<<Powers((int)num)<<endl; break;
		}
		count++;
	}
	return 0;
}
int Powers(int num, int power){
	int temp;
	temp = 1;
	for (int i = 0; i < power; i++){
		temp*=num;
	}
	return temp;
}

double Powers(double num, int power){
	double temp;
	temp = 1.0;
	for (int i = 0; i < power; i++) {
		temp*=num;
	}
	return temp;
}

float Powers(float num, int power) {
	float temp;
	temp = 1.0;
	for (int i = 0; i < power; i++) {
		temp*=num;
	}
	return temp;
}

long double Powers(long double num, int power){
	long double temp;
	temp = 1;
		for (int i = 0; i < power; i++) {
		temp*=num;
	}
		return temp;
}
