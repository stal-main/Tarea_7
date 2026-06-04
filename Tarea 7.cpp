
#include <iostream>
#include <string>
#include "BSTDictionary.h"

using std::cout;
using std::endl;
using std::string; 
using std::cin;

void printDictionaries( BSTDictionary<int, string>& dict1, BSTDictionary<int, string>& dict2) {

    cout << "Dictionary 1: ";

    dict1.print();

    cout << "Dictionary 2: ";

    dict2.print();
}

int chooseDictionary() {

    int choice = 0;

	bool valid = false;

    while (!valid) {

        cout << "Apply to dictionary (1 or 2): ";

        cin >> choice;

        if (cin.fail() || (choice != 1 && choice != 2)) {
            cin.clear();

            cin.ignore(1000, '\n');

            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
        else {
            valid = true;
        }
	}
 
    return choice;
}

void printMenu() {

	cout << "Menu:\n" 
		<< " 1. Insert\n"
		<< " 2. Delete\n"
		<< " 3. Get value\n"
		<< " 4. Set value\n"
		<< " 5. Contains\n"
		<< " 6. Clear\n"
		<< " 7. Get keys\n"
		<< " 8. Get values\n"
		<< " 9. Update\n"
		<< " 10. Zip\n"
		<< " 0. Exit\n"
        << "Choice: ";

}

int main() {

    BSTDictionary<int, string> dict1;

    BSTDictionary<int, string> dict2;

    int option = -1;

	bool running = true;    

    while (running) {

		printDictionaries(dict1, dict2);

		printMenu();

        if (!(cin >> option)) {

			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Invalid input. Please enter a number." << endl;
        }

        else if (option == 0) {

			running = false;

        }

    }

	cout << "Exiting program." << endl;

    return 0;
}

