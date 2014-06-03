#include "Remove.h"
#include "Search.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Search::search() {
	string input;
	cout << "Enter the day or week" << endl;
	cin >> input;

	try {
		int counter = 0;
		fstream f;
		std::string str = "";
		f.open("records.txt",fstream::in);
		while (getline(f, str)) {
			if (str.find(input,0)) {
				counter++;
				cout << str << endl;
			}
		}
		if (counter == 0) {
			cout << "No records found" << endl;
		}
		f.close();
	}
	catch (exception e) {
		e.what();
	}
}