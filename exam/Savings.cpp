#include "Savings.h"
#include <iostream>
using namespace std;
 
Savings::Savings()  // declare values in default constructor
{
    SetName("");       
    SetTaxID(85912345);
    SetBalance(0);
    
    Account::numdeposits = 0;
    Account::numwithdrawals = 0;
    
    for (int i = 0; i < 10; i++)    // keep track of last 10 withdrawals and deposits
    {
        last10withdrawals[i] = 0;
        last10deposits[i] = 0;
    }
}
 
Savings::Savings(string p_name, long p_id, double p_bal)  // declare vlaues in secondary constructor
{
    SetName(p_name);    //pass p_name
    SetTaxID(p_id);     // pass p_id
    SetBalance(p_bal);  // pass p_bal
    
    Account::numdeposits = 0;   // counter 
    Account::numwithdrawals = 0;    //counter
 
    for (int i = 0; i < 10; i++)    // store last 10 withdraws and deposits
    {
        last10withdrawals[i] = 0;
        last10deposits[i] = 0;
    }
}
 
void Savings::DoWithdraw(double amount) // Withdraw amount from savings
{
    SetBalance(GetBalance()-amount);    // set balance, subtract amount when called
    for (int i = 0; i < 10; i++)
    {
        if (last10withdrawals[i] == 0) // if last in array is null then that becomes the amount
        {
            last10withdrawals[i] = amount;
            Account::numwithdrawals++;   // increment  numwithdraws counter
            return;
        }
    }
    for (int i = 0; i < 10; i++)    //increment through to end of array
    {
        if (i < 9)      // while i<9 find last number in array, and push it to 10
        {
            last10withdrawals[i] = last10withdrawals[i+1];  // if no empty elements, shift elements back one slot
        }
    }
    //need to free up new spots in array             
    last10withdrawals[(sizeof(last10withdrawals)/sizeof(double))-1] = amount;  //https://www.geeksforgeeks.org/array-sum-in-cpp-stl
    Account::numwithdrawals++;
}
 
void Savings::display() const // display savings info
{
    cout << "Savings Account" << endl;
    cout << "Name: " << GetName() << endl;
    cout << "TaxID: " << GetTaxID() << endl;
    cout << "Balance: $" << GetBalance() << endl;
    
    cout << "Last 10 withdrawls: \n";
    for (int i = 0; i < 10; i++)    // iterate through 10 spots in array
    {
        cout << "$" << last10withdrawals[i] << endl;   // print last10withdraws array
    }
    cout << endl;
    
    cout << "Last 10 deposits: \n" << endl;
    for (int i = 0; i < 10; i++)    // iterate through 10 spots in array
    {
        cout << "$" << last10deposits[i] << endl;   // print out last10deposits array
    }
    cout << "Number of deposits: " << Account::numdeposits << endl;     // print out total number of deposits
    cout << "Number of withdrawals: " << Account::numwithdrawals << endl;   // print out total number of withdrawals
}