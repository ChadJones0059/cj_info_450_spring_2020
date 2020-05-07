#include <iostream>
#include "Account.h"
#include "Checking.h"
#include "Savings.h"
#include "CreditCard.h"
#include <string>
#include <cstdlib>
using namespace std;
 
void print_menu(int input, Savings *savAcc, Checking *chkAcc, CreditCard *ccAcc);   // print menu to screen
bool display = true;   // run menu till display turns false
void select_menu(int user_selection, Savings *savAcc, Checking *chkAcc, CreditCard *ccAcc);   // allow user to make selection

void savings_deposit(Savings *savAcc);   // savings deposit method
void savings_withdrawal(Savings *savAcc);   // savings withdrawal method

void checking_deposit(Checking *chkAcc);   // checking deposit method
void checking_check(Checking *chkAcc);   // checking withdrawal method

void cc_payment(CreditCard *ccAcc);   // cc depsoit method
void cc_charge(CreditCard *ccAcc);   // cc withdrawal method

void print_menu(int input, Savings *savAcc, Checking *chkAcc, CreditCard *ccAcc)
{
 while (display)   // display menu till display turns false
 {
   cout << "***********************************************************" << endl;
   cout << "*      Please select an option from below:                *" << endl;
   cout << "*                                                         *" << endl;
   cout << "*        1. Savings Deposit                               *" << endl;
   cout << "*        2. Savings Withdrawal                            *" << endl;
   cout << "*        3. Checking Deposit                              *" << endl;
   cout << "*        4. Write A Check                                 *" << endl;
   cout << "*        5. Credit Card Payment                           *" << endl;
   cout << "*        6. Make A Charge                                 *" << endl;
   cout << "*        7. Display Savings                               *" << endl;
   cout << "*        8. Display Checking                              *" << endl;
   cout << "*        9. Display Credit Card                           *" << endl;
   cout << "*        0. Exit                                          *" << endl;
   cout << "***********************************************************" << endl;
   cout << "Checking Balance: \t Checking Balance: \t Credit Card Balance:" << endl;
   cout << "\t$" << chkAcc->GetBalance() << "\t\t\t$" << savAcc->GetBalance() << "\t\t\t$" << ccAcc->GetBalance() << endl;
   cin >> input;
   select_menu(input, savAcc, chkAcc, ccAcc);       // method to see what user selects
 }
}
 
int main()
{
   string userInput;   // set name
   long id = 85912345;  // set id
   double balance = 100;  // set starting balance at $100
   cout << "*****************************************************************" << endl;
   cout << "              WELCOME TO THE BANK OF VCU                         " << endl;
   cout << "*****************************************************************\n" << endl;
   cout << "              Please enter your name: ";
   getline(cin,userInput);

   Savings *savAcc = new Savings(userInput, id, balance);   // setup the three userInput objects and pointers
   Checking *chkAcc= new Checking(userInput, id, balance);
   CreditCard *ccAcc = new CreditCard(userInput, id, balance);
   
   int input = 0;   // menu option selector
   print_menu(input, savAcc, chkAcc, ccAcc);   // display the menu
   return 0;
}

void select_menu(int user_selection, Savings *savAcc, Checking *chkAcc, CreditCard *ccAcc)
{
 switch(user_selection)   // run each case option
 {
   case 0:
     display = false;   // exit program
     break;
    
    case 1:
     savings_deposit(savAcc);
     break;
    
    case 2:
     savings_withdrawal(savAcc);
     break;
    
    case 3:
     checking_deposit(chkAcc);
     break;
    
    case 4:
     checking_check(chkAcc);
     break;
    
    case 5:
     cc_payment(ccAcc);
     break;
    
    case 6:
     cc_charge(ccAcc);
     break;
    
    case 7:
     savAcc->display();
     break;
    
    case 8:
     chkAcc->display();
     break;
    
    case 9:
     ccAcc->display();
     break;
 }
}

void savings_deposit(Savings *savAcc)   // savings deposit method
{
 double depositAmount=0;
 cout << "Savings Deposit Amount: $";
 cin >> depositAmount;
 savAcc->MakeDeposit(depositAmount);
}
 
void savings_withdrawal(Savings *savAcc) // savings withdrawl method
{
 double withdrawAmount = 0;
 cout << "Savings Withdrawal Amount: $";
 cin >> withdrawAmount;
 savAcc->DoWithdraw(withdrawAmount);
}
 
void checking_deposit(Checking *chkAcc)       // checkings depsosit method
{
 double depositAmount = 0;
 cout << "Checking Deposit Amount: $";
 cin >> depositAmount;
 chkAcc->MakeDeposit(depositAmount);
}
 
void checking_check(Checking *chkAcc)   // checkings withdrawal method
{
 double checkAmount = 0;
 int checkNum = 0;
 cout << "Check Number: ";
 cin >> checkNum;
 cout << "Check Amount: $";
 cin >> checkAmount;         
 chkAcc->WriteCheck(checkNum, checkAmount);
}
 
void cc_payment(CreditCard *ccAcc)   // creditcard deposit method
{
 double cc_payment = 0;
 cout << "Credit Card Payment Amount: $";
 cin >> cc_payment;
 ccAcc->MakePayment(cc_payment);
}
 
void cc_charge(CreditCard *ccAcc)   // creditcard withdrawal method
{
 string local;
 double cc_charge = 0;
 cout << "Location of Credit Card:  ";
 cin.ignore();     // http://www.cplusplus.com/reference/istream/istream/ignore
 getline(cin, local);
 cout << "Amount to Charge: $";
 cin >> cc_charge;
 ccAcc->DoCharge(local, cc_charge);
}