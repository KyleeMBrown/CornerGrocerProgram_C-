#include<iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "GroceryList.h"

// member functions below

// function to add items to both unique and non unique lists
void Grocerylist::addItem(int itemId, string item){

	groceryItemList.emplace(itemId, item); // populate with ALL values (non-unuique)
	uniqueGroceryItemList.emplace(item, itemId); // populate with unique values
}

// function to create a file for to store information for backup
void Grocerylist::createOutputFile(){
	ofstream outFS; // output file stream

	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "Could not open frequency.dat" << endl;
	}

	for (auto item : uniqueGroceryItemList) { // iterate through unique list
		outFS << item.first << " " << getItemCount(item.first) << endl; // output the first value of the unique list (the item) and the item count of that value
	}
	outFS.close();
}

// function to get the frequency of a word
int Grocerylist::getItemCount(std::string word){
	int itemCount = 0; // for tracking word frequencies

	// use range-based for loop -- use auto to decide data type on compiile time
	for (auto item : groceryItemList) { // iterate through the list of All items
		if (item.second == word) {
			++itemCount; // increment the item count when duplicates of the word appear
		}
	}
	return itemCount; // return the final word count
}

// function to list the words and their frequencies
void Grocerylist::printListFreq(){
	// use range-based for loop -- use auto to decide data type on compiile time
	for (auto item : uniqueGroceryItemList) { // iterate through unique list
		cout << item.first << " " << getItemCount(item.first) << endl; // output the first value of the unique list (the item) and the item count of that value
	}
}

// function to list the words and their frequencies as a Histogram
void Grocerylist::printListHistogram(){
	int itemCount; // to hold frequency of the word
	// use range-based for loop -- use auto to decide data type on compiile time
	for (auto item : uniqueGroceryItemList) {  // iterate through unique list
		itemCount = getItemCount(item.first); // assign value from getItemCount() to itemCount
		cout << item.first << " ";  // output the first value of the unique list (wich is the item)
		cout << setfill('*') << setw(itemCount + 1) << " " << endl; // output the item count of that value in the form of a histogram // use itemCount + 1 because setw was originally 1 astric off due to whitespace

	}
}


