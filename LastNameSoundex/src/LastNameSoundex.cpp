//============================================================================
// Name        : LastNameSoundex.cpp
// Author      : Christian Aguilar
// Version     :
// Copyright   : March 2015
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Soundex{
private:
	string lastname;
	string newName;
	int index =0;

public:
	Soundex(string name){lastname=name;}
	char nextConsonant();
	void displayNewName();
	void changeName();
};

char Soundex::nextConsonant(){
	char nextConst;
	for(int i = index; i <= lastname.size(); i++){
		if(lastname[index] != 'a' || lastname[index] != 'A' || lastname[index] != 'e' || lastname[index] != 'E' ||
				lastname[index] != 'i' || lastname[index] != 'I' || lastname[index] != 'o' || lastname[index] != 'O' ||
				lastname[index] != 'u' || lastname[index] != 'U' || lastname[index] != 'y' || lastname[index] != 'Y'){

			/*if( lastname[index] == 'b' || lastname[index] == 'f' || lastname[index] == 'p' || lastname[index] == 'v' ||
					lastname[index] == 'B' || lastname[index] == 'F' || lastname[index] == 'P' || lastname[index] == 'V'){
				lastname[index] = '1';
			}
			else if(lastname[index] == 'c' || lastname[index] == 'g' || lastname[index] == 'j' || lastname[index] == 'k' ||
					lastname[index] == 'q' || lastname[index] == 's' || lastname[index] == 'x' || lastname[index] == 'z' ||
					lastname[index] == 'C' || lastname[index] == 'G' || lastname[index] == 'J' || lastname[index] == 'K' ||
					lastname[index] == 'Q' || lastname[index] == 'S' || lastname[index] == 'X' || lastname[index] == 'Z'){
				lastname[index] = '2';
			}
			else if(lastname[index] == 'd' || lastname[index] == 'D' || lastname[index] == 't' || lastname[index] == 'T'){
				lastname[index] = '3';
			}
			else if(lastname[index] == 'l' || lastname[index] == 'L'){
				lastname[index] = '4';
			}
			else if(lastname[index] == 'm' || lastname[index] == 'M' || lastname[index] == 'n' || lastname[index] == 'N'){
				lastname[index] = '5';
			}
			else if(lastname[index] == 'r' || lastname[index] == 'R'){
				lastname[index] = '6';
			}*/
		}
	}
	nextConst = lastname[index];
	return nextConst;
}

void Soundex::changeName(){
	char consLetter = Soundex::nextConsonant();
	if( consLetter == 'b' || consLetter == 'f' || consLetter == 'p' || consLetter == 'v' ||
						consLetter == 'B' || consLetter == 'F' || consLetter == 'P' || consLetter == 'V'){
					lastname[index] = '1';
				}
				else if(consLetter == 'c' || consLetter == 'g' || consLetter == 'j' || consLetter == 'k' ||
						consLetter == 'q' || consLetter == 's' || consLetter == 'x' || consLetter == 'z' ||
						consLetter == 'C' || consLetter == 'G' || consLetter == 'J' || consLetter == 'K' ||
						consLetter == 'Q' || consLetter == 'S' || consLetter == 'X' || consLetter == 'Z'){
					consLetter = '2';
				}
				else if(consLetter == 'd' || consLetter == 'D' || consLetter == 't' || consLetter == 'T'){
					consLetter = '3';
				}
				else if(consLetter == 'l' || consLetter == 'L'){
					consLetter = '4';
				}
				else if(consLetter == 'm' || consLetter == 'M' || consLetter == 'n' || consLetter == 'N'){
					consLetter = '5';
				}
				else if(consLetter == 'r' || consLetter == 'R'){
					consLetter = '6';
				}
}


int main() {

	return 0;
}
