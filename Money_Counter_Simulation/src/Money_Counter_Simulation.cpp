//============================================================================
// Name        : Money_Counter_Simulation.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : January 2015
// Description : Money Counter Program, program handles classes and operator
//				 overload
//============================================================================

#include <iostream>
using namespace std;

class Counter {
private:
	int total, maxVal;
public:
	Counter();
	Counter(int num, int max) {total = num; maxVal = max;}
	//friend Counter operator+(Counter&, int); //operator overload using friend
	Counter operator+(int input) {
		Counter temp(this->total + input, this->maxVal); //operator overload...no friend
		return temp;
	}
	void checkTheOverFlow();
	void printMax(){cout<<"Maximum value of the counter is: "<<maxVal<<endl;}
	void printTotal(){cout<<"Current value of the counter is: "<<total<<endl;}
};
//default constructor
Counter::Counter() {
	total = 0;
	maxVal = 9999;
}

/* Counter operator+(Counter& a, int input){ //operator overload
 return Counter(a.total + input, a.maxVal);
 }*/

void Counter::checkTheOverFlow() {
	if (total > maxVal)
		cout << "The was and OverFlow!\n";
	else
		cout << "There was no OverFlow\n";
}
int main() {
	char id;
	int val;

	Counter counter; //creating new counter object!!!

	cout<< "\nEnter a Key, either a, s, d, f, followed by 1-9. or o for Overflow\n";
	while (id != 'q') {
		cin >> id;
		switch (id) {
		case 'a':
			cin >> val;
			counter = counter + (1 * val);
			break;
		case 's':
			cin >> val;
			counter = counter + (10 * val);
			break;
		case 'd':
			cin >> val;
			counter = counter + (100 * val);
			break;
		case 'f':
			cin >> val;
			counter = counter + (1000 * val);
			break;
		case 'o':
			counter.checkTheOverFlow();
			break;
		}
	}
	cout<<"Enter a new maximum counter\n";
	cin>>val;
	Counter nextCounter(0,val);
	nextCounter.printMax();
	nextCounter.printTotal();
	return 0;
}
