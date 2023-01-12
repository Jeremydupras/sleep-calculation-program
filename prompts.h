// speepPrompts() returns a prompt
// Pre: minuteOrHour and fallOrWakeUp can not be empty strings
// Post: returns a string
string sleepPrompts(string minuteOrHour, string fallOrWakeUp){
   string prompt = "";
   if (minuteOrHour == "minute"){
      prompt = "Enter the minute you will ";
      prompt.append(fallOrWakeUp);
      prompt.append(" \"0-59\": ");
   }
   else if (minuteOrHour == "hour"){
      prompt = "Enter the hour you will ";
      prompt.append(fallOrWakeUp);
      prompt.append(" \"1-12\": ");       
   }
   return prompt;
}


// fillLine() Prints fill on a single line
// Pre: fill is not empty, width is a positive integer
// Post: A fill line is output to the screen
void fillLine(char fill, int width) {
   cout << setfill(fill) << setw(width) << "" << endl;
   return;
}


// printInvalidInput() Prints an invalid input response
// Pre: none
// Post: message is output to the screen
void printInvalidInput(){
   fillLine('-', 65);
   cout << "Invalid input Please try again." << endl;
   fillLine('-', 65);
   cout << endl;
   return;
}
