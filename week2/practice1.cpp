#include <iostream>
using namespace std;

int main()
{
    double userInput = 1;
    double squareUI = 0;

    while(userInput != 0)
    {
        cout << "Please enter a positive number or press 0 to exit. ";
        cin >> userInput;
        squareUI = userInput * userInput; // multiplies the user's choice by itself and saves as squareUI

        if(userInput > 0)
        {
          cout << "This number squared is: " << squareUI << endl; //prints result
        }
        else if(userInput < 0)
        {
          continue;
        }
        else if(userInput == 0)
        {
          cout << "The program is now terminated ";
          break;
        }
    }
    return 0; 
}