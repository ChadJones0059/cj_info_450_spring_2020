#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
  char student[30][100];
  for(int i = 0; i < 31; i++)
  {
    cout << "Please enter student for index " << i << ": ";
    cin.getline(student[i],100);
  }
  return 0;
}