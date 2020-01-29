#include <iostream>
using namespace std;

int main()
{
    int userInput = 1;
    int i;              //iterator
    bool prime = true;  //declare prime to be true

    while(userInput != 0)   //start loop, unless user enters 0
    {
        cout << "Please enter a positive number or press 0 to exit. ";
        cin >> userInput;
        
        for(i = 2; i <= userInput; i++)     //initialize i set to 2. Our condition 2 <= userInput, once ran, add +1 to i 
        {
            if(userInput % i == 0)     //if userInput / 2,3,4... has 0 remainder, then it's NOT prime
            {
                prime = false;      //has 0 remainder, prime is not true
                i++;
                break;              //break from loop
            }
        }
        if(prime == true)           //check bool statement if true
        {
            cout << "This is a prime number. " << endl;     //print output
            continue;                               //return to top
        }   
        else                        //bool statement false
            cout << "This is NOT a prime number. " << endl;     //print output
            continue;
    }
    return 0; 
}