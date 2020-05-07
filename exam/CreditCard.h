#include "Account.h"
#include <string>
using namespace std;
 
class CreditCard : public Account
{
public:
   CreditCard();   // default constructor
   CreditCard(string p_name, long p_id, double p_bal); // secondary constructor
   
   void display() const; // display cc account info
   void DoCharge(string name, double amount);   // charge account, give it location name and charge amount
   void MakePayment(double amount);   // pay some amount of the cc
 
private:
   long cardnumber;   // holds creditcard number
   string last10charges[10];   // array for last 10 locations of charges
};

