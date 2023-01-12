#include <iostream>
using namespace std;

// getInteger() validates for integer input
//Pre: none
//Post: returns integer
int getInteger(string prompt = "Enter integer: ") {
    int num = 0;
    cout << prompt;
    cin >> num;
    while (!cin || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nInvalid integer." << endl;
        cout << endl;
        cout << prompt;
        cin >> num;
    }
    cin.get(); // remove newline left in stream
    return num;
}


//getDouble() validates for float input
//Pre: none
//Post: returns float
float getFloat(string prompt = "Enter float: ") {
    float num = 0;
    cout << prompt;
    cin >> num;
    while (!cin || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid float." << endl;
        cout << prompt;
        cin >> num;
    }
    cin.get(); // remove newline left in stream
    return num;
}


//getDouble() validates for float input
//Pre: none
//Post: returns double
double getDouble(string prompt = "Enter double: ") {
    double num = 0;
    cout << prompt;
    cin >> num;
    while (!cin || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid float." << endl;
        cout << prompt;
        cin >> num;
    }
    cin.get(); // remove newline left in stream
    return num;
}


// getString() validates for a non-empty string
// Pre:none
// Post: Returns string
string getString(string prompt = "Enter a string: ") {
    string phrase = "";
    cout << prompt;
    getline(cin, phrase);
    while (phrase == "") {
        cout << "No characters were entered." << endl;
        cout << prompt;
        getline(cin, phrase);
    }
  return phrase;
}


//getChar() validates that a character is a char
//Pre: none
//Post: returns char
char getChar(string prompt = "Enter a character: ") {
   char char1 = 'n';
   cout << prompt;
   cin >> char1;
   while (!cin || cin.peek() != '\n'){
      cin.clear();
      cin.ignore(100, '\n');
      cout << "\nNot a valid character entry. " << endl;
      cout << endl;
      //cout << char1 << endl; //editing statment
      cout << prompt;
      cin >> char1;
      
   }
   cin.get();
   return char1;
}

