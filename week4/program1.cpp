#include <iostream>
#include <cmath>
using namespace std;

double standardDev(double userInput[]);

int main()
{
    double userInput[10];     
    double sum = 0;         
    double mean = 0;

    for(int i = 0; i < 10; i++)     
    {
        cout << "Enter the number for index " << i << ": ";     
        cin >> userInput[i];                                    
        sum += userInput[i];                                    
        mean = sum / 10;                                        
    }
    cout << "results, " << mean << ", " << standardDev(userInput);
    return 0;
}
double standardDev(double userInput[])
{
    double sum = 0;
    double mean = 0;
    double stdDev = 0;

    for(int i = 0; i < 10; i++)
    {
        sum += userInput[i];
    }
    mean = sum / 10;
    for(int i = 0; i < 10; i++)
    {
        stdDev += (userInput[i] - mean)*(userInput[i] - mean); 
    }
    return sqrt(stdDev/10);
}
