/******************************************************************************
# Author:           Jeremy Dupras
# Assignment:       Assignment 6 
# Date:             09 December 2022
# Description:      This program prompts the user for a sleep start and wake up
#                   time and returns the total sleep time.
# Sources:          Zybooks.
#******************************************************************************/

#include <iostream>
#include <iomanip>
#include "valid.h"
#include "prompts.h"

using namespace std;

struct sleep {
   int dayNum;
   int hourStart;
   int minStart;
   int hourStop;
   int minStop;
};

void printWelcomeMessage();
void printMenu();
char getInputChar();
void printStandardMessage(string);
int getDayCount();
int daySelection(int);
void getSleepTimes(sleep inputs[], int x);
void calcTotalTimes(sleep inputs[], int totalTime[], int dayCount);
void printTotalSleepTimes(int totalTime[], int dayCount);
void printOutputStatment(sleep inputs[], int totalTime[], int dayCount);
void printEnding();

const int MAX = 100;
const char STANDARD_TIME = 'S';
const char QUIT = 'Q';
const string DAYS_OF_THE_WEEK_NAMES[8] = {"empty", "Monday", "Tuesday", 
   "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
   sleep inputs[MAX] = {0};
   int totalTime[MAX] = {0};
   char timeMode = 'A';
   int dayCount = 0; // control for loops
   int x = 0;
  
   printWelcomeMessage();
   
   printMenu();
   timeMode = getInputChar();
  
   while(timeMode != QUIT){
      printStandardMessage("You chose Standard Time mode.");
      printStandardMessage("How many nights do you want to calculate?");

      dayCount = getDayCount();
    
      
      if (timeMode == STANDARD_TIME){
        
         for (x = 1; x <= dayCount; x++){
            inputs[x].dayNum =  daySelection(x);
            
            getSleepTimes(inputs, x);
            
         }  
         calcTotalTimes(inputs, totalTime, dayCount);
        
         printOutputStatment(inputs, totalTime, dayCount);
        
         printTotalSleepTimes(totalTime, dayCount);
        
         printMenu();
         timeMode = getInputChar();
      }  
   }
  
   printEnding();
   return(0);
}


// printWelcomeMessage() prints the welcome message
// Pre: none
// Post: prints welcome message
void printWelcomeMessage() {
   cout << "This is a total overnight sleep calculation app." << endl;
   cout << endl;
   return;
}


// printMenu() prints the menu
// Pre: none
// Post: outputs message to screen
void printMenu() {
   cout << "For Standard Time mode \"1-12am\\pm\" Enter: \"S\"\n"
        << "Or Enter \"Q\" to quit.\n" << endl;
   return;
}


// getInputChar() gets the mode indicator
// Pre: none
// Post: returns character
char getInputChar() {
   string characterInput = "n";
   char invalid = 'n';
   char timeMode;
   string prompt = "Enter mode selection here: ";
   timeMode = getChar(prompt);
   timeMode = toupper(timeMode);
   while (timeMode != STANDARD_TIME && timeMode != QUIT) {
      printInvalidInput();
      timeMode = getChar(prompt);
      timeMode = toupper(timeMode);
   }
   return timeMode;
}


// printStandardMessage() Prints message
// Pre: none
// Post: Prints message to screen
void printStandardMessage(string script){
   cout << endl << script << endl;
   return;
}


//getDayCount gets the number of days 
//Pre: none
//Post returns number of days.
int getDayCount() {
   int dayCount;
   dayCount = getInteger("Enter number of Days: ");
   while (dayCount < 0 || dayCount > 99) {
      cout << "Please enter a day count between 0-99.\n";
      dayCount = getInteger("Enter number of Days: ");
   }
   return dayCount;
}



//daySelection() gets the day of the week from the user and returns an int
//Pre: none
//Post: returns integer
int daySelection(int i) {
   int daySelectionNum = 0;
   int x = 0;
   cout << "\nPlease enter an integer for the day of the week." << endl;
   if (i == 1) {
      for (x = 1; x < 8; x++) {
         cout << x << " -- " << DAYS_OF_THE_WEEK_NAMES[x]
            << endl;
      }
   }
   daySelectionNum = getInteger("\nEnter day number: ");
   while (daySelectionNum < 1 || daySelectionNum > 7) {
      cout << "Number out of range." << endl;
      daySelectionNum = getInteger("\nEnter day number: "); 
   }
   return daySelectionNum;
}


// getSleepTimes() gets the values for the inputs array
// Pre: none
// Post: Returns inputs array
void getSleepTimes(sleep inputs[], int x) {
   string prompt;
      //gets and checks hour start
      inputs[x].hourStart = getInteger(sleepPrompts("hour", "fall asleep"));
      while (inputs[x].hourStart < 1 || inputs[x].hourStart > 12){
         cout << "Number is out of range." << endl;
         inputs[x].hourStart = getInteger(sleepPrompts("hour", "fall asleep"));
      }
   
      //gets and checks min Start
      inputs[x].minStart = getInteger(sleepPrompts("minute", "fall asleep"));
      while (inputs[x].minStart < 0 || inputs[x].minStart > 59){
         cout << "Number is out of range." << endl;
         inputs[x].minStart = 
            getInteger(sleepPrompts("minute", "fall asleep"));
      }
   
      // gets and checks hour stop
      inputs[x].hourStop = getInteger(sleepPrompts("hour", "wake up"));
      while (inputs[x].hourStop < 1 || inputs[x].hourStop > 12){
         cout << "Number is out of range." << endl;
         inputs[x].hourStop = getInteger(sleepPrompts("hour", "wake up"));
      }
   
      // gets and checks min stop
      inputs[x].minStop = getInteger(sleepPrompts("minute", "wake up"));
      while (inputs[x].minStop < 0 || inputs[x].minStop > 59){
         cout << "Number is out of range." << endl;
         inputs[x].minStop = 
            getInteger(sleepPrompts("minute", "fall wake up"));
      }
   
   return;
}


// calcTotalTimes() Calculates the total sleep time
// This calculation works as long as the person doesn't sleep
// past 12pm. 
// Pre: none
// Post: modifies totalTime array
void calcTotalTimes(sleep inputs[], int totalTime[], int dayCount){
  
   int i = 1;
   int total1 = 0;
   int totalMinPerDay = 1440;
   int totalMinHalfDay = 720;
  
   for (i = 1; i <= dayCount; i++) {
      total1 = 0;
         if (inputs[i].hourStart == 12){
            //distance from midnight
            total1 = totalMinPerDay - 
               (inputs[i].hourStart * 60 + inputs[i].minStart);
            //adds distance from midnight to wake up time
            if (inputs[i].hourStop == 12){
               totalTime[i] = total1 + inputs[i].minStop;
            }
            else {
               totalTime[i] = total1 + 
                  inputs[i].hourStop * 60 + inputs[i].minStop;
            }
         }
         else {
            //distance from midnight
            total1 = totalMinHalfDay - 
               (inputs[i].hourStart * 60 + inputs[i].minStart);
            //adds distance from midnight to wake up time
            totalTime[i] = total1 + 
               inputs[i].hourStop * 60 + inputs[i].minStop;
         }
   }
   return;
} 


// printOutputStatment() Prints the total sleep time
// Pre: none
// Post: outputs message to the screen
void printOutputStatment(sleep inputs[], int totalTime[], int dayCount){
   int i = 0;
   fillLine('-', 65);
  for (i = 1; i <= dayCount; i++) {
   cout << "Start " << DAYS_OF_THE_WEEK_NAMES[inputs[i].dayNum] << " at " 
      << inputs[i].hourStart << ":" << setprecision(2) << inputs[i].minStart
      << "PM" << endl;
   cout << "End " << DAYS_OF_THE_WEEK_NAMES[inputs[i].dayNum + 1] << " at " 
      << inputs[i].hourStop << ":" << inputs[i].minStop << "AM" << endl;
   cout << "Your total sleep time is: " << totalTime[i] / 60 << " hours and "
      << totalTime[i] % 60; 
   cout << " minutes." << endl;
   fillLine('-', 65);
}
   return;
}


//printTotalSleepTimes prints out all the total sleep times
//computes max, min, average
//pre: none
//post: prints out all the total sleep times to screen
void printTotalSleepTimes(int totalTime[], int dayCount) {
   int i = 0;
   int cumulativeTime = 0;
   int avgSleep = 0;
   int maxSleep = 0;
   int minSleep = 0;
  
   for (i = 1; i <= dayCount; i++) { 
      cumulativeTime = cumulativeTime + totalTime[i];
   }
   maxSleep = totalTime[1];
   minSleep = totalTime[1];
   for (i = 1; i <= dayCount; i++) {
      if (totalTime[i] < minSleep) {
         minSleep = totalTime[i];
      }
      if (totalTime[i] > maxSleep) {
         maxSleep = totalTime[i];
      }
   }
   avgSleep = cumulativeTime / dayCount;
   
   cout << "Cumulative sleep time is " << cumulativeTime / 60 << " hours "
           << "and " << cumulativeTime % 60 << " minutes." << endl;
   cout << "Average sleep time: " << avgSleep / 60 << " hours " 
      << avgSleep % 60 << " minutes" << endl;
   cout << "Maximum sleep: " << maxSleep / 60 << " hours " << maxSleep % 60
        << " minutes" << endl;
   cout << "Minimum sleep: " << minSleep / 60 << " hours " << minSleep % 60
        << " minutes" << endl;
   fillLine('-', 65);
}


// printEnding() Prints Goodbye message
// Pre: none
// Post: message is output to the screen
void printEnding(){
   cout << endl << "Goodnight!" << endl;
   return;
}



