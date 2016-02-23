//============================================================================
// Name        : CPP_Dictionary.cpp
// Author      : Christian Aguilar
// Version     : 1
// Copyright   : April 2015
// Description : Dictionary program that utilizes the power of the "map" and
//				 'set' functions.
//============================================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <unistd.h>
using namespace std;

void commandLoop(char);

class Dictionary {
private:
	int idx;
	map<string,int> importFile();
	map<string,int> Words;
	map<string,int> Words2;
	void wordSort();
	//void removeCopies 	//only if the map command doesn't ignore the copies
public:
	Dictionary();
	void dispLeWords();
	void addNewWord(string);
	void deleteWord(string);
	void findLeWord(string);
};

Dictionary::Dictionary(){
	Words = Dictionary::importFile();
}

//Imports dictionary and saves into a map
map<string,int> Dictionary::importFile(){
	string line;
	idx = 0;
	map<string, int> Entry;
	ifstream dictionary;
	dictionary.open("Dictionary.txt");
	while(dictionary.good()){
		getline(dictionary, line);
		line.erase(remove(line.begin(), line.end(), '\r'),line.end());
		line.erase(remove(line.begin(), line.end(), '\n'),line.end());
		transform(line.begin(),line.end(),line.begin(), ::tolower); //to lower case
		Entry[line] = idx;		//map index is associated to when it was read in
		idx++;
	}
	if(dictionary.fail()){
		cout<<"Error opening file";
	}
	dictionary.close();
	return Entry;
}

//Adds new word to list
void Dictionary::addNewWord(string newWord){
	transform(newWord.begin(),newWord.end(),newWord.begin(), ::tolower); //to lower case
	if(Words.count(newWord)==0){
		Words[newWord] = idx++;
		cout<<"Word Successfully Added\n";
	}else cout<<"Word already exists in our database\n";
}

//Deletes desired word
void Dictionary::deleteWord(string word){
	if(Words.count(word)!=0){
		Words.erase(Words.find(word));
		cout<<"Word Successfully Deleted :)"<<endl;
	}else cout<<"Cannot delete what is not there :(\n";
}

//Find word to check
void Dictionary::findLeWord(string word){
	if(Words.count(word)!=0){ //counts the number of occurrences. Maps should be unique
		cout<<"Word is located in our database\n";
	}
	else cout<<"No such word!\n";
}

//Display list of words:
void Dictionary::dispLeWords(){
	map<string,int>::iterator loc;
	int count=0;
	for(loc = Words.begin(); loc != Words.end(); ++loc){
		usleep(10000);
		cout<<loc->first<<endl;
		count++;
	}
	cout<<endl<<"Number of entries found: "<<count<<endl;
}


void commandLoop(char cmd){
	Dictionary Entries; //Sets up Dictionary Class with pre-loaded "sorted" Entries
	string word;
	cout<<"Enter desired command\n a: add\t\t d: display\n e: erase\t f: find\n r: resort\t s: sort\n";
	//cin>>cmd;
	while(cmd != 'q'){
			switch(cmd){
			case 'a':
				cout<<"Initiating new entry protocol";
				cout<<'.'; cout<<'.'; cout<<'.';
				cout<<"\nEnter new Entry\n";
				cin>>word;
				Entries.addNewWord(word);
				cin>>cmd;
				break;
			case 'd':
				cout<<"Starting display protocol ... One moment";
				cout<<'.'; cout<<'.'; cout<<'.';
				sleep(1); cout<<"\nComplete.\n";
				Entries.dispLeWords();
				cin>>cmd;
				break;
			case 'e':
				cout<<"Delete protocol... Please word you wish to erase\n";
				cin>>word;
				Entries.deleteWord(word);
				cin>>cmd;
				break;
			case 'f':
				cout<<"What should I find for you my master?\n";
				cin>>word;
				Entries.findLeWord(word);
				cin>>cmd;
				break;
			case 'r':
				cout<<"Re-Sort. \n";
				cin>>cmd;
				break;
			case 's':
				cout<<"...Now Sorting. \n";
				cin>>cmd;
				break;
			}
		}
}

int main() {
	char cmd = 'd';
	commandLoop(cmd);
	cout<<"Successfully quit the program. Have a nice day :D";
	return 0;
}
