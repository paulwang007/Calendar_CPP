#include "Remove.h"
#include "Modify.h"
#include "stdio.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void Modify::modify() {
	string oldString, newString;
	cout << "Type the whole record needs to change:"
		"(MMDDYY,WN,Monday,0800-1350,Dental" 
		"WN is week number like 23" << endl;
	cin >> oldString;
	cout << "Type the new record in the same format:" << endl;
	cin >> newString;
	
	try {
		string str;
		fstream file;
		fstream tempFile;
		file.open("records.txt", fstream::in);
		tempFile.open("temp_records.txt", fstream::out, fstream::app);
		while (getline(file, str)) {
			if (oldString != str) {
				cin >> str; //space needs attention
			}
			else {
				cin >> newString;
			}
		}
		tempFile.close();
		file.close();

		// Once everything is complete, delete old file
		std::remove("records.txt");
		// And rename tmp file's name to old file name
		rename("temp_records.txt", "records,txt");
	}
	catch (exception e) {
		e.what();
	}
}