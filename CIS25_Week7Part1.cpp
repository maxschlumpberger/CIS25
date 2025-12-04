// CIS25_Week7Part1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int main()
{
	int userChoice = 0;
	
	bool exit = false;
	do {
		cout << "Options:" << endl << "1. Add item to display " << endl << "2. View display " << endl << "3. Exit " << endl;

		cin >> userChoice;

		if (userChoice == 1) {
			cout << "Your item was added! Press 1 to add another item! " << endl;
		}
		else if (userChoice == 2) {
			cout << "Items are being displayed..." << endl;
		}
		else if (userChoice == 3) {
			cout << "Exiting..." << endl;
			exit = true;
		}
		else {
			cout << "Your input is invalid, please try again (Enter 1, 2, or 3). " << endl;
		}
	} while (exit == false);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
