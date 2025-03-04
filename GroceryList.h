#pragma once
#ifndef GROCERYLIST_H
#define GROCERYLIST_H


#include <map>
#include <string>
// Class Definition
class Grocerylist {
public:
	//public member functions below
	void addItem(int itemId, std::string item); // function to add item to grocery list
	void createOutputFile();
	int getItemCount(std::string item); // function to get count of item
	void printListFreq(); // function to print ALL words and their frequencies
	void printListHistogram(); // function to print ALL words and their frequencies in the form of a Histogram (*)
private:
	// private data members below
	// declaare map to store ALL
	std::map<int, std::string> groceryItemList; 

	// declare map to store unique items only
	std::map<std::string, int> uniqueGroceryItemList; // swap key and value to create the unique list
};

#endif