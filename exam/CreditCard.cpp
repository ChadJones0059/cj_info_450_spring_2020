#include "CreditCard.h"
#include <iostream>
#include <string>
using namespace std;
 
CreditCard::CreditCard()  // declare values in default constructor
{
    SetName("");      
    SetTaxID(85912345);
    SetBalance(0); 
    cardnumber = 0000000;
    
    Account::numdeposits = 0;   // counter to keep track of num deposits
    Account::numwithdrawals = 0;    // counter to keep track of num withdrawals
    
    for (int i = 0; i < 10; i++)
    {
        last10deposits[i] = 0;
        last10withdrawals[i] = 0;
        last10charges[i] = "";
    }
}
 
CreditCard::CreditCard(string p_name, long p_id, double p_bal)  // declare vlaues in secondary constructor
{
    SetName(p_name); 
    SetTaxID(p_id);
    SetBalance(p_bal);
    cardnumber = 0000000;
    
    Account::numdeposits = 0;   // counter to keep track of num deposits
    Account::numwithdrawals = 0;    // counter to keep track of num withdrawals
    
    for (int i = 0; i < 10; i++)
    {
        last10deposits[i] = 0;
        last10withdrawals[i] = 0;
        last10charges[i] = "";
    }
}
 
void CreditCard::DoCharge(string name, double amount) //charge cc acount for a location name and amount
{
    SetBalance(GetBalance()+amount);
    for (int i = 0; i < 10; i++)    // iterate through arrays to find the end
    {
        if (last10withdrawals[i] == 0) // when we find the null of the list, assign posistions
        {
            last10withdrawals[i] = amount;      // last in arry becomes amount
            last10charges[i] = name;        // last in array becomes name
            Account::numwithdrawals++;  // increment  numwithdraws counter
            return;
        }
    }
    for (int i = 0; i < 10; i++)    // iterate through to open spot at beginning 
    {
        if (i < 9)      // while i<9 find last number in array, and push it to 10
        {
            last10withdrawals[i] = last10withdrawals[i+1]; // if no empty elements, shift elements back one slot
            last10charges[i] = last10charges[i+1];            
        }
    }
    //need to free up new spots in arrays
    last10withdrawals[(sizeof(last10withdrawals)/sizeof(double))-1] = amount;  //https://www.geeksforgeeks.org/array-sum-in-cpp-stl
    last10charges[(sizeof(last10charges)/sizeof(string))-1] = name;  //https://www.geeksforgeeks.org/array-sum-in-cpp-stl
    Account::numwithdrawals++;
}
 
void CreditCard::MakePayment(double amount)
{
    SetBalance(GetBalance()-amount);    // set the balance
    for (int i = 0; i < 10; i++)
    {
        if (last10deposits[i] == 0)        // if no empty elements, shift elements back one slot
        {
            last10deposits[i] = amount;
            Account::numdeposits++;
            return;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (i < 9)
        {
            last10deposits[i] = last10deposits[i+1]; // if no empty elements, shift elements back one slot
        }
    }  
    //need to free up new spots in array                                          
    last10deposits[(sizeof(last10deposits)/sizeof(double))-1] = amount;   //https://www.geeksforgeeks.org/array-sum-in-cpp-stl/
    Account::numdeposits++;     // add to counter
}
 
void CreditCard::display() const  //display cc info
{
    cout << "CreditCard Account" << endl;
    cout << "Name: " << GetName() << endl;
    cout << "TaxID: " << GetTaxID() << endl;
    cout << "Balance: $" << GetBalance() << endl;
    cout << "Last 10 charges: ";
    for (int i = 0; i < 10; i++)
    {
        cout << last10charges[i] <<"---$" << last10withdrawals[i] << endl;   // print last 10 locations and amount
    }
    cout << endl;
    cout << "Last 10 payments: ";
    for (int i = 0; i < 10; i++)
    {
        cout << "$" << last10deposits[i] << endl;   // print last 10 payments
    }
    cout << "\nNumber of deposits: " << Account::numdeposits << endl;
    cout << "Number of withdrawals: " << Account::numwithdrawals << endl;
    cout << endl;
}