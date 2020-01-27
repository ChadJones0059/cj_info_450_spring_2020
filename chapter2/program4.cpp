#include <iostream>
using namespace std;

int main()
{
    double gallons;
    double liters;

    cout << "Enter number of gallons: ";
    cin >> gallons; // this gets input from the user 

    liters = gallons * 3.7854;

    cout << "Liters: " << liters;

    return 0;

}