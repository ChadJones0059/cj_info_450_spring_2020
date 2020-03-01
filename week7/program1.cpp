#include <iostream>
#include <string>

using namespace std;
string reverse(string *s1);
string userInput;
int main()
{
    while(1)
    {
        cout << "Please enter a string: " << endl;
        getline(cin, userInput);
        if(userInput == "")
        {
            break;
        }
        reverse(&userInput);
        cout << "That string reversed is: " << endl;
        cout << userInput << endl << endl;
    }
    return 0;
}
string reverse(string *s1)
{
    *s1;                            // s1 makes a copy of userInput. Also assigns same address, correct?
    int j = s1->length()-1;           // find the length of s1 and - 1
    for(int i = 0; i < j; i++)          
    {
        char container = userInput[i];      // create empty container to shuffle through string, starting with position 0
        userInput[i] = userInput[j];        // move i from beginning to end, and j to beginning etc..
        userInput[j] = container;          
        j--;
    }
    return userInput;
}