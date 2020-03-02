#include <iostream>
#include <string>

using namespace std;
string reverse(string *s1);
int main()
{
    string userInput;
    while(1)
    {
        cout << "Please enter a string: " << endl;
        getline(cin, userInput);
        if(userInput == "")
        {
            break;
        }
        cout << "That string reversed is: ";
        cout << reverse(&userInput)<<endl;
    }
    return 0;
}
string reverse(string *s1)
{
    string return_value = *s1;                              
    int j = return_value.length()-1;                        
    for(int i = 0; i < j; i++)          
    {
        char container = return_value[i];      // create empty container to shuffle through string, starting with position 0
        return_value[i] = return_value[j];        // move i from beginning to end, and j to beginning etc..
        return_value[j] = container;          
        j--;
    }
    return return_value;
}