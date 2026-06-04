
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

BSTDictionary<int, string>& pick(int which, BSTDictionary<int, string>& dict1, BSTDictionary<int, string>& dict2) {
    
	return which == 1 ? dict1 : dict2;
}

BSTDictionary<int, string>& pickOther(int which, BSTDictionary<int, string>& dict1, BSTDictionary<int, string>& dict2) {
    
    return which == 1 ? dict2 : dict1;
}

void handleInsert(BSTDictionary<int, string>& dict) {
    int key;

    string value;

    cout << "Enter key (integer): ";

    cin >> key;

    cout << "Enter value (string): ";

    cin >> value;

    try {
        
		dict.insert(key, value);

		cout << "Inserted (" << key << ", " << value << ") into dictionary." << "\n";
    }
    catch (std::runtime_error& e) {

        cout << "Error: " << e.what() << "\n";

	}
}

void handleRemove(BSTDictionary<int, string>& dict) {

    int key;

    cout << "  Key to remove (int): ";

    cin >> key;

    try {

        string val = dict.remove(key);

        cout << "  Removed key " << key << " (value was \"" << val << "\").\n";
    }

    catch (runtime_error& e) {

        cout << "  Error: " << e.what() << "\n";
    }
}

void handleGetValue(BSTDictionary<int, string>& dict) {

    int key;

    cout << "  Key (int): ";

    cin >> key;

    try {

        string val = dict.getValue(key);

        cout << "  Value: \"" << val << "\"\n";
    }

    catch (runtime_error& e) {

        cout << "  Error: " << e.what() << "\n";
    }
}

void handleSetValue(BSTDictionary<int, string>& dict) {

    int    key;

    string value;

    cout << "  Key (int): ";

    cin >> key;

    cout << "  New value (string): ";

    cin >> value;

    try {

        dict.setValue(key, value);

        cout << "  Updated key " << key << " to \"" << value << "\".\n";
    }

    catch (runtime_error& e) {

        cout << "  Error: " << e.what() << "\n";
    }
}

void handleContains(BSTDictionary<int, string>& dict) {

    int key;

    cout << "  Key (int): ";

    cin >> key;

    cout << "  Contains " << key << ": " << (dict.contains(key) ? "Yes" : "No") << "\n";
}

void handleClear(BSTDictionary<int, string>& dict) {

    dict.clear();

    cout << "  Dictionary cleared.\n";
}

void handleGetKeys(BSTDictionary<int, string>& dict) {

    List<int>* keys = dict.getKeys();

    cout << "  Keys: [ ";

    keys->goToStart();

    while (!keys->atEnd()) {

        cout << keys->getElement() << " ";

        keys->next();
    }
    cout << "]\n";

    delete keys;
}

void handleGetValues(BSTDictionary<int, string>& dict) {

    List<string>* values = dict.getValues();

    cout << "  Values: [ ";

    values->goToStart();

    while (!values->atEnd()) {

        cout << "\"" << values->getElement() << "\" ";

        values->next();
    }

    cout << "]\n";

    delete values;
}

void handleUpdate(BSTDictionary<int, string>& target, BSTDictionary<int, string>& source, int targetNum) {

    int sourceNum = (targetNum == 1) ? 2 : 1;

    target.update(&source);

    cout << "  Dictionary " << targetNum << " updated with contents of dictionary " << sourceNum << ".\n";
}

void handleZip(BSTDictionary<int, string>& dict) {

    int n = 0;

    cout << "  How many pairs to add? ";

    cin >> n;

    if (n <= 0) {

        cout << "  No pairs added.\n";

        return;
    }

    List<int>* keys = new LinkedList<int>();

    List<string>* values = new LinkedList<string>();

    cout << "  Enter " << n << " key(s):\n";

    for (int i = 0; i < n; i++) {

        int k;

        cout << "    Key " << (i + 1) << ": ";

        cin >> k;

        keys->append(k);
    }

    cout << "  Enter " << n << " value(s):\n";

    for (int i = 0; i < n; i++) {

        string v;

        cout << "    Value " << (i + 1) << ": ";

        cin >> v;

        values->append(v);
    }

    dict.zip(keys, values);

    cout << "  Zip applied.\n";

    delete keys;

    delete values;
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

        else if (option < 1 || option > 10) {

            cout << "Invalid option. Please choose a number between 0 and 10." << endl;
        }

        else {

            int which = chooseDictionary();

            BSTDictionary<int, string>& chosen = pick(which, dict1, dict2);

            if (option == 1) {

                handleInsert(chosen);
            }
                

            else if (option == 2) {

                handleRemove(chosen);
            }

            else if (option == 3) {

                handleGetValue(chosen);
            }

            else if (option == 4) {

                handleSetValue(chosen);
            }       

            else if (option == 5) {

                handleContains(chosen);
            }

            else if (option == 6) {

                handleClear(chosen);
            }   

            else if (option == 7) {

                handleGetKeys(chosen);
            }

            else if (option == 8) {

                handleGetValues(chosen);
            }

            else if (option == 9) {

                handleUpdate(chosen, pickOther(which, dict1, dict2), which);
            }

            else if (option == 10) {
                handleZip(chosen);
            }
        }
	

    }

	cout << "Exiting program." << endl;

    return 0;
}

