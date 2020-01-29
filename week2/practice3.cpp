#include <iostream>
using namespace std;

int main()
{
    int userYear = 1;           //declare user input variable

    while (userYear != 0)       //start loop 
    {
        cout << "Please enter a year, or press 0 to exit. ";
        cin >> userYear;        //user input is saved as userYear

        if(userYear % 4 == 0 || (userYear % 100 == 0 && userYear % 400 == 0))       //check if the year is divisible by 4 OR divisible by 100 AND 400
        {
            cout << userYear << " is a leap year. " << endl;        //print result
            continue;
        }
        else
        {
            cout << userYear << " is not a leap year. " << endl;    //print result
            continue;
        }
    }
    return 0;
}