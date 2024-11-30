/*
* Project_One.cpp 
*
*  Date: November 16, 2024
*  Author: Clara H. Abraham 
*/ 

#include <iostream> // Includes input/output library file 

using namespace std; 

// This METHOD formats a number as 2 digits, with a leading 0 if needed. This method can be useful when converting a time like 9 hours, 12 minutes and 3 seconds to "09:12:03" 
string twoDigitString(unsigned int n) {
	
	string converted; 
	
	// Numbers between 10 and 59 just need to be converted to a string
	if (n >= 10 && n <= 59) { 
		converted = to_string(n);  
	}
	
	// Numbers from 0 to 9 need a "O" tacked onto the front of the string representation of the number
	int count = 1; 
	
	if (n >= 0 && n <= 9) {
		converted = to_string(n); 
		converted = converted.insert(0, count, '0');
	} 
	
	// Return the two digit string representation of n 
	return converted;  
} 


// This METHOD returns a string of length n, each character a c. For example, nCharString(5, '*') should return "*****" 
string nCharString(size_t n, char c) { 
	
	string str; 
	
	for (int i = 0; i < n; i++) {
		str.push_back(c); // This will append c at the end of the string 
	}
	
	// return the n character string 
	return str; 
}


// This METHOD formats the time in military format. For example: hh:mm:ss
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	
	string finalString; 
	finalString = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s); 
	
	// return formatted time as hh:mm:ss 
	return finalString; 
} 


// This METHOD formats the time in am/pm format and returns hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive. 
#include <ctime> // Library file 
string formatTime12(unsigned int h, unsigned int m, unsigned int s) { 
	
	// Determines whether A.M. or P.M. 
	string suffix; 
	
	if (h < 12) {  
		suffix = " A M"; 
	}
	else {
		suffix = " P M"; 
	}
	
	// Converts the hour, hh, into 12-hour time format  
	if (h > 12) {
		h = h - 12; 
	}
	else if (h == 0) {
		h = 12; 
	}
	
	// Formats the final string to be returned   
	string final_String; 
	final_String = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + suffix; 
	
	return final_String; 
} 


// This METHOD prints the Menu
void printMenu(char * strings[], unsigned int numStrings, unsigned char width) { 
	
	// Print a line of asterisks (*) with a length of the width parameter 
	cout << nCharString(width, '*') << endl;         
	
	// Loop through each string in the array   
	for (unsigned int i = 0; i < numStrings; i++) {
		stringstream strs;
		strs << "* " << i + 1 << " - " << strings[i]; // Menu choices 
		string line = strs.str();
		int spacesToAdd = (width - 1) - line.length();
		string padding = nCharString(spacesToAdd, ' ');
		cout << line << padding << "*" << endl;
		if (i < numStrings - 1) {
			cout << endl;
		}
	}  
	
	// Outside the loop print another line of asterisks followed by an endl
	cout << nCharString(width, '*') << endl;     
} 


// This METHOD processes user input from the Menu Choices
unsigned int getMenuChoice(unsigned int maxChoice) {

	int input; 
	cin >> input; // Reads user input    
	
	// Loop checks if input is not in range 
	while (input < 1 || input > maxChoice) {   
		cin >> input; 
	}  
	
	// return the value 
	return input;      
} 


// This METHOD displays both 12- and 24-hour time formats on interface 
void displayClocks(unsigned int h, unsigned int m, unsigned int s) { 
	
	// cout 27 stars + 3 spaces + 27 stars + endl
	cout << nCharString(27,'*') << nCharString(3,' ') << nCharString(27,'*') << endl; 
	
	// cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
	cout << "*" << nCharString(6,' ') << "12-HOUR CLOCK" << nCharString(6,' ') << "*" << nCharString(3,' ');  
	
	// cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
	cout << "*" << nCharString(6,' ') << "24-HOUR CLOCK" << nCharString(6,' ') << "*" << endl; 
	
	// cout an endl for a blank line  
	cout << endl; 
	
	// cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces 
	cout << "*" << nCharString(6,' ') << formatTime12(h, m, s) << nCharString(7,' ') << "*" << nCharString(3,' '); 
	
	// cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl 
	cout << "*" << nCharString(8,' ') << formatTime24(h, m, s) << nCharString(9,' ') << "*" << endl; 
	
	// cout 27 stars + 3 spaces + 27 stars + endl 
	cout << nCharString(27,'*') << nCharString(3,' ') << nCharString(27,'*') << endl; 
} 


// This METHOD adds one hour to the current hour (which is the 1st menu choice) 
void addOneHour() {
	
	// if getHour() is between 0 and 22 inclusive, add 1 and setHour() to that
	// if getHour() is 23 the next value for hour is 0 so setHour() to that 
	if (getHour() >= 0 && getHour() <= 22) { 
		setHour(getHour() + 1); 
	} 
	else if (getHour() == 23) {  
		setHour(00); 
	}   
	
	// nothing to return, just setHour to the appropriate value
} 


// This METHOD adds one minute to the current time (which is the 2nd menu choice)  
void addOneMinute() { 

	// if getMinute() is between 0 and 58 inclusive, add 1 and setMinute() to the new value
	// if getMinute() is 59 the minutes must be set to 0 and you must call addOneHour()
	if (getMinute() >= 0 && getMinute() <= 58) {  
		setMinute(getMinute() + 1);  
	}
	else if (getMinute() == 59) {       
		setMinute(00);    
		addOneHour();  
	}
	
	// nothing to return, just setMinute to the appropriate value and use addOneHour if needed
} 


// This METHOD adds one second to the current time (which is the 3rd menu choice) 
void addOneSecond() { 
	
	//if getSecond() is between 0 and 58 inclusive, add 1 and setSecond()
	//if getSecond() is 59, seconds wrap around to 0 and you need to call addOneMinute() 
	if (getSecond() >= 0 && getSecond() <= 58) {  
		setSecond(getSecond() + 1);  
	}
	else if (getSecond() == 59) {  
		setSecond(00); 
		addOneMinute();  
	}
	
	// nothing to return, just call setSecond() with the right value and addOneMinute() when needed
} 


// Method Function to control my program
void mainMenu() {
	
	// getMenuChoice(4) will handle the input and return 1, 2, 3, or 4. 
	int n = getMenuChoice(4);   
	int i;  
	for (i = 0; i <= n; i++) {  
		
		if (n == 1) {   	
			addOneHour(); 
		}
		
		if (n == 2) {  
			addOneMinute(); 
		} 
		
		if (n == 3) {  
			addOneSecond();  
		} 
	}  
	
	// nothing to return, just call the appropriate methods
} 


// the entry point of the program 
int main(int argc, char *argv[]) { 
	
	// Get user input for initial time
	cout << "What is the current time: " << endl; 
	cin >> currentTime; 
	formatTime12(currentTime);   
	
	displayClocks(); 
	
	while (true) { 
		printMenu(); 
		cout << "Enter a menu selection: " << endl; 
		cin >> input; 
		getMenuChoice(input); 
		
		if (getMenuChoice(1)) {
			addOneHour(); 
			cout << "One hour has been added. " << endl; 
			displayClocks();
			printMenu(); 
		} 
		
		if (getMenuChoice(2)) {
			addOneMinute(); 
			cout << "One minute has been added. " << endl; 
			displayClocks(); 
			printMenu();
		}
		
		if (getMenuChoice(3)) {
			addOneSecond(); 
			cout << "One second has been added. " << endl; 
			displayClocks();
			printMenu(); 
		} 
		
		if (getMenuChoice(4)) {
			cout << "Exit Program. " << endl;  
			break; 
		}
	}
	
}