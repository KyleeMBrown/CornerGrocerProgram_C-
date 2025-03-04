/*
Author: Kylee Brown

Date: 2/27/2025
*/

#include<iostream>
#include "GroceryList.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

// function for displaying menu (options 1-4)
void displayMenu() {
	// output menu options to user
	cout << setfill('-') << setw(28) << " " << endl;
	cout << "Corner Grocer TEXT ANALYZER" << endl;
	cout << setfill('-') << setw(28) << " " << endl;
	cout << setfill(' ');
	cout << "[1] -- Find word frequency" << endl; // find word frequency
	cout << "[2] -- Print all items with frequency" << endl; // print all items witth frequencies
	cout << "[3] -- Print all items with frequency Histogram" << endl; // print all items with frequencies (Histogrm)
	cout << "[4] -- Exit" << endl; // exit the program
}

// function of menu behaviors
void menuBehaviors(int menuNumber, Grocerylist list) {
	string word;// for storing the word the user wants to find the frequency of
	switch (menuNumber) {
		case 1: // find word frequency
			cout << "Enter a word: " << endl;
			cin >> word; // take in and store  word from user 
			cout << endl;
			cout << setfill('-') << setw(28) << " " << endl;
			cout << "Word Frequency: " << endl;
			cout << word << " shows up "  << list.getItemCount(word) << " time(s)" << endl; // output word count to user
			cout << setfill('-') << setw(28) << " " << endl;
			cout << endl;
			break;
		case 2: // print all items and frequencies
			cout << "List Frequencies:" << endl;
			cout << setfill('-') << setw(28) << " " << endl;
			list.printListFreq(); // print items and their frequencies
			cout << endl;
			break;
		case 3: // print all items and frequencies -- histogram
			cout << "List Frequencies (Histogram):" << endl;
			cout << setfill('-') << setw(28) << " " << endl;
			list.printListHistogram(); // print items and their frequencies -- Histogram
			cout << endl;
			break;

		}
}

// read file and populate list -- return gorcery lsit object
Grocerylist readFileAndPopulateList() {
	ifstream inFS; // input file stream
	string fileName = "CS210_Project_Three_Input_File.txt"; // file name of file to analyze
	string item; // for storing each item in list
	unsigned int i = 0; // for storing item id
	Grocerylist list; // list object to return after populating

	inFS.open(fileName); // open the file
	if (!inFS.is_open()) { // file error handeling
		cout << "could not open file" << endl;
	}

	while (!inFS.eof()) { // read until end of file
		inFS >> item;
		if (!inFS.fail()) {
			list.addItem(i, item);// add each item and item id to list object
		}
		++i; // increment item id
	}
	return list;
}

// function to start the main loop and take user input
void loop() {
	int userInput = 0; // for storing user input as an integer
	Grocerylist list; // create a list object to store the newly populated list object returned from reading the file

	list = readFileAndPopulateList(); // read the file and populate items
	list.createOutputFile();


	cin.exceptions(ios_base::failbit);// allow cin to trigger the ios_base::failure exception
	while (true) { // run loop until user enters 4 to exit
		try {
			menuBehaviors(userInput, list); // run menu behaviors
			displayMenu();
			cout << "Enter a Number: " << endl;
			cin >> userInput; // take user input

			if (userInput < 1 || userInput > 4 ) { // input is not #1-4
				throw runtime_error("Error: Invalid Number");
			}
			
			if (userInput == 4) { 
				break; // exit loop when userInput equals 4
			}
	
			cout << endl;
		}
		catch (ios_base::failure& excpt2) { // if input is wrong data type:
			cout << "Input Must be of Type Number" << endl; // output error message
			cout << "Please Try Again" << endl;
		}
		catch (runtime_error& excpt) { // if input is not #1-4
			cout << excpt.what() << endl;
			cout << "Please Try Again" << endl;
			cout << endl;
		}
	
		// clear cin so error does not persist if found
		cin.clear();
		cin.ignore();
	}
}

// main function
void main(){
	loop(); // enter main loop
}