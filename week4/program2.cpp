#include <iostream>
using namespace std;

int main()
{
  char student[30][100];
  for(int i = 0; i < 30; i++)
  {
    cout << "Please enter student for index " << i << ": ";
    cin.getline(student[i],100);
    if(student[i] == 0)
    {
      break;
    }
  }
  for(int i =0; i < 30; i++)
  {
    cout << "students[" << i << "] = " << student[i] << endl;
  }
  return 0;
}