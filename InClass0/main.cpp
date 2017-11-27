//
//  main.cpp
//  InClass0
//
//  Created by Marcel on 11/20/17.
//  Copyright © 2017 Marcel. All rights reserved.
//
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string quoteWords[134];
	string wordsCopy[134];
	fstream myFile("/Users/Marcel/Documents/Docs/College/SBCC/COMSC 140/Inclass0/Inclass0/quotes.txt");
	if (myFile.fail()) {
		cout << "Input File Failed to open" << endl;
		exit(1);
	}
	
	string holder;
	int i = 0;
	while (myFile >> holder) {
		transform(holder.begin(), holder.end(), holder.begin(), ::tolower);
		holder.erase(remove(holder.begin(), holder.end(), '.'), holder.end());
		holder.erase(remove(holder.begin(), holder.end(), ','), holder.end());
		holder.erase(remove(holder.begin(), holder.end(), ';'), holder.end());
		quoteWords[i] = holder;
		wordsCopy[i] = holder;
		i++;
	}
	
	map<string, int> myMap;
	
	int counter = -1;
	for (int i = 0; i < 134; i++){
		holder = quoteWords[i];
		counter++;
		for (int j = i; j < 134; j++) {
			if (holder == quoteWords[j]) {
				counter++;
				quoteWords[j] = 126;
			}
		}
		quoteWords[i] = "0";
		myMap.insert(pair<string, int> (holder, counter));
		counter = -1;
	}
	
	map<string, int>::iterator it;
	
	for (it = myMap.begin(); it != myMap.end(); it++) {
		cout << it -> first << " " << it -> second << endl;
	}
}
