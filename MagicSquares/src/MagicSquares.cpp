//============================================================================
// Name        : MagicSquares.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : March 2015
// Description : Magic Squares in C++
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Square {
private:
	int size;
	vector <vector<int> > square;
	void squareFill();
	void setUp();
public:
	Square(int);
	void display();
};
Square::Square(int input){
	size = input;
	setUp();
}

void Square::setUp() {
	//sets up square
	vector<int> row;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			row.push_back(-1);
		}
		square.push_back(row);
	}
	//Square::display();
}

void Square::squareFill(){
	//Fills Square with Values
	int maxNum = size*size;
	int row = 0;
		int col = (size/2);
		for(int i = 1; i <= maxNum; i ++){ // populates matrix with correct numbers
			square[row][col] = i;
			int curRow = row; //increments according to a pattern
			int curCol = col;

			row-=1;
			col++;

			//checks for edge cases
			if(row < 0){ row=(size-1); }
			if(col > (size-1)){ col = 0; }


			if(square[row][col] != -1){	//occupied
				row = curRow+1;
				col = curCol;
			}
		}
}
void Square::display(){
	//Square::setUp();
	Square::squareFill();
	//int maxNum = size*size;
	cout <<endl;
	for(int row = 0; row < size; row++){
		for(int col = 0; col<size; col++){
			cout<<"\t"<<square[row][col];
			if (col== (size-1))
				cout<<endl;
		}
	}
}

int main() {
	int val;
	cout<<"Welcome\n";
	cout<<"What size of magic square would you like? \n";
	cin>>val;
	cout<<endl;
	Square magic(val);
	magic.display();
	return 0;
}
