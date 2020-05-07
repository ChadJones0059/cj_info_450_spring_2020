#ifndef _Account_h_
#define _Account_h_
#include <iostream>
#include <string>
using namespace std;
 
class Account
{
    protected:
        int numdeposits;   // number of deposits
        int numwithdrawals;   // num of withdrawals
        double last10withdrawals[10];   // create array for last 10 withdrawals
        double last10deposits[10];   // create array for last 10 deposits
    
    private:
        string name;   // user's info
        long taxID;   //user ID
        double balance;   // user's balance
 
    public:
        Account();   // default constructor
        Account(string p_name, long p_id, double p_bal); // constuctor with name, taxid, and balance
 
        void SetName(string p_name);   // set username of account
        void SetTaxID(long p_id);   // set users taxid for account
        void SetBalance(double p_bal);   // set balance of the account
 
        string GetName() const;   // return the username
        long GetTaxID() const;   // return the taxid
        double GetBalance() const;   // return the balance
 
        void MakeDeposit(double amount);   // add funds to the account
  
        void display() const;   // display account info
};
#endif      
 

