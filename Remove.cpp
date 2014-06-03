#include "Remove.h"
#include "stdio.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void Remove::remove() {
	string input;
	cout << "Type the record you wish to remove:(MMDDYYYY,WN,Monday,0800-1350,Dental Appointment)";
	cin >> input;
	//Create a temp file, which later will replace the old file
	try {
		string str = "";
		fstream tempFile;
		fstream file;
		file.open("records.txt", fstream::in);
		tempFile.open("temp_records.txt", fstream::out, fstream::app);
		while (getline(file, str)) {
			if (input != str) {
				cin >> str;
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