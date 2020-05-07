#include "Account.h"
#include <string>
#include <iostream>
using namespace std;
 
Account::Account()  // declare values in default constructor
{
  name = "";        
  taxID = 85912345;
  balance = 0;
  
  Account::numdeposits = 0;
  Account::numwithdrawals = 0;
  
  for (int i = 0; i < 10; i++)  // keep track of deposit and withdrawal arrays
  {
    last10deposits[i] = 0;
    last10withdrawals[i] = 0;
  }
}
Account::Account(string p_name, long p_id, double p_bal)  // declare vlaues in secondary constructor
{
  name = p_name;
  taxID = p_id;
  balance = p_bal;
  
  Account::numdeposits = 0;
  Account::numwithdrawals = 0;
  
  for (int i = 0; i < 10; i++)
  {
    last10deposits[i] = 0;
    last10withdrawals[i] = 0;
  }
}
void Account::SetName(string p_name)  //method to set name
{
  name = p_name;   // set user name
}
 
void Account::SetTaxID(long p_id)   // method to set id 
{
  taxID = p_id;   // set user taxid
}
 
void Account::SetBalance(double p_bal)  // method to set balance
{
  balance = p_bal;   // set user balance
}
 
string Account::GetName() const  
{
  return name; // return user name
}
 
long Account::GetTaxID() const  
{
  return taxID;   // return user taxid
}
 
double Account::GetBalance() const
{
  return balance;   // return user balance
}
 
void Account::MakeDeposit(double amount)
{
  SetBalance(GetBalance()+amount);    // set the balance
  for (int i = 0; i < 10; i++)
  {
   if (last10deposits[i] == 0)        // if there is a null character, assign amount to it
    {
      last10deposits[i] = amount;
      Account::numdeposits++;       // increment total num of deposits
      return;
    }
  }
  for (int i = 0; i < 10; i++)  // keep track of deposits in array
  {
    if (i < 9)
    {
      last10deposits[i] = last10deposits[i+1];
    }
    //need to free up new spots in array
    last10deposits[(sizeof(last10deposits)/sizeof(double))-1] = amount;  //https://www.geeksforgeeks.org/array-sum-in-cpp-stl
    Account::numdeposits++;   // increment number of deposits
  }
}
void Account::display() const // print user info
{   
  cout << "Name: " << GetName() << endl;
  cout << "TaxID: " << GetTaxID() << endl;
  cout << "Balance: $" << GetBalance() << endl;
}
