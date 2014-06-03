#include "AddEntry.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void AddEntry::add() {
	string str;
	cout << "Follow the format as:MMDDYYYY,WN,Monday,0800-1350,Dental\nNW-Week Number";
	
	try{
		ofstream myfile;
		myfile.open("records.txt", ios::out, ios::app);
		cin >> str;
		//Needs a new line
		myfile.close();
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

