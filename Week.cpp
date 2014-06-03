#include <iostream>
#include <fstream>
#include <string>
#include "Week.h"

using namespace std;

void Week::decideWeekOrMonth() {
	char c;
	cout << "View for entire week or month?(w/m)" << endl;
	cin >> c;
	if (c == 'w')
		week();
	else if (c == 'm')
		month();
	else
		cout << "Please enter a correct letter" << endl;
}

void Week::week() {
	try {
		string weekNumber;
		string str;
		cout << "Enter the 2-digit week number:" << endl;
		cin >> weekNumber;
		//read record file, and find records with correct week number
		fstream f;
		f.open("records.txt", fstream::in);
		while (getline(f, str)) {
			if (str.find(weekNumber, 8))
				cout << str << endl;
		}
		f.close();
	}
	catch (exception e) {
		e.what();
	}
}

void Week::month() {
	try{
		cout << "Enter the 2-digit month number:" << endl;
		string month;
		cin >> month;
		fstream f;
		string str;
		int counter = 0;
		f.open("records.txt", fstream::in);
		while (getline(f, str)) {
			if (str.find(month, 0)) {
				cout << str << endl;
				counter++;
			}
		}
		if (counter == 0)
			cout << "No matching record found" << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}