#include "Account.h"
#include <string>
using namespace std;
 
class Checking : public Account
{
 public:
   Checking();   // default constructor
   Checking(string p_name, long p_id, double p_bal); // secondary constructor
 
   void WriteCheck(int checknum, double amount);   // Withdraw amount from checking account
   void display() const;   // output Checking account info to screen
  
 private:
   int last10checks[10];   // holds the last 10 check numbers
};
