#include <iostream>
#include "AddEntry.h"
#include "Remove.h"
#include "Modify.h"
#include "Search.h"
#include "Week.h"

using namespace std;

int main() {
	// TODO Auto-generated method stub
	int input = 0;
	while (input != 6) {
		cout << "Menu"
			"\n1.Add entry in the calendar"
			"\n2.Remove entry from calendar"
			"\n3.Modify entry in the calendar"
			"\n4.View entry by date or keyword"
			"\n5.View calendar for the entire week or month"
			"\n6.Exit"
			<< endl;
		cin >> input;

		if (input == 6) {
			cout << "Exit Program" << endl;
			exit(0);
		}
		else {
			switch (input) {
			case 1:
				//Call Add entry
				AddEntry add;
				add.add();
				break;
			case 2:
				//Call Remove entry
				Remove r;
				r.remove();
				break;
			case 3:
				//Call Modify entry
				Modify m;
				m.modify();
				break;
			case 4:
				//View entry by date or keyword
				Search s;
				s.search();
				break;
			case 5:
				//view entry for week or month
				Week w;
				w.decideWeekOrMonth();
				break;
			default:
				cout << "Please enter number 1-6" << endl;
				break;
			}
		}
	}
	return 0;
}