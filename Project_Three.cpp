/*
* Project_Three.cpp
*
*  Date: December 9, 2024
*  Author: Clara H. Abraham 
*/ 

#include <iostream> // library for input and output streams 
#include <string> // library for strings 
#include <fstream> // this is for file streams 
#include <vector> // This header file allows me to work with lists in C++ 
#include <algorithm>
using namespace std; // This saves me from having to type std:: 

class Item {
	public: 
	    // Constructor 
		Item(string myName, int myQuantity) {
			name = myName;
			quantity = myQuantity;
		}
	
	    // Accessors 
		string getName() {
			return name;
		}
	
		int getQuantity() {
			return quantity;
		}
	
	    // Mutators 
		void setName(string myName) {
			name = myName;
		} 
	
		void setQuantity(int myQuantity) {
			quantity = myQuantity;
		} 
		
		// This method function increments the quantity by 1 
		void incrementQuantity() {
			++quantity;
		}
	
	    // This method function decrements the quantity by 1 
		void decrementQuantity() {
			--quantity;
		}
	
	private:
		string name;
		int quantity;
}; 

int main(int argc, char *argv[]) {
	vector<string> CornerGrocerList; // The list named, CornerGrocerList, is declared 
	string input;
	ifstream inputFile("CS210_Project_Three_Input_File.txt"); // Opens the input file named CS210_Project_Three_Input_File.txt 
	if (inputFile.is_open()) { 
		// While the input file is open, each and every line of data is read and stored in the list named, CornerGrocerList  
		while (getline(inputFile, input)) {
			CornerGrocerList.push_back(input);
		}
	}
	inputFile.close(); // Closes the input file 
	
	ofstream outputFile("frequency.dat"); // Creates and opens an output file named, frequency.dat 
	if (outputFile.is_open()) { 
		vector<string> tempList = CornerGrocerList; // This makes a copy of the CornerGrocerList. The copy is named, tempList. 
		int count = 0;
		string item;
		while (!tempList.empty()) { 
			// While tempList is not empty, remove the first item in the list and count it. 
			item = tempList.front();
			tempList.erase(tempList.begin());
			++count;
			for (int i = 0; i < tempList.size(); i++) { 
				// This For loop iterates through the list looking for duplicates of that first item, counts it, and removes it from the list.  
				if (item == tempList[0]) { 
					++count;
					tempList.erase(tempList.begin());
					--i;
				}
			}
			// Writes the item's name along with the item's quantity to the output file 
			outputFile << item << " " << count << endl; 
		}
	}
	outputFile.close(); // Closes output file 
	
	while (true) { 
		int menuOption;
		// Prints the menu display 
		cout << "Menu: " << endl; 
		cout << "Option 1 - Gives the quantity of a specified grocery item." << endl; 
		cout << "Option 2 - Prints a list of the frequency of each and every grocery item purchased." << endl; 
		cout << "Option 3 - Prints a list of the frequency of each and every grocery item purchased in the form of a histogram." << endl; 
		cout << "Option 4 - Exit program." << endl << endl; 
		
		cout << "Enter a menu option: "; // Prompt for user input 
		cin >> menuOption; // Reads user input 
		if (menuOption == 4) {
			// If the user inputs 4, the loop will stop iterating and the program will be exited 
			cout << "Program exited." << endl;
			break;
		} 
		Item item("", 0);
		vector<string> tempList = CornerGrocerList; // This makes a copy of the CornerGrocerList. The copy is named, tempList.
		switch (menuOption) { 
			default: {
				// The purpose of default is so that in the case that the user input is neither option 1, 2, 3, or 4 the loop will break 
				cout << "Enter a valid menu option." << endl << endl; 
				break; 
			}
			case 1:	{
				// Menu option 1 
				string target;
				int counter; 
				cout << "Specify the grocery item you wish to look for: "; // Prompts the user for input 
				cin >> target; // Reads the user input
				counter = count(tempList.begin(), tempList.end(), target);
				// Prints out the specified grocery item's name along with its quantity 
				cout << "The amount of " << target << " is " << counter << "." << endl << endl; 
				break;
			}
		
			case 2: {
				// Menu option 2 
				while (!tempList.empty()) { 
					// While tempList is not empty, remove the first item in the list and count it. 
					item.setName(tempList.front());
					item.setQuantity(1);
					tempList.erase(tempList.begin());
					for (int i = 0; i < tempList.size(); i++) { 
						// This For loop iterates through the list looking for duplicates of that first item, counts it, and removes it from the list.  
						if (item.getName() == tempList.front()) { 
							item.incrementQuantity();
							tempList.erase(tempList.begin());
							--i;
						}
					}
					// Prints out the item's name along with the item's quantity 
					cout << item.getName() << " " << item.getQuantity() << endl; 
				}
				cout << endl;
				break;
			}
			case 3: {
				// Menu option 3 
				while (!tempList.empty()) { 
					// While tempList is not empty, remove the first item in the list and count it. 
					item.setName(tempList.front());
					item.setQuantity(1);
					tempList.erase(tempList.begin());
					for (int i = 0; i < tempList.size(); i++) { 
						// This For loop iterates through the list looking for duplicates of that first item, counts it, and removes it from the list.  
						if (item.getName() == tempList.front()) { 
							item.incrementQuantity();
							tempList.erase(tempList.begin());
							--i;
						}
					} 
					// Prints out the item's name along with the item's quantity in the form of a histogram  
					cout << item.getName() << " ";
					while (item.getQuantity() > 0) {
						cout << "*";
						item.decrementQuantity();
					}
					cout << endl; 
				}
				cout << endl;
				break;
			} 
	}
	} 
	return 0; 
}