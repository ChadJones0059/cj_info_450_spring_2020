// This program coverts gallons to liters 

#include <iostream>
using namespace std;

int main()
{
    int gallons, liters;

    cout << "Enter number of gallons: ";
    cin >> gallons; // This gets input from the user 

    liters = gallons * 4; // converts gallons to liters

    cout << "Liters: " << liters;

    return 0;

}