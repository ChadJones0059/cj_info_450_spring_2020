#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int userInput[10];
    double sum = 0;
    double mean = 0;
    double var = 0;
    double stdDev = 0;
    for(int i = 0; i < 10; i++)
    {
        cout << "Enter the number for index " << i << ": ";
        cin >> userInput[i];
        sum += userInput[i];
        mean = sum / 10;

        var += (userInput[i] - mean)*(userInput[i] - mean);
        var = var / 10;
        stdDev = sqrt(var);        
    }
    cout << "results, " << mean << ", " << stdDev;
    return 0;
}