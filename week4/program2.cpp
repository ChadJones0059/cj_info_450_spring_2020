#include <iostream>
using namespace std;

int main()
{
  char student[30][100];    // two dimensional array
  for(int i = 0; i < 30; i++)   //start for loop for user to enter 2 strings
  {
    cout << "Please enter student for index " << i << ": ";     // print output
    cin.getline(student[i],100);                                // store variable
    if(student[i][i] == 0)                         // if user presses enter, break from loop
    {
      break;  
    }
  }
  for(int i =0; i < 30; i++)                  
  {
    if(student[i][i] == 0)
    {
      break;
    }
    cout << "students[" << i << "] = " << student[i] << endl;
  }
  return 0;
}