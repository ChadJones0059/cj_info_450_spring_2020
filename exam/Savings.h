#include "Account.h"
#include <string>
using namespace std;
 
class Savings : public Account
{
    public:
        Savings();   // default constructor
        Savings(string p_name, long p_id, double p_bal);   // secondary constructor
   
        void display() const;   // display savings account info
        void DoWithdraw(double amount);       // withrdaw from savings account
};