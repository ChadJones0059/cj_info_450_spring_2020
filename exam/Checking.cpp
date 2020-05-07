#include "Checking.h"
#include <iostream>
using namespace std;
 
Checking::Checking()  // declare values in default constructor
{
    SetName("");       // Decalre variables with made up info
    SetTaxID(85912345);
    SetBalance(0);
    
    Account::numdeposits = 0;   // counter to keep track
    Account::numwithdrawals = 0;    // counter to keep track
    
    for (int i = 0; i < 10; i++)    // iterate through and assign the end of array, position 0
    {
        last10withdrawals[i] = 0;
        last10deposits[i] = 0;
        last10checks[i] = 0;
    }
}
 
Checking::Checking(string p_name, long p_id, double p_bal)  // declare vlaues in secondary constructor
{
    SetName(p_name);    
    SetTaxID(p_id);
    SetBalance(p_bal);
    
    Account::numdeposits = 0;       // counter to keep track
    Account::numwithdrawals = 0;    // counter to keep track
    
    for (int i = 0; i < 10; i++)
    {
        last10withdrawals[i] = 0;
        last10deposits[i] = 0;
        last10checks[i] = 0;
    }
}
 
void Checking::display() const  // display checking info
{
    cout << "Checkings Account" << endl;
    cout << "Name: " << GetName() << endl;
    cout << "TaxID: " << GetTaxID() << endl;
    cout << "Balance: $" << GetBalance() << endl;
    
    cout << "Last 10 checks: ";
    for (int i = 0; i < 10; i++)    // print last 10 check numbers and withdrawal amount
    {
        cout << "Num:" << last10checks[i] << "--- $" << last10withdrawals[i] << endl;
    }
    cout << "__________________"<<endl; 
    
    cout << "Last 10 deposits: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "$" << last10deposits[i] << endl;   // print last 10 deposits
    }
    cout << "Number of deposits: " << Account::numdeposits << endl;
    cout << "Number of withdrawals: " << Account::numwithdrawals << endl;
    cout << endl;
}
 
void Checking::WriteCheck(int checknum, double amount)  // withdraw from checking and ask for check number and amount to store
{
    SetBalance(GetBalance()-amount);
    for (int i = 0; i < 10; i++)
    {
        if (last10withdrawals[i] == 0 && last10checks[i] == 0) // if no empty elements, shift elements back one slot
        {
            last10withdrawals[i] = amount;     // last slot is current amount
            last10checks[i] = checknum;        // last written check is current check num
            Account::numwithdrawals++;      // add to with draw counter
            return;
        }
    }
    for (int i = 0; i < 10; i++)        // keep track of checks and withdrawls
    {
        if (i < 9)          // while i<9 find last number in array, and push it to 10
        {
            last10withdrawals[i] = last10withdrawals[i+1];      // if no empty elements, shift elements back one slot
            last10checks[i] = last10checks[i+1];             // free the last element in the array
        }
    }
    //need to free up new spots in arrays
    last10withdrawals[(sizeof(last10withdrawals)/sizeof(double))-1] = amount;   //https://www.geeksforgeeks.org/array-sum-in-cpp-stl
    last10checks[(sizeof(last10checks)/sizeof(int))-1] = checknum;  //https://www.geeksforgeeks.org/array-sum-in-cpp-stl
    Account::numwithdrawals++;  // increment num withdraw
}