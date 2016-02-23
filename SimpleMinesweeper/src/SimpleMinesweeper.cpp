//============================================================================
// Name        : SimpleMinesweeper.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : April 2015
// Description : Minesweeper game, no GUI
//============================================================================

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

class game {
private:
	vector<vector<bool> > values;
	vector<vector<string> > display;
	int maxHorizontal;
	int maxVertical;
	int maxInput();
	void mineGenerate();
	void populateDisplay();
	void randomSelect();
	void autoFill();
	void showMines();
	int nearMines(int, int);
	void updateDisplay(int, int, int);
public:
	game(int);
	void checkForMine(int, int);
	void refresh();
	void clear();
};
game::game(int size) {
	maxHorizontal = size;
	maxVertical = size;
	game::autoFill();
	game::mineGenerate();
}
//returns max number of inputs
int game::maxInput() {
	return maxHorizontal * maxVertical;
}

//fills value vector with possible mines, copies them to display
void game::mineGenerate() {
	game::randomSelect(); //places mines
	game::populateDisplay(); //re-populate the display
}

//populates mine stream with mines
void game::randomSelect() {
	srand(time(NULL));
	int count = game::maxInput() / 3; //mines limited to a third of the total slots
	for (int i = 0; i < maxVertical; i++) {
		for (int j = 0; j < maxHorizontal; j++) {
			float chance = rand() % 3; //1/4 chance of being a mine...number can be a variable in the future
			round(chance);
			//cout << "mine: " << chance << endl; //debug
			if (chance == 1) {
				values[i][j] = true;
				count--;
			}
			if (count == 0) {	//sets a maximum number of mines
				break;
			}
			//cout << values[i][j]; //debug
		}
	}
	cout << endl;
}
//populates display vector with mines if chosen
void game::populateDisplay() {
	for (int i = 0; i < maxVertical; i++) {
		for (int j = 0; j < maxHorizontal; j++) {
			display[i][j] = "\t-";
		}
	}
}
//generate a vector of all false values
void game::autoFill() {
	for (int i = 0; i < maxVertical; i++) {
		vector<string> row;
		vector<bool> row2;
		for (int j = 0; j < maxHorizontal; j++) {
			row.push_back("\t-");
			row2.push_back(false);
		}
		display.push_back(row);
		values.push_back(row2);
	}
	cout << endl;
}

//Display of current game stat
void game::refresh() {
	for (int i = 0; i < maxVertical; i++) {
		for (int j = 0; j < maxHorizontal; j++) {
			cout << display[i][j];
		}
		cout << endl << endl;
	}
}

//move the cursor down five spaces
void game::clear() {
	for (int i = 0; i < 5; i++) {
		cout << endl;
	}
}

void game::showMines() {
	for (int i = 0; i < maxHorizontal; i++) {
		for (int j = 0; j < maxVertical; j++) {
			if (values[i][j] == true) {
				display[i][j] = "\t*";
			}
		}
		cout << endl;
	}
}
//check for mine and refresh the screen
void game::checkForMine(int col, int row) {
	row -= 1;
	col -= 1; //makes searching in a 1-base grid
	if (row >= 0 && col >= 0 && values[row][col] == true) {
		cout << endl << "Game over. You landed on a mine";
		game::showMines();
		game::refresh();
		exit(0);
	} else {
		game::clear();
		//slowly add to the list by uncovering the save zones:
		game::updateDisplay(row, col, game::nearMines(row, col));
		game::updateDisplay(row - 1, col, game::nearMines(row - 1, col));
		game::updateDisplay(row - 1, col + 1,
				game::nearMines(row - 1, col + 1));
		game::updateDisplay(row - 1, col - 1,
				game::nearMines(row - 1, col - 1));
		game::updateDisplay(row, col + 1, game::nearMines(row, col + 1));
		game::updateDisplay(row, col - 1, game::nearMines(row, col - 1));
		game::updateDisplay(row + 1, col, game::nearMines(row + 1, col));
		game::updateDisplay(row + 1, col + 1,
				game::nearMines(row + 1, col + 1));
		game::updateDisplay(row + 1, col - 1,
				game::nearMines(row + 1, col - 1));
		game::refresh();
	}
}
void game::updateDisplay(int col, int row, int num) {
	if (row >= 0 && col >= 0 && row <= maxHorizontal - 1
			&& col <= maxVertical - 1) {
		if (values[row][col] == false) {
			string displaySlot;
			ostringstream convert;
			convert << '\t' << num;
			displaySlot = convert.str();
			display[col][row] = displaySlot;
		}
	}
}
int game::nearMines(int col, int row) {
	int mines = 0;
	if (row > 0 && col >= 0 && values[row - 1][col] == true)
		mines++;
	if ((row > 0) && col < maxVertical - 1
			&& (values[row - 1][col + 1] == true))
		mines++;
	if ((row >= 0 && col < (maxVertical - 1)) && row < maxHorizontal
			&& (values[row][col + 1] == true))
		mines++;
	if ((row < (maxHorizontal - 1)) && (col < (maxVertical - 1))
			&& (values[row + 1][col + 1] == true))
		mines++;
	if ((col >= 0 && row < (maxHorizontal - 1))
			&& (values[row + 1][col] == true))
		mines++;
	if ((row < (maxHorizontal - 1)) && (col > 0)
			&& (values[row + 1][col - 1] == true))
		mines++;
	if (row >= 0 && col > 0 && row < maxHorizontal
			&& values[row][col - 1] == true)
		mines++;
	if ((col > 0) && (row > 0) && (values[row - 1][col - 1] == true))
		mines++;
	return mines;
}

int main() {
	int input;
	cout
			<< "Enter you wish to play with, then enter coordinates seperated by a space"
			<< endl;
	cin >> input;
	game newGame(input); //set up defaults
	newGame.refresh(); //show blank square
	newGame.clear(); //space increment
	int row, col;
	do {
		cin >> row >> col;
		newGame.checkForMine(col, row);
		cout<<": ";
	} while (row > 0 && row <= input && col > 0 && col <= input);
	return 0;
}
